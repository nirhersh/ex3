#ifndef EX3_Queue_H
#define EX3_Queue_H

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
    * pops the first item out of the queue
    * 
    */ 
    void popFront();

    /*
    *
    * returns the size of the queue
    * 
    */ 
    int size();

    /*
    *
    * a function that filters the queue with the given condition
    * 
    * @return a new queue with the filtered items
    * 
    */
    template <class Condition>
    Queue<T> filter(const Condition c);

    /*
    *
    * a function that transforms the items of the given queue with the operation given
    *
    */
    template <class Operation>
    static void transform(Queue<T> queue, const Operation o);

    /*
    *
    * class of iterators to iterate through the queue
    * 
    */ 
    class Iterator;

    Iterator begin() const;
    
    Iterator end() const;

    class ConstIterator;

    ConstIterator beginConst() const;

    ConstIterator endConst() const;

    class EmptyQueue{};

    class Node;

private:
    Node* m_firstNode;
    int m_size;
    static const int EMPTY = 0;
};

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
    Node* currentNodePtr = m_firstNode;
    Node* tempNodePtr;
    while(currentNodePtr != nullptr){ // use iterator instead
        tempNodePtr = currentNodePtr->m_next;
        delete (currentNodePtr);
        currentNodePtr = tempNodePtr;
    }
}

template <class T>
Queue<T>::Queue(const Queue<T>& other) : m_firstNode(nullptr), m_size(other.m_size){
    // implement later with pushback
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other){
    // implement with pushBack
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
    return m_firstNode->m_data;
}

template <class T>
void Queue<T>::popFront(){
    Node* tempNode = m_firstNode->m_next;
    delete m_firstNode;
    m_firstNode = tempNode;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::begin() const{
    return Iterator(this, 0);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end() const{
    return Iterator(this, m_size);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::beginConst() const{
    return ConstIterator(this, 0);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::endConst() const{
    return ConstIterator(this, m_size);
}
//---------------------Node Implementation---------------------
template <class T>
Queue<T>::Node::Node(const T data) : m_data(data), m_next(nullptr){}

//---------------------Iterator Implementation---------------------
template <class T>
Queue<T>::Iterator::Iterator(const Queue<T>* queue, int index) : m_queue(queue), m_index(index){}

template <class T>
T& Queue<T>::Iterator::operator*() const{
    if(m_index < 0 || m_index >= m_queue->m_size){
        throw InvalidOperation();
    }

    Node* tempNode = m_queue->m_firstNode; 
    for(int i=0; i<m_index; i++){
        tempNode = tempNode->m_next;
        assert(tempNode == nullptr);
    }
    return tempNode->m_data;
}

template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++(){
    ++m_index;
    return *this;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int){
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
    return !(*this == i);
}

template <class T>
T* const Queue<T>::Iterator::operator->() const{
    if(m_index < 0 || m_index >= m_queue->m_size){
        throw InvalidOperation();
    }

    Node* tempNode = m_queue->m_firstNode; 
    for(int i=0; i<m_index; i++){
        tempNode = tempNode->m_next;
        assert(tempNode == nullptr);
    }
    return &(tempNode->m_data);
}

//---------------------ConstIterator Implementation---------------------
template <class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>* queue, int index) : m_queue(queue), m_index(index){}

template <class T>
const T& Queue<T>::ConstIterator::operator*() const{
    if(index < 0 || index >= m_queue->m_size){
        throw InvalidOperation();
    }

    Node* tempNode = m_queue->m_firstNode; 
    for(int i=0; i<index; i++){
        tempNode = tempNode->m_next;
        assert(tempNode == nullptr);
    }
    return tempNode->m_data;
}

template <class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++(){
    ++m_index;
    return *this;
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int){
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
    return !(*this == i);
}

template <class T>
const T* const Queue<T>::ConstIterator::operator->() const{
    if(m_index < 0 || m_index >= m_queue->m_size){
        throw InvalidOperation();
    }

    Node* tempNode = m_queue->m_firstNode; 
    for(int i=0; i<m_index; i++){
        tempNode = tempNode->m_next;
        assert(tempNode == nullptr);
    }
    return &(tempNode->m_data);
}

#endif //EX3_Queue_H