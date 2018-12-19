#include "savings.h"

SavingsAccount::SavingsAccount(int balance){
    SavingsAccount::_savings_balance = balance ;
};

float SavingsAccount::annual_savings_rate ;

float SavingsAccount::calculate_monthly_balance() {
    float juros ;
    juros = (_savings_balance)*((annual_savings_rate)/12);
    _savings_balance += juros ;
    return _savings_balance ;
};

//void SavingsAccount::modify_interest_rate(int taxa){
  //  this->annual_savings_rate = taxa ;
//};
