#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(int start,int end,string &str)
{
	while(start<=end)
	{
		if(str[start]==str[end])
		{
			start++;
			end--;
		}
		else
			return false;
	}
	return true;
}


void partitioning_palindrome(string &str,vector<vector<string>> &answer,vector<string> &ans,int index)
{
	if(index==str.size())
	{
		answer.push_back(ans);
		return;
	}

	for(int i=index;i<str.size();i++)
	{
		if(is_palindrome(index,i,str))
		{
			ans.push_back(str.substr(index,i-index+1));
			partitioning_palindrome(str,answer,ans,i+1);
			ans.pop_back();
		}
	}
}

void solve()
{
	string str;
	cin>>str;
	vector<string> ans;
	vector<vector<string>> answer;
	partitioning_palindrome(str,answer,ans,0);
	for(int i=0;i<answer.size();i++)
	{
		for(int j=0;j<answer[i].size();j++)
		{
			cout<<answer[i][j]<<" ";
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