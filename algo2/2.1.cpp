#include <stdio.h>
int obeb(int x,int y);
int main(){
	int sayi1, sayi2;
	printf("1.sayýyý giriniz: \n");
	scanf("%d", &sayi1);
	printf("2.sayýyý giriniz: \n");
	scanf("%d", &sayi2);
	printf("OBEB(%d,%d) = %d", sayi1, sayi2, obeb(sayi1, sayi2));
}
int obeb(int x, int y){
	int temp;
	if(x == 0){
		return y;
	}
	else if(y == 0){
		return x;
	}
	else{
		return obeb(y, x%y);
	}
}
