/* Saifullah SHaik:
   
   This file contains the member functions for the
   data structure classes (A_Node, C_Node, Array, and CLL).
   These data structures are meant to hold the different 
   Event types. The Actors class is represented in a vector,
   the Artists class is an array of LLL's, and the Animals
   class is a CLL.

*/

#include "Nodes.h"

// ********************* A_NODE FUNCTIONS *******************

//constructor
A_Node::A_Node(){
  next = nullptr;
}

//constructor to copy over the artist data
A_Node::A_Node(const Artists & source) : Artists(source){
  next = nullptr;
}

//move through the array of LL
A_Node *& A_Node::go_next(){
  return next;
}

//set the next node
void A_Node::set_next(A_Node* node){
  next = node;
}

// ********************* ARRAY FUNCTIONS *******************

//constructor with args
Array::Array(int s){
  size = s;
  head = new A_Node*[size];
  for(int i = 0; i < size; i++){
    head[i] = nullptr;
  }
}

//copy constructor
Array::Array(const Array & source){
  size = source.size;
  head = new A_Node*[size];

  for(int i = 0; i < size; i++){
    head[i] = new A_Node(*(source.head[i]));
    A_Node * cur = head[i];
    A_Node * ptr = source.head[i];
    while(ptr){
      cur = new A_Node(*ptr);
      cur = cur->go_next();
      ptr = ptr->go_next();
    }
  }
}

//destructor
Array::~Array(){
  for(int i = 0; i < size; i++){
    A_Node * cur = head[i];
    while(cur->go_next()){
      A_Node * temp = cur->go_next();
      delete cur;
      cur = temp;
    }
    delete head[i];
    head[i] = nullptr;
  }
  delete [] head;
  head = nullptr;
}

//insert node wrapper
void Array::insert(Artists & to_add){
  A_Node * a = new A_Node(to_add);
  int index = to_add.hash(size);
  insert(head[index], a);
}

//recursive insert
void Array::insert(A_Node *& current, A_Node *& to_add){
  if(!current){
    current = to_add;
    to_add->set_next(nullptr);
    return;
  }
  if(current->go_next()){
    insert(current->go_next(), to_add);
  } else {
    current->set_next(to_add);
    to_add->set_next(nullptr);
  }
}

//wrapper to remove a node
void Array::remove(A_Node *& to_remove){
  if(is_empty() == true) return;
  int index = to_remove->hash(size);
  if(!head[index]) return;
  remove(head[index], to_remove);
}

//recursive removal
void Array::remove(A_Node *& current, A_Node *& to_remove){
  if(current == to_remove){
    A_Node * temp = current->go_next();
    delete to_remove;
    current = temp;
  }
  else {
    remove(current->go_next(), to_remove);
  }
}


//wrapper to display the array of LLL
void Array::display(){
  if(is_empty() == true) return;
  display(0);
}

//recursive display
void Array::display(int index){
  if(head[index]){
    head[index]->Artists::display();
    A_Node * temp = head[index]->go_next();
    while(temp){
      temp->Artists::display();
      temp = temp->go_next();
    }
  }
  display(index + 1);
}


//wrapper to remove all nodes
void Array::remove_all(){
  if(is_empty() == true) return;
  A_Node * current = nullptr;
  for(int i = 0; i < size; i++){
    current = head[i];
    remove_all(current);
  }
}

//recursive remove all
void Array::remove_all(A_Node * current){
  if(!current) return;
  A_Node * hold = current->go_next();
  delete current;
  current = hold;
  remove_all(current);
}

//sees if the name passed in exists in the DS
A_Node* Array::find_artist(char* name){
  A_Node * temp = nullptr;
  std::string str(name);
  for(int i = 0; i < size; i++){
    temp = head[i];
    if(temp->compare(str)){
      return temp;
    }
    while(temp->go_next()){
      temp = temp->go_next();
      if(temp->compare(str)){
  return temp;
      }
    }
  }
  return nullptr;
}

//checks if array is empty
bool Array::is_empty(){
  for(int i = 0; i < size; i++){
    if(head[i]) return false;
  }
  return true;
}

// ******************* C_NODE FUNCTIONS **************

//constructor
C_Node::C_Node(){
  next = nullptr;
}

//constructor to copy animals details
C_Node::C_Node(const Animals & source) : Animals(source){
  next = nullptr;
}

//move through CLL
C_Node *& C_Node::go_next(){
  return next;
}

void C_Node::set_next(C_Node *& to_add){
  next = to_add;
}

// ********************** CLL FUNCTIONS *********************

//constructor
CLL::CLL(){
  rear = NULL;
}

//copy constructor
CLL::CLL(const CLL & source){
  cp(rear, source.rear, source.rear);
}

//recursive copy for copy constructor
void CLL::cp(C_Node *& cur, C_Node * source, C_Node * s_rear){
  if(source->go_next() == s_rear){ //last node
    cur = new C_Node(*source);
    cur->set_next(rear);
  } else { //all other nodes
    cur = new C_Node(*source);
    cp(cur->go_next(), source->go_next(), s_rear);
  }
}

//destructor
CLL::~CLL(){
  C_Node* cur = rear;
  while(cur->go_next() != rear){
    C_Node* temp = cur->go_next();
    delete cur;
    cur = temp;
  }
  delete rear;
  rear = nullptr;
}

//insert a node
void CLL::insert(Animals & to_add){
  C_Node * a = new C_Node(to_add);
  if(!rear){
    rear = a;
    a->set_next(rear);
  } else {
    C_Node * temp = rear->go_next()->go_next();
    rear->set_next(a);
    a->set_next(temp);
  }
}

//wrapper to remove a node
void CLL::remove(char* to_remove){
  if(!rear) return;
  std::string name = to_remove;
  remove(rear, name);
}

//remove the node whose name matches the one passed in
void CLL::remove(C_Node *& cur, std::string name){
  if(cur->go_next() != rear){
    if(cur->go_next()->compare(name)){
      C_Node * temp = cur->go_next()->go_next();
      delete cur->go_next();
      cur->set_next(temp);
    } else {
      remove(cur->go_next(), name);
    }
  } else { //only node left
    if(cur->compare(name)){
      delete cur;
      rear = nullptr;
    }
  }
}

//wrapper to display all nodes
void CLL::display(){
  if(!rear) return;
  display(rear);
}

//recursive display
void CLL::display(C_Node* cur){
  if(cur->go_next() != rear){
    cur->Animals::display();
    display(cur->go_next());
  }
  cur->Animals::display();
}

//wrapper to remove all nodes
void CLL::remove_all(){
  if(!rear) return;
  remove_all(rear);
}

//remove all nodes
void CLL::remove_all(C_Node * cur){
  if(cur->go_next() != rear){
    C_Node * temp = cur->go_next();
    delete cur;
    cur = temp;
  }
}

//checks if CLL is empty
bool CLL::is_empty(){
  if(rear == nullptr) return true;
  return false;
}


