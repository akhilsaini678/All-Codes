#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(2^n) and Space Complexity : O(2^n)
void subset_sum(vector<int> &arr,int index,vector<int> &tmp,vector<vector<int>> &ans)
{
	for(int i=index;i<arr.size();i++)
	{
		if(i==index||arr[i]!=arr[i-1])
		{
			tmp.push_back(arr[i]);
			ans.push_back(tmp);
			subset_sum(arr,i+1,tmp,ans);
			tmp.pop_back();
		}
	}
}


void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n),tmp;
	vector<vector<int>> ans;
	for(int i=0;i<n;i++) cin>>arr[i];

	sort(arr.begin(),arr.end());
	subset_sum(arr,0,tmp,ans);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
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
5
4 4 4 1 4
Answer :
1 
1 4 
1 4 4 
1 4 4 4 
1 4 4 4 4 
4 
4 4 
4 4 4 
4 4 4 4 

*/