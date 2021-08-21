#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(nlogn+n+n) and Space Complexity : O(n)
   long long int merge_sort(vector<int> &arr,long long int low,long long int mid,long long int high)
{
	long long int L=mid+1-low;
	long long int R=high-mid;
	long long int k=low;
	long long int ans=0,jj=mid+1;
	for(long long int i=low;i<=mid;i++)
	{
		while(jj<=high&&(2LL*arr[jj])<arr[i])
		{
			jj++;
		}
		ans=ans+jj-mid-1;
	}
	vector<long long int> left(L),right(R);
	for(long long int i=0;i<L;i++) left[i]=arr[k++];
	for(long long int i=0;i<R;i++) right[i]=arr[k++];
	k=low;
	long long int i=0,j=0;
	while(i<L&&j<R)
	{
		arr[k++] = (left[i]<right[j])?left[i++]:right[j++];
	}
	while(i<L)
	{
		arr[k++] = left[i++];
	}
	while(j<R)
	{
		arr[k++] = right[j++];
	}
	return ans;
}

long long int merge(vector<int> &arr,long long int low,long long int high)
{
	long long int ans=0;
	if(low<high)
	{
		long long int mid=(low+high)/2;
		ans=ans+merge(arr,low,mid);
		ans=ans+merge(arr,mid+1,high);
		ans=ans+merge_sort(arr,low,mid,high);
	}
	return ans;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<merge(arr,0,n-1)<<endl;
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


/*
Test Case :
1
7
40 25 19 12 9 6 2
*/