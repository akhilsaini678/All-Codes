#include<bits/stdc++.h>
using namespace std;

void articulation_in_graph(vector<int> graph[],int start,int parent,int &timer,vector<int> &intime,vector<int> &lowtime,vector<int> &visited,vector<int> &articulation_points)
{
	intime[start]=lowtime[start]=timer++;
	visited[start]=1;
	int child=0;
	for(auto i: graph[start])
	{
		if(i==parent) continue;
		if(visited[i]==0)
		{
			articulation_in_graph(graph,i,start,timer,intime,lowtime,visited,articulation_points);
			lowtime[start]=min(lowtime[start],lowtime[i]);
			if(lowtime[i]>=intime[start]&&parent!=-1)
			{
				articulation_points[start]=1;
			}
			child++;
		}
		else
		{
			lowtime[start]=min(lowtime[start],intime[i]);
		}
	}
	if(child>1&&parent!=-1)
	{
		articulation_points[start]=1;
	}
}

void solve()
{
	int node,edge,u,v,weight;
	cin>>node>>edge;
	vector<int> graph[node+1];
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v>>weight;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> visited(node+1,0);
	vector<int> intime(node+1);
	vector<int> lowtime(node+1);
	vector<int> articulation_points(node+1,0);
	int timer=0;
	for(int i=0;i<node;i++)
	{
		if(visited[i]==0)
		articulation_in_graph(graph,i,-1,timer,intime,lowtime,visited,articulation_points);	
	}
	for(int i=0;i<node;i++)
	{
		(articulation_points[i]==1)?(cout<<i<<endl):cout<<"";
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