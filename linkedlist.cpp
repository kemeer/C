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

int main(){
	
	//Olusturma
	node *root;
	root = (node*)malloc(sizeof(node));
	root->next = NULL;
	root->x = 500;
	node *iter = root;//iter gezici 
	
	for(int i=0;i<5;i++){
		ekle(root,i*10);
	}
	
	bastir(root);
	
	//Araya ekleme
	for(int i=0;i<3;i++)iter = iter->next;
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->x = 100;
	
	printf("\n\n");
	bastir(root);
	
	return 0;
}
