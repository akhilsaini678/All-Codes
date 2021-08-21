#include<bits/stdc++.h>
using namespace std;


// Best TC : O(nlogn)  Worst TC : O(n*n)  Average TC : O(nlogn)
int partition(vector<int> &arr,int low,int high)
{
	// Randomised Quick Sort
	// int random = low + rand() % (high - low);
    // swap(arr[random], arr[high]);
    // End of Random Selection
    
	int pivot=arr[high];
	int j=low-1;
	for(int i=low;i<high;i++)
	{
		if(arr[i]<pivot)
		{
			j++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[j+1],arr[high]);
	return j+1;
}

void quick_sort(vector<int> &arr,int low,int high)
{
	if(low<high)
	{
		int pi= partition(arr,low,high);
		quick_sort(arr,low,pi-1);
		quick_sort(arr,pi+1,high);
	}
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	quick_sort(arr,0,n-1);
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