//******dijstra******
#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
    cout<<"no. of vertices, edges, starting vertex :";
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(n+1, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest path from source " << s << " to all other vertices:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << dist[i] << "\n";
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, INF));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int u = 0; u < n; u++) {
        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            dp[u][v] = w;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    cout << "\nAll pairs shortest path:\n";
    for (int i = 0; i < n; i++) {
        cout<<i<<" : ";
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

//******obst******
/*Given sequence k = k1<; k2<..... kn of n sorted keys, with a search probability pi for each key ki . Build the Binary search tree that has the least search cost given the access probability for each key. test your program for following example
p1 = 10, p2 = 3, p3 = 9, p4 = 2, p5 = 0, p6 = 10;
q0 = 5, q1 = 6, q2 = 4, q3= 4, q4 = 3, q5 = 8, q6 = 0 */

#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int calc(int arr[], int i, int j)
{
    int sum = 0;
    for (int k = i; k <= j; k++)
        sum += arr[k];
    return sum;
}

int obst(int key_arr[], int arr[], int n)
{
    int cost[n][n];
    for (int i = 0; i < n; i++)
        cost[i][i] = arr[i];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n - i + 1; j++)
        {
            int k = j + i - 1;
            cost[j][k] = INT_MAX;

            for (int r = j; r <= k; r++)
            {
                int c = ((r > j) ? cost[j][r - 1] : 0) + ((r < k) ? cost[r + 1][k] : 0) + calc(arr, j, k);
                if (c < cost[j][k])
                    cost[j][k] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int main()
{
    int n;
    cout << "Number of keys : ";
    cin >> n;
    
    int keys[n], prob[n];
    cout << "Value of the keys : " << endl;
    for (int i = 0; i < n; i++)
        cin >> keys[i];
    cout << " Input Search Probabilities of the keys : " << endl;
    for (int i = 0; i < n; i++)
        cin >> prob[i];
    cout << "Cost of Optimal Binary Search Tree is :: " << obst(keys, prob, n) << endl;
    return 0;
}

//******avl******

#include<iostream>
#include<cstring>
#include<cstdlib>
#define MAX 50
#define SIZE 20
using namespace std;

struct AVLnode
{
    public:
    char cWord[SIZE],cMeaning[MAX];
    AVLnode *left,*right;
    int iB_fac,iHt;
};

class AVLtree
{
	
    public:
        AVLnode *root;
        AVLtree()
        {
            root=NULL;
        }
        int height(AVLnode*);
        int bf(AVLnode*);
        AVLnode* insert(AVLnode*,char[SIZE],char[MAX]);
        AVLnode* rotate_left(AVLnode*);
        AVLnode* rotate_right(AVLnode*);
        AVLnode* LL(AVLnode*);
        AVLnode* RR(AVLnode*);
        AVLnode* LR(AVLnode*);
        AVLnode* RL(AVLnode*);
        AVLnode* delet(AVLnode*,char x[SIZE]);
        void inorder(AVLnode*);
        void Search(char []);
        void UpdateMeaning(char [], char []);
        

};

AVLnode *AVLtree::delet(AVLnode *curr,char x[SIZE])
{
    AVLnode *temp;
    if(curr==NULL)
        return(0);
    else
        if(strcmp(x,curr->cWord)>0)
        {
            curr->right=delet(curr->right,x);
            if(bf(curr)==2)
            if(bf(curr->left)>=0)
                curr=LL(curr);
            else
                curr=LR(curr);
        }
        else
        if(strcmp(x,curr->cWord)<0)
        {
            curr->left=delet(curr->left,x);
            if(bf(curr)==-2)
            if(bf(curr->right)<=0)
                curr=RR(curr);
            else
                curr=RL(curr);
        }
    else
    {
        if(curr->right!=NULL)
        {
            temp=curr->right;
            while(temp->left!=NULL)
            temp=temp->left;
            strcpy(curr->cWord,temp->cWord);
            curr->right=delet(curr->right,temp->cWord);
            if(bf(curr)==2)
            if(bf(curr->left)>=0)
                curr=LL(curr);
            else
                curr=LR(curr);
        }
        else
        return(curr->left);
    }
    curr->iHt=height(curr);
    return(curr);
}


AVLnode* AVLtree :: insert(AVLnode*root,char newword[SIZE],char newmeaning[MAX])
{
    if(root==NULL)
    {
        root=new AVLnode;
        root->left=root->right=NULL;
        strcpy(root->cWord,newword);
        strcpy(root->cMeaning,newmeaning);
    }
	
    else if(strcmp(root->cWord,newword)!=0)
    {
        if(strcmp(root->cWord,newword)>0)
        {
            root->left=insert(root->left,newword,newmeaning);
            if(bf(root)==2)
            {
                if (strcmp(root->left->cWord,newword)>0)
                    root=LL(root);
                else
                    root=LR(root);
            }
        }
		
        else if(strcmp(root->cWord,newword)<0)
        {
            root->right=insert(root->right,newword,newmeaning);
            if(bf(root)==-2)
            {
                if(strcmp(root->right->cWord,newword)>0)
                    root=RR(root);
                else
                    root=RL(root);
            }
        }
    }
    else
        cout<<"\nRedundant AVLnode";
    root->iHt=height(root);
    return root;
}

int AVLtree :: height(AVLnode* curr)
{
    int lh,rh;
    if(curr==NULL)
        return 0;
    if(curr->right==NULL && curr->left==NULL)
        return 0;
    else
    {
        lh=lh+height(curr->left);
        rh=rh+height(curr->right);
        if(lh>rh)
            return lh+1;
        return rh+1;
    }
}		

int AVLtree :: bf(AVLnode* curr)
{
    int lh,rh;
    if(curr==NULL)
        return 0;
    else
    {
        if(curr->left==NULL)
            lh=0;
        else
            lh=1+curr->left->iHt;
        if(curr->right==NULL)
            rh=0;
        else
            rh=1+curr->right->iHt;
        return(lh-rh);
    }
}
			
AVLnode* AVLtree :: rotate_right(AVLnode* curr)
{
    AVLnode* temp;
    temp=curr->left;
    curr->left=temp->right;
    temp->left=curr;
    curr->iHt=height(curr);
    temp->iHt=height(temp);
    return temp;
}

AVLnode* AVLtree :: rotate_left(AVLnode* curr)
{
    AVLnode* temp;
    temp=curr->right;
    curr->right=temp->left;
    temp->left=curr;
    curr->iHt=height(curr);
    temp->iHt=height(temp);
    return temp;
}

AVLnode* AVLtree :: RR(AVLnode* curr)
{
    curr=rotate_left(curr);
    return curr;
}

AVLnode* AVLtree :: LL(AVLnode* curr)
{
    curr=rotate_right(curr);
    return curr;
}
	
AVLnode* AVLtree :: RL(AVLnode* curr)
{
    curr->right=rotate_right(curr->right);
    curr=rotate_left(curr);
    return curr;
}

AVLnode* AVLtree::LR(AVLnode* curr)
{
    curr->left=rotate_left(curr->left);
    curr=rotate_right(curr);
    return curr;
}

void AVLtree :: inorder(AVLnode* curr)
{
    if(curr!=NULL)
    {
        inorder(curr->left);
        cout<<"\n\t"<<curr->cWord<<"\t"<<curr->cMeaning;
        inorder(curr->right);
    }
}

void AVLtree::Search(char word[SIZE])
{
    AVLnode* current = root;
    int comparisons = 0;

    while (current != NULL)
    {
        comparisons++;
        if (strcmp(word, current->cWord) == 0)
        {
            cout << "Word '" << word << "' is present in the AVL tree." << endl;
            cout << "Number of comparisons: " << comparisons << endl;
            return;
        }
        else if (strcmp(word, current->cWord) < 0)
            current = current->left;
        else
            current = current->right;
    }

    cout << "Word '" << word << "' is not present in the AVL tree." << endl;
}

void AVLtree::UpdateMeaning(char word[SIZE], char newMeaning[MAX])
{
    AVLnode* current = root;
    int comparisons = 0;

    while (current != NULL)
    {
        comparisons++;
        if (strcmp(word, current->cWord) == 0)
        {
            // Word found, update the meaning
            strcpy(current->cMeaning, newMeaning);
            cout << "Meaning updated for word '" << word << "'." << endl;
            cout << "Number of comparisons: " << comparisons << endl;
            return;
        }
        else if (strcmp(word, current->cWord) < 0)
            current = current->left;
        else
            current = current->right;
    }

    cout << "Word '" << word << "' is not present in the AVL tree." << endl;
}

int main()
{
    int iCh;
    AVLtree a;
    AVLnode *curr=NULL;
    char cWd[SIZE],cMean[MAX];
    char searchWord[SIZE];
    char wordToUpdate[SIZE];
    char newMeaning[MAX];
    do
    {	
        cout<<"\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Update meaning\n6.Exit";
        cout<<"\nEnter your choice :";
        cin>>iCh;
		
        switch(iCh)
        {
            case 1:	cout<<"\nEnter Word : ";
                cin>>cWd;
                cout<<"\nEnter Meaning : ";
                cin.ignore();
                cin.getline(cMean,MAX);
                a.root=a.insert(a.root,cWd,cMean);
                break;
			
            case 2:	cout<<"\n\tWORD\tMEANING";
                a.inorder(a.root);
                break;
				
            case 3:	cout<<"\nEnter the word to be deleted : ";
                    cin>>cWd;
                    curr=a.delet(a.root,cWd);
                    if(curr==NULL)
                        cout<<"\nWord not present!";
                    else
                        cout<<"\nWord deleted Successfully!";
                    curr=NULL;
                    break;
            case 4:
                    cout << "Enter the word to search: ";
                    cin >> searchWord;
                    a.Search(searchWord);
                    break;
            case 5:
                    cout << "Enter the word to update its meaning: ";
                    cin >> wordToUpdate;
                    cout << "Enter the new meaning: ";
                    cin.ignore();
                    cin.getline(newMeaning, MAX);

                    a.UpdateMeaning(wordToUpdate, newMeaning);
                    break;

			
            case 6:	exit(0);
        }
    }while(iCh!=6);
	 
    return 0;
}

//******heap sort******

// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program
int main()
{
    int arr[] = { 60 ,20 ,40 ,70, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
//heapify algorithm
// the loop must go reverse you will get after analyzing manually
// (i=n/2 -1) because other nodes/ ele's are leaf nodes
// (i=n/2 -1) for 0 based indexing
// (i=n/2) for 1 based indexing
    for(int i=n/2 -1;i>=0;i--){
    heapify(arr,n,i);
}

cout << "After heapifying array is \n";
    printArray(arr, n);


    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
	
return 0;
}


//*********file handling******

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int rollno;
    string name;
    string division;
    string address;
};

void addStudent(const Student& student) {
    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << student.rollno << " "
             << student.name << " "
             << student.division << " "
             << student.address << endl;
        file.close();
        cout << "Student added successfully." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }
}

void deleteStudent(int rollno) {
    ifstream inFile("students.txt");
    ofstream outFile("temp.txt");
    bool deleted = false;
    if (inFile.is_open() && outFile.is_open()) {
        Student student;
        while (inFile >> student.rollno >> student.name >> student.division >> student.address) {
            if (student.rollno != rollno) {
                outFile << student.rollno << " "
                        << student.name << " "
                        << student.division << " "
                        << student.address << endl;
            } else {
                deleted = true;
            }
        }
        inFile.close();
        outFile.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (deleted) {
            cout << "Student deleted successfully." << endl;
        } else {
            cout << "Student not found." << endl;
        }
    } else {
        cout << "Unable to open the file." << endl;
    }
}

void insertStudent(int position, const Student& student) {
    ifstream inFile("students.txt");
    ofstream outFile("temp.txt");
    if (inFile.is_open() && outFile.is_open()) {
        int count = 0;
        Student temp;
        while (inFile >> temp.rollno >> temp.name >> temp.division >> temp.address) {
            if (count == position) {
                outFile << student.rollno << " "
                        << student.name << " "
                        << student.division << " "
                        << student.address << endl;
            }
            outFile << temp.rollno << " "
                    << temp.name << " "
                    << temp.division << " "
                    << temp.address << endl;
            count++;
        }
        inFile.close();
        outFile.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        cout << "Student inserted successfully." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }
}

void searchStudent(int rollno) {
    ifstream file("students.txt");
    if (file.is_open()) {
        Student student;
        bool found = false;
        while (file >> student.rollno >> student.name >> student.division >> student.address) {
            if (student.rollno == rollno) {
                cout << "Roll No: " << student.rollno << endl;
                cout << "Name: " << student.name << endl;
                cout << "Division: " << student.division << endl;
                cout << "Address: " << student.address << endl;
                found = true;
                break;
            }
        }
        file.close();
        if (!found) {
            cout << "Student not found." << endl;
        }
    } else {
        cout << "Unable to open the file." << endl;
    }
}

int main() {
    int choice;
    Student student;
    int position, rollno;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Insert Student\n";
        cout << "4. Search Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll No: ";
                cin >> student.rollno;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, student.name);
                cout << "Enter Division: ";
                getline(cin, student.division);
                cout << "Enter Address: ";
                getline(cin, student.address);
                addStudent(student);
                break;
            case 2:
                cout << "Enter Roll No of the student to delete: ";
                cin >> rollno;
                deleteStudent(rollno);
                break;
            case 3:
                cout << "Enter Position: ";
                cin >> position;
                cin.ignore();
                cout << "Enter Roll No: ";
                cin >> student.rollno;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, student.name);
                cout << "Enter Division: ";
                getline(cin, student.division);
                cout << "Enter Address: ";
                getline(cin, student.address);
                insertStudent(position, student);
                break;
            case 4:
                cout << "Enter Roll No of the student to search: ";
                cin >> rollno;
                searchStudent(rollno);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

//*******topological*******
#include<bits/stdc++.h>
using namespace std;
vector<int>arr[1000];
int ind[1000];
int n,m;

int main(){
	
    cout<<"enter the no. of nodes : ";
    cin>>n;
    cout<<"enter the no. of edges : ";
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        ind[b]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    cout<<"Topological sort :"; 
    while(!q.empty()){
        int ver=q.front();
        q.pop();
        for(int i=0;i<arr[ver].size();i++){
            ind[arr[ver][i]]--;
            if(ind[arr[ver][i]]==0){
                q.push(arr[ver][i]);
            }
        }
        cout<<ver<<" ";
    }
    return 0;
}
