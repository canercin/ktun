#include <stdio.h>
int toplam(int x);
int main(){
	int sayi1;
	printf("Hangi say�ya kadar olan say�lar� toplamak istersiniz? \n");
	scanf("%d", &sayi1);
	printf("Girdi�iniz say�ya (%d) kadar olan say�lar�n toplam� = %d", sayi1, toplam(sayi1));
}
int toplam(int x){
	int top = 0;
	if(x > 0){
		top = x + toplam(x - 1);
	}
	return top;
}
