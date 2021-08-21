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


// Add two numbers given as a linked list.
node* add(node* head1,node* head2)
{
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;

	node* head3=NULL;
	int carry=0;
	int sum=0;
	while(1)
	{
		if(head1==NULL&&head2==NULL)
			break;
		if(head1!=NULL&&head2!=NULL)
		{
		sum=(head1->data+head2->data+carry)%10;
		carry=(head1->data+head2->data+carry)/10;
		head1=head1->next;
		head2=head2->next;
		insert(head3,sum);
		}
		else if(head1!=NULL)
		{
			sum=(head1->data+carry)%10;
			carry=(head1->data+carry)/10;
			insert(head3,sum);
			head1=head1->next;
		}
		else if(head2!=NULL)
		{
			sum=(head2->data+carry)%10;
			carry=(head2->data+carry)/10;
			insert(head3,sum);
			head2=head2->next;
		}
	}
	if(carry!=0)
	{
		insert(head3,carry);
	}
	return head3;
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
	printlist(head1);
	printlist(head2);
	node* head3 = add(head1,head2);
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