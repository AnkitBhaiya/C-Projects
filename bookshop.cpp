#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class book {
    private:
    char *author,*title,*publisher;
    float *price;
    int *stock;
    public:
    book(){
        author = new char[20];
        title = new char[20];
        publisher = new char[20];
        price = new float;
        stock = new int;
    }
    void feeddata();
    void editdata();
    void showdata();
    int search(char[],char[]);
    void buybook();
};
void book::feeddata(){
    cin.ignore();
    cout<<"Enter the author's name : "<<endl;
    cin.getline(author,20);
    cout<<"Enter the title Name : "<<endl;
    cin.getline(title,20);
    cout<<"Enter the publisher Name : "<<endl;
    cin.getline(publisher,20);
    cout<<"Enter Price : ";
    cin>>*price;
    cout<<"Enter Stock Position : ";
    cin>>*stock;
}
void book::editdata(){
    cout<<"Enter the author's Name : "<<endl;
    cin.getline(author,20);
    cout<<"Enter the title Name : "<<endl;
    cin.getline(title,20);
    cout<<"Enter the publisher Name : "<<endl;
    cin.getline(publisher,20);
    cout<<"Enter Price : ";
    cin>>*price;
    cout<<"Enter Stock Position : ";
    cin>>*stock;
}
void book::showdata(){
    cout<<"Author's Name : "<<author<<endl;
    cout<<"Title Name : "<<title<<endl;
    cout<<"Publisher Name : "<<publisher<<endl;
    cout<<"Price : "<<*price<<endl;
    cout<<"Stock Position : "<<*stock<<endl;
}
int book::search(char tbuy[20] , char abuy[20]){
    if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
    return 1;
    else return 0;
}
void book::buybook(){
    int count;
    cout<<"Enter Number of Books to Buy : "<<endl;
    cin>>count;
    if(count<=*stock){
        *stock = *stock-count;
        cout<<"Books bought successfully"<<endl;
        cout<<"Amount : Rs "<<(*price)*count<<endl;
    }
    else
    cout<<"Required Copies are not in Stock."<<endl;
}
int main()
{
    book *B[20];
    int i=0,r,t,choice;
    char titlebuy[20],authorbuy[20];
    while(1)
    {
        cout<<"\n\n\t\tMENU"
            <<"\n1. Entry of a New Book"
            <<"\n2. Buy a Book"
            <<"\n3. Search for a  Book"
            <<"\n4. Edit Details of a Book"
            <<"\n5. Exit"
            <<"\n\nEnter Your Choice : ";
            cin>>choice;
            switch(choice)
            {
              case 1: B[i] = new book;
              B[i]->feeddata();
              i++; break;
              case 2: cin.ignore();
              cout<<"Enter the Title of the Book : "<<endl;   cin.getline(titlebuy,20);
              cout<<"Enter Author of the Book : "<<endl;      cin.getline(authorbuy,20);
              for(t=0;t<i;t++)
              {
                  if(B[t]->search(titlebuy,authorbuy))	{
						B[t]->buybook();
                        break;
					}
              }
              if(t==1)
              cout<<"This book is not in Stock."<<endl;
              break;
            case 3: cin.ignore();
            cout<<"Enter the title of the book : "<<endl;   cin.getline(titlebuy,20);
            cout<<"Enter the author of the book : "<<endl;  cin.getline(authorbuy,20);
             for(t=0;t<i;t++){
                  if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"Book Found Successfully"<<endl;
                        B[t]->showdata();
                        break;
					}
              }
              if(t==i)
              cout<<"This Book is not in Stock"<<endl;
              break;
            case 4: cin.ignore();
            cout<<"Enter Title of Book: "<<endl;   cin.getline(titlebuy,20);
              cout<<"Enter Author of Book: "<<endl;   cin.getline(authorbuy,20);
              for(t=0;t<i;t++){
                  if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"Book Found Successfully"<<endl;
                        B[t]->editdata();
                        break;
					}
              }
              if(t==i)
              cout<<"This Book is not in Stock"<<endl;
              break;
              case 5: exit(0);
              default: cout<<"Invalid Choice Entered";
        }
    }
    return 0;
}