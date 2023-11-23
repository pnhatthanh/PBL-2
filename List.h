#pragma once
#include <iostream>
using namespace std;
template<typename T>
struct Node
{
    T data;
    Node *pre;
    Node *next;
};
template<typename T>
Node<T> *makeNode(T data)
{
    Node<T> *node;
    node = new Node<T>;
    node->data = data;
    node->next = NULL;
    node->pre = NULL;
    return node;
}
template <typename T>
class List
{
    private:
        Node<T> *pHead;
        Node<T> *pTail;
        int size;

    public:
        List();
        ~List();
        void addFirst(T data);
        void addLast(T data);
        int size_list();
        void removeFirst();
        void removeLast();
        void remove(int);
        T &operator[](int);
        T &getLast();
};
