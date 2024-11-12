#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct intArr{
	int num;
	struct intArr *nIntArr;
};
struct intArr *takeInfo(struct intArr *top, int rint);
struct intArr *printInfo(struct intArr *top, int *pint);
struct intArr *find(struct intArr *arr, int snum);
struct intArr *del(struct intArr *arr, int snum);
int main(){
	/*stack*/
	struct intArr *top = NULL;
	int rInt, hM, arananDeger;
	char eH = 'h', eH2 = 'h';
	printf("How many number will you enter?");
	scanf("%d", &hM);
	for(int i = 0; i < hM; i++){
		printf("enter a number for stack");
		scanf("%d", &rInt);
		top = takeInfo(top,rInt);
	}
	printf("\n");
	printf("Herhangi bir deðeri aramak ister misiniz ? (e/h)\n");
	eH = getch();
	if(eH == 'e'){
		printf("Hangi deðeri aramak istiyorsunuz?\n");
		scanf("%d", &arananDeger);
		struct intArr *bul = find(top, arananDeger);
		printf("Aranýlan deðer %x adresinde", bul);
		printf("Aradýðýnýz deðeri silmek istiyor musunuz? (e/h)\n");
		eH2 = getch();
		if(eH2 == 'e'){
			top = del(top, arananDeger);
			for(int j = 0; j<hM-1; j++){
				top = printInfo(top,&rInt);
				printf("readed int from stack = %d\n", rInt);
			}
		}
		else{
			for(int j = 0; j<hM; j++){
			top = printInfo(top,&rInt);
			printf("readed int from stack = %d\n", rInt);
			}
		}
	}
}
/*add number func for stack*/
struct intArr *takeInfo(struct intArr *top, int rint){
	struct intArr * newintArray = (struct intArr*)malloc(1*sizeof(struct intArr *));
	newintArray->num = rint;
	newintArray->nIntArr = NULL;
	if(top == NULL){
		top = newintArray;
		return top;
	}
	else{
		newintArray->nIntArr = top;
		return newintArray;
	}
	
}
/*printf number func for stack*/
struct intArr *printInfo(struct intArr *top, int *pint){
	if(top == NULL){
		printf("hata");
	}
	else{
		struct intArr *temp;
		temp = top;
		*pint = temp->num;
		top = top->nIntArr;
		free(temp);
		return top;
	}
}
/*find num func*/ 
struct intArr *find(struct intArr *arr, int snum){
	struct intArr *temp = arr;
	while(temp != NULL){
		if(temp->num == snum){
			return temp;	
		}
		temp = temp->nIntArr;
	}
}
/*delete num func*/
struct intArr *del(struct intArr *arr, int snum){
	struct intArr *temp = arr;
	struct intArr *delArr = NULL;
	while(temp != NULL){
		if(temp->num == snum){
			if(temp == arr){
				arr = arr->nIntArr;
				free(temp);
				return arr;
			}
			else if(temp->nIntArr->nIntArr == NULL){
				free(temp->nIntArr->nIntArr);
				temp->nIntArr = NULL;
				return arr;
			}
			else{
				while(temp->nIntArr->num != snum){
					temp = temp->nIntArr;
				}
				delArr = temp->nIntArr;
				temp->nIntArr = temp->nIntArr->nIntArr;
				free(delArr);
				return arr;
			}
		}
		temp = temp->nIntArr;
	}	
}
