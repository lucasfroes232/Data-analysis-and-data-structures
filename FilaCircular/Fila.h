//Constantes
#define tam 10

//struct
typedef struct{
    int primeiro;
    int ultimo;
    int nroElementos;
    int elementos[tam];
}tFila;

//criar tFila
void criar(tFila *f){
    f->nroElementos = 0;
    f->ultimo = 0;
}

//checar vazia
int vazia(tFila *f){
    int flag;
    if(f->nroElementos == 0)
        flag = 1;
    else
        flag = 0;
    
    return flag;
}
//checar cheia
int cheia(tFila *f){
    int flag;
    if(f->nroElementos == tam)
        flag = 1;
    else
        flag = 0;
    
    return flag;
}
//inserir elemento
void inserir(tFila *f,int elemento, int *deuCerto){
    if(cheia(&f) == 0){
        f->nroElementos         = f->nroElementos + 1;
        f->elementos[f->ultimo] = elemento;
        f->ultimo               = f->ultimo + 1;
        deuCerto                = 1;
    }else{
        deuCerto = 0;
    }
}
//retirar elemento
void retirar(tFila *f,int *elemento, int *deuCerto){
    if(vazia(&f) == 0){
        f->nroElementos         = f->nroElementos - 1;
        *elemento               = f->elementos[f->primeiro];
        //ciclar a primeira pos
        if(f->primeiro == 10){
            f->primeiro = 1;
        }else{
            f->primeiro = f->primeiro + 1;
        }
        deuCerto                = 1;
    }else
        deuCerto = 0;
}
