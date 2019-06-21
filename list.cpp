/***********************************************************
Name: Justen Crockett
Assignment: 03
Purpose:
***********************************************************/
#include "list.h"

List::List() {
    head = nullptr;
    count = 0;
}

//********************************************PUBLIC METHODS********************************************
bool List::addNode(int new_id, string new_data){
    if(head != nullptr){
        if(head->next == nullptr){
            addTail(new_id, new_data);
        }else{
            addMiddle(new_id, new_data);
        }
    }else{
        addHead(new_id, new_data);
    }
}

bool List::deleteNode(int){

}

bool List::getNode(int, DataNode *){

}

void List::printList(bool){
    cout << head->id << endl;
}

int List::getCount(){
    return count;
}

bool List::clear(){

}

//********************************************HELPER METHODS********************************************


int List::linearSearch(int id){

}

void List::addHead(int new_id, string new_data){
    Node *tmp = new Node;
    tmp->id = new_id;
    tmp->data = new_data;
    tmp->next = nullptr;
    tmp->back = nullptr;
    head = tmp;
}

void List::deleteHead(){

}

void List::addMiddle(int id, string data){

}

void List::deleteMiddle(){

}

void List::addTail(int id, string data){

}

void List::deleteTail(){

}


