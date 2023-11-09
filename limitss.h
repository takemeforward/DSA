#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end){

	int pivote = arr[start];

	int count = 0;
	for(int i = start; i<=end; i++){
		if(arr[i]<=pivote){
			count++;
		}
	}

	int pivoteIndex = count+start;

	swap(arr[start], arr[pivoteIndex]);

	int i = start, j = end;

	while(i<=pivoteIndex && j>pivoteIndex){

		if(arr[i]<=pivote){
			i++;
		}
		if(arr[j]>pivote){
			j--;
		}
		if(i<pivoteIndex && j>pivoteIndex){
			swap(arr[i++], arr[j--]);
		}
	}
	return pivoteIndex;
}

void quickSort(int arr[], int start, int end){
	if(start>=end){
		return;
	}
	int p = partition(arr, start, end);

	quickSort(arr, start, p-1);
	quickSort(arr, p+1, start);
}


void merge(vector<int> &arr, int low, int mid, int high){
	vector<int> temp;

	int left = low;
	int right = mid+1;

	while(left<=mid && right<=high){
		if(arr[left]<=arr[right]){
			temp.push_back(arr[left]);
			left++;
		}else{
			temp.push_back(arr[right]);
			right++;
		}
	}
	while(left<=mid){
		temp.push_back(arr[left]);
		left++;
	}

	while(right<=high){
		temp.push_back(arr[right]);
		right++;
	}

	for(int i = low; i<=high; i++){
		arr[i] = temp[i-low];
	}
}


void mergeSort(vector<int> &arr, int low, int high){

	if(low>=high)
		return;

	int mid = (low+high)/2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);

	merge(arr, low, mid, high);
}


// knapsack
#include<stdio.h>
#include<conio.h>
#include<iostream>
 
using namespace std;
 
// A utility function that returns maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more than Knapsack capacity W, then
    // this item cannot be included in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    // Return the maximum of two cases: (1) nth item included (2) not included
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
                knapSack(W, wt, val, n - 1));
}
 
// Driver program to test above function
int main()
{
    cout << "Enter the number of items in a Knapsack:";
    int n, W;
    cin >> n;
    int val[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight for item " << i << ":";
        cin >> val[i];
        cin >> wt[i];
    }
 
    //    int val[] = { 60, 100, 120 };
    //    int wt[] = { 10, 20, 30 };
    //    int W = 50;
    cout << "Enter the capacity of knapsack";
    cin >> W;
    cout << knapSack(W, wt, val, n);
 
    return 0;
}


// $ g++ 0-1Knapsack.cpp
// $ a.out
 
// Enter the number of items in a Knapsack:5
// Enter value and weight for item 0:11 111
// Enter value and weight for item 1:22 121
// Enter value and weight for item 2:33 131
// Enter value and weight for item 3:44 141
// Enter value and weight for item 4:55 151
// Enter the capacity of knapsack 300
// 99


// prims
C++ Program to find the minimum spanning tree of the given graph using Prims algorithm. Prim’s algorithm is a greedy algorithm that finds a minimum spanning tree for a connected weighted undirected graph. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.
Program:
#include <stdio.h>
#include <limits.h>
#include <iostream>
 
using namespace std;
 
// Number of vertices in the graph
#define V 5
 
// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
    min = key[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], int n, int graph[V][V])
{
    cout<<"Edge   Weight\n";
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
        return 0;
}
 
// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
    int parent[V]; // Array to store constructed MST
    int key[V]; // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    // Always include first 1st vertex in MST.
    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST
 
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)
 
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    // print the constructed MST
    printMST(parent, V, graph);
}
 
// driver program to test above function
int main()
{
    /* Let us create the following graph
     2    3
     (0)--(1)--(2)
     |   / \   |
     6| 8/   \5 |7
     | /     \ |
     (3)-------(4)
     9          */
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, { 2, 0, 3, 8, 5 },
            { 0, 3, 0, 0, 7 }, { 6, 8, 0, 0, 9 }, { 0, 5, 7, 9, 0 }, };
 
    // Print the solution
    primMST(graph);
 
    return 0;
}
Output:
Edge   Weight
0 - 1    2 
1 - 2    3 
0 - 3    6 
1 - 4    5 


