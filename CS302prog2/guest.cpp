#include "guest.h"
#include "dll.h"

//Saifullah Shaik
//CS302
//The purpose of this file is to implement the functions from the classes in the guest.h file.
//Functions include constructors, copy connstructors, create guest functions, add to master list,
//display master list, assignment operators, relational operators, and output operators.

//constructor
Guest::Guest() {}

//constructor
Game::Game() {}

//constructor
Food::Food() {}

//constructor
Tour::Tour() {}

//Add guest to master list given name, date, and time
void Guest::add_to_list(string name, string date, int time) {

    //combine date and time into string
    string dateandtime = date + " at " + to_string(time);

    //Exception handling to check if guest date and time are already booked
     for (auto itr = guest_list.find(dateandtime); itr != guest_list.end(); itr++) {
            throw(dateandtime);
        }

     //Add to list
    guest_list[dateandtime] = name;
}

//Display master list
void Guest::display_list() {

    //Iterate through list to display
    for (auto &item: guest_list) {
        cout << item.second << ": " << item.first << endl;
    }

    cout << endl;
}

//Game copy constructor
Game::Game(const Game &obj) {
    date = obj.date;
    time = obj.time;
    location = obj.location;
    name = obj.name;
    players = obj.players;

}

//Create game function
void Game::create_guest(string date, string location, int time, string name, int players) {

    this->date = date;
    this->location = location;
    this->time = time;
    this->name = name;
    this->players = players;

}

//Overloaded output operator
ostream & operator<<(ostream &os, const Game &h) {
    os << "Game name: " << h.name << endl << "Game location: " << h.location << endl << "Guests date: " << h.date
       << endl << "Guests time: " << h.time << endl << "Number of players playing this game: " << h.players << endl << endl;
    return os;
}

//Assignment operators for game:
Game Game::operator+ (const int i) {

    Game copy(*this);
    copy.time += i;

    if (time > 2400) {

        copy.time = 0;

    }

    return copy;
}

Game Game::operator+= (const int i) {

    Game copy(*this);
    copy.time += i;

    if (time > 2400) {

        copy.time = 0;

    }

    return copy;
}

Game Game::operator- (const int i) {

    Game copy(*this);
    copy.time -= i;

    if (time < 0) {

        copy.time = 0;

    }

    return copy;
}

//Relational Operators for game:
bool Game::operator==(const Game &op2) const {

    if (this->time == op2.time) {
        return true;
    }

    return false;
}

bool Game::operator!=(const Game &op2) const {

    if (this->time == op2.time) {
        return false;
    }

    return true;
}

bool Game::operator<(const Game &op2) const {

    if (this->time < op2.time) {
        return true;
    }

    return false;
}

bool Game::operator<=(const Game &op2) const {

    if (this->time <= op2.time) {
        return true;
    }

    return false;
}

bool Game::operator>(const Game &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}

bool Game::operator>=(const Game &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}

//Food copy constructor
Food::Food(const Food &obj) {
    date = obj.date;
    time = obj.time;
    location = obj.location;
    type = obj.type;
    dietary_restrictions = obj.dietary_restrictions;
}


//Create food reservation function
void Food::create_reservation(string date, string location, int time, string type, vector<string> dietary_restrictions ) {

    this->date = date;
    this->location = location;
    this->time = time;
    this->type = type;
    this->dietary_restrictions = dietary_restrictions;

}

//Overloaded output operator
ostream & operator<<(ostream &os, const Food &f) {
    os << "Reservation Type: " << f.type << endl << "Restaurant location: " << f.location << endl << "Reservation date: " << f.date
       << endl << "Reservation time: " << f.time << endl << "Dietary Restrictions: ";

    //Loop for vector, adding each entry to the output.
    for (string dietary_restriction: f.dietary_restrictions) {
        os << dietary_restriction << ", ";
    }

    os << endl << endl;

    return os;
}

//Assignment operators:
Food Food::operator+ (const int i) {

    Food copy(*this);
    copy.time += i;

    if (time > 2400) {

        copy.time = 0;

    }

    return copy;
}

Food Food::operator+= (const int i) {

    Food copy(*this);
    copy.time += i;

    if (time > 2400) {

        copy.time = 0;

    }

    return copy;
}

Food Food::operator- (const int i) {

    Food copy(*this);
    copy.time -= i;

    if (time < 0) {
        copy.time = 0;
    }

    return copy;
}

Food Food::operator-= (const int i) {

    Food copy(*this);
    copy.time += i;

    if (time > 2400) {
        copy.time = 0;
    }

    return copy;
}

//Relational operators:
bool Food::operator==(const Food &op2) const {

    if (this->time == op2.time) {
        return true;
    }

    return false;
}

bool Food::operator!=(const Food &op2) const {

    if (this->time == op2.time) {
        return false;
    }

    return true;
}

bool Food::operator<(const Food &op2) const {

    if (this->time < op2.time) {
        return true;
    }

    return false;
}

bool Food::operator<=(const Food &op2) const {

    if (this->time <= op2.time) {
        return true;
    }

    return false;
}

bool Food::operator>(const Food &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}

bool Food::operator>=(const Food &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}

//Tour copy constructor
Tour::Tour(const Tour &obj) {

    date = obj.date;
    time = obj.time;
    location = obj.location;
    type = obj.type;
    tour_length = obj.tour_length;
}

//Create tour reservation for guest
void Tour::create_guest(string date, string location, int time, string type, int tour_length) {

    this->date = date;
    this->location = location;
    this->time = time;
    this->type = type;
    this->tour_length = tour_length;
}

//Overloaded output operator
ostream & operator<<(ostream &os, const Tour &e) {
    os << "Tour Type: " << e.type << endl << "Tour location: " << e.location << endl << "Tour date: " << e.date
       << endl << "Tour time: " << e.time << endl << "tour Length: " << e.tour_length << " Hours" << endl << endl;
    return os;
}

//Assignment operators:
Tour Tour::operator+(const int i) {

    Tour copy(*this);
    copy.time += i;

    if (time > 2400) {
        copy.time = 0;
    }

    return copy;
}

Tour Tour::operator+= (const int i) {

    Tour copy(*this);
    copy.time += i;

    if (time > 2400) {

        copy.time = 0;

    }

    return copy;
}

Tour Tour::operator-(const int i) {

    Tour copy(*this);
    copy.time -= i;

    if (time < 0) {

        copy.time = 0;

    }


    return copy;
}

Tour Tour::operator-=(const int i) {

    Tour copy(*this);
    copy.time -= i;

    if (time < 0) {
        copy.time = 0;
    }

    return copy;
}

//Relational Operators:
bool Tour::operator==(const Tour &op2) const {

    if (this->time == op2.time) {
        return true;
    }

    return false;
}

bool Tour::operator!=(const Tour &op2) const {

    if (this->time == op2.time) {
        return false;
    }

    return true;
}

bool Tour::operator<(const Tour &op2) const {

    if (this->time < op2.time) {
        return true;
    }

    return false;
}

bool Tour::operator<=(const Tour &op2) const {

    if (this->time <= op2.time) {
        return true;
    }

    return false;
}

bool Tour::operator>(const Tour &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}

bool Tour::operator>=(const Tour &op2) const {

    if (this->time >= op2.time) {
        return true;
    }

    return false;
}


