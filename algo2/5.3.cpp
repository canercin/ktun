#include <stdio.h>
int main(){
	char yn = 'n';
	do{
		printf("Hello");
		scanf("%c", &yn);
	}
	while(yn == 'y');
}
