#include <stdio.h>
int main(){
	char alinanMetin[500];
	puts("Bir metin giriniz:");
	gets(alinanMetin);
	for(int i = 0; alinanMetin[i] != '\0'; i++){
		if(alinanMetin[i]<=90 && alinanMetin[i]>=65){
			alinanMetin[i] = alinanMetin[i] + 32;
		}
		else if(alinanMetin[i]<=122 && alinanMetin[i]>=97){
			alinanMetin[i] = alinanMetin[i] - 32;
		}
	}
	printf("%s", alinanMetin);
}
