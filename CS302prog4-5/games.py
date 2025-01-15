
import list
import calc

#Saifullah Shaik

#The purpose of this code is to set up the game hierarchy
#
#The game class has pushed up data as well as edit and display functions, and operators
#The 3 derived classes all have their own extra data members as edit functions for them and display functions

#Base class
class game:
    def __init__(self, name, score, date, comments):
        self.__name = name
        self.__score = score
        self.__date = date
        self.__comments = comments

    def edit_name(self, name):
        self.__name = name
        return

    def edit_score(self, score):
        self.__score = score
        return

    def edit_date(self, date):
        self.__date = date
        return

    def edit_comments(self, comments):
        self.__comments = comments
        return

    def display(self):
        print(f"Name: {self.__name}")
        print(f"Score: {self.__score}")
        print(f"Date: {self.__date}")
        print(f"Comments: {self.__comments}")


    def get_name(self):
        return self.__name

    def get_score(self):
        return self.__score

    #will use operators for BST management, and score manipulation

    def __add__(self, other):
      score = self.__score + other
      return game(self.__name, score, self.__date, self.__comments)

    def __sub__(self, other):
      score = self.__score - other
      return game(self.__name, score, self.__date, self.__comments)

    def __eg__(self, other):
      if self.__score == other.get_score():
        return True
      else:
        return False

    def __lt__(self, other):
      if self.__score < other.get_score():
        return True
      else:
        return False

    def __gt__(self,other):
      if self.__score > other.get_score():
        return True
      else:
        return False

    def __le__(self, other):
      if self.__score <= other.get_score():
        return True
      else:
        return False

    def __ge__(self,other):
      if self.__score >= other.get_score():
        return True
      else:
        return False



#Derived classes with base class functions
class team(game):
    type = "team"
    def __init__(self, name, score, date, comments, map, points):
        game.__init__(self, name, score, date, comments)
        self.__map = map
        self.__points = points #game object

    def edit_map (self, map):
        self.__map = map

    def add_points(self, points):
        self.__points.append(points)

    #remove by name
    def remove_points(self, name):
        i = 0
        found = False
        for t in self.__points:
            if t.get_name() == name:
                found = True
                break
            i+= 1

        if found:
            del self.__points[i]

    def display(self):
        game.display(self)
        print(f"Maps: {self.__map}")

        print("Points: ")
        for t in self.__points:
            game.display(t)
            print("\n")
        print("\n")


class solo(game):
    type = "solo"
    def __init__(self, name, score, date, comments, maps, curve):
        game.__init__(self, name, score, date, comments)
        self.__maps = maps
        self.__curve = curve

    def add_maps(self, map):
        self.maps.append(map) 

    def remove_maps(self, map):
        self.maps.remove(map)

    def edit_curve(self, curve):
        self.curve = curve

    def display(self):
        game.display(self)

        print("Maps: ")
        for t in self.__maps:
            print(t)

        print(f"Curve: {self.__curve}")
        print("\n")


class zombies(game):
    type = "zombies"
    def __init__(self, name, score, date, comments, challenge, time):
        game.__init__(self, name, score, date, comments)
        self.__challenge = challenge
        self.__time = time

    def edit_challenge(self, challenge):
        self.__challenge = challenge

    def edit_time(self, time):
        self.__time = time

    def display(self):
        game.display(self)
        print(f"Challenge: {self.__challenge}")
        print(f"Time: {self.__time}")
        print("\n")

  
