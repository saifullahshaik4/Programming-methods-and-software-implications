//Saifullah Shaik

/* This program implements Dynamic binding (upcasting, downcasting). The specfic heiarchy is decribed in the Pet.h file description.
 * Using a 2-3-4 tree, we allow the user to select from 3 pet types for adoption (derived classes) and we then prompt for general data and then speacilized 
 * data based on the pet type selected. We store that data intialized to a newly created object pointer of the derived class and then send it to be inserted
 * into the pet base class pointer array in our node into the 2-3-4 tree, This program allows insert, remove all, and display options with the tree
 */

#include "Pet.h"
using namespace std;

int main()
{
  manager object, object2, object3;		//2-3-4 tree manager class object

  cout << "\n\no Welcome to the Pet Selection Program: " << endl;	
  cout << "\n======================================================================================" << endl;

  cout << "\n\to Before we begin lets make sure how many pets we are dealing with :  {Operator Overloading}" << endl;
  cout << "\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

  cout << "\n\to How many pets will be in the first group?  ";
  cin >> object2; 					// Input >> operator overloading
  cin.ignore(100, '\n');

  cout << "\n\to How many pets will be in the second group ?";
  cin >> object3; 					// Input >> operator overloading
  cin.ignore(100, '\n');

  // OPERATOR OVERLOADING FOR <, >, <=, >=, ==, !=, +, +=, = using the group int values in the manager class objects
  if(object2 < object3)		// <
    cout << "\n\to Group 1 has ( < ) less than Group 2." << endl;

  if(object2 > object3)		// >
    cout << "\n\to Group 1 has ( > ) more than Group 2." << endl;

  if(object2 <= object3)		// <=
    cout << "\n\to Group 1 has ( <= ) less than or equal to Group 2." << endl;

  if(object2 >= object3)		// >=
    cout << "\n\to Group 1 has ( >= ) more than or equal to Group 2." << endl;

  if(object2 != object3)		// !=
    cout << "\n\to Group 1 is ( != ) not equal to Group 2." << endl;

  if(object2 == object3)		// ==
    cout << "\n\to Group 1 is ( == ) equivalent to Group 2." << endl;

  object = object2 + object3;				// + operator overload
  cout << "\n\to We will now add the 2 groups together for the total number of pets. \n\t\t+ Total Group is now: ";
  cout << object;						//Output << operator overloading

  object2 += object3; 					// += operator overload
  object += object2;	
  cout << "\n\n\to It seems that there is a third group as well to add. \n\t\t+ Total Group is: ";
  cout << object;	

  object = object3;					// = operator overloaded
  cout << "\n\n\to It seems we will remove group 1 and 3. \n\t\t+ Total Group is: "; 
  cout << object;

  cout << "\n\to Now that we have the number of pets being adopted lets describe their characteristics " << endl;
  cout << "\n\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

  user_menu(object);	//begin program, sending it to user menu to learn about the program 

  return 0;
}



