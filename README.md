This is a console-based ATM simulation project developed in C++ that simulates an ATM machine and supports multiple users. It provides features such as user registration, login, cash withdrawal, balance inquiry, mobile number update, transaction history tracking, and account locking for security after multiple incorrect PIN attempts.

Functionalities
User Registration:
New users can register by providing account number, name, PIN, mobile number, and initial balance.

Login Authentication:
Users must input correct account number and PIN. After 3 incorrect PIN attempts, the account is locked.

User Operations:
After login, users can:

View balance

Withdraw cash (limit: ₹20000)

View account details

Update mobile number

View transaction history

Lock account for security

Transaction History:
Maintains withdrawal history in a vector.

Security Features:

Account locking after 3 incorrect PINs

Lock/unlock account manually

Reset PIN attempt counter after successful login

OOP Concepts Used:

Encapsulation: Private data members and public methods

Class and Object Usage

Vector usage for storing transaction history

Pointer usage in user search and authentication
