
#include <bits/stdc++.h>
using namespace std;
void minimumColors(int N, int E,
				int U[], int V[])
{
	vector<int> adj[N];
	vector<int> count(N, 0);
	vector<int> colors(N, 1);
	for (int i = 0; i < N; i++) {
		adj[V[i] - 1].push_back(U[i] - 1);
		count[U[i] - 1]++;
	}
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		if (count[i] == 0) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

	for (auto x : adj[u]) {
			count[x]--;

		if (count[x] == 0) {
				Q.push(x);
			}

		if (colors[x] <= colors[u]) {
				colors[x] = 1 + colors[u];
			}
		}
	}
	int minColor = -1;
	for (int i = 0; i < N; i++) {
		minColor = max(minColor, colors[i]);
	}
	cout << minColor << endl;
}
int main()
{
	int N = 5, E = 6;
	int U[] = { 1, 2, 3, 1, 2, 3 };
	int V[] = { 3, 3, 4, 4, 5, 5 };

	minimumColors(N, E, U, V);
	return 0;
}
