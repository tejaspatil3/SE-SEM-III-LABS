#DSL Practical ASSIGNMENT 4 (Searching&Sorting) 205B065
#Sorting

'''Write a Python program to store roll numbers of student in array who attended training 
program in random order. Write function for searching whether particular student attended 
training program or not, using linear search and Sentinel search.
Write a Python program to store roll numbers of student array who attended
training program in sorted order. Write function for searching whether particular 
student attended training program or not, using Binary search and Fibonacci search
'''

print("\nYou are Going to sort Data List\nPlease Provide Input\n")
list1=[] #MAKING LIST
n1=int(input("Enter Number of Elements in Data list : "))
for i in range(n1):
    n2 = input("Enter Data Element one by one : ")
    list1.append(n2)
print()
print("INPUT UNSORTED LIST IS : ",list1)
print("----------------------------------------------------")
length = len(list1)

#Defining Functions
def Bubble_sort(list1):
    
    for j in range(length-1):
        for i in range(length-1):
            if (list1[i] > list1[i+1]):
                #Swaping After Compairing
                temp = list1[i]
                list1[i] = list1[i+1]
                list1[i+1] = temp
        #Printing After Each Step Sort
        print("After Pass",j," list1 : ",list1)
        print("----------------------------------------------------")
    print("\nFinal Output After Sorting Using Bubble Sort ")
    print("The Sorted List Is : ",list1)
    print("----------------------------------------------------")

def Selection_sort1(list1):
    for i in range(length):
        j=i+1
        for j in range(length):
            if (list1[i]>list1[j]):
                #Swaping After Compairing
                temp=list1[j]
                list1[j]=list1[i]
                list1[i]=temp
            print("After Each Pass list1 : ",list1)
            print("----------------------------------------------------")
    
    print("\nFinal Output after Sorting Using Selection Sort ")
    print("The Sorted List (DESCENDING) : ",list1)
    print("----------------------------------------------------")

def Selection_sort2(list1):
    print()
    for i in range(length):
        j=i+1
        for j in range(length):
            if (list1[i]<list1[j]):
                #Swaping After Compairing
                temp=list1[j]
                list1[j]=list1[i]
                list1[i]=temp
            print("After Each Pass list1 : ",list1)
            print("----------------------------------------------------")
    
    print("\nFinal Output after Sorting Using Selection Sort ")
    print("The Sorted List (ASCENDING) : ",list1)
    print("----------------------------------------------------")

def Insertion_sort(list1):
    for i in range(length):
        temp = list1[i]
        j=i
        while(j>0 and list1[j-1]>temp):
            #Swaping After Compairing
            list1[j] = list1[j-1]
            j=j-1
        #Assigning Value to empty memory location
        list1[j]=temp
        print("AFTER EACH PASS UPDATED LIST : ",list1)
    print("----------------------------------------------------")
    print("\nFinal Output after Sorting Using Insertion Sort ")
    print("The Sorted List Is : ",list1)
    print("----------------------------------------------------")

#def Quick_sort(list1):
#    def Partition(list1,low,high):
#    pi=list1[high]
#    i=low-1

#    for j in range(low,high)



#Driver Code (main)
#Creating Loop for Choices
#Limiting Number of Iterations By While Loop   
n=1
while(n <= 5):
    n = n + 1
    
    print("\n\tCHOICES\n 1 : Bubble Sort\n 2 : Selection Sort\n 3 : Insertion Sort\n"
                " 4 : Quick Sort\n\t Enter Selected CHOICE Number : ",end=" ")
    k=int(input())

    #Calling Functions For CHOICE number
    if(k == 1):
        Bubble_sort(list1)
    elif(k == 2):
        Selection_sort1(list1)
        Selection_sort2(list1)
    elif(k == 3):
        Insertion_sort(list1)
    #elif(k == 4):
    #    Quick_sort(list1)
    #For adding Other Functions
    else:
        print("Enter Valid Choice")
        
