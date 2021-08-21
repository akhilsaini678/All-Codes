#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(n) and Space Complexity : O(n)
long long int fibonacci(long long int n,vector<long long int> &dp)
{
	if(n<=2) return 1;
	if(dp[n]!=-1)
		return dp[n];
	return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
}

void solve()
{
	long long int n;
	cin>>n;
	vector<long long int> dp(n+1,-1);
	cout<<fibonacci(n,dp)<<endl;
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