#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
	map<int, string> mapa;

	mapa[1] = "joao";
	mapa[2] = "maria";
	mapa[3] = "pedro";

	// alterando o valor associado a uma chave
	mapa.at(1) = "carol";

	if(mapa.empty())
		cout << "Mapa vazio!!\n" << endl;
	else
		cout << "Mapa NAO vazio!!\n" << endl;

	if(mapa.count(4) > 0)
		cout << "4 eh elemento do mapa\n";
	else
		cout << "4 NAO eh elemento do mapa\n";

	// mostrando todos os elementos
	map<int, string>::iterator it;
	for(it = mapa.begin(); it != mapa.end(); ++it)
		cout << "A chave " << it->first << " => " << it->second << endl;

	it = mapa.find(2);
	mapa.erase(it);

	// verificando se uma chave existe
	if(mapa.find(2) == mapa.end())
		cout << "\nChave 2 NAO existe!\n\n";
	else
		cout << "\nChave 2 existe!\n\n";

	it = mapa.begin();
	mapa.insert(pair<int, string>(2, "maria"));

	// mostrando todos os elementos
	for(it = mapa.begin(); it != mapa.end(); ++it)
		cout << "A chave " << it->first << " => " << it->second << endl;

	// utilizando multimap
	multimap<int, string> mm;

	mm.insert(pair<int, string>(1, "python 2"));
	mm.insert(pair<int, string>(1, "python 3"));
	mm.insert(pair<int, string>(3, "C"));
	mm.insert(pair<int, string>(4, "C++"));
	mm.insert(pair<int, string>(4, "ruby"));

	multimap<int, string>::iterator it_low, it_up, it2;
	
	it_low = mm.lower_bound(2);
	it_up = mm.upper_bound(4);
	
	cout << endl;
	
	for(it2 = it_low; it2 != it_up; ++it2)
		cout << it2->first << " => " << it2->second << endl;


	return 0;
}