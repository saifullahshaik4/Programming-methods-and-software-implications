#include "guest.h"
#include "dll.h"

//Saifullah Shaik
//5/4/2022
//CS202
//The purpose of this file is to test the functionality of the program using the DLL and guest classes.
//In this code under main, this testing takes place through a dummy application with a user nav menu that allows for the
//tesing of different functions. For this program this includes adding games, Food, and tour reservations,
//displaying these options for the guest, and displaying the master list.


int main() {

    int loop = 0;
    int menu = 0;
    Guest r;
    DLL<Game> hlist;
    DLL<Food> flist;
    DLL<Tour> elist;



    //Only thing untestable here are all operators except output, these were tested in the testing suite commented out below
    do {
        cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Please choose an option below: " << endl;
        cout << "[1] Add Game night plan" << endl;
        cout << "[2] Add Food Reservation" << endl;
        cout << "[3] Add Tour Reservation" << endl;
        cout << "[4] Display Game night plan" << endl;
        cout << "[5] Display Food Reservations" << endl;
        cout << "[6] Display Event Reservations" << endl;
        cout << "[7] Display Master List" << endl;
        cout << "[Anything Else] Quit the program" << endl << endl;
        cin >> menu;
        cin.ignore(100, '\n');

        //If the user wants to enter a Game night plan
        if (menu == 1) {
            Game h;
            string date;
            string location;
            int time;
            string name;
            int players;

            cout << "Enter the Game name: ";
            cin >> name;

            cout << "Enter the location: ";
            cin >> location;

            cout << "Enter the date: ";
            cin >> date;

            cout << "Enter the time: ";
            cin >> time;

            cout << "Enter the number of players: ";
            cin >> players;

            //Exception handeling to check for overlapping plans
            try {
                r.add_to_list(name, date, time);
                h.create_guest(date, location, time, name, players);

                hlist.insert(h);

            } catch (string dateandtime) {
                cout << "Warning: " << dateandtime << " already has a plan!" << endl;
            }
        }

        //If the user wants to add a Food Reservation
        else if (menu == 2) {
            Food f;
            string date;
            string location;
            int time;
            string type;
            vector<string> dietary_restrictions;

            cout << "Enter the meal type: ";
            cin >> type;

            cout << "Enter the location: ";
            cin >> location;

            cout << "Enter the reservation date: ";
            cin >> date;

            cout << "Enter the reservation time: ";
            cin >> time;

            //While loop to fill vector
            int dietary_restrictions_loop = 1;

            while (dietary_restrictions_loop == 1) {
                string dietary_restriction;
                cout << "Enter dietary restriction: ";
                cin >> dietary_restriction;
                dietary_restrictions.push_back(dietary_restriction);

                cout << "Add another? 1 for Yes and 0 for No: ";
                cin >> dietary_restrictions_loop;
            }

            //Exception handeling to check for overlapping reservations
            try {
                r.add_to_list(type, date, time);
                f.create_reservation(date, location, time, type, dietary_restrictions);

                flist.insert(f);

            } catch (string dateandtime) {
                cout << "Warning: " << dateandtime << " already has a reservation!" << endl;
            }
        }

        //If the user wants to add an Tour Reservation
        else if (menu == 3) {
            Tour e;
            string date;
            string location;
            int time;
            string type;
            int length;

            cout << "Enter the place you are touring: ";
            cin >> type;

            cout << "Enter the location: ";
            cin >> location;

            cout << "Enter the reservation date: ";
            cin >> date;

            cout << "Enter the reservation time: ";
            cin >> time;

            cout << "Enter the tour length: ";
            cin >> length;

            //Exception handeling to check for overlapping reservations
            try {
                r.add_to_list(type, date, time);
                e.create_guest(date, location, time, type, length);

                elist.insert(e);

            } catch (string dateandtime) {
                cout << "Warning: " << dateandtime << " already has a reservation!" << endl;
            }
        }

        //
        else if (menu == 4) {

            //Method for the following cout's:
            //Uses DLL class output operator which outputs one of the guest subclass objects,
            // this causes the program to then use that subclass's output operator.
            cout << hlist;
        }

        //
        else if (menu == 5) {

            cout << flist;
        }

        //
        else if (menu == 6) {

            cout << elist;
        }

        //
        else if (menu == 7) {

            r.display_list();
        }

            //If anything else then change quite loop
        else {
            loop = 1;
        }
    } while (loop != 1);

    return 0;
}





