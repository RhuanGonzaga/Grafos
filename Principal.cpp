#include "Grafo.h"

using namespace std;

	Grafo *G;

void main()
{

	int i, j, x, n, pond;
	char ok;
	int op;

	do{
		system("CLS");
		cout << "============== MENU ==============" << endl;
		cout << "1. Inserir grafo" << endl;
		cout << "2. Verificar se e simples" << endl;
		cout << "3. Verificar se e completo" << endl;
		cout << "4. Verificar se e regular" << endl;
		cout << "5. Verificar por adjacencia" << endl;
		cout << "6. Verificar grau por vertice" << endl;
		cout << "7. Verificar se e Euleriano" << endl;
		cout << "8. Caminho minimo (djikstra)" << endl;
		cout << "9. Trilha euleriana" << endl;
		cout << "10. Sair" << endl;
		cout << "==================================" << endl;
		cout << "Sua opcao: ";
		cin >> op;

		switch(op)
		{
		case 1:

			cout << "Digite o numero de vertices do Grafo: ";
			cin >> n;
			G = new Grafo(n);
			cout << "O grafo e ponderado ? (1) sim e (2) nao: ";
			cin >> pond;

			if (pond == 1)
			{
				cout << "Digite a distancia: " << endl;
				for (i = 0; i < n; i++)
					for (int j=0;j<n;j++)
					{
						cout << "(" << i+1 << " para " << j+1 << ") : ";
						cin >> x;
						G->setGrafos(i,j,x);
					}
				cout << "Matriz gravada com sucesso !! " << endl;

			} else {

				do{
					cout << "Digite a relacao de adjacencia do Grafo" << endl;
					cout << "Vertice: "; 
					cin >> i;
					cout << "Vertice: "; 
					cin >> j;
					cout << "Valor: "; 
					cin >> x;
					G->setGrafos(i, j, x);
					cout << "\nContinuar ? s/n: "; 
					cin >> ok;
					system("cls");
				} while (ok != 'n');

			}

		G->mostraMatriz();
		system ("pause");
	
		break;
		
		// Verifica se e simples
		case 2:
			G->mostraMatriz();
			if(G->grafoSimples() == true) 
				cout << "Grafo simples!";
			else
				cout << "Grafo NAO simples!";
			system("pause");
		break;

		// Verifica se e completo
		case 3:
			G->mostraMatriz();
			cout << G->grafoCompleto() << endl << endl;
			system("pause");
		break;

		// Verifica se e regular
		case 4:
			G->mostraMatriz();
			cout << G->grafoRegular() << endl << endl;
			system("pause");
		break;

		case 5:
			int v1, v2;

			G->mostraMatriz();

			cout << "Informe o vertice 1: ";
			cin >> v1;
			cout << "Informe o vertice 2: ";
			cin >> v2;
			
			if(G->verificaAdjacencia(v1,v2) == true)
				cout << "Vertice " << v1 << " e vertice " << v2 << " possuem adjacencia!";
			else
				cout << "Vertice " << v1 << " e vertice " << v2 << " NAO possuem adjacencia!";
			system("pause");
		break;

		case 6:
			G->mostraMatriz();
			G->verificaGrau();
			system("pause");
		break;

		case 7:
			G->mostraMatriz();
			if (pond == 1)
				cout << "O grafo e ponderado, por isso nao e euleriano!" << endl;
			else
			{
				if (G->grafoEuleriano() == true)
					cout << "Grafo Euleriano!" << endl;
				else
					cout << "Grafo NAO Euleriano" << endl;
			}
			system("pause");
		break;
		
		case 8:
			G->mostraMatriz();
			if (pond == 2)
				cout << "O grafo nao e ponderado, por isso nao pode rodar o caminho minimo!" << endl;
			else
			{
				int origem, destino;
				cout << "Informe a origem: ";
				cin >> origem;
				cout << "Informe o destino: ";
				cin >> destino;

				cout << G->grafoDijkstra(destino-1,origem-1);
			}
			system("pause");
		break;

		case 9:
			cout << G->trilhaEuleriana() << endl;
			system("pause");
		break;
		}

	}while(op != 10);

		cout << endl;
		cout << endl;
		system("pause");

}