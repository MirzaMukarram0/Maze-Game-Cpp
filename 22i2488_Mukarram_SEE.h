//Mirza Mukarram Haseeb  //22i-2488  //SE-E  //DSA Project  //"Car-Game"

#pragma once
using namespace std;

//Class for scores and player names
class TreeNode{
public:
    int score; //for scores
    string name;  //players name    
    TreeNode* right; //right for tree
    TreeNode* left;//left for tree

    //Default Const
    TreeNode(){
        //to 0
        score = 0;
        // to \0
        name = "\0"; 
        //to null
        right = NULL; 
        //to null
        left = NULL;
    }

    //Paramet const
    TreeNode(int sc,string na){
        score = sc;
        name = na;
        right = NULL;
        left = NULL;
    }
};

//Making a BinaryTree
class BinaryTree{
public:
    //root of binary tree
    TreeNode* Root; 
    //Default const
    BinaryTree(){Root = nullptr;}

    //For inserting the nodes in tree
    void insertnodes(string na,int sc){
        //creating new node
        TreeNode* newnode = new TreeNode(sc, na); //new TreeNode
        if (!Root){//if root is null
            Root = newnode;
        }
        //if root isn't Null
        else{
           TreeNode* current = Root; //creating node for a iterator
           while (current!=nullptr){
           //if score is greater then current
           if (sc>current->score){
           //if current right exists
               if (current->right){
                //then move on to right
                current = current->right;
               }
               else{
                //if not exists
                current->right = newnode; //then insert it 
                return;
                }
           }
           //if the score is less then the curr score
           else if (sc < current->score) {
                if (current->left) { //if curr left exists
                //move on to left
                current = current->left;
                }
                else {
                //if not exists
                current->left = newnode; //insert it there
                return;
                }
           }
           //if score == to the current score
           else if (sc==current->score){
               //if current left exists
               if (current->left){
               //move on to left
               current = current ->left;
               }
               else{
               //if not exists
               current->left = newnode; //insert it there
               return;
                }
           }
           //else return 
           else {
           return;
           }
      }

     }

    }

    //to display the name and scores of all the players scored in tree
    void DisplayTree(TreeNode* root){  
        //check if the passing node is null or not
        if (root != NULL){//if not null
            DisplayTree(root->right);//recursive on right

            cout << "\033[42m<-------------------------------------->\033[0m\n"; //using colours
            cout << "\033[93mName: " << root->name << " Total Score: " << root->score << "\033[0m\n\n"; //displaying data

            DisplayTree(root->left);//recursive on left
        }
    }
};

//Class for storing the playerscores
class Playerscore {
public:
    string name;
    int score;

    Playerscore() {
        score = 0;
        name = "\0";
    }

    Playerscore(int s, string n) {
        score = s;
        name = n;
    }
};

//For creating Coins 
class Coins {
public:
    //Data types for coins
    char type;
    int score;
    Coins* next;
    Coins() {
        score = 0;
        type = '\0';
        next = nullptr;

    }
    Coins(char t, int s) {
        type = t;
        score = s;
    }
};

//Class for making a linked list of coins
class ListofCoins {
public:
    Coins* head;

    ListofCoins() {
        head = nullptr;
    }
    //for inserting nodes
    void insertnodes(char t) {
        Coins* newnode = new Coins(t, 2);
        if (!head) {
            head = newnode;
        }
        else {
            Coins* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newnode;
        }
    }
    //for displaying the coins collected
    void displaycoins() {
        if (!head) {
            cout << "No coins collected yet." << endl;
            return;
        }
        Coins* curr = head;
        int count = 1;
        //For while iterator
        while (curr) {
            if (curr->type == '*') {
                //for displaying the content about coins
                cout << count << "- You Collected : " << curr->type << " , which added " << curr->score << " points" << endl;
                curr = curr->next;
                count++;
            }
            else if (curr->type == '$') {
                //for displaying the content about powerups
                cout << count << "- You Collected : " << curr->type << " , which multiplied your points by " << curr->score << " points" << endl;
                curr = curr->next;
                count++;
            }
            cout << endl;
        }
    }

};
//Class for obstacles
class Obstacle {
public:
    //data members
    char type;
    int row;
    int col;
    Obstacle* next;

    Obstacle(){
        next = nullptr;
        row = 0;
        col = 0;
        type = '\0';
        
    }

    Obstacle(char ty, int r, int c) {
        next = nullptr;
        row = r;
        col = c;
        type = ty;
    }

};
//for creating a queue
class Queue {
public:
    //data members
    Obstacle* rear;
    Obstacle* front;

