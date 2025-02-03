#include <iostream>
#include "LinkedList/LinkedList.h"

using namespace std;

int main() {

    LinkedList myLinkedList = *new LinkedList(4);

    myLinkedList.append(2);
    myLinkedList.append(3);

    myLinkedList.deleteLast();

    myLinkedList.printAll();

    myLinkedList.makeEmpty();
    return 0;
}
