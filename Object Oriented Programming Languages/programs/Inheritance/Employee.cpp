#ifndef EMPLOYEE_H
#include "Employee.h"
#endif

#include <iostream>

using namespace std;



void Employee::setFirstName( const string &first )
{
   firstName = first; 
} 


string Employee::getFirstName() const
{
   return firstName;
} 


void Employee::setLastName( const string &last )
{
   lastName = last; 
} 


string Employee::getLastName() const
{
   return lastName;
} 


void Employee::setCpf( const string &c )
{
   cpf = c; 
} 


string Employee::getCpf() const
{
   return cpf;
} 
                        
void Employee::print() const                           
{                                                                
   cout << endl << endl << getFirstName() << "  "  << getLastName();
   cout << "\ncpf: " << getCpf();
}                                  


