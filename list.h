/***********************************************************
Name: Justen Crockett
Assignment: 03
Purpose:
***********************************************************/
#ifndef LIST_H
#define LIST_H
#include "functions.h"
#include "data.h"

class List
{
    public:

    List();
    bool addNode(int, string);
    bool deleteNode(int);
    bool getNode(int, DataNode*);
    int getCount();
    bool clear();

    private:
    //administrative variables
    struct Node *head;
    int count;

    //helper methods
    void addHead();
    void deleteHead();
    void addMiddle();
    void deleteMiddle();
    void addTail();
    void deleteTail();

};

#endif //LIST_H
