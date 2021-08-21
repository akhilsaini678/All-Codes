#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int node,edge,u,v,weight,cost=0;
	cin>>node>>edge;
	vector<pair<int,int>> graph[node];
	vector<int> parent(node,-1),key(node,1e9);
	vector<bool> mst(node,false);
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v>>weight;
		graph[u].push_back({v,weight});
		graph[v].push_back({u,weight});
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
	key[0]=0;
	pq.push({0,0});
	while(!pq.empty())
	{	
		int u=pq.top().second;
		pq.pop();
		mst[u]=true;
		for(auto it:graph[u])
		{
			int v=it.first;
			int weight=it.second;
			if(mst[v]==false&&weight<key[v])
			{
				key[v]=weight;
				parent[v]=u;
				pq.push({key[v],v});
			}
		}
	}
	for(int i=0;i<node;i++)
	{
		cost=cost+key[i];
		cout<<key[i]<<"  ";
	}
	cout<<endl;
	cout<<cost<<endl;
	for(int i=1;i<node;i++)
	{
		cout<<parent[i]<<" - "<<i<<endl;
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