#include <stdio.h>
int toplam(int x);
int main(){
	int sayi1;
	printf("Hangi sayýya kadar olan sayýlarý toplamak istersiniz? \n");
	scanf("%d", &sayi1);
	printf("Girdiðiniz sayýya (%d) kadar olan sayýlarýn toplamý = %d", sayi1, toplam(sayi1));
}
int toplam(int x){
	int top = 0;
	if(x > 0){
		top = x + toplam(x - 1);
	}
	return top;
}
