#include <stdio.h>
void asalMi(int x);

int main(){
	int sayi;
	printf("Asall���n� kontrol etmek istedi�iniz say�y� giriniz:\n");
	scanf("%d", &sayi);
	asalMi(sayi);
}

/*Fonskiyon 1*/
void asalMi(int x){
	int kontrol = 0;
	if(x<= 1){
		printf("Girdi�iniz say� asal de�ildir.");
	}
	else if(x == 2){
		printf("Girdi�iniz say� asald�r");
	}
	else{
		for(int i = 2; i < x; i++){
			if(x % i == 0){
				kontrol = 1;
				break;
			}
		}
		if(kontrol == 0){
			printf("Girdi�iniz say� asald�r.");
		}
		else if(kontrol == 1){
			printf("Girdi�iniz say� asal de�ildir");
		}
	}
}
