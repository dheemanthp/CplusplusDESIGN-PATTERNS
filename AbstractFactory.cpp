//Abstract Factory


//Mobile Factory(Class used to create Mobile Objects)
//Mobile(Abstract Base Class)
//Mobile High End (Dervied Class)
//Mobile Low  End (Dervied class)






#include<iostream>
#include<string>

using namespace std;

//Mobile Abstract Base Class: Has 2 Pure virtual functions
//Abstract class cannot have any objects , but we 
//can make use of the polymorphic abilities
//

typedef class Mobile{
public:
	virtual string camera() = 0;
	virtual string keyboard() = 0;
	//Depending on the type of object , specific virtual function implementation will be called
	void print(){
		cout << camera() << endl;
		cout << keyboard() << endl;
	}
	//Virtual destructor:Base class destructor is virtual
	virtual ~Mobile(){

	}
}M;

//publically inherit
typedef class MobileLowEnd:public M{
public:
	string camera(){
		return ("Camera Low End");
	}
	string keyboard(){
		return ("Keyboard Low End");
	}
	//~MobileLowEnd(){
	//	delete this;
	//}

}MLE;

//publically inherit
typedef class MobileHighEnd:public M{
	string camera(){
		return ("Camera High End");
	}
	string keyboard(){
		return ("Keyboard High End");
	}
	//~MobileHighEnd(){
	//	delete this;
	//}
}MHE;

//Factory class which can create Mobiles , depending on the type of string passed
typedef class MobileFactory{

public:
	M * create_mobiles(string type){
		//Depending the type of informartion passed, a mobile object is returned
		if (type == "MLE") return(new MLE());
		if (type == "MHE") return(new MHE());
		else throw("Cannot create objects");
	}
}MF;


int main(){
	MF *mfobj = new MF();
	//Create 3 mobile Objects
	try{
		M  *mobileobj1 = mfobj->create_mobiles("MLE");
		mobileobj1->print();
		M  *mobileobj2 = mfobj->create_mobiles("MHE");
		mobileobj2->print();
		M  *mobileobj3 = mfobj->create_mobiles("MLE");
		mobileobj3->print();
		//since we are trying to delete using Base Class pointer
		//we will need to make base class destructor as virtual
		//so that the derived class destructor is called
		//if we do not make the base class destructor as virtual then
		//the derived class destructor will never be called
		delete mobileobj1;
		delete mobileobj2;
		delete mobileobj3;

	}
	catch (string e){
		cout << "Try Creating valid objects" << endl;
	}


	//Can also Create Mobile objects in an other way
	M  *mobileobj4 = new MLE();
	mobileobj4->print();
	M  *mobileobj5 = new MHE();
	mobileobj5->print();
	delete mobileobj4;
	delete mobileobj5;

	getchar();
	return 0;
}

