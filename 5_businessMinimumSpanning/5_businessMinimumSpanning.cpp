#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minKey(int key[], bool mstSet[], int cities)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < cities; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int main()
{
    int edges = 0,c1,c2,weight,cities,total = 0;
    char ch = 'y';
    cout<<"Enter the no. of cities: ";
    cin>>cities;
    string name[cities];
    for(int i=0;i<cities;i++)
    {
        cout<<"Enter the name of the cities: ";
        cin>>name[i];
    }
    int g[cities][cities];
    for(int i=0;i<cities;i++)
    {
        for(int j=0;j<cities;j++)
        {
            g[i][j] = 0;
        }
    }
    while(ch == 'y')
    {
        cout<<"Enter the two cities with edge "<<edges+1<<": "<<endl;
        cin>>c1>>c2;
        cout<<"Enter the weight required: ";
        cin>>weight;
        g[c1][c2] = weight;
        g[c2][c1] = weight;
        edges++;
        cout<<"Do you wish to enter more edges (y/n): ";
        cin>>ch;
    }
    int parent[cities],key[cities];
    bool mstSet[cities];
    for (int i = 0; i < cities; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < cities-1; count++)
    {
        int u = minKey(key, mstSet,cities);
        mstSet[u] = true;
        for (int c = 0; c < cities; c++)
        if (g[u][c] && mstSet[c] == false && g[u][c] < key[c])
            parent[c] = u, key[c] = g[u][c];
    }
    cout<<"Edge: Weight"<<endl;
    for(int i=1;i<cities;i++)
    {
        cout<<name[parent[i]]<<"-"<<name[i]<<": "<<g[i][parent[i]]<<endl;
        total = total + g[i][parent[i]];
    }
    cout<<"The total cost is : "<<total<<endl;
    return 0;
}

