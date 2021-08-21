#include<bits/stdc++.h>
using namespace std;


// DFS code
bool bipartite_graph_dfs(vector<int> graph[],int start,int pre, vector<int> &color)
{
	color[start]=1-pre;
	for(auto i: graph[start])
	{
		if(color[i]==-1)
		{
			color[i]=1-color[start];
			if(!bipartite_graph_dfs(graph,i,color[start],color)) return false;
		}
		else if(color[i]==color[start])
			return false;
	}
	return true;
}



// BFS code
bool bipartite_graph_bfs(vector<int> graph[],int start, vector<int> &color)
{
	queue<int> q;
	q.push(start);
	color[start]=0;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for( auto i: graph[x])
		{
			if(color[i]==-1)
			{
				q.push(i);
				color[i]=1-color[x];
			}
			else if(color[x]==color[i])
			{
				return false;
			}
		}
	}
	return true;
}


void solve()
{
	int node,edge,u,v,count=0;
	cin>>node>>edge;
	vector<int> graph[node+1];
	bool check=true,bfs=false;
	vector<int> color(node+1,-1);
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1;i<=node;i++)
	{
		if(color[i]==-1)
		{
			count++;
			// cout<<i<<endl;
			if(!bfs&&!bipartite_graph_dfs(graph,i,1,color))
			{
				check=false;
				break;
			}

			if(bfs&&!bipartite_graph_bfs(graph,i,color))
			{
				check=false;
				break;
			}
		}
	}
	for(int i=1;i<node+1;i++) cout<<color[i]<<" ";
	if(check==true)
		cout<<"Graph is Bipartite Graph"<<endl;
	else
		cout<<"Graph is not Bipartite Graph"<<endl;
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