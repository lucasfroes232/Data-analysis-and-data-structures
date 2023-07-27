
#include <iostream>
using std::cout;
using std::endl;
#include "ABB.h"

int main()
{
    abb b1;
    bool ok;
    cria(&b1);
    if(vazia(b1)){
        cout << "Vazio"<<endl;
    }
    //insere 10
    if(insere(&b1,10)) {
        cout<<"Inseriu 10"<<endl;
    }
    if(esta(b1,10) ){
        cout << "10 Esta"<<endl;
    }else{
        cout<< "10 Não esta"<<endl;
    }
    
    if(remover(&b1,10)){
        cout<<"Removeu 10"<<endl;
    }
    if(vazia(b1)){
        cout << "Arvore Vazia"<<endl;
        cout<<" "<<endl;
    }
    // inserir dois valores 10,11
    if(insere(&b1,10)&& insere(&b1,11)) {
        cout<<"Inseriu 10 e 11"<<endl;
    }
    cout<<"A arvore tem tamanho:"<<tamanho(b1)<<endl;
    if(esta(b1,10) && esta(b1,11)){
        cout << "10 e 11 Estao"<<endl;
    }else{
        cout<< "Não esta"<<endl;
    }
    if(remover(&b1,10)){
        cout<<"Removeu 10"<<endl;
    }
    if(esta(b1,11) ){
        cout << "11 esta"<<endl;
    }
    cout<<"A arvore tem tamanho:"<<tamanho(b1)<<endl;
    
    
    
    
    
    
}
