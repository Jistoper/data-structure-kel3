#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

void addstock();
struct Node* head;
void clear() { system("cls"); }
void delay(int number_of_seconds) {
  int milli_seconds = 1000 * number_of_seconds;

  clock_t start_time = clock();

  while (clock() < start_time + milli_seconds)
    ;
}

struct Node {
  char code[6];
  char doll_name[30];
  int quantity;
  int price;
  struct Node* next;
};

struct Node* pushHead(struct Node* head, struct Node data) {
  if (head == NULL) {
    head = (struct Node*)malloc(sizeof(struct Node));
    strcpy(head->code, data.code);
    strcpy(head->doll_name, data.doll_name);
    head->quantity = data.quantity;
    head->price = data.price;
    head->next = NULL;
  } else {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->code, data.code);
    strcpy(newNode->doll_name, data.doll_name);
    newNode->quantity = data.quantity;
    newNode->price = data.price;
    newNode->next = head;

    head = newNode;
  }
  return head;
}
struct Node* pushTail(struct Node* head, struct Node data) {
  struct Node* ptr = head;
  if (head == NULL) {
    head = (struct Node*)malloc(sizeof(struct Node));
    strcpy(head->code, data.code);
    strcpy(head->doll_name, data.doll_name);
    head->quantity = data.quantity;
    head->price = data.price;
    head->next = NULL;
    return head;
  } else {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->code, data.code);
    strcpy(newNode->doll_name, data.doll_name);
    newNode->quantity = data.quantity;
    newNode->price = data.price;
    newNode->next = NULL;
    while (ptr->next->next != NULL) ptr = ptr->next;
    ptr->next = newNode;
    return head;
  }
}

struct Node* popTail(struct Node* head) {
  struct Node* ptr;
  ptr = head;
  if (head == NULL) {
    printf("No Data to Delete!");
    getch();
    return head;
  }
  if (head->next == NULL) {
    printf("data %s telah dihapus", head->code);
    free(head);
    head = NULL;
  } else {
    while (ptr->next->next != NULL) ptr = ptr->next;

    printf("data %s telah dihapus", ptr->next->code);
    free(ptr->next);
    ptr->next = NULL;
  }
  getch();
  return head;
}
struct Node* popHeaad(struct Node* head) {
  struct Node* ptr;
  ptr = head;
  if (head == NULL) {
    printf("No Data to Delete!");
    getch();
    return head;
  }
  if (head->next == NULL) {
    printf("data %s telah dihapus", head->code);
    free(head);
    head = NULL;
  } else {
    head = head->next;
    free(ptr);
  }
  return head;
}
struct Node* popsomething(struct Node* head, int x) {}

void viewData(struct Node* head) {
  struct Node* ptr;
  ptr = head;

  if (head == NULL)
    printf("Data not available");
  else {
    int i = 0;
    printf(
        "No. | Code  |            Doll Name           | Available | Price      "
        "  "
        "\n");
    while (ptr != NULL) {
      i++;
      printf("%.2d. | %.5s | %-30s | %-3.d       | Rp. %d,-\n", i, ptr->code,
             ptr->doll_name, ptr->quantity, ptr->price);
      ptr = ptr->next;
    }
    for (int i = 0; i < 75; i++) printf("-");
  }
}

int menu() {
  int pilih;
  // struct Node* head;
  // head = NULL;
  do {
    system("cls");
    viewData(head);
    printf("\n\nMenu\n");
    printf("1. Sell\n");
    printf("2. Add Stock\n");
    printf("3. Remove Stock\n");
    printf("4. Exit\n");
    printf("Pilihan : ");
    scanf("%d", &pilih);
    switch (pilih) {
      case 1:
        break;
      case 2:
        addstock();
        break;

      case 3: {
        int choice;
        system("cls");
        printf("Input Choice\n");
        printf("1.Pop Data at Head\n");
        printf("2.Pop Data at Tail\n");
        printf("Choice:");
        scanf("%d", &choice);
        if (choice == 1) {
          head = popHeaad(head);
          break;
        } else if (choice == 2) {
          head = popTail(head);
        } else {
          break;
        }
        getch();
        system("cls");
        break;
      }
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
  } while (pilih != 4);
}

void addstock() {
  struct Node data;
  int choice;
  system("cls");
  printf("Input Choice\n");
  printf("1.Push Data at Head\n");
  printf("2.Push Data at Tail\n");
  printf("Choice: ");
  scanf("%d", &choice);
  system("cls");
  printf("Input Doll Code [5 chars]: ");
  scanf("%s", data.code);
  getchar();
  printf("Input Doll Name: ");
  scanf("%[^\n]", data.doll_name);
  getchar();
  printf("Input Doll Quantity: ");
  scanf("%d", &data.quantity);
  getchar();
  printf("Input Doll Price: ");
  scanf("%d", &data.price);
  getchar();
  if (choice == 1) {
    head = pushHead(head, data);
  } else if (choice == 2) {
    head = pushTail(head, data);
  } else {
  }
  system("cls");
}

int main() {
  // head = NULL;
  head = NULL;
  printf("Welcome to our program\n\n");
  // delay(2);
  printf("Loading data");
  for (int i = 0; i < 3; i++) {
    printf(".");
    delay(1);
  }
  menu();
}