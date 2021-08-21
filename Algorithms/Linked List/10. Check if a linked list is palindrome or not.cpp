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

bool ispalindrome(node* head)
{
	node* tmp = head;
	node* slow = head;
	node* fast = head;

	while(fast->next!=NULL&&fast->next->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}

	node* tmp2=slow->next;
	node* prev=NULL;
	node* cur=slow->next;
	node* nex;
	while(cur!=NULL)
	{
		nex=cur->next;
		cur->next=prev;
		prev=cur;
		cur=nex;
	}
	slow->next=prev;

	slow=slow->next;
	while(slow!=NULL)
	{
		if(slow->data==tmp->data)
		{
			slow=slow->next;
			tmp=tmp->next;
		}
		else
		{
			return false;
		}
	}
	return true;
}


void solve()
{
	node* head=NULL;
	insert(head,1);
	insert(head,2);
	insert(head,3);
	insert(head,4);
	insert(head,3);
	insert(head,2);
	insert(head,1);
	printlist(head);
	ispalindrome(head)?cout<<"Linked list is palindrome."<<endl:cout<<"Linked List is not palindrome."<<endl;
	printlist(head);
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