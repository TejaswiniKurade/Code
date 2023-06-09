#include <bits/stdc++.h>
using namespace std;
#define MAX 10


/*void make_set(int v, vector<int> &parent){
    parent[v] = v;
}
int find_set(int v, vector<int> &parent){
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}
void union_set(int a, int b, vector<int> &parent){
    a = find_set(a,parent);
    b = find_set(b,parent);
    if (a != b)
        parent[b] = a;
}
*/

class graph{
     int n,connected;
     int** adjmatrix;
     int** weight;
     bool* visited;
     public:
         graph(int size=10){
             n=size;
             connected=0;
             adjmatrix= new int *[n];
             weight = new int *[n];
             visited= new bool[n];
             
             for(int i=0;i<n;i++){
             
                adjmatrix[i]=new int[n];
                weight[i]=new int [n];
                visited[i]=false;
                
                for(int j=0;j<n;j++){
                    adjmatrix[i][j]=0;
                    weight[i][j]= INT_MAX;
                }
             }
         
         }
         
         
         ~graph(){
             for(int i=0;i<n;i++){
                 delete[] adjmatrix[i];
                 
             }
             delete[] adjmatrix;
         }
         
         
         
         void addEdge(int u,int v,int wt=0){
              adjmatrix[u][v]=1;
              adjmatrix[v][u]=1;
              weight[u][v]=wt;
              weight[v][u]=wt;
         
         }
         
         void remove(int u,int v){
              adjmatrix[u][v]=0;
              adjmatrix[v][u]=0;
              weight[u][v]=INT_MAX;
              weight[v][u]=INT_MAX;
         
         }
         
         void display(){
             cout<<"          Adjacency Matrix    "<<endl;
             cout<<"    ";
             for (int i = 0; i < n; i++){
				cout << i << " ";
			 }
			 cout <<endl;
			for (int i = 0; i < n; i++) {
				cout << i << " : ";
				for (int j = 0; j < n; j++){
				    cout << adjmatrix[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "                    Weight MATRIX  "<<endl;
			cout << "    ";
			for (int i = 0; i < n; i++){
				cout << i << " ";
			}
			cout <<endl;
			for (int i = 0; i < n; i++) {
				cout << i << " : ";
				for (int j = 0; j < n; j++){
				    if (weight[i][j] == INT_MAX)
				    {   
				        cout << -1 << " ";continue;
				    } 
				    cout << weight[i][j] << " ";
				}
				cout <<endl;
			}
         
         }
         
           void clear_visited(){
				for (int i = 0; i < n; i++){
					visited[i] = false;
				}
				return;
			}

			void dfs(int vertex){
				visited[vertex] = true;
				connected++;
				cout << vertex << " ";
				for (int i = 0; i < n; i++)
					if (adjmatrix[vertex][i] == 1 and visited[i] == false){
						dfs(i);
				    }
				return ;
			}

			void bfs(int vertex){
				queue <int> q;
				q.push(vertex);
				visited[vertex] = true;

				while (!q.empty()){
					int curr_vertex = q.front();
					q.pop();
					cout << curr_vertex << " ";
					for (int i = 0; i < n; i++)
						if (adjmatrix[curr_vertex][i] == 1 and visited[i] == false)
						    visited[i] = true, q.push(i);
				}
				return;
			}
			
			bool is_connected(){
				clear_visited();
				connected = 0;
                dfs(0);
				if (connected == n)
					return true;
				int count = 1;
				for (int i = 1; i < n; i++)
					if (visited[i] == false)
						dfs(i), count++;
				cout << "Total Connected components : " << count << "\n";
				return  false;
			}


};

int main(){

int n;
cout<<"enter number of nodes = ";
cin>>n;
graph gf(n);
int u, v;
int vertex; 
int choice;
do{
     cout<<"------  GRAPH  ------"<<endl;
     cout<<"1. Add edge"<<endl;
     cout<<"2. Remove edge"<<endl;
     cout<<"3. Display graph"<<endl;
     cout<<"4. Add all edges for a particular node"<<endl;
     cout<<"5. Depth first traversal"<<endl;
     cout<<"6. Breadth first traversal"<<endl;
     cout<<"7. Check if the Graph is Connected"<<endl;
     cout<<"8. EXIT"<<endl;
     
     cout<<"Enter your choice = ";
     cin>>choice;
     switch(choice){
          
          case 1:
                
                cout << "     Enter first node : "; cin >> u;
                cout << "     Enter second node : "; cin >> v;
                gf.addEdge(u, v);
                break;
          case 2:
                
                cout << "     Enter first node : "; cin >> u;
                cout << "     Enter second node : "; cin >> v;
                gf.remove(u, v);
                break;
          case 3:
                gf.display();
                break;
            
          case 4 : 
                
                cout << "   Enter node : "; cin >> u;
                for (int i = 0; i < n; i++){
                    gf.addEdge(u, i);
                }
                break;
          case 5 : 
                 
                cout << "Enter the root vertex : "; cin >> vertex;
                gf.clear_visited();
                gf.dfs(vertex);
                cout << "\n";
                break;
            
           case 6 : 
                
                cout << "Enter the root vertex : "; cin >> vertex;
                gf.clear_visited();
                gf.bfs(vertex);
                cout <<endl;
                break;
            
           case 7 : 
                if (gf.is_connected())
                    cout << "The graph is Connected!"<<endl;
                else
                    cout << "The graph is NOT Connected!"<<endl;
                break;
            
          case 8:
                exit(0);
            
     
     }





}while(choice!=8);



return 0;
}

