#include <stdio.h>
#include <locale.h>
int main()
{
	char *locale;
	locale = setlocale(LC_ALL, "");
	
	int sayi1;
	int sayi2;
	printf("Lütfen birinci sayýyý giriniz:");
	scanf("%d",&sayi1);
	
	printf("Lütfen ikinci sayýyý giriniz:");
	scanf("%d",&sayi2);
	
	int sayilarinToplami = sayi1 + sayi2;
	int sayilarinFarki = sayi1 - sayi2;
	int sayilarinCarpimi = sayi1 * sayi2;
	int sayilarinBolumu = sayi1 / sayi2;
	printf("\nGirmiþ olduðunuz iki sayýnýn toplamý %d\'dýr", sayilarinToplami);
	printf("\nGirmiþ olduðunuz iki sayýnýn farký %d\'dýr", sayilarinFarki);
	printf("\nGirmiþ olduðunuz iki sayýnýn çarpýmý %d\'dýr", sayilarinCarpimi);
	printf("\nGirmiþ olduðunuz iki sayýnýn bölümü %d\'dýr", sayilarinBolumu);
	return 1;
}
