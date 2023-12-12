def acceptData(arr):
    size = int(input("Enter number of students: "))
    print("Enter percentages of the students:")
    for i in range(size):
        arr.append(float(input("> ")))
    return size


def partition(arr, start, end):
    pivot = start
    left = start+1
    right = end

    while True:
        if arr[left] <= arr[pivot]:
            left += 1
        if arr[right] >= arr[pivot]:
            right -= 1
        if right < left:
            temp = arr[pivot]
            arr[pivot] = arr[right]
            arr[right] = temp
            pivot = right
            break
        if arr[left] > arr[right]:
            temp = arr[left]
            arr[left] = arr[right]
            arr[right] = temp

    return pivot


def quickSort(arr, start, end):
    if start >= end:
        return None

    pivot = partition(arr, start, end)

    quickSort(arr, start, pivot - 1)
    quickSort(arr, pivot + 1, end)
    return arr


def main():
    scores = []
    while True:
        choice = int(input('''
  (1) - Accept Score
  (2) - Quick Sort
  (3) - Display array
  (4) - Exit
    Enter your choice: '''))

        if choice == 1:
            scores = []
            size = acceptData(scores)
        elif choice == 2:
            start = 0
            end = len(scores) - 1
            quickSort(scores, start, end)
        elif choice == 3:
            print("Array is:", scores)
        elif choice == 4:
            print("Exiting...")
            break
        else:
            print("Enter a valid input!")


main()
