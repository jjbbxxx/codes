#include <iostream>
using namespace std;

class Date {
   public:                  
     Date(int m,int d,int y):month(m),day(d),year(y){ }
     void print()const
	 {
     	cout<<month<<" "<<day<<" "<<year<<endl;
	 }                       
  private:
     int month;
     int day;
     int year;
};
//Please correct the errors in the program below.
//Don't modify the class of Date and main().     
class Student{
 public:
      Student(int id,char s,int d,int m,int y)
	  {
	  	sex = s;
		id = studentID; 
	  }                            
      void print()const;
private:
    char sex;
    int studentID;
    Date birthday;
    const char sex; 
};
void Student::print()const{
    cout<<birthday.month<<" "<<birthday.day<<" "<<birthday.year<<endl;
    cout<<"ID="<<studentID<<endl;
}

int main(){
	Student s1(123,'M',22,3,1999);
	s1.print();
}

