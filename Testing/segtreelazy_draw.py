from visualiser.visualiser import Visualiser as vs

# Add decorator
# Decorator accepts optional arguments: ignore_args , show_argument_name, show_return_value and node_properties_kwargs

mx = 30
tree = 3*mx*[0]
lazy = 3*mx*[0]
arr = [0,10,5,39,-2,14,3,54,1,-12]



@vs(node_properties_kwargs={"shape":"record","color":"#f57542", "style":"filled", "fillcolor":"grey"})
def init(node,b,e):
    if b==e:
        tree[node]=arr[b];
        return;
    left=node*2; right=left+1; mid=(b+e)//2;
    init(node=left,b=b,e=mid);
    init(node=right,b=mid+1,e=e);
    tree[node]=tree[left]+tree[right];

# @vs(node_properties_kwargs={"shape":"record","color":"#f57542", "style":"filled", "fillcolor":"grey"},ignore_args=["i","j"])
def query(node, b, e, i, j, carry=0):
    if i>e or j<b: 
        return 0;

    if b>=i and e<=j: 
        return tree[node] + (e-b+1)*carry;

    left=node*2; right=left+1; mid=(b+e)//2;
    
    p1=0; p2=0;

    if not (i>mid or j<b):
        p1=query(node=left,b=b,e=mid,i=i,j=j,carry=carry+lazy[node])
    if not (i>e or j<mid+1):
        p2=query(node=right,b=mid+1,e=e,i=i,j=j,carry=carry+lazy[node])

    return p1+p2;

# @vs(node_properties_kwargs={"shape":"record","color":"#f57542", "style":"filled", "fillcolor":"grey"},ignore_args=["i","j"])
def update( node, b, e, i, j,newvalue):
    if(i>e or j<b):
        return;

    if(b>=i and e<=j):
        tree[node] += (e-b+1)*newvalue; 
        lazy[node] += newvalue;
        return;

    left=node*2; right=left+1; mid=(b+e)//2;
    if not (i>mid or j<b):
        update(node=left,b=b,e=mid,i=i,j=j,newvalue=newvalue);
    if not (i>e or j<mid+1):
        update(node=right,b=mid+1,e=e,i=i,j=j,newvalue=newvalue);
    tree[node]=tree[left]+tree[right]+(e-b+1)*lazy[node];


def main():
#     print(fib(2))
    n = len(arr)-1
    init(node=1,b=1,e=n)
#     update(node=1,b=1,e=n,i=1,j=3,newvalue=1)
#     query(node=1,b=1,e=n,i=1,j=3)
    vs.write_image("tree.png")
    # Save recursion tree to a file
#     vs.make_animation("tree.gif", delay=1)


if __name__ == "__main__":
    main()
