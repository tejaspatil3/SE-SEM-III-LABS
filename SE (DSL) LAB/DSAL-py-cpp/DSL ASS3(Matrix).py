#DSL Practical ASSIGNMENT 3 (MATRIX OPERATIONS) 205B065
 
 #Write Python program for storing matrix.
 #Write functions for
 #a) Check whether given matrix is upper triangular or not
 #b) Compute summation of diagonal elements
 #c) Compute transpose of matrix
 #d) Add, subtract and multiply two matrices

#Matrix Operations 
#Taking input for first matrix 
print("Matrix\nR1C1 	R1C2 	R1C3	.. 	R1Cn\nR2C1 	R2C2 	R2C3 	.. 	R2Cn"
	  "\nR3C1 	R3C2 	R3C3 	.. 	R3Cn\n.\n.\nRnC1 	RnC2 	RnC3 	.. 	RnCn")
Row1 = int(input("Enter the number of rows of First matrix1: "))
Column1 = int(input("Enter the number of columns of First matrix1 : "))
print("\n")
matrix1 = [] #Using List for Creating Matrix
for row in range(Row1): #For loop iterating rows
	a1 = [] #Creating Second list for storing columns 
	#and them we will add it to first to get full matrix
	for column in range(Column1): #For loop iterating
		a1.append(int(input("Enter the entries row wise : ")))
	matrix1.append(a1)
	#First Matrix created
#Printing First Matrix
for row in range(Row1):
	for column in range(Column1):
		print(matrix1[row][column], end=" ")
	print()
print("Length of Matrix1",len(matrix1))

#Taking input for Second Matrix
Row2 = int(input("Enter the number of rows of second matrix : "))
Column2 = int(input("Enter the number of columns of second matrix : "))
print("\n")
matrix2 = [] #Using List for Creating Matrix
for row in range(Row2): #For loop iterating rows
	a2 = [] #Creating Second list for storing columns 
	#and them we will add it to first to get full matrix
	for column in range(Column2): #For loop iterating
		a2.append(int(input("Enter the entries row wise : ")))
	matrix2.append(a2)
	#First Matrix created
#Printing Second Matrix
for row in range(Row2):
	for column in range(Column2):
		print(matrix2[row][column], end=" ")
	print()
print("Length of Matrix2",len(matrix2))

#Creating functions
def f1(): #ADDITION function
	print("\n")
	print("Element wise Addition of Matrix is \n")
	#Creating Default Matrix for Storing result
	#r1=[[0,0,0],[0,0,0],[0,0,0]]
	r1=[]
	for i1 in range(Column1):
		a=[]
		for i2 in range(Row1):
			a.append(0)
		r1.append(a)
	for i in range(len(matrix1)):
		for j in range(len(matrix1)):
			r1[i][j] = matrix1[i][j] + matrix2[i][j]
	for r in  r1: #Printing Resultant matrix of addition
		print(r)

def f2(): #SUBSTRACTION function
	print("\n")
	print("Element wise Substraction of Matrix is \n")
	#Creating Default Matrix for Storing result
	#r1=[[0,0,0],[0,0,0],[0,0,0]]
	r1=[]
	for i1 in range(Column1):
		a=[]
		for i2 in range(Row1):
			a.append(0)
		r1.append(a)

	for i in range(len(matrix1)):
		for j in range(len(matrix1)):
			r1[i][j] = matrix1[i][j] - matrix2[i][j]
	for r in  r1: #Printing Resultant matrix of addition
		print(r)

def f3(): #MULTIPLICATION function
	print("\n")
	print("Multiplication of Matrices is \n")
	#Creating Default Matrix for Storing result
	#r1=[[0,0,0],[0,0,0],[0,0,0]]
	r1=[]
	for i1 in range(Row1):
		a=[]
		for i2 in range(Column2):
			a.append(0)
		r1.append(a)
	print(r1)

	for i in range(len(matrix1)): #length of Matrix is number of rows
		for j in range(len(matrix2[0])):
			for k in range(len(matrix2)):
				r1[i][j] = matrix1[i][k] * matrix2[k][j]
	for r in  r1: #Printing Resultant matrix of addition
		print(r)

def f4(): #TRANSPOSE function
	print("\n")
	
	#Creating Default Matrix for Storing result
	r1=[[0,0,0],[0,0,0],[0,0,0]]
		
	for i in range(len(matrix1)):
		for j in range(len(matrix1)):
			r1[i][j] = matrix1[j][i]
	print("Transpose of matrix-1 is \n")
	for r in  r1: #Printing Resultant Transpose
		print(r)
	
	#Creating Default Matrix for Storing result
	r2=[[0,0,0],[0,0,0],[0,0,0]]

	for i in range(len(matrix2)):
		for j in range(len(matrix2)):
			r2[i][j] = matrix2[j][i]
	print("\nTranspose of matrix-2 is \n")
	for r0 in  r2: #Printing Resultant Transpose
		print(r0)

n=1    
while(n<=5):
	k=int(input("\n\t CHOICES\n 1:ADDITION\n"
				 " 2:SUSTRACTION\n 3:MULTIPLICATION\n"
				 " 4:TRANSPOSE \n\t Enter Selected choice number = "))
	n=n+1

	if (k==1):
		if (Row1==Row2 and Column1==Column2):
			f1()
		else:
			print("Addition cannot be done")
	elif(k==2):
		if (Row1==Row2 and Column1==Column2):
			f2()
		else:
			print("Substraction cannot be done")
	elif(k==3):
		if (Row2==Column1):
			f3()
		else:
			print("Multiplication cannot be done ")
			print("IN order to perform multiplication columns of first matrix"
		 " should be equal to rows of second matrix")
	elif(k==4):
		f4()
	else:
		print("enter valid choice")

	

	