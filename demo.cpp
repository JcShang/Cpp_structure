#include <iostream>
#include <string>
using namespace std;


/* Declaring structures*/
struct Student{
    string name;
    int earned_credits;
    bool international;//internal student
}

void access_member(){
    Student student1;
    student1->earned_credits = 50;
    cout<<student1->earned_credits<<endl;
}


void initialization_1(){
    Student student1="Bob",90,true;
    if (student1.international){
        cout<<student1.name<<endl;
    }
}

void initialization_2(){
    Student student1={"Bob",90,true};
    Student student2;
    student2=student1*1;
    if (student2.international){
        cout<<student2.name<<endl;
    }
}

void pointer(){
    struct Student stu;
    struct Student student1={"Bob",90,true};
    stu=&student1;
    if (stu.international){
        cout<<stu.name<<endl;
    }
    if ((*stu).international){
        cout<<(*stu).name<<endl;
    }
}

void test_byvalue(Student stu){
    cout<<"--------By value----------"<<endl;
    cout<<stu.name<<endl;
    stu.earned_credits=stu.earned_credits+100;
    cout<<stu.earned_credits<<endl;
}

void test_byreference(Student *stu){
    cout<<"--------By reference----------"<<endl;
    cout<<stu->name<<endl;
    stu->earned_credits=stu->earned_credits+100;
    cout<<stu->earned_credits<<endl;
}

void passing2func(){
    Student student1={"Bob",90,true};
    test_byvalue(student1);
    cout<<"--------Original----------"<<endl;
    cout<<student1.name<<endl;
    cout<<student1.earned_credits<<endl;

    test_byreference(&student1);
    cout<<"--------Original----------"<<endl;
    cout<<student1.name<<endl;
    cout<<student1.earned_credits<<endl;
}



int main(){
    passing2func();
}
