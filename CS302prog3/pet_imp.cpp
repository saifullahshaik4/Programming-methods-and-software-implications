//Saifulah Shaik

#include "Pet.h"
using namespace std;


//  NODE CLASSS 

//CONSTRUCTOR
//when a new root or new node is create via a split we intialize a new node with all data pet pointers and child pointers set to null
node::node()
{
  for(int i = 0; i < 3; ++i)
  {
    data[i] = NULL;
  }

  for(int j = 0; j < 4; ++j)
  {
    child[j] = NULL;
  }
}


//CHILD POINTER GETTER
//this function is my getter used to pull the child pointers from the node when we are traversing in the display_all or remove_all function
node *& node::getchild(int index)
{	
  if(index == 0)
    return child[0];
  if(index == 1)
    return child[1];
  if(index == 2)
    return child[2];
  if(index == 3)
    return child[3];

static node* null_node = nullptr;
  return null_node; 
}


//INTIAL BASE CASE FUNCTION
//we are a currently empty tree and now we input the first data item
int node::first_item(pet * new_item)
{
  data[0] = new_item;            //add our data to middle data location in the node
  return 1;
}



node* node::split_tree(pet *& median)
{
  median = data[1];       //data that will be added to the parent
  data[1] = NULL;		//set the root data[1] to now be null since we saved the data

  node * largest = new node;	//create a new node to hold the right most data and the children attached to it in the root node
  largest->data[0] = data[2];
  data[2] = NULL;

  largest->child[0] = child[2];	//save the children attached to the largest node data
  largest->child[1] = child[3];

  child[2] = NULL;		//reset the root child pointers to NULL since we saved their ptrs in largest
  child[3] = NULL;

  return largest;
}


//INSERT TRAVERSER CHILD DETERMINER

node* node::what_path(int number)
{
  if(data[0] != 0 && number < data[0]->pullID())                  //check for left most data point
    return child[0];					//if numberue is less than it send to child 0 left most

  else if(number >= data[0]->pullID() && data[1] == 0)		//if the number is greater or equal to the left most data and we have no mid data
    return child[1];					//return child 1

  else if( (data[0] != 0 && data[1] != 0) && (number >= data[0]->pullID() && number < data[1]->pullID()) ) //if we have both the first and second data points
    return child[1];					//if less than first and greater than second send to child 1

  else if( (data[1] != 0 && data[2] == 0) && (number >= data[1]->pullID()) )          //check if we have both second and third data points
    return child[2];					//if less than second and greater than third then send to child 2

  else if( (data[1] != 0 && data[2] != 0) && (number >= data[1]->pullID() && number < data[2]->pullID()) )
    return child[2];					//if we have the first and second data points and our new data is more or equal to the 
                  //first but less than the second return child 2
  else if(data[2] != 0 && number >= data[2]->pullID())            //check if we have the right most data point
    return child[3];					//if greater than right most send to child 3

  return NULL;	//no case hit so return null
}


int node::is_leaf()
{
  if(child[0] == NULL && child[1] == NULL && child[2] == NULL && child[3] == NULL)        //are we a leaf
    return 1;
  return 0;
}


int node::is_full()
{
  if(data[0] != NULL && data[1] != NULL && data[2] != NULL)		//are we a full node, every index has a pet pointer
    return 1;
  return 0;
}



int node::add_data(node *& below, pet *& median, int IDnumber, bool datapoints, bool pointers)
{
  //data adjustment and placement

  if(datapoints == true)		//if we call the function when we wish to adjust the data in the node
  {
    if(data[0] == NULL && data[1] == NULL && data[2] == NULL)        //new node case, all data is 0
    {
      data[0] = median;					 //median can be the mid data point of a split node or our newest data

    }else if(data[0] != NULL && data[1] == NULL)			 //determine if we only have the first data point
    {
      if(IDnumber < data[0]->pullID())                         //if our data to add in is less then set as data[0]
      {
        data[1] = data[0];				 //move over the old first data point and set new data as the first 
        data[0] = median;
      }
      else
        data[1] = median;				 //if not less then set as the second data point since its bigger than first

    }else if(IDnumber < data[0]->pullID())				 //if our data to add is less than the first data point and we also have the 
    {								 //second data point not null then move all the data over by one and input the 
      data[2] = data[1];					 //newest data as the first data point
      data[1] = data[0];
      data[0] = median;

    }else if(IDnumber < data[1]->pullID())				 //our data to add is less than the second data point
    {								 //only move the second data point over to the right by one index and make new  
      data[2] = data[1];					 //data the second data point
      data[1] = median;

    }else								 //our data to add is larger than the second data point so add it to data point 3
      data[2] = median;                          //set val to right most
  }

  return add_pointers(below, below->data[0]->pullID(), pointers);
}


