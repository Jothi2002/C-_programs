#include <iostream>
#include <cstdlib>
using namespace std;

class user {
public:
    string username;
    string encryptedPwd;  // Store the encrypted password instead of plain text
    string web;
};

class passwordmanagement : public user {
public:
    user currentuser;

    // Function for user registration
    void userreg() {
        cout << "Enter username: ";
        cin >> currentuser.username;

        cout << "Enter password: ";
        cin >> currentuser.encryptedPwd;  // Change 'pwd' to 'encryptedPwd'

        // Encrypt the password before storing
        currentuser.encryptedPwd = encryptPwd(currentuser.encryptedPwd);

        cout << "User registration successful" << endl;
    }

    // Function for user login
    void userlogin() {
        string enteredUsername, enteredPassword;
        cout << "Enter username: ";
        cin >> enteredUsername;

        cout << "Enter password: ";
        cin >> enteredPassword;

        // Decrypt and check if the entered password matches the stored encrypted password
        if (enteredUsername == currentuser.username && enteredPassword == decryptPwd(currentuser.encryptedPwd)) {
            cout << "User login successful" << endl;
        } else {
            cout << "User login failed" << endl;
        }
    }

    // Function for store password
    void storagepwd() {
        cout << "Enter website : ";
        cin >> currentuser.web;

        cout << "Enter username: ";
        cin >> currentuser.username;

        cout << "Enter password or type 'generate' for a generated password." << endl;
        string password;
        cin >> password;

        if (password == "generate") {
            // Generate a random password
            currentuser.encryptedPwd = encryptPwd(generatepwd(15));
        } else {
            // Encrypt the entered password before storing
            currentuser.encryptedPwd = encryptPwd(password);
        }

        cout << "Password stored successfully!" << endl;
    }

    // Function for retrieve password
    void retrievepwd() {
        string enteredUsername, enteredWeb;
        cout << "Enter username: ";
        cin >> enteredUsername;

        cout << "Enter website: ";
        cin >> enteredWeb;

        // Check if entered username and account_name match the stored values
        if (enteredUsername == currentuser.username && enteredWeb == currentuser.web) {
            // Decrypt and display the stored encrypted password
            cout << "Retrieved password: " << decryptPwd(currentuser.encryptedPwd) << endl;
        } else {
            cout << "User password not found" << endl;
        }
    }

    // Function for generating a random password
    string generatepwd(int n) {
        const char input[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*(){}<>";
        string generatedPwd;

        for (int i = 0; i < n; i++) {
            generatedPwd += input[rand() % (sizeof(input) - 1)];
        }

        return generatedPwd;
    }

    string encryptPwd(const string& password) {
        // Placeholder: Simple XOR-based encryption
        string encryptedPassword = password;
        const char xorKey = 'X';  // Choose a secret key (not secure, just for demonstration)

        for (char& character : encryptedPassword) {
            character = character ^ xorKey;
        }

        return encryptedPassword;
    }

    string decryptPwd(const string& encryptedPassword) {
        // Placeholder: Simple XOR-based decryption
        string decryptedPassword = encryptedPassword;
        const char xorKey = 'X';  // Use the same key as in encryption

        for (char& character : decryptedPassword) {
            character = character ^ xorKey;
        }

        return decryptedPassword;
    }
};

int main() {
    passwordmanagement password1;
    int choice;

    while (true) {
        cout << "1. User Registration\n2. User Login\n3. Store Password\n4. Retrieve Password\n5.Exit";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                password1.userreg();
                break;
            case 2:
                password1.userlogin();
                break;
            case 3:
                password1.storagepwd();
                break;
            case 4:
                password1.retrievepwd();
                break;
            case 5:
           return 0;
        }
    }

    return 0;
}