// kruskal's algo

// Kruskal's algorithm in C++

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;  // graph
  vector<pair<int, edge> > T;  // mst
  int *parent;
  int V;  // number of vertices/nodes in graph
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];

  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
}
void Graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cout << endl;
  }
}
int main() {
  Graph g(6);
  g.AddWeightedEdge(0, 1, 4);
  g.AddWeightedEdge(0, 2, 4);
  g.AddWeightedEdge(1, 2, 2);
  g.AddWeightedEdge(1, 0, 4);
  g.AddWeightedEdge(2, 0, 4);
  g.AddWeightedEdge(2, 1, 2);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 5, 2);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 2, 3);
  g.AddWeightedEdge(3, 4, 3);
  g.AddWeightedEdge(4, 2, 4);
  g.AddWeightedEdge(4, 3, 3);
  g.AddWeightedEdge(5, 2, 2);
  g.AddWeightedEdge(5, 4, 3);
  g.kruskal();
  g.print();
  return 0;
}

// bfs dfs

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
//add the edge in graph
void edge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}
//function for bfs traversal
void bfs(int s,vector<int>adj[],bool visit[]){
  queue<int>q;//queue in STL
  q.push(s);
  visit[s]=true;
  while(!q.empty()){
    int u=q.front();
    cout<<u<<" ";
    q.pop();
//loop for traverse
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        q.push(adj[u][i]);
        visit[adj[u][i]]=true;
      }
    }
  }
}
//function for dfs traversal
void dfs(int s,vector<int>adj[],bool visit[]){
  stack<int>stk;//stack in STL
  stk.push(s);
  visit[s]=true;
  while(!stk.empty()){
    int u=stk.top();
    cout<<u<<" ";
    stk.pop();
//loop for traverse
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        stk.push(adj[u][i]);
        visit[adj[u][i]]=true;
      }
    }
  }
}
//main function
int main(){
  vector<int>adj[5];//vector of array to store the graph
  bool visit[5];//array to check visit or not of a node
  //initially all node are unvisited
  for(int i=0;i<5;i++){
    visit[i]=false;
  }
  //input for edges
  edge(adj,0,2);
  edge(adj,0,1);
  edge(adj,1,3);
  edge(adj,2,0);
  edge(adj,2,3);
  edge(adj,2,4);
  cout<<"BFS traversal is"<<"  ";
  //call bfs funtion
  bfs(0,adj,visit);//1 is a starting point
  cout<<endl;
  //again initialise all node unvisited for dfs
  for(int i=0;i<5;i++){
    visit[i]=false;
  }
  cout<<"DFS traversal is"<<"  ";
  //call dfs function
  dfs(0,adj,visit);//1 is a starting point
}

// implementation of stack

#include <iostream>
using namespace std;
int stack[100], n = 100, top = -1;
void push(int val) {
   if(top >= n-1)
      cout<<"Stack Overflow"<<endl;
   else {
      top++;
      stack[top] = val;
   }
}
void pop() {
   if(top <= -1)
      cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>= 0) {
      cout<<"Stack elements are:";
      for(int i = top; i>= 0; i--)
         cout<<stack[i]<<" ";
      cout<<endl;
   } else
      cout<<"Stack is empty";
}
int main() {
   int ch, val;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch! = 4);
   return 0;
}


// queue
#include <iostream>
using namespace std;
int queue[100], n = 100, front = - 1, rear = - 1;
void Insert() {
   int val;
   if (rear == n - 1)
   cout<<"Queue Overflow"<<endl;
   else {
      if (front == - 1)
      front = 0;
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}
void Delete() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow ";
      return ;
   } else {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;;
   }
}
void Display() {
   if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}
int main() {
   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: Insert();
         break;
         case 2: Delete();
         break;
         case 3: Display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
   return 0;
}