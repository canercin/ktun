#include <stdio.h>
int main(){
	int girilenSayi;
	int asalSayiSayisi = 0, asalSayiToplami = 0;
	int kontrol = 0;
	while(girilenSayi >= 0){
		int sayac = 2;
		kontrol = 0;
		printf("L�tfen bir say� giriniz: ");
		scanf("%d", &girilenSayi);
		if(girilenSayi > 1){
			while(sayac < girilenSayi){
				if(girilenSayi % sayac == 0){
					kontrol = 1;
					break;
				}
				sayac++;
			}
			if(kontrol == 0){
				asalSayiSayisi++;
				asalSayiToplami = asalSayiToplami + girilenSayi;
			}
			else if(girilenSayi == 2){
				asalSayiSayisi++;
				asalSayiToplami = asalSayiToplami + girilenSayi;			
			}		
		}
	}
	float asalSayiOrtalama = (float)asalSayiToplami / (float)asalSayiSayisi;
	if(asalSayiSayisi != 0){
		printf("Girmi� oldu�unuz say�lardan asal olanlar�n�n toplam� %d\n", asalSayiToplami);
		printf("Girmi� oldu�unuz say�lardan asal olanlar�n�n ortalamas� %f", asalSayiOrtalama);
	}
	else{
		printf("Asal say� girmediniz.");
	}
}
