//Prepared by : Ansh Kushwaha
#include <iostream>
using namespace std;

typedef struct term{ 
    int pow, coeff;
    term *next;
}term;

term* addTerm(term *first, int p, int c){
    if(p<0){
    cout << "Undefined power" << endl;
    return first;
    }
    if(first == NULL){
    term *tmp = new term;
    tmp->pow = p;
    tmp->coeff = c;
    tmp->next = first;
    first = tmp;
    return first;
    }
    
    else if(first->pow == p){
        first->coeff += c;
        return first;
    }

    else{
        int pos = 1;
        term *q = first;
        term *nxt = NULL;

        while(q->next!=NULL){
            nxt = q->next;
            if(p == q->pow){
                q->coeff += c;
                return first;
            }
            if(p > q->pow)
                break;
            else if(p < q->pow && p > nxt->pow){
                pos++;
                break;
            }
            else{
                q = q->next;
                pos++;
            }
        }
        if(p == q->pow && q->next == NULL){
            q->coeff += c;
            return first;
        }

        if(p < q->pow && nxt == NULL)
            pos++;

        if(pos==1){
            term* tmp = new term;
            tmp->pow = p;
            tmp->coeff = c;
            tmp->next = q;
            q = tmp;
            return q;
        }

        else{
            term *tmp = new term;
            tmp->pow = p;
            tmp->coeff = c;
            tmp->next = q->next;
            q->next = tmp;
            return first;
        }
    }
    return first;
}

term* create(term *&first, int n){
    int p, c;
    for(int i=1; i<=n; i++){
        cout << "Enter Coefficient and Power of " << i << " term : ";
        cin >> c >> p;
        first = addTerm(first, p, c);
    }
    return first;
}

term *multiply(term *one, term *two, term *res){
    term *tmp = two;
    while(one != NULL){
        while(tmp != NULL){
            res = addTerm(res, (one->pow + tmp->pow), (one->coeff * tmp->coeff));
            tmp = tmp->next;
        }
        tmp = two;
        one = one->next;
    }
    return res;
}

void printPoly(term *first){
    char var = 'x';
    while(first!=NULL){
        if(first->pow == 0){
            cout << first->coeff << " ";
            first = first->next;
        }

        else{
            cout << first->coeff << var << "^" << first->pow << " ";
            first = first->next;
        }
         if(!(first == NULL))
            cout << "+ ";  
    }
    cout << endl;
}

int main(){
    term *start1 = NULL;
    term *start2  = NULL;
    int choice, m, n, x;
    cout << "Enter the number of terms in polynomial 1 : ";
    cin >> m;
    start1 = create(start1, m);
    cout << "Enter the number of terms in polynomial 2 : ";
    cin >> n;
    start2 = create(start2, n);
    cout << "\n";

    cout << "Polynomial 1 : ";
    printPoly(start1);
    cout << "Polynomial 2 : ";
    printPoly(start2);
    cout << "\n";

    cout << "The multiplication of the above two polynomials : ";
    term *res = NULL;
    res = multiply(start1, start2, res);
    printPoly(res);
    return 0;
}