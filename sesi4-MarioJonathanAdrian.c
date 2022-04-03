#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>


struct Data {
	char code[6];
	char name[20];
};
struct Node {
	struct Data data;
	struct Node* next;
};


// LINKED LIST FUNCTIONS
bool isEmpty(struct Node* top) { return (top == NULL); }
bool isOverflow(struct Node* top, int max) {
	struct Node* ptr;
	ptr = top;
	if (isEmpty(top))
		return false;
	else {
		int count = 1;
		while (ptr->next != NULL) {
			count++;
			ptr = ptr->next;
		}
		if (count == max)
			return true;
		else
			return false;
	}
}
void viewData(struct Node* top) {
	struct Node* ptr;
	ptr = top;
	if (isEmpty(top))
		printf("No Data Found!");
	else {
		int index = 1;
		for (int i = 0;i < 25; i++) printf("-");
		printf("\nNo. | CODE  | Name\n");
		while (ptr != NULL) {
			printf("%.2d  | %-5s | %s", index++, ptr->data.code, ptr->data.name);
			if (ptr == top) printf("     -> Top");
			printf("\n");
			ptr = ptr->next;
		}
		for (int i = 0;i < 25; i++) printf("-");
	}
}
struct Node* push(struct Node* top, struct Data newData) {
	if (isEmpty(top)) {
		top = (struct Node*)malloc(sizeof(struct Node));
		top->data = newData;
		top->next = NULL;
	}
	else {
		struct Node* newNode;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = newData;
		newNode->next = top;
		top = newNode;
	}
	return top;
}
struct Node* pop(struct Node* top) {
	if (isEmpty(top))
		printf("No Data to delete");
	else if (isEmpty(top->next)) {
		free(top);
		top = NULL;
	}
	else {
		struct Node* ptr;
		ptr = top;
		top = ptr->next;
		free(ptr);
	}
	return top;
}
struct Data peekTop(struct Node* top) { return top->data; }
struct Node* destroy(struct Node* top) {
	struct Node* current = top;
	struct Node* next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	top = NULL;
	return top;
}

// ARRAY FUCTIONS
// bool arr_isEmpty(struct Node* top) { return top->next == -1; }//Present?


void menu() {
	struct Node* top = NULL;
	int max, pilihan, mod = 2;
	printf("Masukkan Max Data : ");
	scanf("%d", &max);
	while (1) {
		system("cls");
		printf("1. Push Data\n");
		printf("2. Pop Data\n");
		printf("3. Peek Data\n");
		printf("4. View All Data\n");
		printf("5. Setting\n");
		printf("6. Exit\n");
		printf("\nPilihan Anda: ");
		scanf("%d", &pilihan);

		switch (pilihan) {
		case 1:
			if (mod == 1) {
				// ARRAY
			}
			else if (mod == 2) {
				if (isOverflow(top, max))
					printf("Stack Overflow please pop first!");
				else {
					struct Data newData;
					printf("masukan code: ");
					scanf("%s", &newData.code);
					printf("masukan nama: ");
					scanf("%s", &newData.name);
					top = push(top, newData);
					printf("data berhasil dimasukan!");
					getch();
				}
			}
			break;

		case 2:
			if (mod == 1) {}
			else if (mod == 2)top = pop(top);
			break;

		case 3:
			if (mod == 1) {}
			else if (mod == 2) {
				if (isEmpty(top))
					printf("No Data to Peek!");
				else {
					struct Data dataTop = peekTop(top);
					printf("%s %s \n", dataTop.code, dataTop.name);
				}
			}
			getch();
			break;

		case 4:
			viewData(top);
			getch();
			break;

		case 5:
			system("cls");

			int pil = 0;
			while (pil != 3) {
				system("cls");
				if (mod == 1)
					printf("1. change mode to linked list\n");
				else
					printf("1. change mode to array\n");
				printf("2. delete all data\n");
				printf("3. Kembali\n");
				printf("Pilihan Anda: ");
				scanf("%d", &pil);

				if (pil == 1) {
					if (mod == 1) {
						//delete array
					}
					else {
						top = destroy(top);
					}
					mod = (mod == 1) ? 2 : 1;
				}
				else if (pil == 2)
					top = destroy(top);
				else if (pil < 0 || pil > 3) {
					printf("Menu Tidak Ada\n");
					printf("--Tekan Enter untuk Melanjutkan--");
					getch();
				}
			}
			break;

		case 6:
			return;
			break;

		default:
			printf("Menu Tidak Ditemukan\n");
		}
	}
}

int main() {
	menu();
	return 0;
}

/*
1
DL003 Boneka1
1
DL004 Boneka2
1
DL005 Boneka3
*/