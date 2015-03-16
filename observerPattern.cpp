//All the clients will register with the server(Singleton pattern for only server) ,
//and the server will notify the clients who are registered.
//Used Set data structure in the server to store all the clients who are registered with the server


//           client 3
//          / 
//         /
//        /
////Server ----------Client 1
//       \
//	      \
//		   \ client 2

#include<iostream>
#include<set>
using namespace std;

//Abstract Client Class
typedef class AClient{
public:
	virtual void Notify_Client() = 0;
	virtual ~AClient() {};
}C;


typedef class Server{

private:
	//static member
	static Server * instance;
	//set of clients who are registered
	set<AClient*> registered_clients;

public:
	//static function to return the status of static member
	static Server * get_instance(){
		if (instance == NULL){
			instance = new Server();
		}
		return instance;
	}

	void add_client(AClient* cli){
		registered_clients.insert(cli);
	}

	void remove_client(AClient * cli){
		registered_clients.erase(cli);
	}

	void notify_clients(){

		set<AClient *>::iterator it;

		for (it = registered_clients.begin(); it != registered_clients.end(); it++){
			//notify the clients here
			(*it)->Notify_Client();

		}
	}
}S;

Server * Server::instance = NULL;


typedef class Client :public AClient{
	Server *S1;
public:
	Client(){
		S1 = Server::get_instance();
		//add the this into Server object
		S1->add_client(this);
		
		
	}
	~Client(){
		cout << "destructor called" << endl;
		S1->remove_client(this);
	}
	void Notify_Client(){
		cout << "Client 1 notified" << endl;
	}
}C1;


int main(){
	//Server object will now be created
	Server * Sobj = Server::get_instance();
	//Create Client1
	AClient* Cobj1 = new Client();
	//Create Client2
	AClient* Cobj2 = new Client();
	//Create Client2
	AClient* Cobj3 = new Client();

	Sobj->notify_clients();
	//Call the derived destructors by making base class destructor as virtual
	delete Cobj1;
	delete Cobj2;
	delete Cobj3;

	getchar();
	return 0;

}

