#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(2^n) and Space Complexity : O(2^n)

bool ispalindrome(int start,int end,string &str)
{
	while(start<=end)
	{
		if(str[start]==str[end])
		{
			start++,end--;
		}
		else
			return false;
	}
	return true;
}
e
void partitioning_palindrome(string str,int index,vector<string> &tmp,vector<vector<string>> &ans)
{
	if(str.size()==index)
		ans.push_back(tmp);

	for(int i=index;i<str.length();i++)
	{
		if(ispalindrome(index,i,str))
		{
			tmp.push_back(str.substr(index,i-index+1));
			partitioning_palindrome(str,i+1,tmp,ans);
			tmp.pop_back();
		}
	}
}


void solve()
{
	int n;
	string str;
	cin>>str;
	vector<string> tmp;
	vector<vector<string>> ans;
	partitioning_palindrome(str,0,tmp,ans);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
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
a a b b 
a a bb 
aa b b 
aa bb 

*/