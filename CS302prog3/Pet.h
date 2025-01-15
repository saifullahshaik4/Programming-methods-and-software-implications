//Saifullah Shaik


/* The heirarchy of this program is as follow 6 classes. The pet class is an abstract base class that acts as a "glue" and similar data holder for the 3 
 *  The manager class handles the 2-3-4 tree and "has a" node class that contains a 

 */
#include <iostream>
using namespace std;
#include <cstring>
#include <cctype>
#include <typeinfo>		//allow for the dynamic_cast keyword
#include <stdlib.h>		//for the rand() function
#include <cstring>

class manager;

class pet;

//+++ NODE CLASS 2-3-4 

class node						//node container for the 2-3-4 tree in the manager class
{
  public:
    node();					//node constructor for when we need to split and create a new root, intializes all data and children to NULL

    node *& getchild(int index);		//child getter for traversal in remove_all and display_all	
    int node_delete();			//delete the contents of the whatever node is calling it
    int node_display() const;		//for the displays in the derived classes (dynamically bound)

  protected:

    pet * data[3];			//base class pointer, (will be used to send derived class pointers to store)
    node * child[4];		//children pointers for the tree


    int first_item(pet * new_item);	//intial base case for adding the very first data item to the tree
    node* split_tree(pet *& median);  	//split the full node, hold onto the middle data point in median
    node* what_path(int number); 		//determine what path we need to traverse to based on the data we have
    int add_data(node *& below, pet *& median, int IDnumber, bool datapoints, bool pointers);	//insert the newest data into a determined node 
    int add_pointers(node *& below, int belowID, bool pointers); 		//re-organize the child ptrs when new data is added or when a node is split
    int is_leaf();				//determine if the node we are at is a leaf (all children NULL) 
    int is_full(); 				//determine if the node we are on is full and ready to split (all data points are not NULL) 

    friend class manager;		//now the manager class can access the node class protected functions without denigned accesss error
};


//+++++++++++++++++++ PET BASE CLASS +++++++++++++++++


class pet						//abstract base class, glue of the pet type classes	
{
  public:
    pet();					//default constructor
    pet(const pet & source);		//copy constrcutor 
    virtual ~pet() = 0;			//virtual destructor (required for dynamic binding, and for virtal pure abstract class)

    virtual int display() const = 0;	//virtual pure implemented in all the derived classes
    int pullID();				//small getter for the manager class to get the ID value

  protected:					//similar data between all the derived classes
    char * name;				//name of the pet	
    int ID;					//int value we randomly assign to each pet, this is also the value base on to insert into the tree	
    int weight;
    int age;
};


// DERIVED PET TYPE CLASSES 

// DOG CLASS 
class Dog : public pet				//pet type stored in the 2-3-4 tree nodes
{
  public:
    Dog ();							//default constructor
    Dog(char * tempName, char * care, bool history, int wght, int ag , int number);	//constructor with args
    Dog& operator = (const Dog& item);		//OPERATOR OVERLOADED IN DERIVED = used in the constructor with args
    Dog(const Dog & source);			//copy constructor
    ~Dog();							//destructor dynamically bound	

    int display() const;						//display this nodes data dynamically bound func
    friend std::ostream& operator << (std::ostream& output, const Dog& m)	//ostream operator overload
    {
      output << "\n\to Number: " << m.ID << "\n\to Name: " << m.name << "\n\to pet : " << m.item << "\n\to Weight: ";
      output << m.weight_dog << "\n\to Weight Limit: " << m.weight << "\n\to age: " << m.age_dog;
      output << "\n\to age Limit: " << m.age << "\n\to History : ";
      if(m.history == true)
        output << " YES ";
      else 
        output << " NO ";
      output << "\n";
      return output;
    }

  protected:
    char * item;							//pet
    bool history;						//determines what string literal is assigned to item
    int weight_dog;
    int age_dog;
};

// CAT CLASS 
class Cat : public pet				//pet type stored in the 2-3-4 tree nodes
{
  public:
    Cat();					//default constructor
    Cat(char * tempName, char * care, bool outdoor, int weight, int age, int number);	//constructor with args
    Cat& operator = (const Cat& item);	//OPERATOR OVERLOADED IN DERIVED = used in constructor with args
    Cat(const Cat & source);		//copy constuctor
    ~Cat();					//deconstructor dynamically bound	

