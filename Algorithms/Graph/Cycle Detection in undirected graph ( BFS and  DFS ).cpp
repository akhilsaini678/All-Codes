#include<bits/stdc++.h>
using namespace std;

// BFS code
bool cycle_detect_bfs(vector<int> graph[],int start,vector<int> visited)
{
	queue<pair<int,int>> q;
	q.push({start,-1});
	visited[start]=true;
	while(!q.empty())
	{
		pair<int,int> x= q.front();
		q.pop();
		for(auto i : graph[x.first])
		{
			if(visited[i]==0)
			{
				q.push({i,x.first});
				visited[i]=true;
			}
			else if(i!=x.second)
			{
				return true;
			}
		}
	}
	return false;
}


// DFS code
bool cycle_detect(vector<int> graph[],int start,int pre,vector<int> &visited)
{
	visited[start]=true;
	for(auto i : graph[start])
	{
		if(visited[i]==0)
			if(cycle_detect(graph,i,start,visited)) return true;
		else if(i!=pre)
			return true;
	}
	return false;
}

void solve()
{
	int node,edge,u,v;
	cin>>node>>edge;
	bool check;
	vector<int> graph[node+1];
	vector<int> visited(node+1,0);
	for(int i=0;i<node;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1;i<=node;i++)
	{
		if(visited[i]==0)
		{
			// check = cycle_detect_dfs(graph,i,-1,visited);
			check = cycle_detect_bfs(graph,i,visited);
			if(check==true)
				break;
		}
	}
	if(check==true)
	cout<<"Graph has a cycle.";
	else
	cout<<"Graph has no cycle.";	
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