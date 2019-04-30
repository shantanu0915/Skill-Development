#include <iostream>
#include<cstring>
#include<fstream>

using namespace std;

class Student{
private:
    char name[30], div, address[100];
    int rollNo;
public:
    Student(){
    }
    Student(char name[30],int rollNo,char div,char address[100])
    {
        strcpy(this->name, name);
        this->rollNo = rollNo;
        this->div = div;
        strcpy(this->address, address);
    }
    Student(Student &s2){
        cout<<"I am here.."<<endl;
        strcpy(name,s2.name);
        rollNo = s2.rollNo;
        div = s2.div;
        strcpy(address,s2.address);

    }
    int getRollNo(){ return rollNo;}
    void displayStudentData(){
        cout<<"Name: "<<this->name<<endl;
        cout<<"Roll No: "<<this->rollNo<<endl;
        cout<<"Division: "<<this->div<<endl;
        cout<<"Address: "<<this->address<<endl<<endl;
    }
};

void addStudentToFile(){
    char name[30], div, address[100];
    int rollNo;
    cout<<"Enter students Information : "<<endl;
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter roll no: ";
    cin>>rollNo;
    cout<<"Enter division: ";
    cin>>div;
    cout<<"Enter address: ";
    cin>>address;
    Student s(name, rollNo, div, address);

    ofstream outstream;
    outstream.open("students.txt", ios::app);
    outstream.write((char*)&s, sizeof(s));
}

void searchStudentFromFile(){
    cout<<"......Search........"<<endl;
    cout<<"Roll No. : ";
    int rollNo;
    cin>>rollNo;

    ifstream inStream;
    inStream.open("students.txt", ios::in);
    Student s,s2;
    inStream.read((char*)&s, sizeof(s));

    while(!inStream.eof()){
        if(s.getRollNo() == rollNo){
            s2 = s;
            break;
        }
        inStream.read((char*)&s, sizeof(s));
    }
    if(s2.getRollNo() == rollNo){
        s2.displayStudentData();
    }
    else{
        cout<<"Student is not found."<<endl;
    }

}


int main()
{
    int choice;
    char ch = 'y';
    while(ch=='y' || ch=='Y')
    {
        cout<<"********MENU********"<<endl;
        cout<<"1) Add Student"<<endl;
        cout<<"2) Search Student"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1 :
                addStudentToFile();
                break;
            case 2 :
                searchStudentFromFile();
                break;
            default :
                cout<<"Wrong Input!!"<<endl;
        }
        cout<<"Do you want to continue? (y/n): ";
        cin>>ch;
    }

    return 0;
}

