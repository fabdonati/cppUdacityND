#include <iostream>
#include <string>

using namespace std;

class BankAccount 
{
    public:
        BankAccount(string name, int number, float funds): ownerName_(name), accountNumber_(number), availableFunds_(funds) {}
        BankAccount(string name, int number): ownerName_(name), accountNumber_(number) {}
        void SetAvailableFunds(float funds) { availableFunds_ = funds;};
        float GetAvailableFunds() { return availableFunds_;};
        void ModifyAvailableFunds(float funds) {availableFunds_ += funds;};
        
    private:
        int accountNumber_{0};
        string ownerName_{0};
        float availableFunds_{0.0};
};

int main() {
    BankAccount saraAccount("Sara", 0, 1000.0);
    saraAccount.ModifyAvailableFunds(-200.0);
    BankAccount fabAccount("Fabrizio", 1);
    fabAccount.SetAvailableFunds(2000.0);
    cout << saraAccount.GetAvailableFunds() << endl;
    cout << fabAccount.GetAvailableFunds() << endl;
    return 0;
}