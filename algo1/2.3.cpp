#include <stdio.h>
#include <math.h> 
int main()
{
	int sayi, aritmatikOrtalama, geometrikOrtalama, tekSayilarinToplami = 0, tekSayac = 0, ciftSayilarinCarpimi = 1, ciftSayac = 0;
	
	for(int i = 1; i <= 4; i++)
	{
		printf("%d. say�y� giriniz: ", i);
		scanf("%d", &sayi);
		
		if(sayi % 2 == 1)
		{
			tekSayilarinToplami = tekSayilarinToplami + sayi;
			tekSayac = tekSayac + 1;	
		}
		else
		{
			ciftSayilarinCarpimi = ciftSayilarinCarpimi * sayi;
			ciftSayac = ciftSayac + 1;	 
		}
	}
	
	aritmatikOrtalama = tekSayilarinToplami / tekSayac;
	geometrikOrtalama = pow(ciftSayilarinCarpimi, pow(ciftSayac, -1));
	printf("Girilen tek say�lar�n aritmatik ortalamas� %d'dir.\n", aritmatikOrtalama);
	if(ciftSayac != 0)
	{
		printf("Girilen �ift say�lar�n geometrik ortalamas� %d'dir.\n", geometrikOrtalama);	
	}
	else
	{
		printf("�ift say� girilmemi�tir.");
	}
}

	
