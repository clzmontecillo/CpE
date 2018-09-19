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
	//std::string name;
	std::string address;
	float payrate;
	char str[50];
	int numOfEmp = 0;
	std::string name[50];
	
	// fetch entries
	while(!employeeData.eof()){
		employeeData.getline(str, 50, ';');
		name[0] = str;			// save name to array of names
		std::cout << str << std::endl;
		employeeData.ignore(255, '\n');
		numOfEmp++;
	}
	// display names
	int i = 0;
	while(i < numOfEmp){
		std::cout << name[i] << std::endl;
		i++;
	}
	//std::cout << "\nFile Handling";
	return 0;	
}
