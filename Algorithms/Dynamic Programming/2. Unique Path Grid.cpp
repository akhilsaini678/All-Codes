#include<bits/stdc++.h>
using namespace std;
#define ll long long int


// Time Complexity : O(n) and Space Complexity : O(n)
ll path(ll i,ll j,ll n,ll m,vector<vector<ll>> &dp)
{
	if(i==n-1&&j==m-1)
		return 1;
	if(i>=n||j>=m)
		return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	return dp[i][j] = path(i+1,j,n,m,dp) + path(i,j+1,n,m,dp);
}

void solve()
{
	ll n,m;
	cin>>n>>m;
	vector<vector<ll>> dp(n+100,vector<ll> (m+100,-1));
	cout<<path(0,0,n,m,dp)<<endl; 
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