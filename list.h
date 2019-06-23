/***********************************************************
Name: Justen Crockett
Assignment: 03
Purpose:
***********************************************************/
#ifndef LIST_H
#define LIST_H
#include <string>
#include <iostream>
#include "functions.h"
#include "data.h"
using namespace std;

class List
{
    public:

    List();
    bool addNode(int, string);
    bool deleteNode(int);
    bool getNode(int, DataNode*);
    void printList(bool);
    int getCount();
    bool clear();

    private:
    //administrative variables
    struct Node *head;
    int count;

    //helper methods
    int linearSearchMiddle(int);
    void addHead(int, string);
    void deleteHead();
    void addMiddle(int, string);
    void deleteMiddle();
    void addTail(int, string);
    void deleteTail();

};

#endif //LIST_H
