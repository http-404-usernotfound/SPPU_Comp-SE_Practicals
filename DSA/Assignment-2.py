class elem:
    def __init__(self, key, value, chain = None):
        self.key = key
        self.value = value
        self.chain = chain

class HashDict:
    diction = []
    def __init__(self, size):
        self.size = size
        for i in range(size):
            self.diction.append(None)
        self.count = 0
    
    def isFull(self):
        return self.count==self.size
    
    def isEmpty(self):
        return self.count==0
    
    def hash1(self, key):
        return key%self.size
    
    def addW_Orplace(self, elem):
        if self.isFull():
            print("Dictionary is FULL!")
            return None
        index = self.hash1(elem.key)
        
        if self.diction[index]!=None:
            while self.diction[index].chain!=None:
                index = self.diction[index].chain
                
        temp = index
        while self.diction[index]!=None:
            index+=1
            
        self.diction[temp].chain = index
        self.diction[index] = elem
    
    def addWreplace(self, elem):
        if self.isFull():
            print("\nDictionary is FULL!\n")
            return None
        
        index = self.hash1(elem.key)
        while self.diction[index]!=None:
           if self.hash1(self.diction[index].key)==index and self.diction[index].chain!=None:
               index = self.diction[index].chain
    
    def get(self, key):
        if self.isEmpty():
            print("\nDictionary is EMPTY!\n")
            return None
        index = self.hash1(key)
        i = 0
        while self.diction[index].key!=key:
            index = self.diction[index].chain
            i+=1
            if i==self.size:
                print("\nElement not found :(\n")
                return None
        
        return self.diction[index]
    
    def display(self):
        i = 0
        for elem in self.diction:
            print(i, elem.value, elem.chain)
            i+=1
    
def main():
    hd = HashDict(10)
    element = elem
    while True:
        choice = int(input('''
=========== MENU =============
(1) - Add With Replacement
(2) - Add Without Replacement
(3) - Get Value
(4) - Display
(5) - Exit
    Enter your choice: '''))
        
    if choice==1:
        element.key = int(input("Enter key: "))
        element.value = input("Enter value: ")
        hd.addWreplace(element)
    
    elif choice==2:
        element.key = int(input("Enter key: "))
        element.value = input("Enter value: ")
        hd.addW_Orplace(element)
    
    elif choice==3:
        key = int(input("Enter key: "))
        value = hd.get(key)
        
        print("Value is:", value)
    
    elif choice==4:
        hd.display()
    
    elif choice==5:
        return
    
    else:
        print("Enter a valid choice!")

main()