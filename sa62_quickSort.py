#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def acceptData(arr):
    size = int(input("Enter number of students: "))
    print("Enter percentages of the students:")
    for i in range(size):
        arr.append(float(input("> ")))
    return size


def quickSort(arr, size):
    for Pass in range(size):
        for j in range(size - 1):
            if arr[j] > arr[j+1]:
                temp = arr[j+1]
                arr[j+1] = arr[j]
                arr[j] = temp


def main():
    size = None
    scores = []
    while True:
        choice = int(input('''
  (1) - Accept Score
  (2) - Quick Sort
  (3) - Display array
  (4) - Exit
    Enter yout choice: '''))
    
        if choice == 1:
            scores = []
            size = acceptData(scores)
        elif choice == 2:
            quickSort(scores, size)
        elif choice == 3:
            print("Array is:", scores)
        elif choice == 4:
            print("Exiting...")
            break
        else:
            print("Enter a valid input!")


main()
