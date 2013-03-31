#!/bin/sh
# 20130331 sampo@synergetics.be

find=find
pgp=gpg
ses_atime=1
trail_atime=30
backupdir=~/backup

warning="WARNING: Running this script (zxlogclean.sh) in production environment
         may destroy valuable audit trail data, which you may be legally obliged
         to retain. Be sure any such data has already been copied to a safe place."

help="This is a ZXID log cleanup script, typically run from cron(8)

$warning

Default: The default behaviour is to
   - backup most files not touched in $trail_atime days to directory $backupdir
   - remove any sessions older than 1 day by access time stamp (find ses -atime +$ses_atime)

./zxlogclean.sh              - Runs default behaviour assuming CWD to be the ZXID_PATH
./zxlogclean.sh [OPTIONS] path1 path2  - Runs in specified instance directories

Options:
 -d   Debug mode
 -n   Dryrun: do not actually delete files, just print what would be done
 -r   Really remove: delete files that by default would have been backed up
 -b   Always backup: backup all files, even those that would usually be removed
 -pgp PUBKEY   - When backing up, encrypt the backups using $pgp and public key
      at the path supplied.
 -sym SYMKEY   - When backing up, encrypt the backups using $pgp and symmetric key supplied.
        WARNING: The supplied key will be visible from the command line history and ps. For
                 best security, you should use the -pgp PUBKEY option. 
 -bdir D  Backups are to be made to directory D (default $backupdir)
 -ses N   Session deletion -atime value
 -nw  Shut down the warning about audit trail destruction
 -h   This help
 --   End of options
"

while 1; do
case "$1" in
"-d") debug=1; shift; continue;;
"-n") dryrun=1; shift; continue;;
"-r") remove=1; shift; continue;;
"-b") backup=1; shift; continue;;
"-pgp")  shift; pubkey=shift; continue;;
"-sym")  shift; symkey=shift; continue;;
"-ses")  shift; ses_atime=shift; continue;;
"-bdir") shift; backupdir=shift; continue;;
"-nw") warning=""; shift; continue;;
"-h") echo $help; exit;;
"--") shift; break; ;;
esac
done

[ $warning ] && echo $warning

[-d $backupdir -a !dryrun -a !remove] || { echo "Backup directory $backupdir does not exist. Run mkdir $backupdir"; exit; }

clean_inst() {
    dir = $1
    [ $debug ] && echo "cleaning $dir"
    if [ $dryrun ] ;   then $find ses -atime +$ses_atime -ls
    elif [ $remove ] ; then $find ses -atime +$ses_atime -delete
    else                    $find ses -atime +$ses_atime | xargs tar czf $backupdir
}

if [ "x$*" == "x" ] ; then clean("."); exit; fi

for inst in $* do
  if [ !-d $instance ] ; then echo "Instance($inst) is not a directory. Skipping."; continue; fi
  clean_inst($inst)
done

#EOF