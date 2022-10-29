//Prepared by : Ansh Kushwaha
#include <iostream>
using namespace std;

typedef struct node{
    node *prev, *next;
    int data;
}node;

node* create(node *first, int n){
    if(n<=0){
        cout << "Can't create list.\n";
        return first;
    }
    int x;
    node *last;
    node *tmp = new node;
    tmp->prev = tmp->next = NULL;
    cout << "Enter data of 1 element : ";
    cin >> x;
    tmp->data = x;
    first = tmp;
    last = first;
    if(n== 1)
        return first;
        
    for(int i=2; i<=n; i++){
        cout << "Enter data of " << i << " element : ";
        cin >> x;
        node *tmp = new node;
        tmp->prev = last;
        tmp->next = last->next;
        tmp->data = x;
        last->next = tmp;
        last = tmp;
    }
    return first;
}

int isEmpty(node *first){
    if(first == NULL)
        return 1;
    else
        return 0;
}

int isFull(node *first){
    node *tmp = new node;
    if(tmp != NULL){
        delete tmp;
        return 0;
    }
    else
        return 1;
}

int length(node *first){
    int l = 0;
    while(first != NULL){
        l++;
        first = first->next;
    }
    return l;
}

int find(node *first, int pos){
    if(first == NULL){
        cout << "List is empty.\n";
        return -12345;
    }
    
    if(pos<1 || pos>length(first)){
        cout << "Invalid Position\n";
        return -12345;
    }
    
    for(int i=1; i<pos; i++)
        first = first->next;
    return first->data;
}

int search(node *first, int x){
    if(first == NULL){
        cout << "List is empty.\n";
        return -1;
    }
    int pos = 1;
    while(first != NULL){
        if(first->data == x)
            return pos;
        else{
            pos++;
            first = first->next;
        }
    }
    return -1;
}

node* insert(node *first, int pos, int x){
    int l = length(first);
    if(pos<1 || pos >(l+1)){
        cout << "Invalid position\n";
        return first;
    }
    if(l==0 && pos==1){
        node *tmp = new node;
        tmp->prev = tmp->next = NULL;
        tmp->data = x;
        first = tmp;
        return first;
    }
    else if(pos==1){
        node *tmp = new node;
        tmp->prev = NULL;
        tmp->next = first;
        tmp->data = x;
        first->prev = tmp;
        first = tmp;
        return first;
    }
    else if(pos<=l){
        node *q = first, *r;
        for(int i=1; i<pos-1; i++)
            q = q->next;
        node *tmp = new node;
        tmp->prev = q;
        tmp->next = q->next;
        tmp->data = x;
        r = q->next;
        q->next = tmp;
        r->prev = tmp;
        return first;
    }
    else{
        node *q = first;
        do{
            q = q->next;
        }
        while(q->next != NULL);
        node *tmp = new node;
        tmp->next = NULL;
        tmp->prev = q;
        tmp->data = x;
        q->next = tmp;
        return first;
    }
}
