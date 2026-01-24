#include <iostream>
using namespace std;

class Student {
    string name;
    int roll;
    string course;
    int reg_no;

    public:
    Student() {
        cout<<"Default constructor: Hello Student!"<<endl;
    }

    Student(string name, int roll, string course, int reg_no) {
        this->name = name;
        this->roll = roll;
        this->course = course;
        this->reg_no = reg_no;
    }

    void display() {
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No.:"<<roll<<endl;
        cout<<"Course: "<<course<<endl;
        cout<<"Reg. No.: "<<reg_no<<endl;
    }
};

int main() {
    Student std1("Shraddha", 20, "CSE", 12304195);  //static (stack) memory allocation
    std1.display();

    Student *std2 = new Student("Amit", 19, "BCA", 12345678);   //dynamic (heap) memory allocation
    std2->display();
    delete std2;    //free the dynamic memory
}