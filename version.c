#include<stdio.h>
/*
    Detecting the compiler version
    gcc version.c // System default

    gcc -std=c89 version.c
    gcc -std=c90 version.c

    gcc -std=iso9899:199409 version.c
    gcc -std=c99 version.c
    gcc -std=c11 version.c
    gcc -std=c17 version.c
    gcc -std=c2x version.c

    -ansi
        In C mode, this is equivalent to -std=c90
*/

int main(){
    #ifndef __STDC_VERSION__
        printf("\nVersion: c89. __STDC_VERSION__ is not defined.\n\n");
    #else
        printf("\n__STDC_VERSION__ %ld - ", __STDC_VERSION__);

        if (__STDC_VERSION__ == 199409L) {
            printf("Version: C94\n\n");
        } else if (__STDC_VERSION__ == 199901L) {
            printf("Version: C99\n\n");
        } else if (__STDC_VERSION__ == 201112L) {
            printf("Version: C11\n");
        } else if (__STDC_VERSION__ == 201710L) {
            printf("Version: C17\n\n");
        } else if (__STDC_VERSION__ > 201710L) {
            printf("Version: C2x\n");
            printf("The next version of the ISO C standard, still under development.\n");
            printf("The support for this version is  experimental and incomplete.\n\n");
        } else {
            printf("Unknown standard\n\n");
        }
    #endif

    return 0;
}
