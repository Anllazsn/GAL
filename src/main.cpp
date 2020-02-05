#include <iostream>
#include <string>
#include <ctime>
#include <list>

using namespace std;

/*
src
lib
include
bin
build
doc
*/

class Localidade
{
public:
	long id;
	string nome;
	string endereco;
};

class Empresa
{
public:
	long id;
	string nome;
	list<Localidade*> localidades;
	
	void Print()
	{
		cout << "Empresa[" << this->id << "]: " << this->nome << endl;
		for(auto& item : this->localidades)
		{
			cout << "\tLocalidade[" << item->id << "]: " << item->nome << " - " << item->endereco << endl;
		}
	}
};

class AcessoPermitido
{
public:
	long idLocalidade;
	long idCliente;
	// Empresa* empresa;
	// Localidade* localidade;
	// Cliente cliente;
};

//é preciso registrar toda vez que ele for liberado????
class LogAcessoPermitido
{
public:
	long idLocalidade;
	long idCliente;
	time_t data;
};

/*O mesmo cliente pode ter acesso a várias empresas mas seu cadastro teria que ser duplicado
Ex:
empresa A cadastra o cliente 1 - ANDRE cpf 123
empresa B cadastra o cliente 2 - ANDRE cpf 123
os cadastros possuem ids diferentes mas a pessoa é a mesma por causa do cpf*/
//2020+123+1
class Cliente
{
public:
	long id;
	Empresa* empresa; 
	string matricula; //TODO: vai ser a pk ou uk? (ano+empresa+sequencia) para modo offline a matricula so deveria ser gerada com acesso a internet?
	bool isAtivo;
	string nome;
	time_t dataNascimento;
	string cpf;
	string endereco;
	string email;
	string telefone1;
	string telefone2;
	bool isAcessaTodasLocalidades;
	list<AcessoPermitido*> acessosPermitidos;
	//TODO: biometria

	//TODO: Controlar onde este cliente pode acessar
	//TODO: Linkar com forma de pagamento
};

namespace fin
{
	class FormaPagamento
	{

	};
}

Empresa* cadastrarEmpresa(string nomeEmpresa, string nomeLocalidade, string endereco)
{
	Empresa* empresa = new Empresa();
	empresa->id = 0;
	empresa->nome = nomeEmpresa;

	Localidade* localidade = new Localidade();
	localidade->id = 0;
	localidade->nome = nomeLocalidade;
	localidade->endereco = endereco;

	empresa->localidades.push_back(localidade);

	return empresa;
}

int main()
{	
	cout << "BEM VINDO" << endl;

	string nomeEmpresa, nomeLocalidade, endereco;

	getline(cin, nomeEmpresa);
	//cin >> nomeEmpresa;
	cout << "ok\n";
	getline(cin, nomeLocalidade);
	//cin >> nomeLocalidade;
	cout << "ok\n";
	getline(cin, endereco);
	//cin >> endereco;
	cout << "ok\n";

	Empresa* empresa = cadastrarEmpresa(nomeEmpresa, nomeLocalidade, endereco);

	Localidade* loc = new Localidade();
	loc->id = 0;
	loc->nome = "ANDRE";
	loc->endereco = "ENDERECO";	
	empresa->localidades.push_back(loc);

	empresa->Print();

	return 0;
}