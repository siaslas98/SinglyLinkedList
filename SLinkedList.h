#pragma once
#include<iostream>

using namespace std;

template<typename T>
class SLinkedList{
private:
    struct Node{
    public:
        T _val;
        Node* nextNode;

        Node(T value): _val(value), nextNode(nullptr){}
    };

    Node* _head;

public:
    SLinkedList() : _head(nullptr){} // Initialize to no elements

    ~SLinkedList() {
        Node* current = _head;
        while(current != nullptr){
            Node* next = current->nextNode;
            delete current;
            current = next;
        }
    }

    void insertAtHead(T val){
        Node* newNode = new Node(val); // Allocate memory for a new Node on the heap
        newNode->nextNode = _head; // Direct the new nodes nextNode pointer to what _head was pointing to
        _head = newNode; // Then have _head point to memory address of newNode
    };

    void insertAtTail(T val){
        Node* newNode = new Node(val);

        // Edge case: headNode doesn't point to anything
        if(_head == nullptr){
            _head = newNode;
        }

        else {
            Node* currentNode = _head;
            while (currentNode->nextNode != nullptr) {
                currentNode = currentNode->nextNode;
            }

            currentNode->nextNode = newNode;
        }
    }

    bool remove(T val){
        // Edge case: If head doesn't point to anything, there is nothing to remove
        if(_head == nullptr) return false;

        // Edge case: If head contains the value we want to remove
        if(_head->_val == val){
            Node* temp = _head;
            _head = _head -> nextNode;
            delete temp;
            return true;
        }

        Node* current = _head; // Start at _head pointer
        while(current->nextNode != nullptr){ // As long as the next pointer is not nullptr we continue checking
            if(current->nextNode->_val == val){ // Compare the next Nodes value with the value we want to remove
                Node* temp = current->nextNode->nextNode; // Keep track of the next Nodes next Node
                delete current->nextNode; // Delete the next node because it has the value we want to remove
                current->nextNode = temp; // Set current nodes next node pointer to what its previous next node pointer points to
                return true;
            }
            current = current->nextNode;
        }
        return false;
    }

    void printList() const{
        Node* current = _head;
        while(current != nullptr){
            cout << current->_val << " -> ";
            current = current->nextNode;
        }
        cout << "nullptr" << endl;
    }
};

