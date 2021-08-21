#include<bits/stdc++.h>
using namespace std;

// Best TC : O(n)  Worst TC : O(n*n)  Average TC : O(n*n)
void insertion_sort(vector<int> &arr)
{
	int n=arr.size();
	for(int i=1;i<n;i++)
	{
		int x=arr[i];
		int j=i-1;
		while(x<arr[j]&&j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}
		j++;
		arr[j]=x;
	}
}


void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	insertion_sort(arr);
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