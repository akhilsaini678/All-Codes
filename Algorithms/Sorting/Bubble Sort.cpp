#include<bits/stdc++.h>
using namespace std;

// Best TC : O(n)  Worst TC : O(n*n)  Average TC : O(n*n)
void bubble_sort(vector<int> &arr)
{
	bool swaps=false;
	int  n=arr.size();
	for(int i=0;i<n-1;i++)
	{
		swaps=false;
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swaps=true;
			}
		}
		if(swaps==false)
			return;
	}
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	bubble_sort(arr);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
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