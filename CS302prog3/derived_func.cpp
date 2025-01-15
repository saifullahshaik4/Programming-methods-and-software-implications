//Saifullah Shaik

/* this file handles all of the functions in the dynamic bind heirarchy, the pet abstract base class, and its derived classes. These are functions like the 
 * constructors, constructor with args to set the temp data gained in support.cpp to the new derived class object pointer, the copy constructors, and their
 * = operator overloading used in teh constructor with args, the destructors that are dynamcially bound and the displays called via downcasting from the node
 * function node_diplay
*/

#include "Pet.h"
using namespace std;



//CONSTRUCTOR
//set all data to intiliaze to null
pet::pet() : name(NULL), ID(0), weight(0), age(0)
{
}

//COPY CONSTRUCTOR
//since its derived and both base and derived have dynamic memory then it will use the intialization list to call the base copy constructor
pet::pet(const pet & source) : ID(source.ID), weight(source.weight), age(source.age)
{
  name = new char[strlen(source.name) + 1];
  strcpy(name, source.name);
}

//VIRTUAL DESTRUCTOR 
pet::~pet()
{
  delete [] name;
  name = NULL;
}

int pet::pullID()
{
  return ID;
}

//display virtual function is pure so no need to implement it

//==========================================================================
//+++++++++++++++++++++++++ Dog DERIVED CLASS ++++++++++++++++++++++++++
//==========================================================================

//CONSTRUCTOR
Dog::Dog() : item(NULL), history(false), weight_dog(0), age_dog(0) 
{
}

//COPY CONSTRUCTOR
//since its derived and both base and derived have dynamic memory then it will use the intialization list to call the base copy constructor
Dog::Dog(const Dog & source) : history(source.history), weight_dog(source.weight_dog), age_dog(source.age_dog)
{
  item = new char[strlen(source.item) + 1];
  strcpy(item, source.item);
}


//CONSTRUCTOR WITH ARGS
//used for setting temp varibles for the newly created derived class object to set all the data to the new object
Dog::Dog(char * tempName, char * care, bool history, int wght, int ag, int number)
{
  name = new char[strlen(tempName)+1];
  strcpy(name, tempName);

  item = new char[strlen(care)+1];	//set dynamic mem
  strcpy(item, care);

  history = history;
  weight = wght;
  age = ag;

  if(weight > 150)
    weight_dog = 150;
  else
    weight_dog = weight;		// OPERATOR = OVERLOADED AND USED ON THE DERIVED CLASS THAT HAS DYNAMIC MEM 

  if(age > 50)
    age_dog = 50;
  else
    age_dog = age;

  ID = number;				
}

//OPERATOR = OVERLOAD
// = operator overload on derived class used in there copy constructors to assign the calorie value to what the calorie limit is
Dog& Dog::operator = (const Dog& C)
{
  this->weight_dog = C.weight;
  return *this;
}

//DECONSTRUCTOR
// delete the dynamic mem in the class dynamically bound
Dog::~Dog()
{
  delete [] item;
  item = NULL;
}

//DISPLAY FOR DERIVED DYNAMIC BOUND FUNCTION
//This is called from the node class via downcasting as it determines the type we are and calls the appropriate derived class display to display the 
//speacilized data stored on this derived object
int Dog::display() const
{
    cout << "\to Number: " << ID << endl;	
    cout << "\to Name: " << name << endl;	
    cout << "\to Pet: " << item << endl;
    cout << "\to weight for pet: " << weight_dog << endl;
    cout << "\to weight limit: " << weight << endl;
    cout << "\to age of dog: " << age_dog << endl;
    cout << "\to age limit: " << age << endl;
    cout << "\to A good history: ";
    if(history == true)
      cout << " YES " << endl;
    else 
      cout << " NO " << endl;
  cout << "\n";
  return 1;
}



//CONSTRUCTOR
Cat::Cat() : item(NULL), outdoor(false), weight_cat(0), age_cat(0)
{
}

//COPY CONSTRUCTOR
//since its derived and both base and derived have dynamic memory then it will use the intialization list to call the base copy constructor
Cat::Cat(const Cat & source) : outdoor(source.outdoor), weight_cat(source.weight_cat), age_cat(source.age_cat)
{
  item = new char[strlen(source.item) + 1];
  strcpy(item, source.item);
}

