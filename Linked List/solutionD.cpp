#include <bits/stdc++.h>
using namespace std;

struct node {
    char data;
    struct node *next;
    struct node *down;
};
typedef struct node Node;

Node *head = new Node();

void createNode(Node *head, int n, int k) {
    Node *temp, *last, *flag;
    int i = 0;
    int j = 0;
    flag = head;
    last = head;
    while(i < n) {
        temp = new Node();
        temp->data = NULL;
        temp->next = NULL;
        temp->down = NULL;
        flag->down = temp;
        flag = temp;
        j = 0;
        while (j < k) {
            char input;
            temp = new Node();
            cin >> input;
            //getchar();
            temp->data = input;
            temp->next = NULL;
            last->next = temp;
            last = temp;
            j++;
        }
        last = flag;
        i++;
    }
}


Node *reverse(Node *head, int n, int k) {
    Node *temp, *last, *flag, *downController, *flagDown, *newPointer, *headPointer;
    temp = head;
    headPointer = head;
    downController = head;

    flag = new Node();
    flagDown = flag;
    newPointer = new Node();
    flagDown->down = newPointer;
    while(n--) {
        last = flagDown;
        int l = k;
        while(l--) {
            while(temp->next != NULL) {
                headPointer = temp;
                temp = temp->next;
            }
            last->next = temp;
            last = last->next;
            headPointer->next = NULL;
            temp = downController;
        }
        newPointer = new Node();
        flagDown->down = newPointer;
        flagDown = flagDown->down;
        temp = downController->down;
        downController = downController->down;
    }
    return flag;
}


void display(Node *head) {
    Node *temp, *last, *flag;
    last = head;
    flag = head;
    temp = head;

    while (temp->down != NULL) {
        while(temp->next != NULL) {
            cout << temp->next->data << "";
            temp = temp->next;
        }
        cout << "\n";
        temp = last->down;
        last = last->down;
    }
}


int main() {
    int n, k;
    cin >> n >> k;
    createNode(head, n, k);

    head = reverse(head, n, k);
    display(head);
}