import games
import calc


#Saifullah Shaik
#The purpose of this code is to set up the Linear Linked List data structure that holds multiple games for one player.
#In order to do this we have the Node class with the data and next pointer data members, as well as the Player class which acts as the actual list manager.
#The Player class includes functions such as inserting, removing, and displaying. All functions are done recursively.

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

class Player:
    def __init__(self, name):
        self.name = name
        self.head = None
        self.tail = None


    def get_head(self):
        return self.head

    #Recursive insert function
    def insertR(self, tmp, to_add):

        print("inserting")

        if (self.head == None):
            self.head = Node(to_add)
            self.tail = self.head
            self.tail.next = None

        else:            
            self.tail.next = Node(to_add)          
            self.tail = self.tail.next
            self.tail.next = None

    #Recursive insert wrapper
    def insert(self, to_add):
        self.insertR(self.head, to_add)

    #Recursive remove function
    def removeR(self, tmp, to_remove):
        if tmp is None:
            return None

        elif tmp.get_data() == to_remove:
            return tmp.get_next()

        else:
            tmp.set_next(self.removeR(tmp.get_next(), to_remove))
            return tmp

    #Recurisve remove wrapper
    def remove(self, to_remove):
        self.head = self.removeR(self.head, to_remove)

    #Recursive display function
    def displayR(self, tmp):
        if tmp == None:
            return

        tmp.data.display()

        self.displayR(tmp.next)

    #Recursive display wrapper
    def display(self):
        print(f"Player Name: {self.name}")

        return self.displayR(self.head)


    def __lt__(self, other):
        if len(self.name) < len(other.name):
            return True
        else:
            return False

    def __gt__(self,other):
        if len(self.name) > len(other.name):
            return True
        else:
            return False

