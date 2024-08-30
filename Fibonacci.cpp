#include<stdio.h>
int main(){
	
	int i;
	int x;
	int ilk=1;
	int iki=1;
	
	printf("Kac Asama:");
	scanf("%d", &x);
	
	printf("%d ",ilk);
	printf("%d ",iki);
	
	for(i=1;i<x;i++){
		int temp = iki;
		iki+=ilk;
		ilk = temp;
		printf("%d ",iki);	
	}
	
	
	return 0;
}
