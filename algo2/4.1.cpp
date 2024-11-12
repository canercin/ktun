#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	int *d;
	d = (int *) malloc(20*sizeof(int));
	int temp;
	for(int i = 0; i < 20; i++){
		*(d+i) = rand()%101;
	}
	for(int j = 0; j < 20; j++){
		printf("%d. %d\t", j+1, *(d+j));
	}
	printf("\n\n ---------- Sýralanmýþ Hali (b->k) ---------- \n\n");
	for(int k = 0; k < 20; k++){
		for(int l = k + 1; l < 20; l++){
			if(*(d+k) > *(d+l)){
				temp = *(d+l);
				*(d+l) = *(d+k);
				*(d+k) = temp;
			}
		}
	}
	for(int m = 19; m >= 0; m--){
		printf("%d. %d\t", m+1, *(d+m));
	}
	free(d);
}
