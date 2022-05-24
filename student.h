#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<vector>
#include <iomanip>
#include <iterator>
using namespace std;

typedef struct student
{
	string ID;
	string FName;
	string LName;
	string MNumber;
	string Class;
	string line;
	
};

void newStudentRegistration(){
	string FName, LName, ID , MNumber, Class;

fstream outfile ("studentInfo.txt",ios::app);
student s1;
cout<< "Enter your First name \n";
cin>>  FName;
cout<< "Enter your Last name \n";
cin>> LName;
cout<< "Enter your Id number \n";
cin >>ID;
cout<< "Enter your Mobile number \n";
cin>> MNumber;
cout<<"Enter your class group";
cin>>Class;
outfile<<  FName<< " "<<LName<<" "<<ID<<" "<<MNumber<<endl;
cout<< "\n *Successfully added* \n"; 
outfile.close();
}
void updateStudentInform() {
	string FName, LName, ID, MNumber, Class, line;
	cout << "\n Enter student ID \n";
	cin >> ID;
	student s1;
	fstream infile("studentInfo.txt");
	fstream tempfile("tempInfo.txt", ios::app);

	while (std::getline(infile, line))
	{
		istringstream ss(line);
		std::istream_iterator<std::string> begin(ss), end;
		//putting all the tokens in the vector
		std::vector<std::string> arrayTokens(begin, end);

		vector<string>::iterator it;
		int i = 0, flag = 0;
		for (it = arrayTokens.begin(); it != arrayTokens.end(); it++)
		{
			if (i == 0 && ID == *it)
			{
				flag = 1;
			}
			else
				break;
			i++;
		}
	if (flag == 1)
	{
		cout << "Enter your First name \n";
		cin >> FName;
		cout << "Enter your Last name \n";
		cin >> LName;
		cout << "Enter your Id number \n";
		cin >> ID;
		cout << "Enter your Mobile number \n";
		cin >> MNumber;
		cout << "Enter your class group";
		cin >> Class;
		tempfile << FName << " " << LName << " " << ID << " " << MNumber << endl;

		cout << "\n *Successfully added* \n";
	}
	else
	{
		tempfile << line << endl;
	}
}
		infile.close();
		tempfile.close();
		remove ("studentInfo.txt");
		rename ("tempInfo.txt","studentInfo.txt");
}
void deleteStudentInform() {
	string ID;
	int update;
	cout << "Enter Student Registration ID";
	cin >> ID;
	student s1;
	string line;
	fstream infile("studentInfo.txt");
	fstream tempfile("tempInfo.txt,ios::app");

	
	
	while (getline(infile, line))
	{
		istringstream ss(line);
		std::istream_iterator<std::string> begin(ss), end;
		//putting all the tokens in the vector
		std::vector<std::string> arrayTokens(begin, end);

		vector<string>::iterator it;
		int i = 0, flag = 0;
		for (it = arrayTokens.begin(); it != arrayTokens.end(); it++)
		{
			if (i == 0 && ID == *it)
			{
				flag = 1;
			}
			else
				break;
			i++;
		};
	if (update != 1)
	{
		tempfile << line << endl;
	}
	else
	{
		cout << "\n\n **Deleted Successfully **\n";
	}
}
		infile.close();
		tempfile.close();
		remove ("studentInfo.txt");
		rename ("tempInfo.txt","studentInfo.txt");
}

	void listOfStudents()
{ 
	fstream file ("studentInfo.txt");
student s1;
cout<<endl<<"\t\t\t\t!STUDENT LIST **!\t\t\n\n\n";
cout<<setw(15)<<"ID"<<setw(15)<<"FName"<<setw(15)<<"LName"<<setw(15)<<"MNumber"<<endl<<endl;
	}