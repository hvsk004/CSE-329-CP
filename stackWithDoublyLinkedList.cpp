#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(NULL), next(NULL) {}
};

void push(int x, Node*& head, Node*& mid, int& count) {
    Node* newNode = new Node(x);
    if (head == NULL) {
        head = newNode;
        mid = head;
        count = 1;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        count++;
        // Corrected logic for updating the mid pointer
        if (count % 2 != 0) {
            mid = mid->prev;
        }
    }
}

void pop(Node*& head, Node*& mid, int& count) {
    if (head == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Popped element is " << head->data << endl;
    Node* temp = head->next;
    delete head;
    head = temp;
    if (head != NULL) {
        head->prev = NULL;
    }
    count--;
    if (count % 2 == 0 && count != 0) {
        mid = mid->next;
    }


}

int findMiddle(Node* mid) {
    if (mid == NULL) {
        cout << "Stack is empty" << endl;
        return INT_MIN;
    }
    return mid->data;
}

int main() {
    Node* head = NULL;
    Node* mid = NULL;
    int count = 0;
    push(10, head, mid, count);
    push(20, head, mid, count);
    push(30, head, mid, count);
    push(40, head, mid, count);
    push(50, head, mid, count);
    cout << "Middle element is " << findMiddle(mid) << endl;
    pop(head, mid, count);
    cout << "Middle element is " << findMiddle(mid) << endl;
    pop(head, mid, count);
    cout << "Middle element is " << findMiddle(mid) << endl;
    return 0;
}
