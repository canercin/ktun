#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int sayi = 0;
	srand(time(NULL));
	FILE *f1;
	FILE *f2;
	f1 = fopen("dosya0.txt", "w");
	f2 = fopen("dosya1.txt", "w");
	for(int i = 0; i < 100; i++){
		sayi = rand()%101;
		if((sayi & 1<<5)){
			fprintf(f2, "%d--->", sayi);
			sayi = sayi & ~8;
			fprintf(f2, "%d\n", sayi);
		}
		else{
			fprintf(f1, "%d--->", sayi);
			sayi = sayi | 16;
			fprintf(f1, "%d\n", sayi);
		}
	}
	fclose(f1);
	fclose(f2);
}