    Queue() : rear(NULL), front(NULL) {}
    //for enqueuing 
    void enqueue(Obstacle* Q) {
        if (!front) {
            front = Q;
            rear = Q;
        }
        else {
            rear->next = Q;
            rear = Q;
        }
    }
    //for dequeuing 
    void dequeue() {
        if (!front) {
            return;
        }
        Obstacle* temp = front;
        if (front->next) {
            front = front->next;
            delete temp;
        }
        else {
            front = NULL;
            rear = NULL;
            delete temp;
        }
    }
    //for checking if queue is empty or not
    bool isEmpty() {
        if (front) {
            return false;
        }
        return true;
    }
};

//Node class declaratiom
class Node;
//For creating edges of graph
class Edge {
public:
    Node* next;

    Edge() {
        next = nullptr;
    }
    Edge(Node* n) {
        next = n;
    }

};
//for creating class of nodes
class Node {
public:
    //Data members 
    char id;
    Edge* Topedge;
    Edge* Bottomedge;
    Edge* Rightedge;
    Edge* Leftedge;

    Node() {
        Topedge = nullptr;
        Bottomedge = nullptr;
        Rightedge = nullptr;
        Leftedge = nullptr;

        id = '\0';
    }
    Node(char i) {
        id = i;
        Topedge = nullptr;
        Bottomedge = nullptr;
        Rightedge = nullptr;
        Leftedge = nullptr;
    }
};

//For creating a graph class
class Graph {
public:
    //Data Members
    Node*** Grid;//for dynamically creating adjlist type grid
    int hp; //for storing hp
    int horizontalnodes; //for rows in grid
    int verticalnodes; //for cols in grid
    static int points; //for storing points
    Queue* obstaclequeue; //for creating queue of obs
    ListofCoins* List; //for list of coins collected

    Graph() : Grid(nullptr), hp(0) {}

    Graph(int w, int h) {
        horizontalnodes = w;
        verticalnodes = h;
        //dynamically creating array
        Grid = new Node **[horizontalnodes];
        for (int x = 0; x < horizontalnodes; x++) {
            Grid[x] = new Node * [verticalnodes];
            for (int y = 0; y < verticalnodes; y++) {
                //At the extreme boundary
                if (x == 0 || x == horizontalnodes - 1) {
                    //For creating grid boundary
                    Grid[x][y] = new Node('_');
                }
                //At the extreme boundary
                else if (y == 0 || y == verticalnodes - 1) {
                    //For creating grid boundary
                    Grid[x][y] = new Node('|');
                }
                //At the Ending point
                else if (x == horizontalnodes - 2 && y == verticalnodes - 2) {
                    //For creating grid endpoint
                    Grid[x][y] = new Node('^');
                }
                //At the Starting point
                else if (x == 1 && y == 1) {
                    //For creating Car
                    Grid[x][y] = new Node('C');
                }
                else {
                    //For creating locations
                    Grid[x][y] = new Node('.');
                }
            }
        }
        //for objs
        obstaclequeue = new Queue();
        List = new ListofCoins();
        
    }

    //for creating edges
    void createlink() {
        for (int i = 0; i < horizontalnodes; i++) { //the outer for loop for rows
            for (int j = 0; j < verticalnodes; j++) { //inner for cols

                //Conditions for creating the Links of edges
                if (Grid[i][j] && j + 1 < verticalnodes) { //for creating the Right edges
                    //Creating instances of edges
                    Grid[i][j]->Rightedge = new Edge(Grid[i][j + 1]); 
                }

                if (Grid[i][j] && j - 1 >= 0) { //for creating the Left edges
                    //Creating instances of edges
                    Grid[i][j]->Leftedge = new Edge(Grid[i][j - 1]);
                }

                if (Grid[i][j] && i + 1 < horizontalnodes) { //for creating the bottom edges
                    //Creating instances of edges
                    Grid[i][j]->Bottomedge = new Edge(Grid[i + 1][j]);
                }

                if (Grid[i][j] && i - 1 >= 0) { //for creating the Top edges
                    //Creating instances of edges
                    Grid[i][j]->Topedge = new Edge(Grid[i - 1][j]);
                }
            }
        }
    }

