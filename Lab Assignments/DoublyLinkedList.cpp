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