int node::add_pointers(node *& below, int belowID, bool pointers)
{
  // ++++++++++++++++pointer adjustment and placement ++++++++++++++++++++++++ //

  if(pointers == true)
  {
    if(belowID < data[0]->pullID())			//the below node ptr can be eiter the largest node that we created when we spilt the node or the  
    {						//old root that go spilt which holds the smallest data of that node
      if(child[0] == NULL)			//using belowID which is the ID number of one of those nodes we compare to the current nodes
        child[0] = below;		//data to determine where the child ptrs should go to attach below "largest or root"
      else					//if the very first child is null and our below ID is less than the first data point then
      {					//set as the first data point moving the old child ptrs to the right if needed
        child[3] = child[2];
        child[2] = child[1];
        child[1] = child[0];
        child[0] = below;
      }
    }
    else if(belowID >= data[0]->pullID() && data[1] == NULL)      //add largest pointer to the inner left
    {							      //if the below ID is greater than the first data point and the second data is null
      if(child[1] == NULL)				      //then add to the first child
        child[1] = below;
      else
      {
        child[3] = child[2];
        child[2] = child[1];
        child[1] = below;
      }
    }
    else if(belowID >= data[0]->pullID() && data[1] != NULL && belowID < data[1]->pullID()) //add largest pointer to the inner left
    {
      if(child[1] == NULL)						//we have both the first and second data points and our
        child[1] = below;					//below ID is between them then make the first data point
      else
      {
        child[3] = child[2];
        child[2] = child[1];
        child[1] = below;
      }
    }
    else if(belowID >= data[1]->pullID() && data[2] == NULL)              //add largest pointer to inner right
    {
      if(child[2] == NULL)						//we are greater than the second data point, and the thrid data point
        child[2] = below;					//doesnt exist so we make it the 3 child point
      else
      {
        child[3] = child[2];
        child[2] = below;
      }
    }
    else if(belowID >= data[1]->pullID() && data[2] != NULL && belowID < data[2]->pullID())  //add largest pointer to inner right
    {
      if(child[2] == NULL)						//if both the second and third data is exists and our 
        child[2] = below;					//below data is inbeteen them then make it the third child
      else
      {
        child[3] = child[2];
        child[2] = below;
      }
    }
    else    //below->data[0] >= data[2]                     //add largest pointer to righter most since we are larger than the thrid data 
      child[3] = below;
  }

  return 1;
}

int node::node_delete()
{	
  for(int i = 0; i < 3; ++i)
  {
    delete data[i];
    data[i] = NULL;
  }

return 1;
}


int node::node_display() const
{	
  for(int i = 0; i < 3; ++ i)
  {	
    Dog * mptr = dynamic_cast<Dog*>(data[i]);		//downcast
    if(mptr)						//determine if we are that type RTTI
      mptr->display();				//call the the correct derived class display function

    Cat * bptr = dynamic_cast<Cat*>(data[i]);		//same for all
    if(bptr)
      bptr->display();

    Rabbit * cptr = dynamic_cast<Rabbit*>(data[i]);
    if(cptr)
      cptr->display();
  }

  for(int j = 0; j < 4; ++j)				//print what children the node has and what they attach to so its easy to understand the tree
  {
    if(child[j] == NULL)
      cout << "Child[" << j << "] is X" << endl;
    else
      cout << "Child[" << j << "] is connected to " << child[j]->data[0]->pullID() << endl;
  }

  return 0;
}


//CONSTRUCTOR
//default constructor set head and tail to NULL
manager::manager() : root(NULL)
{
}

//DECONSTRUCTOR
//deconstructor for the list, call the recursive deconstruct function to remove all nodes in the list
manager::~manager()
{
  if(!root)
    cout << endl;	
  else
    int hold = remove_all(root);
}


int manager::remove_all()
{
  if(!root) return 0;

  else
    int hold = remove_all(root);

  return 1;
}

//REMOVE ALL RECURSIVE
//move to each leaf and remove the node by using the node delete function in the node class
int manager::remove_all(node *& root)
{
  if(!root) return 0;

  int found = remove_all(root->getchild(0));	//post order traverse
  found = remove_all(root->getchild(1));
  found = remove_all(root->getchild(2));
  found = remove_all(root->getchild(3));	

  if(root->is_leaf())				//check if we are a leaf
  {
    root->node_delete();			//call the node delete to remove the leaf data
    delete root;				//remove the node itself
    root = NULL;
  }

  return found;
}


