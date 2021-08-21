#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(n) and Space Complexity : O(n)
int majority_element(vector<int> &arr,int n)
{
	unordered_map<int,int> maps;
	for(int i=0;i<n;i++)
	{
		maps[arr[i]]++;
		if(maps[arr[i]]>n/3)
			return arr[i];
	}
	return 0;
}

// Time Complexity : O(n) and Space Complexity : O(1)
vector<int> majority_element1(vector<int> &arr,int n)
{
	vector<int> ans;
	int count1=0,count2=0,one=0,two=0;
	int element1=-1,element2=-1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==element1)
			count1++;
		else if(arr[i]==element2)
			count2++;
		else if(count1==0)
		{
			element1=arr[i];
			count1++;
		}
		else if(count2==0)
		{
			element2=arr[i];
			count2++;
		}
		else
		{
			count1--;
			count2--;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(element1==arr[i])
			one++;
		else if(element2==arr[i])
			two++;
	}
	if(one>n/3)
		ans.push_back(element1);
	else if(two>n/3)
		ans.push_back(element2);

	return element;
}

void solve()
{
	long long int n,m,x,answer=0;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<majority_element(arr,n)<<endl;
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