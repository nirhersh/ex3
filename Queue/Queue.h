//
// composed by code artists nir herscovici & roei bloch
// all rights reserved to niroei industries ba'am
//

#ifndef EX3_Queue_H
#define EX3_Queue_H

#include <iostream>
#include <cassert>

template <class T>
class Queue{
public:
    /*
    *
    * C'tor of the Queue class
    * 
    */
    Queue();

    /*
    *
    * D'tor of the Queue class
    * 
    */
    ~Queue();

    /*
    *
    * Copy c'tor of the Queue class
    * 
    */
    Queue(const Queue<T>& other);

    /*
    *
    * D'tor of the Queue class
    * 
    */
    Queue<T>& operator=(const Queue<T>& other);

    /*
    *
    * pushes a new item to the end of the queue
    * 
    */ 
    void pushBack(const T newItem);

    /*
    *
    * returns the item at the start of the queue
    * 
    */ 
    T& front();

    /*
    *
    * returns the item at the start of the queue
    * 
    */ 
    const T& front() const;

    /*
    *
    * pops the first item out of the queue
    * 
    */ 
    void popFront();

    /*
    *
    * returns the size of the queue
    * 
    */ 
    int size() const;

    /*
    *
    * class of iterators to iterate through the queue
    * 
    */ 
    class Iterator;

    /*
    *
    * function that returns an iterator to the start of the queue
    * 
    */ 
    Iterator begin();
    
    /*
    *
    * function that returns an iterator to the end of the queue
    * 
    */
    Iterator end();

    /*
    *
    * class of iterators to a const queue
    * 
    */
    class ConstIterator;

    /*
    *
    * function that returns a const iterator to the start of the queue
    * 
    */
    ConstIterator begin() const;

    /*
    *
    * function that returns a const iterator to the end of the queue
    * 
    */
    ConstIterator end() const;

    /*
    *
    * an exception that is thrown when trying to make invalid operation on an empty queue
    * 
    */
    class EmptyQueue{};

    /*
    *
    * a class of nodes that hold the objects in the queue
    * 
    */
    class Node;

private:
    Node* m_firstNode;
    int m_size;
    static const int EMPTY = 0;
};

/*
*
* a function that filters the queue with the given condition
* 
* @return a new queue with the filtered items
* 
*/
template <class T ,class Condition>
Queue<T> filter(const Queue<T> queue, const Condition c)
{
    Queue<T> result;
    for (const T& elem : queue)
    {
        if (c(elem))
        {
            result.pushBack(elem);
        }
    }
    return result;
}

/*
*
* a function that transforms the items of the given queue with the operation given
*
*/
template <class T, class Operation>
void transform(Queue<T>& queue, const Operation o){
    for(T& data : queue){
        o(data);
    }
}

template <class T>
class Queue<T>::Node{
    Node(const Node&) = delete;
    Node& operator=(const Node& other) = delete;
private:
    T m_data;
    Node* m_next; 
    Node(const T data);
    friend class Queue<T>;
};

template <class T>
class Queue<T>::Iterator{
public:
    T& operator*() const;
    T* const operator->() const;
    Iterator& operator++();
    Iterator operator++(int);

    bool operator==(const Iterator& it) const;
    bool operator!=(const Iterator& it) const;

    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    
    class InvalidOperation{};
private:
    const Queue<T>* m_queue;
    int m_index;
    Iterator(const Queue<T>* queue, int index);
    Iterator(ConstIterator constIt);
    friend class Queue<T>;
};

template <class T>
class Queue<T>::ConstIterator{
public:
    const T& operator*() const;
    const T* const operator->() const;
    ConstIterator& operator++();
    ConstIterator operator++(int);

    bool operator==(const ConstIterator& it) const;
    bool operator!=(const ConstIterator& it) const;

    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;

    class InvalidOperation{};
private:
    const Queue<T>* m_queue;
    int m_index;
    ConstIterator(const Queue<T>* queue, int index);
    friend class Queue<T>;
};

//---------------------Queue Implementation---------------------
template <class T>
Queue<T>::Queue() : m_firstNode(nullptr), m_size(EMPTY)
{}

template <class T>
Queue<T>::~Queue(){
    int size = m_size;
    for(int i=0; i < size; i++){
         this->popFront();
    }
    assert(m_firstNode == nullptr);
}

template <class T>
Queue<T>::Queue(const Queue<T>& other) : m_firstNode(nullptr), m_size(EMPTY){
    for(const T& elem : other){
        try{
            this->pushBack(elem);
        }catch(std::bad_alloc& e){
            int size = m_size;
            for(int i=0; i < size; i++){
                this->popFront();
                throw e;
            }
        }
    }
    assert(m_size == other.m_size);
    
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other){
    if(&other == this)
    {
        return *this;
    }
    int size = m_size;
    for(int i=0; i<size; i++){
        this->popFront();
    }
    for(const T& elem : other){
        this->pushBack(elem);
    }
    assert(m_size == other.m_size);
    return *this;
    
}

