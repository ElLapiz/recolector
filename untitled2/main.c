#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *cpuinfo = fopen("/proc/meminfo", "rb");  //rb = read binary
    char *file_content = 0;
    size_t size = 0;
    while(getdelim(&file_content, &size, 0, cpuinfo) != -1)
    {
        puts(file_content);
    }
    printf("%s", file_content);
    free(file_content);
    fclose(cpuinfo);
    return 0;
}