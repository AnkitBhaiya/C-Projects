#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
class account 
{
   int acno;
   char name[50];
   int deposit;
   char type;
public:
   void create_account();
   void show_account() const;
   void modify();
   void dep(int);
   void draw(int);
   void report() const;
   int retacno() const;
   int retdeposit() const;
   char rettype() const;
};

void account::create_account()
{
	cout<<"Enter the account No. : "<<endl;
	cin>>acno;
	cout<<"\n\nEnter the name of the account Holder : ";
    cin.ignore();
	cin.getline(name,50);
	cout<<"Enter the type of account (C/S) "<<endl;
	cin>>type;
	type = toupper(type);
	cout<<"\nEnter the initial amount (>=500 for Saving and >=1000 for Current) : ";
	cin>>deposit;
	cout<<"\n\n\nAccount Created......";
}

void account::show_account() const
{
	cout<<"Account No. : "<<acno<<endl;
	cout<<"Account Holder's Name : "<<endl;
	cout<<name;
	cout<<"Type of Account : "<<type<<endl;
	cout<<"Balance Amount : "<<deposit<<endl;
}
void account::modify()
{
	cout<<"Account Number : "<<acno<<endl;
	cout<<"Modify Account Holder's Name : "<<endl;
	cin.ignore();
	cin.getline(name,50);
	cout<<"Modify Type of Account : "<<endl;
	cin>>type;
	type = toupper(type);
	cout<<"Modify Balance amount : "<<endl;
	cin>>deposit;
}
void account::dep(int x)
{
	deposit+=x;
}
void account::draw(int x)
{
	deposit-=x;
}
void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}
int account::retacno() const
{
	return acno;
}
int account::retdeposit() const
{
	return deposit;
}
char account::rettype() const
{
	return type;
}
//******************************************************************************************
//                                  Function Declaration
//******************************************************************************************
void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int,int);
void intro();

int main()
{
	char ch;
	int num;
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\n\t05. ALL ACCOUNT HOLDER'S LIST";
		cout<<"\n\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1 to 8) : ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
			case '1':
			write_account();
			break;
			case '2':
			cout<<"\n\n\tEnter The Account No. : ";
			cin>>num;
			deposit_withdraw(num,1);
			break;
			case '3':
			cout<<"\n\n\tEnter The Account No. : ";
			cin>>num;
			deposit_withdraw(num,2);
			break;
			case '4':
			cout<<"\n\n\tEnter The Account No. : ";
			cin>>num;
			display_sp(num);
			break;
			case '5':
			display_all();
			break;
			case '6':
			cout<<"\n\n\tEnter The Account No. : ";
			cin>>num;
			delete_account(num);
			break;
			case '7':
			cout<<"\n\n\tEnter the Account No. : ";
			cin>>num;
			modify_account(num);
			break;
			case '8':
			cout<<"\n\n\tThanks for using Bank Management System";
			break;
			default:
			cout<<"/a";
		}
		cin.ignore();
		cin.get();
	} 
	while (ch!='8');
	return 0;
}
void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}
void display_sp(int n)
{
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any key.....";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read(reinterpret_cast<char *> (&ac) , sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if(flag == false)
	cout<<"\n\nAccount Number does not exist";
}
void modify_account(int n)
{
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any key to exit.....";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter the new details of the account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\tRecord Updated";
			found = true;
		}
	}
	File.close();
	if(found==false)
	cout<<"\n\nRecord not Found";
}
void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any key to exit.....";
		return;
	}
	outFile.open("Temp.dat",ios::binary)
}