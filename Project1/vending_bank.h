#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class VendingBank {
    public:
        // Constructors
        VendingBank();
        VendingBank(int id, string name, double balance);

        // Getters
        int getId() const;
        double getBalance() const;
        string getName() const;

        // Setters
        bool setId(int id);
        bool setBalance(double balance);
        bool setName(const string& name);

        // Transaction functions
        bool deposit(double amount);
        bool withdraw(double amount);
        bool addTransaction(const string& transaction);

        // Functions related to coins
        int getPennies() const;
        int getNickels() const;
        int getDimes() const;
        int getQuarters() const;

        bool addPennies(int count);
        bool addNickels(int count);
        bool addDimes(int count);
        bool addQuarters(int count);

        bool removePennies(int count);
        bool removeNickels(int count);
        bool removeDimes(int count);
        bool removeQuarters(int count);

        vector<string> getTransactionHistory() const;

        // Operator overloads
        bool operator==(const VendingBank& other) const;
        bool operator!=(const VendingBank& other) const;
        friend ostream& operator<<(ostream& os, const VendingBank& bank);

    private:
        // Data members
        int id_;                      
        string name_;                 
        double balance_;            
        int pennies_;                  
        int nickels_;                  
        int dimes_;                   
        int quarters_;                 

        vector<string> transaction_history_;

        // Helper function (private) to check if there's enough change for a withdrawal
        bool hasSufficientChange(double amount) const;
};

#endif