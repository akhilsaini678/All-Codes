#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(2^n) and Space Complexity : O(2^n)
void combination_sum(vector<int> &arr,int sum,int index,int tmp_sum,vector<int> &tmp,vector<vector<int>> &ans)
{
	if(tmp_sum>sum)
		return;
	else if(tmp_sum==sum)
		ans.push_back(tmp);

	for(int i=index;i<arr.size();i++)
	{
		if(i!=index&&arr[i]==arr[i-1]) continue;
		tmp.push_back(arr[i]);
		combination_sum(arr,sum,i+1,tmp_sum+arr[i],tmp,ans);
		tmp.pop_back();
	}
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n),tmp;
	vector<vector<int>> ans;
	for(int i=0;i<n;i++) cin>>arr[i];
	int sum,tmp_sum=0;
	cin>>sum;
	sort(arr.begin(),arr.end());
	combination_sum(arr,sum,0,tmp_sum,tmp,ans);
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
4
2 3 6 7
7
Answer :
2 2 3 
7 
*/