#include<bits/stdc++.h>
using namespace std;

struct bag{
	int value;
	int weight;
	bag(int a,int b)
	{
		value=a;
		weight=b;
	}
};

bool cmp(bag a,bag b)
{
	return (double(a.value)/double(a.weight))>(double(b.value)/double(b.weight));
}

// Time Complexity : O(nlogn) and Space Complexity : O(1)
double fractional_kanpsack(vector<bag> &arr,int bag_size)
{
	int n=arr.size();
	double ans=0;
	sort(arr.begin(),arr.end(),cmp);
	int i=0;
	while(bag_size>0)
	{
		if(bag_size-arr[i].weight>=0)
		{
			bag_size=bag_size-arr[i].weight;
			ans=ans+arr[i].value;	
		}
		else
		{
			ans=ans+(double(bag_size*arr[i].value))/double(arr[i].weight);
			bag_size=0;
		}
		i++;
		if(i>=n)
			break;
	}
	return ans;
}



void solve()
{
	int n,a,b,c;
	cin>>n>>c;
	vector<bag> arr;
	vector<int> first(n),second(n);
	for(int i=0;i<n;i++)
		cin>>first[i];
	for(int i=0;i<n;i++)
		cin>>second[i];
	for(int i=0;i<n;i++)
	{
		arr.push_back({first[i],second[i]});
	}
	cout<<fractional_kanpsack(arr,c)<<endl;
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
3 50
60 100 120
10 20 30 

Answer :
240
*/

	