#include<bits/stdc++.h>
using namespace std;


class Node {
public:
	int data ;
	Node* next;
	Node(int a)
	{
		data=a;
		next=NULL;
	}
};

void insert(Node* &head,int value)
{
	Node* tmp = new Node(value);
	tmp->next=head;
	head=tmp;
}

void insert_at_last(Node* &head,int value)
{
	Node* tmp=new Node(value);
	if(head==NULL)
	{
		head=tmp;
		return;
	}

	Node* tmp1=head;
	while(tmp1->next!=NULL)
		tmp1=tmp1->next;

	tmp1->next=tmp;
}

void reverse(Node* &head)
{
	Node* previous=NULL;
	Node* current=head;
	Node* nexts=NULL;

	while(current!=NULL)
	{
		nexts=current->next;
		current->next=previous;
		previous=current;
		current=nexts;
	}
	head=previous;
}

void middle_of_linked_list(Node* &head)
{
	Node* slow=head;
	Node* fast=head;
	do {
		slow=slow->next;
		fast=fast->next->next;
	}
	while(fast!=NULL&&fast->next!=NULL);

	cout<<slow->data<<endl;
}


Node* merge_linkedlist(Node* head1,Node* head2)
{
	Node* tmp=NULL;

	while(head1!=NULL&&head2!=NULL)
	{
		if(head1->data<=head2->data)
		{
			insert(tmp,head1->data);
			head1=head1->next;
		}
		else
		{
			insert(tmp,head2->data);
			head2=head2->next;
		}
	}
	while(head1!=NULL)
	{
		insert(tmp,head1->data);
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		insert(tmp,head2->data);
		head2=head2->next;
	}
	reverse(tmp);
	return tmp;
}

// Merge List without extra space
Node* merge_linkedlist1(Node* head1,Node* head2)
{
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;
	if(head1->data>head2->data) swap(head1,head2);

	Node* ans=head1;
	cout<<head1->data<<endl;

	while(head1!=NULL&&head2!=NULL)
	{
		Node* tmp=NULL;
		while(head1!=NULL&&head1->data<=head2->data)
		{
			tmp=head1;
			head1=head1->next;
		}
		tmp->next=head2;
		swap(head1,head2);
	}
	return ans;
}


void remove(Node* &head,int n)
{
	Node* slow=head;
	Node* fast=head;
	for(int i=0;i<n;i++)
		fast=fast->next;

	while(fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
	}
	Node* del=slow->next;
	slow->next=slow->next->next;
	delete del;
}


void removes(Node* &add)
{
	add->data=add->next->data;
	add->next=add->next->next;
	delete add->next;
}

Node* adds(Node* head1,Node* head2)
{
	int sum=0,carry=0;
	Node* head3=NULL;
	while(head1!=NULL&&head2!=NULL)
	{
		sum=(head1->data+head2->data+carry)%10;
		carry=(head1->data+head2->data+carry)/10;
		head1=head1->next;
		head2=head2->next;
		insert(head3,sum);
	}
	while(head1!=NULL)
	{
		sum=(head1->data+carry)%10;
		carry=(head1->data+carry)/10;
		head1=head1->next;
		insert(head3,sum);
	}
	while(head2!=NULL)
	{
		sum=(head2->data+carry)%10;
		carry=(head2->data+carry)/10;
		head2=head2->next;
		insert(head3,sum);
	}
	if(carry!=0)
		insert(head3,carry);

	reverse(head3);
	return head3;
}

void printlist(Node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

bool ispalindrome(Node* &head)
{
	Node* slow=head;
	Node* fast=head;
	do {
		slow=slow->next;
		fast=fast->next->next;
	}
	while(fast->next!=NULL&&fast->next->next!=NULL);

	Node* previous=NULL;
	Node* current=slow->next;
	Node* nexts;
	while(current!=NULL)
	{
		nexts=current->next;
		current->next=previous;
		previous=current;
		current=nexts;
	}

	slow->next=previous;

	Node* tmp=head;
	slow=slow->next;
	while(slow!=NULL)
	{
		if(tmp->data!=slow->data)
			return false;
		tmp=tmp->next;
		slow=slow->next;
	}
	return true;
}


void solve()
{
	int n,m,value;
	cin>>n;
	Node* head=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>value;
		insert(head,value);
	}
	reverse(head);
	printlist(head);
	middle_of_linked_list(head);
	// insert_at_last(head,36);

	Node* head1=NULL;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>value;
		insert(head1,value);
	}
	reverse(head1);

	Node* head2=NULL;
	for(int i=0;i<m;i++)
	{
		cin>>value;
		insert(head2,value);
	}
	reverse(head2);

	/*Node* mer=merge_linkedlist1(head1,head2);
	printlist(head1);

	remove(head,4);
	printlist(head);*/

	Node* head3 = adds(head1,head2);
	printlist(head3);

	cin>>m;
	Node* head4=NULL;
	for(int i=0;i<m;i++)
	{
		cin>>value;
		insert(head4,value);
	}
	reverse(head2);
	
	if(ispalindrome(head4))
		cout<<"Palindrome"<<endl;
	else
		cout<<"Not Palindrome"<<endl;
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