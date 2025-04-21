#include <iostream>
#include <string>

class Wallet {
private:
    double balance;
    double dailyDepositTotal;
    double dailyWithdrawalTotal;
    static constexpr double MAX_DAILY_DEPOSIT = 10000.0;
    static constexpr double MAX_DAILY_WITHDRAWAL = 5000.0;

public:
    Wallet() : balance(0), dailyDepositTotal(0), dailyWithdrawalTotal(0) {}

    bool deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid deposit amount.\n";
            return false;
        }
        if (dailyDepositTotal + amount > MAX_DAILY_DEPOSIT) {
            std::cout << "Deposit failed: Daily deposit limit exceeded.\n";
            return false;
        }
        balance += amount;
        dailyDepositTotal += amount;
        std::cout << "Deposited: $" << amount << "\n";
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid withdrawal amount.\n";
            return false;
        }
        if (dailyWithdrawalTotal + amount > MAX_DAILY_WITHDRAWAL) {
            std::cout << "Withdrawal failed: Daily withdrawal limit exceeded.\n";
            return false;
        }
        if (balance < amount) {
            std::cout << "Withdrawal failed: Insufficient balance.\n";
            return false;
        }
        balance -= amount;
        dailyWithdrawalTotal += amount;
        std::cout << "Withdrew: $" << amount << "\n";
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void resetDailyLimits() {
        dailyDepositTotal = 0;
        dailyWithdrawalTotal = 0;
    }
};

class User {
private:
    std::string userID;
    std::string name;
    Wallet wallet;

public:
    User(std::string id, std::string username) : userID(id), name(username) {}

    bool deposit(double amount) {
        std::cout << "[" << name << "] ";
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        std::cout << "[" << name << "] ";
        return wallet.withdraw(amount);
    }

    void checkBalance() const {
        std::cout << "[" << name << "] Balance: $" << wallet.getBalance() << "\n";
    }

    void resetLimits() {
        wallet.resetDailyLimits();
    }
};

// ----- Main Function to Demonstrate -----
int main() {
    User user1("U001", "Alice");
    User user2("U002", "Bob");

    user1.deposit(5000);
    user1.withdraw(1000);
    user1.checkBalance();

    user2.deposit(12000); // Should fail (limit)
    user2.deposit(8000);  // Should pass
    user2.withdraw(6000); // Should fail (limit)
    user2.withdraw(4000); // Should pass
    user2.checkBalance();

    return 0;
}
