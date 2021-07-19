/*

Partycja postanowiła włączyć się do pewnej akcji. Grupa jej przyjaciół prowadzi eksperyment nad wydajnością badań grupy naukowców. Obecnie pracują nad nowymi metodami walki z globalnym ociepleniem. Ponieważ katastrofa może nastąpić lada moment trzeba działać szybko. Badacze muszą zostać rozdzieleni na dwie grupy pracujące równolegle. Okazuje się, że właśnie to jest kluczową sprawą dla wydajności. Partycja otrzymała listę naukowców składającą się z imienia, nazwiska oraz punktów zdolności badawczych. Im punktacja jest wyższa tym zdolniejszy jest dany naukowiec. Badacze są jednak niezwykle przywiązani do swoich miejsc. Siedzą przy okrągłym stole zawsze w takiej samej kolejności jaki prezentuje lista. Partycja musi ich podzielić na dwie równe grupy. Należy jednak pamiętać, że różnica między najzdolniejszym oraz najmniej zdolnym naukowcem powinna być jak najmniejsza i absolutnie nie może przekraczać ściśle określonej wartości. Mogłoby to spowodować konflikty w zespole. Ważniejsze są jednak średnie zdolności każdego zespołu która powinny być możliwie najrówniejsze. Zawsze może się zdarzyć sytuacja w której zespół można podzielić na więcej niż jeden sposób dlatego nasza bohaterka musi wykonać swoją pracę zgodnie ze ściśle określoną procedurą. Podzieli stół na dwie równe połowy względem otrzymanej listy. Następnie będzie przesuwała się o jedną osobę zgodnie z kierunkiem ruchu zegara. Pierwsze najlepsze rozwiązanie zostaje uznane za właściwy podział. Co ważne liczba naukowców zawsze jest parzysta. Ponieważ pracę należy wykonywać codziennie bo pracownicy często się zmieniają Partycji przydałby się program który zautomatyzuje pracę.

## Wejście:
W pierwszej linii wejścia program otrzymuje liczbę n oznaczającą ilość naukowców oraz v będącą maksymalną różnicą zdolności naukowców w zespole. Następnie w n liniach program otrzymuje dane naukowców zgodnie z ruchem wskazówek zegara, składające się z dwóch ciągu znaków f oraz s będących imieniem i nazwiskiem naukowca oraz liczbę naturalną i oznaczającą zdolność.

## Wyjście:
Na wyjściu program powinien wyświetlić dwie listy naukowców oddzielone spacją. Listy powinny być wyświetlone w kierunku zgodnym z kierunkiem wprowadzania. Jeżeli naukowców nie da się podzielić zgodnie z wytycznymi należy wyświetlić słowo „NIE”.

1 ≤ n ≤ 100000

1 ≤ i ≤ 1000

Przykładowe wejście:
6 5
Jan Nowak 12
Wojciech Kowalski 11
Irena Krawiec 1
Marcin Janowski 3
Krystian Król 2
Joanna Malinowska 10

Przykładowe wyjście:
Irena Krawiec
Marcin Janowski
Krystian Król

Joanna Malinowska
Jan Nowak
Wojciech Kowalski

Uwaga:
Rozwiązanie ma wykorzystywać samodzielną implementację kolejki bez wykorzystania bibliotek STL.

*/

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
