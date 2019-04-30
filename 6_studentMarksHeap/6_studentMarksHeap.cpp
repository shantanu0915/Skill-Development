#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Tree
{
    int maxHeap[50];
    int maxSize;
    int minHeap[50];
    int minSize;
    public:

        Tree()
        {
            maxSize = 0;
            minSize = 0;
        }

        void maxHeapify(int nodeIndex)
        {
            int parentIndex,temp;
            parentIndex = (nodeIndex-1)/2;
            if(maxHeap[nodeIndex]>maxHeap[parentIndex])
            {
                temp = maxHeap[nodeIndex];
                maxHeap[nodeIndex] = maxHeap[parentIndex];
                maxHeap[parentIndex] = temp;
                maxHeapify(parentIndex);
            }
        }

        void insertMaxHeap(int data)
        {
            maxSize++;
            maxHeap[maxSize-1] = data;
            maxHeapify(maxSize-1);
        }

        void minHeapify(int nodeIndex)
        {
            int parentIndex,temp;
            parentIndex = (nodeIndex-1)/2;
            if(minHeap[nodeIndex]<minHeap[parentIndex])
            {
                temp = minHeap[nodeIndex];
                minHeap[nodeIndex] = minHeap[parentIndex];
                minHeap[parentIndex] = temp;
                minHeapify(parentIndex);
            }
        }

        void insertMinHeap(int data)
        {
            minSize++;
            minHeap[minSize-1] = data;
            minHeapify(minSize-1);
        }

        int getMaxMarks()
        {
            return maxHeap[0];
        }
        int getMinMarks()
        {
            return minHeap[0];
        }
};

int main()
{
    int student[50],n;
    Tree tree;
    cout<<"Enter the no. of students: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter marks for student "<<i+1<<": ";
        cin>>student[i];
        tree.insertMaxHeap(student[i]);
        tree.insertMinHeap(student[i]);
    }
    cout<<"The maximum marks is: "<<tree.getMaxMarks()<<endl;
    cout<<"The minimum marks is: "<<tree.getMinMarks();
    return 0;
}
