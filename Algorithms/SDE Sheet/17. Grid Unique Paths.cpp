#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(n) and Space Complexity : O(n)
// Recursive Approach
long long int recursion(long long int i,long long int j,long long int n,long long int m,vector<vector<long long int>> &dp)
{
	long long int mod=1e9+7;
	if(i==n-1&&j==m-1)
		return 1;
	if(i>=n||j>=m)
		return 0;

	// DP approach
	if(dp[i][j]!=-1)
		return dp[i][j];
	dp[i][j] = ((recursion(i+1,j,n,m,dp)+recursion(i,j+1,n,m,dp))%(mod));
	return dp[i][j];
}

// Cominatorial Approach
long long int fun(int n,int m)
{
	int N=n+m-2;
	int R=n-1;
	int mod=1e9+7;
	long long int ans = 1;

	for(int i=1;i<=R;i++)
	{
		ans=((ans*(N-R+i))/i)%mod;
	}
	return ans;
}

void solve()
{
	long long int n,m;
	cin>>n>>m;
	vector<vector<long long int>> dp(n,vector<long long int> (m,-1));
	cout<<fun(n,m)<<endl;
	cout<<recursion(0,0,n,m,dp)<<endl;
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