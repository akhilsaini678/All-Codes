#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[],int start,vector<int> &visited)
{
	cout<<start<<endl;
	visited[start]=true;
	for(int i=0;i<graph[start].size();i++)
	{
		if(visited[graph[start][i]]==0)
			dfs(graph,graph[start][i],visited);
	}	 
}


void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> graph[n+1];
	vector<int> visited(n+1,0);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(visited[i]==0)
			dfs(graph,i,visited);
}

void fast()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("D:\\Online\\Coding\\Contest\\input.txt","r",stdin);
	freopen("D:\\Online\\Coding\\Contest\\output.txt","w",stdout);
	#endif
}

int main()
{
	fast();
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}