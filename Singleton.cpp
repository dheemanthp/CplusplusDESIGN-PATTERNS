//In C++, "static" applies to member functions and data members of classes.
//A static data member is also called a "class variable", 
//while a non - static data member is an "instance variable".This is Smalltalk terminology.
//This means that there is only one copy of a static data member shared by all objects of a class, 
//while each object has its own copy of a non - static data member.So a static data member 
//is essentially a global variable, that is a member of a class.
//
//Non - static member functions can access all data members of the class :
//static and non - static.Static member functions can only operate on the static data members.
//
//One way to think about this is that in C++ static data members and static member
//functions do not belong to any object, but to the entire class.

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SINGLETON DESIGN PATTERN:This design pattern and methodology ensures that only one instance of the C++ class is instantiated.
// WHOLE IDEA
/////////////
//we create one and only one instance , 
//1)by ensuring all the constructors and assignment operators are private , which means it can never be called outside the class
//2)by having a static class pointer member , and a static function to access that member and also call the constructor

//PROBLEMS WITH SINGLETON
/////////////////////////
//1)global variable
//2)Lazy initialization takes control away from you
//3)They encourage coupling
//4)They aren’t concurrency - friendly
//5)Static local variables break concurrent execution
//Reentrant functions – functions that can be called from
//multiple concurrent threads of execution
//Static state must be guarded with mutexes, or function will
//not generate correct results
//(For reentrant functions, better to just avoid static state!)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;

//singleton class
typedef class singleton{


private:
	//make all the constructors private , so that no constructors can be called
	//private constructor
	singleton(){
		cout << "private constructor called" << endl;
	}
	//make destructor private too , dont want any caller to get instance and destroy the object
	~singleton(){
		delete instance;
	}
	//private copy constructor implement , so that default copy constructor from compiler is avoided
	singleton(singleton const&){
	
	}
	//private Assignment operator
	singleton& operator=(singleton const&){
	
	};
	//Static member
	static singleton* instance;
public:
	//only this function can call constructor , public access to constructor is denied
	// this function has to be static , otherwise to call this function , we would have to create object
	static singleton* getinstance();

	
}SINGLETON;





// Global static pointer used to ensure a single instance of the class.
SINGLETON* SINGLETON::instance = NULL;

singleton* SINGLETON::getinstance(){
	//if no istance is created , create a new instance
	if (!instance){
		cout << "CREATING OBJECT first time" << endl;
		instance = new SINGLETON();
		return instance;
	}
	else{
		return  NULL;
	}
}


int main(){
	SINGLETON* obj;
	//call the static getter function  , creates a new object
	obj = singleton::getinstance();
	cout <<"1st object"<<obj << endl;//print the pointer value

	SINGLETON* obj1;
	//call the static getter function , and returns NULL
	obj1 = singleton::getinstance();
	cout <<"2nd object"<< obj1 << endl;//print the pointer value

	getchar();
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
//Improvments suggested here:
//1)Avoid having a static member
//2)http://courses.cms.caltech.edu/cs11/material/advcpp/lectures/cs11-advcpp-lec9.pdf
//3)http://preshing.com/20130930/double-checked-locking-is-fixed-in-cpp11/
//4)http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
//5)http://gameprogrammingpatterns.com/singleton.html
