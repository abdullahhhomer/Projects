#pragma once
#include <iostream>
#include<thread>
#include<Windows.h>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;



void play_music() {
    PlaySoundA("Rick-Roll-Sound-Effect.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

#include "D:\FAST\Third Semester Docs\Data Structures\D Project\21i2571_21i2569_21i2476\Project_DS\AVL Tree.cpp"


class WeightedGraph {
public:
    int rows;
    int cols;
    int** vertices;
    int** weights;
    int crystalRow, crystalCol;
    int** adjacencyMatrix; // 2D array to represent the adjacency matrix

    WeightedGraph(int r, int c) {
        rows = r;
        cols = c;
        vertices = new int* [rows];
        weights = new int* [rows];
        adjacencyMatrix = new int* [rows * cols];
        // initialize the adjacency matrix to all zeroes
        for (int i = 0; i < rows * cols; i++) {
            adjacencyMatrix[i] = new int[rows * cols];
            for (int j = 0; j < rows * cols; j++) {
                adjacencyMatrix[i][j] = 0;
            }
        }
        // randomly generate vertices and weights for the graph
        for (int i = 0; i < rows; i++) {
            vertices[i] = new int[cols];
            weights[i] = new int[cols];
            for (int j = 0; j < cols; j++) {//clear path
                int randomNum = rand() % 9;
                if (randomNum == 0) {
                    vertices[i][j] = 0;
                    weights[i][j] = 1;
                }
                else if (randomNum == 1) {//jewel
                    vertices[i][j] = 1;
                    weights[i][j] = 1;
                }
                else if (randomNum == 2) {//potion
                    vertices[i][j] = 2;
                    weights[i][j] = 1;
                }
                else if (randomNum == 3) {//weapon
                    vertices[i][j] = 3;
                    weights[i][j] = 1;
                }
                else if (randomNum == 4) {//deathpoint
                    vertices[i][j] = 4;
                    weights[i][j] = 1;
                }
                else if (randomNum == 5) {//obstacle
                    vertices[i][j] = 5;
                    weights[i][j] = 100;
                }
                else if (randomNum == 6) {//dragon
                    vertices[i][j] = 6;
                    weights[i][j] = 1;
                }
                else if (randomNum == 7) {//goblin
                    vertices[i][j] = 7;
                    weights[i][j] = 1;
                }
                else if (randomNum == 8) {//werewolf
                    vertices[i][j] = 8;
                    weights[i][j] = 1;
                }
            }
        }
        // randomly place the crystal on the graph
        int temprandomNum1 = rand() % rows;
        int temprandomNum2 = rand() % cols;
        vertices[temprandomNum1][temprandomNum2] = 9;//crystal
        weights[temprandomNum1][temprandomNum2] = 1;
        crystalRow = temprandomNum1;
        crystalCol = temprandomNum2;

        // populate the adjacency matrix based on the graph vertices and weights
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int vertexIndex = i * cols + j;
                if (vertices[i][j] != 5) { // ignore obstacles
                    if (i > 0 && vertices[i - 1][j] != 5) { // check up
                        int neighborIndex = (i - 1) * cols + j;
                        adjacencyMatrix[vertexIndex][neighborIndex] = weights[i - 1][j];
                    }
                    if (j > 0 && vertices[i][j - 1] != 5) { // check left
                        int neighborIndex = i * cols + (j - 1);
                        adjacencyMatrix[vertexIndex][neighborIndex] = weights[i][j - 1];
                    }
                    if (i < rows - 1 && vertices[i + 1][j] != 5) { // check down
                        int neighborIndex = (i + 1) * cols + j;
                        adjacencyMatrix[vertexIndex][neighborIndex] = weights[i + 1][j];
                    }
                    if (j < cols - 1 && vertices[i][j + 1] != 5) { // check right
                        int neighborIndex = i * cols + (j + 1);
                        adjacencyMatrix[vertexIndex][neighborIndex] = weights[i][j + 1];
                    }
                }
            }
        }
    }

    int getWeight(int row, int col) {
        return weights[row][col];
    }

    void printVertices() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << vertices[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printWeights() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << weights[i][j] << " ";
            }
            cout << endl;
        }
    }


    void printAdjacencyMatrix() {
        cout << " ";
        for (int i = 0; i < rows * cols; i++) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < rows * cols; i++) {
            cout << i << " ";
            for (int j = 0; j < rows * cols; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int getCrystalRow() {
        return crystalRow;
    }

    int getCrystalCol() {
        return crystalCol;
    }



    ~WeightedGraph() {
        // free memory for vertices array
        for (int i = 0; i < rows; i++) {
            delete[] vertices[i];
        }
        delete[] vertices;

        // free memory for weights array
        for (int i = 0; i < rows; i++) {
            delete[] weights[i];
        }
        delete[] weights;

        // free memory for adjacencyMatrix array
        for (int i = 0; i < rows * cols; i++) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }


};

/*The function first creates a copy of the adjacency matrix of the graph.It then applies Floyd's algorithm to
this copy to compute the shortest paths between all pairs of vertices in the graph. After this, it
prints the shortest paths from the starting point to all other points in the graph.

Finally, the function extracts the shortest path from the starting point to the ending point and returns
it as a 2D array.If there is no path between the starting and ending points, it returns nullptr.
*/

bool printShortestPath(int** path, int shortestPath, WeightedGraph*& graph, AVLTree*& tree, bool& check) {
    cout << "Shortest path: ";
    for (int i = 0; i < shortestPath; i++) {

        if (graph->vertices[path[i][0]][path[i][0]] == 4)//if deathpoint
        {
            check = true;
            return check;
        }
        if (graph->vertices[path[i][0]][path[i][1]] == 1)//if jewel
        {
            tree->insert(50);
        }
        if (graph->vertices[path[i][0]][path[i][1]] == 2)//if potion
        {
            tree->insert(70);
        }
        if (graph->vertices[path[i][0]][path[i][1]] == 3)//if weapon
        {
            tree->insert(30);
        }
        if (graph->vertices[path[i][0]][path[i][1]] == 6)//if dragon
        {
            tree->deleteByScore(50);
        }
        if (graph->vertices[path[i][0]][path[i][1]] == 7)//if goblin
        {
            tree->deleteByScore(70);
        }
        if (graph->vertices[path[i][0]][path[i][1]] == 8)//if werewolf
        {
            tree->deleteByScore(30);
        }
        if (graph->vertices[path[i][0]][path[i][1]] == 4)//if deathpoint
        {
            check = true;
            return check;
        }
        cout << "(" << path[i][0] << ", " << path[i][1] << ")";
        if (i < shortestPath - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
    return false;
}

int** floyd(WeightedGraph*& graph, int startRow, int startCol, int endRow, int endCol, AVLTree*& tree) {
    // create a copy of the adjacency matrix
    int** dist = new int* [graph->rows * graph->cols];
    for (int i = 0; i < graph->rows * graph->cols; i++) {
        dist[i] = new int[graph->rows * graph->cols];
        for (int j = 0; j < graph->rows * graph->cols; j++) {
            dist[i][j] = graph->adjacencyMatrix[i][j]; // initialize the distance matrix to be the same as the adjacency matrix
        }
    }

    // apply Floyd's algorithm
    for (int k = 0; k < graph->rows * graph->cols; k++) {
        for (int i = 0; i < graph->rows * graph->cols; i++) {
            for (int j = 0; j < graph->rows * graph->cols; j++) {
                if (dist[i][k] != 0 && dist[k][j] != 0 && (dist[i][j] == 0 || dist[i][k] + dist[k][j] < dist[i][j])) { // if the path through vertex k is shorter than the current path
                    dist[i][j] = dist[i][k] + dist[k][j]; // update the shortest path distance
                }
            }
        }
    }

    // return null if there is no path from start to end
    int shortestPath = dist[startRow * graph->cols + startCol][endRow * graph->cols + endCol];
    if (shortestPath == 0) {
        cout << "No path from (" << startRow << ", " << startCol << ") to (" << endRow << ", " << endCol << ")" << endl;
        return nullptr;
    }

    // construct the shortest path array
    int** path = new int* [shortestPath];
    for (int i = 0; i < shortestPath; i++) {
        path[i] = new int[2];
    }
    int currentRow = endRow;
    int currentCol = endCol;
    for (int i = shortestPath - 1; i >= 0; i--) {
        path[i][0] = currentRow;
        path[i][1] = currentCol;
        if (currentRow > 0 && dist[startRow * graph->cols + startCol][(currentRow - 1) * graph->cols + currentCol] == dist[startRow * graph->cols + startCol][currentRow * graph->cols + currentCol] - graph->getWeight(currentRow - 1, currentCol)) { // if the shortest path goes up
            currentRow--;
        }
        else if (currentCol > 0 && dist[startRow * graph->cols + startCol][currentRow * graph->cols + (currentCol - 1)] == dist[startRow * graph->cols + startCol][currentRow * graph->cols + currentCol] - graph->getWeight(currentRow, currentCol - 1)) { // if the shortest path goes left
            currentCol--;
        }
        else if (currentRow < graph->rows - 1 && dist[startRow * graph->cols + startCol][(currentRow + 1) * graph->cols + currentCol] == dist[startRow * graph->cols + startCol][currentRow * graph->cols + currentCol] - graph->getWeight(currentRow + 1, currentCol)) { // if the shortest path goes down
            currentRow++;
        }
        else if (currentCol < graph->cols - 1 && dist[startRow * graph->cols + startCol][currentRow * graph->cols + (currentCol + 1)] == dist[startRow * graph->cols + startCol][currentRow * graph->cols + currentCol] - graph->getWeight(currentRow, currentCol + 1)) { // if the shortest path goes right
            currentCol++;
        }
    }

    // print the shortest path
    bool death_check = false;
    printShortestPath(path, shortestPath, graph, tree, death_check);

    if (death_check == true) {
        return NULL;
    }

    // return the shortest path array
    return path;
}

void prim(WeightedGraph*& graph, AVLTree* tree) {
    int numVertices = graph->rows * graph->cols;
    int* parent = new int[numVertices]; // array to store the parent of each vertex in the tree
    int* key = new int[numVertices]; // array to store the minimum weight edge connecting each vertex to the tree
    bool* inTree = new bool[numVertices]; // array to keep track of vertices already in the tree

    // initialize the arrays
    for (int i = 0; i < numVertices; i++) {
        parent[i] = -1; // no parent yet
        key[i] = INT_MAX; // initialize to maximum value
        inTree[i] = false; // not in the tree yet
    }

    // start with the crystal vertex as the source
    int srcVertex = graph->getCrystalRow() * graph->cols + graph->getCrystalCol();
    key[srcVertex] = 0; // source vertex has no weight

    // keep adding vertices to the tree until all vertices are included
    for (int i = 0; i < numVertices - 1; i++) {
        // find the minimum weight edge connecting a non-tree vertex to the tree
        int minKey = INT_MAX;
        int minIndex = 0;
        for (int j = 0; j < numVertices; j++) {
            if (!inTree[j] && key[j] < minKey) {
                minKey = key[j];
                minIndex = j;
            }
        }
        // add the vertex to the tree
        inTree[minIndex] = true;
        // update the key values of adjacent vertices
        for (int j = 0; j < numVertices; j++) {
            if (graph->adjacencyMatrix[minIndex][j] != 0 && !inTree[j] && graph->adjacencyMatrix[minIndex][j] < key[j]) {
                key[j] = graph->adjacencyMatrix[minIndex][j];
                parent[j] = minIndex;
            }
        }
    }

    // print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 0; i < numVertices; i++) {
        if (parent[i] != -1) {
            if (graph->vertices[parent[i] / graph->cols][parent[i] % graph->cols] == 1)//if jewel
            {
                tree->insert(50);
            }
            if (graph->vertices[parent[i] / graph->cols][parent[i] % graph->cols] == 2)//if potion
            {
                tree->insert(70);
            }
            if (graph->vertices[parent[i] / graph->cols][parent[i] % graph->cols] == 3)//if weapon
            {
                tree->insert(30);
            }
            if (graph->vertices[parent[i] / graph->cols][parent[i] % graph->cols] == 6)//if dragon
            {
                tree->deleteByScore(50);
            }
            if (graph->vertices[parent[i] / graph->cols][parent[i] % graph->cols] == 7)//if goblin
            {
                tree->deleteByScore(70);
            }
            if (graph->vertices[parent[i] / graph->cols][parent[i] % graph->cols] == 8)//if werewolf
            {
                tree->deleteByScore(30);
            }
            cout << "(" << parent[i] / graph->cols << "," << parent[i] % graph->cols << ")--" << key[i] << "-->(" << i / graph->cols << "," << i % graph->cols << ")" << endl;
        }
    }

    // free memory
    delete[] parent;
    delete[] key;
    delete[] inTree;
}






// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool visited[], int V) {
    int min_dist = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min_dist) {
            min_dist = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the shortest path from source to target
void printPath(int parent[], int target) {
    if (parent[target] == -1)
        return;
    printPath(parent, parent[target]);
    cout << " -> " << target;
}

// Function to implement Dijkstra's algorithm for shortest path
void dijkstra(WeightedGraph*& graph, int source, int target) {
    int V = graph->rows * graph->cols;
    int* dist = new int[V];     // Stores the shortest distance from source to each vertex
    bool* visited = new bool[V]; // Keeps track of visited vertices
    int* parent = new int[V];   // Stores the parent vertex of each vertex in the shortest path

    // Initialize all distances as infinite and visited[] as false
    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        visited[v] = false;
        parent[v] = -1;
    }

    // Distance of source vertex from itself is always 0
    dist[source] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        // Update dist[v] only if it's not visited, there is an edge from u to v,
        // and the total weight of the path from source to v through u is smaller
        // than the current value of dist[v]
        for (int v = 0; v < V; v++) {
            int rowU = u / graph->cols;
            int colU = u % graph->cols;
            int rowV = v / graph->cols;
            int colV = v % graph->cols;

            if (!visited[v] && graph->adjacencyMatrix[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph->adjacencyMatrix[u][v] < dist[v] &&
                ((rowV == rowU - 1 && colV == colU) || // Check if v is above u
                    (rowV == rowU && colV == colU - 1) || // Check if v is to the left of u
                    (rowV == rowU + 1 && colV == colU) || // Check if v is below u
                    (rowV == rowU && colV == colU + 1))) { // Check if v is to the right of u
                dist[v] = dist[u] + graph->adjacencyMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    // If a path exists from source to target, print it
    if (dist[target] != INT_MAX) {
        cout << "Shortest Path from (" << source / graph->cols << ", " << source % graph->cols << ") to (" << target / graph->cols << ", " << target % graph->cols << "): ";
        cout << "(" << source / graph->cols << ", " << source % graph->cols << ")";
        printPath(parent, target);
        cout << "\nShortest Distance: " << dist[target] << endl;
    }
    else {
        cout << "No path exists from (" << source / graph->cols << ", " << source % graph->cols << ") to (" << target / graph->cols << ", " << target % graph->cols << ")" << endl;
    }
    // Clean up dynamically allocated memory
    delete[] dist;
    delete[] visited;
    delete[] parent;
}





class player {
public:
    int id;
    int score;

};

void module_2(player&);
void module_1(player&);
void login(player&);



void displayibox(string str) {
    cout << "\n\n\n\n\n\n\n\n";
    string line(str.length() + 6, '*');
    string linE(str.length() + 6, ' ');
    cout << "\t\t\t\t\t" << '|' << line << "|" << std::endl;
    cout << "\t\t\t\t\t" << "|" << linE << "|" << std::endl;
    cout << "\t\t\t\t\t" << "|   " << str << "\t" << "|" << std::endl;
    cout << "\t\t\t\t\t" << "|" << linE << "|" << std::endl;
    cout << "\t\t\t\t\t" << "|" << line << "|" << std::endl;
}


void Register(player& p1) {
    system("cls");
    displayibox("Register");
    int id;
    cout << "\n\n\nEnter your new ID: ";
    cin >> id;

    p1.id = id;
    p1.score = 0;
    fstream file("player.bin", ios::app | ios::binary);
    file.write((char*)&p1, sizeof(p1));
    file.close();
    login(p1);
}

void login(player& p1) {
    system("cls");
    displayibox("Login");
    int id;
    bool check = false;

    ifstream file("player.bin", ios::binary);


    cout << "\n\n\nEnter your ID: ";
    cin >> id;
    if (file.is_open()) {
        while (file.read((char*)&p1, sizeof(p1))) {
            if (id == p1.id) {
                check = true;
                break;
            }
            if (check) {
                break;
            }
        }
    }
    if (!check) {
        system("cls");
        displayibox("Login Failed");
        Sleep(3000);
        system("cls");
        int n;
        cout << "\nYou want to register press 1";
        cin >> n;
        if (n == 1) {
            Register(p1);
        }
    }
    if (check) {
        module_2(p1);
    }

}


void logout(player p1) {
    system("cls");
    displayibox("Logout");
    fstream file("player.bin", ios::app | ios::binary);
    file.write((char*)&p1, sizeof(p1));
    file.close();
    module_1(p1);
}






void select_floyd(WeightedGraph*& graph, AVLTree*& score_tree, int start_r, int start_c, int end_r, int end_c,player& p1) {
    int start_row = start_r;
    int start_col = start_c;
    int end_row = end_r;
    int end_col = end_c;
    int graph_row = graph->rows;
    int graph_col = graph->cols;
    int** floyd_MST = floyd(graph, start_row, start_col, 4, 4, score_tree);



    if (floyd_MST == NULL) {
        while (floyd_MST == NULL) {

            delete score_tree;
            delete graph;
            cout << "Graph Restarted" << endl;
            graph = new WeightedGraph(graph_row, graph_col);

            // Print the vertices of the graph
            cout << "Vertices of the graph:" << endl;
            graph->printVertices();
            cout << endl;

            // Print the weights of the vertices
            cout << "Weights of the vertices:" << endl;
            graph->printWeights();
            cout << endl;

            graph->printAdjacencyMatrix();

            score_tree = new AVLTree(0);
            end_row = graph->getCrystalRow();
            end_col = graph->getCrystalCol();


            floyd_MST = floyd(graph, start_row, start_col, 4, 4, score_tree);

        }
    }
    //module_2(p1);
}







void select_prims(WeightedGraph*& graph, AVLTree*& score_tree,player& p1) {
    prim(graph, score_tree);

   // module_2(p1);

}




void select_dijkstra(WeightedGraph*& graph, AVLTree*& score_tree, int start_r, int start_c, int end_r, int end_c,player& p1) {
    int start_row = start_r;
    int start_col = start_c;
    int end_row = end_r;
    int end_col = end_c;
    int graph_row = graph->rows;
    int graph_col = graph->cols;

    // Create the adjacency matrix
   // int** adjacencyMatrix = graph->getAdjacencyMatrix();

    // Perform Dijkstra's algorithm to find the shortest path
    dijkstra(graph, start_row * graph_col + start_col, end_row * graph_col + end_col);

   // module_2(p1);

}




void module_1(player& p1) {
    system("color 4e");
    system("cls");
    int n;


    displayibox("THE QUEST FOR THE CRYSTAL KINGDOM");
    Sleep(5000);
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tLoading";
            cout << " *";
            Sleep(100);
        }
        if (i % 5 == 0) {
            cout << " * *";
            Sleep(100);
        }
        if (i % 10 == 0) {
            cout << " * * *";
            Sleep(100);
        }
    }

    cout << "\n\n\n\nCHOOSE FROM THE BELOW MENU: ";
    cout << "\n1-Login";
    cout << "\n2-Register";
    cout << "\n3-Close";
    cout << "\nOption: ";
    cin >> n;
    switch (n) {
    case 1:
        login(p1);
        break;
    case 2:
        Register(p1);
        break;

    default:
        exit(0);

    }

}

void module_2(player& p1) {
    system("cls");
    int n;
    displayibox("THE QUEST FOR THE CRYSTAL KINGDOM");
    Sleep(5000);
    cout << "\n\n\n\nCHOOSE FROM THE BELOW MENU: ";
    cout << "\n1-Floyd";
    cout << "\n2-Prism";
    cout << "\n3-Kruskal";
    cout << "\n4-Dijkstra";
    cout << "\n5-Logout";
    cout << "\nOption: ";
    
    cin >> n;

    int graph_rows;
    int graph_cols;

    cout << "\n Enter graph rows: ";
    cin >> graph_rows;

    cout << "\n Enter graph cols: ";
    cin >> graph_cols;

    WeightedGraph* graph = new WeightedGraph(graph_rows, graph_cols);
    AVLTree* score_tree = new AVLTree(0);




    switch (n) {
    case 1:
        // Print the vertices of the graph
        cout << "Vertices of the graph:" << endl;
        graph->printVertices();
        cout << endl;

        // Print the weights of the vertices
        cout << "Weights of the vertices:" << endl;
        graph->printWeights();
        cout << endl;

        graph->printAdjacencyMatrix();

        int start_row;
        int start_column;
        int end_row;
        int end_column;


        cout << "Enter starting row: ";
        cin >> start_row;

        cout << endl << "Starting col: ";
        cin >> start_column;

        cout << endl << "Ending row: ";
        cin >> end_row;

        cout << endl << "Ending col: ";
        cin >> end_column;


        select_floyd(graph, score_tree, start_row, start_column, end_row, end_column,p1);
        p1.score = score_tree->sumScores(score_tree->root);
        cout << "Total score: " << p1.score << endl;
        system("pause");

        break;
    case 2:
        // Print the vertices of the graph
        cout << "Vertices of the graph:" << endl;
        graph->printVertices();
        cout << endl;

        // Print the weights of the vertices
        cout << "Weights of the vertices:" << endl;
        graph->printWeights();
        cout << endl;

        graph->printAdjacencyMatrix();
        select_prims(graph, score_tree,p1);
        p1.score = score_tree->sumScores(score_tree->root);
        cout << "Total score: " << p1.score << endl;
        Sleep(100);
        break;
    case 3:
        // Print the vertices of the graph
        cout << "Vertices of the graph:" << endl;
        graph->printVertices();
        cout << endl;

        // Print the weights of the vertices
        cout << "Weights of the vertices:" << endl;
        graph->printWeights();
        cout << endl;

        graph->printAdjacencyMatrix();
        p1.score = score_tree->sumScores(score_tree->root);
        cout << "Total score: " << p1.score << endl;
        system("pause");
        break;
    case 4:
        // Print the vertices of the graph
        cout << "Vertices of the graph:" << endl;
        graph->printVertices();
        cout << endl;

        // Print the weights of the vertices
        cout << "Weights of the vertices:" << endl;
        graph->printWeights();
        cout << endl;

        graph->printAdjacencyMatrix();




        //int start_row;
        //int start_column;
        //int end_row;
        //int end_column;


        cout << "Enter starting row: ";
        cin >> start_row;

        cout << endl << "Starting col: ";
        cin >> start_column;

        cout << endl << "Ending row: ";
        cin >> end_row;

        cout << endl << "Ending col: ";
        cin >> end_column;

        select_dijkstra(graph, score_tree, start_row, start_column, end_row, end_column,p1);
        p1.score = score_tree->sumScores(score_tree->root);
        cout << "Total score: " << p1.score << endl;
        system("pause");
        break;
    case 5:
        logout(p1);
        break;
    }
    int num;
    cout << "\nDo you want to try again? press 1 and for logout press 0";
    cin >> num;
    if (num == 1) {
        module_2(p1);
    }
    else {
        logout(p1);
    }

}



int main() {
    thread t(play_music);
    srand(time(NULL));

    player p1;
    module_1(p1);
    t.join();
    return 0;
}





