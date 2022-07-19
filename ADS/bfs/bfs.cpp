#include <iostream>
#include <queue>
using namespace std;
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define NOTSET -1


int min(int a, int b) {
	return a < b ? a : b;
}

struct Node {
	char c;
	Node* neighbors[4] = { NULL, NULL, NULL, NULL };
	int counter = NOTSET;
	int countCamera = NOTSET;
	bool isVisited() {
		return counter != NOTSET;
	}
};
Node* readGraph(){      //zwraca roota
    Node *root;
    Node *node;
    int row, col;
    char c;
    cin >> row >> col;
    Node *arr[row][col];

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            cin >> c;
            if(c == '#'){  //izolujemy; nie tworzymy noda
                arr[i][j] = NULL;
                continue;
            }/**/
            node = new Node;
            node->c = c;
            arr[i][j] = node;
            if(c == 'S')    root = node;    //19 linia; tu ustawiamy nasz link

            if(i > 0 && arr[i - 1][j] != NULL){
                node->neighbors[UP] = arr[i - 1][j];   //interesuje nas tylko gorny sasiad
                arr[i - 1][j]->neighbors[DOWN] = node;   //ustawiamy dolnego s. gornemu
            }/**/
            if(j > 0 && arr[i][j - 1] != NULL){
                node->neighbors[LEFT] = arr[i][j - 1];   //interesuje nas tylko lewy sasiad
                arr[i][j - 1]->neighbors[RIGHT] = node;   //ustawiamy prawego s. lewemu
            }/**/
        }
    }
    return root;
}


Node* searchMaze(Node* root, char target, char camera){ //zwracamy noda z X
	queue<Node*> que;
	que.push(root);
	Node* currentNode, * currentNeighbor;
	root->countCamera = 0;
	root->counter = 0;

	while (!que.empty()) {
		currentNode = que.front();
		que.pop();
		if (currentNode->c == target)
			return currentNode;
		
		for (int i = 0; i < 4; ++i) {
			currentNeighbor = currentNode->neighbors[i];
			if (currentNeighbor) {      //somsiady mogo byc nulami
				if (currentNeighbor->isVisited()) { //jesli ma inna wartosc niz notset
					currentNeighbor->countCamera = min(currentNeighbor->countCamera, currentNode->countCamera + (currentNeighbor->c == camera ? 1:0));
					//wybieramy optymalniejsze kamery dla sasiada
				}
				else {
					currentNeighbor->counter = currentNode->counter + 1;
//jesli nie byl odwiedzony to zwiekszamy counter, ale jesli byl to nie ruszamy go, bo BFS daje gwarancje ze beda takie same
					currentNeighbor->countCamera = currentNode->countCamera + (currentNeighbor->c == camera ? 1 : 0);
					que.push(currentNeighbor);
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);

	Node* root = readGraph();
	Node * target = searchMaze(root, 'X', 'M');
	cout << target->counter << " " << target->countCamera << endl;
	return 0;
}
