#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*int main(){
	srand(time(NULL));
	FILE *d1;
	int sayi, kacTane = 0;
	int *d;
	d1 = fopen("sayi.txt", "w");
	if(d1 != NULL){
		for(int i = 0; i < 100; i++){
			sayi = rand()%101;
			fprintf(d1, "%d\n", sayi);
			if(sayi & 1<<5){
			}
			else{
				kacTane++;
			}
		}
		fclose(d1);
		printf("Dosya a��l�m� ba�ar�l�, gerekli bilgiler dosyaya yaz�ld�.\n");
		printf("%d\n", kacTane);
		d = (int *) malloc(kacTane * sizeof(int));
		d1 = fopen("sayi.txt", "r");
		for(int j = 0; j < 100; j++){
			fscanf(d1, "%d\n", &sayi);
			printf("--%d\n", sayi);
		}
		fclose(d1);
	}
	
	else{
		printf("Dosya a��l�m�nda hata olu�tu.");
	}

	
	free(d);
}*/
int main(){
	int sayi;
	FILE *d1;
	d1 = fopen("sayi.txt", "w");
	if(d1 != NULL){
		for(int i = 0; i < 100; i++){
			sayi = rand()%101;
			fprintf(d1, "%d\n", sayi);
		}
		fclose(d1);
		printf("Dosya a��l�m� ba�ar�l�, gerekli bilgiler dosyaya yaz�ld�.\n");
		d1 = fopen("sayi.txt", "r");
		for(int j = 0; j < 100; j++){
			fscanf(d1, "%d\n", &sayi);
			printf("--%d\n", sayi);
		}
		fclose(d1);
	}
	
	else{
		printf("Dosya a��l�m�nda hata olu�tu.");
	}
}
