#include<iostream>
#include<fstream>//we use the library fstream as we can read and store information directed by the user
#include<cstdlib>  
#include<sstream>// it allow us to inturpet information in string object
#include<string>
#include<iterator>
#include<vector>
#include<iomanip>

using namespace std;

typedef struct staff   // typedef struct in a keyword used in c++ to creat  templated types
{
	string ID;
	string FIRSTname;
	string LASTname;
	string phonenumber;
	string adress;
	string qualification;
	string payment;
};

void newStaffRegistration()
{
	string ID , FIRSTname , LASTname , phonenumber,adress,qualification,payment;

	//fstream is used to read and update information from stored files in my program
	
	fstream outfile("staffInfo.txt", ios::app);
	staff s1;

		//prompt the user to enter the the staff ID
		cout << "please enter the ID of staff member requiered\n";
	cin >> ID;

	//prompt the user to enter student first and last names    
	cout << "please enter the your firt name\n";
	cin >> FIRSTname;
	cout << "please enter the your last name\n";
	cin >> LASTname;

	//prompt the user to enter their mobile number 
	cout << "please enter your phone number\n";
	cin >> phonenumber;

	//prompt the user to enter their current adress
	cout << "please enter your current adress\n";
	cin >> adress;

	//prompt the user to enter their qualification
	cout << "please enter your qualification and previous experinces\n";
	cin >> qualification;

	// prompt the user to enter their desired payment
	cout << "please enter the desired payment\n";
	cin >> payment;

	outfile << ID << FIRSTname << LASTname << phonenumber << adress << qualification << payment;
	cout << "\n**Successfuly Added**\n";
	outfile.close();

}



void updateStaffInform()
{    string ID , FIRSTname ,line, LASTname , phonenumber,adress,qualification,payment;
	string StaffID;
		//prompt the user to enter there new ID or phone number if there has been any change to them
		cout<< "Enter the Staff ID\n" << StaffID;
	cin >> StaffID;

	staff s1;
	fstream infile("registerinfo");
	fstream tempfile("tempInfo.txt", ios::app);   // the tempfile is used here to creat and open temporary files in a given file
	
	
	ifstream fileopner; // this use the function to read files stored in fstream

	fileopner.open("staffInfo.txt");

	if (fileopner.is_open())
	{

		exit(EXIT_FAILURE);    //in case the staffInfo file doesnot open

	}

	int update;

	cout << "if you want to update the staf information enter update= 1";
	cin >> update;

	if (update == 1)
	{

		cout << "please enter the your firt name\n";
		cin >> FIRSTname;

		cout << "please enter the your last name\n";
		cin >> LASTname;

		cout << "please enter your phone number\n";
		cin >> phonenumber;

		cout << "please enter your current adress\n";
		cin >> adress;

		cout << "please enter your qualification and previous experince\n";
		cin >> qualification;

		cout << "please enter the desired payment\n";
		cin >> payment;

		tempfile << ID << FIRSTname << LASTname << phonenumber << adress << qualification << payment;
		cout << "\n**Successfully updated**\n";

	}
	else
	{

		tempfile << line << endl;
	}
	infile.close();
	tempfile.close();
	remove("staffInfo.txt");
	rename("tempInfo.txt", "staffInfo.txt");
}

void deleteStaffInform()
{
	string ID , FIRSTname ,line, LASTname , phonenumber,adress,qualification,payment;

	string StaffID;
		//prompt the user to enter there new ID or phone number if there has been any change to them
		cout<< "Enter the Staff ID" << StaffID;
	cin >> StaffID;

	staff s1;
	fstream infile("registerinfo");
	fstream tempfile("tempInfo.txt", ios::app);   // the tempfile is used here to creat and open temporary files in a given file
	ifstream fileopner; // this use the function to read files stored in fstream
	fileopner.open("staffInfo.txt");

	if (fileopner.is_open())
	{

		exit(EXIT_FAILURE);    //in case the staffInfo file doesnot open

	}

	int update;

	cout << "if you want to delete the staf information enter update ";
	cin >> update;

	if (update != 1)
	{
		tempfile << line << endl;

	}
	else
	{
		cout << "\n\n **Deleted Successfully**\n";
	}
	infile.close();
	tempfile.close();
	remove("staffInfo.txt");
	rename("tempInfo.txt", "staffInfo.txt");
}

void listOfStaffs()
{
	fstream file("staffInfo.txt");
	staff s1;
	cout << endl << "\t\t\t\t !** STAFF LIST **!\t\t\n\n\n";
	cout << setw(10) << "ID" << setw(10) << "staffFIRSTname" << setw(10) << "staffLASTname" << setw(10) << "payment" << setw(10) << "qualification" << setw(10) << "mobile" << setw(10) << "adress" << endl << endl;

}