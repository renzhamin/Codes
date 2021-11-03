#include "doubly.cpp"
#define ll long long 
using namespace std;

int main(){
    init_list();
    int x;
    while(cin>>x && x!=-1){
        insert_back(1,x);
    }
    if(list_size<3){
        showAll();
        return 0;
    }
    struct Node* cur=head->next,*temp;
    int prev_value=cur->value;
    cur=cur->next;

    while(cur!=tail){
        if(cur->value == prev_value){
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            temp = cur;
            cur = cur->next;
            free(temp);
        } else {
            prev_value = cur->value;
            cur=cur->next;
        }
       
    }
    showAll();
}
