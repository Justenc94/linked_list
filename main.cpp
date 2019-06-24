/***********************************************************
Name: Justen Crockett
Assignment: 03
Purpose:
***********************************************************/
#include "main.h"

int main() {

    srand(time(NULL));

    // making number of test cases from
    // TEST_CASE_OFFSET to TEST_CASE_BASE + TEST_CASE_OFFSET (5 - 25)
    int num_tests = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[num_tests];
    char *data[num_tests];
    for (int i = 0; i < num_tests; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << num_tests << " test cases..." << endl;
    make_test_cases(ids, data, num_tests);
    cout << "Test cases done" << endl << endl;
    List new_item;

    new_item.addNode(1, "TESTING ADD HEAD");
    //new_item.addNode(2, "TESTING ADD TAIL");
    //new_item.addNode(5, "TESTING ADD TAIL");
    //new_item.addNode(4, "TESTING ADD MIDDLE");

    new_item.printList(true);

    for (int j = 0; j < num_tests; j++) {
        cout << "Printing elements in test: " << data[j] << "\t\tID: " << ids[j] << endl;
    }

    for (int j = 0; j < num_tests; j++) {
        cout << "ADDING RANDOM NODE" << endl;
        new_item.addNode(ids[j], data[j]);
    }

    new_item.printList(true);

    return 0;
}