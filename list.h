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
    int searchIds(int);
    int getNodePos(int);
    void addHead(Node*);
    void deleteHead(int);
    void addMiddle(Node*);
    void deleteMiddle(int);
    void addTail(Node*);
    void deleteTail(int);

};

#endif //LIST_H
