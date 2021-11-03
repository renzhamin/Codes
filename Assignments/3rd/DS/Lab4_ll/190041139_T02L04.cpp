#include "doubly.cpp"
#define ll long long 
using namespace std;

bool menu(){
    printf("1.insert at front\n2.insert at back\n3.insert after node\n4.update node\n5.remove node\n6.remove last node\n7.show the list\n8.exit\nEnter option : ");

    int option,key, v;
    cin >> option;
    switch(option){
        case 1:
            cout<<"Enter value : ";
            cin >> key;
            insert_front(1,key);
            break;
        case 2:
            cout<<"Enter value : ";
            cin >> key;
            insert_back(1,key);
            break;
        case 3:
            cout<<"Enter node value : ";
            cin >> key;
            cout<<"Enter new node value : ";
            cin >> v;
            insert_after_node(key, v);
            break;
        case 4:
            cout<<"Enter value : ";
            cin >> key;
            cout<<"Enter new value : ";
            cin >> v;
            update_node(key, v);
            break;
        case 5:
            cout<<"Enter node value: ";
            cin >> v;
            del_by_value(v);
            break;
        case 6:
            del_back(1);
            break;
        case 7:
            showAll();
            showAll_reverse();
            break;
        case 8:
            return 0;
        default:
            printf("invalid input\n");
    }
    return 1;
}

int main(){
    init_list();
    while(menu());
}
