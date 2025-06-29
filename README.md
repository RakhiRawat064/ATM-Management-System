# ATM Simulation System in C++

This is a **console-based ATM simulation project** developed in **C++** that simulates an ATM machine and supports multiple users. It provides features such as user registration, login, cash withdrawal, balance inquiry, mobile number update, transaction history tracking, and account locking for security after multiple incorrect PIN attempts.

---

## 🧩 Functionalities

### ✅ User Registration
New users can register by providing:
- Account number
- Name
- PIN
- Mobile number
- Initial balance

### 🔐 Login Authentication
- Users must input the correct **account number** and **PIN**.
- After **3 incorrect PIN attempts**, the account is **locked**.

### 💳 User Operations (Post Login)
Users can perform the following:
- View balance
- Withdraw cash (limit: ₹20000 per transaction)
- View account details
- Update mobile number
- View transaction history
- Lock account for security

### 📜 Transaction History
- Maintains a history of **withdrawal transactions** using a **vector**.

### 🔒 Security Features
- Account locking after 3 incorrect PINs
- Manual lock/unlock option
- Reset PIN attempt counter after successful login

---

## 👨‍💻 OOP Concepts Used

- **Encapsulation:** Private data members and public getter/setter methods
- **Class and Object Usage:** Defined `ATM` class and created multiple objects
- **Vector Usage:** For storing transaction history
- **Pointer Usage:** In login function to return user reference using `findUser()`

---

## 📎 Notes

- Developed using standard C++ libraries (`<iostream>`, `<string>`, `<vector>`)
- Runs in any C++ IDE or compiler supporting C++11 or higher
- Can be extended further by:
  - Adding file handling
  - GUI using libraries like Qt or SFML
  - Including deposit and PIN change features
