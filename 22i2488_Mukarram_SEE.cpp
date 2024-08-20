//Mirza Mukarram Haseeb  //22i-2488  //SE-E  //DSA Project  //"Car-Game"

#include <iostream>
#include<fstream>
#include"22i2488_Mukarram_SEE.h"
#include<string>
using namespace std;

//Declaration of functions
void viewscore();
void MainMenu();
void Level1();
void Level2();
void Level3();
void Exportscore();
void Rules();

//Some Global Declaratio 
Graph* G = new Graph();
string playername;

void Level1() {

    G = new Graph(20, 20);
    G->hp = 3;
    G->createlink();
    G->generateObstacles(10);
    G->addobstacles();
    G->generateboundary(50);
    G->addboundary();
    G->generatepoints(30);

    int tmp = 0;
    while (true) {
        system("cls");
        cout << "\033[1;31mPoints : \033[0m" << G->points << "\033[1;31m\t Hp : \033[0m" << G->hp << endl << endl; //displaying points and hp
        G->display();
        char s;
        cin >> s;
        G->movement(s);
        tmp++;
        if (G->checkpoints()) {
            system("cls");
            cout << "Sorry! You Lost The Level" << endl;
            G->points = 0;
            G->List->displaycoins();
            Exportscore();
            string choice;
            cout << "Press Any Key to Return to menu" << endl;
            cin >> choice;
            MainMenu();
        }
        if (G->checkhp()) {
            system("cls");
            cout << "Sorry! You Lost The Level" << endl;
            G->List->displaycoins();
            Exportscore();
            G->points = 0;
            string choice;
            cout << "Press Any Key to Return to menu" << endl;
            cin >> choice;
            MainMenu();


        }
        if (tmp == 15) {
            G->createhp(1);
            G->generatepowerups(1);
            G->createrandomobs(3);
            tmp = 0;
        }

        if (G->checkendpoint()) {
            system("cls");
            string choice;
            cout << "Congratulations! You Won the Level" << endl;
            cout << "These Are you Game Stats" << endl;
            G->List->displaycoins();
            cout << "Press Any Key When You Are ready to play Next Level" << endl;
            cin >> choice;
            Level2();
            MainMenu();
            return;
        }
    }
}

void Level2() {

    G = new Graph(25, 25);
    G->hp = 3;
    G->createlink();
    G->generateObstacles(25);
    G->addobstacles();
    G->generatepoints(40);
    G->generateboundary(65);
    G->addboundary();
    int tmp = 0;

    while (true) {
        system("cls");
        cout << "\033[1;31mPoints : \033[0m" << G->points << "\033[1;31m\t Hp : \033[0m" << G->hp << endl << endl; //displaying points and hp
        G->display();
        char s;
        cin >> s;
        G->movement(s);
        tmp++;
        if (tmp == 20) {
            G->createhp(1);
            G->generatepowerups(2);
            G->createrandomobs(3);
            tmp = 0;
        }
        if (G->checkpoints()) {
            system("cls");
            cout << "Sorry! You Lost The Level" << endl;
            G->points = 0;
            G->List->displaycoins();
            Exportscore();
            string choice;
            cout << "Press Any Key to Return to menu" << endl;
            cin >> choice;
            MainMenu();

        }
        if (G->checkhp()) {
            system("cls");
            cout << "Sorry! You Lost The Level" << endl;
            G->List->displaycoins();
            Exportscore();
            G->points = 0;
            string choice;
            cout << "Press Any Key to Return to menu" << endl;
            cin >> choice;
            MainMenu();


        }
        if (G->checkendpoint()) {
            system("cls");
            string choice;

            cout << "Congratulations! You Won the Level" << endl;
            cout << "These Are you Game Stats" << endl;
            G->List->displaycoins();
            cout << "Press Any Key When You Are ready to play Next Level" << endl;
            cin >> choice;
            Level3();

        }
    }
}

void Level3() {

    G = new Graph(35, 35);
    G->hp = 3;
    G->createlink();
    G->generateObstacles(60);
    G->addobstacles();
    G->generatepoints(70);
    G->generateboundary(120);
    G->addboundary();
    int tmp = 0;
    while (true) {
        system("cls");
        cout << "\033[1;31mPoints : \033[0m" << G->points << "\033[1;31m\t Hp : \033[0m" << G->hp << endl << endl; //displaying points and hp
        G->display();
        char s;
        cin >> s;
        G->movement(s);
        tmp++;
        if (tmp == 25) {
            G->createhp(2);
            G->generatepowerups(2);
            G->createrandomobs(5);
            tmp = 0;
        }
        if (G->checkhp()) {
            system("cls");
            cout << "Sorry! You Lost The Level" << endl;
            G->List->displaycoins();
            Exportscore();
            G->points = 0;
            string choice;
            cout << "Press Any Key to Return to menu" << endl;
            cin >> choice;
            MainMenu();
        }
        if (G->checkpoints()) {
            system("cls");
            cout << "Sorry! You Lost The Level" << endl;
            G->points = 0;
            G->List->displaycoins();
            Exportscore();
            string choice;
            cout << "Press Any Key to Return to menu" << endl;
            cin >> choice;
            MainMenu();

        }
        if (G->checkendpoint()) {
            system("cls");
            string choice;
            cout << "Congratulations! You Won All the Levels" << endl;
            cout << "These Are you Game Stats" << endl;
            G->List->displaycoins();
            Exportscore();
            G->points = 0;
            cout << "Press Any Key to Return to menu" << endl;
            cin >> choice;
            MainMenu();
        }
    }
}

