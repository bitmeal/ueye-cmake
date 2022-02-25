#include <stdlib.h>
#include <stdio.h>

#include <ueye.h>

int main(int argc, char const *argv[])
{
    int version = is_GetDLLVersion();
    int build = version & 0xFFFF;
    version = version >> 16;
    int minor = version & 0xFF;
    version = version >> 8;
    int major = version & 0xFF;
    
    printf("API version %d.%d.%d\n", major, minor, build);

    return 0;
}
