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

node* iscycle(node* head)
{
	node* slow=head;
	node* fast=head;
	do {
		if(fast->next==NULL||fast==NULL)
			return NULL;
		slow=slow->next;
		fast=fast->next->next;
	}
	while(slow!=fast);

	node* tmp=head;
	while(slow!=tmp)
	{
		slow=slow->next;
		tmp=tmp->next;
	}
	return slow;
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
	node* x = iscycle(head);
	(x==NULL) ? cout<<"No, there is no cycle."<<endl : cout<<x->data<<endl;
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