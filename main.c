#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct elemento{
    int dados;
    struct elemento *prox;
}Elem;

typedef struct fila{
    struct elemento *inicio;
    struct elemento *fim;
}Fila;

Fila * cria_fila(){
    Fila *fi = (Fila *) malloc (sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
    }
    return fi;
}

int insere_fila(Fila *fi, int valor){
    Elem *novo;
    if(fi == NULL){
        return 0;
    }
    novo = (Elem *) malloc (sizeof(Elem));
    if(novo == NULL){
        return 0;
    }

    novo->dados = valor;
    novo->prox = NULL;

    if(fi->inicio == NULL){
        fi->inicio = novo;
    }
    else{
     fi->fim->prox = novo;
    }
     fi->fim = novo;
     return 1;

}

void Imprime(Fila *fi)
{
    Elem *aux;
    aux = fi->inicio;
if(aux == NULL)
    printf("\nFila vazia.\n");

    printf("\nFila: \n");
    while(aux != NULL){
        printf(" %d ",aux->dados);
        aux = aux->prox;
    }
    printf("\n");
}

int remove_fila(Fila *fi)
{
    Elem *no; int dado;

    if(fi == NULL)
        return 0;
    if(fi->fim == NULL)
        return 0;

    no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    dado = no->dados;

    if(fi->inicio == NULL)
        fi->fim = NULL;
    free(no);
    return dado;
}

 int tamanho(Fila *fi)
 {
     int cont =0; Elem *no;
     if(fi == NULL)
     {
         return 0;
     }
     no = fi->inicio;
     while(no)
     {
         cont++;
         no = no->prox;
     }
     return cont;
 }


int main (){
    setlocale(LC_ALL, "Portuguese");
    Fila *fi,*f2,*f3;
    int aux, resp,tamanhof;
    fi = cria_fila();
    f2 = cria_fila();
    f3 = cria_fila();
    if(fi == NULL){ //!f1 tbm funciona
        printf("Erro na criação");
        return 0;
    }
    if(f2 == NULL){ //!f1 tbm funciona
        printf("Erro na criação");
        return 0;
    }
    if(f3 == NULL){ //!f1 tbm funciona
        printf("Erro na criação");
        return 0;
    }
    int opcao = 0;
    do{
        system("cls");
        printf("\n [1] - Criar Fila 1");
        printf("\n [2] - Imprime Fila");
        printf("\n [3] - Remover Elemento da Fila 1");
        printf("\n [4] - Criar Fila 2");
        printf("\n [5] - Criar Fila 3 (Concatenção das filas 1 e 2)");
        printf("\n [6] - Imprime Fila 2");
        printf("\n [7] - Imprime Fila 3");
        printf("\n [8] - Remover Elemento negativo da fila 3");
        printf("\n [9] - Criar Fila 3 (União das filas 1 e 2)");
        printf("\n [0] - Sair");
        printf("\n Digite a opcao: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                system("cls");
                printf("\n [1] - Digite o novo valor para a fila F1: ");
                scanf("%d", &aux);
                resp = insere_fila(fi, aux);
                if(resp == 0){
                    printf("\n ERRO\n");
                }else{
                    printf("\n Inserido!\n");
                    getch();
                }
            break;
            case 2:
               Imprime(fi);
               break;
            case 3:
                Imprime(fi);
             printf("\nValor removido: %d", remove_fila(fi));
             getch();
                break;
            case 4:
                 system("cls");
                printf("\n [1] - Digite o novo valor para a fila F2: ");
                scanf("%d", &aux);
                resp = insere_fila(f2, aux);
                if(resp == 0){
                    printf("\n ERRO\n");
                }else{
                    printf("\n Inserido!\n");
                    getch();
                }
                break;
                case 5:
                    while(fi->inicio){
                        resp = remove_fila(fi);
                        insere_fila(f3,resp);
                    }
                    while(f2->inicio){
                        resp = remove_fila(f2);
                        insere_fila(f3,resp);
                    }
                    printf("\nJunção de Filas criadas.\n");
                    getch();

                break;
                case 6:
                    Imprime(f2);
                    getch();
                    break;
                case 7:
                    Imprime(f3);
                    getch();
                    break;
                    case 8:
                    Imprime(f3);
                    tamanhof = tamanho(f3);
                   for(int i =0; i<tamanhof; i++){

                        resp = remove_fila(f3);
                        if(resp>0){
                        insere_fila(f3,resp);
                        }
                    }
                    printf("\nElementos negativos removidos.\n");
                    Imprime(f3);
                    getch();
                    break;
        }
    }while(opcao != 0);
    return 0;
}

void menu(){
    system("cls");
    printf("\n1 - Inserir elementos na Fila 1\n");
    printf("\n6 - Finalizar");
}
