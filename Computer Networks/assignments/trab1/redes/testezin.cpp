#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>

using namespace std;

int main(void)
{
	std::ifstream arquivo;
	try
	{
		arquivo.open("curriculo.html", std::ifstream::ate | std::ifstream::binary);
	}
	catch(ifstream::failure e)
	{
		cout << "Erro na abertura de arquivo." << endl;
	}
	std::string teste = static_cast<stringstream const&>(stringstream() << arquivo.rdbuf()).str();
	cout << teste << endl;
	return 0;
}