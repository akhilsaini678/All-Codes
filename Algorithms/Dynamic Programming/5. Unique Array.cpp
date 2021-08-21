#include<bits/stdc++.h>
using namespace std;
#define ll long long int


// Time Complexity : O(n) and Space Complexity : O(n)
ll consecutive_ways(vector<vector<ll>> &dp,int n,int k,int x,int start,int index)
{
	int mod=1e9+7;
	if(index==n)
	{
		if(start==x)
		return 1;
		else
		return 0;
	}

	if(dp[index][start]!=0)
		return dp[index][start];

	int ans=0;
	for(int i=1;i<=k;i++)
	{
		if(i!=start)
		dp[index][start]=(dp[index][start]+consecutive_ways(dp,n,k,x,i,index+1))%mod;
	}
	return dp[index][start];
}

void solve()
{
	ll n,k,x,m;
	cin>>n>>k>>x;
	vector<vector<ll>> dp(n+100,vector<ll> (n+100,0));
	cout<<consecutive_ways(dp,n,k,x,1,1)<<endl; 
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