#include <stdio.h>
#include <stdlib.h>
struct node{
	int sayi;
	struct node *onceki;
	struct node *sonraki;
};
struct node *addNode(struct node *head, int x);
void pNode(struct node *head);
struct node *find(struct node *head, int x);
struct node *del(struct node *head, int x);

int main(){
	struct node *ilk = NULL;
	struct node *temp = NULL;
	struct node *ptr = NULL;
	struct node *BUL = NULL;
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
	
	int snum;
	temp = ilk;
	printf("silmek istediðiniz sayýyý giriniz:\n");
	scanf("%d", &snum);
	BUL = find(temp, snum);
	printf("--%x--", BUL);
	printf("------------------------\n");
	pNode(del(ilk, snum));
	
	
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
	while(temp){
		printf("%d\n", temp->sayi);
		temp = temp->sonraki;
	}
	return;
}
struct node *find(struct node *head, int x){
	struct node *temp = head;
	while(temp != NULL){
		if(temp->sayi == x){
			return temp;
		}
		temp = temp->sonraki;
	}
}
struct node *del(struct node *head, int x){
	struct node *temp = head;
	struct node *del = NULL;
	if(head->sayi == x){
		head = head->sonraki;
		head->onceki = NULL;
		free(temp);
		return head;	
	}
	else{
		while(temp->sayi != x){
			temp = temp->sonraki;
		}
		temp->onceki->sonraki = temp->sonraki;
		if(temp->sonraki != NULL){
			temp->sonraki->onceki = temp->onceki;
		}
		else{
			temp->onceki->sonraki = NULL;
		}
		free(temp);
		return head;
	}
}
