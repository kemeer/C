#include<stdio.h>
#include<stdlib.h>

struct n{
	int x;
	n *next;
};
typedef n node;

void bastir(node* r){
	while(r!=NULL){
		printf("%d\n",r->x);
		r= r->next;
	}
}

void ekle(node *r,int x){
	while(r->next!=NULL){
		r= r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
}

node* ekleSirali(node *r,int x){
	if(r==NULL){//Linked list bossa
		r=(node*)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;
		return r;
	}
	
	if(r->x>x){//ilk elemandan kucuk elemansa basa eklenir
				//root degisir 
			node* temp = (node*)malloc(sizeof(node));
			temp->x = x;
			temp->next = r;
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
	temp->x = x;
	return r;
	
	
	//Tek kutu olma durumu
//	if(r->next = NULL){
//		if{
//			node* temp = (node*)malloc(sizeof(node));
//			temp->x = x;
//			temp->next = NULL;
//			r->next= temp;
//			
//		}
//	}
}

int main(){
	node * root = NULL;
	root = ekleSirali(root,1);
	root = ekleSirali(root,12);
	root = ekleSirali(root,3);
	root = ekleSirali(root,2);
	root = ekleSirali(root,56);
	root = ekleSirali(root,34);
	//Olusturma
	
	bastir(root);
	
	return 0;
}
