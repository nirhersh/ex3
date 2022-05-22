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
    * pushes a new item to the end of the queue
    * 
    */ 
    void pushBack(const T& newItem);

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

    class EmptyQueue{};

private:
    T* data; // or should we make a linked list??
    int size;
    int maxSize;
    void expandArray();
    static const int EXPAND_RATE = 2;
    static const int INITIAL_SIZE = 10;
};

template <class T>
class Queue<T>::Iterator{
public:
    const T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);

    bool operator==(const Iterator& it) const;
    bool operator!=(const Iterator& it) const;

    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    class InvalidOperation{};
private:
    const Queue<T>* queue;
    int index;
    Iterator(const Queue<T>* queue, int index);
    friend class Queue<T>;
};

#endif //EX3_Queue_H