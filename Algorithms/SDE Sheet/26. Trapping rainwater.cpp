#include<bits/stdc++.h>
using namespace std;

// Prefix / Suffix Approach
// Time Complexity : O(n) and Space Complexity : O(n)
int trap_rainwater(vector<int> &arr)
{
	int n=arr.size();
	int ans=0;
	vector<int> prefix(n);
	vector<int> suffix(n);
	prefix[0]=arr[0];
	suffix[n-1]=arr[n-1];
	for(int i=1;i<n;i++) prefix[i]=max(arr[i],prefix[i-1]);
	for(int i=n-2;i>=0;i--) suffix[i]=max(arr[i],suffix[i+1]);
	for(int i=0;i<n;i++)
		ans=ans+min(prefix[i],suffix[i])-arr[i];
	return ans;
}


// Two pointer approach
// Time Complexity : O(n) and Space Complexity : O(1)
int trap_rainwater1(vector<int> &arr)
{
	int n=arr.size();
	int ans=0;
	int left=0,right=n-1,leftmax=0,rightmax=0;
	while(left<=right)
	{
		if(arr[left]<=arr[right])
		{
			if(leftmax<=arr[left]) leftmax=arr[left];
			else
				ans=ans+leftmax-arr[left];
			left++;
		}
		else 
		{
			if(rightmax<=arr[right]) rightmax=arr[right];
			else 
				ans=ans+rightmax-arr[right];
			right--;
		}
	}
	return ans;
}



void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<trap_rainwater1(arr);
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
12
0 1 0 2 1 0 1 3 2 1 2 1


Ans :
6
*/
