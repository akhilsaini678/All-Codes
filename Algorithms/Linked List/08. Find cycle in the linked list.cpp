#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int val)
	{
		data=val;
		next=NULL;
	}
};

void insert(node* &head,int val)
{
	node* tmp=new node(val);
	if(head==NULL)
	{
		head=tmp;
		return;
	}

	node* tmp1=head;
	while(tmp1->next!=NULL)
	{
		tmp1=tmp1->next;
	}
	tmp1->next=tmp;
}

bool iscycle(node* head)
{
	node* slow=head;
	node* fast=head;
	do {
		if(fast==NULL)
			return false;
		slow=slow->next;
		fast=fast->next->next;
	}
	while(slow!=fast);
	return true;
}


void solve()
{
	node* head=NULL;
	insert(head,1);
	insert(head,2);
	insert(head,3);
	insert(head,4);
	insert(head,5);
	insert(head,6);
	node* tmp=head;
	while(tmp->next!=NULL) tmp=tmp->next;
	tmp->next=head;
	(iscycle(head)) ? cout<<"Yes, there is a cycle."<<endl:cout<<"No, there is no cycle."<<endl;
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