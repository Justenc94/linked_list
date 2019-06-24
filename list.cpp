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
    Node *temp_node = head;
    if(searchIds(new_id) != -1){
        Node *new_node = new Node;
        new_node->id = new_id;
        new_node->data = new_data;
        if(temp_node == nullptr || temp_node->id > new_node->id){
            addHead(new_node);
            return true;
        }else{
            while(temp_node->next != nullptr && temp_node->next->id < new_node->id){
                addMiddle(new_node);
                return true;
            }
            addTail(new_node);
            return true;
        }
    }
    return false;
}

bool List::deleteNode(int){

}

bool List::getNode(int, DataNode *){

}

void List::printList(bool){
    Node *temp_node;
    temp_node = head;
    for (int i = 0; i < count; i++) {
        cout << "\tNode Number: " << (i+1) << endl;
        cout << "ID: " << temp_node->id << endl;
        cout << "DATA: " << temp_node->data << endl << endl;
        temp_node = temp_node->next;
    }
}

int List::getCount(){
    return count;
}

bool List::clear(){

}

//********************************************HELPER METHODS********************************************

//method to determine if an id is already in list and if not - return position where node should be added
int List::searchIds(int id_search){
    Node *temp_node = head;
    for (int i = 0; i < count; i++) {
        if(id_search == temp_node->id){
            return -1;
        }
        temp_node = temp_node->next;
    }
    return count;
}

void List::getNodePos(int id_search, string temp_data){

}

void List::addHead(Node *temp_node){
    Node *temp_head = head;
    if(temp_head == nullptr){
        head = temp_node;
        temp_node->next = nullptr;
        temp_node->back = nullptr;
        count++;
    }else {
        temp_node->next = temp_head;
        temp_node->back = nullptr;
        temp_head->back = temp_node;
        temp_head->next = temp_head->next->next;
        count++;
    }
}

void List::deleteHead(){

}

void List::addMiddle(Node *temp_node){

}

void List::deleteMiddle(){

}

void List::addTail(Node *temp_node){

}

void List::deleteTail(){

}


