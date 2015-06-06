#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Grafo
{
private:
	int **matriz;
	int tamanho;

public:
	Grafo(int);	
	void setGrafos(int, int, int);
	int getGrafos(int, int);
	void mostraMatriz();
	bool grafoSimples();
	string grafoRegular();
	string grafoCompleto();
	bool verificaAdjacencia(int, int);
	void verificaGrau();
	bool grafoEuleriano();
	string trilhaEuleriana();
	string grafoDijkstra(int, int);
	~Grafo();
};

