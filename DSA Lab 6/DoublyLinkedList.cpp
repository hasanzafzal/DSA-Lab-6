#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() 
{
	head = nullptr;

}

DoublyLinkedList::~DoublyLinkedList() 
{
    clear();
}

void DoublyLinkedList::insertSorted(int data)
{
    Node* newNode = new Node(data);
    if (!head || head->data >= data)
    {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data < data) 
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    if (temp->next)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void DoublyLinkedList::deleteNode(int data) 
{
    if (!head)
    {
        return;
    }
    Node* temp = head;
    while (temp && temp->data != data) {
        temp = temp->next;
    }
    if (!temp)
    {
        return;
    }
    if (temp->prev)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }
    if (temp->next)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void DoublyLinkedList::traverseForward()  
{
    Node* temp = head;
    if (!temp) 
    {
        cout << "List is empty.\n";
        return;
    }
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void DoublyLinkedList::traverseBackward()  
{
    if (!head) 
    {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

bool DoublyLinkedList::search(int data)  
{
    Node* temp = head;
    int position = 1;
    while (temp) 
    {
        if (temp->data == data) 
        {
            cout << "Element found at position: " << position << endl;
            return true;
        }
        temp = temp->next;
        position++;
    }
    cout << "Element not found.\n";
    return false;
}

void DoublyLinkedList::clear() 
{
    while (head) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}