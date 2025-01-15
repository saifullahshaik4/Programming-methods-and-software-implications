//Saifullah Shaik



#include "Pet.h"

using namespace std;

void user_menu(manager & object)
{
  bool valid = false;
  int choice = 0;
  int * IDlist = NULL;		//int dynamic array that will hold a rand int value where the array will be used to make sure we dont end up with duplicates
  IDlist = new int[20];		//these rand int values is what we will use to insert into the tree and where it will go
  for(int i = 0; i < 20; ++i)	//intialize all indexs to 0
    IDlist[i] = 0;

  do
  {	//user menu options to manipulate the tree
    cout << "\n\nO Pet Selection User menu: " << "\n======================================================================================" << endl;	
    cout << "\n\n\t1) Add Pet" << endl;
    cout << "\n\t2) Remove Pets" << endl;	
    cout << "\n\t3) Display Pets" << endl;	
    cout << "\n\t4) Quit " << endl;

    cout << "\n\n\to Selection: ";
    cin >> choice;
    cin.ignore(100, '\n');

    try{	//test to see if input is valid
      if(choice != 1 && choice != 2 && choice != 3 && choice != 4)
        throw choice;
    }
    catch(int)	//non valid input defaults to quit option to end the program
    {			
      cout << "\n\t+ Non valid selection given, defaulting to 4) Quit" << endl;
      choice = 4;
    }

    if(!determine(object, IDlist, choice))		//valid input gets sent into the determine function, if the user choose quit when it returns it will
      valid = true; 				//set valid to true and exit the do while loop and end the program

  }while(!valid);

  delete [] IDlist;	//once we exit this loop the user selected to Quit so lets delete the memory of the array
  IDlist = NULL;
  cout << "\n\n\to Thank you for using the pet selection menu!!!\n\n\n\n" << endl;
}

bool determine(manager & object, int * IDlist, int choice)
{
  switch(choice)		//determine case by the user choice varible
  {
    case 1:
      add_pet(object, IDlist);	//send to support function to take in user input into temp varibles to be initialized to new derived object
      break;
    case 2:
      {
        if(!object.remove_all())	//send to remove_all class fucntion
          cout << "\n\n\t+ Not all the pets have been removed from the tree" << endl;
        else
          cout << "\n\n\t+ All pets have been removed from the from the tree" << endl;
      }

      break;
    case 3:
      {
        if(!object.display())		//send to the display class member function
          cout << "\n\t\t+ pet tree is currently empty" << endl;
      }
      break;
    case 4:
      return 0;				//user chose to quit the program
  }
  return 1;
}


void add_pet(manager & object, int * IDlist)
{
  bool valid = false;
  int choice = 0;
  char option = 0;

  do		//display the types of rental units they user can rent
  {
    cout << "\n\no Pet Options: " << endl;
    cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "\n\n\t1) Dog " << endl;
    cout << "\n\t2) Cat " << endl;
    cout << "\n\t3) Rabbit " << endl;

    cout << "\n\n\to Please make your selection: ";
    cin >> choice;
    cin.ignore(100, '\n');

    if(choice == 1 || choice == 2 || choice == 3)	//input checker
      valid = true;
    else
    {
      cout << "\n\tO Please only make your selection from the given options above. ";
      cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << endl;
    }
  }while(!valid);

  cout << "\no Specific: ";	//based on the user choice of what kind of item they want we now determine the diet restrictions if any
  cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << endl;

  switch(choice)
  {
    case 1:
      {
        cout << "\n\to Do you need a Perfect breeding history? (Y - Now / N - Later) : ";
        cin >> option;								
        cin.ignore(100,'\n');
        option = toupper(option);
      }
      break;

    case 2:
      {
        cout << "\n\to Do you need outdoor cat? (Y / N) : ";		
        cin >> option;
        cin.ignore(100,'\n');
        option = toupper(option);
      }
      break;

    case 3:
      {
        cout << "\n\to Do you need a long eared rabbit? (Y / N) : ";	
        cin >> option;
        cin.ignore(100,'\n');
        option = toupper(option);
      }	
      break;	
  }
  try{
    if(option != 'Y' && option != 'N')				//try block to check input
      throw option;
  }
  catch(char){								//if a non valid is received it will default to 'N'
    cout << "\n\t\t+ Non-given option received, auto correcting to 'N'" << endl;
    option = 'N';
  }

  gather_data(object, IDlist, choice, option);		//gather data function call
}

