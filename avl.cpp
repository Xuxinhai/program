#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<iostream>
#include<map>
#include<iomanip>
#include<fstream>
#include<set>
#include<ctime>
#include<string>
#include<stdlib.h>
#include<sstream>

using namespace std;

typedef long long ll;
const int N = 1e3 + 100;
const int M = 1e5 + 100;
ll mod = 1e9+7;
const int INF = 2e9;
const double PI = 3.14159265358979323;

struct node {
	int data;
	int height;
	node *l,*r;
	node(int data=0,int height=0,node *l=NULL,node *r=NULL){
		this->data = data;
		this->height = height;
		this->l = l;
		this->r = r;
	}
};

int geth(node *root){
	if(!root) return 0;
	return root->height;
}

void updateh(node *root){
	root->height = max(geth(root->l),geth(root->r))+1;
}

int getfac(node *root){
	return geth(root->l)-geth(root->r);
}

void L(node* &root){
	node *temp = root->r;
	root->r = temp->l;
	temp->l = root;
	updateh(root);
	updateh(temp);
	root = temp;
}

void R(node* &root){
	node *temp = root->l;
	root->l = temp->r;
	temp->r = root;
	updateh(root);
	updateh(temp);
	root=temp;
	
}

void insert(node *&root,int x){
	if(!root){
		root = new node(x,1);
		return;
	}
	if(x < root->data){
		insert(root->l,x);
		updateh(root);
		if(getfac(root) == 2){
			if(getfac(root->l) == 1){
				R(root);
			}
			else if(getfac(root->l) == -1){
				L(root->l);
				R(root);
			}
		}
	}
	else{
		insert(root->r,x);
		updateh(root);
		if(getfac(root) == -2){
			if(getfac(root->r) == -1){
				L(root);
			}
			else if(getfac(root->r) == 1){
				R(root->r);
				L(root);
			}
		}
	}
} 

int main() {
	int n,x;
	cin >> n;
	node *root = NULL;
	for(int i = 0;i < n;i++){
		cin >> x;
		insert(root,x);
	}
	
	cout << root->data << endl;
	return 0;
}


/*

*/


