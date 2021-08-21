#include<bits/stdc++.h>
using namespace std;


void topological_sort(vector<int> graph[],int start,vector<int> &visited,vector<int> &degree,vector<int> &vec)
{
	queue<int> q;
	for(int i=0;i<degree.size();i++)
		if(degree[i]==0)
		{
			visited[i]=true;
			q.push(i);
		}
	while(!q.empty())
	{
		int x = q.front();
		vec.push_back(x);
		q.pop();
		for(auto i : graph[x])
		{
			degree[i]--;
			if(degree[i]==0)
			{
				q.push(i);
				visited[i]=true;
			}
		}
	}

}

void solve()
{
	int node,edge,u,v;
	cin>>node>>edge;
	vector<int> graph[node+1];
	vector<int> visited(node+1,0),vec,degree(node);
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
	}
	for(int i=0;i<node;i++)
	{
		for(auto j:graph[i])
		degree[j]++;
	}
	for(int i=0;i<node;i++)
	{
		if(visited[i]==0)
		topological_sort(graph,i,visited,degree,vec);
	}
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<endl;
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