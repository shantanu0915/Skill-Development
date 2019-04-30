#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cities,paths = 0,c1,c2,time;
    char ch = 'y';
    cout<<"Enter the no. of cities: ";
    cin>>cities;
    int g[cities][cities];
    string cityName[cities];

    for(int i=0;i<cities;i++)
    {
        for(int j=0;j<cities;j++)
        {
            g[i][j] = 0;
        }
        cout<<"Enter the name of city "<<i+1<<": ";
        cin>>cityName[i];
    }
    while(ch == 'y')
    {
        cout<<"Enter the two cities with path "<<paths+1<<": "<<endl;
        cin>>c1>>c2;
        cout<<"Enter the time required: ";
        cin>>time;
        g[c1][c2] = time;
        g[c2][c1] = time;
        paths++;
        cout<<"Do you wish to enter more paths (y/n): ";
        cin>>ch;
    }
    for(int i=0;i<cities;i++)
    {
        cout<<"For city "<<cityName[i]<<": "<<endl;
        for(int j=0;j<cities;j++)
        {
            cout<<cityName[j]<<": "<<g[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
