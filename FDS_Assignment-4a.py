#!/usr/bin/env python3

rollNos = []


def take_array(array):
    num = int(input("Enter number of students: "))
    print("Enter the values:")
    for i in range(num):
        array.append(int(input(f'{i+1}> ')))
    print("The array is:", array)
    
def linear_search(array):
    value = int(input("Enter roll no. for linear search: "))
    for index in range(len(array)):
        if array[index] == value:
            return index
    return -1

def sentinel_search(array):
    value = int(input("Enter roll no. for sentinel search: "))
    tail = len(array) - 1
    if array[tail] == value:
        return tail
    
    temp = array[tail]
    array[tail] = value
    
    i= 0
    while i < tail:
        if array[i] == value:
            array[tail] = temp
            return i
        i+=1
        
    array[i] = temp
    return -1

def menu():
   
    while True:
        choice = int(input('''
    (1) - Take Array
    (2) - Linear Search
    (3) - Sentinel Search
    (4) - Exit
   Enter your choice:
       > '''))
       
        if choice == 1:
            take_array(rollNos)
        elif choice == 2:
            print("Index is:", linear_search(rollNos))
        elif choice == 3:
            print("Index is:", sentinel_search(rollNos))
        elif choice == 4:
            break


menu()
