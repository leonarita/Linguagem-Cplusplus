#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char *argv[])
{
	priority_queue<int> pq;
	// priority_queue<int, vector<int>, greater<int> > pq; // inverte a prioridade

	pq.push(20);
	pq.push(15);
	pq.push(50);

	cout << "Elemento do topo: " << pq.top() << endl;

	if(pq.empty())
		cout << "\nFila vazia!!\n";
	else
		cout << "\nFila NAO vazia!!\n";

	cout << "\nTamanho da fila: " << pq.size() << endl;
	cout << "\nMostrando os elementos: ";

	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	
	cout << endl;

	return 0;
}