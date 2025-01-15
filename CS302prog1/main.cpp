/* Saifullah Shaik
  
   main.cpp is a testing site for Actors, Artists, and Animals. For help with testing, type 0 in the main screen
   when you run it.


 */

#include <iostream>
#include "Nodes.h"
#include <cstring>
#include <vector>
using namespace std;

void setup_b(vector<Actors> & b_vtr); //make new
void setup_s(Array & art); //make new artist
void setup_r(CLL & ani); //make new animal
void actor(Actors & b);
void manage_actor(vector<Actors> & b_vtr);
void artists(Artists & s);
void manage_artists(Array & art);
void animals(Animals & r);
void manage_animals(CLL & ani);

//vector functions:
void rm_vtr(vector<Actors> & b_vtr, char* name);
void rm_all(vector<Actors> & b_vtr);
void d_vtr(vector<Actors> & b_vtr);

int main(){
  cout << "Welcome to Comic Con Planner!" << endl;
  char choice = 'a';
  char manage = 'a';
  vector<Actors> b_vtr;
  CLL ani;
  Array art;

  do {
    cout << " " << endl;
    cout << "-----------------------" << endl;
    cout << "Select an appointment." << endl;
    cout << "-----------------------" << endl;
    cout << "1 - Actor meet" << endl;
    cout << "2 - Artist meet" << endl;
    cout << "3 - Animal meet" << endl;
    cout << " " << endl;
    cout << "OR" << endl;
    cout << "4 - Manage existing Appointments (display all, delete, add, etc)" << endl;
    cout << "0 - Help: How to use this interface" << endl;
    cout << "q - quit program" << endl;
    cin >> choice;
    cin.ignore(1000, '\n');

    //Actor
    if(choice == '1'){
      setup_b(b_vtr);
    }

    //Artist
    else if (choice == '2'){
      setup_s(art);
    }

    //animals
    else if(choice == '3'){
      setup_r(ani);
    }
    //manage existing
    else if(choice == '4'){
      cout << "Manage which type of appointment?" << endl;
      cout << "1 - Actor" << endl;
      cout << "2 - Artist" << endl;
      cout << "3 - Animal" << endl;
      cin >> manage;
      cin.ignore(1000, '\n');
      if(manage == '1'){
  if(b_vtr.size() == 0) {
    cout << "You have not met any actors yet." << endl;
    break;
  }
  manage_actor(b_vtr);
      } else if (manage == '2'){
  if(art.is_empty() == true) {
    cout << "You have not met any artists yet." << endl;
    break;
  }
  manage_artists(art);
      } else if (manage == '3'){
  if(ani.is_empty() == true){
    cout << "You have not met any animal characters." << endl;
    break;
  }
  manage_animals(ani);
      } else {
  cout << "That was not one of the choices." << endl;
      }
    } else if(choice == '0'){
      cout << "Start by selecting one of the events to plan." << endl;
      cout << "After successfully making an event, you can choose (y/n) to " << endl;
      cout << "do specific operations on that event such as customize it " << endl;
      cout << "or change details." << endl;
      cout << " " << endl;
      cout << "From the main screen, you can also choose to manage" << endl;
      cout << "existing events. With this option, you can test the " << endl;
      cout << "data structures." << endl;
    } 
  } while(choice != 'q'); 
  return 0;
}

void setup_b(vector<Actors> & b_vtr){
  int a = 0;
  string word;
  char clothes[150];
  char dir[500];
  vector<string> vtr;
  char yn[5];
  cout << "Enter the amount of items you would like to get autographed" << endl;
  cout << "add to the list of things to get autographed" << endl;
  cout << "> ";
  cin >> a;
  cin.ignore(1000, '\n');
  cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

  for(int i = 0; i < a; i++){
    cout << "> ";
    getline(cin, word);
    vtr.push_back(word);
  }
  cout << "Please enter what you plan to wear tp the photo." << endl;
  cout << "> ";
  cin.get(clothes, 150);
  cin.get();
  cout << "Enter the directions to the appointment: " << endl;
  cout << "> ";
  cin.get(dir, 500);
  cin.get();

  Actors b(vtr, dir, clothes);

  b.read();
  b_vtr.push_back(b);

  while(strcmp(yn, "n") != 0){
      cout << " " << endl;
      cout << "Would you like to change any fields or look at more Actors options? (y/n)" << endl;
      cout << "> ";
      cin.get(yn, 5);
      cin.get();
      if(strcmp(yn, "y") == 0){
        actor(b);
      }
    }
  }


