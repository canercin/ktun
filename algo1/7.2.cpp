#include <stdio.h>
struct dersler{
	int dersKodu;
	int vize;
	int final;
	float gecmeNotu;
};
struct sahisBilgileri{
	char ad[40];
	char soyad[40];
	int ogrNo;
	struct dersler ders[5];
	
};

struct sahisBilgileri bilgiAlma();
struct dersler dersBilgiAlma();

int main(){
	struct sahisBilgileri sahis[5];
	struct dersler ders[5];
	for(int i = 0; i<5; i++){
		sahis[i] = bilgiAlma();
		for(int k = 0; k<5; k++){
			sahis[i].ders[k] = dersBilgiAlma();
		}
	}
	for(int j = 0; j<5; j++){
		printf("%d numaralý, %s %s isimli öðrencinin; ", sahis[j].ogrNo, sahis[j].ad, sahis[j].soyad);
		for(int l = 0; l<5; l++){
			printf("%d kodlu dersin vize notu %d, ", sahis[j].ders[l].dersKodu, sahis[j].ders[l].vize);
			printf("final notu %d ve geçme notu %f'dir.", sahis[j].ders[l].final, sahis[j].ders[l].gecmeNotu);
			printf("\n");
		}
		printf("\n");
	}
}
struct sahisBilgileri bilgiAlma(){
	struct sahisBilgileri sahis;
	printf("öðrencinin ismini giriniz:");
	scanf("%s", &sahis.ad);
	printf("öðrencinin soyismini giriniz:");
	scanf("%s", &sahis.soyad);
	printf("öðrencinin numarasýný giriniz:");
	scanf("%d", &sahis.ogrNo);
	return sahis;
}
struct dersler dersBilgiAlma(){
	struct dersler ders;
	printf("dersin kodunu giriniz:");
	scanf("%d", &ders.dersKodu);
	printf("dersin vize notunu giriniz:");
	scanf("%d", &ders.vize);
	printf("dersin final notunu giriniz:");
	scanf("%d", &ders.final);
	ders.gecmeNotu = (float)((ders.vize*0.4)+(ders.final*0.6));
	return ders;
}
