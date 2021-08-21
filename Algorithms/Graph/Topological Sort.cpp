#include<bits/stdc++.h>
using namespace std;


void topological_sort(vector<int> graph[],int start,vector<int> &visited,stack<int> &st)
{
	visited[start]=1;
	for(auto i : graph[start])
	{
		if(visited[i]==0)
			topological_sort(graph,i,visited,st);
	}
	st.push(start);
}

void solve()
{
	int node,edge,u,v;
	cin>>node>>edge;
	vector<int> graph[node+1];
	vector<int> visited(node+1,0),vec;
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
	}
	stack<int> st;
	for(int i=0;i<node;i++)
	{
		if(visited[i]==0)
		topological_sort(graph,i,visited,st);
	}
	while(!st.empty())
	{
		vec.push_back(st.top());
		st.pop();
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