void PlayGame() {
    G = new Graph();
    system("cls");
    cout << "Enter Your Name: ";
    cin >> playername;
    Level1();
}

void Exportscore() {
    //for exporting data
    ofstream outFile("scores.txt", ios::app);
    if (outFile.is_open()) {
        outFile << playername << " " << G->points << endl;
    }
    outFile.close();
}

void viewscore() {
    system("cls");
    //Basic variable for file name
    string file = "scores.txt";
    BinaryTree* L = new BinaryTree();
    //Basic operator for importing from a file
    ifstream importfile(file);
    //for checking if file is open or not
    if (!importfile.is_open()) {
        //if file not open
        cout << "Error! Can't open the Text File" << endl;
        return;
    }
    string line;
    string n;
    int p;
    //using getline for storing a line of content 
    while (getline(importfile, line)) {
        //For Finding the positions at which spaces occur in the line
        int space1 = line.find(' '); //space1 is position 1
        //For storing the content in strings 
        n = line.substr(0, space1);
        p = stoi(line.substr(space1 + 1));
        //inserting in the binary tree
        L->insertnodes(n, p);
    }
    importfile.close();
    //displaying the tree
    L->DisplayTree(L->Root);
    
    int temp;
    cout << "Press Any Key to Return" << endl;
    cin >> temp;
    MainMenu();
}


//Function for the Rules and Regulations
void Rules() {
    system("cls");
    //Displaying the Rules
    cout << "\033[1;105m<------------------:Rules:------------------>\033[0m\n\n";
    cout << "\033[1;91m1- 'X' will deduct your points by 5 and Hp by 1\033[0m\n";
    cout << "\033[1;91m2- '*' will increase your points by 1\033[0m\n";
    cout << "\033[1;91m3- '$' will Multiply your points by 2\033[0m\n";
    cout << "\033[1;91m4- '|' and '_' player can't traverse through them\033[0m\n";
    cout << "\033[1;91m5- '+' will increase your hp by 1\033[0m\n\n\n";

    //Displaying the Controls
    cout << "\033[1;101m<-----------------:Controls:----------------->\033[0m\n\n";
    cout << "\033[93mA to Move Left\033[0m\n";
    cout << "\033[93mW to Move Up\033[0m\n";
    cout << "\033[93mS to Move Down\033[0m\n";
    cout << "\033[93mD to Move Right\033[0m\n";
    cout << endl;
    int temp;
    cout << "Press Any Key to Return" << endl;
    cin >> temp;
    MainMenu();
}

void MainMenu() {

    int opt = -1;
    int width = 0, height = 0;
    system("cls");
    //A Structure of 2D Car
    cout << "\033[1;107m\t\t<-------------------------------------------->\033[0m\n";
    cout << "\033[1;70m\t\t  222   DDD  \t   CCCC   AAA    RRRR   SSSS \033[0m" << endl;
    cout << "\033[1;32m\t\t 2   2  D  D \t  C      A   A   R   R  S    \033[0m" << endl;
    cout << "\033[1;50m\t\t    2   D  D \t  C      AAAAA   RRRR    SSS \033[0m" << endl;
    cout << "\033[1;32m\t\t   2    D  D \t  C      A   A   R  R       S\033[0m" << endl;
    cout << "\033[1;70m\t\t 22222  DDD  \t   CCCC  A   A   R   R  SSSS \033[0m" << endl;
    cout << "\033[1;107m\t\t<-------------------------------------------->\033[0m\n";
    cout << endl;
    //for menu
    cout << "\t\t\t\t\033[1;32m1-Play Game\033[0m\n";
    //play game
    cout << "\033[1;107m\t\t<-------------------------------------------->\033[0m\n";
    cout << "\t\t\t\t\033[1;32m2-View Scores\033[0m\n";
    //view score
    cout << "\033[1;107m\t\t<-------------------------------------------->\033[0m\n";
    cout << "\t\t\t\t\033[1;32m3-Rules & Controls\033[0m\n";
    //rules and controls
    cout << "\033[1;107m\t\t<-------------------------------------------->\033[0m\n";
    cout << "\t\t\t\t\033[1;32m0-Exit\033[0m\n";
    //exit game
    cout << "\033[1;107m\t\t<-------------------------------------------->\033[0m\n";
    cin >> opt;
    //if to exit game
    if (opt == 0) {
        exit(0);
    }
    //to play game
    else if (opt == 1) {
        PlayGame();
    }
    //to view scores
    else if (opt == 2) {
        viewscore();
    }
    //to view rules 
    else if (opt == 3) {
        Rules();
    }
    //if wrong input
    else {
        MainMenu();
    }
}

//main function
int main() {
    //Calling menu
    MainMenu();
    cout << "Hope You Enjoyed The Game" << endl;
    return 0;

}
