#include<bits/stdc++.h>
using namespace std;


void dijkstra(vector<pair<int,int>> graph[], int start,vector<int> &distance,stack<int> st)
{
	distance[start]=0;
	while(!st.empty())
	{
		int x = st.top();
		st.pop();
		if(distance[x]!=1e9+7)
		{
			for(auto i: graph[x])
			{
				if(distance[x]+i.second<distance[i.first])
				{
					distance[i.first]=distance[x]+i.second;
				}
			}
		}
	}
}

void topological_sort(vector<pair<int,int>> graph[],int start,vector<int> &visited,stack<int> &st)
{
	visited[start]=1;
	for(auto i:graph[start])
	{
		if(visited[i.first]==0)
			topological_sort(graph,i.first,visited,st);
	}
	st.push(start);
}

void solve()
{
	int node,edge,u,v,weight;
	cin>>node>>edge;
	vector<pair<int,int>> graph[node+1];
	vector<int> distance(node+1,1e9+7),visited(node+1,0);
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v>>weight;
		graph[u].push_back({v,weight});
		// graph[v].push_back({u,weight});
	}
	stack<int> st;
	topological_sort(graph,0,visited,st);
	dijkstra(graph,0,distance,st);
	for(int i=0;i<node;i++)
	{
		cout<<distance[i]<<" ";
	}
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