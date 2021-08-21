#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n) and Space Complexity : O(1)
int lcs(vector<int> &arr)
{
	unordered_map<int,int> maps;
	int n=arr.size();
	for(int i=0;i<n;i++)
		maps[arr[i]]++;

	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(maps.find(arr[i]-1)!=maps.end())
			continue;
		else if(maps.find(arr[i]+1)!=maps.end())
		{
			int j=0,tmp=0;
			while(maps.find(arr[i]+j)!=maps.end())
			{
				cout<<arr[i]+j<<endl;
				j++;
				tmp++;
			}
			ans=max(ans,tmp);
		}
        else 
            ans=max(ans,1);
	}
	return ans;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<lcs(arr)<<endl;	
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