#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

typedef struct CirularLinkedList{
    node* create(node *last, int n){
        last = NULL;
        int x;
        if(n<=0){
            cout << "Invalid length" << endl;
            return last;
        }
        else{
            if(n>=1){
                node *tmp = new node;
                cout << "Ente data of 1 element : ";
                cin >> x;
                tmp->data = x;
                tmp->next = tmp;
                last = tmp;
                if(n==1)
                    return last;
                else{
                    node *q = last;
                    for(int i = 2; i<=n; i++){
                        node *tmp = new node;
                        cout << "Enter data of " << i << " element : ";
                        cin >> x;
                        tmp->data = x;
                        tmp->next = last->next;
                        last->next = tmp;
                        last = tmp;
                    }
                }
            }
        }
        return last;
    }
    
    int isEmpty(node *last){
        if(last == NULL)
            return 1;
        else
            return 0;
    }
    
    int isFull(){
        node *tmp = new node;
        if(tmp!=NULL){
            delete tmp;
            return 1;
        }
        else
            return 0;
    }
    
    int length(node *last){
        int l=0;
        if(last == NULL){
            cout << "List already empty" << endl;
            return 0;
        }
        node *q = last;
        do{
            l++;
            q = q->next;
        }
        while(q != last);
        return l;
    }
    
    int find(node *last, int pos){
        if(last == NULL){
            cout << "List is empty"<< endl;
            return -12345;
        }
        else if(pos<1 || pos>length(last)){
            cout << "Invalid position" << endl;
            return -12345;
        }
        else{
            node *q = last->next;
            for(int i=1; i<pos; i++){
                q = q->next;
            }
            return q->data;
        }
    }
    
    int search(node *last, int x){
    node *q = last;
        if(last == NULL){
            cout << "List is empty" << endl;
            return -1;
        }
        else{
            int pos = 1;
            do{
                q = q->next;
                if(q->data == x){
                    return pos;
                }
                else
                    pos++;
            }
            while(q != last);
        }
        if(q == last){
            return -12345;
        }
    }
    
    node* insert(node *last, int pos, int x){
        int l = length(last);
        if(pos<1 || pos>(l+1)){
            cout << "Invalid position" << endl;
            return last;
        }
        
        if(last == NULL && pos == 1){
            node *tmp = new node;
            tmp->data = x;
            tmp->next = tmp;
            last = tmp;
            return last;
        }
        
        else{
            if(pos==1){
                node *tmp = new node;
                tmp->data = x;
                tmp->next = last->next;
                last->next = tmp;
                return last;
            }
            else if(pos==l+1){
                node *tmp = new node;
                tmp->data = x;
                tmp->next = last->next;
                last->next = tmp;
                last = tmp;
                return last;
            }
            else if(pos>1 && pos<(l+1)){
                node *q = last->next;
                node *tmp = new node;
                while(pos!=2){
                    q = q->next;
                    pos--;
                }
                tmp->data = x;
                tmp->next = q->next;
                q->next = tmp;
                return last;
            }
        }
        return last;
    }
    void output(node *last){
        node *q = last;
        do{
            q = q->next;
            cout << q->data << " ";
        }
        while(q != last);
        cout << endl;
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
                last->next = q->next;
                x = q->data;
                delete q;
                return last;
            }
            if(pos==l){
                node *q = last;
                x = q->data;
                node *prev = last->next;
                while(prev->next != last){
                    prev = prev->next;
                }
                prev->next = last->next;
                last = prev;
                delete q;
                return last;
            }
            else{
                node *prev = last->next;
                while(pos!=2){
                    prev = prev->next;
                    pos--;
                }
                node *q = prev->next;
                x = q->data;
                prev->next = q->next;
                delete q;
                return last;
            }
        }
    }
}cll;

int main() {
    node *last = NULL;
    cll l1;
    last = l1.create(last, 5);
    l1.output(last);
    cout << l1.length(last) << endl;
    cout << l1.find(last, 5) << endl;
    cout << l1.search(last, 9) << endl;
    last = l1.insert(last, 5, 99);
    l1.output(last);
    int x = 0;
    last = l1.del(last, 4, x);
    cout << "deleted " << x << endl;
    l1.output(last);
    return 0;
}
