#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <string>
#include <ctime>
#include <list>

class Localidade
{
public:
	long id;
	std::string nome;
	std::string endereco;
};

class Empresa
{
public:
	long id;
	std::string nome;
	std::list<Localidade*> localidades;
	
	void Print()
	{
		std::cout << "Empresa[" << this->id << "]: " << this->nome << std::endl;
		for(auto& item : this->localidades)
		{
			std::cout << "\tLocalidade[" << item->id << "]: " << item->nome << " - " << item->endereco << std::endl;
		}
	}
};

#endif