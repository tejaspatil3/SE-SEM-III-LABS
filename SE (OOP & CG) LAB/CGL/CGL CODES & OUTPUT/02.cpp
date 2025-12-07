#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int i,n,n1,n2;
    cout<<"Enter array size : ";
    cin>>n1;

    int add[n1];
    cout<<"\nEnter Number of Elements in the array : ";
    cin>>n;
    
    if(n>n1)
        {cout<<"\nEnter numberof elements Less than array size : ";
        cin>>n;}
    for(i=0;i<n;i++){
        cout<<"\nEnter elements of the array : ";
        cin>>add[i];}
    cout<<"\nyour Entered array is :";
    for(i=0;i<n;i++)
        cout<<add[i]<<"  ";
    //deleting
    cout<<"\nEnter the Location index of the Element to be Deleted : ";
    cin>>n2;
    while (n2<n){
        add[n2]=add[n2+1];
        n2++;}
    n--;
    cout<<"Array after Deletion ";
    for(i=0;i<n;i++)
        cout<<add[i]<<"  ";
    
    return 0;

}