/*Saifullah SHaik
  
  This file contains 4 classes:
  Array, A_Node, C_Node, and Circular_LL.
  A_node and Array work together to make an array of LLL's
  and C_Node and Circular_LL make a circular LL.
 */
#include "Comic.h"

class A_Node : public Artists {
public:
  A_Node(); //constructor
  A_Node(const Artists & source); //copy constructor
  A_Node *& go_next(); //move through array of LL 
  void display_data(char* name); //display data for a particular node
  void set_next(A_Node * node); //set next

protected:
  A_Node* next;
};

class Array {
public:
  Array(int s = 5); //set size of array
  Array(const Array & source); //copy constructor
  ~Array(); //destructor
  void insert(Artists & to_add); //add a node
  void remove(A_Node *& to_remove); //remove a node
  void display(); //display the whole DS
  void remove_all(); //remove all nodes
  A_Node * find_artist(char* name);
  bool is_empty();
private:
  void insert(A_Node *& current, A_Node *& to_add);
  void remove(A_Node *& current, A_Node *& to_remove);
  void display(int index);
  void remove_all(A_Node * current);
  A_Node ** head;
  int size;
};

class C_Node : public Animals {
public:
  C_Node(); //constructor
  C_Node(const Animals & source);
  C_Node *& go_next(); //move through CLL
  void set_next(C_Node *& to_add);
protected:
  C_Node* next;
};

class CLL {
public:
  CLL(); //constructor
  CLL(const CLL & source); //copy constructor
  ~CLL(); //destructor
  void insert(Animals & to_add); //insert a node
  void remove(char* to_remove); //remove a node
  void display(); //wrapper to display all nodes
  void remove_all(); //remove all nodes;
  bool is_empty();
private:
  void remove(C_Node *& cur, std::string to_remove);
  void display(C_Node * cur); //recursive display
  void remove_all(C_Node * cur);
  void cp(C_Node *& cur, C_Node * source, C_Node * s_rear);
  C_Node * rear;
};


