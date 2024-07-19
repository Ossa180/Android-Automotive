#include <iostream>
#include <vector>

class Account
{
public:
    Account(double initial_deposit)
    {
        account_index = total_accounts++;
        current_money = initial_deposit;
        total_deposits = initial_deposit;
        total_withdraws = 0;
        total_deposits_in_atm += initial_deposit;
    }

    void deposit(double amount)
    {
        current_money += amount;
        total_deposits += amount;
        total_deposits_in_atm += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= current_money)
        {
            current_money -= amount;
            total_withdraws += amount;
            total_withdraws_in_atm += amount;
        }
        else
        {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }

    void printDetails() const
    {
        std::cout << "Account Index: " << account_index << std::endl;
        std::cout << "Current Money: " << current_money << std::endl;
        std::cout << "Total Deposits by this Account: " << total_deposits << std::endl;
        std::cout << "Total Withdraws by this Account: " << total_withdraws << std::endl;
    }

    static void printATMStats()
    {
        std::cout << "Total Number of Accounts: " << total_accounts << std::endl;
        std::cout << "Total Deposits in Current ATM: " << total_deposits_in_atm << std::endl;
        std::cout << "Total Withdraws in Current ATM: " << total_withdraws_in_atm << std::endl;
    }

private:
    int account_index;
    double current_money;
    double total_deposits;
    double total_withdraws;

    static int total_accounts;
    static double total_deposits_in_atm;
    static double total_withdraws_in_atm;
};

int Account::total_accounts = 0;
double Account::total_deposits_in_atm = 0;
double Account::total_withdraws_in_atm = 0;

int main()
{
    std::vector<Account> accounts;
    accounts.emplace_back(100.0); // Create an account with an initial deposit of 100
    accounts.emplace_back(200.0); // Create another account with an initial deposit of 200

    accounts[0].deposit(50.0);
    accounts[0].withdraw(30.0);
    accounts[1].withdraw(100.0);

    std::cout << "Account 0 Details:" << std::endl;
    accounts[0].printDetails();
    std::cout << std::endl;

    std::cout << "Account 1 Details:" << std::endl;
    accounts[1].printDetails();
    std::cout << std::endl;

    std::cout << "ATM Statistics:" << std::endl;
    Account::printATMStats();

    return 0;
}
