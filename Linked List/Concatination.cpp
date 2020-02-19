#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next, *back;
};

typedef struct node Node;

void display(Node *start) {
    Node *temp;
    temp = start;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node *concatinate(Node *start, Node *head) {
    Node *temp = start;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    return start;
}


int main() {
    Node *start, *temp, *last, *head;
    start = NULL;
    head = NULL;
    int ans, searchData;

    printf("Do you want to add item for Start node?\n");
    scanf("%d", &ans);

    while(ans == 1) {
        if(start == NULL) {
            start = new Node();
            printf("Enter data:\n");
            scanf("%d", &start->data);
            start->next = NULL;
            start->back = NULL;
            last = start;
        } else {
            temp = new Node();
            printf("Enter data:\n");
            scanf("%d", &temp->data);
            temp->next = NULL;
            last->next = temp;
            temp->back = last;
            last = temp;
        }

        printf("Do you want to add item for Start node?\n");
        scanf("%d", &ans);
    }

    printf("Do you want to add item for Head node?\n");
    scanf("%d", &ans);


    while(ans == 1) {
        if(head == NULL) {
            head = new Node();
            printf("Enter data:\n");
            scanf("%d", &head->data);
            head->next = NULL;
            head->back = NULL;
            last = head;
        } else {
            temp = new Node();
            printf("Enter data:\n");
            scanf("%d", &temp->data);
            temp->next = NULL;
            last->next = temp;
            temp->back = last;
            last = temp;
        }

        printf("Do you want to add item for Head node?\n");
        scanf("%d", &ans);
    }

    start = concatinate(start, head);
    display(start);
}
