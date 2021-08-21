#include<bits/stdc++.h>
using namespace std;

struct node {
	int u;
	int v;
	int wt;
	node(int first,int second,int third)
	{
		u=first;
		v=second;
		wt=third;
	}
};

void solve()
{
	int vertices,edge,u,v,count=0,weight;
	cin>>vertices>>edge;
	vector<node> graph;
	vector<int> distance(vertices+1,1e9);
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v>>weight;
		graph.push_back(node(u,v,weight));
	}

	for(int i=1;i<vertices;i++)
	{
		for(auto it:graph)
		{
			if(distance[it.u]+it.wt<distance[it.v])
			{
				distance[it.u]=it.wt+distance[it.v];	
			}
		}
	}

	int flag=0;
	for(auto it:graph)
	{
		if(distance[it.u]+it.wt<distance[it.v])
		{
			flag=1;
			break;	
		}
	}
	if(flag==1)
		cout<<"There is a negative edge cycle.";
	else
		cout<<"There is no negative edge cycle.";
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