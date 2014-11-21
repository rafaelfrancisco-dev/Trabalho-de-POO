#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include "verCom.h"
#include "Consola.h"
#include "musFundo.h"
#include "impEcra.h"

using namespace std;

int verificarComando(){
	string comando, temp, buf;
	int controlo = 0;
	Consola con;

	con.setTextColor(8);
	vector<string> bocados1;

	cout << "Escreva um comando : " ;
	cin >> comando;
	temp = comando;

	stringstream ss(comando);
	ss >> buf;
	bocados1.push_back(buf);
    ss.flush();

	cout << "O comando inserido foi : " << comando << endl;  //Eliminar este comando futuramente, funcao de debug apenas para verificar separa�ao de string

	if (bocados1[0] == "playmusic"){
		musFundo(3);
		controlo = 1;
		con.clrscr();
		imprimirMenu();
		imprimirOpcoes("Normal", "Originais");
		verificarComando();
	}
	if (bocados1[0] == "stopmusic"){
		musFundo(2);
		controlo = 1;
		con.clrscr();
		imprimirMenu();
		imprimirOpcoes("Normal", "Originais");
		verificarComando();
	}

	if (bocados1[0] == "mkgame")
	{

	}

	if (controlo == 0)
	{
		cout << "Comando nao reconhecido !" << endl;
		fflush(stdin);                                        //Lembrar de arranjar solu�ao melhor para subsituir o fflush
		getchar();
		con.clrscr();
		imprimirMenu();
		imprimirOpcoes("Normal", "Originais");
		verificarComando();
	}

	return 0;
}