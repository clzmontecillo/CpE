#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	// Declare File Identifier
	std::ifstream employeeData;
	// Open the File
	employeeData.open("employeeData.dat");
		/* absence of employeeData.dat file leads to a segmentation fault */
	// Declare Variables
	std::string address[255];
	std::string payrate[50];
	char str[50];
	char addr[255];
	char pay[20];
	int numOfEmp = 0;
	std::string name[50];
	std::cout	<< setw(0) << "Name"
			 	<< setw(35) << "Address"
				<< setw(50) << "Payrate\n";
	std::cout << "_________________________________________________________________________________________________________________\n\n";
	// Fetch Entries
	while(!employeeData.eof()){
		employeeData.getline(str,50,';');
		name[numOfEmp] = str;
		employeeData.getline(addr,255,';');
		address[numOfEmp] = addr;
		employeeData.getline(pay,50,'\n');
		payrate[numOfEmp] = pay;
		//std::cout << name[numOfEmp] << setw(60) << address[numOfEmp] << payrate[numOfEmp] <<  endl;
		printf("%s %60s %40s \n", str, addr, pay);
		numOfEmp++;
	}
	return 0;
}
