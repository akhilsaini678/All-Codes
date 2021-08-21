#include<bits/stdc++.h>
using namespace std;

// Time complexity : O(n^3) and Space complexity : O(1);
int max_sum(vector<int> &arr)
{
	int ans=0;
	int n=arr.size();
	/*for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
			{
				sum=sum+arr[k];
			}
			ans=max(ans,sum);
		}
	}*/

	// A slight modification ( Time Complexity : O(n^2));
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=i;j<n;j++)
		{
			sum=sum+arr[j];
			ans=max(ans,sum);
		}
	}
	return ans;
}

// Time complexity : O(n) and Space complexity : O(1);
/*int max_sum1(vector<int> &arr)
{
	int ans=arr[0],sum=0;
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		sum=sum+arr[i];
		ans=max(ans,sum);
		if(sum<0)
			sum=0;
	}
	return ans;
}*/

int max_sum1(vector<int> &arr)
{
	int sum=0,n=arr.size();
	int ans=arr[0];
	for(int i=0;i<n;i++)
	{
		sum=sum+arr[i];
		ans=max(ans,sum);
		if(sum<0)
			sum=0;
	}
	return ans;
}


void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<max_sum1(arr)<<endl;
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
1
6
3 2 -4 4 6 -10
*/