#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct result
{
	string registerID;
	string classes;
	string english;
	string science;
	string maths;
	string history;
	string geography;
};

int newResultAdd()
{
	fstream outfile("resultInfo.txt", ios::app);
	result s1;
		cout << "Registration ID: ";
		cin >> s1.registerID;
		cout << "Class Number: ";
		cin >> s1.classes;
		cout << "English: ";
		cin >> s1.english;
		cout << "Science: ";
		cin >> s1.science;
		cout << "History: ";
		cin >> s1.history;
		cout << "Geography: ";
		cin >> s1.geography;
		outfile << s1.registerID << " " << s1.classes << " " << s1.english << " " << s1.maths << " " << s1.science << " " << s1.history << " " << s1.geography << endl;
		cout << "\n**Successfully Added**\n";
		outfile.close();
		return 0;
}
int updateResultAdd()
{
	string registerID, classes;
	cout << "\n Enter Student Registration ID: \n";
	cin >> registerID;
	cout << "\n Enter Student Class: \n";
	cin >> classes;

	result s1;
	fstream infile("resultInfo.txt");
	fstream tempfile("tempInfo.txt", ios::app);
	string line;

	while (std::getline(infile, line));
	{
		istringstream ss(line);
		std::istream_iterator<std::string> begin(ss), end;
		std::vector<std::string> arrayTokens(begin, end);

		vector<string>::iterator it;
		int i = 0, flag = 0;
		for (it = arrayTokens.begin(); it != arrayTokens.end(); it++)
		{
			if (i == 0 && registerID == *it)
			{
				flag = 1;
			}
			else
				break;
			i++;
		}
		if (flag == 1)
		{
			cout << "English: ";
			cin >> s1.english;
			cout << "Maths: ";
			cin >> s1.maths;
			cout << "Science: ";
			cin >> s1.science;
			cout << "History: ";
			cin >> s1.history;
			cout << "Geography: ";
			cin >> s1.geography;
			tempfile << s1.registerID << " " << s1.classes << " " << s1.english << " " << s1.maths << " " << s1.science << " " << s1.history << " " << s1.geography << endl;
			cout << "\n**Successfully Updated**\n";
		}
		else
		{
			tempfile << line << endl;
		}
	}
	infile.close();
	tempfile.close();
	remove("resultInfo.txt");
	rename("tempInfo.txt", "resultInfo.txt");
	return 0;
}
int deleteResult()
{
	string registerID, classes;
	cout << "\n Enter Student Registration ID: \n";
	cin >> registerID;
	cout << "\n Enter Student Class: \n";
	cin >> classes;

	result s1;
	fstream infile("resultInfo.txt");
	fstream tempfile("tempInfo.txt", ios::app);
	string line;

	while (std::getline(infile, line));
	{
		istringstream ss(line);
		std::istream_iterator<std::string> begin(ss), end;
		std::vector<std::string> arrayTokens(begin, end);

		vector<string>::iterator it;
		int i = 0, flag = 0;
		for (it = arrayTokens.begin(); it != arrayTokens.end(); it++)
		{
			if (i == 0 && registerID == *it)
			{
				flag = 1;
			}
			else
				break;
			i++;
		}
		if (flag != 1)
		{
			tempfile << line << endl;
		}
		else
		{
			cout << "\n\n**Successfully Deleated**\n\n";
		}
	}
	infile.close();
	tempfile.close();
	remove("resultInfo.txt");
	rename("tempInfo.txt", "resultInfo.txt");
	return 0;
}

