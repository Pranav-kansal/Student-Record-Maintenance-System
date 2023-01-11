#include "windows.h"
#include<iostream>
#include<string.h>
#include<conio.h>
#include<fstream>

using namespace std;
void gotoxy(int x,int y);
void menu();
void changepassword();
class student{
private :
    char name[30];
    char contactno[15];
    int rno;
    char course[20];
    char  branch[20];
    char fname[30];
    char fno[15];
    char address[50];
    float cgpa;
    char fees[20];

public:
    void add();
    void view();
    void Search();
    void modify();
    void delrec();
    void viewcgpa();
    };
int main()
{
    char c;
    string pass,password;
    system("color 09");
    gotoxy(70,30);
    cout<<"<---:STUDENT RECORD MANAGEMENT SYSTEM:--->";
    gotoxy(70,33);
    cout<<"Enter any key to continue. ";
    fflush(stdin);
    getch();
     ifstream fst;
      fst.open("password.txt",ios::in);
     if(!fst)
     {
         system("cls");
         cout<<"Error Opening File";
     }

        int j=0;
        fst.seekg(0,ios::beg);
        char ch;
        getline(fst,password);
        fst.close();
    for(int i=1;i<=3;i++)
    {
        system("cls");
        gotoxy(50,20);
        cout<<"Enter Password :    ";
        getline(cin,pass);
        if(pass==password)
        {
            menu();
        }
        else
        {

            system("cls");
            gotoxy(50,20);
            cout<<"Wrong Password :   ";
            gotoxy(50,23);
            cout<<"You Have "<<3-i<<" attempt left ";
             gotoxy(50,25);
             cout<<"Press any key to continue ";
             getch();
             if(i==3)
             {
                 gotoxy(50,27);
                 cout<<"SORRY,No more attempts left !!!";
             }
        }
    }
    return 0;
}
void menu()
{
    student st;
     int choice;
    system("cls");
    gotoxy(50,11);
    system("color 09");
    cout<<"<--:MENU:-->";
    gotoxy(50,13);
    cout<<"Enter appropriate number to perform following task.";
    gotoxy(50,15);
    cout<<"1 : Add Record.";
    gotoxy(50,16);
    cout<<"2 : View Record.";
    gotoxy(50,17);
    cout<<"3 : Search Record.";
    gotoxy(50,18);
   cout<<"4 : Modify Record.";
    gotoxy(50,19);
   cout<<"5 : Delete.";
    gotoxy(50,20);
   cout<<"6 : Students CGPA.";
    gotoxy(50,21);
   cout<<"7 : Change Password.";
    gotoxy(50,22);
   cout<<"8 : Exit.";
   gotoxy(50,24);
   cout<<"Enter Your choice  : ";


     gotoxy(72,24);
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        st.add();
        break;

    case 2:
        st.view();
        break;

    case 3:
        st.Search();
        break;

    case 4:
        st.modify();
        break;

    case 5:
        st.delrec();
        break;

    case 6:
        st.viewcgpa();
        break;

    case 7:
        changepassword();
        break;

    case 8:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void student::add()
{
    system("cls");
    char c;
    ofstream fst;
    fst.open("studentrecord.txt",ios::app);
    gotoxy(70,30);
    if(!fst)
    {
        cout<<"Cannot open file";
    }
    student st;
    char another='y';
    while(another=='y' || another=='Y')
    {
        gotoxy(10,10);
        cout<<"<---:ADD RECORDS:--->";
         gotoxy(10,12);
        cout<<"Enter details of student.";
        gotoxy(10,14);
        cout<<"Enter Name : ";
        fflush(stdin);
        gotoxy(50,14);
        gets(st.name);

        gotoxy(10,16);
        cout<<"Enter Mobile Number : ";
        fflush(stdin);
        gotoxy(50,16);
        gets(st.contactno);

        gotoxy(10,18);
        cout<<"Enter Roll No : ";
        fflush(stdin);
        gotoxy(50,18);
        cin>>st.rno;

        gotoxy(10,20);
        cout<<"Enter Course : ";
        fflush(stdin);
        gotoxy(50,20);
        gets(st.course);

        gotoxy(10,22);
        cout<<"Enter Branch : ";
        fflush(stdin);
        gotoxy(50,22);
        gets(st.branch);

        gotoxy(10,24);
        cout<<"Enter Father's Name : ";
        fflush(stdin);
        gotoxy(50,24);
        gets(st.fname);

        gotoxy(10,26);
        cout<<"Enter Father's Contact Number : ";
        fflush(stdin);
        gotoxy(50,26);
        gets(st.fno);

        gotoxy(10,28);
        cout<<"Enter Address : ";
        fflush(stdin);
        gotoxy(50,28);
        gets(st.address);

        gotoxy(10,30);
        cout<<"Enter First Year CGPA :";
        gotoxy(50,30);
        cin>>st.cgpa;

        gotoxy(10,32);
        cout<<"Fees status : ";
        fflush(stdin);
        gotoxy(50,32);
        gets(st.fees);


       fst.write((char*)&st,sizeof(st));
        gotoxy(10,34);
        cout<<"Want to add of another record? Then press 'y' else 'n'.";
        fflush(stdin);
        another=getch();
        system("cls");
    }
    fst.close();
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void student::view()
{
    char c;
     ifstream fst;
     fst.open("studentrecord.txt",ios::in);
    int i=1,j;
    student st;
    system("cls");
    gotoxy(10,3);
    cout<<"<--:VIEW RECORD:-->";
    gotoxy(10,5);
   cout<<"S.No   Name of Student          Mobile No        Roll No        Course        Branch        CGPA        FEES";
    gotoxy(10,6);
    cout<<"--------------------------------------------------------------------------------------------------------------------";

    if(!fst){
        gotoxy(10,8);
        cout<<"Error opening file.";
        exit(1);
    }
    j=8;
    while(!fst.eof()){
         fst.read((char*)&st,sizeof(st));
        gotoxy(10,j);
        if(fst.eof())
        {
            break;
        }
        printf("%-7d%-22s%-18s%-16d%-14s%-14s%-12.2f%-12s",i,st.name,st.contactno,st.rno,st.course,st.branch,st.cgpa,st.fees);
        i++;
        j++;
    }
     fst.close();
    gotoxy(10,j+3);
    cout<<"Press any key to continue.";
    fflush(stdin);
    getch();
    menu();
}
void student::Search()
{
    char c;
    ifstream fst;
     fst.open("studentrecord.txt",ios::in);
    student st;
    int r;
    int f=0;
    system("cls");
    gotoxy(10,3);
    cout<<"<--:SEARCH RECORD:-->";
    gotoxy(10,5);
    cout<<"Enter Roll No of student : ";
    cin>>r;
    if(!fst){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    fst.seekg(0,ios::beg);
    if(fst.eof())
    {
        gotoxy(10,16);
        cout<<"NO RECORD ADDED !!!!";
    }
    while(!fst.eof())
        {
            fst.read((char*)&st,sizeof(st));

            if(st.rno==r)
                {
                    f=1;
                    gotoxy(10,8);
                    cout<<"Name : "<<st.name;
                    gotoxy(10,9);
                    cout<<"Mobile Number : "<<st.contactno;
                    gotoxy(10,10);
                    cout<<"Roll No : "<<st.rno;

                    gotoxy(10,11);
                    cout<<"Father Name : "<<st.fname;

                    gotoxy(10,12);
                    cout<<"Father No : "<<st.fno;

                    gotoxy(10,13);
                    cout<<"Branch : "<<st.branch;

                    gotoxy(10,14);
                    cout<<"Course :"<<st.course;

                    gotoxy(10,15);
                    cout<<"Address : "<<st.address;

                    gotoxy(10,16);
                    cout<<"CGPA : "<<st.cgpa;

                    gotoxy(10,17);
                    cout<<"FEES Status : "<<st.fees;

                    getch();
                    system("cls");

                    break;
                }
         }
         if(f==0)
         {
             gotoxy(10,10);
             cout<<"NO RECORD FOUND !!!!";
             getch();
             system("cls");
         }
    fst.close();
    gotoxy(10,17);
   cout<<"Press any key to continue.";
   fflush(stdin);
    getch();
    menu();
}
void student::modify()
{
    int r;
    int f=0;
    student st;
    system("cls");
    gotoxy(10,3);
    cout<<"<--:MODIFY RECORD:-->";
    gotoxy(10,5);
    cout<<"Enter Roll No of student to modify: ";
    cin>>r;
    fstream fst;
    fst.open("studentrecord.txt",ios::in|ios::out);
    if(!fst){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    fst.seekg(0,ios::beg);
    fflush(stdin);
    while(!fst.eof())
    {
        fst.read((char*)&st,sizeof(st));
        if(r==st.rno){
                f=1;
            gotoxy(10,7);
            cout<<"Enter name: ";
            gotoxy(50,7);
            gets(st.name);

            gotoxy(10,8);
            cout<<"Enter mobile number : ";
             gotoxy(50,8);
            gets(st.contactno);

            gotoxy(10,9);
            cout<<"Enter roll no : ";
             gotoxy(50,9);
            cin>>st.rno;

            gotoxy(10,10);
            cout<<"Enter Father Name : ";
            fflush(stdin);
             gotoxy(50,10);
            gets(st.fname);

            gotoxy(10,11);
            cout<<"Enter Father Number : ";
            fflush(stdin);
             gotoxy(50,11);
            gets(st.fno);

            gotoxy(10,12);
            fflush(stdin);
            cout<<"Enter Address : ";
             gotoxy(50,12);
            gets(st.address);

            gotoxy(10,14);
            fflush(stdin);
            cout<<"Enter Branch : ";
             gotoxy(50,14);
            gets(st.branch);

            gotoxy(10,13);
            fflush(stdin);
            cout<<"Enter Course : ";
             gotoxy(50,13);
            gets(st.course);

            gotoxy(10,15);
            cout<<"Enter CGPA : ";
             gotoxy(50,15);
            cin>>st.cgpa;

            gotoxy(10,16);
            cout<<"Enter Fees Status : ";
            fflush(stdin);
             gotoxy(50,16);
            gets(st.fees);

            fst.seekp(-sizeof(st),ios::cur);
            fst.write((char*)&st,sizeof(st));
            getch();
            system("cls");
            break;
        }
    }
    if(f==0)
    {
        gotoxy(10,7);
        cout<<"NO RECORD FOUND !!!!";
        getch();
        system("cls");
    }
    fst.close();
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void student::delrec()
{
    int r;
    char c;
   ifstream fst;
   fst.open("studentrecord.txt",ios::in);

    student st;
    system("cls");
    gotoxy(10,3);
   cout<<"<--:DELETE RECORD:-->";
    gotoxy(10,5);
    cout<<"Enter Roll No of student to delete record : ";
    cin>>r;
    if(!fst){
        gotoxy(10,6);
        cout<<"Error opening file";
        exit(1);
    }
    ofstream temp;
    temp.open("temp.txt",ios::out);
    if(!temp){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(!fst.eof()){
            fst.read((char*)&st,sizeof(st));
        if(r!=st.rno)
        {
           temp.write((char*)&st,sizeof(st));
        }
    }
    fst.close();
    temp.close();
    remove("studentrecord.txt");
    rename("temp.txt","studentrecord.txt");
    gotoxy(10,7);
    cout<<"RECORD DELETED !!!";
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void student::viewcgpa()
{
     char c;
     ifstream fst;
     fst.open("studentrecord.txt",ios::in);
    int i=1,j;
    student st;
    system("cls");
    gotoxy(10,3);
    cout<<"<--:STUDENTS RECORDS:-->";
    gotoxy(10,5);
   cout<<"S.No   Name of Student                CGPA";
    gotoxy(10,6);
    cout<<"------------------------------------------------";

    if(!fst){
        gotoxy(10,8);
        cout<<"Error opening file.";
        exit(1);
    }
    j=8;
    while(!fst.eof()){
         fst.read((char*)&st,sizeof(st));
        gotoxy(10,j);
        if(fst.eof())
        {
            break;
        }
        printf("%-7d%-24s%0.2f",i,st.name,st.cgpa);
        i++;
        j++;
    }
     fst.close();
    gotoxy(10,j+3);
    cout<<"Press any key to continue.";
    fflush(stdin);
    getch();
    menu();
}
void changepassword()
{
    system("cls");
    ofstream fst;
    string password;
    fst.open("password.txt",ios::out);
    gotoxy(40,25);
    cout<<"Password should be atleast 8 digit long and contains atlest capital letter,digit and special character";
    gotoxy(50,26);
    cout<<"Enter New Password : ";
    cin>>password;
    if(password.length()<8)
    {
        system("cls");
        gotoxy(50,27);
        cout<<"WRONG PASSWORD !! ";
        gotoxy(50,28);
        cout<<"Press any key to continue ";
        getch();
        menu();
    }
    fst<<password;
    fst.close();

}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

