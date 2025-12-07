//Assignment No:01 {Object Oriented Programming}

/* Implement a class Complex which represents the Complex Number data type.
Implement the following 1. Constructor (including a default constructor which creates
the complex number 0+0i). 2. Overload operator+ to add two complex numbers. 3.
Overload operator* to multiply two complex numbers. 4. Overload operators << and >>
to print and read Complex Numbers. */

#include<iostream>
using namespace std;
class complex
{
float x , y;
public:
complex(){
x = 0;
y = 0;
}
complex operator+(complex &);
complex operator*(complex &);
friend istream &operator>>(istream & , complex &);
friend ostream &operator<<(ostream & , complex &);
};
istream &operator>>(istream &in , complex &d){
cout<<"\n Enter the real part of Complex Number : ";
in>>d.x;
cout<<"Enter imaginary part of Complex Number : ";
in>>d.y;
return in;
}
ostream &operator<<(ostream &out , complex &c){
out<<c.x<<" + "<<c.y<<"i";
out<<endl;
return out;
}
complex complex::operator+(complex &c){
complex temp;
temp.x = x + c.x;
temp.y = y + c.y;
return temp;
}
complex complex::operator*(complex &c){
complex temp1;
temp1.x = (x*c.x)-(y*c.y);
temp1.y = (y*c.x) + (x*c.y);
return temp1;
}
int main(){
complex c1,c2,c3,c4;
cout<<"";
cout<<"\n Default Constructor : ";
cout<<c1;
cout<<"\n\n Enter First Complex Number : ";
cin>>c1;
cout<<"\n\n Enter Second complex Number : ";
cin>>c2;
c3 = c1 + c2;
c4 = c1 * c2;
cout<<"\nAddition : "<<c3<<endl;
cout<<"\nMultiplication : "<<c4<<endl;
}
//End of Program