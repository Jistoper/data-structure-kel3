#include <stdio.h>

struct Node {
  char code[6];
  char doll_name[30];
  int quantity;
  int price;
  struct Node* next;
};

struct Node* pushHead(struct Node* head, struct Node* input) {
  struct Node* newNode;
  newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode = input;
  newNode->next = (head == NULL) ? NULL : head;
  return newNode;
}

int main() {
  int pilih;
  struct Node* head;
  head = NULL;

  printf("Menu\n");
  printf("1. Sell\n");
  printf("2. Add Stock\n");
  printf("3. remove Stock\n");
  printf("4. Exit\n");
  printf("Pilihan : ");
  scanf("%d", &pilih);
  switch (pilih) {
    case 1:
      sell();
      break;
    case 2:
      addstock();
      break;
    case 3:
      removestock();
      break;
    case 4:
      printf("Exiting program...");
      delay();
      exit();
      break;
    default:
      printf("Menu yang anda cari tidak ada\n");
      delay();
      break;
  }
  return 0;
}