#include<stdio.h>
#include<stdlib.h>

typedef struct sNo{
    int info;
    struct sNo *esq;
    struct sNo *dir;
}No;

typedef struct sArvBinPesq{
    No *ptRaiz;
}ArvBinPesq;

void criarArvore(No **ptRaiz){ //Inicializar
    *ptRaiz = NULL;
}

void insereComRecursao(No **ptRaiz, int info2){ //Inserção com recursão
    if (*ptRaiz == NULL){
        *ptRaiz=(No *)malloc(sizeof(No));
        if(*ptRaiz == NULL){
            printf("\nErro.Memoria nao alocada");
            return;
        }

        (*ptRaiz)->esq=NULL;
        (*ptRaiz)->dir=NULL;
        (*ptRaiz)->info=info2;
    }else{
        if (info2 < ((*ptRaiz)->info)){
            insereComRecursao(&((*ptRaiz)->esq), info2);
        } else {
            insereComRecursao(&((*ptRaiz)->dir), info2);
        }
    }
}

void insereSemRecursao(No** ptRaiz, int info2){ //Inserção com recursão
    No* aux = *ptRaiz;
    No* aux2 = NULL;
    No* novo = (No *)malloc(sizeof(No));

    if(novo == NULL){
        printf("\nErro: Memoria nao alocada");
        return;
    }

    novo->info = info2;
    novo->esq = NULL;
    novo->dir = NULL;

    while(aux != NULL){
        aux2 = aux;

        if(info2 < aux->info){
            aux = aux->esq;
        }else{
            aux = aux->dir;
        }
    }

    if(aux2 == NULL){
        *ptRaiz = novo;
    }else {
        if(info2 <aux2->info){
            (aux2)-> esq = novo;
        }else{
            (aux2)-> dir = novo;
        }
    }
}

No *MaiorDireita(No **no){ //Remoção
    if((*no)->dir != NULL){
       return MaiorDireita(&(*no)->dir);
    }else{
        No *aux = *no;

        if((*no)->esq != NULL){ // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esq!
            *no = (*no)->esq;
        }else{
            *no = NULL;
            return aux;
        }
    }
}

No *MenorEsquerda(No **no){
    if((*no)->esq != NULL){
        return MenorEsquerda(&(*no)->esq);
    } else {
        No *aux = *no;
        if((*no)->dir != NULL) { // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da dir!
            *no = (*no)->dir;
        } else {
            *no = NULL;
        }
        return aux;
    }
}

void remover(No **ptRaiz, int info2){
    if(*ptRaiz == NULL){ // esta verificacao serve para caso o info nao exista na arvore.
        printf("Numero nao existe na arvore!");
        return;
    }

    if(info2 < (*ptRaiz)->info){
        remover(&(*ptRaiz)->esq, info2);
    }else{
        if(info2 > (*ptRaiz)->info){
            remover(&(*ptRaiz)->dir, info2);
        }else{ // se nao eh menor nem maior, logo, eh o info que estou procurando! :)
            No *pAux = *ptRaiz; // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
            if(((*ptRaiz)->esq == NULL) && ((*ptRaiz)->dir == NULL)){ // se nao houver filhos...
                free(pAux);
                (*ptRaiz) = NULL;
            }else{ // so tem o filho da dir
                if((*ptRaiz)->esq == NULL){
                    (*ptRaiz) = (*ptRaiz)->dir;
                    pAux->dir = NULL;
                    free(pAux); pAux = NULL;
                }else{ //so tem filho da esq
                    if ((*ptRaiz)->dir == NULL){
                        (*ptRaiz) = (*ptRaiz)->esq;
                        pAux->esq = NULL;
                        free(pAux); pAux = NULL;
                    }else{ //Escolhi fazer o maior filho direito da subarvore esq.
                        pAux = MaiorDireita(&(*ptRaiz)->esq); //se vc quiser usar o Menor da esq, so o que mudaria seria isso:
                        pAux->esq = (*ptRaiz)->esq; // pAux = MenorEsquerda(&(*ptRaiz)->dir);
                        pAux->dir = (*ptRaiz)->dir;
                        (*ptRaiz)->esq = (*ptRaiz)->dir = NULL;
                        free((*ptRaiz));
                        *ptRaiz = pAux;
                        pAux = NULL;
                    }
                }
            }
        }
    }
}

void visita(No *raiz){
    printf("    %d\n",raiz->info);
}

void exibirEmOrdem(No *ptRaiz){ //Em ordem
    if(ptRaiz != NULL){
        exibirEmOrdem(ptRaiz->esq);
        visita(ptRaiz);
        exibirEmOrdem(ptRaiz->dir);
    }
}

void exibirPreOrdem(No *ptRaiz){ //Pré-ordem
    if(ptRaiz != NULL){
        visita(ptRaiz);
        exibirPreOrdem(ptRaiz->esq);
        exibirPreOrdem(ptRaiz->dir);
    }
}

void exibirPosOrdem(No *ptRaiz){ //Pós-ordem
    if(ptRaiz != NULL){
        exibirPosOrdem(ptRaiz->esq);
        exibirPosOrdem(ptRaiz->dir);
        visita(ptRaiz);
    }
}

