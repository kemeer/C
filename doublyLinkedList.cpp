#include<stdio.h>
#include<stdlib.h>

struct n{
	int x;
	n *next;
	n* prev;
};
typedef n node;

void bastir(node* r){
	while(r!=NULL){
		printf("%d\n",r->x);
		r= r->next;
	}
	printf("\n");
}

node* ekleSirali(node *r,int x){
	if(r==NULL){//Linked list bossa
		r=(node*)malloc(sizeof(node));
		r->next = NULL;
		r->prev = NULL;
		r->x = x;
		return r;
	}
	
	if(r->x>x){//ilk elemandan kucuk elemansa basa eklenir
				//root degisir 
			node* temp = (node*)malloc(sizeof(node));
			temp->x = x;
			temp->next = r;
			r->prev = temp;
			r= temp;
			return r;
		}
	
	node *iter= r;
	while(iter->next!=NULL && iter->next->x <x){//bos degilse benden daha buyuk eleman gorene kadar devam et
		iter= iter->next;
	} 
	node * temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->prev = iter;
	if(temp->next!=NULL)temp->next->prev = temp;
	temp->x = x;
	return r;
}

node *sil(node *r,int x){
	node *temp,*iter=r;
	
	if(r->x==x){
		temp = r;
		r = r->next;
		free(temp);
		return r;
	}
		
	while(iter->next !=NULL && iter->next->x!=x)iter = iter->next;
	
	if(iter->next==NULL){
		printf("Sayi bulunamadi");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	if(iter->next!=NULL)iter->next->prev = iter;
	return r;
	
}

int main(){
	node * root = NULL;
	root = ekleSirali(root,1);
	root = ekleSirali(root,12);
	root = ekleSirali(root,3);
	root = ekleSirali(root,2);
	root = ekleSirali(root,56);
	root = ekleSirali(root,34);
	
	bastir(root);
	
	root = sil(root,2);
	
	bastir(root);
	
	return 0;
}
