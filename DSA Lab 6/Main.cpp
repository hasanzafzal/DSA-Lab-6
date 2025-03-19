#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

int main() 
{
    DoublyLinkedList list;
    int choice;
    int value;
    while (true) 
    {
        cout << "\nMenu:\n";
        cout << "1. Insert in sorted order\n";
        cout << "2. Delete an element\n";
        cout << "3. Traverse forward\n";
        cout << "4. Traverse backward\n";
        cout << "5. Search for an element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertSorted(value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;
        case 3:
            list.traverseForward();
            break;
        case 4:
            list.traverseBackward();
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}