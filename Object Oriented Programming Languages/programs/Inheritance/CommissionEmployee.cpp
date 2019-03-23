// Implementação dos métodos da classe CommissionEmployee

#ifndef COMMISSION_H
#include "CommissionEmployee.h"
#endif

#include <iostream>

using std::cout;
                                                   
            

void CommissionEmployee::setGrossSales( double sales )
{
   grossSales = ( sales < 0.0 ) ? 0.0 : sales;
} 
double CommissionEmployee::getGrossSales() const
{
   return grossSales;
}
void CommissionEmployee::setCommissionRate( double rate )
{
   commissionRate = ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0;
} 
double CommissionEmployee::getCommissionRate() const
{
   return commissionRate;
}
          
double CommissionEmployee::earnings() const
{                                         
   return getGrossSales()*getCommissionRate();
}       
                       
void CommissionEmployee::print() const                           
{                                                                
   Employee::print();
   cout << "\nVendas brutas: " << getGrossSales()                         
        << "\nTaxa de comissao: " << getCommissionRate();                
}                                  


