#include<stdio.h>

int main(){	

	//3 2 1->2 1 3
	int a[] = {4,12,6,87,12,3,5,6};//->015
	int i,j;

	for(i=0;i<8;i++){
		for(j=0;j<7;j++){
			int temp= a[j+1];
			if(a[j]>a[j+1]){
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	
	for(i=0;i<8;i++)printf("%d\n",a[i]);
}
