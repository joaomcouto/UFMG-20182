#ifndef SAVINGS_H
#define SAVINGS_H

class SavingsAccount {
  private:
    float _savings_balance;
  public:
    static float annual_savings_rate;
    SavingsAccount(int n) ;
    float calculate_monthly_balance() ;
    void modify_interest_rate(int taxa);
};


#endif
