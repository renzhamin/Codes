#include "doubly.cpp"
#define ll long long 
using namespace std;

#define push_front(x) insert_front(1,x)
#define push_back(x) insert_back(1,x)
#define pop_front() del_front(1)
#define pop_back() del_back(1)

int main(){
    init_list();
    for(int i=0;i<3;i++){
        push_back(i);
    }
    push_front(-1);
//     pop_front();
    showAll();
}
