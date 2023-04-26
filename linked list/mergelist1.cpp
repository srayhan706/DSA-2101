#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int val){
		data=val;
		next=NULL;
	}

};

void insertattail(node* &head,int val)
{
	node* n=new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}

void copytovect(node* head,vector<int> &v)
{
	node* temp=head;
	while(temp!=NULL){
		v.push_back(temp->data);
		temp=temp->next;
	}
}
void printlist(node *head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main(){
    freopen("merin.txt","r",stdin);
    freopen("merout.txt","w",stdout);


	node* head1=NULL;
	node* head2=NULL;
	node* head3=NULL;
	int n1,n2;
	cin>>n1;
	cin>>n2;
	for(int i=0;i<n1;i++){
        int x;
        cin>>x;
		insertattail(head1,x);
	}
	for(int i=0;i<n2;i++){
        int x;
        cin>>x;
		insertattail(head2,x);
	}
	vector<int> v;
	copytovect(head1,v);
	copytovect(head2,v);
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		insertattail(head3,v[i]);

	}


	printlist(head3);
	//printlist(head2);
	return 0;
}
