#include <iostream>

using namespace std;

class Point {
	private:
	  int x;
	  int y;
	  char * color; 
	
	public: 
	  //constructor
	  
	  
	  // destructor
	  
	  void set(int a,int b,char*c); //redefine set 
      void show();//redefine set 
};	

	void Point::set(int a,int b){
	  x=a;
	  y=b;
   }

   void Point::show(){
	cout<<"("<<x<<","<<y<<")"<<endl;
    }


int main(){
	Point p1(3,4,"red");
	p1.set(0,0,"blue");
	p1.show();
}
