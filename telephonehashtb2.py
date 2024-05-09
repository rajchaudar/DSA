def take_data():
    ele1 = int(input("\nEnter Mobile Number:- "))
    ele2 = input("Enter Name:- ")
    data = [ele1, ele2]
    return data

def insert_using_linear_probing(data_1, table):
    index = data_1[0] % len(table)
    hash_add = index
    while True:
        if table[index] == -1:
            table[index] = data_1
            print(f"\n {data_1} added successfully....")
            return
        else:
            index = (index + 1) % len(table)
            print("\nCollision Occur...")
        if index == hash_add:
            return -1

def search_using_linear_probing(mobile_num, table):
    index = mobile_num % len(table)
    hash_add = index
    comparision = 1
    while True:
        if table[index][0] == mobile_num:
            print(f"Number of Comparision Required are :- {comparision}")
            return table[index]
        else:
            index = (index + 1) % len(table)
            comparision = comparision + 1
        if index == hash_add:
            return -1

def insert_using_quadratic_probing(data_1, table):
    global temp_count
    index = data_1[0] % len(table)
    i = 1
    while True:
        if table[index] == -1:
            table[index] = data_1
            temp_count = temp_count + 1
            print(f"\n {data_1} added successfully.....")
            return
        else:
            index = (index + (i * i)) % len(table)
            i = i + 1
            print("\nCollision Occur...")
        if temp_count == len(table):
            return -1

def search_using_quadratic_probing(mobile_num, table):
    index = mobile_num % len(table)
    hash_add = []
    i = 1
    while True:
        if table[index][0] == mobile_num:
            print(f"Number of Comparision required :- {i}")
            return table[index]
        else:
            index = (index + (i * i)) % len(table)
            i = i + 1
            if index not in hash_add:
                hash_add.append(index)
            if len(hash_add) == len(table):
                print(hash_add)
                print(table)
                return -1

def display(table):
    for i in table:
        print(i)

def sub_manu(temp):
    print("\n1.Insert.")
    print("2.Search.")
    print("3.Display.")
    print("4.Back to main manu.")
    temp_ch2 = int(input("\n Enter your choice:- "))
    if temp_ch2 == 1:
        temp_data = take_data()
        if temp == 1:
            print("\n Inserted Using Linear Probing.")
            num = insert_using_linear_probing(temp_data, Table1)
        elif temp == 2:
            print("\n Inserted Using Quadratic Probing.")
            num = insert_using_quadratic_probing(temp_data, Table2)
        if num == -1:
            print("Table is full....")
        sub_manu(temp)
    elif temp_ch2 == 2:
        mob_num = int(input("Enter number want to find:- "))
        if temp == 1:
            print("\n Searched Using Linear Probing.")
            num = search_using_linear_probing(mob_num, Table1)
            print(f"pair found:- ", num)
        elif temp == 2:
            print("\n Searched Using Linear Probing.")
            num = search_using_quadratic_probing(mob_num, Table2)
            print(f"pair found:- ", num)
        if num == -1:
            print("Number is not present in Table")
        sub_manu(temp)
    elif temp_ch2 == 3:
        print("\n Element in Table are:-\n")
        if temp == 1:
            display(Table1)
        elif temp == 2:
            display(Table2)
        sub_manu(temp)
    elif temp_ch2 == 4:
        main_manu()

def main_manu():
    print("\n1.Linear Probing.")
    print("2.Quadratic Probing.")
    print("3.Exit.")
    temp_ch = int(input("\n Enter your choice:- "))
    if temp_ch == 1:
        sub_manu(temp_ch)
    elif temp_ch == 2:
        sub_manu(temp_ch)
    elif temp_ch == 3:
        print("\n Exiting...")
        exit(0)

Table1 = [-1, -1, -1, -1, -1]
Table2 = [-1, -1, -1, -1, -1]
temp_count = 0

while True:
    main_manu()

