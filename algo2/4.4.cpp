#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	FILE *txt;
	int *d, k;
	int sayi, oSayi, kacTane = 0;
	txt = fopen("sayi.txt", "w");
	if(txt == NULL){
		printf("Dosya açýlýmý baþarýsýz.");
	}
	else{
		for(int i = 0; i < 100; i++){
			sayi = rand()%101;
			fprintf(txt, "%d\n", sayi);
			if(sayi & 1<<5){
			}
			else{
				kacTane++;
			}
		}
		d = (int *) malloc(kacTane * sizeof(int));
		fclose(txt);
		txt = fopen("sayi.txt", "r");
		int k = 0;
		for(int j = 0; j < 100; j++){
			fscanf(txt, "%d", &oSayi);
			if(oSayi & 1<<5){
			}
			else{
				while(k <= kacTane){
					*(d+k) = oSayi;
					printf("--- %d\n", k);
					k++;
				}
			}
		}
		for(int y = 0; y <= kacTane; y++){
			printf("%d\n", *(d+y));
		}
	}
	free(d);
	fclose(txt);
}
