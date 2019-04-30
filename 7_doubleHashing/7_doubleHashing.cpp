#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;
int hashTable[TABLE_SIZE] ={0};

void addInTable(){
    int key;
    bool isPlaced = false;
    cout<<"Enter the key to be inserted in the table : ";
    cin>>key;
    int Hash1 = key % TABLE_SIZE;
    int Hash2 = 7 - (key % 7);
    if(hashTable[Hash1] == 0){
        hashTable[Hash1] = key;
        isPlaced = true;
    }
    else if(hashTable[Hash2] == 0){
        hashTable[Hash2] = key;
        isPlaced = true;
    }
    else{
        for(int i = 0;i<TABLE_SIZE; i++){
            if(hashTable[Hash1 + (i*Hash2)] == 0){
                hashTable[Hash1 + (i*Hash2)] = key;
                isPlaced = true;
            }
        }
    }
    if(!isPlaced){
        cout<<"The number is not inserted as array is full."<<endl;
    }
}

void displayTable(){
    for(int i = 0; i<TABLE_SIZE; i++){
        cout<<i<<": "<<hashTable[i]<<endl;
    }
    cout<<endl;
}

int main()
{
    int choice,n;
    char ch = 'y';
    while(ch=='y' || ch=='Y')
    {
        cout<<"********MENU********"<<endl;
        cout<<"1) Insert in Hash Table"<<endl;
        cout<<"2) Display Hash Table"<<endl;
        cout<<"Enter the choice: ";
        cin>>choice;
        switch(choice){
        case 1 :
            cout<<"Enter the no. of elements to be added: ";
            cin>>n;
            while(n != 0)
            {
                addInTable();
                n--;
            }
            break;
        case 2: displayTable();
            break;
        default: cout<<"Wrong choice "<<endl;
        }
        cout<<"Do you want to continue? (y/n): ";
        cin>>ch;
    }
    return 0;
}