    int display() const;				//display this nodes data dynamically bound
    friend std::ostream& operator << (std::ostream& output, const Cat& b)	//ostream operator overload
    {
      output << "\n\to Number: " << b.ID << "\n\to Name: " << b.name << "\n\to cat: " << b.item << "\n\to weight : ";
      output << b.weight_cat << "\n\to weight Limit: " << b.weight << "\n\to age: " << b.age_cat;
      output << "\n\to age Limit: " << b.age << "\n\to outdoor/indoor: ";
      if(b.outdoor == true)
        output << " YES ";
      else 
        output << " NO ";
      output << "\n";
      return output;
    }

  protected:
    char * item;					
    bool outdoor;				//determines what string literal is assigned to item
    int weight_cat;
    int age_cat;
};

// Rabbit CLASS 
class Rabbit : public pet				
{
  public:						
    Rabbit();					//default constructor
    Rabbit(char * tempName, char * care, bool ears, int wght, int ag, int number);	//constructor with args
    Rabbit& operator = (const Rabbit& item);	//OPERATOR OVERLOADED IN DERIVED = used in constructor with args
    Rabbit(const Rabbit & source);		//copy constructor
    ~Rabbit();					//deconstructor dynamically bound


    int display() const;				

    friend std::ostream& operator << (std::ostream& output, const Rabbit& d)	//ostream overload 
    {
      output << "\n\to Number: " << d.ID << "\n\to Name: " << d.name << "\n\to Rabbit: " << d.item << "\n\to Weight: ";
      output << d.weight_rabbit << "\n\to weight Limit: " << d.weight << "\n\to Age: " << d.age_rabbit;
      output << "\n\to age Limit: " << d.age << "\n\to Long ears: ";
      if(d.long_ears == true)
        output << " YES ";
      else 
        output << " NO ";
      output << "\n";
      return output;
    }

  protected:
    char * item;				
    bool long_ears;			//determines what string literal is assigned to item	
    int weight_rabbit;
    int age_rabbit;
};


 //MANAGER 2-3-4 CLASS 

class manager							//manages the 2-3-4 tree that stores the derived objects in the base class node pointer
{								//	handles tree manipulation
  public:
    manager();					//default constructor
    ~manager();					//deconstructor

    int insert(Dog * dog_object, int number);			//inserts based on the derived class pointer we are being sent
    int insert(Cat * cat_object, int number);			//this is where my upcasting occurs
    int insert(Rabbit * rabbit_object, int number);			//these are esstianlly wrappers for the inserter function

    int remove_all();				//remove entire list	
    int display();					

    //operator overloading
    manager operator + (const manager&) const;	// +
    manager& operator += (const manager&);		// += 
    manager& operator = (const manager&);		// = 
    bool operator <(const manager& M);		// <
    bool operator >(const manager& M);		// >
    bool operator <=(const manager& M);		// <= 
    bool operator >=(const manager& M);		// >=
    friend std::ostream& operator << (std::ostream& output, const manager& M)	// <<
    {
      output << M.group;
      return output;
    }
    friend std::istream& operator >> (std::istream& input, manager& M)		// >>
    {
      input >> M.group;
      return input;
    }
    bool friend operator == (const manager& M, const manager& M2)			// ==
    {
      if(M.group == M2.group)
        return true;
      return false;
    }
    bool friend operator != (const manager& M, const manager& M2)			// != 
    {
      if(M.group != M2.group)
        return true;
      return false;
    }

  protected:
    node * root;					//root node pointer for the tree

    int group;					

    int inserter(pet * new_pet, int number);	// inserter check intial base case, send to the split determine and the place 
    int split_determine(node *& root, node *& parent, pet *& new_pet, pet *& mid, int number);//splits up the tree if where we need to insert is full 
    int place(node *& root, pet *& new_pet, int number); 	//insert the newest data item into the tree once split 	

    int remove_all(node *& root);				//destory the entire tree
    int display(node * root, int & num) const;		//recursivly move through the list to call the derived class displays via the node_display
};


// MAIN SUPPORT FUNCTIONS 

void user_menu(manager & object);					  //show user program options
bool determine(manager & object, int * IDlist, int choice);		  //take that choice and call the appropriate functions

void add_pet(manager & object, int * IDlist);					//display pet options
void gather_data(manager & object, int * IDlist, int choice, char option);	//get similar data all the derived classes share
void gather_special_data(manager & object, char option, int * IDlist, int wght, int ag, int choice);	//get final data and send to insert function



