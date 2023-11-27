#include <iostream>
#include <string>
#include <map>
using namespace std;
//base class Transaction
class Transaction {
public:
    string date;
    string category;
    double amount;
};
//class derived from Transaction
class ExpenseTracker : public Transaction {
public:
    static const int MAX_TRANSACTIONS = 100; // variable to keep track total number of transaction
    Transaction transactions[MAX_TRANSACTIONS];
    int num = 0;
//function to add transaction
    void addTransaction(string date, string category, double amount) {
        if (num >= MAX_TRANSACTIONS) {
            cout << "Transaction limit reached." << endl;
            return;
        }
        transactions[num].date = date;
        transactions[num].category = category;
        transactions[num].amount = amount;
        num++;

        cout << "Transaction added successfully!" << endl;
    }
//function to displaytransaction
    void displayTransactions() {
        if (num == 0) {
            cout << "No transactions to display" << endl;
            return;
        }
        cout << "Transaction History:" << endl;
        cout << "Date\t\tCategory\t\tAmount" << endl;

        for (int i = 0; i < num; i++) {
            cout << transactions[i].date << "\t\t" << transactions[i].category << "\t\t" << transactions[i].amount << endl;
        }
    }
//function to display spendingpatterns and total amount spending 
    void displaySpendingPatterns() {
        if (num == 0) {
            cout << "No transactions to display" << endl;
            return;
        }

        map<string, double> sum_category; //map to store total spending for each category

        for (int i = 0; i < num; ++i) {
            sum_category[transactions[i].category] += transactions[i].amount;
        }
        cout << "Spending Patterns Report:" << endl;
        cout << "Category\tTotal Spending" << endl;
        double total_spending_amount = 0.0; //variable to keep track total amount
        for (const auto &entry : sum_category) {
            cout << entry.first << "\t\t" << entry.second << endl;
            total_spending_amount+=entry.second;//calculate total spending for each category
        }
        cout<<"Total Spending Amount:\t"<<total_spending_amount<<endl;
    }
};
int main() {
    ExpenseTracker expenseTracker;
    while (true) {
        cout << "1. add Transaction\n2. display Transactions\n3. display Spending Patterns Report\n4. exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string date, category;
                double amount;
                cout << "Enter Date (MM/DD/YYYY): ";
                cin >> date;
                cout << "Enter Category: ";
                cin.ignore();
                getline(cin, category);
                cout << "Enter Transaction Amount: ";
                cin >> amount;
                expenseTracker.addTransaction(date, category, amount);
                break;
            }
            case 2:
                expenseTracker.displayTransactions();
                break;
            case 3:
                expenseTracker.displaySpendingPatterns();
                break;
            case 4:
                cout << "Exiting Expense Tracker" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
