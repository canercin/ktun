#include <stdio.h>
int faktoriyel(int x);
float kombinasyon(int x, int y);

int main(){
	int sayi1, sayi2;
	printf("�lk say�y� giriniz:\n");
	scanf("%d", &sayi1);
	printf("�kinci say�y� giriniz:\n");
	scanf("%d", &sayi2);
	float sonuc = kombinasyon(sayi1, sayi2);
	printf("%d say�s�n�n %d ile kombinasyonu = %f",sayi1, sayi2, sonuc);
}
	/*Fonksiyon 1*/
int faktoriyel(int x){
	int faktoriyel = 1;
	while(x>0){
		faktoriyel = faktoriyel * x;
		x--;
	}
	return faktoriyel;
}
	/*Fonksiyon 2*/
float kombinasyon(int x, int y){
	float sonuc = (float)faktoriyel(x)/(float)(faktoriyel(y) * faktoriyel(x-y));
	return sonuc;
}
