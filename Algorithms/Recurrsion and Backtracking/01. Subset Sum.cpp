#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(2^n) and Space Complexity : O(2^n)
void subset_sum(vector<int> &arr,int index,int sum,vector<int> &ans)
{
	if(index==arr.size())
	{
		ans.push_back(sum);
		return;
	}
	subset_sum(arr,index+1,sum+arr[index],ans);
	subset_sum(arr,index+1,sum,ans);
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n),ans;
	for(int i=0;i<n;i++) cin>>arr[i];
	subset_sum(arr,0,0,ans);
	sort(ans.rbegin(),ans.rend());
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	cout<<endl;
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
3
1 2 3

Answer :
6 5 4 3 3 2 1 0 
*/