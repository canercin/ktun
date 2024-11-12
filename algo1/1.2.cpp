#include <stdio.h>
#include <locale.h>
int main()
{
	char *locale;
	locale = setlocale(LC_ALL, "");
	
	int sayi1, sayi2;
	printf("Lütfen birinci sayýyý giriniz: ");
	scanf("%d", &sayi1);
	printf("Lütfen ikinci sayýyý giriniz: ");
	scanf("%d", &sayi2);
	
	if(sayi1>sayi2)
	{
		printf("Girmiþ olduðunuz sayýlardan ilk girdiðiniz sayi olan %d daha büyüktür",sayi1);
	}
	else if(sayi1==sayi2)
	{
		printf("Girmiþ olduðunuz iki sayý birbirine eþittir.");
	}
	else
	{
		printf("Girmiþ olduðunuz sayýlardan ikincisi olan %d daha büyüktür.",sayi2);
	}
	return 0;	
}
