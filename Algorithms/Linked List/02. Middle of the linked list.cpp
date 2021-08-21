#include<bits/stdc++.h>
using namespace std;

// This is the node.
class node{
public:
	int data;
	node* next;
	node(int val)
	{
		data=val;
		next=NULL;
	}
};

/*// Middle of the linked list
void middle_of_linked_list(node* head)
{
	node* slow=head;
	node* fast=head;
	do
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	while(fast!=NULL&&fast->next!=NULL);
	cout<<slow->data;
}*/


void middle_of_linked_list(node* &head)
{
	node* slow=head;
	node* fast=head;
	do {
		slow=slow->next;
		fast=fast->next->next;
	}
	while(fast!=NULL&&fast->next!=NULL);
	cout<<slow->data;
}

// Insert at the begining.
void insertbegin(node* &head,int val)
{
	node* tmp = new node(val);
	tmp->next=head;
	head=tmp;
}

// Insert element at the end.
void insert(node* &head,int val)
{
	node* tmp = new node(val);
	if(head==NULL)
	{
		head=tmp;
		return;
	}

	node* tmp1 = head;
	while(tmp1->next!=NULL) tmp1=tmp1->next;
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

void solve()
{
	node* head=NULL;
	insert(head,1);
	insert(head,2);
	insertbegin(head,0);
	insert(head,3);
	printlist(head);
	middle_of_linked_list(head);
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