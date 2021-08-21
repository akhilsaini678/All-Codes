#include<bits/stdc++.h>
using namespace std;

// One solution can be generating all the substring and then finding out the substring with unique characters. Which will result into O(n^2)
// Time Complexity : O(2*n) and Space Complexity : O(n)
int substring_without_repeat(string s)
{
	unordered_map<char,int> maps;
	int left=0,right=0;
	int ans=0;
	for(int i=0;i<s.length();i++)
	{
		if(maps.find(s[right])!=maps.end())
		{
			while(maps.find(s[right])!=maps.end())
			{
				maps.erase(s[left]);
				left++;
			}
		}
		maps[s[right]]++;
		right++;
		int x=maps.size();
		// cout<<x<<endl;
		ans=max(ans,x);
	}
	return ans;
}

void solve()
{
	int n;
	string str;
	cin>>str;
	cout<<substring_without_repeat(str)<<endl;	
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