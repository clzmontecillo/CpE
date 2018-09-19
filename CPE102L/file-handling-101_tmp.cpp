#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	// Declare file identifier
	std::ifstream employeeData;
	// Open the file
	employeeData.open("employeeData.dat");
	// Verify if the file is open
	/*
		if(employeeData.is_open()){ 
			// output
		};
	*/
	//std::cout << employeeData.is_open();
	// Declare Three Variables
	string name = "Pochi";
	string address = "Manila";
	float payrate;
	char str[50];
	
	while(!employeeData.eof()){
		employeeData.getline(str, 50, ';');
		std::cout << str << std::endl;
		employeeData.ignore(255, '\n');
	}
	
	//std::cout << "\nFile Handling";
	return 0;	
}
