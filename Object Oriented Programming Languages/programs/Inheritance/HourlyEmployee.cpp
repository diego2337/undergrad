// Implementação dos métodos da classe CommissionEmployee

#ifndef HOURLY_H
#include "HourlyEmployee.h"
#endif

#include <iostream>

using std::cout;                                      
            

void HourlyEmployee::setWage( double hourlyWage )
{
   this->wage = (hourlyWage < 0.0 ? 0.0 : hourlyWage);
} 

double HourlyEmployee::getWage() const
{
   return wage;
}
void HourlyEmployee::setHours( double workedHours )
{
   hours = (( workedHours > 0.0 && workedHours < 168.0 ) ? workedHours : 0.0);
} 

double HourlyEmployee::getHours( ) const
{
   return hours;
} 

double HourlyEmployee::earnings() const
{                                         
   if (getHours() <= 40) return getWage()*getHours();
   else return 40*getWage()+((getHours() - 40)*getWage()*1.5);
}       

                        
void HourlyEmployee::print() const                           
{                                                                
  
   Employee::print();
   cout << "\nSalario-hora: " << getWage()                         
        << "\nHoras trabalhadas: " << getHours();                
}                                  


