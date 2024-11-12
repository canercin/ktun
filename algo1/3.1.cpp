#include <stdio.h>
int main(){
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
			if((i+j) >=6){
				printf("#");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	/* -------------------------------------*/
	for(int k = 4; k >= 1; k--){
		for(int l = 1; l <= 5; l++){
			if((k+l) >= 6){
				printf("#");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
}
