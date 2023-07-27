struct Node {
    int info;
    struct Node *dir;
    struct Node *esq;
};
typedef struct Node *abb;
//cria
void cria(abb *r){
    *r = NULL;
};
//vazia
bool vazia(abb r){
    if(r==NULL){
        return true;
    }else{
        return false;
    }
};
//esta
bool esta(abb r,int x){
    if(vazia(r)){
        return false;
    }else if(r->info ==x){
        return true;
    }else if(x>r->info){
        esta(r->dir,x);
    }else{
         esta(r->esq,x);
    }
};
bool insere(abb *r,int x){
    if(esta(*r,x)){
        return false;
    }else{
        abb aux = new Node;
        aux->info = x;
        if(vazia(*r)){
            aux->esq = NULL;
            aux->dir = NULL;
            *r = aux;
            return true;
        }else{
            if(x>(*r)->info){
                insere((&(*r)->dir),x);
            }else{
               insere((&(*r)->esq),x); 
            }
        }
    }
};
//remove
bool remover(abb *r,int x){
    abb aux = new Node;
    if(vazia(*r)){
        return false;
    }else{
        if(esta(*r,x)){
            if((*r)->info == x){
                aux = *r;
                //sem filhos
                if((*r)->dir == NULL && (*r)->esq == NULL){
                    delete abb(aux);
                    *r = NULL;
                    return true;
                }else if((*r)->dir != NULL && (*r)->esq != NULL){//dois filhos
                    aux = (*r)->esq;
                    while(aux->dir !=NULL){
                        aux = aux->dir;
                    }
                    (*r)->info = aux->info;
                    remover(&((*r)->esq),(*r)->info);
                }else{//1 filho
                    if((*r)->esq == NULL){
                        *r = (*r)->dir;
                    }
                    else{
                        *r = (*r)->esq;
                    }
                    return true;
                    delete abb(aux);
                }
            }else{
                if(x>(*r)->info){
                    remover(&((*r)->dir),x);
                }else{
                    remover(&((*r)->esq),x);
                }
            }
        }else{
            return false;
        }
    }
};
//tamanho da arvore
int tamanho(abb r){
    int tamEsq,tamDir;
    if(vazia(r)){
        return 0;
    }else{
        tamEsq = tamanho(r->esq);
        tamDir = tamanho(r->dir);
        if(tamDir>tamEsq){
            return 1 + tamDir;
        }else{
            return 1 + tamEsq;
        }
    }
}
