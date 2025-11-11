/*
 * @file pass_by_value_vs_reference.cpp
 * @author: James Anderson
 * @date: 11 November 2025
 * @brief Demonstrates pass-by-value vs. pass-by-reference,
 *        and pointer passing semantics in C++.
 *
 * This example uses both primitive types (int) and a simple
 * class (Node) to illustrate how different parameter passing
 * methods affect the caller’s variables.
 *
 * Functions demonstrated:
 * - passIntValue(int value)
 *      Passes an integer by value. Changes do NOT affect the caller.
 * - passIntRef(int& ref)
 *      Passes an integer by reference. Changes DO affect the caller.
 * - passNodePtr(Node* nodePtr)
 *      Passes a pointer by value. The pointer is copied, so changing it
 *      inside the function does NOT affect the caller’s pointer.
 * - passNodePtrRef(Node*& nodePtr)
 *      Passes a pointer by reference. The pointer itself can be modified,
 *      allowing the function to allocate or redirect it.
 *
 * @note Try printing or debugging variable values before and after
 *       each call in main() to observe which changes persist.
 */
#include <iostream>

/**
 * A simple Node class for demonstration
 */
class Node {
public:
    int key;
    double value;
    Node *next;
};

/**
 * Pass in int by VALUE
 * --------------------
 * A *copy* of the argument is made.
 * Changes here do NOT affect the original variable
 * @param value copy of the argument passed by the caller
 */
void passIntValue(int value) {
    value = 9;
}

/**
 * Pass an int by REFERENCE
 * ------------------------
 * The parameter ref refers to the original variable.
 * Changes here DO affect the original variable.
 * @param ref reference to the argument passed by the caller
 */
void passIntRef(int &ref) {
    ref = 15;
}

/**
 * Pass a Node pointer by VALUE.
 * -----------------------------
 * We can change what it points to inside the function,
 * but the caller's pointer remains unchanged.
 * @param nodePtr copy of the pointer passed by the caller
 */
void passNodePtr(Node *nodePtr) {
    nodePtr = new Node;
    nodePtr->key = 9;
    nodePtr->value = 4.0;
}

/**
 * Pass a node pointer by REFERENCE
 * --------------------------------
 * The pointer itself is passed by reference,
 * so we can modify the caller's pointer to make
 * it point to a new node
 * @param nodePtr reference to the caller's pointer, we can modify and assign a new
 * address to the pointer variable passed in (the pointer variable in main() is assigned
 * a new address which points to the node created in passNodePtrRef())
 */
void passNodePtrRef(Node *&nodePtr) {
    if (nodePtr == nullptr) {
        nodePtr = new Node;
        nodePtr->key = 8;
        nodePtr->value = 16.0;
        nodePtr->next = nullptr;
    }
}

/**
 * main() to demonstrate all the functions above
 * @return an int
 */
int main() {
    int mainValue = 10;

    // Pass-by-value: mainValue is NOT changed
    passIntValue(mainValue);
    // Pass-by-reference: mainValue IS changed to 15
    passIntRef(mainValue);

    Node *mainNodePtr = nullptr;

    // Pass pointer by value: this function creates a new node,
    // but mainNodePtr is still nullptr afterward
    passNodePtr(mainNodePtr);

    // Pass pointer by reference: this function allocates a new node
    // and updates mainNodePtr in the caller (mainNodePtr is no longer nulltpr,
    // it has the address of the Node created in passNodePtrRef)
    passNodePtrRef(mainNodePtr);

    // Here mainNodePtr points to a valid node
    // passing its 'next' pointer (currently nullptr) by reference
    // allocates and attaches a *second* node
    passNodePtrRef(mainNodePtr->next);

    return 0;
}
