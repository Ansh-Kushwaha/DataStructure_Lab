#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *prev;
    node *next;
}node;

node* create(node *last , int n){
    if(n<=0){
        cout << "Can't create list" << endl;
        return last;
    }
    else{
        last = NULL;
        int x;
        node *first;
        node *tmp = new node;
        cout << "Enter data of 1 element : ";
        cin >> x;
        tmp->data = x;
        tmp->prev = tmp;
        tmp->next = tmp;
        last = tmp;
        first = tmp;
        if(n==1)
            return last;
        for(int i=2; i<=n; i++){
            node *tmp = new node;
            cout << "Enter data of " << i << " element : ";
            cin >> x;
            tmp->data = x;
            tmp->prev = last;
            tmp->next = last->next;
            last->next = tmp;
            first->prev = tmp;
            last = tmp;
        }
    }
    return last;

}

bool isFull(){
    node *tmp = new node;
    if(tmp!=NULL){
        delete tmp;
        return false;
    }
    else
        return true;
}

bool isEmpty(node *last){
    if(last == NULL)
        return true;
    else
        return false;
}

int length(node *last){
    int l = 0;
    if(last == NULL)
        return 0;
    node *q = last->next;
    do{
        l++;
        q = q->next;
    }
    while(q!=last->next);
    return l;
}

int search(node *last, int x){
    int pos = 1;
    node *q = last->next;
    if(isEmpty(last))
        return -12345;
    else{
        do{
            if(q->data == x)
                break;
            else{
                q = q->next;
                pos++;
            }
        }
        while(q!=last->next);
    }
    if(q == last->next)
        return -1;
    else
        return pos;
}

int find(node *last, int pos){
    int l = length(last);
    if(length == 0)
        return -12345;
    else if(pos<1 || pos>l)
        return -12345;
    else{
        if(pos<=l/2){
            node *q = last->next;
            while(--pos){
                q = q->next;
            }
            return q->data;
        }
        else{
            pos = l - (pos-1);
            node *q = last;
            while(--pos){
                q = q->prev;
            }
            return q->data;
        }
    }
    return -12345;
}

node* insert(node *last, int pos, int x){
    int l = length(last);
    if(pos<1 || pos > (l+1)){
        cout << "Invalid position" << endl;
        return last;
    }
    else{
        if(pos==1 && last==NULL){
            node *tmp = new node;
            tmp->data = x;
            tmp->prev = tmp;
            tmp->next = tmp;
            last = tmp;
            return last;
        }
        else if(pos==1 && last!=NULL){
            node *tmp = new node;
            tmp->data = x;
            tmp->prev = last;
            tmp->next = last->next;
            last->next->prev = tmp;
            last->next = tmp;
        }
        else if(pos>1 && pos<(l+1)){
            node *tmp = new node;
            tmp->data = x;
            if(pos<=l/2){
                // cout << "first case" << endl;
                node *q = last;
                while(--pos){
                    q = q->next;
                }
                tmp->prev = q;
                tmp->next = q->next;
                q->next->prev = tmp;
                q->next = tmp;
            }
            else{
                // cout << "second case" << endl;
                pos = l - (pos-1);
                node *q = last;
                while(pos!=1){
                    q = q->prev;
                    pos--;
                }
                tmp->next = q;
                tmp->prev = q->prev;
                q->prev->next = tmp;
                q->prev = tmp;               
            }
        }
        else{
            node *tmp = new node;
            tmp->data = x;
            tmp->prev = last;
            tmp->next = last->next;
            last->next->prev = tmp;
            last->next = tmp;
            last = tmp;
        }
    }
    return last;
}

node* del(node *last, int pos, int &x){
    int l = length(last);
    if(pos<1 || pos>l){
        cout << "Invalid Position" << endl;
        return last;
    }
    else{
        if(pos==1){
            node *q = last->next;
            x = q->data;
            q->next->prev = last;
            last->next = q->next;
            delete q;
            return last;
        }
        else if(pos==l){
            node *q = last;
            x = q->data;
            q->next->prev = q->prev;
            q->prev->next = q->next;
            last = q->prev;
            delete q;
            return last;
        }
        else{
            node *tmp = new node;
            if(pos<=l/2){
                // cout << "first case" << endl;
                node *q = last;
                while(pos--){
                    q = q->next;
                }
                x = q->data;
                q->next->prev = q->prev;
                q->prev->next = q->next;
            }
            else{
                // cout << "second case" << endl;
                pos = l - (pos-1);
                node *q = last;
                while(pos--){
                    q = q->prev;
                }
                x = q->data;
                q->next->prev = q->prev;
                q->prev->next = q->next;
            }
        }
    }
    return last;
}

void output(node *last){
    node *q = last->next;
    cout << "LtoR : ";
    do{
        cout << q->data << " ";
        q = q->next;
    }
    while(q!=last->next);
    cout << "\n";
    cout << "RtoL : ";
    node *p = last;
    do{
        cout << p->data << " ";
        p = p->prev;
    }
    while(p!=last);
    cout << "\n";
}

int main(){
    node *last = NULL;
    last = create(last, 5);
    output(last);
    cout << length(last) << endl;
    cout << search(last, 9) << endl;
    cout << find(last, 3) << endl;
    last = insert(last, 1, 81);
    last = insert(last, 3, 82);
    last = insert(last, 8, 83);
    output(last);
    int x = 0;
    last = del(last, 1, x);
    cout << "Deleted : " << x << endl;
    last = del(last, 2, x);
    cout << "Deleted : " << x << endl;
    last = del(last, 6, x);
    cout << "Deleted : " << x << endl;
    output(last);
    return 0;
}