#include<bits/stdc++.h>
using namespace std;


// One way can be using two for nested loop with i and j, which will result into the time complexity of O(n^n)

// Time Complexity : O(n) and Space Complexity : O(n)
vector<int> two_sum(vector<int> &arr,int target)
{
	vector<int> ans;
	unordered_map<int,int> maps;111
	for(int i=0;i<arr.size();i++)
	{
		if(maps.find(target-arr[i])!=maps.end())
		{
			ans.push_back(maps[target-arr[i]]);
			ans.push_back(i);
			return ans;
		}
		maps[arr[i]]=i;
	}
	return ans;
}

void solve()
{
	int n,target;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cin>>target;
	vector<int> ans;
	ans= two_sum(arr,target);
	for(auto i:ans)
		cout<<i<<" ";
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