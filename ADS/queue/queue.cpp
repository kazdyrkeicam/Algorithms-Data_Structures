#include <iostream>
int absx(int x){if(x >= 0) return x; else return x * (-1);}

using namespace std;
struct Element{
    string name, surname;
    int points;
    Element *next;
    Element(string n, string s, int p){name = n; surname = s; points = p; next = NULL;}
};
struct Queue{
    int max, min;
    int sum;
    Element *head, *tail;
    Queue(){head = tail = NULL; max = min = 0; sum = 0;}
    void add(string n, string s, int p){
        Element *element = new Element(n, s, p);
        if(head == NULL){
            max = min = p;
            sum = p;
            head = tail = element;
        }
        else{
            sum += p;
            if(p > max) max = p;
            if(p < min) min = p;
            tail->next = element;
            tail = element;
        }
    }
    void finalshow(){
        Element *tmp = head;
        while(tmp != NULL){
            cout << tmp->name << " " << tmp->surname << endl;
            tmp = tmp->next;
        }
        cout << endl;
    }
    void show(){
        Element *tmp = head;
        cout << "\t\tMAX=" << max << "\tMIN=" << min << "\tSUMA=" << sum << endl;
        while(tmp != NULL){
            cout << tmp->name << " " << tmp->surname << " " << tmp->points << endl;
            tmp = tmp->next;
        }
        cout << "\tFINISH" << endl;
    }
    void findMax(){
        Element *tmp = head;
        max = tmp->points;
        while(tmp != NULL){
            if(tmp->points > max)   max = tmp->points;
            tmp = tmp->next;
        }
    }
    void findMin(){
        Element *tmp = head;
        min = tmp->points;
        while(tmp != NULL){
            if(tmp->points < min)   min = tmp->points;
            tmp = tmp->next;
        }
    }
};

void dequeue(Queue *one, Queue *two, int sum){
    int head1 = one->head->points;
    int head2 = two->head->points;
    one->tail->next = two->head;
    one->tail = one->tail->next;
    one->sum += one->tail->points;
    if(one->tail->points < one->min)  one->min = one->tail->points;
    if(one->tail->points > one->max)  one->max = one->tail->points;
    two->tail->next = one->head;
    two->tail = two->tail->next;
    two->sum += two->tail->points;
    if(two->tail->points < two->min)  two->min = two->tail->points;
    if(two->tail->points > two->max)  two->max = two->tail->points;
    one->sum -= one->head->points;
    two->sum -= two->head->points;
    one->head = one->head->next;
    two->head = two->head->next;
    one->tail->next = NULL;
    two->tail->next = NULL;
    if(sum != 0){
        if(head1 == one->max)    one->findMax();
        if(head1 == one->min)    one->findMin();
        if(head2 == two->max)    two->findMax();
        if(head2 == two->min)    two->findMin();
    }
}
void linked(Queue *one, Queue *two){
    one->tail->next = two->head;
    one->tail = one->tail->next;
    two->tail->next = one->head;
    two->tail = two->tail->next;
    one->head = one->head->next;
    two->head = two->head->next;
    one->tail->next = NULL;
    two->tail->next = NULL;
}

int main(){
    int scienum, maxDiff;
    int smallSum = 1000 * 100000;
    Queue *que = new Queue();
    Queue *que2 = new Queue();
    cin >> scienum >> maxDiff;
    scienum = scienum / 2;
    string n, s;
    int p;
    for(int i = 0; i < scienum; ++i){
        cin >> n >> s >> p;
        que->add(n, s, p);
    }
    for(int i = 0; i < scienum; ++i){
        cin >> n >> s >> p;
        que2->add(n, s, p);
    }
    int counter = 0;
    for(int i = 1; i < scienum + 1; ++i){
        if(que->max - que->min <= maxDiff){
            if(que2->max - que2->min <= maxDiff){
                if(smallSum > absx(que->sum - que2->sum)){
                    smallSum = absx(que->sum - que2->sum);
                    counter = i;
                }
            }
        }
        dequeue(que, que2, smallSum);
    }
    if(counter == 0)    cout << "NIE" << endl;
    else if(counter == 1){
        que2->finalshow();
        que->finalshow();
    }
    else{
        while(counter > 1){
            linked(que, que2);
            counter--;
        }
        que2->finalshow();
        que->finalshow();
    }
    return 0;
}
