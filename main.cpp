#include <iostream>
#include "List.h"
using namespace std;


int main() {
    List<int> myList;

    myList.addFront(10);
    myList.addFront(20);
    myList.addTail(30);
    myList.addTail(40);

    cout << "Initial List: ";
    myList.displayForwards();

    // Testing getAt()
    try {
        cout << "Element at index 2: " << myList.getAt(2) << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Testing insertAt()
    try {
        cout << "Inserting 99 at index 2..." << endl;
        myList.insertAt(2, 99);
        myList.displayForwards();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Testing removeAt()
    try {
        cout << "Removing element at index 3..." << endl;
        myList.removeAt(3);
        myList.displayForwards();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Testing removeFront()
    try {
        cout << "Removing front element..." << endl;
        myList.removeFront();
        myList.displayForwards();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Testing removeTail()
    try {
        cout << "Removing tail element..." << endl;
        myList.removeTail();
        myList.displayForwards();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.