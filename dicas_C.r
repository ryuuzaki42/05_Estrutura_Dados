
## Dicas e truques em C ##

#
# Autor= João Batista Ribeiro
# Bugs, Agradecimentos, Críticas "construtivas"
# me envie um e-mail. Ficarei Grato!
# e-mail: joao42lbatista@gmail.com
#
# Last update: 14/05/2024
#

## Leitura
    char a;
    int b;
    float c;
    double d;
    char s[20];

    scanf("%c %d %f %lf %s", &a, &b, &c, &d, s);

    char %c, int %i ou %d, float %f, double %lf, string (vetor de char) %s

    ## Impressão
        endereço, ponteiro %p
        %d decimal, %o octal, %x hexadecimal, %x hexadecimal com letra maiúscula

## String ou vetor de char tem \0 no final
    Alocar sempre com N + 1

## Não use gets()
    ## Use fgets
        char s[1001];
        fgets(s, 1001, stdin);

## Limpar o buffer do teclado
    ## Não use fflush(stdin)

    setbuf(stdin, NULL);

## No scanf lendo char, o & é opcional
## No scanf lendo vetor de char, o & não é usado
    char s[1001];
    scanf("%s", s);

## Descarta \n - enter depois do um int
    scanf("%d%*c", &n);

## Um espaço " %c" - elimina “ ”, tab e \n
    scanf(" %c", &a);

    ## Ou combinar dos dois lados
        scanf(" %c ", &mov);

## Em certas parte pode utilizar getchar para limpar partes do lixo do buffer do teclado
    mov = getchar();

## Leitura de valores e descartar outros
    int dia, mes, ano;
    printf("\n1 Digite uma data no formato dia/mes/ano: ");
    scanf("%d/%d/%d", &dia, &mes, &ano); // Descarta os /
    printf("Data : %d/%d/%d", dia, mes, ano);

    printf("\n2 Digite uma data no formato dia/mes/ano:: ");
    scanf("%d%*c%d%*c%d", &dia, &mes, &ano); // Descarta qualquer character de tamanho 1
    printf("Data: %d/%d/%d", dia, mes, ano);

        // %*c would exclude one character. Remember, '/n' and '/t' are single characters
        // %*d would exclude one integer
        // %*f would exclude one float
        // %*s would exclude one word

## Dividir entrada em quantidade de dígitos
    int n1, n2, n3;
    printf("Digite um número com com pelo menos 6 digitos: ");
    scanf("%1d%2d%d", &n1, &n2, &n3); // 1 dígito para n1, 2 em n2, os restar em n3
    printf("n1: %d n2: %d n3: %d", n1, n2, n3);

## Dividir entrada em tipos de valores
    char c;
    float f;
    printf("\nDigite um numero, uma letra e um valor real: ");
    scanf("%d %c %f", &n1, &c, &f);
    printf("n1: %d c: %c f: %f\n", n1, c, f);

## Impressão tabular com espaço automáticos
    /%-Xs => - alinhamento a esquerda, X o tamanho do texto, s o tipo
    /%Xs => sem o -, alinhamento a direita

    // %-12d %12d %-12f %12f

    // %-12.3f %12.4f float e double com a quantidade de casas decimais

    printf("\n%-12s %-12s %s\n", "Nome", "Idade", "Sexo");
    printf("%-12s %-12d %c\n", "Marcelo", 39, 'M');
    printf("%-12s %-12.3f %c\n", "Marina", 9.7, 'F');
    printf("%-12s %-12d %c\n", "Luis", 11, 'M');

    printf("\n%12s %12s %s\n", "Nome", "Idade", "Sexo");
    printf("%12s %12d %c\n", "Marcelo", 39, 'M');
    printf("%12s %12.4f %c\n", "Marina", 9.7, 'F');
    printf("%12s %12d %c\n", "Luis", 11, 'M');

## Valores grandes com muitos zeros
    int teste = (1000 * 1000 * 1000);
    printf("\n teste: %d", teste);

    teste = 1e+9;
    printf("\n teste: %d\n", teste);

    #define _000 *1000
    #define TAM 1 _000 _000

    int main(){
        printf("TAM: %d\n", TAM);
    }

## Versão do C - std version
    ## Flags
        -Wall      # warnings
        -Wextra    # extra warning
        -Wpedantic # enforces ISO C and ISO C++ standards
        -O3        # -O Optimize, -O1 -O2 -O3, 3 optimize more, -O0 Reduce compilation time, is the default
        -ansi      # In C, this is equivalent to -std=c90. In C++, it is equivalent to -std=c++98

    ## -std
        -std=$stdVersion
        stdVersion="c99" # c89 c99 c11 c17 c18

    gcc -Wall -Wextra -Wpedantic -O3 -std=$stdVersion "$file" -o test.out
    gcc -Wall -Wextra -Wpedantic -O3 -ansi "$file" -o test.out

## Bons Links
    https://wiki.sj.ifsc.edu.br/index.php/SOP-stdio
    http://www.cs.ecu.edu/karl/2530/fall17/Notes/lec33A.html
    https://medium.com/@zoha131/fun-with-scanf-in-c-3d7a8d310229
    https://www.cprogramming.com/tips/tip/the-power-of-scanf
    https://codeforces.com/blog/entry/56932
