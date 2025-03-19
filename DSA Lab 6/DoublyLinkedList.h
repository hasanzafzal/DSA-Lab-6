#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
using namespace std;

class DoublyLinkedList 
{
private:
    struct Node 
    {
        int data;
        Node* prev;
        Node* next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };
    Node* head;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertSorted(int data);
    void deleteNode(int data);
    void traverseForward();
    void traverseBackward();
    bool search(int data);
    void clear();
};

#endif