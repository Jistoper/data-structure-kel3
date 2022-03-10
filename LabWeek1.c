#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void clear() { system("CLS"); }

struct item {
  char code[6];
  char doll_name[30];
  int quantity;
  int price;
};

struct item arr_item[7];

void addstock() {
  char doll_code[5];
  int i, marker = 0, quantity = 0;

  while (marker != 1) {
    printf("\n\nInput Doll Code [ 5 chars ]: ");
    scanf("%s", &doll_code);

    for (i = 1; i <= 7; i++) {
      if (strcmp(doll_code, arr_item[i].code) == 0) {
        marker = 1;
        break;
      }
    }

    if (marker != 1) {
      clear();
      printf("--The doll code doesn't exist--");
    }
  }

  clear();

  while (marker != 2) {
    printf("\n\nInput Quantity [1...100]: ");
    scanf("%d", &quantity);

    if (quantity > 1 && quantity <= 100) {
      marker = 2;
    } else {
      clear();
      printf("--The quantity must be more than 0 and less than 101--");
    }
  }
  arr_item[i].quantity = arr_item[i].quantity + quantity;

  printf("\n\n--Adding Stock Success--");
}

void sell() {
  char code[6];
  scanf("%s", code);
}

void printarray() {
  printf(
      "No. | Code  |           Doll Name          | Available | Price        "
      "| ");
  for (int i = 0; i < 5; i++) {
    printf("%.2d | %.5s | %-30s |    %.3d    | Rp. %d", i + 1, arr_item[i].code,
           arr_item[i].doll_name, arr_item[i].quantity, arr_item[i].price);
  }
}

int main() {
  printarray();
  while (1) {
    system("cls");
    printf("1. Sell item\n2. Add stock\n3. Exit\n");
    int pil;
    scanf("%d", &pil);
    system("cls");
    switch (pil) {
      case 1:
        sell();
        break;

      case 2:
        addstock();
        break;

      case 3:
        printf("Exiting Program...\n");
        Sleep(1000);
        exit(0);
        break;

      default:
        printf("Pilihan anda salah!");
        break;
    }
  }

  return 0;
}