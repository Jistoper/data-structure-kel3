#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

void viewData();
void menu();

void clear() { system("cls"); }
void delay(int number_of_seconds) {
  int milli_seconds = 1000 * number_of_seconds;

  clock_t start_time = clock();

  while (clock() < start_time + milli_seconds)
    ;
}

struct Node {
  char code[6];
  char item_name[30];
  int quantity;
  int price;
  struct Node* next;
};
struct Node* head;

int getCount(struct Node* head) {
  int count = 0;
  struct Node* current = head;
  do {
    count++;
    current = current->next;
  } while (current != head);
  return count;
}

struct Node* initNode(struct Node* head, struct Node data) {  // Adrian
  head = (struct Node*)malloc(sizeof(struct Node));
  strcpy(head->code, data.code);
  strcpy(head->item_name, data.item_name);
  head->quantity = data.quantity;
  head->price = data.price;
  head->next = head;
  printf("Data has been added successfully!");
  return head;
}
struct Node* pushHead(struct Node* head, struct Node data) {  // Adrian
  if (head == NULL) return initNode(head, data);
  struct Node *ptr = head, *newNode = (struct Node*)malloc(sizeof(struct Node));
  while (ptr->next != head) ptr = ptr->next;
  strcpy(newNode->code, data.code);
  strcpy(newNode->item_name, data.item_name);
  newNode->quantity = data.quantity;
  newNode->price = data.price;
  newNode->next = head;
  head = newNode;
  ptr->next = head;
  return head;
}
struct Node* pushTail(struct Node* head, struct Node data) {  // Mario G
  if (head == NULL) return initNode(head, data);
  struct Node *newNode, *ptr;
  ptr = head;
  newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->code, data.code);
  strcpy(newNode->item_name, data.item_name);
  newNode->quantity = data.quantity;
  newNode->price = data.price;
  newNode->next = head;
  while (ptr->next != head) ptr = ptr->next;
  ptr->next = newNode;
  return head;
}
struct Node* pushSomewhere(struct Node* head, struct Node data, int pil) {  // A
  if (head == NULL) return initNode(head, data);
  struct Node *ptr = head, *praptr;
  struct Node* newNode;
  newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->code, data.code);
  strcpy(newNode->item_name, data.item_name);
  newNode->quantity = data.quantity;
  newNode->price = data.price;
  for (int i = 0; i < pil - 2; i++) ptr = ptr->next;
  praptr = ptr->next;
  ptr->next = newNode;
  newNode->next = praptr;
  return head;
}

struct Node* popTail(struct Node* head) {  // DAH
  struct Node* ptr = head;
  if (head->next == head) {
    printf("data %s telah dihapus", head->code);
    free(head);
    head = NULL;
  } else {
    while (ptr->next->next != head) ptr = ptr->next;

    printf("data %s telah dihapus", ptr->next->code);
    free(ptr->next);
    ptr->next = head;
  }
  return head;
}
struct Node* popHead(struct Node* head) {  // Mario G
  if (head == NULL) {
    printf("No Data to Delete!");
  } else if (head->next == head) {
    printf("Data %s berhasil dihapus", head->code);
    free(head);
    head = NULL;
  } else {
    struct Node* ptr;
    ptr = head;

    while (ptr->next != head) ptr = ptr->next;

    head = head->next;
    printf("Data %s berhasil dihapus", ptr->next->code);
    free(ptr->next);
    ptr->next = head;
  }
  return head;
}
struct Node* popSomewhere(struct Node* head, int x) {
  struct Node *ptr, *tmp;
  ptr = head;
  if (head->next == NULL) {
    printf("data %s telah dihapus", head->code);
    free(head);
    head = NULL;
  } else {
    for (int i = 0; i < x - 2; i++) ptr = ptr->next;

    printf("data %s telah dihapus", ptr->next->code);
    tmp = ptr->next->next;
    free(ptr->next);
    ptr->next = tmp;
  }
  getch();
  return head;
}

