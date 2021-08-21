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


/*struct node {
	int data;
	node* next;
	node(int val)
	{
		data=val;
		next=NULL;
	}
};*/

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

// Print the linked list.
void printlist(node* &head)
{
	node* tmp = head;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	cout<<endl;
}

// Search in linked list.
bool search(node* &head,int val)
{
	node* tmp=head;
	while(tmp!=NULL)
	{
		if(tmp->data==val)
			return true;
		tmp=tmp->next;
	}
	return false;
}

// Delete from begining in linked list.
void deletebegin(node* &head)
{
	node* tmp = head;
	head=head->next;
	delete tmp;
}

// Delete a node from linked list.
void deletion(node* &head,int val)
{
	node* tmp=head;
	if(head==NULL)
		return;
	if(head->next==NULL)
	{
		delete tmp;
		return;
	}

	while(tmp->next->data!=val)
	{
		tmp=tmp->next;
	}
	node* tmp1 = tmp->next;
	tmp->next=tmp->next->next;
	delete tmp1;
}


void solve()
{
	node* head=NULL;
	insert(head,1);
	insert(head,2);
	insertbegin(head,0);
	deletebegin(head);
	deletion(head,2);
	printlist(head);
	search(head,1)?(cout<<"Value is found."<<endl):cout<<"Value is not found."<<endl;
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