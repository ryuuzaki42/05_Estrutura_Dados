#include<stdio.h>
#include<string.h>

void print_msg(char* msg_1, char* msg_2, int x){
    char format[20] = "\n%-12s %-6s ";
    strcat(format, msg_2); // e.g. "%-15s %-4s %d" printf("%s", format);

    printf(format, msg_1, msg_2, x);
}

void print_binary(unsigned int number){
    if (number >> 1)
        print_binary(number >> 1);

    putc((number & 1) ? '1' : '0', stdout);
}

int main(){
    int x;
    printf("Digite um número: ");
    scanf("%d", &x);

    print_msg("Integer", "%i", x);
    print_msg("Decimal", "%d", x);
    print_msg("Unsigned", "%u", x);
    print_msg("Octal", "%o", x);
    print_msg("hexadecimal", "%x", x);
    print_msg("HEXADECIMAL", "%X", x);

    // Numero negativo faz CP_1 e CP_2 (CP complemento)
    // CP_1 de negativo, inverte o valor, 0 to 1 e 1 to 0. 1 em d, 0001 -> 1110
    // CP_2 adiciona 1 no CP_1. 1110 + 1 = 1111

    printf("\nBinary       func   ");
    print_binary(x);
    printf("\n-(Binary)    func   ");
    print_binary(-x);

    printf ("\n\nCharacters: %c %c \n", 'A', 65);
    printf ("Decimals: %d %ld\n", 1977, 650000L);
    printf ("Preceding with blanks: %10d \n", 1977);
    printf ("Preceding with zeros: %010d \n", 1977);
    printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
    printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
    printf ("Width trick: %*d \n", 5, 10);
    printf ("%s\n\n", "A string");

    return 0;
}
