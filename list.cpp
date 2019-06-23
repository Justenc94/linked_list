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
int List::linearSearch(int id_search){
    Node *temp_node;
    temp_node = head;
    int found;
    for (int i = 0; i < count; i++) {
        if(id_search == temp_node->id){
            found = i;
            return found;
        }else{
            return -1;
        }
    }
}

void List::addHead(int new_id, string new_data){
    Node *temp_node = new Node;
    temp_node->id = new_id;
    temp_node->data = new_data;
    temp_node->next = nullptr;
    temp_node->back = nullptr;
    head = temp_node;
    count++;
}

void List::deleteHead(){

}

void List::addMiddle(int new_id, string new_data){

}

void List::deleteMiddle(){

}

void List::addTail(int id, string data){
    Node *new_node = new Node;
    Node *temp_node;
    new_node->id = id;              //add id to new node
    new_node->data = data;          //add data to new node
    temp_node = head;               //TODO: need to make this equal to the last node in the list
    new_node->back = temp_node;
    new_node->next = nullptr;
    temp_node->next = new_node;
    count++;
}

void List::deleteTail(){

}