void gather_data(manager & object, int * IDlist, int choice, char option)
{
  int wght = 0, ag = 0;
  option = 0;	

  for(int i = 1; i < 3; ++i)	//cycle through the 2 prompts
  {
    switch(i)
    {
      case 1:		//calorie prompt
        {
          cout << "\n\n\to If you have a weight please enter the limit" << endl;
          cout << "\n\t\t+ One dog typically weighs 150 pounds, one cat typically weighs 60 pounds, one rebbit 200" << endl;
          cout << "\n\t\t+ Selection: ";
          cin >> wght;
          cin.ignore(100, '\n');
        }
        break;

      case 2:		//sugar prompt
        {
          cout << "\n\n\to If you have a age limit please enter the limit" << endl;
          cout << "\n\t\t+  dog 25 , cat typically 15, rabbit 5" << endl;
          cout << "\n\t\t+ Selection: ";
          cin >> ag;
          cin.ignore(100, '\n');
        }
        break;
    }		
    try{					//if the input is less than 0 default it to 0
      if(wght < 0)
        throw wght;
      if(ag < 0)
        throw ag;
    }
    catch(int){				//if a negative value is given it will default to 0
      cout << "\n\t\t+ Non-valid limit given, auto correcting to 0" << endl;
      if(wght < 0)
        wght = 0;
      if(ag < 0)
        ag = 0;
    }
  }

  gather_special_data(object, option, IDlist, wght, ag, choice);	//send to the gather speacilized data function to get the pet data

}

void gather_special_data(manager & object, char option, int * IDlist, int wght, int ag, int choice)
{	
  char * care = NULL;
  char * tempName = NULL;	
  char buffer[20];	
  bool history = false, outdoor = false, long_ears = false, validnum = false;
  int number = 0, zeroindex = 0;

  //attach tempname to be added to the derived object to be added
  cout <<"\n\n\to Now that we have your data PLEAsE ENTER IN YOUR NAME to be placed with your pet. \n\t\t+ Enter Name: ";
  cin.get(buffer, 20, '\n');
  cin.ignore(100, '\n');
  tempName = new char[strlen(buffer)+1];
  strcpy(tempName, buffer);

  do{					//determine a random number to be attached to the new pet item, used to sort through the list to 
    validnum = false;		//determine where it should be placed
    number = rand() % 100 + 1;	//select ID number between 1 and 100
    for(int i = 0; i < 20; ++i)	//make sure we dont already have that value
    {
      if(number == IDlist[i])	
        validnum = true;
      if(IDlist[i] == 0)	//when we reach our next 0 save that index
        zeroindex = i;
    }
  }while(validnum);

  IDlist[zeroindex] = number;		//using that 0 index add our newest int value	

  cout << "\n\to You will now also be assigned a randomized number with your pet. \n\t\t+ Pet Number: " << number << endl;

  switch(choice)		//determine pet they wanted
  {
    case 1:			//Dog
      {
        if(history == true)				
        {						
          char main2[15] = "Golden Retr";
          care = new char[strlen(main2)+1];	//create it dynamic
          strcpy(care, main2);
        }else
        {
          char main1[8] = "Bulldog";
          care = new char[strlen(main1)+1];
          strcpy(care, main1);
        }

        if(option == 'Y' && choice == 1)			
          history = true;
        //create the new derived object that will be added to the tree along using all of the temporary data values
        Dog * dog_object = new Dog(tempName, care, history, wght, ag, number);	
        cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;	
        cout << "\n\to You are adding the following data to the tree: " << endl;
        cout << "\n\t+ New Data: \n" << *dog_object << endl;		//ostream derived class overload
        object.insert(dog_object, number);				//insert object pointer into the tree
      }
      break;

    case 2:			//CAT
      {					
        if(outdoor == true)		//determine what string literal is assigned to the new derived pointer
        {					//based on user inputed diet restricion
          char pet2[10] = "alley cat";
          care = new char[strlen(pet2)+1];	//create it dynamic
          strcpy(care, pet2);
        }else
        {
          char pet1[11] = "garden cat";
          care = new char[strlen(pet1)+1];
          strcpy(care, pet1);
        }

        if(option == 'Y' && choice == 2)
          outdoor = true;

        //create the new derived object that will be added to the tree along using all of the temporary data values
        Cat * cat_object = new Cat(tempName, care, outdoor, wght, ag, number);
        cout << "\n\to You are adding the following data to the tree: " << endl;						
        cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;	
        cout << "\n\t+ New Data: \n" << *cat_object << endl;	//ostream derived class overload
        object.insert(cat_object, number);				//insert pointer object into the tree
      }
      break;

    case 3:			//Rabbit
      {
        if(long_ears == true)				//determine what string literal is assigned to the new derived pointer
        {						//based on user inputed diet restriction
          char rabbit2[14] = "french lop";
          care = new char[strlen(rabbit2)+1];	//create it dynamic
          strcpy(care, rabbit2);
        }else
        {
          char rabbit1[15] = "english lop";
          care = new char[strlen(rabbit1)+1];
          strcpy(care, rabbit1);
        }

        if(option == 'Y' && choice == 3)
          long_ears = true;							

        //create the new derived object that will be added to the tree along using all of the temporary data values
        Rabbit * rabbit_object = new Rabbit(tempName, care, long_ears, wght, ag, number);	
        cout << "\n\to You are adding the following data to the tree: " << endl;	
        cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;	
        cout << "\n\t+ New Data: \n" << *rabbit_object << endl;	//ostream derived class overload
        object.insert(rabbit_object, number);				//insert pointer object into the tree
      }
      break;
  }

  delete [] care;				//all of these will create a dynamic char* of rental type so delete it 
  care = NULL;
  delete [] tempName;				//delete the dynamic temp name now that its been added to the derived pointer and put into the tree
  tempName = NULL;
}



