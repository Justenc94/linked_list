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
    cout << "Making " << num_tests << " random test nodes...\n" << endl;
    make_test_cases(ids, data, num_tests);

    //adding all the random ids and data to list
    cout << "Node count: " << list.getCount() << endl;
    cout << "Adding test nodes to list..." << endl;
    for (int i = 0; i < num_tests; i++) {
        if(!list.addNode(ids[i], data[i])){
            list.getNode(ids[i], tempDataNode);
            if(tempDataNode->id == ids[i]){
                cout << "\nID already exists in list, not added." << endl;
            }else{
                cout << "\nerror: something went wrong." << endl;
                print_list_switch = false;
            }
        } else {
            list.addNode(ids[i], data[i]);
        }
    }
    cout << "Node count: " << list.getCount() << endl << endl;

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
    make_head_cases(head_ids, head_data, num_head_tests);
    cout << "Node count: " << list.getCount() << endl;
    cout << "Adding " << num_head_tests << " random nodes to the head of the list" << endl;
    for (int i = 0; i < num_head_tests; ++i) {
        if(!list.addNode(head_ids[i], head_data[i])){
            cout << "\nerror: something went wrong." << endl;
            print_list_switch = false;
        }else{
            list.addNode(head_ids[i], head_data[i]);
        }
    }
    cout << "Node count: " << list.getCount() << endl << endl;

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
    make_tail_cases(tail_ids, tail_data, num_tail_tests);
    cout << "Node count: " << list.getCount() << endl;
    cout << "Adding " << num_tail_tests << " random nodes to the tail of the list" << endl;
    for (int i = 0; i < num_tail_tests; ++i) {
        if(!list.addNode(tail_ids[i], tail_data[i])){
            cout << "\nerror: something went wrong." << endl;
            print_list_switch = false;
        }else{
            list.addNode(tail_ids[i], tail_data[i]);
        }
    }
    cout << "Node count: " << list.getCount() << endl << endl;

    //printing list with tails added
    if(print_list_switch){
        list.printList(print_list_switch);
    } else {
        cout << "\nerror: something went wrong." << endl;
    }

    //******************************************TESTING DELETE NODES******************************************

    //delete random number of heads
    int num_to_del = rand() % (TEST_HEAD_TAIL_BASE+1) + TEST_HEAD_TAIL_OFFSET;
    int del_count = 0;
    auto nodeToDel = new DataNode;
    cout << "Node count: " << list.getCount() << endl;
    cout << "Deleting head list node " << num_to_del << " times..." << endl;
    for (int i = 0; i < num_to_del; i++) {
        for (int j = 0; j <= MAX_ADD_TAIL_ID+10000; j++) {
            if(list.getNode(j, nodeToDel) && del_count < num_to_del){
                list.deleteNode(nodeToDel->id);
                del_count++;
            }
        }
    }
    cout << "Node count: " << list.getCount() << endl << endl;

    //prints list with deleted heads
    if(print_list_switch){
        list.printList(print_list_switch);
    } else {
        cout << "\nerror: something went wrong." << endl;
    }

    //delete random number of middle items
    del_count = 0;
    cout << "Node count: " << list.getCount() << endl;
    cout << "Deleting middle list node " << num_to_del << " times... (2nd node)" << endl;
    for (int i = 0; i < num_to_del; i++) {
        for (int j = 0; j <= MAX_ADD_TAIL_ID+10000; j++) {
            if(list.getNode(j, nodeToDel) && del_count < num_to_del+1){     //bypasses first id to be deleted by incrementing
                if(del_count ==  0){                                        //count without deleting the first match (the head)
                    del_count++;
                }else{
                    list.deleteNode(nodeToDel->id);
                    del_count++;
                }
            }
        }
    }
    cout << "Node count: " << list.getCount() << endl << endl;

    //prints list with deleted middles
    if(print_list_switch){
        list.printList(print_list_switch);
    } else {
        cout << "\nerror: something went wrong." << endl;
    }


    //delete random number of tails
    del_count = 0;
    nodeToDel = new DataNode;
    cout << "Node count: " << list.getCount() << endl;
    cout << "Deleting tail list node " << num_to_del << " times..." << endl;
    for (int i = 0; i < num_to_del; i++) {
        for (int j = MAX_ADD_TAIL_ID+10000; j > 0; j--) {
            if(list.getNode(j, nodeToDel) && del_count < num_to_del){
                list.deleteNode(nodeToDel->id);
                del_count++;
            }else if(list.getCount() == 0){
                cout << "Cannot delete ID, list is empty." << endl;
                del_count++;
            }
        }
    }
    cout << "Node count: " << list.getCount() << endl << endl;

    //prints list with deleted tails
    if(print_list_switch){
        list.printList(print_list_switch);
    } else {
        cout << "\nerror: something went wrong." << endl;
    }

    //******************************************TESTING GET NODE******************************************

    //calls the getnode method on every item in list to show that any position is get-able
    auto nodeToGet = new DataNode;
    auto tempGetNode = new DataNode;

    cout << "======= Testing getNode() on entire list =======" << endl;
    for (int j = 0; j <= MAX_ADD_TAIL_ID+15000; j++) {
        list.getNode(j, nodeToGet);
        if(nodeToGet->id == j){
            list.getNode(nodeToGet->id, tempGetNode);
            cout << "Get Node on ID: " << tempGetNode->id << "\tData: " << tempGetNode->data << endl;
        }
    }
    cout << "================================================" << endl << endl;

    //testing that getnode will not get a ID that is not in the list
    tempGetNode = new DataNode;
    int num_wrong_ids = rand() % (TEST_HEAD_TAIL_BASE+1) + TEST_HEAD_TAIL_OFFSET;   //number of times that get wrong id should iterate
    int random_ids[num_wrong_ids];                                                  //stores random wrong ids
    //generate random ids that are too large to be inside list
    for (int i = 0; i < num_wrong_ids; i++) {
        int random_id = rand() % MAX_ADD_TAIL_ID + 25000;
        random_ids[i] = random_id;
    }

    cout << "Testing get node on ID that is not in list " << num_wrong_ids << " times...\n" << endl;
    for (int i = 0; i < num_wrong_ids; i++) {
        cout << "Searching list for ID: " << random_ids[i] << endl;
        if(!list.getNode(random_ids[i], tempGetNode)){                       //if getnode is not successful in search
            cout << "ID not found. Cannot get ID." << endl;
        }else{
            list.getNode(random_ids[i], tempGetNode);                       //if getnode is succesful returns get of that ID
            cout << "Get Node on ID: " << tempGetNode->id << "\tData: " << tempGetNode->data << endl;
        }
    }
    cout << "\n*****Testing get node complete*****" << endl << endl;

    //************************************** TESTING DELETE NODE SPECIAL CASES ***************************************

    //testing delete on empty list and ID that doesnt exist
    cout << "Testing delete node on ID that is not in list " << num_wrong_ids << " times...\n" << endl;
    for (int i = 0; i < num_wrong_ids; i++) {
        cout << "Searching to delete list ID: " << random_ids[i] << endl;
        if(!list.deleteNode(random_ids[i])){                       //if getnode is not successful in search
            cout << "ID not found. Cannot delete ID." << endl;
        }else{
            list.deleteNode(random_ids[i]);                       //if getnode is succesful returns get of that ID
            cout << "Delete Node on ID: " << tempGetNode->id << "\tData: " << tempGetNode->data << endl << endl;
        }
    }

    //testing delete list on an empty list
    cout << "\nTesting delete node on all original random nodes..." << endl;
    list.clear();                              //clear list for tests
    cout << "Cleared list..." << endl << endl;

    for (int i = 0; i < num_tests; i++) {
        list.getNode(ids[i], nodeToGet);
        if(nodeToGet->id == i){
            list.deleteNode(nodeToGet->id);
            cout << "Deleted Node on ID: " << ids[i] << endl;
        }else if(list.getCount() == 0) {
            cout << "Tried to delete node for ID: " << ids[i] << "\t Unable to delete node, list is empty." << endl;
        }else{
                cout << "ID not found. Cannot get ID." << endl;
            }
    }
    cout << "\n*****Testing delete node on wrong IDs and empty list complete*****" << endl << endl;


    //TODO: Need to build a test to show that you can clear a list, with cases: 0, 1, or greater than 1 nodes

    //************************************** TESTING CLEAR LIST SPECIAL CASES ***************************************

    int add_node_num;   //variable to determine whether one or more nodes will be added

    //testing clear on empty list

    cout << "Node count: " << list.getCount() << endl;
    cout << "Testing clear list on empty list..." << endl;

    if (list.clear()){
        cout << "List successfully cleared" << endl;
    }else{
        cout << "List is already empty. Not cleared." << endl;
    }
    cout << "Node count: " << list.getCount() << endl << endl;

    //testing clear on list with 1 node
    add_node_num = 1;

    for (int i = 0; i < add_node_num; i++) {
        list.addNode(ids[i], data[i]);
    }

    cout << "Node count: " << list.getCount() << endl;
    cout << "Testing clear list on list with 1 node..." << endl;

    if (list.clear()){
        cout << "List successfully cleared" << endl;
    }else{
        cout << "List is already empty. Not cleared." << endl;
    }
    cout << "Node count: " << list.getCount() << endl << endl;

    //testing clear on list with more than 1 node

    cout << "Node count: " << list.getCount() << endl;
    cout << "Testing clear list on list with more than 1 node..." << endl;

    if (list.clear()){
        cout << "List successfully cleared" << endl;
    }else{
        cout << "List is already empty. Not cleared." << endl;
    }
    cout << "Node count: " << list.getCount() << endl << endl;

    return 0;
}
