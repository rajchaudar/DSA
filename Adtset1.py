str1 = input("Enter elements of set1: ")
str2 = input("Enter elements of set2: ")

set1 = set(str1.split())
set2 = set(str2.split())
print(set1)
print(set2)

def union(set1, set2):
    result = set()
    for element in set1:
        result.add(element)
    for element in set2:
        result.add(element)
    return result

def intersection(set1, set2):
    result = set()
    for element in set1:
        if element in set2:
            result.add(element)
    return result

def difference(set1, set2):
    result = set()
    for element in set1:
        if element not in set2:
            result.add(element)
    return result

def is_subset(set1, set2):
    for element in set1:
        if element not in set2:
            return False
    return True



while True:
    print("--------------------")
    print("1. Add new elements")
    print("2. Remove an element")
    print("3. Check whether element is present in set or not")
    print("4. Check the size of set1")
    print("5. Intersection of two sets")
    print("6. Difference of two sets")
    print("7. Union of two sets")
    print("8. Subset")
    print("9. Exit")
    choice = int(input("Choose an option: "))
    if choice == 1:
        element = input("Enter the element you want to add: ")
        set1.add(element)
        print(set1)
    elif choice == 2:
        element = input("Enter the element you want to remove: ")
        if element in set1:
            set1.remove(element)
            print("Element removed:", element)
        else:
            print("Element not present in set1")
            print(set1)
    elif choice == 3:
        element = input("Enter the element you want to check: ")
        if element in set1:
            print("Element is present in set1")
        else:
            print("Element not present in set1")
            print(set1)
    elif choice == 4:
        print("Size of set1:", len(set1))
    elif choice == 5:
        print("Intersection:", intersection(set1, set2))
    elif choice == 6:
        print("Difference (set1 - set2):", difference(set1, set2))
    elif choice == 7:
        print("Union:", union(set1, set2))
    elif choice == 8:
        print("set1 is subset of set2:", is_subset(set1, set2))
    elif choice == 9:
        break
    else:
        print("Invalid choice")
