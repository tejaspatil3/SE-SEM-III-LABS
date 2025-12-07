#include <iostream>
#include <string.h>

using namespace std ;
struct node
{
    char lable[20];
    int ch_count;
    struct node *child[10];
}*root;

class GT
{
    public:
    GT()
    {
        root=NULL;
    }
    void create_tree();
    void display_tree(node *r);
};

void GT::create_tree()
{
    int tbook,tchapter,i,j,k,l;
    root=new node;
    cout<<"Enter the name of the book=";
    cin>>root->lable;
    cout<<"Enter Number of Chapter=";
    cin>>root->ch_count;
    tchapter=root->ch_count;
    for(i=0;i<tchapter;i++)
    {
        root->child[i]=new node;
        cout<<"Enter Chapter "<<i+1<<" name =\n";
        cin>>root->child[i]->lable;
        cout<<"Enter Number of Section in the Chapter=";
        cin>>root->child[i]->ch_count;
        for(j=0;j<root->child[i]->ch_count;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"Enter Section "<<j+1<<" name =\n";
            cin>>root->child[i]->child[j]->lable;
        }
    }
}

void GT::display_tree(node *r1)
{
    int i,j,k,tchapter;
    if(r1!=NULL)
    {
        cout<<"\n------------Book Hierarchy------------";
        cout<<"\n Book Title:" <<r1->lable<<endl;
        tchapter=r1->ch_count;
        for(i=0;i<tchapter;i++)
        {
            cout<<"\n Chapter "<<i+1<<" :";
            cout<<r1->child[i]->lable;
            cout<<"\n Section: \n";
            for(j=0;j<r1->child[i]->ch_count;j++)
            {
                cout<<" "<<r1->child[i]->child[j]->lable<<endl;
            }
        }
    }
}
int main()
{
    int choice;
    GT gt;
    while(1)
    {
        cout<<"--------------------"<<endl;
        cout<<"Book Tree Creation"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Quit"<<endl;
        cout<<"Enter the choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            gt.create_tree();
            break;

        case 2:
            gt.display_tree(root);
            break;

        case 3:
            exit(1);

        default:
            cout << "Wrong Choice....!!!"<<endl;
        }
    }
}