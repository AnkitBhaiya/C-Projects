
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;
int main(){
    double usd;
    double rate;
    double inr;
    rate = 73;
    const int COLMFT1 = 35;
    const int COLMFT2 = 15;
    cout<<fixed<<setprecision(2);
    cout<<"Welcome to C++ currency Converter"<<endl;
    cout<<setw(COLMFT1)<<left<<"Enter a value(US Dollars): ";
    cin>>usd;
    cout<<endl;
    cout<<setw(COLMFT1)<<left<<"US dollars: ";
    cout<<setw(COLMFT1)<<right<<usd<<endl;
    cout<<setw(COLMFT1)<<left<<"Conversion rate(per US dollar): ";
    cout<<setw(COLMFT1)<<right<<rate<<endl;
    inr = usd * rate;
    cout<<setw(COLMFT1)<<left<<"INR: ";
    cout<<setw(COLMFT1)<<right<<inr<<endl;
    cout << "\n--------------------------- " << endl;
    cout << "\nEnd of Rate Converter" << endl;
}