void setup_s(Array & art){
  int a = 0;
  int b = 0;
  string word;
  string item;
  vector<string> arts;
  vector<string> items;
  int bg;
  char yn[5];
  cout << "Enter the amount of artists you would like to meet." << endl;
  cin >> a;
  cin.get();
  cout << "Enter each artist in 1 at a time, separated by a newline." << endl;
  for(int i = 0; i < a; i++){
    cout << "> ";
    getline(cin, word);
    arts.push_back(word);
  }
  cout << "Enter how many items you would like to yout autograph list" << endl;
  cin >> b;
  cin.get();
  cout << "Enter each item in 1 at a time, separated by a newline." << endl;
  for(int j = 0; j < b; j++){
    cout << "> ";
    getline(cin, item);
    items.push_back(item);
  }

  cout << "What is your budget for this meet?" << endl;
  cout << "> ";
  cin >> bg;
  cin.get();

  Artists s(arts, items, bg);
  s.read();
  while(strcmp(yn, "n") != 0){
    cout << " " << endl;
    cout << "Would you like to change any fields or look at more artist options? (y/n)" << endl;
    cout << "> ";
    cin.get(yn, 5);
    cin.get();
    if(strcmp(yn, "y") == 0){
      artists(s);
    }
  }
  art.insert(s);
}

void setup_r(CLL & ani){
  Animals r;
  char yn[5];
  r.read();

  while(strcmp(yn, "n") != 0){
    cout << " " << endl;
    cout << "Would you like to change or view more Charaters to meet? (y/n)" << endl;
    cout << "> ";
    cin.get(yn, 5);
    cin.get();
    if(strcmp(yn, "y") == 0){
      animals(r);
    }
  }
  ani.insert(r);
}


// ******************************** ACTORS SELECTIONS *************************************

void actor(Actors & b){
  char choice;
  string word;
  int amount;
  vector<string> to_add;
  vector<string> to_remove;

  cout << "Select an option." << endl;
  cout << "1 - add items to bring to autograph " << endl;
  cout << "2 - remove from the list of items to bring" << endl;
  cout << "3 - display your current actor meet details" << endl;
  cout << "4 - check the weather at the meet " << endl;
  cout << "5 - hear a fun fact about this place" << endl;
  cin >> choice;
  cin.ignore(1000, '\n');

  //add items
  if (choice == '1'){
    cout << "how many items would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add.push_back(word);
    }
    b.add_items(to_add);
  }

  //remove items
  else if (choice == '2'){
    cout << "how many items would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove.push_back(word);
    }
    b.remove_items(to_remove);
  }

  //display
  else if (choice == '3'){
    b.display();
  }

  //check weather
  else if (choice == '4'){
    b.check_weather();
  } 

  //fun fact
  else if (choice == '5'){
    b.fun_fact();
  }

  else {
    cout << "That was not one of the options." << endl;
  }
}

// ******************************** ARTISTS SELECTIONS *************************************
void artists(Artists & s){
  char i;
  vector<string> to_add1;
  vector<string> to_remove1;
  vector<string> to_add2;
  vector<string> to_remove2;
  int amount;
  string word;

  cout << "Select an option." << endl;
  cout << "1 - Add artist to the list. " << endl;
  cout << "2 - Remove artists from the list." << endl;
  cout << "3 - Add items to your autograph list. " << endl;
  cout << "4 - Remove items from your autograph list." << endl;
  cout << "5 - Display all details of your  Artist meet." << endl;
  cout << "> ";
  cin >> i;
  cin.get();

  if(i == '1'){
    cout << "how many artists would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each artist (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add1.push_back(word);
    }    
    s.add_artists(to_add1);
  }

  else if(i == '2'){
    cout << "how many artists would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each artist (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove1.push_back(word);
    }    
    s.remove_artists(to_remove1);
  }

  else if(i == '3'){
    cout << "how many items would you like to add?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;

    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_add2.push_back(word);
    }
    s.add_items(to_add2);
  }

  else if(i == '4'){
    cout << "how many items would you like to remove?" << endl;
    cout << "> ";
    cin >> amount;
    cin.get();
    cout << "Enter in each item (1 at a time, separated by a newline)" << endl;
    for(int i = 0; i < amount; i++){
      cout << "> ";
      getline(cin, word);
      to_remove2.push_back(word);
    }    
    s.remove_items(to_remove2);
  }

  else if(i == '5'){
    s.display();
  }
}

