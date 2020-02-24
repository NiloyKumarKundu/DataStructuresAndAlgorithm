#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    char ch;
    int power;
    struct Node *next;
};

typedef struct Node node;
node *headOne = new node();
node *headTwo = new node();


void insert(node *head) {
    head->next = NULL;
    node *temp;
    node *flag, *last;
    last = head;
    string str;
    getline(cin, str);
    int i = 0;
    while(i <= str.length()) {
        if(head->next == NULL) {
            temp = new node();
            temp->data = str.at(0) - 48;
            i++;
            if (str.at(i) == 'x' || str.at(i) == 'X') {
                temp->ch = str.at(i);
                i++;
            }
            if (str.at(i) != '+') {
                temp->power = str.at(i) - 48;
                i++;
            }
            if (str.at(i) == '+')
                i++;

            head->next = temp;
            last = temp;
        } else {
            flag = new node();
            flag->data = str.at(i) - 48;
            i++;
            if(i == str.length()) {
                last->next = flag;
                last = last->next;
                break;
            }

            if (str.at(i) == 'x' || str.at(i) == 'X') {
                flag->ch = str.at(i);
                i++;
            }
            if (str.at(i) != '+') {
                flag->power = str.at(i) - 48;
                i++;
            }
            if (str.at(i) == '+')
                i++;

            last->next = flag;
            last = last->next;
        }
    }
}


void sum(node *headOne, node *headTwo) {
    node *tempOne = headOne;
    node *tempTwo = headTwo;

    while(tempOne->next != NULL) {
        while(tempTwo->next != NULL) {
            if((tempOne->next->power == tempTwo->next->power) && (tempOne->next->ch == tempTwo->next->ch)) {
                tempOne->next->data += tempTwo->next->data;
            }
            tempTwo = tempTwo->next;
        }
        tempTwo = headTwo;
        tempOne = tempOne->next;
    }
}


void display(node *head) {
    node *temp = head->next;
    while(temp != NULL) {
        cout << temp->data;
        if(temp->ch != NULL)
            cout << temp->ch;
        if(temp->power >= 2)
            cout << temp->power;
        if(temp->next != NULL)
            cout << "+";
        temp = temp->next;
    }
}

int main() {
    insert(headOne);
    insert(headTwo);
    sum(headOne, headTwo);
    display(headOne);
}