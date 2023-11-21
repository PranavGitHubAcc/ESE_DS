#include <stdio.h>
#define V 4

void make(int matrix[V][V]){
    for(int i =0;i<V;i++){
        for(int j=0;j<V;j++){
            matrix[i][j]=0;
        }
    }
}

void print(int matrix[V][V]){
    for(int i =0;i<V;i++){
        for(int j=0;j<V;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void add_edge(int matrix[V][V],int from,int to){
    matrix[from][to] = 1;
    matrix[to][from] = 1;
}

int main() {
    int edge = 1;
    int matrix[V][V];
    make(matrix);
    add_edge(matrix,0,1);
    add_edge(matrix,0,2);
    add_edge(matrix,0,3);
    add_edge(matrix,1,2);
    add_edge(matrix,2,3);
    print(matrix);
    printf("\n");
}
