#ifndef DLL_H
#define DLL_H
#include <iostream>
using namespace std;

//Saifullah Shaik

//CS302
//The purpose of this code is to set up the DLL data structure that manages data for the guests manager program.
//The classes used include the Node class and the DLL class. Both of these classes use templates so that they can take
//any data type. Key functions include insert, display, and the output operator



//Node class using a template
template<class T>
class Node {
public:

    Node(T data);
    ~Node();
    T getData() const;
    Node<T> *next;
    Node<T> *last;
private:
    T data;
};

//DLL class using a template
template<class T>
class DLL {
public:

    DLL();//constructor
    DLL(const DLL &copy); //copy constructor
    DLL<T> copyconstructor(Node<T> *head); //Recursive work for copy constructor



    //Operator Overloading for input
    template<class U>
    friend ostream &operator<<(ostream&, const DLL<U>&);

    void insert(Node<T> *node); //Insert function using Node objefct
    void insert(const T &data); //Inser function using data
    void display(); //Display function
    void displayR(Node<T> *head); //Recursive work for display function

private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
};

#include "dll.tpp"

#endif //DLL_H


