// BFS graph traversal in C
#include<stdio.h>
int queue[100],front = 0,back = 0;
void push(int val){ 
	queue[back] = val;
	back++;
}
void pop(){ 
	queue[front] = 0;
	front++; 
}
int graph[100][100],visited[100];
void bfs(int,int);
int main(){
	int n,vertices,u,v,source;
	printf("Enter no of nodes : ");
	scanf("%d",&n);
	printf("Enter no of vertices : ");
	scanf("%d",&vertices);
	printf("Enter the vertices : \n");
	for(int i=0;i<n;i++){
		visited[i]=0;
		for(int j=0;j<n;j++){
			graph[i][j]=0;//initialise of the graph
		}
	}
	for(int i=0;i<vertices;i++){
		scanf("%d%d",&u,&v);
		graph[u][v] = graph[v][u] = 1;
	}
	printf("Enter the source vertex : ");
	scanf("%d",&source);
	bfs(n,source);
}
void bfs(int n,int source){
	visited[source] = 1;
	push(source);
	while(front < back){
		int current_vertex = queue[front];
		printf("%d -->",current_vertex);
		pop();
		for(int i=0;i<n;i++){
			if((graph[current_vertex][i] == 1) && (visited[i] == 0)){
				visited[i] = 1;
				push(i);
			}
		}
	}
}
