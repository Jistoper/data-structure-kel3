#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
struct Node {
  char code[6];
  char doll_name[30];
  int quantity;
  int price;
  struct Node *next;
};

struct Node* pushHead(struct Node* head, struct Node data)
{
	if(head == NULL)
	{
		head = (struct Node*)malloc(sizeof(struct Node));
		strcpy(head->code,data.code);
		strcpy(head->doll_name,data.doll_name);
		head->quantity = data.quantity;
		head->price = data.price;
		head->next = NULL;
	}
	else
	{
		struct Node *newNode;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		strcpy(newNode->code,data.code);
		strcpy(newNode->doll_name,data.doll_name);
		newNode->quantity = data.quantity;
		newNode->price = data.price;
		newNode->next = head;
		
		head = newNode;
	}
	return head;
}


void viewData(struct Node* head) {
		struct Node* ptr;
	ptr = head;
	
	if(head == NULL)
		printf("Data not available");
	else {
		int i=0;
		printf(
      "No. | Code  |            Doll Name           | Available | Price        "
      "\n");
	while(ptr != NULL)
	{
		i++;
		printf("%.2d. | %.5s | %-30s | %-3.d       | Rp. %d,-\n",i,ptr->code,ptr->doll_name,ptr->quantity,ptr->price);
		ptr = ptr->next;
	}
	for (int i = 0; i < 75; i++) printf("-");
	}
}
	


/*void exit() {
	system("cls");
	printf("\n\nThank you for trying!!!\n\n");
	printf("Press Enter to continue");
	getch();
	return 0;                                        	
}*/

int main() {
  int pilih;
  int choice;
  struct Node* head;
  head = NULL;
	do{
  printf("Menu\n");
  printf("1. Sell\n");
  printf("2. Add Stock\n");
  printf("3. View Data\n");
  printf("3. Remove Stock\n");
  printf("4. Exit\n");
  printf("Pilihan : ");
  scanf("%d", &pilih);
  switch (pilih) {
    case 1:
      break;
    case 2:{
    	struct Node data;
	system("cls");
	printf("Input Choice\n");
	printf("1.Push Data at Head\n");
	printf("2.Push Data at Tail\n");
	printf("Choice:");
	scanf("%d",&choice);
	system("cls");
	printf("Input Doll Code [5 chars]:");
	scanf("%s",data.code);
	printf("Input Doll Name:");
	scanf("%s",data.doll_name);
	printf("Input Doll Quantity:");
	scanf("%d",&data.quantity);
	printf("Input Doll Price:");
	scanf("%d",&data.price);
	if(choice == 1){
		head = pushHead(head,data);
	}
	else if(choice == 2){
		break;
	}
	else{
		break;
	}
      system("cls");
      break;}
    case 3:
    viewData(head);
    getch();
    system("cls");
    break;
    case 4:
      printf("Exiting program...");
      sleep(3);
      system("cls");
       printf("\n\nThank you for trying!!!\n\n");
		printf("Press Enter to continue");
		getch();
      break;
      return 0;
    default:
    	system("cls");
      printf("Menu not available\n");
      getch();
      system("cls");
      break;
  }
  	}while(pilih!=4);
  return 0;
}
