#include <iostream>
using namespace std;

struct term{
    int pow, coeff;
    term *next;
};

typedef struct polynomial{
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
            cout << "returned first" << endl;
            return first;
        }
        else{
            int pos = 1;
            term *q = first;
            term *nxt = NULL;
            while(q->next!=NULL){
                nxt = q->next;
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
            // cout << "pos = " << pos << endl;
            if(p < q->pow && nxt == NULL){
                pos++;
                // cout << "special" << endl;
            }
            if(pos==1){
                term* tmp = new term;
                tmp->pow = p;
                tmp->coeff = c;
                tmp->next = q;
                q = tmp;
                // cout << "inserted at " << pos << endl;
                return q;
            }
            else{
                term *tmp = new term;
                tmp->pow = p;
                tmp->coeff = c;
                tmp->next = q->next;
                q->next = tmp;
                // cout << "inserted at " << pos << endl;
                return first;
            }
        }
        return first;
    }

    term* add(term* one, term* two, term* res){
        while(one!=NULL && two!=NULL){
            if(one->pow == two->pow){
                res = addTerm(res, one->pow, (one->coeff+two->coeff));
                one = one->next;
                two = two->next;
                cout << "eq" << endl;
            }
            else if(one->pow < two->pow){
                res = addTerm(res, two->pow, two->coeff);
                two = two->next;
                cout << " t > o" << endl;
            }
            else if(one->pow > two->pow){
                res = addTerm(res, one->pow, one->coeff);
                one = one->next;
                cout << "o > t" << endl;
            }
        }
        while(one!=NULL || two!=NULL){
            if(one!= NULL){
                res = addTerm(res, one->pow, one->coeff);
                one = one->next;
            }
            if(two!= NULL){
                res = addTerm(res, two->pow, two->coeff);
                two = two->next;
            }
        }
        return res;
    }

    void printPoly(term *first){
        char var = 'x';
        while(first!=NULL){
            cout <<first->coeff << var << "^" << first->pow << " ";
            first = first->next;
            if(!(first == NULL))
                cout << "+ ";  
        }
        cout << endl;
    }
}poly;

int main(){
    term *first1 = NULL;
    poly p1;
    first1 = p1.addTerm(first1, 0, 1);
    first1 = p1.addTerm(first1, 5, 2);
    first1 = p1.addTerm(first1, 3, 4);
    first1 = p1.addTerm(first1, 4, 9);
    // first = p1.addTerm(first, 0, 2);

    term *first2 = NULL;
    poly p2;
    first2 = p2.addTerm(first2, 0, 2);
    first2 = p2.addTerm(first2, 5, 9);
    first2 = p2.addTerm(first2, 3, 10);
    first2 = p2.addTerm(first2, 7, 3);
    
    p1.printPoly(first1);
    p2.printPoly(first2);

    term *firstR = NULL;
    poly result;
    firstR = result.add(first1, first2, firstR);
    result.printPoly(firstR);
}