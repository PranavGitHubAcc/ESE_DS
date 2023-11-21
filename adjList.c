#include <stdio.h>
#include <stdlib.h>
#define MAXNODES 4

typedef struct node{
    int vertexNum;
    struct node *next;
}Node;

typedef struct list{
    Node *head;
}List;

List *adjList[MAXNODES];

void edge(int s, int d){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertexNum = d;
    newNode->next = NULL;
    if(adjList[s]->head == NULL){
        adjList[s]->head = newNode;
        return;
    }
    Node *temp = adjList[s]->head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void addEdge(int s, int d){
    edge(s, d);
    edge(d, s);
}

void displayList(){
    for(int i = 0; i<MAXNODES; i++){
        printf("%d: ", i);
        Node *temp = adjList[i]->head;
        while(temp!=NULL){
            printf("%d ", temp->vertexNum);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    for(int i = 0; i<MAXNODES; i++){
        adjList[i] = (List*)malloc(sizeof(List));
        adjList[i]->head = NULL;
    }
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,3);
    displayList();
}
#include <stdio.h>
#include <stdlib.h>
#define MAXNODES 4

typedef struct node{
    int vertexNum;
    struct node *next;
}Node;

typedef struct list{
    Node *head;
}List;

List *adjList[MAXNODES];

void edge(int s, int d){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertexNum = d;
    newNode->next = NULL;
    if(adjList[s]->head == NULL){
        adjList[s]->head = newNode;
        return;
    }
    Node *temp = adjList[s]->head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void addEdge(int s, int d){
    edge(s, d);
    edge(d, s);
}

void displayList(){
    for(int i = 0; i<MAXNODES; i++){
        printf("%d: ", i);
        Node *temp = adjList[i]->head;
        while(temp!=NULL){
            printf("%d ", temp->vertexNum);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    for(int i = 0; i<MAXNODES; i++){
        adjList[i] = (List*)malloc(sizeof(List));
        adjList[i]->head = NULL;
    }
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,3);
    displayList();
}
