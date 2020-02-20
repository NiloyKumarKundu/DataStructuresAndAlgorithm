#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *top;
    struct node *bottom;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

int sumLeft = 0;
int sumRight = 0;
int sumTop = 0;
int sumBottom = 0;

void countLeft(Node *head) {
    Node *temp;
    temp = head;

    while (temp->left != NULL) {
        int flag = temp->left->data;
        sumLeft += flag;
        temp = temp->left;
    }
}

void countRight(Node *head) {
    Node *temp;
    temp = head;

    while (temp->right != NULL) {
        int flag = temp->right->data;
        sumRight += flag;
        temp = temp->right;
    }
}

void countTop(Node *head) {
    Node *temp;
    temp = head;

    while (temp->top != NULL) {
        int flag = temp->top->data;
        sumTop += flag;
        temp = temp->top;
    }
}

void countBottom(Node *head) {
    Node *temp;
    temp = head;

    while (temp->bottom != NULL) {
        int flag = temp->bottom->data;
        sumBottom += flag;
        temp = temp->bottom;
    }
}

void insertBottom(Node *head, int value) {
    Node *flag, *temp;

    if(head->bottom == NULL) {
        flag = new Node();
        flag->data = value;
        flag->left = NULL;
        head->bottom = flag;
    } else {
        temp = head;
        while (temp->bottom != NULL) {
            temp = temp->bottom;
        }
        flag = new Node();
        flag->data = value;
        flag->left = NULL;
        temp->bottom = flag;
    }
}

void insertTop(Node *head, int value) {
    Node *flag, *temp;

    if(head->top == NULL) {
        flag = new Node();
        flag->data = value;
        flag->left = NULL;
        head->top = flag;
    } else {
        temp = head;
        while (temp->top != NULL) {
            temp = temp->top;
        }
        flag = new Node();
        flag->data = value;
        flag->left = NULL;
        temp->top = flag;
    }
}


void insertRight(Node *head, int value) {
    Node *flag, *temp;

    if(head->right == NULL) {
        flag = new Node();
        flag->data = value;
        flag->left = NULL;
        head->right = flag;
    } else {
        temp = head;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        flag = new Node();
        flag->data = value;
        flag->left = NULL;
        temp->right = flag;
    }
}

void insertLeft(Node *head, int value) {
    Node *flag, *temp;

    if(head->left == NULL) {
        flag = new Node();
        flag->data = value;
        flag->left = NULL;
        head->left = flag;
    } else {
        temp = head;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        flag = new Node();
        flag->data = value;
        flag->left = NULL;
        temp->left = flag;
    }
}


void Max(int sLeft, int sRight, int sTop, int sBottom) {
    if((sLeft > sRight) && (sLeft > sTop) && (sLeft > sBottom))
        cout << "Left Link List Has Maximum Sum " << sLeft << "\n";
    else if((sRight > sLeft) && (sRight > sTop) && (sRight > sBottom))
        cout << "Right Link List Has Maximum Sum " << sRight << "\n";
    else if((sTop > sLeft) && (sTop > sRight) && (sTop > sBottom))
        cout << "Top Link List Has Maximum Sum " << sTop << "\n";
    else
        cout << "Bottom Link List Has Maximum Sum " << sBottom << "\n";
}



int main() {
    Node *head = new Node();
    int n;
    cin >> n;

    while (n--) {
        char ch;
        int value;
        cin >> ch;
        cin >> value;

        if (ch == 'L') {
            insertLeft(head, value);
        } else if (ch == 'R') {
            insertRight(head, value);
        } else if (ch == 'T') {
            insertTop(head, value);
        } else if (ch == 'B') {
            insertBottom(head, value);
        }
    }
    countLeft(head);
    countRight(head);
    countTop(head);
    countBottom(head);
    Max(sumLeft, sumRight, sumTop, sumBottom);
}