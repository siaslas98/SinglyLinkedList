#include <iostream>
#include "SLinkedList.h"

int main() {
    SLinkedList<int> list;

    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtHead(3);
    list.printList(); // Output 3 -> 2 -> 1 -> nullptr

    list.remove(2);
    list.printList(); // Output: 3 -> 1 -> nullptr

    list.insertAtTail(4);
    list.printList(); // Output: 3 -> 1 -> 4 -> nullptr

    return 0;
}