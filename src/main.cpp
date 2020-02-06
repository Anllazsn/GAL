#include <iostream>
#include <string>
#include <ctime>
#include <list>
#include "empresa.hpp"
#include "cliente.hpp"

using namespace std;

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