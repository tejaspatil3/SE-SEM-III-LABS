#ASSIGNMENT 2
#Write a Python program to compute following operations on String:
#a) To display word with the longest length
#b) To determines the frequency of occurrence of particular character in the string
#c) To check whether given string is palindrome or not
#d) To display index of first appearance of the substring 
#   To count the occurrences of each word in a given string

print("\t\tASSIGNMENT 2\n")

print("Enter the String")
s=input("\n")
print("\n")
def f1():
   word_list=s.split(" ")
   print("List of words",word_list)

def f2():
   word_list = s.split(" ")
   Longest = max(word_list)
   print("\nWord with longest Length in the string= ",Longest)

def f3():
   print("Enter a Char to get freq of occurrence in the string = ")
   s2=input()
   R={i:s.count(i) for i in set(s)}
   print("Frequency of occurence of character,",s2,"is = ",R[s2])

def f4():
   print("Enter A string to cherck palindrome = ")
   s1=input()
   s3=s1[::-1]
   if (s1==s3):
       print("Entered String is Palindrome\n")
   else:
       print("Entered String is NOT Palindrome\n")

def f5():
   print("Enter substring to get the First occurance index")
   s4=input()
   print("index is ",s.find(s4))

def f6():
   word=s.split()
   Dict={i:word.count(i) for i in set(word)}
   print("\nCount the occurance of each word",Dict)
   
n=1
while(n<=8):
   n=n+1
   print("\n\nChoice \n")
   print("1:List of words.\n2:Word with longest Length. \n"
         "3:Determine the freq of occ of particuler character in the string.\n"
         "4:Enter A string to cherck palindrome.\n"
         "5:Enter substring to check First occurance.\n"
         "6:Count the occur of each word in the given string.\n")
   k=int(input("Select a choice "))
   if (k==1):
       f1()
   elif(k==2):
       f2()
   elif(k==3):
       f3()
   elif(k==4):
       f4()
   elif(k==5):
       f5()
   elif(k==6):
       f6()
   else:
       print("Enter Valid choice\n")




