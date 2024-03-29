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
void deleteduplicate(node* head,set<int> &s){
	node* temp=head;
	while(temp!=NULL && temp->next!=NULL){
		if(temp->data==temp->next->data){
			node* del =temp->next;
			s.insert(temp->data);
			temp->next=temp->next->next;
			delete(del);
		}
		else{
			temp=temp->next;
		}
	}
}
void deleteNodeWithValue(node** headRef, int value) {
    node* temp = *headRef;
    node* prev = nullptr;

 
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == nullptr) {
        return;
    }

    
    if (prev == nullptr) {
        *headRef = temp->next;
    } else {
        prev->next = temp->next;
    }

   
    delete(temp);
 }

void printlist(node *head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}


int main()
{
    freopen("dupin.txt","r",stdin);
    freopen("dupout.txt","w",stdout);
	set <int> s;
	node* head=NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertattail(head,x);
	}
	deleteduplicate(head,s);
	for (auto i : s) {
        deleteNodeWithValue(&head,i);
    }
    printlist(head);
	return 0;
}
