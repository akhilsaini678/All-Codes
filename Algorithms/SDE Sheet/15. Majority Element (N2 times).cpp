#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(n) and Space Complexity : O(n)
int majority_element(vector<int> &arr,int n)
{
	unordered_map<int,int> maps;
	for(int i=0;i<n;i++)
	{
		maps[arr[i]]++;
		if(maps[arr[i]]>n/2)
			return arr[i];
	}
	return 0;
}

// Time Complexity : O(n) and Space Complexity : O(1)
int majority_element1(vector<int> &arr,int n)
{
	int count=0;
	int element=0;
	for(int i=0;i<n;i++)
	{
		if(count==0)
			element=arr[i];
		if(arr[i]==element)
			count++;
		else
			count--;
	}
	return element;
}


void solve()
{
	long long int n,m,x,answer=0;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<majority_element1(arr,n)<<endl;
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