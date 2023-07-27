#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct node
{
    /* data */
    int alt;
    int info;
    struct node *esq;
    struct node *dir;
};

//altura
int altNo(struct node* no){
    if(no==NULL)
        return -1;
    else
        return no->alt;
}
//fator de balanceamento
int balanceamento(struct node *no){
    return labs(altNo(no->esq)-altNo(no->dir));
}
//maior valor
int maior(int x,int y){
    if (x>y)
        return x;
    else
        return y;
}
//printar em pre ordem
void preOrdem_ArvAVL(ArvAvl *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("No %d/altura: %d\n",(*raiz)->info,altNo(*raiz));
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}
//===========================//
//criar
ArvAvl* cria_ArvAVL(){
    ArvAvl* raiz = (ArvAvl*) malloc(sizeof(ArvAvl));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}
//busca 
int consultaAvl(ArvAvl *raiz,int info){
    if(*raiz == NULL){
        return 0;
    }else{
        if(info == (*raiz)->info){
            return 1;
        }else{
            if( info > (*raiz)->info){
                consultaAvl(&(*raiz)->dir,info);
            }else{
                 consultaAvl(&(*raiz)->esq,info);
            }
        }
    }
}
//rotacao direita
void rotacaoLL(ArvAvl *raiz){
    struct node *no;
    no = (*raiz)->esq;
    (*raiz)->esq= no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(altNo((*raiz)->esq),altNo((*raiz)->dir))+1;
    no->alt = maior(altNo(no->esq),(*raiz)->alt)+1;
    *raiz = no;
}
//rotacao esquerda
void rotacaoRR(ArvAvl *raiz){
    struct node *no;
    no = (*raiz)->dir;
    (*raiz)->dir= no->esq;
    no->esq = *raiz;
    (*raiz)->alt = maior(altNo((*raiz)->esq),altNo((*raiz)->dir))+1;
    no->alt = maior(altNo(no->dir),(*raiz)->alt)+1;
    *raiz = no;
}
//rotacao esquerda-direita
void rotacaoLR(ArvAvl *raiz){
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}
//rotacao direita-esquerda
void rotacaoRL(ArvAvl *raiz){
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}
//inserir
int insereAvl(ArvAvl *raiz,int valor){
    int res;
    if(*raiz == NULL){
        struct node *novo;
        novo =(struct node*)malloc(sizeof(struct node));
        if(novo ==NULL)
            return 0;
        novo->info= valor;
        novo->alt=0;
        novo->esq=NULL;
        novo->dir=NULL;
        *raiz = novo;
        return 1;
    }
    struct node* atual = *raiz ;
    if(valor<atual->info){
        if((res=insereAvl(&(atual->esq),valor))==1){
            if(balanceamento(atual)>=2){
                if(valor<(*raiz)->esq->info){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }else{
        if(valor>atual->info){
            if((res=insereAvl(&(atual->dir),valor))==1){
                if(balanceamento(atual)>=2){
                    if(valor>(*raiz)->dir->info){
                        rotacaoRR(raiz);
                    }else{
                        rotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor ja existe\n");
            return 0;
        }

    }
    atual->alt = maior(altNo(atual->esq),altNo(atual->dir))+1;
    return res;
}
//tratar remocao de no com 2 filhos 
struct node* procuraSuc(struct node*atual){
    struct node *no = atual;
    struct node *no2 = atual->esq;
    while(no2!=NULL){
        no = no2;
        no2 = no2->esq;
    }
    return no;
}
//remocao
int removeAvl(ArvAvl *raiz,int valor){
   if(raiz==NULL){
    printf("valor não existe!\n");
    return 0;
   }
   int res;
   if(valor<(*raiz)->info){
    if((res=removeAvl(&(*raiz)->esq,valor))==1){
        if(balanceamento(*raiz)>=2){
            if(altNo((*raiz)->dir->esq)<=altNo((*raiz)->dir->dir)){
                rotacaoRR(raiz);
            }
            else
                rotacaoRL(raiz);
        }
    }
   }
   if(valor>(*raiz)->info){
        if((res=removeAvl(&(*raiz)->dir,valor))==1){
            if(balanceamento(*raiz)>=2){
                if(altNo((*raiz)->esq->dir) <= altNo((*raiz)->esq->esq))
                        rotacaoLL(raiz);
                else
                        rotacaoLR(raiz);
            }
        }
   }
   if((*raiz)->info == valor){
	    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){// 1 filho ou nenhum
			struct node* oldNode = (*raiz);
			if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
			free(oldNode);
		}else { //  2 filhos
			struct node* temp = procuraSuc((*raiz)->dir);
			(*raiz)->info = temp->info;
			removeAvl(&(*raiz)->dir, (*raiz)->info);
            if(balanceamento(*raiz) >= 2){
				if(altNo((*raiz)->esq->dir) <= altNo((*raiz)->esq->esq))
					rotacaoLL(raiz);
				else
					rotacaoLR(raiz);
			}
		}
        return 1;
	}
	(*raiz)->alt = maior(altNo((*raiz)->esq),altNo((*raiz)->dir)) + 1;
	return res;
}

