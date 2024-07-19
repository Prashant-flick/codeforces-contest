#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n+1];
        for(int i=1; i<=n; i++){
            cin >> arr[i];
        }

        Node* head = new Node(arr[1]);
        for(int i=2; i<=n; i++){
            int num;
            cin >> num;
            
        }

    }
    
}