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

/*// Remove nth node from the last -> Time Complexity : O(2N).
void remove(node* &head,int n)
{
	node* tmp =head;
	int count=0;
	while(tmp!=NULL)
	{
		tmp=tmp->next;
		count++;
	}

	tmp=head;
	for(int i=0;i<count-n-1;i++)
	{
		tmp=tmp->next;
	}
	if(count==n)
	{
		head=tmp->next;
		delete tmp;
	}
	else
	{
		node* del = tmp->next;
		tmp->next=tmp->next->next;
		delete del;
	}
}*/


// Remove nth node from the last -> Time Complexity : O(N).
void remove(node* &head,int n)
{
	node* tmp =new node(-1);
	tmp->next=head;
	node* slow =tmp;
	node* fast =tmp;
	for(int i=0;i<n;i++)
	{
		fast=fast->next;
	}
	while(fast->next!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	if(slow->data==-1)
	{
		node* del = slow->next;
		head=slow->next->next;
		delete del;
		delete tmp;
		return;
	}
	node* del = slow->next;
	slow->next=slow->next->next;
	delete del;
	delete tmp;
}

void solve()
{
	node* head=NULL;
	insert(head,8);
	insert(head,1);
	insert(head,2);
	insert(head,3);
	insert(head,7);
	insert(head,4);
	insert(head,5);
	insert(head,6);
	printlist(head);
	remove(head,4);
	remove(head,7);
	printlist(head);
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