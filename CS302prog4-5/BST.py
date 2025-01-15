import games
import list

#Saifullah Shaik
#The purpose of this code is to set up the Binary Search Tree data structure that holds multiple players.
#In order to do this we have the BSTNode class which holds data members and manages the list.
#The BST includes functions such as insert, delete, find, and display.

class BSTNode:
    def __init__(self, data=None):
        self.left = None
        self.right = None
        self.data = data

    def insert(self, data):
        if not self.data:
            self.data = data
            return

        if self.data == data:
            return

        if data < self.data:
            if self.left:
                self.left.insert(data)
                return
            self.left = BSTNode(data)
            return

        if self.right:
            self.right.insert(data)
            return
        self.right = BSTNode(data)

    def delete(self, to_delete):
        if self == None:
            return self

        if to_delete < self.data:
            self.left = self.left.delete(to_delete)
            return self

        if to_delete > self.data:
            self.right = self.right.delete(to_delete)
            return self

        if self.right == None:
            return self.left

        if self.left == None:
            return self.right

        tmp = self.right
        while tmp.left:
            tmp = tmp.left
        self.data = tmp.data
        self.right = self.right.delete(tmp.data)
        return self

    def find(self, to_find):
        if len(to_find) == len(self.data.name):
            return self.data

        if len(to_find) < len(self.data.name):
            if self.left == None:
                return False
            return self.left.find(to_find)

        if self.right == None:
            return False
        return self.right.find(to_find)

    def display(self, vals):
        if self.left is not None:
            self.left.display(vals)
        if self.data is not None:
            self.data.display()
        if self.right is not None:
            self.right.display(vals)
        return vals

