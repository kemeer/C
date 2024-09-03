#include<stdio.h>
#include<stdlib.h>
#include "stackArr.h"

int *dizi=NULL;
int boyut=2,tepe=0;

stack* tanim(){
    stack *s = (stack*)malloc(sizeof(stack));

    s->dizi = NULL;
    s->boyut = 2;
    s->tepe = 0;

    return s;
}

int pop(stack *s){
    if(s->tepe<=0 || s->dizi==NULL){
        printf("Dizi bos\n");
        return -1;
    }

    if(s->tepe<=boyut/4 && s->boyut>2){
        int *dizi2= (int*)malloc(sizeof(int)*(s->boyut/2));
        for (int  i = 0; i < s->tepe; i++)
        {
            dizi2[i] = dizi[i];
        }
        free(s->dizi);
        s->dizi = dizi2;
        s->boyut /=2;
    }
    return s->dizi[--s->tepe];
}
void push(int a, stack *s){
    if(s->dizi==NULL){
            s->dizi = (int*)malloc(sizeof(int)*2);
    }
    if(s->tepe >= s->boyut-1){
        int *dizi2= (int*)malloc(sizeof(int)*(s->boyut*2));
        for (int  i = 0; i < s->tepe; i++)
        {
            dizi2[i] = s->dizi[i];
        }
        free(s->dizi);
        s->dizi = dizi2;
        s->boyut *=2;
    }
 
    s->dizi[s->tepe] = a;
    s->tepe++; 
}

void bastir(stack *s){
    printf("Boyut:%d ",s->boyut);
    for(int i = 0;i<s->tepe;i++){
        printf("%d ",s->dizi[i]);
    }
}
 