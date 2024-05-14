
## Dicas e truques em C ##

#
# Autor= João Batista Ribeiro
# Bugs, Agradecimentos, Críticas "construtivas"
# Mande me um e-mail. Ficarei Grato!
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

## Bons Links
    https://wiki.sj.ifsc.edu.br/index.php/SOP-stdio
    http://www.cs.ecu.edu/karl/2530/fall17/Notes/lec33A.html
    https://medium.com/@zoha131/fun-with-scanf-in-c-3d7a8d310229
    https://www.cprogramming.com/tips/tip/the-power-of-scanf
    https://codeforces.com/blog/entry/56932
