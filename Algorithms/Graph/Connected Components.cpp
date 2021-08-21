#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> graph[],int start,vector<int> &visited)
{
	queue<int> q;
	q.push(start);
	visited[start]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		cout<<x<<endl;
		for(int i=0;i<graph[x].size();i++)
		{
			if(visited[graph[x][i]]==0)
			{
				q.push(graph[x][i]);
				visited[graph[x][i]]=1;
			}
		}
	}
}

void solve()
{
	int n,m,u,v,count=0;
	cin>>n>>m;
	vector<int> graph[n+1];
	vector<int> visited(n+1,0);
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			count++;
			bfs(graph,i,visited);	
		}
	}
	cout<<count<<endl;
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
	while(t--) solve();
	return 0;
}