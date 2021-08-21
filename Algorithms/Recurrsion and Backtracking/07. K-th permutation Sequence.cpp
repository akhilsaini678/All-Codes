#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(n!*n) and Space Complexity : O(n)
void k_th_permutation(string str,int index,string &tmp,vector<string> &ans)
{
	if(index==str.length())
	{
		ans.push_back(tmp);
	}

	for(int i=index;i<str.length();i++)
	{
		swap(tmp[index],tmp[i]);
		k_th_permutation(str,index+1,tmp,ans);
		swap(tmp[index],tmp[i]);
	}
}


void solve()
{
	int n;
	string str;
	cin>>str;
	string tmp=str;
	vector<string> ans;
	k_th_permutation(str,0,tmp,ans);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
	cout<<endl;
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
ABC
Answer :
ABC
ACB
BAC
BCA
CBA
CAB


*/