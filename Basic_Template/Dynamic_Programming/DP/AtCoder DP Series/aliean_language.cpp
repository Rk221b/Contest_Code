#include<bits/stdc++.h>
#include<set>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

	void topoSortUtil(int v,bool visited[],stack<int> &st);
	public:
	Graph(int V);
	void addEdge(int v,int w);
	void topoSort();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}


void Graph:: topoSortUtil(int v,bool visited[],stack<int> &st){
	visited[v] = true;
	list<int>::iterator i;

	for(i=adj[v].begin();i!=adj[v].end();i++)
		if(!visited[*i])
			topoSortUtil(*i,visited,st);

	st.push(v);
}


void Graph::topoSort(){

	stack<int> st;
	bool *visited = new bool[V];

	for(int i=0;i<V;i++)
	visited[i] = false;

	for(int i=0;i<V;i++)
		if(visited[i] == false)
			topoSortUtil(i,visited,st);

	while(!st.empty()){
		cout<<(char)('a'+st.top());
		st.pop();
	}
}

void solve(vector<string> s, int n, int alp){
	Graph g(alp);

	for(int i=0;i<n-1;i++){
		string w1 = s[i],w2 = s[i+1];

		for(int j=0;j<min(w1.length(),w2.length());j++){
			if(w1[j] != w2[j]){
				g.addEdge(w1[j]-'a',w2[j]-'a');
				break;
			}
		}
	}
	g.topoSort();
}


int main(){

	vector<string> s;
	string t;
	int num = 3;

	while(num--){
        cin>>t;
		s.push_back(t);
	}
	int len = 0;
	set<char> uniq;

	for(int i=0;i<s.size();i++){
		for(int j=0;j<s[i].length();j++){
			uniq.insert(s[i][j]);
		}
	}

	len = uniq.size();

	solve(s,s.size(),len);

	return 0;
}
