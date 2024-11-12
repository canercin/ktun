#include <stdio.h>
int main(){
	char alinanMetin[500];
	char alinanKelime[100];
	int uzunluk = 0, kontrol = 0;
	int k,l;
	puts("Bir metin giriniz:");
	gets(alinanMetin);
	puts("Bir kelime giriniz");
	gets(alinanKelime);
	for(int i = 0; alinanKelime[i] != '\0'; i++){
		uzunluk++;
	}
	for(k = 0; alinanMetin[k] != '\0'; k++){
		if(alinanKelime[0] == alinanMetin[k]){
			kontrol = 0;
			for(l = 0; l < uzunluk; l++){
				if(alinanKelime[l] == alinanMetin[k+l]){
					kontrol++;
				}
			}
			if(uzunluk == kontrol){
				printf("Girmiþ olduðunuz kelime girmiþ olduðunuz metinde bulunmaktadýr.\nBaþlangýç indisi:%d\nBitiþ indisi:%d", k, k+l-1);
			}
		}
	}	
}
