//******dijshtra*********
#include <iostream>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 

    bool sptSet[V]; 
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
     
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

// driver's code
int main()
{

    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    // Function call
    dijkstra(graph, 0);

    return 0;
}


//******prims*********

#include <bits/stdc++.h>
using namespace std;

class MST
{
    int V;
    int** graph;
    vector<int> distance;
    vector<bool> visited;
    public:
  
    MST(int V)
    {
        this->V=V;
        initialize();
    }
    void initialize();
    void prims();
    void kruskal();
    void create_graph();
    void printgraph();
};

void MST :: kruskal()
{
    vector<pair<int,int>> vec;
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            vec.push_back(make_pair(i,j));
        }
    }

}

void MST :: initialize()
{
    graph = new int*[V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
    }
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            graph[i][j] = 0;
        }
    }
}

void MST :: printgraph()
{
    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void MST :: create_graph()
{
    cout<<"Enter edges = ";
    int n;cin>>n;
    cout<<"Enter vertices = ";
    int v;cin>>v;
    V=v;
    for(int i=0;i<n;i++)
    {
       int x,y,z;
       cin>>x>>y>>z;
       graph[x][y]=z;
       graph[y][x]=z;
    }
}


int minimum_v(vector<int> &distance, vector<bool> &visited)
{
    int minimum = INT_MAX;
    int vertex;
    int V = distance.size();
    for (int i = 0; i < V; ++i)
    {
        if (visited[i] == false && distance[i] < minimum)
        {
            vertex = i;
            minimum = distance[i];
        }
    }
    return vertex;
}

void MST :: prims()
{
    int parent[V];
    vector<int> distance(V, INT_MAX);
    vector<bool> visited(V, false);
    parent[0] = -1;
    distance[0] = 0;
    for (int i = 0; i < V - 1; ++i)
    {

        int U = minimum_v(distance, visited);
        visited[U] = true;
        for (int j = 0; j < V; ++j)
        {
            if (graph[U][j] && visited[j] == false && graph[U][j] < distance[j])
            {
                distance[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }

    for (int i = 1; i < V; ++i)
        cout << parent[i] << "-->" << i << "  weight = " << graph[i][parent[i]] << endl;
}

int main()
{
    MST mt(5);
    // mt.printgraph();
    // mt.create_graph();
    // mt.printgraph();
    // mt.prims();

}

//*******heap********

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void findMinMaxMarks(const std::vector<int>& marks) {
    std::cout << "Marks: ";
    for (int mark : marks) {
        std::cout << mark << " ";
    }
    std::cout << std::endl;

    // Create a min heap and max heap
    std::vector<int> minHeap(marks.begin(), marks.end());
    std::vector<int> maxHeap(marks.begin(), marks.end());

    // Convert min heap to max heap
    std::make_heap(maxHeap.begin(), maxHeap.end());

    // Find the minimum mark
    int minMark = minHeap.front();

    // Find the maximum mark
    int maxMark = maxHeap.front();

    std::cout << "Minimum mark: " << minMark << std::endl;
    std::cout << "Maximum mark: " << maxMark << std::endl;
}

// Function to perform heapify operation
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to perform heapsort
void heapSort(std::vector<int>& marks) {
    int n = marks.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(marks, n, i);
    }

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        std::swap(marks[0], marks[i]);

        // Heapify the reduced heap
        heapify(marks, i, 0);
    }
}

int main() {
    std::vector<int> marks = {90, 75, 80, 95, 85};

    findMinMaxMarks(marks);

    std::cout << "Marks in descending order: ";
    heapSort(marks);
    for (int mark : marks) {
        std::cout << mark << " ";
    }
    std::cout << std::endl;

    return 0;
}


//*******file*******

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

struct Student {
    int rollNo;
    std::string name;
    std::string division;
    std::string address;
};

// Function to display a student's information
void displayStudent(const Student& student) {
    std::cout << "Roll No: " << student.rollNo << std::endl;
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Division: " << student.division << std::endl;
    std::cout << "Address: " << student.address << std::endl;
    std::cout << std::endl;
}

// Function to add student information to the file
void addStudent(std::fstream& file) {
    Student student;

    std::cout << "Enter Roll No: ";
    std::cin >> student.rollNo;
    std::cin.ignore();

    std::cout << "Enter Name: ";
    std::getline(std::cin, student.name);

    std::cout << "Enter Division: ";
    std::getline(std::cin, student.division);

    std::cout << "Enter Address: ";
    std::getline(std::cin, student.address);

    // Move the file pointer to the end and append the student record
    file.seekp(0, std::ios::end);
    file.write(reinterpret_cast<char*>(&student), sizeof(Student));
    std::cout << "Student information added successfully!" << std::endl;
}

// Function to delete student information from the file
void deleteStudent(std::fstream& file) {
    int rollNo;
    std::cout << "Enter the Roll No of the student to delete: ";
    std::cin >> rollNo;

    // Move the file pointer to the beginning
    file.seekg(0, std::ios::beg);

    // Find the student record and delete it
    bool found = false;
    Student student;
    while (!file.eof()) {
        file.read(reinterpret_cast<char*>(&student), sizeof(Student));
        if (file.eof()) break;

        if (student.rollNo == rollNo) {
            found = true;
            break;
        }
    }

    if (found) {
        // Move the file pointer back to the beginning of the record
        file.seekp(-static_cast<int>(sizeof(Student)), std::ios::cur);
        // Overwrite the record with the last record in the file
        Student lastStudent;
        file.seekg(-static_cast<int>(sizeof(Student)), std::ios::end);
        file.read(reinterpret_cast<char*>(&lastStudent), sizeof(Student));
        file.write(reinterpret_cast<char*>(&lastStudent), sizeof(Student));
        // Truncate the file by removing the last record
        file.seekp(-static_cast<int>(sizeof(Student)), std::ios::end);
        file.truncate();
        std::cout << "Student information deleted successfully!" << std::endl;
    } else {
        std::cout << "Student with Roll No " << rollNo << " not found!" << std::endl;
    }
}

// Function to insert student information at a specific position in the file
void insertStudent(std::fstream& file) {
    int position;
    std::cout << "Enter the position to insert the student information: ";
    std::cin >> position;

    // Move the file pointer to the end
    file.seekg(0, std::ios::end);

    // Count the number of student records in the file
    int numRecords = file.tellg() / sizeof(Student);

    if (position < 1 || position > numRecords + 1) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    Student student;

    std::cout << "Enter Roll No: ";
    std::cin >> student.rollNo;
    std::cin.ignore();

    std::cout << "Enter Name: ";
    std::getline(std::cin, student.name);

    std::cout << "Enter Division: ";
    std::getline(std::cin, student.division);

    std::cout << "Enter Address: ";
    std::getline(std::cin, student.address);

    // Shift the records from the insertion position to the end by one position
    for (int i = numRecords; i >= position; i--) {
        file.seekg((i - 1) * sizeof(Student), std::ios::beg);
        file.read(reinterpret_cast<char*>(&student), sizeof(Student));
        file.seekp(i * sizeof(Student), std::ios::beg);
        file.write(reinterpret_cast<char*>(&student), sizeof(Student));
    }

    // Move the file pointer to the insertion position and write the new student record
    file.seekp((position - 1) * sizeof(Student), std::ios::beg);
    file.write(reinterpret_cast<char*>(&student), sizeof(Student));

    std::cout << "Student information inserted successfully!" << std::endl;
}

// Function to search for a student by Roll No
void searchStudent(const std::fstream& file) {
    int rollNo;
    std::cout << "Enter the Roll No of the student to search: ";
    std::cin >> rollNo;

    // Move the file pointer to the beginning
    file.seekg(0, std::ios::beg);

    // Search for the student record
    bool found = false;
    Student student;
    while (!file.eof()) {
        file.read(reinterpret_cast<char*>(&student), sizeof(Student));
        if (file.eof()) break;

        if (student.rollNo == rollNo) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "Student information found!" << std::endl;
        displayStudent(student);
    } else {
        std::cout << "Student with Roll No " << rollNo << " not found!" << std::endl;
    }
}

// Function to display all student information in the file
void displayAllStudents(const std::fstream& file) {
    // Move the file pointer to the beginning
    file.seekg(0, std::ios::beg);

    Student student;
    while (!file.eof()) {
        file.read(reinterpret_cast<char*>(&student), sizeof(Student));
        if (file.eof()) break;

        displayStudent(student);
    }
}

int main() {
    std::fstream file("student_data.bin", std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);

    if (!file) {
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }

    int choice;
    do {
        std::cout << "========== Student Information Management ==========" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Delete Student" << std::endl;
        std::cout << "3. Insert Student" << std::endl;
        std::cout << "4. Search Student" << std::endl;
        std::cout << "5. Display All Students" << std::endl;
        std::cout << "6. Exit" << std::
    }

//********obst******

#include <iostream>
#include <vector>
#include <limits>

// Structure to represent a node in the binary search tree
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Helper function to calculate the sum of access probabilities between keys ki and kj
double sumProbabilities(const std::vector<double>& probabilities, int i, int j) {
    double sum = 0.0;
    for (int k = i; k <= j; k++) {
        sum += probabilities[k];
    }
    return sum;
}

// Function to build the optimal binary search tree using the given access probabilities
Node* buildOptimalBST(const std::vector<int>& keys, const std::vector<double>& probabilities) {
    int n = keys.size();
    // Create matrices for cost and root values
    std::vector<std::vector<double>> cost(n + 2, std::vector<double>(n + 1, 0.0));
    std::vector<std::vector<int>> root(n + 1, std::vector<int>(n + 1, 0));

    // Calculate the initial costs for the dummy keys
    for (int i = 1; i <= n + 1; i++) {
        cost[i][i - 1] = probabilities[i - 1];
    }

    // Perform dynamic programming calculation
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            cost[i][j] = std::numeric_limits<double>::infinity();

            for (int r = i; r <= j; r++) {
                double currentCost = cost[i][r - 1] + cost[r + 1][j] + sumProbabilities(probabilities, i - 1, j);
                if (currentCost < cost[i][j]) {
                    cost[i][j] = currentCost;
                    root[i][j] = r;
                }
            }
        }
    }

    // Build the optimal BST recursively
    std::function<Node*(int, int)> buildSubtree = [&](int i, int j) -> Node* {
        if (i > j) {
            return nullptr;
        }

        int rootIndex = root[i][j];
        Node* rootNode = new Node(keys[rootIndex - 1]);

        rootNode->left = buildSubtree(i, rootIndex - 1);
        rootNode->right = buildSubtree(rootIndex + 1, j);

        return rootNode;
    };

    // Return the root of the optimal BST
    return buildSubtree(1, n);
}

// Function to perform in-order traversal of the binary search tree
void inorderTraversal(const Node* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    std::vector<int> keys = {10, 20, 30, 40, 50};
    std::vector<double> probabilities = {0.15, 0.10, 0.05, 0.10, 0.20};

    Node* root = buildOptimalBST(keys, probabilities);

    std::cout << "In-order traversal of the optimal BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // TODO: Don't
