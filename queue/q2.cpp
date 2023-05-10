#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear,size;

public:
    Queue() {
        front = -1;
        rear = -1;
        size=0;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full. Overflow condition!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = data;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Underflow condition!" << endl;
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements are: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
    void solve(int x,int n){
        int maxLength = 0;
        int currentSum = 0;
        int endIndex = -1;
        Queue sub;

        for (int i = 0; i < n; i++) {
            sub.enqueue(arr[i]);
            currentSum +=arr[i];

            while (currentSum > x) {
                currentSum -= sub.getFront();
                sub.dequeue();
            }
            if (sub.size> maxLength) {
                maxLength = sub.rear;
                endIndex = i;
            }
        }
        for (int i = endIndex - maxLength ; i <= endIndex; i++) {
            cout<<arr[i]<<" ";
        }

      
    }
};

int main() {
    Queue q;

    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.enqueue(x);
    }
    cin>>x;
    q.solve(x,n);
    return 0;
}
