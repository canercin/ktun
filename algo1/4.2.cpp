#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int dizi1[10], dizi2[10], kontrol = 0, temp;
	srand(time(NULL));
	for(int i = 0; i<10; i++){
		dizi1[i] = rand()%50;
	}	
	for(int j = 0; j<10; j++){
		dizi2[j] = rand()%50;
	}
	for(kontrol; kontrol<10; kontrol++){
		printf("%d\t", dizi1[kontrol]);
		printf("%d\n", dizi2[kontrol]);
	}
	for(int k = 0; k<=5; k++){
		temp = dizi1[2*k];
		dizi1[2*k] = dizi2[(2*k) + 1];
		dizi2[(2*k) + 1] = temp;
	}
	
	kontrol = 0;
	printf("\nDizilerin deðiþtirilmiþ hali:\n");
	for(kontrol; kontrol<10; kontrol++){
		printf("%d\t", dizi1[kontrol]);
		printf("%d\n", dizi2[kontrol]);
	}
	
	
	
}
