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



node* k_grouping(node* head,int k)
{
	node* tmp = new node(-1);
	tmp->next=head;
	node* prev=tmp;
	node* cur;
	node* nex;
	int count=0;

	node* tmp1 = head;
	while(tmp1!=NULL)
	{
		tmp1=tmp1->next;
		count++;
	}

	while(count>=k)
	{
		cur=prev->next;
	 	nex=cur->next;
		for(int i=0;i<k-1;i++)
		{
			cur->next=nex->next;
			nex->next=prev->next;
			prev->next=nex;
			nex=cur->next;
		}
		prev=cur;
		count=count-k;
	}
	return tmp->next;
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
	insert(head,7);
	insert(head,8);
	insert(head,9);
	printlist(k_grouping(head,3));
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