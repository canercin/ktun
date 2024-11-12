#include <stdio.h>
int asalMi(int x);

int main(){
	FILE *dosya1; 
	FILE *dosya2;
	int alinanSayi;
	dosya1 = fopen("sayilar.txt","r");
	dosya2 = fopen("sayilar2.txt","w");
	if(dosya1 == NULL){
		printf("Say�lar�n okundu�u belge a��l�rken hata meydana geldi");
	}
	if(dosya2 == NULL){
		printf("Asal say�lar�n yaz�ld��� belge a��l�rken hata meydana geldi");
	}
	while(!feof(dosya1)){
		fscanf(dosya1,"%d",&alinanSayi);
		if(asalMi(alinanSayi)){
			fprintf(dosya2,"%d\n", alinanSayi);
		}
	}
	fclose(dosya1);
	fclose(dosya2);
	printf("��lem ba�ar�yla ger�ekle�ti");
}
int asalMi(int x){
	int kontrol = 0;
	if(x<= 1){
		return 0;
	}
	else if(x == 2){
		return 1;
	}
	else{
		for(int i = 2; i < x; i++){
			if(x % i == 0){
				kontrol = 1;
				break;
			}
		}
		if(kontrol == 0){
			return 1;
		}
		else if(kontrol == 1){
			return 0;
		}
	}
}
