#include <iostream>
#include <string.h>
using namespace std;

class Point {
	private:
	  int x;
	  int y;
	  char * color; 
	
	public: 
	  Point (int a,int b,char * c):x(a),y(b){
	  	  if(c== NULL){
	  	  	    c = "black";
			}
		  color = new char[strlen(c)+1];
		  strcpy(color,c); 
	  }
	  
	  // Copy Constructor...
	  
	  
	  
	  
	  ~Point(){
	  	 cout<<"deleting point..."<<endl;
	  	 delete [] color;
	  }
	  void set(int a,int b,char*c);
      void show();
};	

	void Point::set(int a,int b,char * c){
	  x=a;
	  y=b;
	  if(c!= NULL){
	  	delete [] color;
	  	color = new char[strlen(c)+1];
		strcpy(color,c); 
	  }
		  
   }

   void Point::show(){
	cout<<"("<<x<<","<<y<<"),color="<<color<<endl;
    }


int main(){
	Point p1(3,4,"red");
	Point p2 = p1;
	p1.show();
	p2.show();
	p2.set(0,0,"blue");
	p1.show();
	p2.show();
}