void overAllClassResult()
{
	string classes;
	cout << "Please enter the class";
	cin >> classes;

	int Fail = 0, Pass = 0, Total = 0;
	
	ifstream file("resultinfo.txt");
	string line;
	int check_fail = 0;

	while (std::getline(file, line))
	{
		check_fail = 0;
		istringstream ss(line);
		std::istream_iterator<std::string> begin(ss), end;
		std::vector<std::string> arrayTokens(begin, end);
		vector<string>::iterator it;
		int Flag = 0, x = 0;
		for (it = arrayTokens.begin(); it != arrayTokens.end(); it++)
		{
			string p =*it;
			stringstream geek(p);
			int y = 0;
			geek >> y;
			if (Flag == 1)
			{
				if (x < 35)
				{
					check_fail = 0;
					Fail++;
					break;
				}
				else
				{
					continue;
				}
			}
			if (classes == (*it) && x == 1)
			{
				Flag = 1;
				Total++;
			}
			x++;
		}
		if (check_fail == 0 && Flag == 1)
		{
			Pass++;
		}
	}
	cout<<endl<<"\t\t\t\t !** CLASS "<<classes<<"RESULT**!\t\t\n\n\n";
	cout << "Total number of failed students: " << Fail << endl;
	cout << "Total number of Passed students: " << Pass << endl;
	cout << "Total number of students: " << Total << endl;
	cout << "School Annual result(%):" << (double)(100 * Pass) / Total << "%"; 
	cout << endl;
}

void schoolResult()
{
	int Fail = 0, Pass = 0, Total = 0;
	ifstream file("resultinfo.txt");
	string line;

	while (std::getline(file, line));
	{
		istringstream ss(line);
		std::istream_iterator<std::string> begin(ss), end;
		std::vector<std::string> arrayTokens(begin, end);
		vector<string>::iterator it;

		int Flag = 0, x = 0;
		for (it = arrayTokens.begin(); it != arrayTokens.end(); it++)
		{
			string p =* it;
			stringstream geek(p);
			int y = 0;
			geek >> y;
			if (y < 35 && x>1)
			{
				Flag = 1;
				Fail++;
				break;
			}
			x++;
		}
		if (Flag == 0)
		{
			Pass++;
		}
		Total++;
	}
	cout << "Total number of failed students: " << Fail << endl;
	cout << "Total number of Passed studets: " << Pass << endl;
	cout << "Total number of students: " << Total << endl;
	cout << "School Annual Result(%): " << (double)(100 * Pass) / Total << "%";
	cout << endl;
}

void studentResult()
{
	string registerID;
	cout << "Please enter student Reg.ID: " << endl;
	cin >> registerID;
	ifstream file("resultinfo.txt");
	string line;
	int s_result = 1;
	string r1;
	int Total = 0;

	while (std::getline(file, line))
	{
		istringstream ss(line);
		std::istream_iterator<std::string> begin(ss), end;
		std::vector<std::string> arrayTokens(begin, end);
		vector<string>::iterator it;
		int Flag = 0, x = 0;
		for (it = arrayTokens.begin(); it != arrayTokens.end(); it++)
		{
			string p =* it;
			stringstream geek(p);
			int y = 0;
			geek >> y;
			if (Flag == 1)
			{
				Total += y;
				if (y < 35)
				{
					s_result = 0;
					break;
				}
				else
				{
					continue;
				}
			}
		if (registerID == (*it) && x == 0)
		{
			Flag = 1;
			it++;
			r1 = line;
		}
		else
			break;
	}
}
cout << endl << "\t\t\t\t!** STUDENT RESULT **!\t\t\n\n\n";
cout << setw(10) << "Reg.ID";
cout << setw(10) << "Class";
cout << setw(10) << "English";
cout << setw(10) << "Maths";
cout << setw(10) << "Science";
cout << setw(10) << "History";
cout << setw(10) << "Geography";
cout << endl;
istringstream ss(r1);
std::istream_iterator < std::string> begin(ss), end;
std::vector < std:: string > arrayTokens(begin, end);

vector<string>::iterator it;
for (it = arrayTokens.begin(); it != arrayTokens.end(); it++)
{
	cout << setw(10) << *it;
}

	if (s_result == 0)
	{
		cout << "**Result is Fail**";
	}
	else
	{
		cout << "\n\n\tTotal Score-> " << Total << endl;
		cout << "\tTotal Percentage(%)->" << ((double)Total / 500) * 100 << "%" << endl;
		cout << "\t**Result is Pass**";
	}

}
