#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n) and Space Complexity : O(1)
int consecutive_ones(vector<int> &arr)
{
	int n=arr.size();
	int ans=0,count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
			count=0;
		else
		{
			count++;
			ans=max(ans,count);
		}
	}
    return ans;
}



void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<remove_duplicate(arr)<<endl;
	
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


