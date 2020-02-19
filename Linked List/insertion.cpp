#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next, *back;
};

typedef struct node Node;

Node *start = NULL;

void showMenu() {
    printf("\n1. Insert\n2. Delete\n3. Exit\n");
}

void display(Node *start) {
    Node *temp;
    temp = start;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertion(int item) {
    Node *temp, *t;
    if(start == NULL) {
        start = new Node();
        start->data = item;
        start->next = NULL;
    } else if(item <= start->data) {
        temp = new Node();
        temp->data = item;
        temp->next = start;
        start = temp;
    } else {
        temp = start;

        while((temp->next != NULL) && (temp->next->data < item)) {
            temp = temp->next;
        }

        t = new Node();
        t->data = item;
        t->next = temp->next;
        temp->next = t;

    }

}



int main() {
    int choice, i = 1, item;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter item to insert: ");
            scanf("%d", &item);
            insertion(item);
            display(start);

        } else if(choice == 2) {

        } else {
            i = 0;
        }
    } while(i);
}

