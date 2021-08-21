#include<bits/stdc++.h>
using namespace std;


void counting_sort(vector<int> &arr)
{
	int n=arr.size(),range=0;
	for(int i=0;i<n;i++) range=max(range,arr[i]);
	vector<int> count(range+1,0),output(n);
	for(int i=0;i<n;i++)
		count[arr[i]]++;

	for(int i=1;i<=range;i++)
	{
		count[i]+=count[i-1];
		cout<<count[i]<<" ";
	}
	cout<<endl;
	
	for(int i=n-1;i>=0;i--)
	{
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}

	for(int i=0;i<n;i++)
		arr[i]=output[i];
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	counting_sort(arr);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
}

void fast()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("C:\\Data\\Online\\Coding\\Contest\\input.txt","r",stdin);
	freopen("C:\\Data\\Online\\Coding\\Contest\\output.txt","w",stdout);
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