#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <ctime>
#include <list>

class Empresa;
class AcessoPermitido;

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
	std::string matricula; //TODO: vai ser a pk ou uk? (ano+empresa+sequencia) para modo offline a matricula so deveria ser gerada com acesso a internet?
	bool isAtivo;
	std::string nome;
	time_t dataNascimento;
	std::string cpf;
	std::string endereco;
	std::string email;
	std::string telefone1;
	std::string telefone2;
	bool isAcessaTodasLocalidades;
	std::list<AcessoPermitido*> acessosPermitidos;
	//TODO: biometria

	//TODO: Controlar onde este cliente pode acessar
	//TODO: Linkar com forma de pagamento
};

#endif