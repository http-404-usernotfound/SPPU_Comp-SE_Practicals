#!/usr/bin/env python3
# -*- coding: utf-8 -*-

rollNos = []


def takeArray(arr):
	size = int(input("Enter Number of students:"))
	print("Enter roll number of students:")
	for i in range(size):
		arr.append(int(input("> ")))
	return size


def sortArray(arr, size):
	for i in range(int(size/2)):
		for j in range(i, size):
			if arr[i] > arr[j]:
				temp = arr[i]
				arr[i] = arr[j]
				arr[j] = temp


def binarySearch(arr, value, size):
	low = 0
	upp = size - 1
	while low < upp:
		med = int((low + upp)/2)
		if arr[med] == value:
			return med
	
		if value > arr[med]:
			low = med
		elif value < arr[med]:
			upp = med
	return -1


def fibonacciSearch(arr, value, size):
	fib2 = 0
	fib1 = 1
	fib = fib1 + fib2
	offset = -1
	i = 0
	
	while fib < size:
		fib2 = fib1
		fib1 = fib
		fib = fib1 + fib2
	
	while arr[i] != value:
		i = min(offset + fib2, size-1)
		if arr[i] == value:
			return i
		elif arr[i] < value:
			fib = fib1
			fib1 = fib2
			fib2 = fib - fib1
			offset = i
		elif arr[i] > value:
			fib = fib2
			fib1 -= fib2
			fib2 = fib - fib1
	
	return -1


def main():
	length = 0
	
	while True:
		choice = int(input('''
  (1) - Accept Array
  (2) - Print Array
  (3) - Binary Search
  (4) - Fibonacci Search
  (5) - Exit
	Enter your choice:
	> '''))
	
		if choice == 1:
			length = takeArray(rollNos)
			sortArray(rollNos, length)
		elif choice == 2:
			print("The array is:", rollNos)
		elif choice == 3:
			key = int(input("Enter roll number to search: "))
			print("Index is:", binarySearch(rollNos, key, length))
		elif choice == 4:
			key = int(input("Enter roll number to search: "))
			print("Index is:", fibonacciSearch(rollNos, key, length))
		elif choice == 5:
			print("Exiting...")
			break
		else:
			print("Enter a valid input!")


main()
