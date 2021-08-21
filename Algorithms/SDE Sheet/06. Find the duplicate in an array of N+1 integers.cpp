#include<bits/stdc++.h>
using namespace std;


// One way can be sorting and then time complexity will be O(nlogn);
// Other way can be using hasing and then time complexity will be O(n) and space complexity will be O(n);
// Time complexity : O(n) and Space complexity : O(1);
int duplicate(vector<int> &arr)
{
	int slow=arr[0];
	int fast=arr[0];
	do {
		slow=arr[slow];
		cout<<slow<<fast<<endl;
		fast=arr[arr[fast]];
	}
	while(slow!=fast);

	int tmp=arr[0];
	while(slow!=tmp)
	{
		slow=arr[slow];
		tmp=arr[tmp];
	}
	return slow;
}


void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<duplicate(arr)<<endl;
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