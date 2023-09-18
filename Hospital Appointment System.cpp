#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;

int bookAppointment()
{
    system("cls");
    cout<<"\t\t\tBook Your Appointment\t\t\t"<<endl;
    cout<<"\t\t\tAvailable Slots\t\t\t"<<endl;

    //check if record already exists...

    ifstream read;
    read.open("appointment.dat");

    int hoursbook=8;

    int arr[13]={0,0,0,0,0,0,0,0,0,0,0,0, 0};
    int recordFound=0;

    if(read)
    {
        string line;
        char key='A';
        int i=9;

        while(getline(read, line))
        {
            char temp=line[0];
            int index=temp-65;
            arr[index]=1;
            recordFound=1;
        }
        if(recordFound==1)
        {
            cout<<"Appointment Summary by hours:\n";
            char key='A';
            int hours=9;
            for(int i=0; i<=12; i++)
            {
                if(i==0)
                {
                    if(arr[i]==0)
                        cout<<"\n"<<key<<"->"<<hours<<"-Available\n";
                    else
                        cout<<"\n"<<key<<"->"<<hours<<"-Booked\n";
                }
                else
                {
                    if(arr[i]==0)
                        cout<<"\n"<<key<<"->"<<hours<<"-Available\n";
                    else
                        cout<<"\n"<<key<<"->"<<hours<<"-Booked\n";
                }
                hours++; key++;
            }
        }
        read.close();
    }
    if(recordFound==0)
    {
        cout<<"Appointment Available for following hours:\n";
        char key='A';
        for(int i=9; i<=21; i++)
        {
            if(i==9)

                cout<<"\n"<<key<<"->"<<i<<"-Available\n";

                else
                    cout<<"\n"<<key<<"->"<<i<<"Available\n";
                key++;
            }
        }
        char choice;
        cout<<"\n\nInput your choice:\n";
        cin>>choice;

        if(!(choice>='A'&& choice <='Z'))
        {
            cout<<"Error: Invalid Selection";
            cout<<"Please selection correct value from menu A-Z\n";
            cout<<"Press any key to continue\n";
            getchar();getchar();
            system("cls");
            bookAppointment();
        }
        int index=(choice-65);
        int isBooked=1;
        if(arr[index]==0)
            isBooked=0;

        if(isBooked==1)
        {
            cout<<"Error: Appointment is already booked for this hour.\n";
            cout<<"Please select different time!!\n";
            cout<<"Press any key to continue!!\n";
            getchar();getchar();
            system("cls");
            bookAppointment();
        }
        string name;
        cout<<"Enter Your name:\n";
        cin>>name;

        ofstream out;
        out.open("appointment.dat", ios::app);
         if(out)
         {
             out<<choice<<":"<<name.c_str()<<"\n";
             out.close();
             cout<<"Appointment Booked for Hours:\n"<<(choice-65)+9<<"successfully!!";\
         }
         else
         {
             cout<<"Error while saving booking";
         }
         cout<<"Press any key to continue....\n";
         getchar();getchar();
         return 0;
    }
    int existingAppointment()
    {
        system("cls");
        cout<<"---------------------------------------------Appointment Summary--------------------------------------------------------\n";
        //check if record already exist..
        ifstream read;
        read.open("appointment.dat");

        int hoursbook=8;

        int arr[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
        int recordFound=0;

        if(read)
        {
            string line;
            char key='A';
            int i=9;

            while(getline(read, line))
            {
                char temp=line[0];
                int index=(temp-65);
                arr[index]=1;
                recordFound=1;
            }
            if(recordFound==1)
            {
                cout<<"\n\n\t\t\t\t\tAppointment Summary by hours:\n";
                char key='A';
                int hours=9;
                for(int i=0; i<=12; i++)
                {
                    if(arr[i]==0)
                    {
                        cout<<"\n"<<key<<"->"<<hours<<"-Available";
                    }
                        else
                            cout<<"\n"<<key<<"->"<<hours<<"-Booked";
                        hours++;key++;
                }
            }
                read.close();
            }
            else
            {
                int hours;
                char key='A';
                for(int i=9; i<=21; i++)
                {
                    if(i==9)
                        cout<<"\n"<<key<<"->0"<<i<<"-Available.\n";
                    else
                        cout<<"\n"<<key<<"->"<<i<<"-Booked.\n";
                        hours++;
                    key++;
                }
            }
            cout<<"\nPress any key to continue..\n";
            getchar();getchar();
            return 0;
    }

            int main(int argc, char** argv)
            {
            while(1)
                {
                    system("cls");
                    cout<<"\t\t\t\t\t\tDoctor Appointment system\n";
                    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
                    cout<<"1: Book an Appointment.\n";
                    cout<<"2: Existing Appointment.\n";
                    cout<<"0. Exit\n";

                    int choice;

                    cout<<"Enter your choice:\n";
                    cin>>choice;

                    switch(choice)
                    {
                        case 1: bookAppointment();break;
                        case 2: existingAppointment();break;
                        case 0:
                        while(1)
                        {
                            system("cls");
                            cout<<"Are you sure, you want to exit?y|n\n";
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
                                {
                                    cout<<"Invalid choice!!!";
                                    getchar();
                                }
                            }break;
                            default: cout<<"Invalid choice. Enter again.\n";
                            getchar();
                        }

                    }
    return 0;

}
            }
