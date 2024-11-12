#include <stdio.h>
int main(){
	int sayac = 0;
	char alinanMetin[999];
	puts("LÜtfen bir metin giriniz:");
	gets(alinanMetin);
	
	for(int i = 0; alinanMetin[i]!='\0'; i++){
		if(alinanMetin[i] == ' ' && alinanMetin[i+1] != ' ' && alinanMetin[i-1] != ' '){
			sayac++;
		}
	}
	printf("Girilen metinde %d kadar kelime vardır.", sayac+1);
	
}
