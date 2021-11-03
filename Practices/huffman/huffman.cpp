#include <bits/stdc++.h>
#define ll long long 
using namespace std;

struct node{ // structure created to build the huffman tree
    int freq; // frequency 
    char c; // what character it contains (for leaf node)
    struct node *l,*r; // each node having left and right child
    node(char ch=' ',int f=0,struct node*left=NULL,struct node*right=NULL){
        l=left,r=right;
        freq=f;  // Initialisation with given values or defualt value if not given
        c=ch;
    }
}*root; // used to reference the root node

bool cmp(node*a,node*b){ // comparator function for the set
    return a->freq<=b->freq; // increasing order of frequency
}
set<node*,decltype(cmp)*>st(cmp); // set which is ordered according to cmp
// its a set of pointers,only stores the adresses
// so the actual memory will not be deleted when something is deleted from the set
vector<pair<char,string>>prefix_codes;

void dfs(node* cur,string s=""){
    if(cur->l==cur->r){ // leaf node,only possible case when both child are null
        cout<<cur->c<<" : "<<s<<"\n"; // print the code and return
        prefix_codes.emplace_back(cur->c,s);
        // storing the codes,can be used to calculate avg bits used
        return;
    }
    if(cur->l){
        dfs(cur->l,s+="0"); // traverse left subtree add 0 to the prefix code
        s.pop_back();
        // getting rid of the 0 to get ready for traversing the right subtree
    }
    if(cur->r){
        dfs(cur->r,s+="1");
        s.pop_back(); // going back to its parent node
    }
    delete cur; // whole subtree traveresed,clearing node from heap
}
string word[10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
// words assigned according to index
// word[0] will map to "ZERO", word[2] will map to "TWO" and so on
string message(string id){ // function to return string according to ID
    string s;
    int n=id.length()-1; // length of the ID
    int nth=4,r,index= max(-1,n-nth);
    //nth=number of digits considered from the last
    //index=current index starting from the 4th(nth) position from the last,
    //also handles ID with length<nth
    while(nth-- && ++index<=n){
        r=(id[index]-'0')%10; //r=numeric value of current index
        s+=word[r]; //proper words added according to numeric value
    }
    return "MYIDIS"+s;
}

int freq[26]{}; //tracks frequency of 26 characters
void buildleaf(string msg){
    int n=msg.length(); // length of the message
    for(int i=0;i<n;i++) 
        freq[msg[i]-'A']++; //calculate frequency of all 26 characters

    for(int i=0;i<26;i++){
        if(freq[i]>0){ // ith character is present in the message
            auto tmp=new node('A'+i,freq[i]);
            st.emplace(tmp);
            // new leaf node created and address added to set
        }
    } 
}

double avg(int len){
    int n=prefix_codes.size();
    double ans=0;
    for(int i=0;i<n;i++){
        ans+=freq[prefix_codes[i].first-'A']/(double)len* \
             prefix_codes[i].second.length();
    } 
    return ans;
}

int main(){
    string id="1139"; 
    string msg=message(id);
    buildleaf(msg);
    cout<<msg<<"\n";
    root=new node();
    while(st.size()>1){
        auto it=st.begin(),it2=it; it2++;
        //it=current element with least frequency,it2=next to it
        auto tmp=new node(' ',(**it).freq+(**it2).freq,*it2,*it);
        // new node created for merge
        st.erase(it),st.erase(it2);
        st.emplace(tmp);
        //two elements with least frequency removed and
        //their merged subtree address added to the set
        root=tmp; //tracking the root
    }
    dfs(root); //printing the prefix codes
    int n=prefix_codes.size();
    cout<<"Average Bits Used : "<<avg(msg.length())<<"\n";
}
