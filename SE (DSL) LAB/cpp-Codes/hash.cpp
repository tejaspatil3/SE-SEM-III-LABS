#include <iostream>
// #include<iomanip>

using namespace std;

class node
{
private:
    int data;
    node * next;
public:
    node()
    {
        data = 0;
        next = NULL;

    }
    friend class hashtab;

};
class hashtab
{
    private:
        node hashtable[21];
        
    public:
            // hashtab()
            // {
            //     for(int i=0;i<w;i++)
            //     {
            //         hashtable[i].data=0;
            //     }
            // }
    int hash(int x)
        {
            //int w;
            int address = x%10;
            return address;
        }
    void insert(int x)
        {
            int index;
            index = hash(x);
            if (hashtable[index].data==0)
            {
                hashtable[index].data = x;
            }
            else
            {
                node *pNew = new node();
                pNew-> data = x;
                pNew -> next = hashtable[index].next;
                hashtable[index].next = pNew;
            }
        }
    void search(int x)
        {   
            int flag;
            int index;
            index = hash(x);

            if(hashtable[index].data !=0)
                {
                    if(hashtable[index].data == x)
                    {
                        flag =1;
                    }
                }
            else
                {
                    node * temp = hashtable[index].next;
                    while(temp != NULL)
                    {
                        if(temp->data !=x)
                        {
                            temp = temp->next;
                        }
                    }
                }
            if(flag ==1)
            {
                cout<<"Key is Found at "<<index<<endl;
            }
            else
            {
                cout<<"Key Not Found "<<endl;
            }
        }
    void display()
    {
        cout<<"    index"<<"        "<<"data"<<endl;
        for(int i= 0; i<21;i++)
        {   //cout<< setw(5)<<i<<"  "<<hashtable[i].data;
            cout<<"    "<<i<<"      "<<hashtable[i].data<<"   ";
            node * temp = hashtable[i].next;
            while(temp != NULL)
            { 
                //cout<<setw(5)<<temp->data;
                cout<<temp->data<<"   ";
                temp = temp->next;
            }
                cout<<endl;
            
            }
    }

};

int main()
{
    
    node n;
    hashtab h;

    while(1)
    {
        cout<<" 1.Insert\n 2.Search\n 3.Display"<<endl;
        int ch ;
        
        cout<< "Enter Selcted Choice : ";
        cin>>ch;


        if (ch==1)
        {
            int n;
            cout<<"How many elements you have to insert : ";
            cin>>n;
            int key;
            
            for(int i =0;i<n;i++)
            {
                cout<<"Enter Number one By one : ";
                cin>>key;

                h.insert(key);
                }
        }

        else if (ch == 2)
        { 
            int key;
            cout<<"Enter Key : ";
            cin>>key;
            h.search(key);
        }

        else if(ch == 3)
        {
            h.display();
        }

        else
        {
            break;
        }
    }
        return 0;

}