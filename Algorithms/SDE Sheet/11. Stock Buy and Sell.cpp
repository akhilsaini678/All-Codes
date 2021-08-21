#include<bits/stdc++.h>
using namespace std;


// Time complexity : O(n) and Space complexity : O(1);
int buy_and_sell(vector<int> &arr)
{
	int prev=1e9;
    int next=0;
    int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        if(prev>arr[i])
            prev=arr[i];
        else if(arr[i]>=prev)
        {
            ans=max(ans,arr[i]-prev);
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
	cout<<buy_and_sell(arr)<<endl;
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