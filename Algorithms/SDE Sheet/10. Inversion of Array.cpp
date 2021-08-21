#include<bits/stdc++.h>
#define ll long long int
using namespace std;



ll merge_sort(vector<ll> &arr,ll low,ll mid,ll high)
{
	ll L=mid+1-low;
	ll R=high-mid;
	ll k=low;
	ll ans=0;
	vector<ll> left(L);
	vector<ll> right(R);
	for(ll i=0;i<L;i++) left[i]=arr[k++];
	for(ll i=0;i<R;i++) right[i]=arr[k++];	
	ll i=0,j=0;
	k=low;
	while(i<L&&j<R)
	{
		if(left[i]>right[j])
		{
			ans=ans+L-i;
			// cout<<mid+1-(i+low)<<" ";
			arr[k++]=right[j++];
		}
		else
			arr[k++]=left[i++];
	}
	while(i<L)
	{
		arr[k++]=left[i++];
	}
	while(j<R)
	{
		arr[k++]=right[j++];
	}
	// cout<<ans<<endl;
	return ans;
}


// Time complexity : O(nlogn) and Space complexity : O(1);
ll inversion(vector<ll> &arr,ll low,ll high)
{
	ll ans=0;
	if(low<high)
	{
		ll mid=(low+high)/2;
		ans=ans+inversion(arr,low,mid);
		ans=ans+inversion(arr,mid+1,high);
		ans=ans+merge_sort(arr,low,mid,high);
	}
	return ans;
}




void solve()
{
	ll n;
	cin>>n;
	vector<ll> arr(n);
	for(ll i=0;i<n;i++) cin>>arr[i];
	cout<<inversion(arr,0,n-1)<<endl;
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