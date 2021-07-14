#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a;
    string line,old,pass1,pass2,pass;
    cout<<"******* SECURITY SYSTEM PROGRAM *******";
    do{
    cout<<endl<<endl<<"***************************************"<<endl;  
	cout<<"* 1 ->       change the password      *"<<endl;
    cout<<"* 2 ->  go to login panel to see data *"<<endl;
    cout<<"* 3 ->       quit the program         *"<<endl;
    cout<<"***************************************"<<endl<<endl;
    cout<<"enter your choice :- ";
    cin>>a;
    switch(a)
    {
        case 1:
        {
            ifstream outf;
            outf.open("file.txt");
            cout<<"enter the old password :-";
            cin>>old;
            if (outf.is_open())
            {
            	while(!outf.eof())
            	{
             		outf>>line;
      
	        		if(old==line)
            		{
                		outf.close();
                		ofstream outf1;
                		outf1.open("file.txt");
                		if (outf1.is_open())
             			{
             				cout<<"enter your new password :-";
		                	cin>>pass1;
             				cout<<"enter your password again :-";
             				cin>>pass2;
             				if(pass1==pass2)
             				{
                 				outf1<<pass1;
                 				cout<<"password change succesfully";
             				}
             			}
            		}
            		else
            		{
              			cout<<"please enter valid password";
            		}
            	}
            }
           break;
        }
    case 2:
        {
            ifstream outf2;
            outf2.open("file.txt");
            cout<<"please enter a password :-";
            cin>>pass;
            if (outf2.is_open())
            {
            	while(!outf2.eof())
            	{
             		outf2>>line;
           		if(pass==line)
           		{
               			cout<<"acess granted";
           		}
           		else
           		{
               			cout<<"password is wrong"<<endl;
           		}
            	}
       	     }
    	break;
       }
    case 3:
        {
            break;
        }
    	default:
        	cout<<"enter valid choice";
    }
    }
    while(a != 3);
    return 0;
}