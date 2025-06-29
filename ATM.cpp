#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ATM {
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;
    vector<string> transactionHistory;
    bool isLocked = false;
    int pinAttempts = 0;

public:
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a) {
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }

    long int getAccountNo() { return account_No; }
    string getName() { return name; }
    int getPIN() { return PIN; }
    double getBalance() { return balance; }
    string getMobileNo() { return mobile_No; }
    vector<string> getTransactionHistory() { return transactionHistory; }
    bool getLockStatus() { return isLocked; }

    void setMobile(string mob_prev, string mob_new) {
        if (mob_prev == mobile_No) {
            mobile_No = mob_new;
            cout << "\nSuccessfully Updated Mobile no.";
        } else {
            cout << "\nIncorrect Old Mobile no!";
        }
        cin.ignore();
        cin.get();
    }

    void cashWithDraw(int amount_a) {
        if (amount_a > 0 && amount_a <= balance && amount_a <= 20000) {
            balance -= amount_a;
            string transaction = "Withdrew: " + to_string(amount_a);
            transactionHistory.push_back(transaction);
            cout << "\nPlease Collect Your Cash";
            cout << "\nAvailable Balance: " << balance;
        } else if (amount_a > 20000) {
            cout << "\nWithdrawal limit exceeded! You can only withdraw up to 20000.";
        } else {
            cout << "\nInvalid Input or Insufficient Balance";
        }
        cin.ignore();
        cin.get();
    }

    void lockAccount() {
        isLocked = true;
        cout << "\nYour account has been locked due to multiple incorrect attempts.";
        cin.ignore();
        cin.get();
    }

    void trackPinAttempts() {
        pinAttempts++;
        if (pinAttempts >= 3) {
            lockAccount();
        }
    }

    void resetPinAttempts() {
        pinAttempts = 0;
    }

    void unlockAccount() {
        isLocked = false;
        pinAttempts = 0;
        cout << "\nYour account has been unlocked. Please try again with correct details.";
        cin.ignore();
        cin.get();
    }
};

vector<ATM> users;

// Function to find user by account number
ATM* findUser(long int accNo) {
    for (auto& user : users) {
        if (user.getAccountNo() == accNo) {
            return &user;
        }
    }
    return nullptr;
}

// Function to register a new user
void registerUser() {
    ATM newUser;
    long int accNo;
    string name, mobile;
    int pin;
    double balance;

    cout << "\nEnter Account Number: ";
    cin >> accNo;
    if (findUser(accNo)) {
        cout << "\nAccount number already exists!";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "Enter Name: ";
    cin.ignore(); // Clear buffer
    getline(cin, name);

    cout << "Set 4-digit PIN: ";
    cin >> pin;

    cout << "Enter Initial Balance: ";
    cin >> balance;

    cout << "Enter Mobile Number: ";
    cin >> mobile;

    newUser.setData(accNo, name, pin, balance, mobile);
    users.push_back(newUser);

    cout << "\nUser Registered Successfully!";
    cin.ignore();
    cin.get();
}

void userMenu(ATM &user) {
    int choice;
    do {
        cout << string(50, '\n');
        int amount;
        string oldMobileNo, newMobileNo;

        cout << "\n**** Welcome, " << user.getName() << " *****";
        cout << "\n1. Check Balance";
        cout << "\n2. Cash Withdraw";
        cout << "\n3. Show User Details";
        cout << "\n4. Update Mobile No.";
        cout << "\n5. View Transaction History";
        cout << "\n6. Lock Account (for security)";
        cout << "\n7. Logout" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nBalance: " << user.getBalance();
                cin.ignore();
                cin.get();
                break;
            case 2:
                cout << "\nEnter amount: ";
                cin >> amount;
                user.cashWithDraw(amount);
                break;
            case 3:
                cout << "\nAccount No: " << user.getAccountNo();
                cout << "\nName: " << user.getName();
                cout << "\nBalance: " << user.getBalance();
                cout << "\nMobile No: " << user.getMobileNo();
                cin.ignore();
                cin.get();
                break;
            case 4:
                cout << "\nEnter Old Mobile No.: ";
                cin >> oldMobileNo;
                cout << "\nEnter New Mobile No.: ";
                cin >> newMobileNo;
                user.setMobile(oldMobileNo, newMobileNo);
                break;
            case 5: {
                vector<string> trans = user.getTransactionHistory();
                cout << "\n*** Transaction History ***";
                for (string t : trans)
                    cout << "\n" << t;
                cin.ignore();
                cin.get();
                break;
            }
            case 6:
                user.lockAccount();
                return;
            case 7:
                return;
            default:
                cout << "\nInvalid option!";
                cin.ignore();
                cin.get();
                break;
        }
    } while (true);
}

int main() {
    // Add a default user
    ATM defaultUser;
    defaultUser.setData(987654321, "Rakhi Rawat", 1234, 50000, "9876543210");
    users.push_back(defaultUser);

    int mainChoice;

    do {
        cout << string(50, '\n');
        cout << "\n==== ATM SYSTEM ====";
        cout << "\n1. Login";
        cout << "\n2. Register New User";
        cout << "\n3. Exit" << endl;
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: {
                long int accNo;
                int pin;

                cout << "\nEnter Account No: ";
                cin >> accNo;
                cout << "Enter PIN: ";
                cin >> pin;

                ATM* user = findUser(accNo);
                if (user && !user->getLockStatus()) {
                    if (user->getPIN() == pin) {
                        user->resetPinAttempts();
                        userMenu(*user);
                    } else {
                        cout << "\nIncorrect PIN!";
                        user->trackPinAttempts();
                        cin.ignore();
                        cin.get();
                    }
                } else if (user && user->getLockStatus()) {
                    cout << "\nAccount is locked.";
                    cin.ignore();
                    cin.get();
                } else {
                    cout << "\nUser not found!";
                    cin.ignore();
                    cin.get();
                }
                break;
            }
            case 2:
                registerUser();
                break;
            case 3:
                cout << "\nExiting... Thank you!";
                return 0;
            default:
                cout << "\nInvalid choice!";
                cin.ignore();
                cin.get();
                break;
        }
    } while (true);

    return 0;
}
