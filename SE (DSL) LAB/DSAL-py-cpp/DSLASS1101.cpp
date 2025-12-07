//Practical Assignment No:11 {Data Structure Lab}

/*Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from
queue.*/


#include<iostream>
#include<conio.h>
using namespace std;

class job			//class declaration
{
    int num;		//store serial no. of job
    job *next;		//points toward next node of job
public:
    job()
    {
        next = NULL;
    }
    void setnum(int x)
    {
        num = x;
    }
    void setnext(job *y)
    {
        next = y;
    }
    int getnum()
    {
        return num;
    }
    job* getnext()
    {
        return next;
    }
};

class order
{
    job *first,*last,*temp1;	
public:
    order()
    {
        first = NULL;
        last = NULL;
	temp1=NULL;
    }
    void create();
    void add();
    void del();
    void display();
};

void order::create()		//It creates the initial queue
{
    char ans;
    do
    {
        int n;
        cout<<"\nEnter the job number: ";
        cin>>n;
        job *nn;
        nn = new job();
        nn->setnum(n);
        if(first == NULL)
        {
            first = nn;
            last = nn;
            cout<<"\nfirst job inserted";
        }
        else
        {
            last->setnext(nn);
            last=last->getnext();
            cout<<"\njob inserted";
        }
        cout<<"\nDo you want to add another job, press Y/y :";
        cin>>ans;
    }while(ans == 'y' || ans == 'Y');
}

void order::add()		
{
    int n;
    job *nn;
    nn = new job();
    cout<<"\nEnter the job number: ";
    cin>>n;
    nn->setnum(n);
    if(first == NULL)
        {
            first = nn;
            last = nn;
        }
        else
        {
            last->setnext(nn);
            last=last->getnext();
        }
        cout<<"\nJob Added Successfully\n";
}

void order::del()		
{
    if(first == NULL)
    {
        cout<<"\nJob Queue is Empty\n";
    }
    else
    {
        job *temp;
        temp = first->getnext();
        delete(first);
        first = temp;
    }
    cout<<"\nFirst Job Removed Successfully\n";
}

void order::display()		//for verification(logically can't be performed) of data available inside queue
{
    cout<<"\nJob Queue :\n";

        temp1 = first;
        cout<<temp1->getnum()<<" ";
        while(temp1->getnext()!= NULL)
        {
            temp1 = temp1->getnext();
            cout<<temp1->getnum()<<" ";
        }
        cout<<endl;
}

int main()			//main function
{
    char ans;
    order Obj1;
    do
    {
    int choice;
    cout<<"\nChoice List: \n";			
    cout<<"\n\t1.Create Job Queue\n"<<"\n\t2.Insert Job in Job Queue\n";
    cout<<"\n\t3.Remove First Job from Job Queue\n"<<"\n\t4.Display Job Queue\n";
    cout<<"\nEnter Choice : ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
     case 1:
        Obj1.create();
        break;
     case 2:
        Obj1.add();
        break;
     case 3:
        Obj1.del();
        break;
     case 4:
        Obj1.display();
        break;
     default:
        cout<<"\n\tInvalid option Selected, Please try Again\n";
        break;
    }
    cout<<"\nTo continue with this Queue operations, Press Y/y: ";
    cin>>ans;
    cout<<endl;
    }while(ans == 'y' || ans == 'Y');
return 0;
}


