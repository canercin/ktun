#include <stdio.h>
#include <locale.h>
int main()
{
	char *locale;
	locale = setlocale(LC_ALL, "");
	
	int sayi1, sayi2, sayi3;
	printf("Lütfen bir sayý giriniz: ");
	scanf("%d", &sayi1);
	printf("Lütfen bir sayý giriniz: ");
	scanf("%d", &sayi2);
	printf("Lütfen bir sayý giriniz: ");
	scanf("%d", &sayi3);
	
	int ortalama = (sayi1 + sayi2 + sayi3)/3;
	printf("Girdiðiniz 3 sayýnýn ortalamasý %d\'dir", ortalama);
	return 1;
}
