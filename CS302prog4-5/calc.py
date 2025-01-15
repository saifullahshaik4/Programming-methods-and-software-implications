import games
import list

#Saifullah Shaik
#The purpose of this code is to set up the gamecalc class which is used for managing the game objects from games.py.
#The gamecalc class holds a lot of data but it pertains to one student per gamecalc object (this may change with program #5).
#The gamecalc class includes the import player function, the set weights function, the set winning function, the total xp function, and the check win function

class gamecalc:
    def __init__(self):
        self.this_player = None
        self.teams = []
        self.solos = []
        self.zombies = []

        self.team_weight = 0
        self.solo_weight = 0
        self.zombies_weight = 0
        self.winning_score = 0

        self.total_xp = 0

    #This function takes in and stores a Player(linked list) object as well as sorts the games out by type into lists
    def import_player(self, player):

        self.this_player = player

        tmp = player.head

        while tmp:

            if tmp.data.type == "team":
                self.teams.append(tmp.data)

            if tmp.data.type == "solo":
                self.solos.append(tmp.data)

            if tmp.data.type == "zombies":
                self.zombies.append(tmp.data)

            tmp = tmp.next

    #This function allows for the weights of the 3 game types to be set
    def set_weights(self, team_weight, solo_weight, zombies_weight):

        #Raises an error if value is negative
        if team_weight < 0 or solo_weight < 0 or zombies_weight < 0:
            raise ValueError("Weight can't be negative!")

        else:
            self.team_weight = team_weight
            self.solo_weight = solo_weight
            self.zombies_weight = zombies_weight

    #This function allows for the score required to win to be set.
    def set_winning(self, score):

        #Raises an error if value is negative
        if score < 0:
            raise ValueError("Winning score can't be negative!")

        else:
            self.winning_score = score

    #This function takes in the different scores from the game objects and the weights to determine the total game score
    #expecting decimals for weight and percent as integer for game scores
    def total_games(self):

        total = 0

        #not super positive on the actual logic for calculating total score based on weight, but this is something I tried
        for t in self.teams:
            total += t.get_score()*self.team_weight

        for t in self.solos:
            total += t.get_score()*self.solo_weight

        for t in self.zombies:
            total += t.get_score()*self.zombies_weight

        self.total_game = total

        return total


    #This function checks if the total game score is greater than or equal to the score required to win
    def check_win(self):

        if self.total_game >= self.winning_score:
            return True

        else:
            return False


