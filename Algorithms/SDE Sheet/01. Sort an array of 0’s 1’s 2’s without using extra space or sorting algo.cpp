#include<bits/stdc++.h>
using namespace std;

// Time complexity : O(2N) and Space complexity : O(1);
/*void counting_sort(vector<int> &arr)
{
	int zero=0,one=0,two=0,n=arr.size();
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0) zero++;
		if(arr[i]==1) one++;
		if(arr[i]==2) two++;
	}
	for(int i=0;i<n;i++)
	{
		if(zero>0)
		{
			zero--;
			arr[i]=0;
		}
		else if(one>0)
		{
			one--;
			arr[i]=1;
		}
		else
			arr[i]=2;
	}
}*/


// Time complexity : O(N) and Space complexity : O(1);
void dutch_national_flag(vector<int> &arr)
{
	int n=arr.size();
	int low=0,mid=0,high=n-1;
	while(mid<=high)
	{
		switch(arr[mid]){

			case 0: swap(arr[mid++],arr[low++]);
			break;
			case 1: mid++;
			break;
			case 2:
			swap(arr[mid],arr[high--]);
		}
	}
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	dutch_national_flag(arr);
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

/*
Test Case :
Input :
1
6
2 2 0 1 1 2
Output :
0 1 1 2 2 2
*/
