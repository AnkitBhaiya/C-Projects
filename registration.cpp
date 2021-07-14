#include<iostream>
#include<fstream>
using namespace std;
struct mail
{
    char un[50];
    char pd[50];
    void reg(int);
} obj[5];
void mail::reg(int k)
{
    int i=k;
    cout<<"Enter user name: "<<endl;
    cin>>un;
    cout<<"Enter the password: "<<endl;
    cin>>pd;

    ofstream filout;
    filout.open("C:\\Users\\acer\\Documents\\registration.txt",ios::app|ios::binary);
    if(!filout)
    {
        cout<<"\nCan not open file\n";
    }
    else
    {
        cout<<endl;
        filout.write((char *)&obj[i],sizeof(mail));
        filout.close();
    }
    cout<<"\n...........You are now registered.......... \n\n";
}
int main()
{
    int t;
    cout<<"\nEnter registration details for User 1:: \n";
    obj[0].reg(0);
    cout<<"\nEnter registration details for User 1:: \n";
    obj[1].reg(1);
    cout<<"\nEnter registration details for User 1:: \n";
    obj[2].reg(2);
    cout<<"\nEnter registration details for User 1:: \n";
    obj[3].reg(3);
    cout<<"\nEnter registration details for User 1:: \n";
    obj[4].reg(4);

    mail obj2;
    ifstream filein;
    filein.open("C:\\Users\\acer\\Documents\\registration.txt",ios::in|ios::binary);
    if(!filein)
    {
        cout<<"\nUnable to open file to read\n";
    }
    else
    {
        cout<<"\nRegistered Details of All Users :: \n";
        filein.read((char *)&obj2,sizeof(obj2));
        while(filein)
        {
            cout<<"\nUsername :: "<<obj2.un<<"\nPasswword :: "<<obj2.pd<<"\n";
            filein.read((char *)&obj2,sizeof(obj2));
        }
            
    }
    return 0;
}