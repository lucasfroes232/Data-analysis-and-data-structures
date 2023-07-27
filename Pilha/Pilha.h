

//constante
#define tam 10

//struct
typedef struct{
    int topo;
    int elementos[tam];
}tPilha;

//Empilhar
void empilha(tPilha *p,int elemento,int *flag){
    if(cheio(&p) == 1){
        *flag = 0;
    }else{
        p->elementos[p->topo] = elemento;
        p->topo = p->topo + 1; 
        *flag = 1;
    }
}
//Desempilha
void desempilha(tPilha *p,int elemento,int *flag){
    if(vazia(&p) == 1){
        *flag == 0;
    }else{
        elemento = p->elementos[p->topo];
        p->topo = p->topo - 1; 
        *flag = 1;
    }
}

//Cheio
int cheio(tPilha *p){
    int flag;
    if(p->topo == tam)
        flag = 1;
    else 
        flag = 0;
        
    return flag;
    
}

//Vazia
int vazia(tPilha *p){
    int flag;
    if(p->topo == 0)
        flag == 1;
    else
        flag = 0;
    return flag;
}

//Cria 
void cria(tPilha *p){
    p->topo = 0;
}