    //For randomly creating powerups
    void generatepowerups(int count) {
        //loop according to the passed count
        int temp = 0;
        while(temp <count){
            //Random cols index verticalnodes
            int cols = ((rand()) % (verticalnodes - 2)) + 1;
            //Random rows index
            int rows = ((rand()) % (horizontalnodes - 2)) + 1;
            //Data of powerups
            char objtype = '$';
            //The random shouldn't repace the car or endpoints
            if (Grid[rows][cols]->id != '^') {
                if (Grid[rows][cols]->id != 'C') {
                    Grid[rows][cols]->id = objtype;
                }
            }
            temp++;
        }
    }
    //For randomly creating points
    void generatepoints(int count) {
        //loop according to the passed count
        int temp = 0;
        while (temp < count) {
            //Random cols index
            int cols = ((rand()) % (verticalnodes - 2)) + 1;
            //Random rows index
            int rows = ((rand()) % (horizontalnodes - 2)) + 1;
            //Data of coins
            char objtype = '*';
            //The random shouldn't repace the car or endpoints
            if (Grid[rows][cols]->id != '^') {
                if (Grid[rows][cols]->id != 'C') {
                    Grid[rows][cols]->id = objtype;
                }
            }
            temp++;
        }
    }
    //For randomly creating 
    void createrandomobs(int count) {
        //loop according to the passed count
        int temp = 0;
        while (temp < count) {
            //Random cols index
            int c = ((rand()) % (verticalnodes - 2)) + 1;
            //Random rows index
            int r = ((rand()) % (horizontalnodes - 2)) + 1;
            //The random shouldn't repace the car or endpoints
            if (Grid[r][c]->id != '^') {
                if (Grid[r][c]->id != 'C') {
                    Grid[r][c]->id = 'X';
                }
            }
            temp++;
        }
    }

    //For randomly creating hps
    void createhp(int count) {
        //loop according to the passed count
        int temp = 0;
        while (temp < count) {
            //Random cols index verticalnode
            int c = ((rand()) % (verticalnodes - 2)) + 1;
            //Random rows index
            int r = ((rand()) % (horizontalnodes - 2)) + 1;
            //The random shouldn't repace the car or endpoints
            if (Grid[r][c]->id != '^') {
                if (Grid[r][c]->id != 'C') {
                    Grid[r][c]->id = '+';
                }
            }
            temp++;
        }
    }

    //For randomly creating boundaries through queue
    void generateboundary(int count) {
        //loop according to the passed count
        int x = 0;
        while (x < count) {
            //Random cols index
            int c = ((rand()) % (verticalnodes - 3)) + 1;
            //Random rows index
            int r = ((rand()) % (horizontalnodes - 2)) + 1;
            //For creating the nodes to pass in queues
            Obstacle* temp = new Obstacle('|', r, c);\
            //using enqueue
            obstaclequeue->enqueue(temp);
            x++;
        }
    }

    //For randomly creating obstacles through queue
    void generateObstacles(int count) {
        //loop according to the passed count
        int x = 0;
        while(x <count){
            //Random cols index
            int c = ((rand()) % (verticalnodes - 3)) + 1;
            //Random rows index
            int r = ((rand()) % (horizontalnodes - 2)) + 1;
            //For creating the nodes to pass in queues
            Obstacle* temp = new Obstacle('X', r, c);
            //using enqueue
            obstaclequeue->enqueue(temp);
            x++;
        }
    }

    //now deqeueing the obstacles in the grid
    void addobstacles() {
        //loop while the queue isn't empty
        while (!obstaclequeue->isEmpty()) {
            //for front
            Obstacle* curr = obstaclequeue->front;
            //The osbtacle shouldn't repace the car or endpoints
            if (Grid[curr->row][curr->col]->id != 'C' && Grid[curr->row][curr->col]->id != '^') {
                Grid[curr->row][curr->col]->id = curr->type;
            }
            //dequeue
            obstaclequeue->dequeue();
        }
    }

    //now deqeueing the boundaries in the grid
    void addboundary() {
        //loop while the queue isn't empty
        while (!obstaclequeue->isEmpty()) {
            //for front
            Obstacle* curr = obstaclequeue->front;
            //The boundary shouldn't repace the car or endpoints
            if (Grid[curr->row][curr->col]->id != 'C' && Grid[curr->row][curr->col]->id != '^') {
                Grid[curr->row][curr->col]->id = curr->type;
            }
            //dequeue
            obstaclequeue->dequeue();
        }
    }

