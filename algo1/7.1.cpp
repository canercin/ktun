#include <stdio.h>
/* MÝSSÝON COMPLETED */
struct isci{
	char adi[30];
	char soyadi[];
	int yas;
	double aylikucret;
};
struct isci bilgiAlma();
int main(){
	struct isci isci1;
	isci1 = bilgiAlma();
	printf("Ýþçinin ismi %s", isci1.adi);
	printf(" Ýþçinin soyismi %s", isci1.soyadi);
	printf(" Ýþçinin yaþý %d", isci1.yas);
	printf(" Ýþçinin ismi %f", isci1.aylikucret);
}
struct isci bilgiAlma(){
	struct isci isci1;
	printf("Ýþçinin ismini giriniz:");
	scanf("%s", &isci1.adi);
	printf("Ýþçinin soyismini giriniz:");
	scanf("%s", &isci1.soyadi);
	printf("Ýþçinin yaþýný girin:");
	scanf("%d", &isci1.yas);
	printf("iþçinin maaþýný girin:");
	scanf("%lf", &isci1.aylikucret);
	return isci1;
}


