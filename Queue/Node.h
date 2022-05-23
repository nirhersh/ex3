#ifndef EX3_NODE_H
#define EX3_NODE_H

template<class T>
class Node {
public:
    explicit Node(T data);

    ~Node() = default;

    Node(const Node<T>& other) = delete;

    Node<T>& operator=(const Node<T>&) = delete;

    T& getData() const;

    Node<T>* getNext();

private:
    T m_data;
    Node<T>* m_next;
};

template<class T>
Node<T>::Node(T data) : m_data(data), m_next(NULL){}

template<class T>
T& Node<T>::getData() const{
    return &m_data;
}

template<class T>
Node<T>* Node<T>::getNext(){
    return m_next;
}

#endif //EX3_NODE_H