// ******************************** Animals SELECTIONS *************************************
void animals(Animals & r){
  char c;
  //char d;

  cout << "Select an option." << endl;
  cout << "1 - Get the contact info of the character meet representative." << endl;
  cout << "2 - Write a review of this character." << endl;
  cout << "3 - Display all character details." << endl;
  cout << "> ";
  cin >> c;
  cin.get();
  if(c == '1'){
    r.contact_info();
  } else if (c == '2'){
    r.write_review();
  } else if (c == '3'){
    r.display();
  } else {
    cout << "That was not one of the options." << endl;
  }
}


//manage Actors
void manage_actor(vector<Actors> & b_vtr){
  char c;
  char name[50];

  cout << "Select an option. " << endl;
  cout << "1 - add another Actor" << endl;
  cout << "2 - remove an Actor" << endl;
  cout << "3 - display all Actors" << endl;
  cout << "4 - remove all Actors" << endl;
  cin >> c;
  cin.ignore(1000, '\n');

  if(c == '1'){
    setup_b(b_vtr);
  } else if (c == '2'){
    cout << "What is the name of the Actor event you would like to remove?" << endl;
    cin.get(name, 50);
    cin.get();
    rm_vtr(b_vtr, name);
  } else if(c == '3'){
    d_vtr(b_vtr);
  }
}

//remove a specific actor
void rm_vtr(vector<Actors> & b_vtr, char* name){
  string str(name);

  for(vector<Actors>::iterator it = b_vtr.begin(); it!=b_vtr.end(); ++it){
    if((*it).compare(str)){
      b_vtr.erase(it);
      break;
    }
  }

}

//display all actors
void d_vtr(vector<Actors> & b_vtr){
  for(vector<Actors>::iterator i = b_vtr.begin(); i!=b_vtr.end(); ++i){
    (*i).display();
  }
}

//remove all actors
void rm_all(vector<Actors> & b_vtr){
  for(vector<Actors>::iterator i = b_vtr.begin(); i!=b_vtr.end(); ++i){
    b_vtr.erase(i);
  }
}



//manage artists
void manage_artists(Array & art){
  char c;
  char name[50];

  cout << "Select an option. " << endl;
  cout << "1 - add another artist" << endl;
  cout << "2 - remove a artist" << endl;
  cout << "3 - display all artist" << endl;
  cout << "4 - remove all artist" << endl;
  cin >> c;
  cin.ignore(1000, '\n');

  if(c == '1'){
    setup_s(art);
  } else if (c == '2'){
    cout << "What is the name of the artis you would like to remove?" << endl;
    cin.get(name, 50);
    cin.get();
    A_Node * found = art.find_artist(name);
    if(found) art.remove(found);
    else {
      cout << "Could not find a artist by that name." << endl;
    }
  } else if(c == '3'){
    art.display();
  } else if(c == '4'){
    art.remove_all();
  }
}

//manage animals
void manage_animals(CLL & ani){
  char c;
  char name[50];

  cout << "Select an option. " << endl;
  cout << "1 - add another Character" << endl;
  cout << "2 - remove a Character" << endl;
  cout << "3 - display all Character" << endl;
  cout << "4 - remove all Characters" << endl;
  cin >> c;
  cin.ignore(1000, '\n');

  if(c == '1'){
    Animals n;
    n.read();
    ani.insert(n);
  }

  else if(c == '2'){
    cout << "Enter the name of the animal you would like to remove." << endl;
    cout << "> ";
    cin.get(name, 50);
    cin.get();
    ani.remove(name);
  }

  else if(c == '3'){
    ani.display();
  }

  else if(c == '4'){
    ani.remove_all();
  }
}




