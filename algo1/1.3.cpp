#include <stdio.h>
#include <locale.h>
int main()
{
	char *locale;
	locale = setlocale(LC_ALL, "");
	
	int sayi1, sayi2, sayi3;
	printf("L�tfen bir say� giriniz: ");
	scanf("%d", &sayi1);
	printf("L�tfen bir say� giriniz: ");
	scanf("%d", &sayi2);
	printf("L�tfen bir say� giriniz: ");
	scanf("%d", &sayi3);
	
	int ortalama = (sayi1 + sayi2 + sayi3)/3;
	printf("Girdi�iniz 3 say�n�n ortalamas� %d\'dir", ortalama);
	return 1;
}
