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
 void create(BinaryTreeNode<T>* r){root=r;}
 void levelOrder();//�������
 void preOrder();//ǰ��
 void PreOrderWithRecursion(BinaryTreeNode<T> * root);  //�ǵݹ�ǰ��
 void inOrder(); //����
 void InOrderWithRecursion(BinaryTreeNode<T> * root);  //�ǵݹ�����
 void postOrder();//����
 void PostOrderWithRecursion(BinaryTreeNode<T> * root);  //�ǵݹ����
 void deleteBinaryTree();  
 void visit(BinaryTreeNode<T> *t); 
 void preincreatetree(BinaryTreeNode<T> *t,string pre,string in);  //ǰ������򴴽�������
 void inpostcreatetree(BinaryTreeNode<T> *t,string in,string post);  //��������򴴽�������
 void buildtree(){//����һ�������õĶ����� 
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



//���
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

//ǰ��
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

//����ǵݹ������ 
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


//����
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



//�ݹ�
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
 
template<class T>
void preinbinarytree(BinaryTreeNode<T> *&root,string pre,string in){  //��֪ǰ���������� ����������
	if(!pre.length()||pre.length()!=in.length()){
    	root=NULL;
    	return;
	}  
	T rootnode=pre[0]; 
	int r=in.find(rootnode);
	string l_in=in.substr(0,r);
	string r_in=in.substr(r+1); 
	int l_len=l_in.length();
    int r_len=r_in.length();
    string l_pre=pre.substr(1,l_len);
    string r_pre=pre.substr(1+l_len);
    root=new BinaryTreeNode<T>;
	if(root!=NULL){
		root->element=rootnode;
	    preinbinarytree(root->leftChild,l_pre,l_in);
	    preinbinarytree(root->rightChild,r_pre,r_in);
	}	 
}
int main(){
	BinaryTreeNode<char> *t;
	string s1="ABECDFGHIJ";
	string s2="EBCDAFHIGJ";
    preinbinarytree(t,s1,s2);
    BinaryTree<char> tree;
	tree.create(t);
	cout<<"ǰ�����:";
	tree.preOrder();
	cout<<endl<<"�������:";
	tree.inOrder();
	cout<<endl<<"�������:";
	tree.postOrder();
	return 0;
}