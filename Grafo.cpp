#include "Grafo.h"

Grafo::Grafo(int tam)
{
	matriz = new int*[tam];
	for (int i = 0; i < tam; i++)
		matriz[i] = new int[tam];
	tamanho = tam;
	for (int i = 0; i < tam; i++)
		for (int j = 0; j < tam; j++)
			matriz[i][j] = 0;
}

void Grafo::setGrafos(int i, int j, int k)
{
	matriz[i][j] = k;
	matriz[j][i] = k;
}

int Grafo::getGrafos(int i, int j)
{
	return matriz[i][j];
}

void Grafo::mostraMatriz()
{
	for (int i = 0; i < tamanho; i++)
	{
		cout << endl;
		for (int j = 0; j < tamanho; j++)
			cout << getGrafos(i, j) << "\t";
		cout << endl << endl;
	}
}

bool Grafo::grafoEuleriano()
{
	for (int i = 0; i < tamanho; i++)
	{
		for (int j = 0; j < tamanho; j++)
		{
			if (i == j)
			{
				if (matriz[i][j] != 0)
					return false;
			}
			else
			{
				if (matriz[i][j] > 1)
					return false;
			}
		}
	}

	for (int i = 0; i < tamanho; i++)
	{
		int soma = 0;
		for (int j = 0; j < tamanho; j++)
		{
			soma = soma + matriz[i][j];
		}
		if (soma % 2 != 0)
		{
			return false;
		}
	}
	return true;
}

bool Grafo::grafoSimples()
{
	// Nao pode ter laco ou paralela
	for (int i = 0; i < tamanho; i++)
		for (int j = 0; j < tamanho; j++)
		{
			if (matriz[i][j] > 1 || matriz[i][i] > 0)
			{
				return false;
			}
						
		}	
		return true;
}

string Grafo::grafoRegular()
{
	int i, y, z = 0;
	int *x = new int[tamanho];

	for (i = 0; i < tamanho; i++)
		x[i]=0;

	for (i = 0; i < tamanho; i++)
		for (y = 0; y < tamanho; y++)
			x[i] += matriz[i][y];

	for (i = 0; i < tamanho; i++)
		if((x[i] == x[i+1]) && ((i+1) < tamanho))
			z++;

	if(z == (tamanho-1))
		return "O grafo e regular!";
	else
		return "O grafo nao e regular!";
}

string Grafo::grafoCompleto()
{
	int i, y, z = 0;

	for(i = 0; i < tamanho; i++)
		for(y = 0; y < tamanho; y++)
			if((matriz[i][y] == 0) && (i != y))
			{
				y = tamanho;
				i = tamanho;
				z = 1;
			}

	if(z == 1)
		return "O grafo nao e completo!";
	else
		return "O grafo e completo!";

}

bool Grafo::verificaAdjacencia(int x, int y)
{
	if(matriz[x][y] == 0)
		return false;
	else
		return true;
}

void Grafo::verificaGrau()
{
	int grau;
	for (int i = 0; i < tamanho; i++)
	{
		grau = 0;
		for(int j = 0; j < tamanho; j++)
		{
			if (matriz[i][j] == 1)
				grau = grau + 1;
		}

		cout << "Vertice " << i << " grau = " << grau << endl;
	}
}

string Grafo::grafoDijkstra(int x, int y)
{
	int inf = 1000;
	char *cm = new char[tamanho];
	int *d = new int[tamanho];
	int *va = new int[tamanho];
	int v, t, dAnt;
	char ok = 0;
	ostringstream aux;

	for (v = 0; v < tamanho; v++)
	{
		d[v] = matriz[x][v];
		va[v] = (d[v] >= inf) ? inf : x;
		cm[v] = 0;
	}

	cm[x] = 1;
	if (x == y)
	{
		ok = 1;
	}

	while (ok == 0)
	{
		t = x;
		for (v = 0; v < tamanho; v++)
		{
			if ((cm[v] == 0) && (d[v] < d[t]))
				t = v;
		}
		cm[t] = 1;

		if (cm[y] == 1)
			ok = 1;
		else
		{
			for (v = 0; v < tamanho; v++)
			{
				if (cm[v] == 0)
				{
					dAnt = d[v];
					if (d[v] > d[t] + matriz[t][v])
						d[v] = d[t] + matriz[t][v];
					if (d[v] != dAnt)
						va[v] = t;
				}
			}
		}
	}

	aux << "Na ordem inversa, o caminho e: " << y+1;
	v = y;
	while (v != x)
	{
		aux << ", " << va[v]+1;
		v = va[v];
	}
	aux << "\nA distancia do caminho minimo e: " << d[y];
	return aux.str();
}

string Grafo::trilhaEuleriana()
{
	int i, j, grau;
	int vi = 0;
	for (i = 0; i < tamanho; i++)
	{
		grau = 0;
		for (j = 0; j < tamanho; j++)
		{
			if (matriz[i][j] == 1)
				grau++;

			if ((grau % 2) == 1 && j == (tamanho - 1))
				vi++;
		}
	}

	if (vi > 2)
		return "Trilha nao euleriana!";
	else
		return "Trilha euleriana";
}

Grafo::~Grafo()
{
}
