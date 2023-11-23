cricket = []
football = []
badminton = []


def myIntersection(set1, set2):
    result = []
    for name1 in set1:
        for name2 in set2:
            if name1 == name2:
                result.append(name1)
    return result


def myUnion(set1, set2):
	result = []
	for element in set1:
		if element in set2:
			continue
		result.append(element)
	for element in set2:
		result.append(element)
	return result

def myUnion3(set1, set2, set3):
    result = [] 
    for element in set1:
        if element in set3 or element in set2:
            continue
        result.append(element)
    
    for element in set2:
        if element in set3:
            continue
        result.append(element)
        
    for element in set3:
        result.append(element)
        
    return result

def myDifference(set1, set2):
    result = []
    for element in set1:
        if element not in set2:
            result.append(element)
            
    return result

def myIntersection3(set1, set2, set3):
    result = []
    for name1 in set1:
        for name2 in set2:
            for name3 in set3:
                if name1 == name2 and name2 == name3 and name1 == name3:
                    result.append(name1)
    return result


crilen = int(input("Enter no. of students playing cricket: "))
print("\nEnter names of students playing cricket:")
for i in range(crilen):
    cricket.append(input("> "))

print("\nStudents playing cricket:", cricket)

footlen = int(input("\n\nEnter no. of stidents playing football: "))
print("\nEnter names of students playing football:")
for i in range(footlen):
    football.append(input("> "))

print("\nStudents playing football:", football)

badlen = int(input("\n\nEnter no. of students playing badminton: "))
print("\nEnter names of students playing badminton:")
for i in range(badlen):
    badminton.append(input("> "))

print("\nStudents playing badminton:", badminton)

criANDbad = myIntersection(cricket, badminton)

CriOrBad = myUnion(cricket, badminton)
eitherCriOrBad = myDifference(CriOrBad, criANDbad)
#print(eitherCriOrBad)
CriOrBadOrFoot = myUnion3(cricket, badminton, football)
#print(CriOrBadOrFoot)
noCrinoBad = myDifference(CriOrBadOrFoot, CriOrBad)
CriAndFoot = myIntersection(cricket, football)
CriAndFootNoBad = myDifference(CriAndFoot, badminton)
playingAll = myIntersection3(cricket, badminton, football)
print("\nStudents playing both cricket and badminton:", criANDbad)
print("Students playing either cricket or badminton but not both:", eitherCriOrBad)
print("Students playing neither cricket nor badminton:", noCrinoBad)
print("Students playing cricket and football but not badminton:", CriAndFootNoBad)
print("\nStudents playing all sports:", playingAll)

