#include<bits/stdc++.h>
using namespace std;


void dijkstra(vector<int> graph[], int start,vector<int> &distance)
{
	queue<int> q;
	q.push(start);
	distance[start]=0;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(auto i: graph[x])
		{
			if(distance[x]+1<distance[i])
			{
				distance[i]=distance[x]+1;
				q.push(i);
			}
		}
	}
}

void solve()
{
	int node,edge,u,v;
	cin>>node>>edge;
	vector<int> graph[node+1];
	vector<int> distance(node+1,1e9+7);
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dijkstra(graph,0,distance);
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