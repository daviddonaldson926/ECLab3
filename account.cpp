#include <iostream>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string &num, const std::string &holder, double bal)
        : accountNumber(num), accountHolder(holder), balance(bal) {}

    void displayDetails() const {
        std::cout << "Account Details (ID: " << accountNumber << "):\n";
        std::cout << "   Holder: " << accountHolder << "\n";
        std::cout << "   Balance: $" << balance << "\n";
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds.\n";
        }
    }
};

class SavingsAccount : public Account {
    double interestRate;

public:
    SavingsAccount(const std::string &num, const std::string &holder, double bal, double rate)
        : Account(num, holder, bal), interestRate(rate) {}

    void displayDetails() const {
        Account::displayDetails();
        std::cout << "   Interest Rate: " << (interestRate * 100) << "%\n";
    }
};

class CurrentAccount : public Account {
    double overdraftLimit;

public:
    CurrentAccount(const std::string &num, const std::string &holder, double bal, double limit)
        : Account(num, holder, bal), overdraftLimit(limit) {}

    void displayDetails() const {
        Account::displayDetails();
        std::cout << "   Overdraft Limit: $" << overdraftLimit << "\n";
    }

    void withdraw(double amount) {
        if (balance - amount < 0 && abs(balance - amount) > overdraftLimit) {
            std::cout << "Overdraft limit exceeded.\n";
        } else {
            balance -= amount;
        }
    }
};

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);

    savings.displayDetails();
    current.displayDetails();

    return 0;
}



