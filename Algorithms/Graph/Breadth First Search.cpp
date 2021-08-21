#include<bits/stdc++.h>
using namespace std;


void bfs(vector<int> graph[],int n,int start)
{
	int visited[n+1]={0};
	queue<int> q;
	q.push(start);
	visited[start]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		cout<<x<<endl;
		for(int i=0;i<graph[x].size();i++)
		{
			if(visited[graph[x][i]]==false)
			{
				q.push(graph[x][i]);
				visited[graph[x][i]]=true;
			}
		}
	}
}


void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> graph[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs(graph,n,1);
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