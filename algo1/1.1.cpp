#include <stdio.h>
#include <locale.h>
int main()
{
	char *locale;
	locale = setlocale(LC_ALL, "");
	
	int sayi1;
	int sayi2;
	printf("L�tfen birinci say�y� giriniz:");
	scanf("%d",&sayi1);
	
	printf("L�tfen ikinci say�y� giriniz:");
	scanf("%d",&sayi2);
	
	int sayilarinToplami = sayi1 + sayi2;
	int sayilarinFarki = sayi1 - sayi2;
	int sayilarinCarpimi = sayi1 * sayi2;
	int sayilarinBolumu = sayi1 / sayi2;
	printf("\nGirmi� oldu�unuz iki say�n�n toplam� %d\'d�r", sayilarinToplami);
	printf("\nGirmi� oldu�unuz iki say�n�n fark� %d\'d�r", sayilarinFarki);
	printf("\nGirmi� oldu�unuz iki say�n�n �arp�m� %d\'d�r", sayilarinCarpimi);
	printf("\nGirmi� oldu�unuz iki say�n�n b�l�m� %d\'d�r", sayilarinBolumu);
	return 1;
}
