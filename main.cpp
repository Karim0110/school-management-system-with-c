#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "student.h"
#include "staff.h"
#include "result.h"
#include "fee.h"
using namespace std;

int main()
{
    int choice;
    for(;;)
    {
            cout <<endl<<endl;
            cout << "\t\t\t\t Welcome To The School system"<< endl<<endl; // greeting the user
            cout << "1. Student Info"<< endl;                     // choices for the end user 
            cout << "2. Staff Info"<< endl;
            cout << "3. Results System"<< endl;
            cout << "4. Fees System"<< endl;
            cout << "5. Exit"<< endl;                     //an option to terminate program 
            cout << "Enter your choice (in numbers ):"<< endl;
            cin>>choice;
            switch(choice)                         // switch statement to control the different options of the program 
            {
                case 1:
                            int studentC;
                            cout <<endl;
                            cout << " Welcome To The Student Portal "<< endl;
                            cout << "1. New Registration"<< endl;
                            cout << "2. Update student info"<< endl;
                            cout << "3. Delete student info"<< endl;
                            cout << "4. List All students"<< endl;
                            cout << "5. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>studentC;
                            switch(studentC)
                            {
                                case 1:                                //start of the function calls for each case 
                                    newStudentRegistration();
                                    break;
                                case 2:
                                    updateStudentInform();
                                    break;
                                case 3:
                                    deleteStudentInform();
                                    break;
                                case 4:
                                    listOfStudents();
                                    break;
                                case 5:exit(0);
                                break;
                                default:
                                        cout<<"error , please try another input ";
                            }
                    break;
                case 2:
                            int staffC;

                            cout <<endl;
                            cout << " Welcome Staff Members !! "<< endl;
                            cout << "1. New Registration"<< endl;
                            cout << "2. Update staff info"<< endl;
                            cout << "3. Delete staff info"<< endl;
                            cout << "4. List All staff Members"<< endl;
                            cout << "5. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>staffC;
                            switch(staffC)
                            {
                            case 1:
                                newStaffRegistration();
                                break;
                            case 2:
                                    updateStaffInform();
                                    break;
                            case 3:
                                    deleteStaffInform();
                                    break;
                            case 4:
                                    listOfStaffs();
                                    break;

                            case 5:exit(0);
                            break;
                            default:
                                    cout<<"error , please try another input";
                            }
                    break;

                case 3:
                            int resultC;
                            cout <<endl;
                            cout << " Welcome To The Results Managment system "<< endl;
                            cout << "1. Add Result "<< endl;
                            cout << "2. Update Result"<< endl;
                            cout << "3. Delete Result"<< endl;
                            cout << "4. Overall class Result"<< endl;
                            cout << "5. School Annual Report"<< endl;
                            cout << "6. Student Result"<< endl;
                            cout << "7. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>resultC;
                            switch(resultC)
                            {
                            case 1:
                                    newResultAdd();
                                    break;
                            case 2:
                                    updateResultAdd();
                                    break;
                            case 3:
                                    deleteResult();
                                    break;
                            case 4:
                                    overAllClassResult();
                                    break;
                            case 5:
                                    schoolResult();
                                    break;
                            case 6:
                                    studentResult();
                                    break;
                            case 7:exit(0);
                                break;
                                default:
                                        cout<<"error , please try another input";
                            }
                    break;
                case 4:
                            int feeC;
                            cout <<endl;
                            cout << " Welcome To The Student Fees System  "<< endl;
                            cout << "1. Add New Fee"<< endl;
                            cout << "2. Update Fee Info"<< endl;
                            cout << "3. Delete Fee info"<< endl;
                            cout << "4. List All Fees"<< endl;
                            cout << "5. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>feeC;
                            switch(feeC)
                            {
                                case 1:
                                    addFee();
                                    break;
                                case 2:
                                    updateFee();
                                    break;
                                case 3:
                                    deleteFee();
                                    break;
                                case 4:
                                    listAllFees();
                                    break;
                                case 5:
                                    exit(0);
                                    break;
                                default:
                                    cout<<"error , please try another input";
                            }
                            break;
                case 5:exit(0);
                        break;
                default:cout<<"error , please try another input";
            }
    }
    return 0;
}
