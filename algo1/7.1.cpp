#include <stdio.h>
/* M�SS�ON COMPLETED */
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
	printf("���inin ismi %s", isci1.adi);
	printf(" ���inin soyismi %s", isci1.soyadi);
	printf(" ���inin ya�� %d", isci1.yas);
	printf(" ���inin ismi %f", isci1.aylikucret);
}
struct isci bilgiAlma(){
	struct isci isci1;
	printf("���inin ismini giriniz:");
	scanf("%s", &isci1.adi);
	printf("���inin soyismini giriniz:");
	scanf("%s", &isci1.soyadi);
	printf("���inin ya��n� girin:");
	scanf("%d", &isci1.yas);
	printf("i��inin maa��n� girin:");
	scanf("%lf", &isci1.aylikucret);
	return isci1;
}


