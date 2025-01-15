import games
import calc
import list
import pytest
import BST

#Saifullah Shaik
#The purpose of this code is to set up the pytest testing suite for the gaming program. Below are different tests sorted into relvent catagories.
#These catagories (not including fixtures) are object creation testing, operator testing, data edit testing, and calc functions testing
#Two tests below are designed to fail, those being the ones that test negtaive numbers as they raise errors.


#
#Fixtures for pytest testing
#
@pytest.fixture
def game_setup():
    this_game = games.game("Call of Duty", 50, "1/1", "Generic Comments")
    return this_game

@pytest.fixture
def team_setup():
    this_team = games.team("Team #1", 60, "6/20", "Well done", "Nuke Town", [games.game("Half #1", 90, "6/10 Kills", "Good Half"), games.game("Half #2", 40, "6/16 Kills", "Could use some work")])
    return this_team

@pytest.fixture
def solo_setup():
    this_solo = games.solo("Battle #1", 90, "7/11", "Great job on this one!", ["Nuke Town", "Silo"], 91)
    return this_solo

@pytest.fixture
def zombies_setup():
    this_zombies = games.zombies("Zombies", 10, "12/14 Kills", "Needs improvement", "Shadows of Evil", "1 hour SURVIVE! ")
    return this_zombies

@pytest.fixture
def player_setup():
    this_player = list.Player("John")
    return this_player

@pytest.fixture
def calc_setup():
    this_calc = calc.gamecalc()
    return this_calc

@pytest.fixture
def bst_setup():
    this_bst = BST.BSTNode()
    return this_bst

#
#Object creation testing:
#
def test_gameCreation_success(game_setup):
    assert game_setup.get_name() == "Call of Duty"
    assert game_setup.get_score() == 50

def test_teamCreation_success(team_setup):
    assert team_setup.get_name() == "Team #1"
    assert team_setup.get_score() == 60

def test_soloCreation_success(solo_setup):
    assert solo_setup.get_name() == "Battle #1"
    assert solo_setup.get_score() == 90

def test_zombiesCreation_success(zombies_setup):
    assert zombies_setup.get_name() == "Zombies"
    assert zombies_setup.get_score() == 10

def test_playerCreation_success(player_setup):
    assert player_setup.name == "John"

def test_calcCreation_success(calc_setup):
    assert calc_setup.this_player == None

def test_BSTCreation_success(bst_setup):
    assert bst_setup.data == None

#
#Operator testing:
#

def test_gameOperator_Plus(game_setup):

    new_game = game_setup + 10
    assert new_game.get_score() == 60

def test_gameOperator_Minus(game_setup):

    new_game = game_setup - 10
    assert new_game.get_score() == 40

def test_gameOperator_Gt(game_setup, zombies_setup):

    assert game_setup > zombies_setup

def test_gameOperator_Ge(game_setup, zombies_setup):

    assert game_setup >= zombies_setup

def test_gameOperator_Lt(game_setup, zombies_setup):

    assert zombies_setup < game_setup

def test_gameOperator_Le(game_setup, zombies_setup):

    assert zombies_setup <= game_setup

#
#Data edit testing:
#
def test_gameEdit(game_setup):
    game_setup.edit_name("New Generic Game Name")
    assert game_setup.get_name() == "New Generic Game Name"

    game_setup.edit_score(60)
    assert game_setup.get_score() == 60

#
#Player linked list function testing:
#
def test_gameInsert(team_setup, solo_setup, zombies_setup, player_setup):

    player_setup.insert(team_setup)
    assert player_setup.head.data == team_setup

    player_setup.insert(solo_setup)
    assert player_setup.head.next.data == solo_setup

    player_setup.insert(zombies_setup)
    assert player_setup.head.next.next.data == zombies_setup



def test_gameRemove(zombies_setup, player_setup):
    player_setup.insert(zombies_setup)

    player_setup.remove(zombies_setup)
    assert player_setup.head == None




#
#Calc functions testing:
#
def test_importPlayers(team_setup, solo_setup, zombies_setup, player_setup, calc_setup):
    player_setup.insert(team_setup)
    player_setup.insert(solo_setup)
    player_setup.insert(zombies_setup)

    calc_setup.import_player(player_setup)

    assert calc_setup.this_player == player_setup

def test_setWeights(calc_setup):
    calc_setup.set_weights(.60, .30, .10)
    assert calc_setup.team_weight == .60
    assert calc_setup.solo_weight == .30
    assert calc_setup.zombies_weight == .10

#this one should fail
def test_setWeights_negative(calc_setup):
    calc_setup.set_weights(-.60, -.30, -.10)
    assert calc_setup.team_weight == -.60
    assert calc_setup.solo_weight == -.30
    assert calc_setup.zombies_weight == -.10

def test_setwinning(calc_setup):
    calc_setup.set_winning(80)
    assert calc_setup.winning_score == 80

#this one should also fail
def test_setwinning_negative(calc_setup):
    calc_setup.set_winning(-80)
    assert calc_setup.winning_score == -80


def test_totalGames(team_setup, solo_setup, zombies_setup, player_setup, calc_setup):
    player_setup.insert(team_setup)
    player_setup.insert(solo_setup)
    player_setup.insert(zombies_setup)

    calc_setup.import_player(player_setup)

    calc_setup.set_weights(.60, .30, .10)
    calc_setup.set_winning(80)

    assert calc_setup.total_games() == 64

def test_ifwinning(team_setup, solo_setup, zombies_setup, player_setup, calc_setup):
    player_setup.insert(team_setup)
    player_setup.insert(solo_setup)
    player_setup.insert(zombies_setup)

    calc_setup.import_player(player_setup)

    calc_setup.set_weights(.60, .30, .10)
    calc_setup.set_winning(63)

    calc_setup.total_games()

    assert calc_setup.check_win() == True


#
#BST functions testing:
#
def test_BSTInsert(bst_setup, player_setup):
  bst_setup.insert(player_setup)
  assert bst_setup.data == player_setup

def test_BSTDelete(bst_setup, player_setup):
  bst_setup.insert(player_setup)
  bst_setup.insert(player_setup)
  bst_setup.delete(player_setup)
  assert bst_setup.right == None and bst_setup.left == None

def test_BSTFind(bst_setup, player_setup):
  bst_setup.insert(player_setup)
  found = bst_setup.find("John")

  assert found == player_setup


