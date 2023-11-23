#include "List.h"

template <typename T>
List<T>::List()
{
    this->pHead = NULL;
    this->pTail = NULL;
    this->size = 0;
}

template <typename T>
List<T>::~List()
{
    while (this->pHead != NULL)
    {
        this->removeFirst();
    }
    delete this->pHead;
}

template <typename T>
void List<T>::addFirst(T data)
{
    Node<T> *node = makeNode(data);
    if (this->pHead == NULL)
    {
        this->pHead = this->pTail = node;
    }
    else
    {
        node->next = this->pHead;
        this->pHead->pre = node;
        this->pHead = node;
    }
    this->size++;
}

template <typename T>
void List<T>::addLast(T data)
{
    Node<T> *node = makeNode(data);
    if (this->pHead == NULL)
    {
        this->pHead = this->pTail = node;
    }
    else
    {
        this->pTail->next = node;
        node->pre = this->pTail;
        this->pTail = node;
    }
    this->size++;
}

template <typename T>
int List<T>::size_list()
{
    return this->size;
}

template <typename T>
void List<T>::removeFirst()
{
    if (this->pHead == NULL)
        return;
    if (this->pHead->next == NULL)
    {
        this->pHead = this->pTail = NULL;
        this->size--;
        return;
    }
    this->pHead = this->pHead->next;
    this->pHead->pre = NULL;
    this->size--;
}

template <typename T>
void List<T>::removeLast()
{
    if (this->pTail == NULL)
        return;
    if (this->pHead->next == NULL)
    {
        this->pHead = this->pTail = NULL;
        this->size--;
        return;
    }
    this->pTail = this->pTail->pre;
    this->size--;
}

template<typename T>
void List<T>::remove(int index){
    if(index<0||index>=this->size||this->size==0){
        return;
    }else if(this->size==1){
        this->pHead=this->pTail=NULL;
        this->size=0;
    }else if(index==0){
        this->removeFirst();
    }else if (index==this->size-1){
        this->removeLast();
    }else {
        Node<T>* tmp= new Node<T>;
        tmp=this->pHead;
        for(int i=0;i<index;i++){
            tmp=tmp->next;
        }
        tmp->pre->next=tmp->next;
        tmp->next->pre=tmp->pre;
        this->size--;
    }  
}

template <typename T>
T &List<T>::operator[](int index)
{
    Node<T> *node = new Node<T>;
    node = this->pHead;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node->data;
}
template <typename T>
T &List<T>::getLast()
{
    return this->pTail->data;
}