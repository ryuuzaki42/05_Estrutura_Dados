#include<stdio.h>
// https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html

#define check_code printf("\n\n%s:%d (%s)\n\n", __FILE__, __LINE__, __func__)

int main() {
    printf("\n%s:%d (%s)\n", __FILE__, __LINE__, __func__);
    printf("%s - %s\n", __DATE__, __TIME__);
    printf("%d  - %ld", __STDC__ ,__STDC_VERSION__);

    check_code;

    return 0;
}
