#include<bits/stdc++.h>
using namespace std;

vector<int> parent(10000);
vector<int> ranked(10000);

struct node {
	int wt;
	int u;
	int v;
	node(int first,int second,int third)
	{
		wt=first;
		u=second;
		v=third;
	}
};

bool cmp(node a, node b)
{
	return a.wt<b.wt;
}

int find_parent(int node)
{
	if(node==parent[node])
		return node;

	return parent[node] = find_parent(parent[node]);
}

void union_(int u,int v)
{
	int x = find_parent(u);
	int y = find_parent(v);

	if(ranked[x]<ranked[y])
		parent[x]=y;
	else if(ranked[x]>ranked[y])
		parent[y]=x;
	else
	{
		parent[x]=y;
		ranked[y]++;
	}
}

void solve()
{
	int vertices,edge,u,v,weight,cost=0;
	cin>>vertices>>edge;
	vector<node> graph;
	vector<pair<int,int>> mst;
	for(int i=0;i<vertices;i++)
	{
		parent[i]=i;
		ranked[i]=0;
	}
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v>>weight;
		graph.push_back(node(weight,u,v));
	}
	sort(graph.begin(),graph.end(),cmp);
	for(int i=0;i<edge;i++)
	{
		if(find_parent(graph[i].u)!=find_parent(graph[i].v))
		{
			union_(graph[i].u,graph[i].v);
			mst.push_back({graph[i].u,graph[i].v});
			cost+=graph[i].wt;
		}
	}
	cout<<cost<<endl;
	for(auto it:mst) cout<<it.first<<" -> "<<it.second<<endl;
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