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

// ARRAY FUCTIONS
int main() {
	struct Node* top;
	top = NULL;
	int max = 10;

	int menu;
	do {
		system("cls");
		printf("1. Push data\n");
		printf("2. Pop data\n");
		printf("3. Peek data\n");
		printf("4. View All data\n");
		printf("5. Exit\n");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
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
				break;
			}

		case 2:
			top = pop(top);
			getch();
			break;

		case 3:
			if (isEmpty(top))
				printf("No Data to Peek!");
			else {
				struct Data dataTop = peekTop(top);
				printf("%s %s \n", dataTop.code, dataTop.name);
			}
			getch();
			break;

		case 4:
			viewData(top);
			getch();
			break;

		default:
			printf("EMPTY\n");
			break;
		}
	} while (menu != 5);
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