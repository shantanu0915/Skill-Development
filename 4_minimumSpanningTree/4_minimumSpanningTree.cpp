#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minKey(int key[], bool mstSet[], int vertices)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int main()
{
    int edges = 0,v1,v2,weight,vertices;
    char ch = 'y';
    cout<<"Enter the no. of vertices: ";
    cin>>vertices;
    int g[vertices][vertices];
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            g[i][j] = 0;
        }
    }
    while(ch == 'y')
    {
        cout<<"Enter the two vertices with edge "<<edges+1<<": "<<endl;
        cin>>v1>>v2;
        cout<<"Enter the weight required: ";
        cin>>weight;
        g[v1][v2] = weight;
        g[v2][v1] = weight;
        edges++;
        cout<<"Do you wish to enter more edges (y/n): ";
        cin>>ch;
    }
    int parent[vertices],key[vertices];
    bool mstSet[vertices];
    for (int i = 0; i < vertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < vertices-1; count++)
    {
        int u = minKey(key, mstSet,vertices);
        mstSet[u] = true;
        for (int v = 0; v < vertices; v++)
        if (g[u][v] && mstSet[v] == false && g[u][v] < key[v])
            parent[v] = u, key[v] = g[u][v];
    }
    cout<<"Edge: Weight"<<endl;
    for(int i=1;i<vertices;i++)
    {
        cout<<parent[i]<<"-"<<i<<": "<<g[i][parent[i]]<<endl;
    }
    return 0;
}
