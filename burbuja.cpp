#include <stdio.h>

int main(){
	int n, aux, b;
	
	int a[] = {4,1,7,8,3};
	n = sizeof(a) / sizeof(a[0]);
	//ordenar de forma ascendente
	do{
		b=0;
		for(int i=0; i<n-1; i++){
			if(a[i]>a[i+1]){
				aux = a[i];
				a[i] = a[i+1];
				a[i+1] = aux;
				b=1;
			}
		}
	}while(b==1);
	
	for(int i=0; i<n; i++){
		printf("a[%d] = %d", i, a[i]);
	}
	
	return 0;
}
