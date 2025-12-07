//Assignment No:04 {Object Oriented Programming}

/*Write a C++ program that creates an output file, writes information to it, closes the
file, open it again as an input file and read the information from the file.*/

#include<iostream>
#include<fstream>

using namespace std;
class Employee
{
string Name;
int Id;
double salary;
public:
void accept()
{
cout<<"\n Name : ";
cin.ignore();
getline(cin,Name);
cout<<"\n Id : ";
cin>>Id;
cout<<"\n Salary :";
cin>>salary;
}
void display()
{
cout<<"\n Name of Employee : "<<Name;
cout<<"\n Id of Employee : "<<Id;
cout<<"\n Salary of Employee : "<<salary;
}
};
int main(){

fstream f;
int i, n;
f.open("OOPLASS04FILE.txt" , ios::out);
cout<<"\n Enter the Number of Employee : ";
cin>>n;
Employee o[n];  //Creating array of objects
for(i = 0; i<n ; i++)
{
cout<<"\n Enter the Employee Information : ";
o[i].accept();
f.write((char*)&o[i],sizeof o[i]);
}
f.close();
cout<<"\n Information of Employees as Follow : ";
for(i = 0; i<n ; i++)
{
cout<<endl;
f.write((char*)&o[i],sizeof o[i]);
o[i].display();
}
f.close();
return 0;
}
//End of Program