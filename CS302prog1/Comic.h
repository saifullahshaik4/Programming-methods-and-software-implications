/* Saifullah SHaik
   
   This has information on where the the schedule with the various comic charecters takes place and who is going.
   It inherits Time, which manages when an event
   will occur. This file also contains the 3 classes
   that directly inherit
   Actors, Artists, and Animals.
 */
#include <vector>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
class Time {
public:
  Time();
  void read();
  void display() const;
  int compare(std::string input_time, bool input_is_pm) const;
protected:
  std::string date; //represented in 6 digits
  std::string appointment_time; //represented in 4 digits (hours and mins)
  bool is_pm;
};


class Appointment : public Time {
public:
  Appointment();
  ~Appointment();
  Appointment(const Appointment & source); //copy constructor

  //read location of Appointment:
  void read();
  void fun_fact(); //a function to print out a made up fun fact about the address
  void display() const;
protected:
  //pieces of an address:
  int street_num;
  char* street;
  char* city;
  char* state;
  char* name; //name of who your scheduled to meet
  char* people_going; //who is going
};
class Actors : public Appointment {
public:
  Actors(); //constructor
  Actors(const Actors & source); //copy constructor
  ~Actors(); //destructor
  Actors(std::vector<std::string> &items, char* dir, char* f);
  void add_items(std::vector<std::string>& new_items); //add items to a vector of what to bring
  void remove_items(std::vector<std::string>& to_remove); //remove items from the vector
  void display(); //display actors appointment info info
  void check_weather(); //displays a pretend weather forecast
  bool compare(std::string n);
protected:
  std::vector<std::string> items_to_bring; //what to bring to get autographed
  char* directions; //directions to the appointment
  char* clothes_plans; //what are you going to wear
};

class Artists : public Appointment {
public:
  Artists(); //constructor
  Artists(std::vector<std::string>& artists, std::vector<std::string>& autograph_list, int budget);
  void add_artists(std::vector<std::string> &to_add); //add artists to the list
  void remove_artists(std::vector<std::string>& to_remove); //remove artists from the list
  void add_items(std::vector<std::string>& to_add); //add items to get autographed the list
  void remove_items(std::vector<std::string>& to_remove); //remove items from the list
  void display(); //display autograph details
  bool compare(std::string n);
  int hash(int size);
 protected:
   std::vector<std::string> artists; //what artists to visit
   std::vector<std::string> what_to_sign; // list
   int budget; //how much you want to spend
 };

 class Animals : public Appointment {
 public:
   Animals(); //constructor
   void read();
   void display(); //display animal character details
   void contact_info(); //displays characters phone number (made up)
   void write_review(); //allows user to write a review on your interaction with the character
   bool compare(std::string n);
 protected:
   std::string character_genre; //type of Character
   std::string name; //name of Character
   int budget; //how much you want to spend
   int stars; // how many stars the review has
   std::string review;
   bool reviewed; //whether or not a review has been written
 };


