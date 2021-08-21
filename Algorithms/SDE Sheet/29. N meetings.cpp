#include<bits/stdc++.h>
using namespace std;

struct pairs {
	int first;
	int second;
	int index;
	pairs(int a,int b,int c)
	{
		first=a;
		second=b;
		index=c;
	}
};


bool cmp(pairs a,pairs b)
{
	if(a.second<b.second)
		return true;
	else if(a.second==b.second)
		return a.index<b.index;
	return false;
}

// Time Complexity : O(nlogn) and Space Complexity : O(n)
vector<int> meetings(vector<pairs> &arr)
{
	int n=arr.size();
	sort(arr.begin(),arr.end(),cmp);
	vector<int> ans;
	int end=-1;
	for(int i=0;i<n;i++)
	{
		if(arr[i].first>end)
		{
			ans.push_back(arr[i].index);
			end=arr[i].second;
		}
	}
	return ans;
}



void solve()
{
	int n;
	cin>>n;
	vector<pairs> arr;
	vector<int> first(n),second(n);
	for(int i=0;i<n;i++)
		cin>>first[i];
	for(int i=0;i<n;i++)
		cin>>second[i];

	for(int i=0;i<n;i++)
		arr.push_back({first[i],second[i],i+1});
	
	vector<int> ans=meetings(arr);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";	
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
6
1 0 3 8 5 8
2 6 4 9 7 9

Answer :
4
*/
