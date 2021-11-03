#include "BST.cpp"

void inorder_iter(){
    stack<Node*>st;
    Node *cur=root;
   
    while(st.size() || cur){
        while(cur){
            st.push(cur);
            cur=cur->left;
        }
        cout<<st.top()->x<<" ";
        cur = st.top()->right;
        st.pop();
    }
}

int main(){
    int k;
    bool reserved;
    cin>>k;
    while(k!=-1){
        reserved = insert(k);
        inorder_iter();
        if(!reserved)
            cout<<"(Reservation Failed)";
        cout<<"\n";
        cin>>k;
    }
}
