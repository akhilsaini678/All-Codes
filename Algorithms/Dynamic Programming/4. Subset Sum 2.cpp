#include<bits/stdc++.h>
using namespace std;
#define ll long long int


// Time Complexity : O(n) and Space Complexity : O(n)
bool subset_sum(vector<ll> &arr,ll target,vector<ll> &dp)
{
	if()
}

void solve()
{
	ll n,target;
	cin>>n;
	vector<ll> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cin>>target;
	vector<ll> dp(target+10,-1);
	cout<<subset_sum(arr,target,dp)<<endl; 
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