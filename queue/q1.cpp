#include <bits/stdc++.h>
using namespace std;

#include <iostream>

class PriorityQueue {
private:
    struct Node {
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node* head;

public:
    PriorityQueue() {
        head = nullptr;
    }

    ~PriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int data) {
        Node* newNode = new Node(data);
        if (!head || data < head->data) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* curr = head;
            while (curr->next && curr->next->data <= data) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    int pop() {
        Node* temp = head;
        int data = head->data;
        head = head->next;
        delete temp;
        return data;
    }

    int top() {
        return head->data;
    }

    bool empty() {
        return !head;
    }
};

int main() {
    int t,sf,pump;
    cin>>pump;
    cin>>t;
    cin>>sf;
    int pumppos[pump][2];
    for(int i=0;i<pump;i++){
        for(int j=0;j<2;j++){
             cin>>pumppos[i][j];
        }
    }

    int ans=0;
    int i=0;
    
    if(t<sf){
        cout<<0;
    }
    else{
        PriorityQueue pq;
        while(sf<t)
        {
            while(i<pump && pumppos[i][0]<=sf)
            {
                pq.push(pumppos[i][1]);
                i++;
            }
            if(pq.empty())
                return -1;
            int mx = pq.top();
            pq.pop();
            sf+= mx;
            ans++;
        }
        
    }
    cout<<ans;
    return 0;
}

