#include <iostream>
#include <cstring>

using namespace std;
void addVertex(char** labels, int count, int graph[20][20]);
void addEdge(int graph[20][20], char** labels, int count);
void removeVertex(int graph[20][20], char** labels, int count);
void removeEdge(int graph[20][20], char** labels, int count);
void printTable(int count, int graph[20][20], char** labels);
int findIndex(char** labels, char* text, int count);

/* Graph Creator is a data structure that has vertices and edges, you can add and remove them both
Author: Rowan Miller
Date: 05/03/24
*/

int main()
{
    int count = 0;
    bool stillPlaying = true;
    
    char input[30];
    int graph[20][20]; 
    
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++){
            graph[i][j] = 0; 
        }
    }
    
    char** labels = new char*[40];
    for(int u = 0; u < 20; u++) {
        char* text = new char[40];
        strcpy(text, " ");
        labels[u] = text;
    }
    
    
    while(stillPlaying == true) {
    cout << "Enter ADDVERTEX, ADDEDGE, PRINT, REMOVEVERTEX, REMOVEEDGE, SHORTESTPATH, or QUIT" << endl;
    cin >> input; 
    
        if(strcmp(input, "ADDVERTEX")==0) {
            count++;
            addVertex(labels, count, graph);

        } 

        if(strcmp(input, "ADDEDGE")==0) {
            addEdge(graph, labels, count);

        } 
        
        if(strcmp(input, "PRINT")==0) {
            printTable(count, graph, labels);

        }  
        
        if(strcmp(input, "REMOVEVERTEX")==0) {
            removeVertex(graph, labels, count);

        } 
        
        if(strcmp(input, "REMOVEEDGE")==0) {
            removeEdge(graph, labels, count);

        } 
        
       /* if(strcmp(input, "SHORTESTPATH")==0) {
         

        }  */
        
        if(strcmp(input, "QUIT")==0) {
            stillPlaying = false; 
        } 
    }
}

//used https://www.geeksforgeeks.org/add-and-remove-edge-in-adjacency-matrix-representation-of-a-graph/?ref=ml_lbp 
//for help with some code


//adds vertex
void addVertex(char** labels, int count, int graph[20][20]) {
    char* newLabel = new char[40];
    cout << "enter a vertex name" << endl;
    cin >> newLabel;
    labels[count] = newLabel; 
    
}

//adds edge to graph
void addEdge(int graph[20][20], char** labels, int count) {
    char start[20];
    char end[20];
    int weight;
    cout << "enter first label of edge" << endl;
    cin >> start;
    //finds location of first label
    int s = findIndex(labels, start, count);
    cout << "enter second label of edge " << endl;
    cin >> end;
    //finds location of second label
    int e = findIndex(labels, end, count);
    cout << "enter a weight" << endl;
    cin >> weight;
    //assigns weight to position on graph
    graph[s][e] = weight;
    
}

//removing a vertex
void removeVertex(int graph[20][20], char** labels, int count) {
    char d[20];
    cout << "enter a vertex to be deleted" << endl; 
    cin >> d;
    //iterating through labels
    for(int i=0;i<count+1;i++) {
        if(strcmp(labels[i], d)==0) {
            int toDelete = i;
            char* emptyLabel = new char[20];
            strcpy(emptyLabel, "");
            //making label NULL
            labels[toDelete] = emptyLabel;
            for(int j = 0; j<count+1;j++){
                graph[j][toDelete] = 0;
                graph[toDelete][j] = 0;
            }
        }
        else{
            cout << "value is not in tree" << endl;
        }
    }
    
}

//removes an edge
void removeEdge(int graph[20][20], char** labels, int count) {
    char start[20];
    char end[20];
    int weight;
    cout << "enter first label of edge to remove" << endl;
    cin >> start;
    //finds position of first label
    int s = findIndex(labels, start, count);
    cout << "enter second label of edge to remove" << endl;
    cin >> end;
    //finds position of second label
    int e = findIndex(labels, end, count);
    //assigning position on graph to 0 or deleting
    graph[s][e] = 0;

    
}

//finds position of label
int findIndex(char** labels, char* text, int count) {
    if (strcmp(text, "")==0) {
      //vertex doesn't exist  
        return 0;
    }
    for(int j=0;j<count+1;j++) {
        if(strcmp(labels[j], text)==0) {
            return j;
        }
    }
    
}

//prints out adjacency table
void printTable(int count, int graph[20][20], char** labels) {
    for (int i=0; i<count+1; i++) {
        for (int j=0; j<count+1; j++) {
            if ( (strcmp(labels[i], "")!=0) && (strcmp(labels[i], "")!=0)) {
                cout << graph[i][j] << "  ";
            }
        }
        if (strcmp(labels[i], "")!=0) {
            cout << endl;
        }
    }
}