int manager::insert(Dog * dog_object, int number)	
{	
  return inserter(dog_object, number);
}

int manager::insert(Cat * cat_object, int number)	//same as above	
{
  return inserter(cat_object, number);
}

int manager::insert(Rabbit * rabbit_object, int number)	//same as above	
{
  return inserter(rabbit_object, number);
}


int manager::inserter(pet * new_item, int number)
{
  if(!root)                                               //check intial base case to see if we have an emptry tree
  {
    root = new node;				//if we are then create root and send to first_item function to assign the first data
    root->first_item(new_item);	
    return 1;                                       //return 
  }

  pet * median = NULL;					//create median to store the mid data when we spilt a full node
  node * parent = NULL;					//create the parent holder node to hold onto the parent node when we move through the tree
  int result = split_determine(root, parent, new_item, median, number);	//of whatever node we are on, now send into spilt determine to check
                //where we are adding the new data and if we need to spilt the node if its full and
  place(root, new_item, number);				//and adjust the tree, and once adjusted then fully add in our data to the tree

  return 1;
}

int manager::split_determine(node *& root, node *& parent, pet *& new_item, pet *& median, int number)
{
  if(!root)
    return 0;

  if(root->is_full())					//determine if we are a full node
  {
    node * largest = root->split_tree(median);      //data contains in spilted is greater than median,  

    if(root == this->root)				//if we are still on the original root of the tree
    {
      node * temp = new node;			//create a new node to be the newest root since root needs to spilt into 3 nodes
      temp->add_data(largest, median, median->pullID(),true, true);    //adjust the data and children, add the largest node to the new root
      temp->add_data(root, median, median->pullID(), false, true);	 //adjust the children to add the old root to the new root as a child 

      this->root = temp;			//set the new root to be the newly created node
      return 1;
    }

    if(parent != NULL)				//if our parent isnt NULL then we arent at the orginal node, we have more than one node
    {
      parent->add_data(largest, median, median->pullID(), true, true);  //do both the data placement and adjustment attach the largest node
      return 1;							  //to the parent node i.e set mid data to the parent, and attach the
    }									  //largest node, the current root is already attached to the parent node
  }

  parent = root;						//set the parent to the current node before traversing to the next node
  node * temp = root->what_path(number);                             //what child do we go to next   
  return split_determine(temp, parent, new_item, median, number);              //node function to find correct path based on value trying to add
}

int manager::place(node *& root, pet *& new_item, int number)
{
  if(!root)
    return 0;

  if(root->is_leaf())
  {
    root->add_data(root, new_item, new_item->pullID(), true, false); //node functions determine insert only data is worked on        
    return 1;
  }

  node * temp = root->what_path(number);                             //what child do we go to next   
  return place(temp, new_item, number);               
}
  

int manager::display()
{	
  if(!root)
  {
    cout << "Root is null" << endl;	
    return 0;
  }
  int num = 1;	//to number each item in teh list
  cout << "\nO Dog Tree: " << endl;
  cout << "==========================================" << endl;

  return display(root, num);	//call display recurse
}

int manager::display(node * root, int & num) const
{
  if(!root)
    return 1;

  cout << "\no Dog #" << num << "\n+++++++++++++++++++++++" << endl;	

  root->node_display();	//call node display to downcast and call derived dynamically bound diaply funciton

  cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  ++num;	

  return display(root->getchild(0), num) + display(root->getchild(1), num) + display(root->getchild(2), num) + display(root->getchild(3), num); 
}

bool manager::operator <(const manager& M)
{
  if(group < M.group)
    return true;
  return false;
}
//determine if group 1 is more than group 2 manager objects in main.cpp
bool manager::operator >(const manager& M)
{
  if(group > M.group)
    return true;
  return false;
}

//determine if group 1 is less than or equal to group 2 manager objects in main.cpp
bool manager::operator <=(const manager& M)
{
  if(group <= M.group)
    return true;
  return false;
}

//determine if group 1 is more than equal to group 2 manager objects in main.cpp
bool manager::operator >=(const manager& M)
{
  if(group >= M.group)
    return true;
  return false;
}

manager manager::operator + (const manager& M) const
{
  manager newest;
  newest.group =  this->group + M.group;

  return newest;
}

manager& manager::operator += (const manager& M)
{
  this->group += M.group;
  return *this;
}

manager& manager::operator = (const manager& M)
{
  this->group = M.group;
  return *this;
}