//CONSTRUCTOR WITH ARGS
//used for setting temp varibles for the newly created derived class object to set all the data to the new object
Cat::Cat(char * tempName, char * care, bool outdoor, int wght, int ag, int number)
{	
  name = new char[strlen(tempName)+1];
  strcpy(name, tempName);

  item = new char[strlen(care)+1];	//set dynamic mem
  strcpy(item, care);

  outdoor = outdoor;
  weight = wght;
  age = ag;

  if(weight > 60)
    weight_cat = 60;
  else
    weight_cat = weight;	// OPERATOR = OVERLOADED AND USED ON THE DERIVED CLASS THAT HAS DYNAMIC MEM  

  if(age > 15)
    age_cat = 15;
  else
    age_cat = age;

  ID = number; 				
}

//OPERATOR = OVERLOAD
// = operator overload on derived class
Cat& Cat::operator = (const Cat& B)
{
  this->weight_cat = B.weight;
  return *this;
}


//DESTRUCTOR
// delete the dynamic mem in the class dynamically bound
Cat::~Cat()
{
  delete [] item;
  item = NULL;
}

//DISPLAY FOR DERIVED DYNAMIC BOUND FUNCTION
//This is called from the node class via downcasting as it determines the type we are and calls the appropriate derived class display to display the 
//speacilized data stored on this derived object
int Cat::display() const
{	
    cout << "\to Number: " << ID << endl;	
    cout << "\to Name: " << name << endl;	
    cout << "\to Cat: " << item << endl;
    cout << "\to weight of cat: " << weight_cat << endl;
    cout << "\to weight limit: " << weight << endl;
    cout << "\to age of cat: " << age_cat << endl;
    cout << "\to age limit: " << age << endl;
    cout << "\to outdoor: ";
    if(outdoor == true)
      cout << " YES " << endl;
    else 
      cout << " NO " << endl;
  cout << "\n";
  return 1;
}


//CONSTRUCTOR
Rabbit::Rabbit() : item(NULL), long_ears(false), weight_rabbit(0), age_rabbit(0)
{
}

//COPY CONSTRUCTOR
//since its derived and both base and derived have dynamic memory then it will use the intialization list to call the base copy constructor
Rabbit::Rabbit(const Rabbit & source) : long_ears(source.long_ears), weight_rabbit(source.weight_rabbit), age_rabbit(source.age_rabbit)
{
  item = new char[strlen(source.item) + 1];
  strcpy(item, source.item);
}

//CONSTRUCTOR WITH ARGS
//used for setting temp varibles for the newly created derived class object to set all the data to the new object
Rabbit::Rabbit(char * tempName, char * care, bool long_ears, int wght, int ag, int number)
{
  name = new char[strlen(tempName)+1];
  strcpy(name, tempName);

  item = new char[strlen(care)+1];	//set dynamic mem
  strcpy(item, care);

  long_ears = long_ears;
  age = ag;
  weight = wght;

  if(weight > 60)
    weight_rabbit = 60;
  else
    weight_rabbit = weight;	// OPERATOR = OVERLOADED AND USED ON THE DERIVED CLASS THAT HAS DYNAMIC MEM 

  if(age > 15)
    age_rabbit = 15;
  else
    age_rabbit = age;

  ID = number;			
}

//OPERATOR = OVERLOAD
// = operator overload on derived class 
Rabbit& Rabbit::operator = (const Rabbit& D)
{
  this->weight_rabbit = D.weight;	
  return *this;
}

//DESTRUCTOR
// delete the dynamic mem in the class dynamically bound
Rabbit::~Rabbit()
{
  delete [] item;
  item = NULL;
}

//DISPLAY FOR DERIVED DYNAMIC BOUND FUNCTION
//This is called from the node class via downcasting as it determines the type we are and calls the appropriate derived class display to display the 
//speacilized data stored on this derived object
int Rabbit::display() const
{
    cout << "\n\to Number: " << ID << endl;	
    cout << "\to Name: " << name << endl;	
    cout << "\to Rabbit: " << item << endl;
    cout << "\to weight of Rabbit: " << weight_rabbit << endl;
    cout << "\to weight limit: " << weight << endl;
    cout << "\to age of rabbit: " << age_rabbit << endl;
    cout << "\to age limit: " << age << endl;
    cout << "\to long Ears: ";
    if(long_ears == true)
      cout << " YES " << endl;
    else 
      cout << " NO " << endl;
  cout << "\n";
  return 1;
}



