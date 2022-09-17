#include <iostream>
#define mx 1000001
using namespace std;

struct info {
    int prop, sum;
} tree[mx * 3]; 

void update(int node, int b, int e, int i, int j, int x){
    if (i > e || j < b)
        return;
    
    if (b >= i && e <= j){
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x; 
        return;
    }

    int Left = node << 1,Right = Left + 1,mid = (b + e) >> 1;
    
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}


int query(int node, int b, int e, int i, int j, int carry = 0){
    
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1); 

    int Left = node << 1,Right = Left + 1,mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop); 
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main(){
	//freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);

}