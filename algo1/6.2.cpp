#include <stdio.h>
int rakamlarToplami(int x);

int main(){
	int sonuc, sayi;
	printf("Rakamlarý toplamýný bulmak istediðiniz sayýyý giriniz:\n");
	scanf("%d", &sayi);
	sonuc = rakamlarToplami(sayi);
	printf("Girmiþ olduðunuz sayýnýn (%d) rakamlarýnýn toplamý: %d",sayi, sonuc);
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
