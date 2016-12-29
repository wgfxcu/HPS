#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


static bool switch_to_user( uid_t user_id, gid_t gp_id )
{
    if ( ( user_id == 0 ) && ( gp_id == 0 ) )
    {
            return false;
        }

    gid_t gid = getgid();
    uid_t uid = getuid();
    if ( ( ( gid != 0 ) || ( uid != 0 ) ) && ( ( gid != gp_id ) || ( uid != user_id ) ) )
    {
            return false;
        }

    if ( uid != 0 )
    {
            return true;
        }

    if ( ( setgid( gp_id ) < 0 ) || ( setuid( user_id ) < 0 ) )
    {
            return false;
        }

    return true;
}


int main(int argc, char *argv[])
{

    return 0;
}
