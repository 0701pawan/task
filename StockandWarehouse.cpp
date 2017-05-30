#include <iostream>
#include <stdlib.h>
#include <list>
#include <map>

using namespace std;

list<int> *ever = new list<int>[20];
int varever = 0;

class Graph{
		int v;
		list<int> *adj;
		map<int, double> *weigh;
		void allPathUtil(int, int, bool [], int [], int &);
	public:
		Graph(int v);
		void addEdge(int v, int w, double weight);
		void allPath(int s, int d);
		double getWeight(int v, int w);
};


double Graph::getWeight(int v, int w){
	return weigh[v][w];
}

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v];
	weigh = new map<int, double>[v];
}

void Graph::addEdge(int v, int w, double weight){
	adj[v].push_back(w);
	weigh[v][w] = weight;
}

void Graph::allPath(int s, int d){
	bool *visited = new bool[v];
	int *path = new int[v];
	int path_index = 0;
	for(int i=0; i<v; i++){
		visited[i] = false;
	}
	allPathUtil(s, d, visited, path, path_index);
}

void Graph::allPathUtil(int u, int d, bool visited[], int path[], int &path_index){
	bool check_visit = true;
	for(int p = 1; p < this->v; p++)
		check_visit = check_visit&&visited[p]; 
	if(check_visit)
		visited[d] = true;
	if(u!=d)
		visited[u] = true;
	path[path_index] = u;
	path_index++;

	if (u==d && visited[d])
	{
		for(int i=0; i<path_index; i++){
			ever[varever].push_back(path[i]);
		}
		varever++;

	}
	else
	{
		list<int>::iterator i;
		for(i=adj[u].begin(); i!=adj[u].end(); i++)
			if(!visited[*i])
				allPathUtil(*i, d, visited, path, path_index);
	}
	path_index--;
	visited[u] = false;
}

void shuffle_values(int status, double&shu1, 
					double&shu2, double&shu3){
	double temp;
	switch(status){

			case 2	:	shu1 = shu3;
						break;	

			case 3	:	shu2 = shu3;
						break;

			case 4	:	shu1 = shu1;
						break;

			case 5	:	shu1 = shu2;
						break;

			case 6	:	shu1 = shu3;
						break;
	}
}

int main(){
	int q, w, e, r, t, y, u, a, s;
	cin >> q >> w >> e;
	cin >> r >> t >> y;
	cin >> u >> a >> s;
	double c1 = q*3 + w*2 + e*8;
	double c2 = r*12 + t*25 + y*15;
	double c3 = u*0.5 + a + s*2;
	Graph *g;
	int status;
	if(c1&&c2&&c3)
	{
		g = new Graph(4);
		g->addEdge(0, 1, 3);
		g->addEdge(0, 2, 2.5);
		g->addEdge(0, 3, 2);
		g->addEdge(1, 0, 3);
		g->addEdge(1, 2, 4);
		g->addEdge(2, 0, 2.5);
		g->addEdge(2, 1, 4);
		g->addEdge(2, 3, 3);
		g->addEdge(3, 0, 2);
		g->addEdge(3, 2, 3);
		g->allPath(1,0);
		g->allPath(2,0);
		g->allPath(3,0);
		status = 0;
	}
	else if(c1&&c2 || c1&&c3 || c3&&c2){
		g = new Graph(3);
		if(c1&&c2){
			g->addEdge(0, 1, 3);
			g->addEdge(0, 2, 2.5);
			g->addEdge(1, 0, 3);
			g->addEdge(1, 2, 4);
			g->addEdge(2, 0, 2.5);
			g->addEdge(2, 1, 4);
			g->allPath(1,0);
			g->allPath(2,0);
			status = 1;
		}
		if(c2&&c3){
			g->addEdge(0, 2, 2.5);
			g->addEdge(0, 1, 2);
			g->addEdge(2, 0, 2.5);
			g->addEdge(2, 1, 3);
			g->addEdge(1, 0, 2);
			g->addEdge(1, 2, 3);
			g->allPath(2,0);
			g->allPath(1,0);
			status = 2;
		}
		if(c1&&c3){
			g->addEdge(0, 1, 3);
			g->addEdge(0, 2, 2);
			g->addEdge(1, 0, 3);
			g->addEdge(2, 0, 2);
			g->allPath(1,0);
			g->allPath(2,0);
			status = 3;
		}
	}
	else if(c1 || c2 || c3){
		g = new Graph(2);
		if(c1){
			g->addEdge(0, 1, 3);
			g->addEdge(1, 0, 3);
			g->allPath(1,0);
			status = 4;
		}
		if(c2){
			g->addEdge(0, 1, 2.5);
			g->addEdge(1, 0, 2.5);
			g->allPath(1,0);
			status = 5;
		}
		if(c3){
			g->addEdge(0, 1, 2);
			g->addEdge(1, 0, 2);
			g->allPath(1,0);
			status = 6;
		}
	}
	double sum = 0;
	int hold = 0;
	int i;
	double weight;
	int min_sum;
	shuffle_values(status, c1, c2, c3);
	for(i=0; i<varever; i++){
		list<int>::iterator j;
		list<int>::iterator k;
		for(j=ever[i].begin(); j!=ever[i].end(); j++){
			k = j;
			if(*j == 1)
				hold += c1;
			if(*j == 2)
				hold += c2;
			if(*j == 3)
				hold += c3;
			if(*j == 0)
				hold = 0;
			k++;
			if(k != ever[i].end())
				weight = g->getWeight(*j, *k);
			else
				weight = 0;
			sum += weight*(8*(int)(hold/5) + 10);
		}
		if(i == 0)
			min_sum = sum;
		if(sum < min_sum)
			min_sum = sum;
		sum = 0;
	}
	cout << min_sum << endl;
	if(!varever)
		cout << 0 << endl;
	return 0;
}
