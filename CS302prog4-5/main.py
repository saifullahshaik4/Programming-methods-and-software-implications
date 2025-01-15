import list
import games
import calc
import BST

  #Saifullah Shaik
  

def Main():
    print("-- Start --")

    d = games.zombies("Name", 10, "12/14", "Well done", "Remove Last", 60)

    e = games.solo("Name", 60, "3213", "Not bad", ["Nuke Town", "Silo"], 4)

    a = games.team("Name", 70, "1412", "Good Work", "Nuke Town", [games.game("Name", 4, "321", "Good first"), games.game("Name", 12, "4234", "Great work on second")])

    john = list.Player("John")
    baron = list.Player("Baron")
    danny = list.Player("Danny")
  
    john.insert(d)
    john.insert(e)
    john.insert(a)
    john.insert(a)

    baron.insert(d)
    baron.insert(e)
    baron.insert(a)
    baron.insert(a)

    danny.insert(d)
    danny.insert(e)
    danny.insert(a)
    danny.insert(a)


    g = calc.gamecalc()

    g.import_player(john)

    g.set_weights(.30,.60,.10)

    g.set_winning(80)

    g.total_games()

    is_winning = g.check_win()

    print(f"Total Score: {g.total_game}")
    print(f"Winning: {is_winning}")

    b = BST.BSTNode()
    print("\n")
    print("BST Work:")

    b.insert(john)
    b.insert(baron)
    b.insert(danny)


    b.display([])

    b.delete(baron)



    print("\n")
    print("After deleting:")

    b.display([])

    print("After finding: ")
    found = b.find("John")

    found.display()


Main()
