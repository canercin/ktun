#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i, eklenenSayi;
	srand(time(NULL));
	FILE *dosya;
	dosya = fopen("sayilar.txt","w");
	if(dosya==NULL){
		printf("Dosya a��lamad�");
		return 0;
	}
	for(i = 0; i<100; i++){
		eklenenSayi = rand()%1001;
		fprintf(dosya,"%d\n",eklenenSayi);	
	}
	printf("Dosyaya yazma ba�ar�yla ger�ekle�ti");
	fclose(dosya);	
}
