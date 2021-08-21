#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(2^n) and Space Complexity : O(2^n)

// Returning subset
void subset_sum(vector<int> &arr,int index,vector<int> &ans,vector<vector<int>> &answer)
{
	for(int i=index;i<arr.size();i++)
	{
		ans.push_back(arr[i]);
		answer.push_back(ans);
		subset_sum(arr,i+1,ans,answer);
		ans.pop_back();
	}
} 

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n),ans;
	vector<vector<int>> answer;
	for(int i=0;i<n;i++) cin>>arr[i];
	subset_sum(arr,0,ans,answer);
	for(int i=0;i<answer.size();i++)
	{
		for(int j=0;j<answer[i].size();j++)
		{
			cout<<answer[i][j]<<" ";
		}
		cout<<endl;
	}
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
3
1 2 3

Answer :
1 
1 2 
1 2 3 
1 3 
2 
2 3 
3 
*/