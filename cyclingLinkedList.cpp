#include<stdio.h>
#include<stdlib.h>

struct n{
	int x;
	n *next;
};
typedef n node;

void bastir(node* r){
	node*iter = r;
	printf("%d\n",iter->x);
	iter =iter->next;
	while(iter!=r){
		printf("%d\n",iter->x);
		iter=iter->next;
	}
	printf("\n");
}

void ekle(node *r,int x){
	node * iter = r;
	
	while(iter->next!=r){
		iter= iter->next;
	}
	iter->next = (node*)malloc(sizeof(node));
	iter->next->x = x;
	iter->next->next = r;
}

node* ekleSirali(node *r,int x){
	if(r==NULL){//Linked list bossa
		r=(node*)malloc(sizeof(node));
		r->next = r	;
		r->x = x;
		return r;
	}
	
	if(r->x>x){//ilk elemandan kucuk elemansa basa eklenir
				//root degisir 
			node* temp = (node*)malloc(sizeof(node));
			temp->x = x;
			temp->next = r;
			node*iter =r;
			while(iter->next!=r){
				iter= iter->next;
			}
			iter->next = temp;
			
			return r;
		}
	
	node *iter= r;
	while(iter->next!=r && iter->next->x <x){//bos degilse benden daha buyuk eleman gorene kadar devam et
		iter= iter->next;
	} 
	node * temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->x = x;
	return r;
}

node *sil(node *r,int x){
	node *temp,*iter=r;
	
	if(r->x==x){
		while(iter->next!=r){
			iter=iter->next;
		}
		iter->next = r->next;
		free(r);
		temp = r;
		r = r->next;
		free(temp);
		return iter->next;
	}
		
	while(iter->next !=r && iter->next->x!=x)iter = iter->next;
	
	if(iter->next==r){
		printf("Sayi bulunamadi");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
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
	root = ekleSirali(root,6);
	bastir(root);
	
	root = sil(root,2);
	
	bastir(root);
	
	return 0;
}
