#include <stdio.h>
int rakamlarToplami(int x);

int main(){
	int sonuc, sayi;
	printf("Rakamlar� toplam�n� bulmak istedi�iniz say�y� giriniz:\n");
	scanf("%d", &sayi);
	sonuc = rakamlarToplami(sayi);
	printf("Girmi� oldu�unuz say�n�n (%d) rakamlar�n�n toplam�: %d",sayi, sonuc);
}

/*Fonksiyon 1*/
int rakamlarToplami(int x){
	int rakamlarToplami = 0;
	int sonRakam;
	while(x>0){
		sonRakam = x % 10;
		x = x / 10;
		rakamlarToplami = rakamlarToplami + sonRakam;
	}
	return rakamlarToplami;	
}
