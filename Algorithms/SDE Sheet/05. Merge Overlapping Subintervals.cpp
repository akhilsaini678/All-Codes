#include<bits/stdc++.h>
using namespace std;

// Time complexity : O(nlogn+n) and Space complexity : O(1);
/*vector<vector<int>> merge(vector<vector<int>> &arr)
{
	int n=arr.size();
	vector<vector<int>> ans;
	vector<int> tmp = arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i][0]>tmp[1])
		{
			ans.push_back(tmp);
			tmp=arr[i];
		}
		else
			tmp[1]=max(tmp[1],arr[i][1]);
	}
	ans.push_back(tmp);
	return ans;
}*/

vector<vector<int>> merge(vector<vector<int>> &arr)
{
	int n=arr.size();
	vector<vector<int>> ans;
	vector<int> tmp=arr[0];
	for(int i=0;i<n;i++)
	{
		if(tmp[1]<arr[i][0])
		{
			ans.push_back(tmp);
			tmp=arr[i];
		}
		else
		{
			tmp[1]=max(arr[i][1],tmp[1]);		
		}
	}
	ans.push_back(tmp);
	return ans;
}


void solve()
{
	int n;
	cin>>n;
	vector<vector<int>> arr(n,vector<int> (2));
	for(int i=0;i<n;i++) cin>>arr[i][0]>>arr[i][1];
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans = merge(arr);
	for(int i=0;i<n;i++) cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
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
Test Case
1
6
1 4
0 3 
11 13
2 8
2 7
4 5
*/