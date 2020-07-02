// Implementa��o do algoritmo de Dijkstra
// Teste: http://br.spoj.com/problems/ENGARRAF/

#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
	int V; // n�mero de v�rtices

	// ponteiro para um array contendo as listas de adjac�ncias
	list<pair<int, int> > * adj;

public:

	// construtor
	Grafo(int V)
	{
		this->V = V; // atribui o n�mero de v�rtices

		/*
			cria as listas onde cada lista � uma lista de pairs
			onde cada pair � formado pelo v�rtice destino e o custo
		*/
		adj = new list<pair<int, int> >[V];
	}

	// adiciona uma aresta ao grafo de v1 � v2
	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	// algoritmo de Dijkstra
	int dijkstra(int orig, int dest)
	{
		// vetor de dist�ncias
		int dist[V];

		/*
		   vetor de visitados serve para caso o v�rtice j� tenha sido
		   expandido (visitado), n�o expandir mais
		*/
		int visitados[V];

		// fila de prioridades de pair (distancia, v�rtice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de dist�ncias e visitados
		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a dist�ncia de orig para orig � 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obt�m o v�rtice do pair
			pq.pop(); // remove da fila

			// verifica se o v�rtice n�o foi expandido
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os v�rtices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obt�m o v�rtice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a dist�ncia de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a dist�ncia m�nima at� o destino
		return dist[dest];
	}
};

int main(int argc, char *argv[])
{
	Grafo g(5);

	g.addAresta(0, 1, 4);
	g.addAresta(0, 2, 2);
	g.addAresta(0, 3, 5);
	g.addAresta(1, 4, 1);
	g.addAresta(2, 1, 1);
	g.addAresta(2, 3, 2);
	g.addAresta(2, 4, 1);
	g.addAresta(3, 4, 1);

	cout << g.dijkstra(0, 4) << endl;

	return 0;
}
