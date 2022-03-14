#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

/**
 * TUGAS LAB SESI 1
 * 2501993964 - Mario Gracius K.L
 * 2501980305 - Jonathan Apriliano Saputra B
 * 2501960814 - Augustinus Adrian Triputra
 */

void clear() { system("CLS"); }

void delay(float number_of_seconds) {
  float milli_seconds = 1000 * number_of_seconds;
  clock_t start_time = clock();
  while (clock() < start_time + milli_seconds)
    ;
}

struct item {
  char code[6];
  char doll_name[30];
  int quantity;
  int price;
};

struct item arr_item[7] = {{.code = "DL003",
                            .doll_name = "kangaroo Teddy Bear",
                            .quantity = 25,
                            .price = 60000},
                           {.code = "DL005",
                            .doll_name = "Lil Benny Phant",
                            .quantity = 40,
                            .price = 110000},
                           {.code = "DL006",
                            .doll_name = "Cute Baby Shark",
                            .quantity = 29,
                            .price = 130000},
                           {.code = "DL012",
                            .doll_name = "Plushie Cute Dinosaur",
                            .quantity = 24,
                            .price = 140000},
                           {.code = "DL020",
                            .doll_name = "Sweet Panda",
                            .quantity = 28,
                            .price = 150000},
                           {.code = "DL029",
                            .doll_name = "Reversible Octopus Plushie",
                            .quantity = 18,
                            .price = 150000},
                           {.code = "DL033",
                            .doll_name = "Cute Plush Cat Doll",
                            .quantity = 18,
                            .price = 200000}};

void printarray() {
  printf(
      "No. | Code  |            Doll Name           | Available | Price        "
      "\n");
  for (int i = 0; i < 75; i++) printf("-");
  printf("\n");
  for (int i = 0; i < sizeof(arr_item) / sizeof(arr_item[0]); i++) {
    printf("%.2d. | %.5s | %-30s | %-3.d       | Rp. %d,-\n", i + 1,
           arr_item[i].code, arr_item[i].doll_name, arr_item[i].quantity,
           arr_item[i].price);
  }
  for (int i = 0; i < 75; i++) printf("-");
}

void addstock() {
  printf("Add Stock\n");
  char doll_code[5];
  int i, marker = 0, quantity = 0, temp = 0;

  printarray();

  while (marker != 1) {
    printf("\nInput Doll Code [ 5 chars ]: ");
    scanf("%s", doll_code);

    for (i = 0; i < 7; i++) {
      if (strcmp(doll_code, arr_item[i].code) == 0) {
        marker = 1;
        break;
      }
    }

    if (marker != 1) {
      printf("\n--The doll code doesn't exist--");
      delay(2);
      clear();
      printf("Add Stock\n");
      printarray();
    }
  }

  while (marker != 2) {
    printf("Input Quantity [1...100]: ");
    scanf("%d", &quantity);

    if (quantity > 1 && quantity <= 100) {
      marker = 2;
    } else {
      printf("\n--The quantity must be more than 0 and less than 101--");
      delay(2);
      clear();
      printf("Add Stock\n");
      printarray();
      printf("\nInput Doll Code [ 5 chars ]: %s\n", doll_code);
    }

    temp = 999 - arr_item[i].quantity;
    if (marker == 2 && quantity > temp) {
      marker = 1;
      printf("\n--Stock can't exceeds 999--");
      delay(2);
      clear();
      printf("Add Stock\n");
      printarray();
      printf("\nInput Doll Code [ 5 chars ]: %s\n", doll_code);
    }
  }
  arr_item[i].quantity = arr_item[i].quantity + quantity;

  printf("\n\n--Adding Stock Success--");
}

int sell() {
  char code[6];
  int track = -1;
  int qnt;
  while (1) {
    track = -1;
    clear();
    printarray();
    printf("\nInput doll code [5 chars]: ");
    scanf("%s", code);
    for (int i = 0; i < sizeof(arr_item) / sizeof(arr_item[0]); i++) {
      if (strcmp(code, arr_item[i].code) == 0) {
        track = i;
        break;
      }
    }
    if (track == -1) {
      printf("--- The doll code doesn't exist ---\n");
      delay(2);
    } else
      break;
  }

  while (1) {
    clear();
    printarray();
    printf("\nInput doll code [5 chars]: %s", code);
    printf("\nInput quantity: ");
    scanf("%d", &qnt);
    if (qnt > arr_item[track].quantity) {
      printf("...The quantity of doll is not enough...\n");
      delay(2);
      continue;
    } else if (qnt < 1) {
      printf("...Input invalid...\n");
      delay(2);
      continue;
    }
    break;
  }
  printf("total price is Rp. %d,- * %d = Rp. %d,-", arr_item[track].price, qnt,
         arr_item[track].price * qnt);
  arr_item[track].quantity -= qnt;
  delay(5);
  return 1;
}

int main() {
  // return 0;
  while (1) {
    clear();
    printarray();
    printf("\n1. Sell item\n2. Add stock\n3. Exit\n");
    printf("Input choice : ");
    int pil;
    scanf("%d", &pil);
    clear();
    switch (pil) {
      case 1:
        sell();
        break;

      case 2:
        clear();
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