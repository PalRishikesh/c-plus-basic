#include<iostream>
using namespace std;

class Student{
    public:
    int rollNo;
    // void print(){
    //     cout<<"Roll no. = "<<rollNo;
    // }
      void print(); // use :: out side the class
        void fun();
        void fun2();
        void add();

        Student(){
            cout <<"Constrouctor called"<<endl;
        }
        Student(int rollNo){
            this->rollNo = rollNo;
            cout <<"Parameter Constrouctor called: "<<endl;
        }

        // copy constr
        Student(Student &obj){
            rollNo = obj.rollNo;
        }

};

void Student::print(){
    cout << "Roll No :: ="<<rollNo<<endl;
}
void Student::fun(){
    cout << "Fun ";
}
void Student::fun2(){
    cout << "Fun 3";
}
void Student::add(){
    cout << "Add";
}
int main(){
    // Student obj1;
    // obj1.rollNo = 11;
    // obj1.print();


    // Creating pointer to the object or new key word have to use ->
    // Student *objP;
    // objP->rollNo = 12;
    // objP->print();

    // Student s; // constructor is called
    
    // copy

    Student obj1(50);
    obj1.print();

    Student obj2(obj1);
    obj2.print();
    return 0;
    
}