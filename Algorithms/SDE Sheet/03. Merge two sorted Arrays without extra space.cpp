#include<bits/stdc++.h>
using namespace std;

// Time complexity : O(N*M) and Space complexity : O(1);
void sorts(vector<int> &arr1,vector<int> &arr2)
{
	int n=arr1.size();
	int m=arr2.size();
	for(int i=0;i<n;i++)
	{
		if(arr1[i]>arr2[0])
		{
			swap(arr1[i],arr2[0]);
			for(int k=0;k<m-1;k++)
			{
				if(arr2[k]>arr2[k+1])
					swap(arr2[k],arr2[k+1]);
				else
					break;
			}
		}
	}
}


// Time complexity : O((n+m)log(n+m)) and Space complexity : O(1);
void sorts1(vector<int> &arr1,vector<int> &arr2)
{
	int n=arr1.size();
	int m=arr2.size();
	int i=0,j=0,k=n-1;
	while(i<=k&&j<m)
	{
		if(arr1[i]>arr2[j])
			swap(arr1[k--],arr2[j++]);
		else
			i++;
	}
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
}

// Time Complexity : O(nlogn) and Space Complexity : O(1);
void sorts2(vector<int> &arr1,vector<int> &arr2)
{
	int n=arr1.size();
	int m=arr2.size();
	int sum=ceil((n+m)/2.0);
	int sign=0;
	// cout<<sum<<endl;
	while(sum>=1)
	{
		if(sign==1)
		sum=ceil(sum/2.0);
		if(sum==ceil((n+m)/2.0))
			sign=1;
		for(int i=0;i<n+m;i++)
		{
			if(i+sum<n)
			{
			if(arr1[i]>arr1[i+sum])
				swap(arr1[i],arr1[i+sum]);
			}
			else if(i<n&&((i+sum)-n)<m)
			{
				if(arr1[i]>arr2[(i+sum)-n])
					swap(arr1[i],arr2[(i+sum)-n]);
			}
			else if(i-n<m&&((i+sum)-n)<m)
			{
				if(arr2[i-n]>arr2[(i+sum)-n])
					swap(arr2[i-n],arr2[(i+sum)-n]);
			}
			else
				break;
		}
		if(sum==1)
			break;
	}
}



void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> arr1(n),arr2(m);
	for(int i=0;i<n;i++) cin>>arr1[i];
	for(int i=0;i<m;i++) cin>>arr2[i];
	sorts2(arr1,arr2);
	for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
	cout<<endl;
	for(int i=0;i<m;i++) cout<<arr2[i]<<" ";
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
1
6 6
1 3 5 7 9 11
2 4 6 8 10 12
*/