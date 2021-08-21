#include<bits/stdc++.h>
using namespace std;


// Using BFS
bool cycle_detect_bfs(vector<int> graph[],int start,vector<int> &visited,vector<int> &indegree)
{
	queue<int> q;
	for(int i=0;i<indegree.size();i++)
		if(indegree[i]==0)
		{
			q.push(i);
			visited[i]=1;
		}

	int count=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		// cout<<x<<endl;
		count++;
		for(auto i: graph[x])
		{
			indegree[i]--;
			if(indegree[i]==0)
			{
				q.push(i);
				visited[i]=1;
			}
		}
	}
	if(count==indegree.size())
		return false;
	else
		return true;
}




// Using DFS
bool cycle_detect_dfs(vector<int> graph[],int start,vector<int> &visited,vector<int> &local_visited)
{
	visited[start]=1;
	local_visited[start]=1;
	for(auto i:graph[start])
	{
		if(visited[i]==0)
		{
			if(cycle_detect_dfs(graph,i,visited,local_visited)) return true;
		}
		else if(local_visited[i]==1)
			return  true;
	}
	local_visited[start]=0;
	return false;
}

void solve()
{
	int node,edge,u,v;
	cin>>node>>edge;
	bool check=false,bfs=false;
	vector<int> graph[node+1];
	vector<int> visited(node+1,0),local_visited(node+1,0),indegree(node,0);
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		// graph[v].push_back(u);
	}

	for(int i=0;i<node;i++)
	{
		for(auto j: graph[i])
			indegree[j]++;
	}


	for(int i=0;i<node;i++)
	{
		if(visited[i]==0)
		{
		if(bfs==false&&cycle_detect_dfs(graph,i,visited,local_visited))
		{
			check=true;
			break;
		}

		if(bfs&&cycle_detect_bfs(graph,i,visited,indegree))
		{
			check=true;
			break;
		}
		}
	}
	if(check==true)
		cout<<"Graph has a cycle."<<endl;
	else
		cout<<"Graph has no cycle."<<endl;
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