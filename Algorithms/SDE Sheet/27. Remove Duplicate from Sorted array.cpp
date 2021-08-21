#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n) and Space Complexity : O(1)
int remove_duplicate(vector<int> &arr)
{
	int n=arr.size();
	if(arr.size()<=1) return arr.size();

	int i=0,j=1;
	for(int j=1;j<n;j++)
	{
		if(arr[i]==arr[j])
			continue;
		else
			arr[++i]=arr[j];
	}
        return i+1;
}



void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	remove_duplicate(arr);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
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
1 1 2 2 3 3

Ans :
1 2 3 2 3 3 

*/
