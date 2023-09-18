#include<iostream>
#include<string>
#include<fstream>
#include<cstring>

using namespace std;

int adminView();
int studentView();
int studentLogin();
int checkCredentials(string userName, string password);
int getAllStudentsbyRollNo();
int deleteAllStudents();
int deleteStudentbyRollNo();
int checkListOfStudentsRegistered();
int checkPresenseCountbyRollNo();
int getListofStudentsWithTheirPresenseCount();
int registerStudent();
int markMyAttendance(string userename);
int countMyAttendance(string username);
int delay();

int delay()
{
    for(int i=0; i<3; i++)
    {
        cout<<"\nSaving Records...";
        for(int ii=0; ii<20000; ii++)
        {
            for(int iii=0; iii<20000; iii++)
            {}
        }
    }
    cout<<"Exiting Now...\n";
    for(int i=0; i<3; i++)
    {
        for(int ii=0; ii<20000; ii++)
        {
            for(int iii=0; iii<20000; iii++)
            {}
        }
    }
    return 0;
}
int adminView()
{
    int goBack=0;
    while(1)
    {
        system("cls");
        cout<<"\n1: Register a Student.\n";
        cout<<"\n2: Delete All Students Name.\n";
        cout<<"\n3: Delete Student By Roll No.\n";
        cout<<"\n4: Check List Of Student Registered by User Name.\n";
        cout<<"\n5: Check Presense Count Of Any Student By Roll No.\n";
        cout<<"\n6: Get List Of Student With Their Attendance Count.\n";
        cout<<"\n7: Go Back <-\n";

        int choice;
        cout<<"Enter Your Choice:\n";
        cin>>choice;

        switch(choice)
        {
            case 1: registerStudent();
            break;
            case 2: deleteAllStudents();
            break;
            case 3: deleteStudentbyRollNo();
            break;
            case 4: checkListOfStudentsRegistered();
            break;
            case 5: checkPresenseCountbyRollNo();
            break;
            case 6: getListofStudentsWithTheirPresenseCount();
            break;
            case 7: goBack=1;
            break;
            default: cout<<"\nInvalid choice. Enter again";
            getchar();
        }
        if(goBack==1)
        {
            break;
        }
    }
    return 0;
}
int studentLogin()
{
    system("cls");
    cout<<"\n-----------------------------------------------------------------Student Login-------------------------------------------------------------\n";
    studentView();
    delay();
    return 0;
}
int adminLogin()
{
    system("cls");
    cout<<"\n-------------------------------------------------------------------Admin Login-------------------------------------------------------------\n";
    string username;
    string password;

    cout<<"Enter User name:\n";
    cin>>username;

    cout<<"Enter Password:\n";
    cin>>password;

    if(username=="admin" && password=="admin@2")
    {
        adminView();
        getchar();
        delay();
    }
    else
    {
        cout<<"\nError! Invalid Credentials..\n";
        cout<<"Press any key for main menu.\n";
        getchar();
        getchar();
    }
    return 0;
}


