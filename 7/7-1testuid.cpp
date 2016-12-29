#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    uid_t uid = getuid();
    uid_t euid = geteuid();

    printf("userid is %d, effective userid is:%d \n", uid, euid);

    return 0;
}
