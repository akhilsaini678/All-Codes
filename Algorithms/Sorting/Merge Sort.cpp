#include<bits/stdc++.h>
using namespace std;


// Best TC : O(nlogn)  Worst TC : O(nlogn)  Average TC : O(nlogn)
void merge(vector<int> &arr,int low,int mid,int high)
{
	int L=mid+1-low,R=high-mid,k=low;
	int left[L],right[R];
	for(int i=0;i<L;i++) left[i]=arr[k++];
	for(int i=0;i<R;i++) right[i]=arr[k++];
	int i=0,j=0;
	k=low;
	while(i<L&&j<R)
		arr[k++]= (left[i]<right[j])?left[i++]:right[j++];
	while(i<L)
		arr[k++]=left[i++];
	while(j<R)
		arr[k++]=right[j++];
}

void merge_sort(vector<int> &arr,int low,int high)
{
	if(low<high)
	{
	int mid=(low+high)/2;
	merge_sort(arr,low,mid);
	merge_sort(arr,mid+1,high);

	merge(arr,low,mid,high);
	}
}



void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	merge_sort(arr,0,n-1);
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