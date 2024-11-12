#include <stdio.h>
#include <stdlib.h>
struct node{
	int sayi;
	struct node *onceki;
	struct node *sonraki;
};
struct node *addNode(struct node *head, int x);
void pNode(struct node *head);


int main(){
	struct node *ilk = NULL;
	struct node *temp = NULL;
	struct node *ptr = NULL;
	ilk = addNode(NULL, 0);
	ptr = ilk;
	
	int asayi = 0;
	do{
		printf("Bir sayý giriniz:");
		scanf("%d", &asayi);
		temp = addNode(ptr,asayi);
		if(temp){
			ptr->sonraki = temp;
			ptr = ptr->sonraki;
		}
	}while(asayi != 0);
	pNode(ilk);
}
	

struct node *addNode(struct node *head, int x){
	struct node *node = NULL;
	node = (struct node*)malloc(1*(sizeof(struct node*)));
	if(node){
		node->sayi = x;
		node->sonraki = NULL;
		if(head){
			node->onceki = head;
			head->sonraki = node;
		}
		else{
			node->onceki = NULL;
		}
	}
	return node;
}
void pNode(struct node *head){
	struct node *temp = head;
	temp = temp->sonraki;
	while(temp->sonraki != NULL){
		printf("%d\n", temp->sayi);
		temp = temp->sonraki;
	}
	return;
}
