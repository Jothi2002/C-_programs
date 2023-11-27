#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
class user{
    public:
    string username;
    string pwd;
    string web;
};
class passwordmanagement:public user{
    public:
    user currentuser;
void userreg(string username,string pwd)
{  cout<<"enter usename: ";
    cin>>currentuser.username;
    cout<<"enter pwd: ";
    cin>>currentuser.pwd;
    cout<<"userregistration sucessfull" << endl;
}
void userlogin(string username,string pwd)
{ cout<<"enter username: ";
    cin>>username;
    cout<<"enter pwd: ";
    cin>>pwd;
    if(username==currentuser.username && pwd==currentuser.pwd)
    {
        cout<<"userlogin sucessfull" << endl;;
    }
    else{
        cout<<"userlogin failed" <<endl;
    }
}
 void storagepwd() {
    cout << "Enter the website or account name: ";
    cin >> currentuser.web;

    cout << "Enter the username: ";
    cin >> currentuser.username;

    cout << "Enter the password or type 'generate' for a generated password: ";
    string password;
    cin >> password;

    if (password == "generate") {
        currentuser.pwd = generatepwd(15);  
    } else {
        currentuser.pwd = password;
    }

    cout << "Password stored successfully!" << endl;
}



string retrievepwd(string username,string web)
{ cout<<"enter username";
    cin>>username;
    cout<<"enter web";
    cin>>web;
    if(username==currentuser.username && web==currentuser.web)
    {
        cout<<currentuser.pwd << endl;

    }else{
        cout<<"user pwd not found" << endl;
    }
}
string generatepwd(int n) {
    const char input[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*(){}<>";
    string generatedPwd;

    for (int i = 0; i < n; i++) {
        generatedPwd += input[rand() % (sizeof(input) - 1)];
    }

    return generatedPwd;
}};

int main()
{ passwordmanagement password1;
    string username;
    string pwd;
    string web;
    int choice;
    while (true) {
        cout << "1. User Registration\n2. User Login\n3. Store Password\n4. Retrieve Password\n5. Exit\n";
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
    password1.retrievepwd(username,web);
    break;
    
    default:
        break;
    }}}