#include <stdio.h>
void asalMi(int x);

int main(){
	int sayi;
	printf("Asallýðýný kontrol etmek istediðiniz sayýyý giriniz:\n");
	scanf("%d", &sayi);
	asalMi(sayi);
}

/*Fonskiyon 1*/
void asalMi(int x){
	int kontrol = 0;
	if(x<= 1){
		printf("Girdiðiniz sayý asal deðildir.");
	}
	else if(x == 2){
		printf("Girdiðiniz sayý asaldýr");
	}
	else{
		for(int i = 2; i < x; i++){
			if(x % i == 0){
				kontrol = 1;
				break;
			}
		}
		if(kontrol == 0){
			printf("Girdiðiniz sayý asaldýr.");
		}
		else if(kontrol == 1){
			printf("Girdiðiniz sayý asal deðildir");
		}
	}
}
