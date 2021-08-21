#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int,int>> graph[],int start,vector<int> &distance)
{
	 set<pair<int,int>> st;
	// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	st.insert({0,start});
	// pq.push({0,start});
	distance[start]=0;
	while(!st.empty())
	{
		pair<int,int> x = *(st.begin());
		// pq.pop();
		st.erase(st.begin());
		for(auto i : graph[x.second])
		{
			if(distance[x.second]+i.second<distance[i.first])
			{
				if(distance[i.first]!=1e9)
				{
					st.erase(st.find({distance[i.first],i.first}));
				}
				distance[i.first]=distance[x.second]+i.second;
				st.insert({distance[i.first],i.first});
				// pq.push({distance[i.first],i.first});
			}
		}
	}
}

void solve()
{
	int node,edge,u,v,weight;
	cin>>node>>edge;
	vector<pair<int,int>> graph[node+1];
	vector<int> distance(node+1,1e9);
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v>>weight;
		graph[u].push_back({v,weight});
		graph[v].push_back({u,weight});
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