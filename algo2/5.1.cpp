#include <stdio.h>
#include <stdlib.h>
struct intDizi{
	int sayi;
	struct intDizi *sintDizi;
};
struct intDizi *takeInfo(struct intDizi *top, int rint);
struct intDizi *printInfo(struct intDizi *top, int *pint);
struct intDizi *qTakeInfo(struct intDizi *first, int rInt2);
struct intDizi *qPrintfInfo(struct intDizi *first, int *rInt2);
int main(){
	/*stack*/
	struct intDizi *top = NULL;
	int rInt;
	for(int i = 1; i<6; i++){
		printf("enter a number for stack");
		scanf("%d", &rInt);
		top = takeInfo(top,rInt);
	}	
	printf("\n\n");
	for(int j = 0; j<5; j++){
		top = printInfo(top,&rInt);
		printf("readed int from stack = %d\n", rInt);
	}
	printf("-------------------------------------\n");
	/*queue*/
	struct intDizi *first = NULL;
	int rInt2;
	for(int k = 1; k<6; k++){
		printf("enter a number for queue");
		scanf("%d", &rInt2);
		first = qTakeInfo(first, rInt2);
	}
	printf("\n\n");
	for(int l = 0; l<5; l++){
		first = qPrintfInfo(first,&rInt2);
		printf("readed int from queue = %d\n", rInt2);
	}	
}
/*stack funcs*/
struct intDizi *takeInfo(struct intDizi *top, int rint){
	struct intDizi * newintArray = (struct intDizi*)malloc(1*sizeof(struct intDizi *));
	newintArray->sayi = rint;
	newintArray->sintDizi = NULL;
	if(top == NULL){
		top = newintArray;
		return top;
	}
	else{
		newintArray->sintDizi = top;
		return newintArray;
	}
	
}
struct intDizi *printInfo(struct intDizi *top, int *pint){
	if(top == NULL){
		printf("hata");
	}
	else{
		struct intDizi *temp;
		temp = top;
		*pint = temp->sayi;
		top = top->sintDizi;
		free(temp);
		return top;
	}
}
/*end of stack funcs*/
/*queue funcs*/
struct intDizi *qTakeInfo(struct intDizi *first, int rInt2){
	struct intDizi * newintArray = (struct intDizi*)malloc(1*sizeof(struct intDizi *));
	newintArray->sayi = rInt2;
	newintArray->sintDizi = NULL;
	if(first == NULL){
		first = newintArray;
		return  first;
	}
	else{
		struct intDizi *temp = first;
		while(temp->sintDizi != NULL){
			temp = temp->sintDizi;
		}
		temp->sintDizi = newintArray;
		return first;
	}
}
struct intDizi *qPrintfInfo(struct intDizi *first, int *rInt2){
	if(first == NULL){
		printf("hata");
	}
	else{
		struct intDizi *temp;
		temp = first;
		
		*rInt2 = temp->sayi;
		first = first->sintDizi;
		
		free(temp);
		return first;
	}	
}

