#include <stdio.h>
int bitKaydir(int x, int y);
int main(){
	int sayi, kayOp;
	printf("De�eri ile oynamak istedi�iniz say�y� giriniz: \n");
	scanf("%d", &sayi);
	printf("Ka� bit kayd�rmak istedi�inizi giriniz: \n");
	scanf("%d", &kayOp);
	printf("%d",bitKaydir(sayi ,kayOp));
}
int bitKaydir(int x, int y){
	for(int i = 0; i<y; i++){
		if(x & (1 << 8*sizeof(int) - 1)){
			x = x << 1;
			x = x | 1;
		}
		else{
			x = x << 1;
		}
	}
	return x;
}
