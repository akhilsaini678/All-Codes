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

// Merge the linked list -> Space Complexity : O(N+M)
node* mergelinkedlist1(node* head1,node* head2)
{
	node* head3=NULL;
	node* tmp=head3;
	
	while(head1!=NULL&&head2!=NULL)
	{
		if(head1->data<=head2->data)
		{
			insert(head3,head1->data);
			head1=head1->next;
		}
		else
		{
			insert(head3,head2->data);
			head2=head2->next;
		}
	}
	while(head1!=NULL)
	{
		insert(head3,head1->data);
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		insert(head3,head2->data);
		head2=head2->next;
	}
	return head3;
}


node* mergelinkedlist(node* head1,node* head2)
{
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;
	if(head1->data>head2->data)
		swap(head1,head2);
	node* res=head1;
	while(head1!=NULL&&head2!=NULL)
	{
		node* tmp = NULL;
		while(head1!=NULL&&head1->data<head2->data)
		{
			tmp=head1;
			head1=head1->next;
		}
		tmp->next=head2;
		swap(head1,head2);
	}
	return res;
}




void solve()
{
	node* head1=NULL;
	node* head2=NULL;
	insert(head1,1);
	insert(head1,3);
	insert(head1,5);
	insert(head2,2);
	insert(head2,4);
	insert(head2,6);
	printlist(head1);
	printlist(head2);
	node* head3 = mergelinkedlist(head1,head2);
	printlist(head3);
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