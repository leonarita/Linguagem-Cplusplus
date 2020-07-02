/*
	Generates all subsets of a set using backtracking
	Author: Marcos Castro
*/

#include <iostream>
#include <vector>

using namespace std;

// generates all subsets
void generate(int k, vector<bool> & my_set, int N)
{
	if(k == N)
	{
		// shows the subset
		cout << "{ ";
		for(int i = 0; i < N; i++)
		{
			if(my_set[i] == true)
				cout << i + 1 << " ";
		}
		cout << "}\n";
	}
	else
	{
		my_set[k] = true;
		generate(k + 1, my_set, N);
		my_set[k] = false; // backtracking
		generate(k + 1, my_set, N);
	}
}

int main(int argc, char *argv[])
{
	int N;

	cin >> N;

	vector<bool> my_set(N);

	generate(0, my_set, N);

	return 0;
}
