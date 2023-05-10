#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* link;
    
    // Constructor
    Node(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};

class Stack {
    Node* top;
  
public:
    Stack() { top = NULL; }
  
    void push(int data)
    {
  
       
        Node* temp = new Node(data);
  
        
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }
  
       
        temp->data = data;
  
       
        temp->link = top;
  
        
        top = temp;
    }
  
   
    bool isEmpty()
    {
       
        return top == NULL;
    }
  
    
    int peek()
    {
        
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }
  
   
    void pop()
    {
        Node* temp;
  
       
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
  
           
            temp = top;
  
           
            top = top->link;
  
           
            free(temp);
        }
    }
  
    
    void display()
    {
        Node* temp;
  
       
        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        }
        else {
            temp = top;
            while (temp != NULL) {
  
                
                cout << temp->data;
  
                
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};


int eval(vector<string>& A)
{
    Stack st;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != "+" && A[i] != "-" && A[i] != "/"
            && A[i] != "*") {
            st.push(stoi(A[i]));
            continue;
        }
        else {
            int b = st.peek();
            st.pop();
            int a = st.peek();
            st.pop();
            if (A[i] == "+")
                st.push(a + b);
            else if (A[i] == "-")
                st.push(a - b);
            else if (A[i] == "*")
                st.push(a * b);
            else
                st.push(a / b);
        }
    }
    return st.peek();
}




int main(){
    vector<string> A
        = { "10", "6", "9",  "3", "+", "-11", "*",
            "/",  "*", "17", "+", "5", "+" };
 
    int res = eval(A);
    cout << res << endl;

}
