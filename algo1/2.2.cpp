#include <stdio.h>
int main()
{
	int sonSayi, aritmatikOrtalama, toplam = 0, sayac = 0;
	printf("Hangi say�ya kadar gidilece�ini se�iniz: ");
	scanf("%d", &sonSayi);
	
	for(sayac; sayac <= sonSayi; sayac = sayac + 2)
	{
		toplam = toplam + sayac;		
	}
	
		aritmatikOrtalama = toplam / ((sayac - 2) / 2);
		printf("Girmi� oldu�unuz say�ya kadar olan say�lar�n aritmatik ortalamas� %d'dir.\n", aritmatikOrtalama);
		printf("Girmi� oldu�unuz say�ya kadar olan say�lar�n toplam� %d'dir.", toplam);
}
