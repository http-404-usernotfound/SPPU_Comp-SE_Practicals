def acceptData(arr):
	size = int(input("Enter number of students: "))
	print("Enter percentages of the students:")
	for i in range(size):
		arr.append(float(input("> ")))
	return size


def bubbleSort(arr, size):
	pass


def selectionSort(arr, size):
	pass
	


def main():
	size = None
	scores = []
	while True:
		choice = int(input('''
  (1) - Accept Score
  (2) - Bubble Sort
  (3) - Selection Sort
  (4) - Display array
  (5) - Exit
	Enter yout choice: '''))
	
		if choice == 1:
			size = acceptData(scores)
		elif choice == 2:
			bubbleSort(scores, size)
		elif choice == 3:
			selectionSort(scores, size)
		elif choice == 4:
			print("Array is:", scores)
		elif choice == 5:
			print("Exiting...")
			break
		else:
			print("Enter a valid input!")


main()
