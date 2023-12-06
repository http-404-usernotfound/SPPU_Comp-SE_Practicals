#!/usr/bin/env python3

matrix1 = []
matrix2 = []
summ = []
diff = []
product = []
tr = []


def display(mat):
    if mat == None:
        print(None)
    else:
        print("=================")
        for element in mat:
            print(element)
        print("=================")

def takeMat(mat):
    row = int(input("Enter no. of rows: "))
    col = int(input("Enter no. of columns: "))
    for i in range(row):
        temp = []
        for j in range(col):
            temp.append(int(input(f"Enter [{i+1}][{j+1}] element: ")))
        mat.append(temp)
    print("\n The matrix is:")
    display(mat)
            
def summ(mat1, mat2):
    if len(mat1) != len(mat2):
        print("Addition not possible!")
        return None
    result = []
    for i in range(len(mat1)):
        temp = []
        for j in range(len(mat1[1])):
            temp.append(mat1[i][j]+mat2[i][j])
        
        result.append(temp)
    return result

def diff(mat1, mat2):
    if len(mat1) != len(mat2):
        print("Subtraction not possible!")
        return None
    result = []
    for i in range(len(mat1)):
        temp = []
        for j in range(len(mat1[1])):
            temp.append(mat1[i][j]-mat2[i][j])
        
        result.append(temp)
    return result

def prod(mat1, mat2):
    if len(mat1[1]) != len(mat2):
        print("Multiplication not possible!")
        return None
    result = []
    for i in range(len(mat1)):
        temp = []
        for j in range(len(mat2[1])):
            prod = 0
            for k in range(len(mat2)):
                prod += mat1[i][k]*mat2[k][j]
            temp.append(prod)
        result.append(temp)
    return result

def transpose(mat):
    result = []

    for i in range(len(mat[1])):
        temp = []
        for j in range(len(mat)):
            temp.append(mat[j][i])
        result.append(temp)
    return result


def menu():
    while True:
        choice = int(input('''
    (1) - Addition
    (2) - Subtraction
    (3) - Multiplication
    (4) - Transpose
    (5) - Exit
    
Which operation do you want to perform? :
    > '''))
        
        if choice == 1:
            print("\nThe addition is:")
            display(summ)
        elif choice == 2:
            print("\nThe subtraction is:")
            display(diff)
        elif choice == 3:
            print("\nThe multiplication is:")
            display(product)
        elif choice == 4:
            print("\nThe transpose is:")
            print("Matrix1: ")
            display(tr1)
            print("\nMatrix2: ")
            display(tr2)
        else:
            break
    
matrix1 = []
matrix2 = []

print("For matrix 1:")
takeMat(matrix1)
print("For matrix 2:")
takeMat(matrix2)

summ = summ(matrix1, matrix2)
diff = diff(matrix1, matrix2)
product = prod(matrix1, matrix2)
tr1 = transpose(matrix1)
tr2 = transpose(matrix2)

menu()