    //For Doing Movement 
    void movement(char c) {
        //indexes for movement
        int i = 1;
        int j = 1;
        
        for (i = 1; i < horizontalnodes - 1; i++) {  //Outer For Loop
            for (j = 1; j < verticalnodes - 1; j++) { //Inner loops
                if (Grid[i][j]->id == 'C') { //For finding the car in the grid
                    if (c=='s'||c=='S') { //To move down
                        if (Grid[i][j]->Bottomedge->next!=NULL && Grid[i][j]->Bottomedge!=NULL) { //if the bottom edge isnt null
                            if (Grid[i][j]->Bottomedge->next->id == 'X') { //checking for obs
                                //movement of car
                                Grid[i][j]->Bottomedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                hp--;//for Hp
                                points = points - 5;//for points
                            }
                            else if (Grid[i][j]->Bottomedge->next->id == '+') {//checking for hps
                                //movement of car
                                Grid[i][j]->Bottomedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                hp++;//for Hp
                            }
                            else if (Grid[i][j]->Bottomedge->next->id == '$') { //checking for powerups 
                                List->insertnodes(Grid[i][j]->Bottomedge->next->id); //storing in linked list
                                //movement of car
                                Grid[i][j]->Bottomedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                points = points * 2;//for points
                            }
                            else if (Grid[i][j]->Bottomedge->next->id == '*') { //checking for coins
                                List->insertnodes(Grid[i][j]->Bottomedge->next->id);//storing in linked list
                                //movement of car
                                Grid[i][j]->Bottomedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                points = points + 2;//for points
                            }
                             
                            else if (Grid[i][j]->Bottomedge->next->id != '|' && Grid[i][j]->Bottomedge->next->id != '_') {//checking boundaries 
                                //movement of car
                                Grid[i][j]->Bottomedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position

                            }
                            else {
                                //If the movement is restricted
                                cout << "Sorry! Not possible to move in this direction" << endl;
                            }
                            return;
                        }
                    }
                    else if (c == 'w' || c == 'W') { //if have to move Up
                        if (Grid[i][j]->Topedge->next != NULL && Grid[i][j]->Topedge != NULL) { //checking if Top is null or not
                            if (Grid[i][j]->Topedge->next->id == 'X') {  //checking for obs
                                //movement of car
                                Grid[i][j]->Topedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                hp--;//for Hp
                                points = points - 5;//for points
                            }
                            else if (Grid[i][j]->Topedge->next->id == '+') {//checking for hps
                                //movement of car
                                Grid[i][j]->Topedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                hp++;//for Hp
                            }
                            else if (Grid[i][j]->Topedge->next->id == '$') {//checking for powerups 
                                List->insertnodes(Grid[i][j]->Topedge->next->id);//storing in linked list
                                //movement of car
                                Grid[i][j]->Topedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                points = points * 2;//for points
                            }
                            else if (Grid[i][j]->Topedge->next->id == '*') {//checking for coins
                                List->insertnodes(Grid[i][j]->Topedge->next->id);//storing in linked list
                                //movement of car
                                Grid[i][j]->Topedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                points = points + 2;//for points
                            }
                            else if (Grid[i][j]->Topedge->next->id != '|' && Grid[i][j]->Topedge->next->id != '_') {//checking for boundaries
                                //movement of car
                                Grid[i][j]->Topedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position

                            }
                            else {
                                //If the movement is restricted
                                cout << "Sorry! Not possible to move in this direction" << endl;
                            }
                            return;
                        }
                    }
                    else if (c == 'a' || c == 'A') {
                        if (Grid[i][j]->Leftedge->next != NULL && Grid[i][j]->Leftedge != NULL) {
                            if (Grid[i][j]->Leftedge->next->id == 'X') { //checking for obs
                                //movement of car
                                Grid[i][j]->Leftedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                hp--;//for Hp 
                                points = points - 5;//for points
                            }
                            else if (Grid[i][j]->Leftedge->next->id == '+') { //checking for hps
                                //movement of car
                                Grid[i][j]->Leftedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                hp++;//for Hp
                            }
                            else if (Grid[i][j]->Leftedge->next->id == '$') { //checking for powerups 
                                //movement of car
                                List->insertnodes(Grid[i][j]->Leftedge->next->id);//storing in linked list
                                Grid[i][j]->Leftedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                points = points * 2;//for points
                            }
                            else if (Grid[i][j]->Leftedge->next->id == '*') {//checking for coins
                                List->insertnodes(Grid[i][j]->Leftedge->next->id);//storing in linked list
                                //movement of car
                                Grid[i][j]->Leftedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                points = points + 2;//for points
                            }
                            else if (Grid[i][j]->Leftedge->next->id != '|' && Grid[i][j]->Leftedge->next->id != '_') {//checking for boundaries
                                //movement of car
                                Grid[i][j]->Leftedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position

                            }
                            else {
                                //If the movement is restricted
                                cout << "Sorry! Not possible to move in this direction" << endl;
                            }
                            return;
                        }
                    }

                    else if(c=='d' || c=='D'){ //for moving right
                        if (Grid[i][j]->Rightedge->next != NULL && Grid[i][j]->Rightedge != NULL  ) {
                            if (Grid[i][j]->Rightedge->next->id == 'X') { //checking for obs
                                //movement of car
                                Grid[i][j]->Rightedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                hp--;//for Hp
                                points = points - 5; //for points
                            }
                            else if (Grid[i][j]->Rightedge->next->id == '+') { //checking for hps
                                //movement of car
                                Grid[i][j]->Rightedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                hp++;//for Hp
                            }
                            else if (Grid[i][j]->Rightedge->next->id == '$') { //checking for powerups 
                                List->insertnodes(Grid[i][j]->Rightedge->next->id);//storing in linked list
                                //movement of car
                                Grid[i][j]->Rightedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                points = points * 2;//for points
                            }
                            else if (Grid[i][j]->Rightedge->next->id == '*') {//checking for coins
                                List->insertnodes(Grid[i][j]->Rightedge->next->id);//storing in linked list
                                //movement of car
                                Grid[i][j]->Rightedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                                points = points + 2;//for points
                            }
                            else if (Grid[i][j]->Rightedge->next->id != '|' && Grid[i][j]->Rightedge->next->id != '_') {//checking for boundaries
                                //movement of car
                                Grid[i][j]->Rightedge->next->id = Grid[i][j]->id;
                                Grid[i][j]->id = '.';//For replacing the car previous position
                            }
                            else {
                                //If the movement is restricted
                                cout << "Sorry! Not possible to move in this direction" << endl;
                            }
                            return;
                        }
                    }
                }
            }
        }
    }
   
