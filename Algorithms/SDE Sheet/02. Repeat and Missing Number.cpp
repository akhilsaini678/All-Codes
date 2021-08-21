#include<bits/stdc++.h>
using namespace std;


// Using Hasing 
// Time complexity : O(2N) and Space complexity : O(N);
pair<int,int> repeat_and_mising(vector<int> arr)
{
	int n=arr.size();
	pair<int,int> ans;
	unordered_map<int,int> maps;
	for(int i=0;i<n;i++) maps[arr[i]]++;
	for(int i=1;i<=n;i++)
	{
		if(maps[i]==2)
			ans.first=i;
		else if(maps[i]==0)
			ans.second=i;
	}
	return ans;
}

// Using XOR operation
// Time complexity : O(2N) and Space complexity : O(1);
pair<int,int> repeat_and_mising_xor(vector<int> arr)
{
	int n=arr.size();
	int xors=0;
	int seta=0,setb=0;
	pair<int,int> ans;
	for(int i=0;i<n;i++)
	{
		xors=xors^arr[i];
		xors=xors^(i+1);
	}

	int set_bit_no = xors & ~(xors - 1);

	for(int i=0;i<n;i++)
	{
		if(set_bit_no&arr[i])
			seta=seta^arr[i];
		else
			setb=setb^arr[i];
	}

	for(int i=1;i<=n;i++)
	{
		if(set_bit_no&i)
			seta=seta^i;
		else
			setb=setb^i;
	}

	return make_pair(seta,setb);
}


void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	pair<int,int> ans=repeat_and_mising_xor(arr);
	cout<<ans.first<<" "<<ans.second<<endl;
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
Input :
1
7
1 2 3 4 5 6 6
Output :
7 6
*/
