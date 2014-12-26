#include "Unidades.h"

vector<Popul> populacoes;

Unidade::Unidade(int x, int y, string tipo, int i){
	vida = 100;
	id = i;
	
	setCoords(x,y);
	setTipo(tipo);
}

Edificio::Edificio(int x, int y, string tip, int i){
	vida = 100;
	id = i;

	coordernada_x = x;
	coordernada_y = y;
	tipo = tip;
}

void Unidade::setCoords(int x, int y){
	coordernada_x = x;
	coordernada_y = y;
}

void Unidade::setTipo(string tipo_en){
	tipo = tipo_en;
}

int Unidade::getCoordX(){
	return coordernada_x;
}

int Edificio::getCoordX(){
	return coordernada_x;
}

int Unidade::getCoordY(){
	return coordernada_y;
}

int Edificio::getCoordY(){
	return coordernada_y;
}

int Unidade::getVida(){
	return vida;
}

void Unidade::mudarCoordenadas(int cx, int cy){
	coordernada_x = cx;
	coordernada_y = cy;
}

string Unidade::getTipo(){
	return tipo;
}

string Edificio::getTipo(){
	return tipo;
}

Popul::Popul(string nomes){
	setNome(nomes);
}

void Popul::setNome(string nomes){
	nome = nomes;
}

string Popul::getNome(){
	return nome;
}

void Pops_func(Popul pop_a){
	populacoes.push_back(pop_a);
	cout << "Populacao " << pop_a.getNome() << " adicionada" << endl;
	getchar();
}

vector<Popul> getPops(){
	return populacoes;
}

void imprimirUnidades(vector<Unidade> unit, int mapa_coordx, int mapa_coordy){
	int pos_x, pos_y;
	Consola con;
	DWORD saida;
	HANDLE hconsola;
	hconsola = GetStdHandle(STD_OUTPUT_HANDLE);

	con.setTextColor(con.AZUL_CLARO);

	for (size_t i = 0; i < unit.size(); i++){
		pos_x = unit[i].getCoordX();
		pos_y = unit[i].getCoordY();

		pos_x = pos_x - mapa_global.getCoord_X();
		pos_y = pos_y - mapa_global.getCoords_Y();

		if (unit[i].getTipo() == "sold"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << soldado_n;
			}
		}

		if (unit[i].getTipo() == "camp"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << campones;
			}
		}

		if (unit[i].getTipo() == "caval"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << cavaleiro;
			}
		}

		if (unit[i].getTipo() == "camp_caval"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << camp_caval;
			}
		}

		if (unit[i].getTipo() == "catap"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << catapulta;
			}
		}
	}

	con.gotoxy(0, LINHAS + 4);
	
	for (int j = 0; j < 50; j++){
		WriteConsoleA(hconsola, &limpar, 1, &saida, NULL);
	}

	con.setTextColor(con.BRANCO);
	con.gotoxy(0, LINHAS + 4);
}

void imprimirEdificios(vector<Edificio> unit, int mapa_coordx, int mapa_coordy){
	int pos_x, pos_y;
	Consola con;
	DWORD saida;
	HANDLE hconsola;
	hconsola = GetStdHandle(STD_OUTPUT_HANDLE);

	con.setTextColor(con.AZUL_CLARO);

	for (size_t i = 0; i < unit.size(); i++){
		pos_x = unit[i].getCoordX();
		pos_y = unit[i].getCoordY();

		pos_x = pos_x - mapa_global.getCoord_X();
		pos_y = pos_y - mapa_global.getCoords_Y();

		if (unit[i].getTipo() == "quar"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				WriteConsoleA(hconsola, &topo_e, 1, &saida, NULL);
				WriteConsoleA(hconsola, &topo_d, 1, &saida, NULL);
				con.gotoxy(pos_x, pos_y + 1);
				WriteConsoleA(hconsola, &baixo_e, 1, &saida, NULL);
				WriteConsoleA(hconsola, &baixo_d, 1, &saida, NULL);
			}
		}

		if (unit[i].getTipo() == "esta"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << char(234);
			}
		}

		if (unit[i].getTipo() == "quinta"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << char(227);
			}
		}

		if (unit[i].getTipo() == "cast"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << char(206);
			}
		}
	}

	con.gotoxy(0, LINHAS + 4);

	for (int j = 0; j < 50; j++){
		WriteConsoleA(hconsola, &limpar, 1, &saida, NULL);
	}

	con.setTextColor(con.BRANCO);
	con.gotoxy(0, LINHAS + 4);
}