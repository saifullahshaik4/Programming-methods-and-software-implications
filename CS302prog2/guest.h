#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <exception>
#include "dll.h"
using namespace std;

//Saifullah Shaik
//CS302
//The purpose of this code is to set up hierarchy of guest classes for the guest management program.
//This file includes the guest base class with the game, food, and tour subclasses.
//The guest class has base data and a master list of guests plans.
//The game, food, and tour subclasses all have additional data as well as a create guest function.
//The subclasses also all have operator overloading, with the most important being the output operator allowing seamless display
//with the template based DLL.





//Guest base class
class Guest {
public:
    Guest(); //constructor
    void add_to_list(string name, string date, int time); //Add guest plan to master list
    void display_list(); //Display master list

protected:
    string location;
    int time;
    string date;

    map<string, string> guest_list; //STL map list of all guests with their dates and times



};

//game subclass from guest
class Game : public Guest {
public:
    Game(); //constructor
    Game(const Game &copy); //copy constructor
    void create_guest(string date, string location, int time, string name, int players); //Create game for guest

    //Overloaded Operators
    friend ostream & operator << (ostream & out, const Game & h);
    Game operator+ (const int i);
    Game operator+= (const int i);
    Game operator- (const int i);
    Game operator-= (const int i);
    bool operator== (const Game & h) const;
    bool operator!= (const Game & h) const;
    bool operator< (const Game & h) const;
    bool operator<= (const Game & h) const;
    bool operator> (const Game & h) const;
    bool operator>= (const Game & h) const;

protected:
    string name;
    int players;
};

class Food : public Guest {
public:
    Food(); //constructor
    Food(const Food &copy); //copy constructor
    void create_reservation(string date, string location, int time, string type, vector<string> dietary_restrictions); //Create reastaurant reservation for guest

    //Overloaded Operators
    friend ostream &operator<<(ostream &, const Food & f);
    Food operator+ (const int i);
    Food operator+= (const int i);
    Food operator- (const int i);
    Food operator-= (const int i);
    bool operator== (const Food & f) const;
    bool operator!= (const Food & f) const;
    bool operator< (const Food & f) const;
    bool operator<= (const Food & f) const;
    bool operator> (const Food & f) const;
    bool operator>= (const Food & f) const;


protected:
    string type;
    vector<string> dietary_restrictions; //STL vector list for dietary restrictions
};

class Tour : public Guest {
public:
    Tour(); //constructor
    Tour(const Tour &copy); //copy constructor
    void create_guest(string date, string location, int time, string type, int tour_length); //create a tour for the guest

    //Overloaded Operators
    friend ostream & operator<< (ostream & out, const Tour & e);
    Tour operator+ (const int i);
    Tour operator+= (const int i);
    Tour operator- (const int i);
    Tour operator-= (const int i);
    bool operator== (const Tour & e) const;
    bool operator!= (const Tour & e) const;
    bool operator< (const Tour & e) const;
    bool operator<= (const Tour & e) const;
    bool operator> (const Tour & e) const;
    bool operator>= (const Tour & e) const;

protected:
    string type;
    int tour_length;
};


