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
		printf("Ortalaman�z: %d\nOrtalaman�z s�n�f� ge�mek i�in yetersizdir. B�t�nleme s�nav�ndan ald���n�z nota g�re yeniden hesaplama yap�lacakt�r.\n", ortalama);
		printf("B�t�nleme notunuzu giriniz: ");
		scanf("%d", &but);
		int butluOrtalama = (vize * 0.4) + (but * 0.6);
		if(butluOrtalama >= 60)
		{
			printf("Ortalaman�z: %d\nOrtalaman�z s�n�f� ge�mek i�in yeterlidir.", butluOrtalama);
		}
		else
		{
			printf("Ortalaman�z: %d\nOrtalaman�z s�n�f� ge�mek i�in yetersizdir.", butluOrtalama);	
		}
	}
	else
	{
		if(ortalama >= 60)
		{
			printf("Ortalaman�z: %d\nOrtalaman�z s�n�f� ge�mek i�in yeterlidir.", ortalama);		
		}
		else
		{
			printf("Ortalaman�z: %d\nOrtalaman�z s�n�f� ge�mek i�in yetersizdir.", ortalama);	
		}	
	}
	
	
}

