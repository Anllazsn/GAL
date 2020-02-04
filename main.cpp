#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Empresa
{
public:
	long id;
	string nome;	
};

class Localidade
{
public:
	long id;
	Empresa* empresa;
};

class Cliente
{
public:
	long id;
	string matricula; //TODO: vai ser a pk ou não?
	bool isAtivo;
	string nome;
	time_t dataNascimento;
	string cpf;
	string endereco;
	string telefone1;
	string telefone2;
	//TODO: biometria
};

namespace fin
{
	class FormaPagamento
	{

	};
}

class Acesso
{
public:
	long id;
	Cliente cliente;
	bool isLiberado;
	time_t data;
};

void main()
{

	cout << "BEM VINDO" << endl;

	return 0;
}