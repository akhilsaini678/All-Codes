#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* bottom;
	Node(int a)
	{
		data=a;
		next=NULL;
		bottom=NULL;
	}
};

void insert(Node* &head,int value)
{
	Node* tmp=new Node(value);
	tmp->next=head;
	head=tmp;
}

void reverse(Node* &head)
{
	Node* previous=NULL;
	Node* current=head;
	Node* nexts;

	while(current!=NULL)
	{
		nexts=current->next;
		current->next=previous;
		previous=current;
		current=nexts;
	}
	head=previous;
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

Node* merge(Node* &head1,Node* &head2)
{
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;
	if(head1->data>=head2->data)
		swap(head1,head2);
	Node* res=head1;

	while(head1!=NULL&&head2!=NULL)
	{
		Node* tmp=NULL;
		while(head1!=NULL&&head1->data<=head2->data)
		{
			tmp=head1;
			head1=head1->bottom;
		}
		tmp->bottom=head2;
		swap(head1,head2);
	}
	return res;
}

Node *flatten(Node *root)
{
	if(root->next==NULL)
		return root;

	Node* first  = flatten(root->next);
	Node* second = merge(root,first);
	return second;
}


void solve()
{
	int n,value;
	cin>>n;
	Node* head=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>value;
		insert(head,value);
	}
	reverse(head);
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