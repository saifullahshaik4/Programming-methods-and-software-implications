/*  Saifullah Shaik
   
   This file contains the member functions for
   Actors, Artists, and Animals.
   It can be tested through the client program,
   main.cpp. 
   
 */

#include "Comic.h"

//******************* TIME FUNCTIONS *****************

//constructor with initialization list to initialize all fields
Time::Time() : date(""), appointment_time(""), is_pm(false) {

}

//set the information for the time class
void Time::read(){
  std::string d;
  std::string t;
  std::string ampm;

  std::cout << "Enter the date of this appointment. " << std::endl;
  std::cout << "Please use 6 digits (MMDDYY) to represent the date." << std::endl;
  std::cout << "Example: August 1, 2023 would be 080123." << std::endl;
  std::getline(std::cin, d);
  date = d;
  std::cout << "Enter the time of this appointment. " << std::endl;
  std::cout << "Please use 4 digits (HHMM) where H = hours and M = mins" << std::endl;
  std::cout << "   Example: 4:30 would be 0430" << std::endl;
  std::getline(std::cin, t);
  appointment_time = t;
  std::cout << "Is this event in the am or pm? (am/pm)" << std::endl;
  std::getline(std::cin, ampm);
  if(ampm == "am"){
    is_pm = false;
  } else {
    is_pm = true;
  }
}

void Time::display() const {
  std::cout << "Date: " << date.at(0) << date.at(1) << "/" << date.at(2) << date.at(3) << "/" << date.at(4) << date.at(5) << std::endl;
  std::cout << "Time: " << appointment_time.at(0) << appointment_time.at(1) << ":" << appointment_time.at(2) << appointment_time.at(3);
  if(is_pm == false){
    std::cout << " am" << std::endl;
  } else {
    std::cout << " pm" << std::endl;
  }
}

//*********************** Appointment FUNCTIONS ********************

Appointment::Appointment() : Time(){
  street_num = 0;
  street = new char[30];
  state = new char[30];
  city = new char[30];
  name = new char[50];
  people_going = new char[100];
}

//destructor to deallocate all dynamic memory
Appointment::~Appointment(){
  delete [] street;
  delete [] city;
  delete [] state;
  delete [] name;
  delete [] people_going;
  street = nullptr;
  city = nullptr;
  state = nullptr;
  name = nullptr;
  people_going = nullptr;
}

//copy constructor
Appointment::Appointment(const Appointment & source) : Time(source){
  street = new char[strlen(source.street) + 1];
  strcpy(street, source.street);
  city = new char[strlen(source.city) + 1];
  strcpy(city, source.city);
  state  = new char[strlen(source.state) + 1];
  strcpy(state, source.state);
  name = new char[strlen(source.name) + 1];
  strcpy(name, source.name);
  people_going = new char[strlen(source.people_going) + 1];
  strcpy(people_going, source.people_going);
}

//read in information about the event
void Appointment::read(){
  int num;
  char str[30];
  char c[30];
  char st[30];
  char n[50];
  char pg[100];

  //get info
  std::cout << "Creating an address for this event. Please enter the street number: "<< std::endl;
  std::cin >> num;
  std::cin.get();
  std::cout << "Please enter the street name: " << std::endl;
  std::cin.get(str, 30);
  std::cin.get();
  std::cout << "Please enter the city: " << std::endl;
  std::cin.get(c, 30);
  std::cin.get();
  std::cout << "Please enter the state: " << std::endl;
  std::cin.get(st, 30);
  std::cin.get();
  std::cout << "Address complete.\n" << std::endl;
  std::cout << "What would you like to call this Appointment?" << std::endl;
  std::cin.get(n, 50);
  std::cin.get();
  std::cout << "Finally, who is going to this Appointment?"  << std::endl;
  std::cin.get(pg, 100);
  std::cin.get();

  //set the info
  street_num = num;
  std::cout << "str: "<< str << std::endl;
  std::cout << "Street: " << street << std::endl;
  strcpy(street, str);
  strcpy(city, c);
  strcpy(state, st);
  strcpy(name, n);
  strcpy(people_going, pg);
  Time::read();
}