int checkStudentCredentials(string username, string password)
{
    ifstream read;
    read.open("db.dat");

    if(read)
    {
        int recordFound=0;
        string line;
        string temp=username + password + ".dat";
        cout<<"File name is:\n"<<temp<<endl;
        while(getline(read, line))
        {
            if(line==temp)
            {
                recordFound=1;
                break;
            }
        }
        if(recordFound==0)
            return 0;
        else
            return 1;
    }
    else
    {
        return 0;
    }
}
int getAllStudentsbyName()
{
    cout<<"List of All Students by their Name.\n";
    cout<<"\nPress any key to continue....\n";
    getchar();
    getchar();
    return 0;
}
int getAllStudentsbyRollNo()
{
    cout<<"List of All Students by their Roll No:\n";
    cout<<"Press any key to continue...\n";
    getchar();
    getchar();
    return 0;
}
int deleteStudentbyRollNo()
{
    cout<<"Delete any student by their Roll No:\n";
    cout<<"Press any key to continue...\n";
    getchar();
    getchar();
    return 0;
}
int checkPresenseCountbyRollNo()
{
    cout<<"Check presense count of any student by Roll No:\n";
    cout<<"Press any key to continue...\n";
    getchar();
    getchar();
    return 0;
}
int checkAllPresenseCountbyRollno()
{
    cout<<"Check presense count of All Students by Roll No & Name:\n";
    cout<<"Press any key to continue...\n";
    getchar();
    getchar();
    return 0;
}
int studentView()
{
    cout<<"-------------------------------------------------------------Student Login----------------------------------------------------------------------\n";
    string username, password;
    cout<<"Enter user name:\n";
    cin>>username;

    cout<<"Enter Password:\n";
    cin>>password;

    int res=checkStudentCredentials(username, password);

    if(res==0)
    {
        cout<<"Press any key to continue...\n";
        getchar();
        getchar();
        return 0;
    }
    int goBack=0;
    while(1)
    {
        system("cls");
        cout<<"1: Mark Attendance for Today.\n";
        cout<<"2: Count my Attendance.\n";
        cout<<"0: Go Back <-\n";
        int choice;

        cout<<"Enter your Choice:\n";
        cin>>choice;

        switch(choice)
        {
            case 1: markMyAttendance(username);
            break;
            case 2: countMyAttendance(username);
            break;
            default: cout<<"Invalid choice. Enter again.\n";
            getchar();
        }
        if(goBack==1)
        {
            break;
        }
    }
    return 0;
}
int markMyAttendance(string username)
{
    cout<<"Mark Attendance for today!!";
    cout<<"Press any key to continue...\n";
    getchar();
    getchar();
    return 0;
}
int countMyAttendance(string username)
{
    cout<<"Count my Attendance for today!!\n";
    cout<<"Press any key to continue...\n";
    getchar();
    getchar();
    return 0;
}
int deleteAllStudents()
{
    cout<<"In Delete all Students!!\n";
    cout<<"Press any key to continue...\n";
    getchar();
    getchar();
    return 0;
}
int checkListOfStudentRegistered()
{
    cout<<"List of all registered students.\n";
    cout<<"Press any key to continue...\n";
    getchar();
    getchar();
    return 0;
}
int getListofStudentsWithTheirPresenseCount()
{
    cout<<"All students with their Presense count.\n";
    cout<<"Press any key to continue...\n";
    getchar();
    getchar();
    return 0;
}
int checkListOfStudentsRegistered()
{
    ifstream read;
    read.open("db.dat");

    if(read)
    {
        int recordFound=0;
        string line;
        while(getline(read, line))
        {
            char name[100];
            strcpy(name, line.c_str());
            char onlyname[100];
            strncpy(onlyname, name, (strlen(name)-4));
            cout<<"\n"<<onlyname<<endl;
        }
        read.close();
    }
    else
    {
        cout<<"No record found :("<<endl;
    }

cout<<"Press any  key to continue...\n";
getchar();
getchar();
return 0;
}
int registerStudent()
{
    cout<<"------------------------------------------------------------Form to Register-----------------------------------------------------------------\n";

    string name, username, password, rollno, address, father, mother;

    cout<<"Enter name:\n";
    cin>>name;

    cout<<"Enter User name:\n";
    cin>>username;

    cout<<"Enter Password:\n";
    cin>>password;

    cout<<"Enter Roll No:\n";
    cin>>rollno;

    getchar();

    char add[100];
    cout<<"Enter address:\n";
    cin.getline(add, 100);

    cout<<"Enter Father's name:\n";
    cin>>father;

    cout<<"Enter Mother's name:\n";
    cin>>mother;

    ifstream read;
    read.open("db.dat");

    if(read)
    {
        int recordFound=0;
        string line;
        while(getline(read, line))
        {
            if(line==username + ".dat")
            {
                recordFound=1;
                break;
            }
        }
        if(recordFound==1)
        {
            cout<<"User name already Register. Please choose another username.\n";
            getchar();
            getchar();
            return 0;
        }
    }
    read.close();

    ofstream out;
    out.open("db.dat", ios::app);
    out<<username+ ".dat"<<"\n";
    out.close();

    ofstream out1;
    string temp=username+".dat";
    out1.open(temp.c_str());
    out1<<name<<"\n"; out1<<username<<"\n";
    out1<<rollno<<"\n";out1<<add<<"\n";
    out1<<mother<<"\n";
    out1.close();

    cout<<"Student Registered Successfully!!\n";
    cout<<"Press any key to continue...\n";
    getchar();
    getchar();
    return 0;
}
int main(int argc, char** argv)
{
    while(1)
    {
        system("cls");
        cout<<"------------------------------------------------------Attendance Management System-------------------------------------------------------\n";
        cout<<"-----------------------------------------------------------------------------------------------------------------------------------------\n";

        cout<<"1: Student Login.\n";
        cout<<"2: Admin Login.\n";

        cout<<"0: Exit.\n";
        int choice;

        cout<<"Enter Your Choice:\n";
        cin>>choice;

        switch(choice)
        {
            case 1: studentLogin();
            break;
            case 2: adminLogin();
            break;
            case 0:
                while(1)
                {
                    system("cls");
                    cout<<"Are you sure , you want to exit?\n";
                    char ex;
                    cin>>ex;
                    if(ex=='y'||ex=='Y')
                        exit(0);
                    else if(ex=='n'||ex=='N')
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Invalid choice. Enter Again.\n";
                        getchar();
                    }
                }
                    return 0;
        }
    }
}
