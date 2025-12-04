#include <iostream>

class Node {
public:
    int data;
    Node* next = nullptr;
};

int main() {
    // list head
    Node* listHead = new Node;
    listHead->data = 6;

    // append 5..0 to front of list
    for (int i = 5; i > 0; i--) {
        Node* newNode = new Node;
        newNode->data = i;

        newNode->next = listHead;
        listHead = newNode;
    }

    // start at head, predacessor->next = current
    Node* current = listHead;
    Node* currentPredacessor = nullptr;
    for (int i = 0; i < 3; i++) {
        currentPredacessor = current;
        current = current->next;
    }

    // current->data = 4
    // currentPredacessor->data = 3

    // what does this do?
    currentPredacessor->next = current->next;
    current->next = listHead;
    listHead = current;

    std::cout << "done";
}