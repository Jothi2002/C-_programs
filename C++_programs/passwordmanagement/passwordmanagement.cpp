#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
class user{
    public:
    string username;
    string pwd;
    string account_name;
};
//class derived from user
class passwordmanagement:public user{
    public:
    user currentuser;
//function for user registration
void userreg(string username,string pwd)
{  cout<<"enter username: ";
    cin>>currentuser.username;
    cout<<"enter pwd: ";
    cin>>currentuser.pwd;
    cout<<"userregistration sucessfull" << endl;
}
//function for user login
void userlogin(string username,string pwd)
{ cout<<"enter username: ";
    cin>>username;
    cout<<"enter pwd: ";
    cin>>pwd;
    if(username==currentuser.username && pwd==currentuser.pwd) //check if username and password is already register
    {
        cout<<"userlogin sucessfull" << endl;;
    }
    else{
        cout<<"userlogin failed" <<endl;
    }
}
//function for store password
 void storagepwd() {
    cout << "Enter the website or account name: ";
    cin >> currentuser.account_name;

    cout << "Enter the username: ";
    cin >> currentuser.username;

cout<<"Enter the password or type 'generate' for a generated password."<<endl;
    string password;
    cin >> password;

    if (password == "generate") { 
        currentuser.pwd = generatepwd(15);  //it generates password with a length of 15
    } else {
        currentuser.pwd = password;
    }

    cout << "Password stored successfully!" << endl;
}
//function for retrieve password
string retrievepwd(string username,string web)
{ cout<<"enter username";
    cin>>username;
    cout<<"enter account_name";
    cin>>web;
    if(username==currentuser.username && account_name==currentuser.account_name) 
    {
        cout<<currentuser.pwd << endl;

    }else{
        cout<<"user pwd not found" << endl;
    }
}
//function for generate password
string generatepwd(int n) {
    const char input[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*(){}<>";
    string generatedPwd;

    for (int i = 0; i < n; i++) {
        generatedPwd += input[rand() % (sizeof(input) - 1)]; //it take random character from input and generate password with the length of 15
    }

    return generatedPwd;
}};

int main()
{ passwordmanagement password1;
    string username;
    string pwd;
    string account_name;
    int choice;
    while (true) {
        cout << "1. User Registration\n2. User Login\n3. Store Password\n4. Retrieve Password\n";
        cout << "Enter your choice: ";
        cin >> choice;
   
    switch (choice)
    {
    case 1:
    password1.userreg(username,pwd);
    break;
    case 2:
    password1.userlogin(username,pwd);
    break;
    case 3:
    password1.storagepwd();
    break;
    case 4:
    password1.retrievepwd(username,account_name);
    break;
    
    default:
        break;
    }}}
