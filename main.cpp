/***********************************************************
Name: Justen Crockett
Assignment: 03
Purpose:
***********************************************************/
#include "main.h"

int main() {
    List new_item;

    new_item.addNode(1, "TESTING ADD HEAD");
    new_item.addNode(2, "TESTING ADD TAIL");
    new_item.addNode(3, "TESTING ADD MIDDLE");

    new_item.printList(true);

    return 0;
}