def acceptData(arr):
    size = int(input("Enter number of students: "))
    print("Enter percentages of the students:")
    for i in range(size):
        arr.append(float(input("> ")))
    return size


def bubbleSort(arr, size):
    for Pass in range(size):
        for j in range(size - 1):
            if arr[j] > arr[j+1]:
                temp = arr[j+1]
                arr[j+1] = arr[j]
                arr[j] = temp


def selectionSort(arr, size):
    for i in range(size):
        if arr[0] > arr[i]:
            temp = arr[i]
            arr[i] = arr[0]
            arr[0] = temp
    
    i = 1
    while i < size - 1:
        for j in range(i+1, size):
            if arr[i]>arr[j]:
                 temp = arr[i]
                 arr[i] = arr[j]
                 arr[j] = temp
        i+=1


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
            scores = []
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
