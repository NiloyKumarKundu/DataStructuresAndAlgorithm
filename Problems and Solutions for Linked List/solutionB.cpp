#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node Node;

Node *head = new Node();

void insert(Node *head, int value) {
    Node *temp, *last, *flag;

    if (head->next == NULL) {
        temp = new Node();
        temp->data = value;
        temp->next = NULL;
        temp->prev = head;
        head->next = temp;
        head->prev = NULL;
    } else if (value <= head->next->data) {
        last = head;
        flag = head->next;
        temp = new Node();
        temp->data = value;
        temp->prev = last;
        temp->next = flag;
        last->next = temp;
        flag->prev = temp;
    } else {
        last = head;
        while ((last->next != NULL) && (last->next->data < value)) {
            last = last->next;
        }
        temp = new Node();
        temp->data = value;
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
    }
}

void search(Node *head, int value) {
    Node *temp;
    temp = head;
    int found = 0;

    while (temp->next != NULL) {
        if (temp->next->data == value) {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found == 1)
        cout << "Found!\n";
    else
        cout << "Not Found!\n";
}

void deleteItem(Node *head, int value) {
    Node *temp = head;
    Node *last = head;
    if (temp->next->data == value) {
        head->next = temp->next->next;
        delete (temp->next);
    } else {
        temp = head->next;
        while (temp->data != value) {
            last = temp;
            temp = temp->next;
        }
        if(temp->next == NULL) {
            last->next = temp->next;
            delete (temp);
        } else {
            last->next = temp->next;
            temp->next->prev = last;
            delete (temp);
        }

    }
}

void length(Node *head) {
    Node *temp;
    temp = head;
    int len = 0;

    while (temp->next != NULL) {
        len++;
        temp = temp->next;
    }
    cout << "Length = " << len << "\n";
}


void display(Node *head) {
    Node *temp;
    temp = head;

    while (temp->next != NULL) {
        cout << temp->next->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void showMenu() {
    printf("1. Insert\n2. Show all\n3. Search\n4. Delete\n5. Length\n6. Exit\n");
}

int main() {
    int i = 1;
    do {
        showMenu();
        int n;
        cin >> n;
        if (n == 1) {
            int item;
            printf("Enter Data:\n");
            cin >> item;
            insert(head, item);
        } else if (n == 2) {
            display(head);
        } else if (n == 3) {
            int value;
            printf("Enter the number you want to search:\n");
            cin >> value;
            search(head, value);
        } else if (n == 4) {
            int item;
            printf("Enter the number you want to delete:\n");
            cin >> item;
            deleteItem(head, item);
        } else if (n == 5) {
            length(head);
        } else
            i = 0;
    } while (i);
}

