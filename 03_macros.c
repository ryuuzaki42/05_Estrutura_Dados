#include<stdio.h>
// https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html

#define check_code printf("\n\n%s:%d (%s)\n\n", __FILE__, __LINE__, __func__)

typedef enum {SUN, MON, TUE, WED, THU, FRI, SAT} dayWeek;
typedef enum {FEV=2, MAR=3, APR} month;

int main() {
    printf("\n%s:%d (%s)\n", __FILE__, __LINE__, __func__);
    printf("%s - %s\n", __DATE__, __TIME__);
    printf("%d  - %ld", __STDC__ ,__STDC_VERSION__);

    check_code;

    // gcc 03\ macros.c -D "DEBUG_MODE"
    #ifdef DEBUG_MODE // If defined, run code inside
        printf("\nDEBUG_MODE enabled\n");
    #endif

    #ifndef DEBUG_MODE // Check if not defined
        printf("\nDEBUG_MODE not enabled\n");
    #endif

    for (dayWeek i = SUN; i<SAT; i++){ // dayWeek is int
        printf("Day: %i\n", i);
    }

    for (month j = FEV; j<APR; j++){
        printf("Month: %i\n", j);
    }
    printf("\n");
    return 0;
}
