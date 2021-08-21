#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n) and Space Complexity : O(n)
int count_subarray_xor(vector<int> &arr,int n,int k)
{
	unordered_map<int,int> maps;
	int ans=0;
	int prexor=0;
	for(int i=0;i<n;i++)
	{
		prexor=prexor^arr[i];
		if(prexor==k)
			ans++;
		if(maps.find(prexor^k)!=maps.end())
			ans=ans+maps[prexor^k];
		maps[prexor]++;
	}
	return ans;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	int k;
	cin>>k;
	cout<<count_subarray_xor(arr,n,k)<<endl;	
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