//a function to print out a pretend fun fact about the location of the event
//in a real application, these facts would be real
void Appointment::fun_fact(){
  srand(time(NULL));
  int n = rand() % 5;
  if(n == 0){
    std::cout << "This address was where the Spiderman was found." << std::endl;
  }
  else if (n == 1) {
    std::cout << "There was a Star Wars scene filmed at the location of this event." << std::endl;
  }
  else if (n == 2) {
    std::cout << "That city is home to the largest turtle in the world." << std::endl;
  }
  else if (n == 3) {
    std::cout << "That city holds an annual startrek parade." << std::endl;
  }
  else if (n == 4) {
    std::cout << "Legend has it that Brad Pitt will be at this Event." << std::endl;
  }
}

void Appointment::display() const {
  std::cout << "Event title: " << std::endl;
  std::cout << "   " << name << std::endl;
  std::cout << "People going: " << std::endl;
  std::cout << "   " << people_going << std::endl;
  std::cout << "Address: " << std::endl;
  std::cout << street_num << " " << street << " " << city << " " << state << std::endl;
  Time::display();
}

//******************* Actors FUNCTIONS *****************

//initialization list to initialize all fields and call the parent constructor
Actors::Actors() : Appointment(), directions(nullptr), clothes_plans(nullptr){
  directions = new char[500];
  clothes_plans = new char[150];
}

//destructor to deallocate all dynamic memory
Actors::~Actors(){
  delete [] directions;
  delete [] clothes_plans;
  directions = nullptr;
  clothes_plans = nullptr;
}

//copy constructor
Actors::Actors(const Actors & source){
  directions = new char[strlen(source.directions) + 1];
  strcpy(directions, source.directions);
  clothes_plans = new char[strlen(source.clothes_plans) + 1];
  strcpy(clothes_plans, source.clothes_plans);
}

//set up Actors fields
Actors::Actors(std::vector<std::string>& items, char* dir, char* f){
  directions = new char[500];
  clothes_plans = new char[150];
  items_to_bring = items;
  strcpy(directions, dir);
  strcpy(clothes_plans, f);
}

//passed in a char array of new items to add, adds to vector
void Actors::add_items(std::vector<std::string> &new_items){
  for(std::vector<std::string>::iterator i = new_items.begin(); i!=new_items.end(); ++i){
    items_to_bring.push_back(*i);
  }
}

//passed in a char array of items to remove, removes from vector
void Actors::remove_items(std::vector<std::string>& to_remove){
  for(std::vector<std::string>::iterator j = to_remove.begin(); j!=to_remove.end(); ++j){
    for(std::vector<std::string>::iterator i = items_to_bring.begin(); i!=items_to_bring.end(); ++i){
      if((*i) == (*j)){
  items_to_bring.erase(i);
  break;
      }
    }  
  }
}


//displays info about Actors
void Actors::display(){
  std::cout << "Items to bring: " << std::endl;
  for(std::vector<std::string>::iterator i = items_to_bring.begin(); i!=items_to_bring.end(); ++i){
    std::cout << (*i) << std::endl;
  }
  std::cout << "Directions: " << std::endl;
  std::cout << "   " << directions << std::endl;
  std::cout << "Clothes plans: " << std::endl;
  std::cout << "   " << clothes_plans << std::endl;
  Appointment::display();
}


//a function to display a pretend weather forecast (if this were a real
//application, this would be accurate and not made up)
void Actors::check_weather(){
  srand (time(NULL));
  int n = rand() % 36 + 75; //random number between 75 and 110 degrees
  std::cout << "It should be " << n << " degrees at the Venue." << std::endl;
}

bool Actors::compare(std::string n){
  return n == name;
}


//******************* Artists FUNCTIONS *****************

Artists::Artists() : Appointment(){

}

Artists::Artists(std::vector<std::string> & s, std::vector<std::string>& autograph_list, int b){
  artists = s;
  what_to_sign = autograph_list;
  budget = b;
}

