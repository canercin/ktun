#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int dizi[50];
	int i = 0, toplam = 0, az = 0, fazla = 0;
	float ortalama;
	srand(time(NULL));
	for(i = 0; i<50; i++){
		dizi[i] = rand()%100;
		printf("%d\t", dizi[i]);
	}
	for(int j = 0; j<50; j++){
		toplam = toplam + dizi[j];
	}
	ortalama = (float)toplam/(float)50;
	printf("\nDizideki sayýlarýn toplamý = %d", toplam);
	printf("\nDizideki sayýlarýn ortalamasý = %f", ortalama);
	for(int k = 0; k<50; k++){
		if(dizi[k]<ortalama){
			az++;
		}
		else{
			fazla++;
		}
	}
	printf("\n\n\n\nOrtalamadan küçük olan sayýlarýn sayýsý = %d \n\n\n\nOrtalamadan Büyük olan sayýlarýn sayýsý = %d", az, fazla);
	
}
