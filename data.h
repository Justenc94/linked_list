/**********************************************************
Name: Justen Crockett
Assignment: 03
Purpose:
***********************************************************/
#ifndef DATA_H
#define DATA_H
#include "list.h"
using std::string;

struct Node{
    int id;
    string data;
    Node *next;
    Node *back;
};

struct DataNode{
    int id;
    string data;
};

#endif //DATA_H
