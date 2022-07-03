#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Student
{
public:
    string first_name;
    string last_name;
    string mobile_number;
};

class Academic_info : public Student
{
public:
    string course;
    float tenth_mark;
    float Entrance_mark;
};

int main()
{
    int input = 0;
    Academic_info stu;
    string str;
    while (input != 3)
    {
        cout << "\t\t====== STUDENT DATABASE MANAGEMENT SYSTEM ======";
        cout << "\n\n                                          ";
        cout << "\n \t\t\t 1. Add   Student  Records";
        cout << "\n \t\t\t 2. List  Student  Records";
        cout << "\n \t\t\t 3. Exit  Program";
        cout << "\n\n";
        cout << "\t\t\t Select Your Choice :=> ";
        cin >> input;

        switch (input)
        {
        case 1:
            cout << "Enter Student's First Name: ";
            cin >> stu.first_name;
            cout << "Enter Student's Last Name: ";
            cin >> stu.last_name;
            cout << "Enter your Mobile Number: ";
            cin >> stu.mobile_number;
            cout << "Enter the couse you want to be registered in: ";
            cin >> stu.course;
            cout << "Enter 10th marks(%): ";
            cin >> stu.tenth_mark;
            cout << "Enter Entrance marks(%): ";
            cin >> stu.Entrance_mark;
            if (stu.tenth_mark >= 85 && stu.Entrance_mark >= 60)
            {
                if (stu.course[0] == 'J')
                {
                    ofstream out("JEE.txt", ios::out | ios::app);
                    out << "Student Name: " + stu.first_name + " " + stu.last_name + "\n";
                    out << "Mobile Number: " + stu.mobile_number + "\n";
                    out << "10th Marks: " << stu.tenth_mark << "%\n";
                    out << "Entrance Marks: " << stu.Entrance_mark << "%\n";
                    out << "\n";
                    out.close();
                }
                else
                {
                    ofstream out("NEET.txt", ios::out | ios::app);
                    out << "Student Name: " + stu.first_name + " " + stu.last_name + "\n";
                    out << "Mobile Number: " + stu.mobile_number + "\n";
                    out << "10th Marks: " << stu.tenth_mark << "%\n";
                    out << "Entrance Marks: " << stu.Entrance_mark << "%\n";
                    out << "\n";
                    out.close();
                }
            }
            else
            {
                if (stu.tenth_mark < 85 && stu.Entrance_mark < 60)
                {
                    cout << "Sorry your tenth marks and Entrance marks are not enough to join the institution." << endl;
                }
                else if (stu.tenth_mark < 85)
                {
                    cout << "Sorry your tenth marks are not enough to join the institution." << endl;
                }
                else
                {
                    cout << "Sorry your Entrance marks are not enough to join the institution." << endl;
                }
            }

            break;

        case 2:
            cout << "To see the details of JEE Aspirants enter J, for NEET aspirants enter N and enter B if need to see both the deails" << endl;
            char ch;
            cin >> ch;
            if (ch == 'J')
            {

                ifstream in("JEE.txt");
                while (in.eof() == 0)
                {
                    getline(in, str);
                    cout << str << endl;
                }
                cout << endl;
                in.close();
                break;
            }
            else if (ch == 'N')
            {
                ifstream in("NEET.txt");
                while (in.eof() == 0)
                {
                    getline(in, str);
                    cout << str << endl;
                }
                cout << endl;
                in.close();
                break;
            }
            else
            {
                ifstream inj("JEE.txt");
                while (inj.eof() == 0)
                {
                    getline(inj, str);
                    cout << str << endl;
                }
                cout << endl;
                inj.close();
                ifstream inn("NEET.txt");
                while (inn.eof() == 0)
                {
                    getline(inn, str);
                    cout << str << endl;
                }
                cout << endl;
                inn.close();
                break;
                break;
            }

        case 3:
            cout << "Thanks for using the program!" << endl;
            exit(0);
            break;

        default:
            cout << "You have entered invalid value please try again." << endl;
        }
    }
}