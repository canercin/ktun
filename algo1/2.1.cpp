#include <stdio.h>
int main()
{
	int vize,final,but;
	printf("Vize notunuzu giriniz: ");
	scanf("%d", &vize);
	printf("Final notunuzu giriniz: ");
	scanf("%d", &final);
	int ortalama = (vize * 0.4) + (final * 0.6);
	if(ortalama < 60)
	{
		printf("Ortalamanýz: %d\nOrtalamanýz sýnýfý geçmek için yetersizdir. Bütünleme sýnavýndan aldýðýnýz nota göre yeniden hesaplama yapýlacaktýr.\n", ortalama);
		printf("Bütünleme notunuzu giriniz: ");
		scanf("%d", &but);
		int butluOrtalama = (vize * 0.4) + (but * 0.6);
		if(butluOrtalama >= 60)
		{
			printf("Ortalamanýz: %d\nOrtalamanýz sýnýfý geçmek için yeterlidir.", butluOrtalama);
		}
		else
		{
			printf("Ortalamanýz: %d\nOrtalamanýz sýnýfý geçmek için yetersizdir.", butluOrtalama);	
		}
	}
	else
	{
		if(ortalama >= 60)
		{
			printf("Ortalamanýz: %d\nOrtalamanýz sýnýfý geçmek için yeterlidir.", ortalama);		
		}
		else
		{
			printf("Ortalamanýz: %d\nOrtalamanýz sýnýfý geçmek için yetersizdir.", ortalama);	
		}	
	}
	
	
}

