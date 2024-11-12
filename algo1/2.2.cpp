#include <stdio.h>
int main()
{
	int sonSayi, aritmatikOrtalama, toplam = 0, sayac = 0;
	printf("Hangi sayýya kadar gidileceðini seçiniz: ");
	scanf("%d", &sonSayi);
	
	for(sayac; sayac <= sonSayi; sayac = sayac + 2)
	{
		toplam = toplam + sayac;		
	}
	
		aritmatikOrtalama = toplam / ((sayac - 2) / 2);
		printf("Girmiþ olduðunuz sayýya kadar olan sayýlarýn aritmatik ortalamasý %d'dir.\n", aritmatikOrtalama);
		printf("Girmiþ olduðunuz sayýya kadar olan sayýlarýn toplamý %d'dir.", toplam);
}
