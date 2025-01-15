#include <iostream>
using namespace std;

//Saifullah Shaik
//CS302
//The purpose of this code is to implement the functions in the dll.h file. Functions implemented include constructors,
//a copy constructor, a single getter function (for node data), insert functions, a display function, and an output operator.


//Node constructor
template<class T>
Node<T>::Node(T data): data(data) {};

//Getter function for node data (used for DLL display)
template<class T>
T Node<T>::getData() const {
    return data;
}

//DLL constructor
template<class T>
DLL<T>::DLL() {}

//DLL copy constructor
template<class T>
DLL<T>::DLL(const DLL &copy) {

    Node<T> * tmp = copy.head;

    copyconstructor(tmp);

}

//DLL copy constructor recursive work
template<class T>
DLL<T> DLL<T>::copyconstructor(Node<T> *tmp) {

    if (!tmp) {
        return copy;
    }

    this->insert(tmp);
    tmp = tmp->next;

}

//Insert function with Node input, logic uses tail pointer
template<class T>
void DLL<T>::insert(Node<T> *n) {
    //If head doesn't exist, fill head
    if (head == nullptr) {
        head = n;
        tail = head;
        return;
    }
    //Otherwise add after tail
    n->last = tail;
    tail->next = n;
    tail = tail->next;
}

//Insert function with data input (simply creates node, inserts data into new node, and sends to above insert function)
template<class T>
void DLL<T>::insert(const T &data) {
    auto *n = new Node<T>(data);
    insert(n);

}

//Display function
template<class T>
void DLL<T>::display() {

    //Iterative solution:
    /*
    Node<T> *tmp = head;
    while (tmp) {
        cout << tmp->getData() << ", ";
        tmp = tmp->next;
    }
    cout << endl;
     */

    displayR(head);

}

//Recursive work for display function
template<class T>
void DLL<T>::displayR(Node<T> *tmp) {

    if (!tmp) {
        cout << endl;
        return;
    }

    cout << tmp->getData() << ", ";
    tmp = tmp->next;

    displayR(tmp->next);

}

//Output operator for DLL class.
template<class T>
ostream& operator<<(ostream &os, const DLL<T>& n) {


    Node<T> *tmp = n.head;
    while (tmp) {
        os << tmp->getData() << " ";
        tmp = tmp->next;
    }
    os << endl;

    return os;
}