//push back new items to the list of Artists to visit
void Artists::add_artists(std::vector<std::string>& to_add){
  for(std::vector<std::string>::iterator i = to_add.begin(); i!=to_add.end(); ++i){
    artists.push_back(*i);
  }
}

//remove artists from the list
void Artists::remove_artists(std::vector<std::string> &to_remove){
  for(std::vector<std::string>::iterator j = to_remove.begin(); j!=to_remove.end(); ++j){
    for(std::vector<std::string>::iterator i = artists.begin(); i!=artists.end(); ++i){
      if((*i) == (*j)){
  artists.erase(i);
  break;
      }
    }  
  }
}

//add items to autograph to the list
void Artists::add_items(std::vector<std::string> &to_add){
  for(std::vector<std::string>::iterator i = to_add.begin(); i!=to_add.end(); ++i){
    what_to_sign.push_back(*i);
  }
}

//remove items to autograph from the list
void Artists::remove_items(std::vector<std::string> &to_remove){
  for(std::vector<std::string>::iterator j = to_remove.begin(); j!=to_remove.end(); ++j){
    for(std::vector<std::string>::iterator i = what_to_sign.begin(); i!=what_to_sign.end(); ++i){
      if((*i) == (*j)){
  what_to_sign.erase(i);
  break;
      }
    }  
  }

}

//display Arttists info
void Artists::display(){
  std::cout << "Artists to visit: " << std::endl;
  for(std::vector<std::string>::iterator it = artists.begin(); it!=artists.end(); ++it){
    std::cout << (*it) << std::endl;
  }
  std::cout << "List of items to sign: " << std::endl;
  for(std::vector<std::string>::iterator i = what_to_sign.begin(); i!=what_to_sign.end(); ++i){
    std::cout << (*i) << std::endl;
  }
  std::cout << "Budget: " << budget << std::endl;
  Appointment::display();
}

bool Artists::compare(std::string n){
  return n == name;
}
//hash based on size of items and artists in vector and name of artist                                      
int Artists::hash(int size){
  return (int) pow((artists.size() + what_to_sign.size()), strlen(name)) % size;
}

//******************* Animals FUNCTIONS *****************

//initialization list to initialize all fields and call parent constructor
Animals::Animals() : Appointment(), character_genre(""), name(""), budget(0), review(""), reviewed(false){

}

void Animals::read(){
  std::string n;
  std::string c;
  int b = 0;

  std::cout << "Enter the name of the character." << std::endl;
  std::getline(std::cin, n);
  name = n;
  std::cout << "Enter the character genre of " << n << std::endl;
  std::getline(std::cin, c);
  character_genre = c;
  std::cout << "Enter your budget for the character meet." << std::endl;
  std::cin >> b;
  std::cin.get();
  budget = b;
  Appointment::read();
}

void Animals::contact_info(){
  std::cout << "Character appointment's phone number: ";
  srand(time(NULL));
  for(int i = 0; i < 3; i++){
    std::cout << rand() % 10;
  }
  std::cout << "-";
  for(int i = 0; i < 3; i++){
    std::cout << rand() % 10;
  }
  std::cout << "-";
  for(int i = 0; i < 4; i++){
    std::cout << rand() % 10;
  }
  std::cout << " " << std::endl;
}

//a function to display all animals details
void Animals::display(){
  std::cout << "Characters: " << name << std::endl;
  std::cout << "Genre: " << character_genre << std::endl;
  std::cout << "Budget: " << budget << std::endl;
  if (reviewed == true){
    std::cout << "Review: " << stars << " stars." << std::endl;
    std::cout << review << std::endl;
  }
  Appointment::display();
}

//a function to let the user write a review of the character meet
void Animals::write_review(){
  int num = 0;
  std::string rating;

  std::cout << "How many stars would you rate this Character meet? (0-5)" << std::endl;
  std::cin >> num;
  std::cin.get();
  std::cout << "Please add a description of your rating. " << std::endl;
  std::getline(std::cin, rating);
  review = rating;
  reviewed = true;

}

//compare what is passed in to name
bool Animals::compare(std::string n){
  return n == name;
}


