#include<bits/stdc++.h>
using namespace std;

// One solution can be generating all the subarray and then finding out the largest subarray with sum 0. Which will result into O(n^3)
// Time Complexity : O(n) and Space Complexity : O(n)
int lsws0(vector<int> &arr,int n)
{
	unordered_map<int,int> maps;
	int sum=0,ans=0;
	for(int i=0;i<n;i++)
	{
	    sum=sum+arr[i];
	    if(sum==0)
			ans=max(ans,i+1);
		else if(maps.find(sum)!=maps.end())
			    ans=max(ans,i-maps[sum]);
			 else
			    maps[sum]=i;
	}
	return ans;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<lsws0(arr,n)<<endl;	
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