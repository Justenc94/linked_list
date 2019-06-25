/***********************************************************
Name: Justen Crockett
Assignment: 03
Purpose:
***********************************************************/
#include "main.h"

int main() {

    srand(time(nullptr));

    // making number of test node data from
    // TEST_CASE_OFFSET to TEST_CASE_BASE + TEST_CASE_OFFSET (5 - 25)
    int num_tests = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[num_tests];
    char *data[num_tests];
    for (int i = 0; i < num_tests; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //creates list object
    List list;
    //creates DataNode struct to use getNode method
    auto tempDataNode = new DataNode;
    //bool to use as switch for printing
    bool print_list_switch = true;

    //filling arrays with test node data
    cout << "Making " << num_tests << " random test nodes..." << endl;
    make_test_cases(ids, data, num_tests);
    cout << "TEST NODES CREATED" << endl;

    //adding all the random ids and data to list
    for (int i = 0; i < num_tests; i++) {
        if(!list.addNode(ids[i], data[i])){
            list.getNode(ids[i], tempDataNode);
            if(tempDataNode->id == ids[i]){
                cout << "\nID already exists in list." << endl;
            }else{
                cout << "\nerror: something went wrong." << endl;
                print_list_switch = false;
            }
        } else {
            list.addNode(ids[i], data[i]);
        }
    }
    cout << "\nAdding test nodes to list..." << endl;
    cout << "ADDED " << list.getCount() << " RANDOM NODES TO LIST" << endl << endl;

    //printing list with random ids
    if(print_list_switch){
        list.printList(print_list_switch);
    } else {
        cout << "\nerror: something went wrong." << endl;
    }

    //******************************************TESTING ADD TO HEAD BELOW******************************************

    //making test case parallel arrays to hold test data for add head
    int num_head_tests = rand() % (TEST_HEAD_TAIL_BASE+1) + TEST_HEAD_TAIL_OFFSET;

    int head_ids[num_head_tests];
    char *head_data[num_head_tests];
    for (int i = 0; i < num_head_tests; i++) {
        head_data[i] = new char[BUFFER_SIZE-2];
    }

    //making random nodes to add to head
    cout << "Making " << num_head_tests << " random head nodes..." << endl;
    make_head_cases(head_ids, head_data, num_head_tests);
    cout << "HEAD NODES CREATED" << endl << endl;

    for (int i = 0; i < num_head_tests; ++i) {
        if(!list.addNode(head_ids[i], head_data[i])){
            cout << "\nerror: something went wrong." << endl;
            print_list_switch = false;
        }else{
            list.addNode(head_ids[i], head_data[i]);
        }
    }
    cout << "\nADDED " << num_head_tests << " RANDOM NODES TO THE HEAD OF LIST" << endl << endl;

    //printing list with heads added
    if(print_list_switch){
        list.printList(print_list_switch);
    } else {
        cout << "\nerror: something went wrong." << endl;
    }

    //******************************************TESTING ADD TO TAIL BELOW******************************************

    //making test case parallel arrays to hold test data for add head
    int num_tail_tests = rand() % (TEST_HEAD_TAIL_BASE + 1) + TEST_HEAD_TAIL_OFFSET;

    //making test case parallel arrays to hold test data for add tail
    int tail_ids[num_tail_tests];
    char *tail_data[num_tail_tests];
    for (int i = 0; i < num_tail_tests; i++) {
        tail_data[i] = new char[BUFFER_SIZE-2];
    }

    //making random nodes to add to tail
    cout << "Making " << num_tail_tests << " random tail nodes..." << endl;
    make_tail_cases(tail_ids, tail_data, num_tail_tests);
    cout << "TAIL NODES CREATED" << endl << endl;

    for (int i = 0; i < num_tail_tests; ++i) {
        if(!list.addNode(tail_ids[i], tail_data[i])){
            cout << "\nerror: something went wrong." << endl;
            print_list_switch = false;
        }else{
            list.addNode(tail_ids[i], tail_data[i]);
        }
    }
    cout << "\nADDED " << num_tail_tests << " RANDOM NODES TO THE TAIL OF LIST" << endl << endl;

    //printing list with tails added
    if(print_list_switch){
        list.printList(print_list_switch);
    } else {
        cout << "\nerror: something went wrong." << endl;
    }

    //******************************************TESTING DELETE NODES******************************************
    int num_to_del = rand() % (TEST_HEAD_TAIL_BASE+1) + TEST_HEAD_TAIL_OFFSET;
    int del_count = 0;
    auto nodeToDel = new DataNode;
    cout << "Deleting head list item " << num_to_del << " times..." << endl;
    for (int i = 0; i < num_to_del; i++) {
        for (int j = 0; j <= MAX_ADD_TAIL_ID; j++) {
            if(list.getNode(j, nodeToDel) && del_count < num_to_del){
                list.deleteNode(nodeToDel->id);
                del_count++;
            }
        }
    }

    list.printList(print_list_switch);

    return 0;
}
