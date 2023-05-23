#include<bits/stdc++.h>
using namespace std;

map<char,string> a;

class node
{
public :
	char data;
	int freq;
	node* left;
	node* right;
	node(){
		data = ' ';
		freq = 0;
		left = NULL;
		right = NULL;
	}
	node(char d, int f)
	{
		data = d;
		freq = f;
	}
};

class compare{
public:
	bool operator()(node* first, node* second)
	{
		return ((first->freq) > (second->freq));
	}
};

class binaryTree
{
	node* root;
	public:
		binaryTree(){
			root = NULL;
		}
		binaryTree(node* n){
			root = n;
		} 	
		node* huffman(string);
		void inorderTraversal();
};


node* binaryTree :: huffman(string s)
{

	node* temp = NULL;
	map<char,int>m;
	for(int i=0;i<s.length();i++)
	{
		m[s[i]]++;
	}
	vector<node*>v;
	priority_queue<node* ,vector<node*> , compare>pq;
	for(auto i:m)
	{
		node* temp = new node(i.first, i.second);
		pq.push(temp);
	}
	int len = v.size();
	node* root = NULL;
	while(pq.size()!=1)	
	{
		node* n1 = NULL;
		node* n2 = NULL;
		n1 = pq.top();
		pq.pop();
		
		n2 = pq.top();
		pq.pop();
		
		node* temp = new node;
		temp->left = n1;
		temp->right = n2;
		temp->freq = n1->freq + n2->freq;
		pq.push(temp);
	}
	root = pq.top();
	return root;
}
string code="";
void binaryTree :: inorderTraversal()
{
	if(root == NULL) return;
	if(root->left == NULL  or root->right == NULL) {a[root->data] = code;return;}
	
	node* temp = root;
	root = root->left;
	code.push_back('0');
	
	inorderTraversal();
	
	code.erase(code.size()-1);
	root = temp->right;
	code.push_back('1');
	
	
	inorderTraversal();
	code.erase(code.size()-1);
	root = temp;
}

int main()
{
	string s;
    cout<<"Enter your desired string: ";
    cin>>s;
	map<char,int> alphabets;
	binaryTree bt;
	node* root = bt.huffman(s);	
	binaryTree bt2(root);
	bt2.inorderTraversal();
    
   
	for(int i=0;i<s.length();i++){
		alphabets[s[i]]++;
	}
	for(auto i:alphabets){
		cout<<"Letter : "<<i.first<<"\tCode : "<<a[i.first]<<endl;
	}
    cout<<endl;
    cout<<"Encoded string: ";
    for(auto i:alphabets){
        cout<<i.first;
    }
    cout<<endl;
    
	cout<<"Code of leaf nodes: ";
	for(int i=0;i<s.length();i++){
		cout<<a[s[i]];
	}
	cout<<endl;
}





