#include <stdio.h>
#include <locale.h>
int main()
{
	char *locale;
	locale = setlocale(LC_ALL, "");
	
	int sayi1, sayi2;
	printf("L�tfen birinci say�y� giriniz: ");
	scanf("%d", &sayi1);
	printf("L�tfen ikinci say�y� giriniz: ");
	scanf("%d", &sayi2);
	
	if(sayi1>sayi2)
	{
		printf("Girmi� oldu�unuz say�lardan ilk girdi�iniz sayi olan %d daha b�y�kt�r",sayi1);
	}
	else if(sayi1==sayi2)
	{
		printf("Girmi� oldu�unuz iki say� birbirine e�ittir.");
	}
	else
	{
		printf("Girmi� oldu�unuz say�lardan ikincisi olan %d daha b�y�kt�r.",sayi2);
	}
	return 0;	
}
