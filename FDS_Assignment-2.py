#!/usr/bin/env python3

length = int(input("Enter total number of students in the class: "))

marks = []

absent = 0

def takeMarks(array):
    x = 0
    global absent
    print("Enter marks of all the students(out of 30):")

    while x < length:
        inp = input('> ')
        if inp == 'AB'or inp == 'ab':
            absent += 1
            x += 1
            continue
        inp = int(inp)
        if inp <= 30 and inp >= 0:
            array.append(inp)
            x += 1
        else:
            print("The marks should be out of 30!")


def average(marks):
    avg = 0
    for score in marks:
        avg += score

    avg /= (length-absent)
    return avg


def highest(marks):
    highest = 0
    for score in marks:
        if score > highest:
            highest = score
    return highest

def lowest(marks):
    lowest = highest(marks)
    
    for score in marks:
        if score < lowest:
            lowest = score
    return lowest

def frequency(marks):
    freq = 0
    freqMark = 0
    for score1 in marks:
        tempFreq = 0
        for score2 in marks:
            if score1 == score2:
                tempFreq += 1
    
        if tempFreq > freq :
            freq = tempFreq
            freqMark = score1
            
    return freqMark

def displayInfo():
    print("Average marks are:", average(marks))
    print("Highest scored marks:", highest(marks))
    print("Lowest scored marks:", lowest(marks))
    print("Marks with highest occurence:", frequency(marks))
    print("Number of students absent:", absent)

#============================================================#

takeMarks(marks)

displayInfo()