void addstock() {
  clear();
  struct Node data;
  int choice = 0;
  viewData(head);
  printf("\nMenu\n");
  printf("1. Add Stock\n");
  printf("2. Add New Item\n");
  printf("Choice: ");
  scanf("%d", &choice);
  if (choice == 1) {
    clear();
    if (head == NULL) {
      printf("No Stock to add!");
      getch();
      return;
    }
    struct Node* ptr;
    char item_code[5];
    int check = 0, quantity = 0;

    while (check != 1) {
      ptr = head;
      viewData(head);
      printf("\nInput Item Code [5 chars]: ");
      scanf("%s", item_code);
      while (ptr != NULL) {
        if (strcmp(item_code, ptr->code) == 0) {
          check = 1;
          break;
        }
        ptr = ptr->next;
      }
      if (check == 0) {
        printf("\n--Doll code doesn't exist--");
        delay(2);
        clear();
      }
    }

    clear();
    while (check != 2) {
      printf(
          " Code  |            Doll Name           | Available | Price      "
          "  "
          "\n");
      printf(" %.5s | %-30s | %-3.d       | Rp. %d,-\n", ptr->code,
             ptr->item_name, ptr->quantity, ptr->price);
      printf("Input quantity [1...100]: ");
      scanf("%d", &quantity);
      if (quantity < 1 || quantity > 100) {
        printf("\n--Quantity must be more than 0 and no more than 100--");
        delay(2);
        clear();
      } else {
        check = 2;
      }
    }
    ptr->quantity = ptr->quantity + quantity;
    printf("\nAdding Success!");
  } else if (choice == 2) {
    clear();
    viewData(head);
    printf("\nInput Choice\n");
    printf("1.Push Data at Head\n");
    printf("2.Push Data at Tail\n");
    printf("3.Push somewhere\n");
    printf("Choice: ");
    scanf("%d", &choice);
    system("cls");
    viewData(head);
    int pil = 0;
    if (choice == 3) {
      printf("\nInput Index to be Inserted:");
      scanf("%d", &pil);
      if ((pil < 1) || pil > getCount(head) + 1) {
        printf("invalid input");
        getch();
        return;
      }
    }
    printf("\nInput Doll Code [5 chars]: ");
    scanf("%s", data.code);
    getchar();
    printf("Input Doll Name: ");
    scanf("%[^\n]", data.item_name);
    getchar();
    printf("Input Doll Quantity: ");
    scanf("%d", &data.quantity);
    getchar();
    printf("Input Doll Price: ");
    scanf("%d", &data.price);
    getchar();
    if (choice == 1 || pil == 1)
      head = pushHead(head, data);
    else if (choice == 2 || pil == (getCount(head) + 1))
      head = pushTail(head, data);
    else if (choice == 3)
      head = pushSomewhere(head, data, pil);

    printf("\nAdding Success!");

    system("cls");
    return;
  } else if (choice < 1 || choice > 3) {
    printf("Invalid Input!\n");
  }

  delay(2);
  clear();
  return;
}
void sell() {
  struct Node* ptr;
  int check = 0, quantity = 0, total = 0;
  char item_code[5];

  while (check != 1) {
    clear();
    ptr = head;
    viewData(head);
    if (ptr != NULL) {
      printf("\nInput Doll Code [5 chars]: ");
      scanf("%s", item_code);
      while (ptr != NULL) {
        if (strcmp(item_code, ptr->code) == 0) {
          check = 1;
          break;
        }
        ptr = ptr->next;
      }
      if (check == 0) {
        printf("\n--Doll code doesn't exist--");
        delay(2);
        clear();
      }
    } else {
      system("cls");
      printf("\n\nData doesn't exist\n\n");
      printf("Press Enter to Continue");
      getch();
      system("cls");
      menu();
    }
  }

  clear();
  while (check != 2) {
    printf(
        " Code  |            Doll Name           | Available | Price      "
        "  "
        "\n");
    printf(" %.5s | %-30s | %-9.d | Rp. %d,-\n", ptr->code, ptr->item_name,
           ptr->quantity, ptr->price);
    printf("Input quantity: ");
    scanf("%d", &quantity);
    if (quantity < 1 || quantity > ptr->quantity) {
      printf("\n--Quantity must be more than 0 and not more than stock--");
      delay(2);
      clear();
    } else {
      check = 2;
    }
  }

  clear();
  total = ptr->price * quantity;
  printf("\nYour total spending is Rp. %d,-\n", total);
  printf("\n--Press Enter to Continue--");
  ptr->quantity -= quantity;
  getch();
  clear();
  menu();
}
void removestock() {
  if (head == NULL) {
    printf("No Data to Remove!");
    getch();
  } else {
    int choice;
    system("cls");
    printf("Input Choice\n");
    printf("1.Pop Data at Head\n");
    printf("2.Pop Data at Tail\n");
    printf("3.Pop Somewhere\n");
    printf("Choice:");
    scanf("%d", &choice);
    int pil;
    if (choice == 3) {
      clear();
      viewData(head);
      printf("\nInput Index to be deleted: ");
      scanf("%d", &pil);
    }

    if (choice == 1 || pil == 1)
      head = popHead(head);
    else if (choice == 2 || pil == getCount(head) == 1)
      head = popTail(head);
    else if (choice == 3) {
      if ((pil < 1) || pil > getCount(head)) {
        printf("\nInvalid Input");
        getch();
      } else
        head = popSomewhere(head, pil);
    }
    getch();
    system("cls");
  }
}
void viewData(struct Node* head) {
  struct Node* ptr;
  ptr = head;

  if (head == NULL)
    printf("Data not available!\n");
  else {
    int i = 0;
    printf("%d data available\n", getCount(head));
    printf(
        "No. | Code  |            Doll Name           | Available | Price    "
        "  "
        "  "
        "\n");
    do {
      i++;
      printf("%.2d. | %-5s | %-30s | %-9.d | Rp. %d,-\n", i, ptr->code,
             ptr->item_name, ptr->quantity, ptr->price);
      ptr = ptr->next;
    } while (ptr != head);
    for (int i = 0; i < 75; i++) printf("-");
  }
}

void menu() {
  int pilih;
  viewData(head);
  do {
    system("cls");
    viewData(head);
    printf("\nMenu\n");
    printf("1. Sell\n");
    printf("2. Add Stock\n");
    printf("3. Remove Stock\n");
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
        printf("Exiting program\n");
        for (int i = 0; i < 4; i++) {
          printf(".");
          sleep(1);
        }
        system("cls");
        printf("\n\nThank you for trying!!!\n\n");
        printf("Press Enter to continue");
        getch();
        return;

      default:
        system("cls");
        printf("Menu not available\n");
        getch();
        system("cls");
        break;
    }
  } while (pilih != 4);
}
int main() {
  clear();
  head = NULL;
  printf("Welcome to our program\n\n");
  printf("Loading data");
  for (int i = 0; i < 3; i++) {
    printf(".");
    delay(1);
  }
  system("cls");
  menu();
}

/*
2 2 2
DL003
kangaroo Teddy Bear
25
60000
2 2 2
DL005
Lil Benny Phant
40
110000
2 2 2
DL006
Cute Baby Shark
29
130000
*/