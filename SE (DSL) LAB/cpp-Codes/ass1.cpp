
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct data
{
    char name[30];
    long teleno;
};
class Hash1 {
    public:
    int n, sum, x, c, I, j;
    char na[30];
    long no;
    struct data d[];

    Hash1()
    {
        for (int i = 0; i < 10; i++)
        {
            d[i].teleno = 0;
        }
    }
void insert()
    {
        cout<< "\n enter no.of clients";
        cin>> n; // d[x].name
        for (j = 0; j < n; j++)
        {
            cout << "\n enter name of client";
            cin >> na;
            cout << "\n enter telephone no.of client";
            cin >> no;
            sum = 0;
            for (int i = 0; i < strlen(na); i++)
            {
                sum = sum + na[i];
            }
            x = (sum / strlen(na)) % 10;
            cout << x;
            c = x;
            while (1)
            {
                if (d[x].teleno == 0)
                {
                    strcpy(d[x].name, na);
                    d[x].teleno = no;
                    break;
                }
                x = (x + 1) % 10;
                if (c == x)
                {
                    cout << "\n hash table is full";
                    break;
                }
            }
  }
void search() {
        cout << "\n enter name to be searched";
        cin >> na;
        sum = 0;
        for (int i = 0; i < strlen(na); i++)
        {
            sum = sum + (int)na[i];
        }
        x = (sum / strlen(na)) % 10;
        c = x;
        while (1)
        {
            if (!strcmp(d[x].name, na))
            {
                cout << "\n data found : TELEPHONE NO : " << d[x].teleno;
                break;
            }
            x = (x + 1) % 10;
            if (c == x)
            {
                cout << "\n data not found ";
                break;
            }
        }
    }
void display()
    {
        for (int i = 0; i < 10; i++)
        {
            if (d[i].teleno != 0)
            {
                cout << endl
                     << d[i].name << " " << d[i].teleno;
            }
        }
    }
}

};

int main()
{
    Hash1 h;
    h.insert();
    h.search();
    h.display();
    return 0;
}

