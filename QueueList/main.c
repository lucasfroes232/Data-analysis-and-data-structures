
#include <stdio.h>
#include "queueList.h"

int main()
{
    bool ok;
    int inf;
    Queue q;
    
    createQueue(&q);
    
    //add
    pushQueue(&q,10,&ok);
    if(ok) printf("Insert 10\n");
    pushQueue(&q,20,&ok);
    if(ok) printf("Insert 20\n");
    pushQueue(&q,30,&ok);
    if(ok) printf("Insert 30\n");
    
    printQueue(&q);
    //remove
    popQueue(&q,&inf,&ok);
    if(ok) printf("Remove: %d\n",inf);
    popQueue(&q,&inf,&ok);
    if(ok) printf("Remove: %d\n",inf);
    printQueue(&q);
    popQueue(&q,&inf,&ok);
    if(ok) printf("Remove: %d\n",inf);
    printQueue(&q);
}
