#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(n!*n) and Space Complexity : O(n)
void k_th_permutation(vector<int> &arr,int k)
{
	int fac=1;
	vector<int> arr_fac;
	for(int i=1;i<arr.size();i++)
	{
		fac=fac*i;
		arr_fac.push_back(i);
	}
	arr_fac.push_back(arr.size());
	string str="";
	k=k-1;
	while(1)
	{
		str=str+to_string(arr_fac[k/fac]);
		arr_fac.erase(arr_fac.begin()+(k/fac));
		if(arr_fac.size()==0)
			break;
		k=k%fac;
		fac=fac/arr_fac.size();
	}
	cout<<str<<endl;

}


void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	int k;
	cin>>k;
	k_th_permutation(arr,k);
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
aabb
Answer :

*/