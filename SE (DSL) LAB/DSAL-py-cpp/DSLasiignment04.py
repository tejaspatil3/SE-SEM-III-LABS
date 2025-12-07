def sub(Lists,key):
    size=len(Lists)
    Lists.append(key)
    i=0
    while(Lists[i] !=key):
        i+= 1
    if(i==size):
        print("Student not attended the training program.")
    else:
        print("Student attended the program.")
def Ls(Lists,key):
    for i in range (len(Lists)):
       if key==Lists[i]:
        flag=1
        break

    else:
        flag=0


    if (flag==1):
        print("The student had attended the training session:")
    else:
        print("The student had not attended the training session ")

Lists=[]
CS=int(input("Enter the count for student who attend the training program:"))
for i in range(CS):
    r1=int(input("Enter the roll number of student who attend the program:"))
    Lists.append(r1)
key=int(input("Enter the key from the list:"))


while(1):

    print("\nA:Linear search,\nB:Sentinel search")
    ch=(input("Enter the choice:"))

    if (ch=='A'):
        Ls(Lists,key)

    elif(ch=='B'):
        sub(Lists,key)


    else:
        print("Invalid choice")
        break