template <class T>
void Queue<T>::pushBack(const T newItem){
    Node* newNode = new Queue<T>::Node(newItem);
    if(m_firstNode == nullptr){
        m_firstNode = newNode;
    }else{
        Node* tempNode = m_firstNode;
        while(tempNode->m_next != nullptr){ // need to replace with iterator
            tempNode = tempNode->m_next;
        }
        tempNode->m_next = newNode;
    }
    m_size++;
}


template <class T>
T& Queue<T>::front(){
    if(m_size == 0){
        throw EmptyQueue();
    }
    return m_firstNode->m_data;
}

template <class T>
const T& Queue<T>::front() const{
    if(m_size == 0){
        throw EmptyQueue();
    }
    return m_firstNode->m_data;
}

template <class T>
void Queue<T>::popFront()
{
    if(m_size == EMPTY){
        throw EmptyQueue();
    }
    Node* tempNode = m_firstNode->m_next;
    delete m_firstNode;
    m_firstNode = tempNode;
    m_size--;
}

template <class T>
int Queue<T>::size() const
{
    return m_size;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::begin(){
    return Iterator(this, EMPTY);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end(){
    return Iterator(this, m_size);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const{
    return ConstIterator(this, EMPTY);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::end() const{
    return ConstIterator(this, m_size);
}
//---------------------Node Implementation---------------------
template <class T>
Queue<T>::Node::Node(const T data) : m_data(data), m_next(nullptr){}

//---------------------Iterator Implementation---------------------
template <class T>
Queue<T>::Iterator::Iterator(const Queue<T>* queue, int index) : m_queue(queue), m_index(index){}

template <class T>
Queue<T>::Iterator::Iterator(ConstIterator constIt) : m_queue(constIt.m_queue), m_index(constIt.m_index){}

template <class T>
T& Queue<T>::Iterator::operator*() const{
    if(m_index < EMPTY || m_index >= m_queue->m_size){
        throw InvalidOperation();
    }

    if(m_queue->m_size == EMPTY){
        throw EmptyQueue();
    }

    Node* tempNode = m_queue->m_firstNode; 
    for(int i=0; i<m_index; i++){
        tempNode = tempNode->m_next;
    }
    return tempNode->m_data;
}

template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++(){
    if(m_queue->m_size <= m_index){
        throw InvalidOperation();
    }
    ++m_index;
    return *this;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int){
    if(m_queue->m_size <= m_index){
        throw InvalidOperation();
    }
    Iterator result = *this;
    ++*this;
    return result;
}

template <class T>
bool Queue<T>::Iterator::operator==(const Iterator& it) const{
    return m_index == it.m_index;
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator& it) const{
    return !(*this == it);
}

template <class T>
T* const Queue<T>::Iterator::operator->() const{
    if(m_index < EMPTY || m_index >= m_queue->m_size){
        throw InvalidOperation();
    }

    if(m_queue->m_size == EMPTY){
        throw EmptyQueue();
    }

    Node* tempNode = m_queue->m_firstNode; 
    for(int i=0; i<m_index; i++){
        tempNode = tempNode->m_next;
    }
    return &(tempNode->m_data);
}

//---------------------ConstIterator Implementation---------------------
template <class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>* queue, int index) : m_queue(queue), m_index(index){}

template <class T>
const T& Queue<T>::ConstIterator::operator*() const{
    if(m_index < EMPTY || m_index >= m_queue->m_size){
        throw InvalidOperation();
    }

    if(m_queue->m_size == EMPTY){
        throw EmptyQueue();
    }

    Node* tempNode = m_queue->m_firstNode; 
    for(int i=0; i<m_index; i++){
        tempNode = tempNode->m_next;
    }
    return tempNode->m_data;
}

template <class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++(){
    if(m_queue->m_size <= m_index){
        throw InvalidOperation();
    }
    ++m_index;
    return *this;
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int){
    if(m_queue->m_size <= m_index){
        throw InvalidOperation();
    }
    ConstIterator result = *this;
    ++*this;
    return result;
}

template <class T>
bool Queue<T>::ConstIterator::operator==(const ConstIterator& it) const{
    return m_index == it.m_index;
}

template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& it) const{
    return !(*this == it);
}

template <class T>
const T* const Queue<T>::ConstIterator::operator->() const{
    if(m_index < EMPTY || m_index >= m_queue->m_size){
        throw InvalidOperation();
    }

    if(m_queue->m_size == EMPTY){
        throw EmptyQueue();
    }

    Node* tempNode = m_queue->m_firstNode; 
    for(int i=0; i<m_index; i++){
        tempNode = tempNode->m_next;
    }
    return &(tempNode->m_data);
}


#endif //EX3_Queue_H