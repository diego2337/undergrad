// Defini��o da Classe BasePlusCommissionEmployee
// derivada de ComissionEmployee
// represneta um funcion�rio comissionado com sal�rio base

#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <iostream>
#include <string> // classe string padr�o C++ 

using namespace std;

#include "CommissionEmployee.h" 


class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
   BasePlusCommissionEmployee( 
   const string &first, const string &last, const string &c, 
   double sales, double rate, double salary) : CommissionEmployee(first, last, c, sales, rate)
   // chama explicitamente o construtor da classe b�sica
   {
       cout << endl << "Construindo um BasePlusCommissionEmployee";
	     setBaseSalary(salary);
	   
    } 
   
   ~BasePlusCommissionEmployee()
   {
       cout << "\nDestruindo um objeto BasePlusComissionEmployee." ;
	   // print();
   }
   void setBaseSalary( double );
   double getBaseSalary() const;

   virtual double earnings() const;
   virtual void print() const;
private:
   double baseSalary; // sal�rio-base
}; 

#endif

