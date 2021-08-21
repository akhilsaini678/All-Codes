#include<bits/stdc++.h>
using namespace std;

// One solution can be using 3 nested loop, and then putting unique values in set, Time Complexity : O(N^3(logn))
// Another solution can be using 2 nested loop and checking third value using hashing, Time Complexity : O(N^2(logn))
// Two pointer approach
// Time Complexity : O(n^2) and Space Complexity : O(1)

vector<vector<int>> sum_3(vector<int> &arr)
{
	vector<vector<int>> ans;
	int n=arr.size();
	sort(arr.begin(),arr.end());
	int sum=0;
	for(int i=0;i<n-2;i++)
	{
		sum=0;
		int left=i+1;
		int right=n-1;
		sum=sum+arr[i];
		while(left<right)
		{
			if(sum+arr[left]+arr[right]>0)
				right--;
			else if(sum+arr[left]+arr[right]<0)
				left++;
			else
			{
				vector<int> tmp(3);
				tmp[0]=arr[i];
				tmp[1]=arr[left];
				tmp[2]=arr[right];
				ans.push_back(tmp);

				while(left<right&&arr[left]==tmp[1]) left++;
				while(left<right&&arr[right]==tmp[2]) right--;
			}
		}
		while(i<n-2&&arr[i]==arr[i+1]) i++;
	}
	return ans;
}


void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	vector<vector<int>> ans;
	for(int i=0;i<n;i++) cin>>arr[i];
	ans=sum_3(arr);
	for(int i=0;i<ans.size();i++) {
	for(int j=0;j<3;j++)
	cout<<ans[i][j]<<" ";
	cout<<endl;
	}
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
11
-1 -2 -2 -1 -1 2 0 2 0 0 2

Ans :
-2 0 2 
-1 -1 2 
0 0 0 
*/
