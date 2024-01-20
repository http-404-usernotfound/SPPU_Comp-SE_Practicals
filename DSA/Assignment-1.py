#!/usr/bin/env python3

class Record:
    def __init__(self, key, data):
        self.data = data
        self.key = key
    
    def out(self):
        print("Name:", self.data)
        print("Number:", self.key)
        print('')

class HashTable:
    def __init__(self, size):
        self.teleBook = []
        self.count = 0
        self.size = size
        for i in range(size):
            self.teleBook.append(None)
    
    def hash1(self, key):
        return key%self.size
    
    def hash2(self, key):
        return 7-(key%7)
    
    def isFull(self):
        return self.count == self.size
    
    def isEmpty(self):
        return self.count == 0
    
    def deleteLinearProbe(self, key):
        if self.isEmpty():
            print("Hash Table Empty!!")
            return None
        
        index = self.hash1(key)
        
        while self.teleBook[index].key != key:
            index += 1
        
        self.teleBook[index] = None
        self.count -= 1
        print("Record deleted at index:", index)
    
    def deleteDoubleHash(self, key):
        if self.isEmpty():
            print("Hash Table Empty!!")
            return None
        
        index = self.hash1(key)
        i = 1
        while self.teleBook[index].key != key:
            index = (self.hash1(key) + i*self.hash2(key))%self.size
        
        self.teleBook[index] = None
        self.count -= 1
        print("Record deleted at index:", index)
    
    def display(self):
        i = -1
        for record in self.teleBook:
            i += 1
            print('')
            print(i)
            if record == None:
                continue
            record.out()
        
    def insertLinearProbe(self, rec):
        if self.isFull():
            print("Hash Table Overflow!!")
            return None
        
        index = self.hash1(rec.key)
        
        if self.teleBook[index] != None:
            print("Collision has occurred at index: ", index)
        
        while self.teleBook[index] != None:
            index += 1
        
        self.teleBook[index] = rec
        self.count += 1
        print("Record written at index:", index)
    
    def insertDoubleHash(self, rec):
        if self.isFull():
            print("Hash Table Overflow!!")
            return None
        
        index = self.hash1(rec.key)
        i = 1
        if self.teleBook[index] != None:
            print("Collision has occurred at index: ", index)
        
        while self.teleBook[index] != None:
            index = (self.hash1(rec.key) + i*self.hash2(rec.key))%self.size
            i += 1
        
        self.teleBook[index] = rec
        self.count += 1
        print("Record written at index:", index)


def main():
    size = int(input("Enter size of hash table: "))
    ht = HashTable(size)
    
    while True:
        ch = int(input('''
=========================
   (1) - Linear Probing
       (2) - Double Hashing
    (3) - Exit
=========================
    Enter your choice: '''))
    
        if ch == 3:
            return
        
        elif ch == 2 or ch == 1:
    
            while True:
                choice = int(input('''
======SUB MENU=============
     (1) - Back to main menu
  (2) - Insert
      (3) - Delete
   (4) - Display
===========================
        Enter your choice: '''))
                
                if choice == 1:
                    break
                
                elif choice == 2 and ch == 1:
                    name = input("Name: ")
                    number = int(input("Number: "))
                    
                    record = Record(number, name)
                    ht.insertLinearProbe(record)
                
                elif choice == 2 and ch == 2:
                    name = input("Name: ")
                    number = int(input("Number: "))
                    
                    record = Record(number, name)
                    ht.insertDoubleHash(record)
                
                elif choice == 3 and ch == 1:
                    number = int(input("Number: "))
                    ht.deleteLinearProbe(number)
                
                elif choice == 3 and ch == 2:
                    number = int(input("Number: "))
                    ht.deleteDoubleHash(number)
                
                elif choice == 4:
                    ht.display()
                
                else:
                    print("Enter a valid option!")

main()
