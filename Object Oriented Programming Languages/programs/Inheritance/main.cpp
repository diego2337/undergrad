

#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

#include <iomanip>
#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

void virtualViaPointer (const Employee* const );
void virtualViaReference (const Employee &);

int main ()
{

		cout << fixed << setprecision(2); // <iomanip>
		
		SalariedEmployee salEmp ("Joao", "da Silva", "111222333-44", 800); // dados gerais, e salario-semana
		HourlyEmployee hourEmp ("Pedro","de Souza","444555666-77", 20.0, 48); // dados gerais, salario-hora e horas trabalhadas
		CommissionEmployee comEmp ("Camila", "Miranda", "888999000-66", 10000, 0.06); //dados gerais, vendas brutas e taxa de comissao
		BasePlusCommissionEmployee bComEmp ("Thiago", "Pereira", "555333444-22", 4500.00, 0.04, 700); //dados gerais, venda bruta, taxa de comissao e salario base
		
	
		cout << endl << endl << "Rendimentos calculados individualmente utilizando vinculação estática." ;
		
		salEmp.print();
		cout << endl << "Rendimento: " << salEmp.earnings();
		
		hourEmp.print();
		cout << endl << "Rendimento: " << hourEmp.earnings();
		
		comEmp.print();
		cout << endl << "Rendimento: " << comEmp.earnings();
		
		bComEmp.print();
		cout << endl << "Rendimento: " << bComEmp.earnings();

		
		cout << endl << endl << "Testando a vinculação dinâmica";
		
		// instancia um vetor de 4 posicoes, cada uma armazenando um ponteiro para objeto da classe Employee
		vector <Employee *> employees(4);
		
		employees[0] = &salEmp;
		employees[1] = &hourEmp;
		employees[2] = &comEmp;
		employees[3] = &bComEmp;
		
		
		for(int i = 0; i < employees.size(); i++)
		{
			virtualViaPointer(employees[i]);
		}		
		
		for(int i = 0; i < employees.size(); i++)
		{
			virtualViaReference(*employees[i]);
		}	

		for(int i = 0; i < employees.size(); i++)
		{
			BasePlusCommissionEmployee* derPtr = dynamic_cast<BasePlusCommissionEmployee*>(employees[i]); // <typeinfo>
			if(derPtr)
				cout << "\nObjeto da classe BasePlusCommissionEmployee foi encontrado";
		}
		for(int i = 0; i < employees.size(); i++)
		{
			cout << "\nEncontrei um objeto da classe " << typeid(*employees[i]).name(); // <typeinfo>
		}
		return 0;
}
void virtualViaPointer (const Employee* const baseClassPtr)
{
	baseClassPtr -> print();
	cout << "\nRendimento: " << baseClassPtr->earnings();
}

void virtualViaReference (const Employee& baseClassPtr)
{
	baseClassPtr.print();
	cout << "\nRendimento: " << baseClassPtr.earnings();
}
