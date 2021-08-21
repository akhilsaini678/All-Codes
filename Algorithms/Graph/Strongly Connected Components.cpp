#include<bits/stdc++.h>
using namespace std;

void scc(vector<int> graph[],int start,vector<int> &visited,stack<int> &st)
{
	visited[start]=1;
	for(auto it:graph[start])
	{
		if(visited[it]==0)
		{
			scc(graph,it,visited,st);
		}
	}
	st.push(start);
}

void rev(vector<int> graph[],int start,vector<int> &visited)
{
	visited[start]=1;
	// cout<<start<<" ";
	for(auto it:graph[start])
	{
		if(visited[it]==0)
		{
			rev(graph,it,visited);
		}
	}
}


void solve()
{
	int node,edge,u,v,count=0,weight;
	cin>>node>>edge;
	vector<int> graph[node+1];
	vector<int> visited(node+1,0);
	stack<int> st;
	for(int i=0;i<node;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
	}
	for(int i=0;i<node;i++)
	{
		if(visited[i]==0)
		scc(graph,i,visited,st);		
	}
	vector<int> transpose[node+1];
	for(int i=0;i<node;i++)
	{
		visited[i]=0;
		for(auto it:graph[i])
		{
			transpose[it].push_back(i);
		}
	}
	while(!st.empty())
	{
		int x = st.top();
		// cout<<x<<endl;
		st.pop();
		if(visited[x]==0)
		{
			count++;
			rev(transpose,x,visited);
			// cout<<endl;
		}
	}
	cout<<count<<endl;
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