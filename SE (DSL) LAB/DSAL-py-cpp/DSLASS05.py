def bubblesort():
    n=len(arr)
    for i in range (n-1):
        for j in range (n-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
    print("Bubble Sort=",arr)

def selectionsort():
    n = len(arr)
    for i in range (n):
        min=i
        for j in range (i+1,n):
            if (arr[j]<arr[min]):
                min=j
            temp=arr[i]
            arr[i]=arr[min]
            arr[min]=temp
    print("Selection Sort =",arr)


arr=[]
m=int(input("Enter number of elements:"))
for i in range(m):
    element=float(input("Enter the First Year Percentage"))
    arr.append(element)
print("Percentage before Sorting= ",arr)

while (1):
    print("1:Bubble Sort\n"
          "2:Selection Sort\n")
    choice = int(input("enter your choice="))

    if choice == 1:
        bubblesort()
    elif choice == 2:
        selectionsort()
    else:
        print("Invalid choice")
        break
