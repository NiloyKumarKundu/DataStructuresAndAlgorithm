#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    char ch;
    struct node *next;
};
typedef struct node Node;

Node *head = new Node();

void createNode(Node *head) {
    Node *temp, *last, *flag;

    last = head;
    int i = 0;
    while (i < 26) {
        temp = new Node();
        temp->ch = (char) (97 + i);
        temp->data = 0;
        temp->next = NULL;
        last->next = temp;
        last = last->next;
        i++;
    }

}


string beforeCheck(string msg) {
    for(int i = 0; i < msg.size(); i++) {
        if(msg.at(i) >= 'A' && msg.at(i) <= 'Z') {
            msg.at(i) += 32;
        }
    }
    return msg;
}



Node *check(Node *head, string msg) {
    Node *temp;
    temp = head->next;
    int i = 0;

    while (i < msg.size()) {
        temp = head->next;
        while(temp != NULL) {
            if (msg.at(i) == temp->ch) {
                temp->data++;
                i++;
                break;
            }
            temp = temp->next;
        }
    }
    return head;
}


void display(Node *head) {
    Node *temp;
    temp = head;

    while (temp->next != NULL) {
        cout << temp->next->ch << ": " << temp->next->data << "\n";
        temp = temp->next;
    }
}


int main() {
    createNode(head);
    string msg;
    cin >> msg;
    msg = beforeCheck(msg);
    head = check(head, msg);
    display(head);
}

