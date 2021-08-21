#include<bits/stdc++.h>
using namespace std;

void subset_sum(vector<int> &arr,vector<vector<int>> &answer,vector<int> &ans,int index,int sum,int target)
{
	if(sum==target)
	{
		answer.push_back(ans);
		return;
	}
	if(sum>target)
		return;

	for(int i=index;i<arr.size();i++)
	{
		if(i==index||arr[i]!=arr[i-1])
		{
			ans.push_back(arr[i]);
			subset_sum(arr,answer,ans,i,sum+arr[i],target);
			ans.pop_back();
		}
	}
}

void solve()
{
	int n,target;
	cin>>n;
	vector<int> arr(n),ans;
	vector<vector<int>> answer;
	for(int i=0;i<n;i++) cin>>arr[i];
	cin>>target;
	subset_sum(arr,answer,ans,0,0,target);
	for(int i=0;i<answer.size();i++)
	{
		for(int j=0;j<answer[i].size();j++)
		{
			cout<<answer[i][j]<<" ";
		}
		cout<<endl;
	}
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