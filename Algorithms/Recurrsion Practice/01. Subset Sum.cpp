#include<bits/stdc++.h>
using namespace std;

void subset_sum(vector<int> &arr,vector<int> &answer,int sum,int index)
{
	if(index==arr.size())
	{
		answer.push_back(sum);
		return;
	}
	subset_sum(arr,answer,sum+arr[index],index+1);
	subset_sum(arr,answer,sum,index+1);
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n),answer;
	for(int i=0;i<n;i++) cin>>arr[i];
	subset_sum(arr,answer,0,0);
	sort(answer.rbegin(),answer.rend());
	for(int i=0;i<answer.size();i++) cout<<answer[i]<<" ";
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