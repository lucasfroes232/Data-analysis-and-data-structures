
typedef struct node *ArvAvl;

ArvAvl* cria_ArvAVL();
int removeAvl(ArvAvl *raiz,int valor);
int insereAvl(ArvAvl *raiz,int valor);
int consultaAvl(ArvAvl *raiz,int valor);
void preOrdem_ArvAVL(ArvAvl *raiz);
