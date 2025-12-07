def quicksort(arr1):
    if len(arr1) <= 1:
        return arr1

    pivot = arr1[0]
    left = []
    right = []

    for element in arr1[1:]:
        if element < pivot:
            left.append(element)
        else:
            right.append(element)

    return quicksort(left) + [pivot] + quicksort(right)

arr=[]
m=int(input("Enter number of elements:"))
for i in range(m):
    element=float(input("Enter the First Year Percentage"))
    arr.append(element)
print("Percentage before Sorting= ",arr)
print("Percentage before Sorting= ",quicksort(arr))