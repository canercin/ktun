#include <stdio.h>
#include <stdlib.h>
struct node{
	int sayi;
	struct node *onceki;
	struct node *sonraki;
};
struct node *sekle(struct node *ilk, int x);
void pNode(struct node *head);
int main(){
	struct node *ilk = NULL;
	struct node *temp = NULL;
	struct node *ptr = NULL;
	ilk = sekle(NULL, 0);
	ptr = ilk;
	
	int asayi = 0;
	do{
		printf("Bir sayý giriniz:");
		scanf("%d", &asayi);
		ilk = sekle(ptr,asayi);
	}while(asayi != 0);
	pNode(ilk);
}
struct node *sekle(struct node *ilk, int x){
	struct node *newi = (struct node*)malloc(1*(sizeof(struct node*)));
	struct node *temp = ilk;
	//ilk boþþa ilke ekleme
	if(ilk == NULL){
		ilk = (struct node*)malloc(1*(sizeof(struct node *)));
		ilk->sayi = x;
		ilk->onceki = NULL;
		ilk->sonraki = NULL;
		return ilk;
	}
	else{
		temp = ilk;
		//ilkten küçük ekleme
		if((temp->sayi) > x){
			newi->sayi = x;
			newi->onceki = NULL;
			newi->sonraki = temp;
			temp->onceki = newi;
			return newi;
		}
		else{
			newi->sayi = x;
			while(temp != NULL){
				//sondan bi öncekine ekleme
				if(temp->sonraki == NULL && temp->sayi < x){
					newi->sonraki = NULL;
					newi->onceki = temp;
					temp->sonraki = newi;
					return ilk;
				}
				if(temp->sonraki->sayi > x){
					newi->sonraki = temp->sonraki;
					newi->onceki = temp;
					temp->sonraki = newi;
					newi->sonraki->onceki = newi;
					return ilk;
				}
				temp = temp->sonraki;
			}			
		}
	}
}
void pNode(struct node *head){
	struct node *temp = head;
	while(temp->sonraki != NULL){
		printf("%d--%x\n", temp->sayi, temp);
		temp = temp->sonraki;
	}
	printf("%d--%x\n", temp->sayi, temp);
}
