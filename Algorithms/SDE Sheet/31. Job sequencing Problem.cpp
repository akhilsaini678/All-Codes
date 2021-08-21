#include<bits/stdc++.h>
using namespace std;

struct jobs{
	int id;
	int deadline;
	int profit;
	jobs(int a,int b,int c)
	{
		id=a;
		deadline=b;
		profit=c;
	}
};

bool cmp(jobs a,jobs b)
{
	return a.profit>b.profit;
}

// Time Complexity : O(nlogn) and Space Complexity : O(n)
vector<int> max_profit_job(vector<jobs> &arr)
{
	int ans=0;
	int num=0;
	int empty=0;
	int n=arr.size();
	sort(arr.begin(),arr.end(),cmp);
	vector<int> deadline(n,-1);
	for(int i=0;i<n;i++)
	{
		int xx=arr[i].deadline-1;
		while(xx>=0)
		{
			if(deadline[xx]==-1)
			{
				deadline[xx]=arr[i].id;
				num=num+arr[i].profit;
				ans++;
				break;
			}
			xx--;
		}
	}
	vector<int> anss={ans,num};
	return anss;
}



void solve()
{
	int n,a,b,c;
	cin>>n;
	vector<jobs> arr;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		arr.push_back({a,b,c});
	}
	vector<int> ans=max_profit_job(arr);
	cout<<ans[0]<<" "<<ans[1]<<endl;
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
4
1 4 20
2 1 10 
3 1 40 
4 1 30

Answer :
60
*/