    //checking for the endpoints
    bool checkendpoint() {
        for (int i = 1; i < horizontalnodes - 1; i++) {
            for (int j = 1; j < verticalnodes - 1; j++) {
                if (Grid[i][j]->id == 'C') { //for checking if the car is at the endpoint
                    if (i == horizontalnodes - 2 && j == verticalnodes - 2) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    //for checking the points condition
    bool checkpoints() {
        if (points < 0) { //if points less then zero
            return true;
        }
        else {
            return false;
        }
    }

    //for checking the hp condition
    bool checkhp() {
        if (hp <= 0) { //if hp is zero
            return true;
        }
        return false;
    }
    
    //The display function
    void display() {
        //outer for loop of rows
        for (int i = 0; i < horizontalnodes; i++) {
            for (int j = 0; j < verticalnodes; j++) { //inner for loop of cols
                
                if (Grid[i][j]->id == 'X') {
                    //For Displaying the Colour of 'X'
                    cout << "\033[1;31m" << Grid[i][j]->id << "\033[0m ";
                }

                else if (Grid[i][j]->id == '*') {
                    //For Displaying the Colour of '*'
                    cout << "\033[93m" << Grid[i][j]->id << "\033[0m ";
                }

                else if (Grid[i][j]->id == '$') {
                    //For Displaying the Colour of '$'
                    cout << "\033[1m\033[94m" << Grid[i][j]->id << "\033[0m ";
                }

                else if (Grid[i][j]->id == '^') {
                    //For Displaying the Colour of '^'
                    cout << "\033[1;32m" << Grid[i][j]->id << "\033[0m ";
                }

                else if (Grid[i][j]->id == '|') {
                    //For Displaying the Colour of '|'
                    cout << "\033[1m\033[42m" << Grid[i][j]->id << "\033[0m ";
                }

                else if (Grid[i][j]->id == '_') {
                    //For Displaying the Colour of '_'
                    cout << "\033[1m\033[46m" << Grid[i][j]->id << "\033[0m ";
                }

                else if (Grid[i][j]->id == '.') {
                    //For Displaying the Colour of '.'
                    cout << "\033[1;34m" << Grid[i][j]->id << "\033[0m ";
                }

                else if (Grid[i][j]->id == '+') {
                    //For Displaying the Colour of '+'
                    cout << "\033[1;35m" << Grid[i][j]->id << "\033[0m ";
                }

                else {
                    cout << Grid[i][j]->id << " ";
                }
            }
            cout << endl;
        }
    }

};
int Graph::points = 0; //For assigning the static points to zero