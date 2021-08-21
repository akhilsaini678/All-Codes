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

// Print the elements.
void printlist(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

node* rotate(node* &head,int k)
{
	if(head==NULL||head->next==NULL)
		return head;

	node* tmp=head;
	int count=1;
	while(tmp->next!=NULL)
	{
		count++;
		tmp=tmp->next;
	}

	tmp->next=head;
	k=k%count;
	int loop=count-k;
	while(loop--)
	{
		tmp=tmp->next;
	}
	
	head=tmp->next;
	tmp->next=NULL;
	return head;
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
	node* head1 = rotate(head,3);
	printlist(head1);
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