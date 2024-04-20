
## Dicas e truques em C ##

#
# Autor= João Batista Ribeiro
# Bugs, Agradecimentos, Críticas "construtivas"
# Mande me um e-mail. Ficarei Grato!
# e-mail: joao42lbatista@gmail.com
#
# Last update: 02/04/2024
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

## Bons Links
    https://wiki.sj.ifsc.edu.br/index.php/SOP-stdio
    http://www.cs.ecu.edu/karl/2530/fall17/Notes/lec33A.html
    https://medium.com/@zoha131/fun-with-scanf-in-c-3d7a8d310229
    https://www.cprogramming.com/tips/tip/the-power-of-scanf
    https://codeforces.com/blog/entry/56932

