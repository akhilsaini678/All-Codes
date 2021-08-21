#include<bits/stdc++.h>
using namespace std;

vector<int> parent(10000);
vector<int> ranked(10000);

int find_parent(int node)
{
	if(node==parent[node])
		return node;

	return parent[node] = find_parent(parent[node]);
}

void union_(int u,int v)
{
	int x=find_parent(u);
	int y=find_parent(v);

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
	int node,edge,u,v;
	cin>>node>>edge;
	vector<int> graph[node+1];
	for(int i=0;i<node;i++)
		parent[i]=i,ranked[i]=0;
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		union_(u,v);
	}

	if(find_parent(2)!=find_parent(3))
		cout<<"They belong to different component.";
	else
		cout<<"They belong to the same component.";
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