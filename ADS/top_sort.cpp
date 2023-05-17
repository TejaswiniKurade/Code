#include <bits/stdc++.h>
using namespace std;
#define MAX 10

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
             
             for(int i=1;i<=n;i++){
             
                adjmatrix[i]=new int[n];
                weight[i]=new int [n];
                visited[i]=false;
                
                for(int j=1;j<=n;j++){
                    adjmatrix[i][j]=0;
                    weight[i][j]= INT_MAX;
                }
             }
         
         }
         
         
         ~graph(){
             for(int i=1;i<=n;i++){
                 delete[] adjmatrix[i];
                 
             }
             delete[] adjmatrix;
         }
         
         
         
         void addEdge(int u,int v){
              adjmatrix[u][v]=1;
              //adjmatrix[v][u]=1;
              //weight[u][v]=wt;
              //weight[v][u]=wt;
         
         }
         
         void remove(int u,int v){
              adjmatrix[u][v]=0;
              adjmatrix[v][u]=0;
              //weight[u][v]=INT_MAX;
             // weight[v][u]=INT_MAX;
         
         }
         
                      void display(){
						 		cout<<"          Adjacency Matrix    "<<endl;
						 		cout<<"    ";
						    for (int i = 1; i <=n; i++){
								  cout << i << " ";
							}
							cout <<endl;
							for (int i = 1; i <= n; i++) {
								cout << i << " : ";
								for (int j = 1; j <= n; j++){
									cout << adjmatrix[i][j] << " ";
								}
								cout << "\n";
							}
							/*cout << "                    Weight MATRIX  "<<endl;
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
							}*/
					 
                        }
         
                        void clear_visited(){
							for (int i = 0; i < n; i++){
								visited[i] = false;
							}
							return;
	                   }
	                   
	                   void sort(){
	                         int x=n;
	                         vector<int> sorted;
	                         vector<int> indegree(x,0);
	                         queue<int> zero;
	                         int k=1;
	                         
	                         while(k<=n){
	                               int cnt=0;
	                               for(int i=1;i<=x;i++){
	                             
	                                  if(adjmatrix[i][k]==1){
	                                       cnt++;
	                                  }
	                         
	                               }
	                               indegree[k-1]=cnt;
	                               k++;
	                         }
	                         
	                         for(int i=0;i<x;i++){
	                             cout<<indegree[i]<<" ";
	                         }
	                         cout<<endl;
	                         for(int i=0;i<x;i++){
	                             if(indegree[i]==0){
	                                 zero.push(i+1);
	                             }
	                         }
	                         while(!zero.empty()){
	                             int z=zero.front();
	                             zero.pop();
	                             sorted.push_back(z);
	                             for(int i=0;i<x;i++){
	                                 indegree[i]--;
	                                 if(indegree[i]==0){
	                                     zero.push(i+1);
	                                 }
	                                 
	                             
	                             }
	                             
	                         
	                         
	                         }
	                         
	                         for(int i=0;i<sorted.size();i++){
	                             cout<<sorted[i]<<" ";
	                         }
	                         cout<<endl;
	                   
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
     cout<<"4. Sort"<<endl;
     
     cout<<"5. EXIT"<<endl;
     
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
                
                gf.sort();
                break;
          
          case 5:
                exit(0);
                break;
            
     
     }





}while(choice!=5);




return 0;
}
