#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <class T> 
class BinaryTreeNode{  
public: 
	T element;
 	BinaryTreeNode<T> * leftChild;
	BinaryTreeNode<T> * rightChild; 
	BinaryTreeNode(){
		element = 0;
		leftChild = NULL;
		rightChild = NULL;
	};

	BinaryTreeNode(const T& ele):element(ele),leftChild(NULL),rightChild(NULL){};
	BinaryTreeNode(const T& ele, BinaryTreeNode<T> * l, BinaryTreeNode<T> * r){
		this->element = ele;
		leftChild = l;
		rightChild = r;
	}; 

	BinaryTreeNode<T> * getLeftChild() const{return leftChild;}; 
	BinaryTreeNode<T> * getRightChild() const{return rightChild;}; 
	void setLeftChild(BinaryTreeNode<T> * l){leftChild=l;}; 
	void setRightChild(BinaryTreeNode<T> * r){rightChild=r;}; 
	void createLeftChild(){leftChild = new BinaryTreeNode;}; 
	void createRightChild(){rightChild = new BinaryTreeNode;};
	T getValue() const{return element;};
	void setValue(const T& val){element=val;};
	bool isLeaf() const; 
	void show(){cout<<element<<" ";}
};

template <class T> 
class BinaryTree{ 
friend class BinaryTreeNode<T>;
private: 
 BinaryTreeNode<T> * root;
public: 
 BinaryTree(){
 	root = new BinaryTreeNode<T>(0);
 }
 ~BinaryTree(){
 	delete [] root;
 } 
 bool isEmpty() const{
 	if(root==NULL){
 		return 1;
	 }
	 return 0;
 }
 BinaryTreeNode<T> * getRoot() const{
 	return root;
} 
 void levelOrder();//广度优先
 void preOrder();//前序
 void PreOrderWithRecursion(BinaryTreeNode<T> * root);  //非递归前序
 void inOrder(); //中序
 void InOrderWithRecursion(BinaryTreeNode<T> * root);  //非递归中序
 void postOrder();//后序
 void PostOrderWithRecursion(BinaryTreeNode<T> * root);  //非递归后序
 void deleteBinaryTree();  
 void visit(BinaryTreeNode<T> *t); 
 void preincreatetree(BinaryTreeNode<T> *t,string pre,string in);  //前序和中序创建二叉树
 void inpostcreatetree(BinaryTreeNode<T> *t,string in,string post);  //后序和中序创建二叉树
 void buildtree(){//建立一个测试用的二叉树 
 	root->leftChild =new BinaryTreeNode<T>(1);
 	root->rightChild =new BinaryTreeNode<T>(2);
 	root->leftChild->leftChild =new BinaryTreeNode<T>(3);
 	root->leftChild->rightChild=new BinaryTreeNode<T>(4);
 	root->rightChild->rightChild=new BinaryTreeNode<T>(5);
	root->leftChild->rightChild->leftChild = new BinaryTreeNode<T>(6);
 	root->leftChild->rightChild->rightChild = new BinaryTreeNode<T>(7);
	root->rightChild->rightChild->leftChild = new BinaryTreeNode<T>(8);
	root->rightChild->rightChild->rightChild = new BinaryTreeNode<T>(9);
}
BinaryTreeNode<T>* getroot(){
	return root;
}
};



//广度
template <class T>
void BinaryTree<T>::levelOrder(){
	BinaryTreeNode<T>*pointer;
	pointer = root;
	using std::queue;
	queue<BinaryTreeNode<T>*> q;
	q.push(root);
	while(!q.empty()){
		pointer = q.front();
		pointer->show();
		q.pop();
		if(pointer!=NULL){
			if(pointer->getLeftChild()!=NULL){
				q.push(pointer->getLeftChild());
			}
			if(pointer->getRightChild()!=NULL){
				q.push(pointer->getRightChild());	
			}
		}
	}
}

//前序
template <class T>
void BinaryTree<T>::preOrder(){
	BinaryTreeNode<T>*pointer;
	pointer = root;
	using std::stack;
	stack<BinaryTreeNode<T>*> s;
	s.push(root);
	while(!s.empty()){
		pointer = s.top();
		s.pop();
		pointer->show();
		if(pointer!=NULL){
			if(pointer->getRightChild()!=NULL){
				s.push(pointer->getRightChild());
			}
			if(pointer->getLeftChild()!=NULL){
				s.push(pointer->getLeftChild());	
			}
		}
	}
}

//中序非递归遍历： 
template <class T>
void BinaryTree<T>::inOrder(){
	BinaryTreeNode<T>*pointer;
	pointer = root;
	using std::stack;
	stack<BinaryTreeNode<T>*> s;
	while(!s.empty()||pointer){
	    if (pointer) {
        	s.push(pointer);
		   	pointer = pointer->leftChild;
        }else { 
		   pointer =s.top();
		   s.pop();
		   pointer->show();	
		   pointer = pointer->rightChild;
		}
	}
}


//后序
template <class T> 
void BinaryTree<T>::postOrder(){
	using std::stack;
	stack<BinaryTreeNode<T>*>  s;
	BinaryTreeNode<T> *pointer=root,*pre =root;
	while(pointer!=0){
		for(;pointer->leftChild!=0;pointer=pointer->leftChild)
			s.push(pointer);
		while(pointer->rightChild==0 || pointer->rightChild==pre){
			pointer->show();
			pre =pointer;
			if(s.empty())return;
			pointer=s.top(); 
			s.pop();
	    }
		s.push(pointer);
		pointer = pointer->rightChild;
    } 
}



//递归
template<class T>
void BinaryTree<T>::PreOrderWithRecursion(BinaryTreeNode<T> * root){  	  
     if (root != NULL) {
		root->show();
		PreOrderWithRecursion(root->leftChild);
		PreOrderWithRecursion(root->rightChild);
      }
}
 

template<class T>
void BinaryTree<T>::InOrderWithRecursion(BinaryTreeNode<T> * root){
      if (root != NULL) {
			InOrderWithRecursion(root->leftChild);
            root->show();
			InOrderWithRecursion(root->rightChild); 
       }
}


template<class T>
void BinaryTree<T>::PostOrderWithRecursion(BinaryTreeNode<T>*root){ 	  
	if (root != NULL) {
	      PostOrderWithRecursion(root->leftChild);	
	      PostOrderWithRecursion(root->rightChild);	
	      root->show(); 
    }
}
 
int main(){
	BinaryTree<int>t;
	t.buildtree();
	cout<<"广度：";
	t.levelOrder();
	cout<<endl;
	cout<<"前序：";
	t.PreOrderWithRecursion(t.getRoot());
	cout<<endl;
	cout<<"中序：";
	t.InOrderWithRecursion(t.getroot());
	cout<<endl;
	cout<<"后序：";
	t.PostOrderWithRecursion(t.getroot());
	cout<<endl;
	cout<<"前序非递归：";
	t.preOrder();
	cout<<endl;
	cout<<"中序非递归：";
	t.inOrder();
	cout<<endl;
	cout<<"后序非递归：";
	t.postOrder();
}