int contarNos(No *ptRaiz){ //Contar nós
    if(ptRaiz == NULL){
        return 0;
    }else{
        return 1 + contarNos(ptRaiz->esq) + contarNos(ptRaiz->dir);
    }
}

int contarFolhas(No *ptRaiz){ //Contar folhas
    if(ptRaiz == NULL){
        return 0;
    }

    if(ptRaiz->esq == NULL && ptRaiz->dir == NULL){
        return 1;
    }

    return contarFolhas(ptRaiz->esq) + contarFolhas(ptRaiz->dir);
}

int maior(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int alturaArvore(No *ptRaiz){ //Altura da árvore
    if((ptRaiz == NULL) || (ptRaiz->esq == NULL && ptRaiz->dir == NULL)){
        return 0;
    }else{
        return 1 + maior(alturaArvore(ptRaiz->esq), alturaArvore(ptRaiz->dir));
    }
}

int procuraElementoSemRecursao(No *ptRaiz, int info2){ // Procura o elemento na árvore // O(log n)
    No* temp = ptRaiz;
    int parar=0;

    if(ptRaiz==NULL){
        return 0;
    }else if(temp->esq== NULL && temp->dir==NULL){
        if(temp->info == info2){
            return 1;
        }else{
            return 0;
        }
    }else if(temp->info==info2){
        return 1;
    }else{
        while(parar==0){
            if(temp->info < info2){
                if(temp->esq == NULL){
                    parar++;
                    if (temp->info==info2){
                        break;
                        return 1;
                    }else{
                        return 0;
                    }
                }else{
                    temp=temp->esq;
                        if (temp->info== info2){
                            return 1;
                            break;
                    }
                }
            }else if(temp->info > info2){
                if(temp->dir== NULL){
                    parar++;
                    if (temp->info==info2){
                        return 1;
                        break;
                    }else{
                        return 0;
                    }
                }else{
                    temp=temp->dir;
                    if (temp->info== info2){
                        return 1;
                        break;
                    }
                }
            }
        }
    }
}
No* procuraElementoComRecursao(No *ptRaiz, int info2){ // Procura o elemento na árvore // O(log n)
    No* aux;
    aux = ptRaiz;

    if(aux == NULL){
        return NULL;
    }else if(info2 < aux->info){
        return procuraElementoComRecursao(aux->esq, info2);
    }else if(info2 > aux->info){
        return procuraElementoComRecursao(aux->dir, info2);
    }else{
        return aux;
    }
}
int main(){
    //ArvBinPesq ptRaiz;
    No *ptRaiz;
    No* ptTemp;
    criarArvore(&ptRaiz);

    int info2, opcao, temp;

    while(1){
        printf("\n\n1 insere sem recursao");
        printf("\n2 insere com recursao");
        printf("\n3 remover");
        printf("\n4 exibirPreOrdem");
        printf("\n5 exibirEmOrdem");
        printf("\n6 exibirPosOrdem");
        printf("\n7 contarFolhas");
        printf("\n8 contarNos");
        printf("\n9 alturaArvore");
        printf("\n10 procuraElementoSemRecursao");
        printf("\n11 procuraElementoComRecursao");
        printf("\n0 Para sair do programa");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        printf("\n");
        switch(opcao){
            case 1:
                printf("Numero a ser inserido: ");
                scanf("%d", &info2);
                insereComRecursao(&ptRaiz, info2);
                break;
            case 2:
                printf("Numero a ser inserido: ");
                scanf("%d", &info2);
                insereSemRecursao(&ptRaiz, info2);
                break;
            case 3:
                printf("Numero a ser remvido: ");
                scanf("%d", &info2);
                remover(&ptRaiz, info2);
                break;
            case 4:
                exibirPreOrdem(ptRaiz);
                break;
            case 5:
                exibirEmOrdem(ptRaiz);
                break;
            case 6:
                exibirPosOrdem(ptRaiz);
                break;
            case 7:
                temp=contarFolhas(ptRaiz);
                printf("Quantidade de folhas: %d", temp);
                break;
            case 8:
                temp=contarNos(ptRaiz);
                printf("Quantidade de nos: %d", temp);
                break;
            case 9:
                temp=alturaArvore(ptRaiz);
                printf("Altura da arvore: %d", temp);
                break;
            case 10:
                printf("Numero a ser pesquisado: ");
                scanf("%d", &info2);

                temp = procuraElementoSemRecursao(ptRaiz, info2);

                if (temp == 1){
                    printf("\n\nElemento %d encontrado", info2);
                }else{
                    printf("\n\nElemento nao %d encontrado", info2);
                }
                break;
            case 11:
                printf("Numero a ser pesquisado: ");
                scanf("%d", &info2);

                ptTemp = procuraElementoComRecursao(ptRaiz, info2);

                if (ptTemp != NULL){
                    printf("\n\nElemento %d encontrado: %d", info2, ptTemp->info);
                }else{
                    printf("\n\nElemento nao %d encontrado", info2);
                }
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("A opcao: %d e invalida", opcao);
                break;
        }
    }
}