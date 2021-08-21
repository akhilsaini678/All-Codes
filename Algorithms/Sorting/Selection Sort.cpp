#include<bits/stdc++.h>
using namespace std;


void selection_sort(vector<int> &arr)
{
	int n=arr.size();
	for(int i=0;i<n-1;i++)
	{
		int mini=arr[i];
		int index=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<mini)
			{
				mini=arr[j];
				index=j;
			}
		}
		swap(arr[i],arr[index]);
	}
}


void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	selection_sort(arr);
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