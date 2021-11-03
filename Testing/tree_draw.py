from visualiser.visualiser import Visualiser as vs

# Add decorator
# Decorator accepts optional arguments: ignore_args , show_argument_name, show_return_value and node_properties_kwargs
def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)

mx = 30
tree = 3*mx*[0]
arr = [0,10,5,39,-2,14,3,54,1,-12]



@vs(node_properties_kwargs={"shape":"record","color":"#f57542", "style":"filled", "fillcolor":"grey"})
def init(node,b,e):
    if b==e:
        tree[node]=arr[b];
        return;
    left=node*2; right=left+1; mid=(b+e)//2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];

@vs(node_properties_kwargs={"shape":"record","color":"#f57542", "style":"filled", "fillcolor":"grey"},ignore_args=["i","j"])
def query(node, b, e, i, j):
    if i>e or j<b: 
        return 0;

    if b>=i and e<=j: 
        return tree[node];

    left=node*2; right=left+1; mid=(b+e)//2;
    p1=query(node=left,b=b,e=mid,i=i,j=j)
    p2=query(node=right,b=mid+1,e=e,i=i,j=j)
    return p1+p2;

@vs(node_properties_kwargs={"shape":"record","color":"#f57542", "style":"filled", "fillcolor":"grey"},ignore_args=["i","j"])
def update( node, b, e, i, newvalue):
    if(i>e or i<b):
        return;
    if(b==e):
        tree[node]=newvalue; 
        return;

    left=node*2; right=left+1; mid=(b+e)//2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];


def main():
#     print(fib(2))
    n = len(arr)-1
    init(1,1,n)
#     query(node=1,b=1,e=n,i=1,j=3)
    vs.write_image("tree.png")
    # Save recursion tree to a file
#     vs.make_animation("tree.gif", delay=1)


if __name__ == "__main__":
    main()
