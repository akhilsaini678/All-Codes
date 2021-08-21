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


// Intersection of linked list.
node* intersection1(node* head1,node* head2)
{
	unordered_map<node*,int> maps;
	while(head1!=NULL)
	{
		maps[head1]=true;
		head1=head1->next;
	}

	while(head2!=NULL)
	{
		if(maps.find(head2)!=maps.end())
		{
			return head2;
		}
		head2=head2->next;
	}
	return NULL;
}

// Intersection of Linked list without extra space.
node* intersection(node* head1,node* head2)
{
	node* tmp1=head1;
	node* tmp2=head2;
	while(tmp1!=tmp2)
	{
		if(tmp1==NULL)
			tmp1=head2;
		else
			tmp1=tmp1->next;
		if(tmp2==NULL)
			tmp2=head1;
		else
			tmp2=tmp2->next;
	}
	return tmp1;
}


void solve()
{
	node* head1=NULL;
	node* head2=NULL;
	insert(head1,2);
	insert(head1,4);
	insert(head1,3);
	insert(head2,5);
	insert(head2,6);
	insert(head2,7);
	insert(head2,9);
	insert(head2,10);
	node* tmp1=head1;
	node* tmp2=head2;
	while(tmp2->data!=6)
	{
		tmp2=tmp2->next;
	}
	while(tmp1->next!=NULL)
	{
		tmp1=tmp1->next;
	}
	tmp1->next=tmp2;
	printlist(head1);
	printlist(head2);
	node* head3 = intersection(head1,head2);
	cout<<(head3->data);
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