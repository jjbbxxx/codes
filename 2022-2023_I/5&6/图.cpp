#include<iostream>
#include<assert.h>
#include<queue>
#include<stack>
#include<iomanip>
using namespace std;

template <class T>
class LinkNode{
	public:
		T data;
		LinkNode<T>* link;
		LinkNode(){}
		LinkNode(const T&el,LinkNode<T>*ptr=0){
			data=el;
			link=ptr;
		}
};
template<class T>
class LinkList{
private:
	LinkNode<T> *head, *tail;
public:
	LinkList(){
		head=NULL;
		tail=NULL;
	}
	void insertTail(const T&item);
	void print()
	{
		LinkNode<T> *p;
		p=head;
		while(p)
		{
			cout<<p->data<<"   ";
			p=p->link;
		}
	 } 
};
template <class T>
void LinkList<T>::insertTail(const T&item){
	LinkNode<T>*p;
    p=new LinkNode<T>(item);
	if(head==NULL){
		head=p;
		tail=p;
	}
	else{
		tail->link=p;
    	tail=p;
	}
}

template<class T>
class List
{
	void Clear();
	bool IsEmpty();
	bool Append(const T value);
	bool Insert(const int p,const T value);
	bool Delete(const int p);
	bool GetValue(const int p,T& value);
	bool SetValue(const int p,const T value);
	bool GetPos(int &p,const T value);
};

template<class T>
class ArrayList : public List<T>
{
	private:
			T *arrayList;
			int maxSize;
			int curLen;
			int position;
	public:
		ArrayList()
		{
			maxSize=6;
			arrayList=new T[maxSize];
			curLen=0;
			position=0;
		}
		ArrayList(const int size)
		{
			if(size<1)
				{
					cout<<"Size must be greater than 0";
					throw -1; 
				} 
			maxSize=size;
			arrayList=new T[maxSize];
			curLen=0;
			position=0;
		}
		~ArrayList(){
			delete[] arrayList;
		}
		void clear(){
			delete[] arrayList;
			curLen=0;
			position=0;
			arrayList=new T[maxSize];
		}
		int Length();
		bool Append(const T value);
		bool Insert(const int p,const T value);
		bool Delete(const int p);
		bool GetValue(const int p,T& value);
		bool SetValue(const int p,const T value);
		bool GetPos(int &p,const T value);
		int Search(T x);
		T & operator[](int i)
		{
			return *(arrayList+i);
		}
		
}; 
template <class T>
int ArrayList<T>::Search(T x){
	for(int i=0;i<curLen; i++)
	    if(arrayList[i] == x)
	        return i;
	return -1;
}
template <class T>
bool ArrayList<T>::Insert(const int p,const T value){
	if(curLen >= maxSize){
		cout<<" The List is overflow "<<endl;
		return false;
	}
	if( p<0 || p>curLen)
	{
		cout<<"Insertion point is illegal"<<endl;
		return false; 
	}
	for(int i=curLen;i>p;i--){
		arrayList[i]=arrayList[i-1];
	}
	arrayList[p]=value;
	curLen++;
	return true;
} 
template <class T>
bool ArrayList<T>::Delete(const int p){
	if(curLen<=0){
		cout<<"No element to delete"<<endl;
		return false;
	}
	if(p<0||p>curLen){
		cout<<"Deleteion is illegal"<<endl;
		return false;
	}
	for(int i=p;i<curLen-1;i++){
		arrayList[i]=arrayList[i+1];
	
	}
		curLen--;
		return true;
}
template<class T>      //边定义 
class Edge{
public:
	int start; //边的始点
	int end;  //边的终点 
	T weight;  //边的权
	Edge() {}
	//构造边(start,end),权重为weight
	Edge(int start,int end,T weight):start(start),end(end),weight(weight){}	
	//重载运算符用于比较边
	bool operator==(const Edge<T>& other)const{
	    return start==other.start&&end==other.end&&weight==other.weight;
	}
	bool operator!=(const Edge<T>& other)const{return !(*this==other);}
	bool operator<(const Edge<T> other) const{
	    return this->weight <other.weight;
	} 
	bool operator>(const Edge<T>&other)const{
	    return this->weight>other.weight;
	}
	//构造一个空边用以判断是否有效 
	static Edge Empty(){return Edge(-1,-1,0);} 
};
ostream& operator <<(ostream& out,Edge<int> &X)
{
	out<<X.start<<"  "<<X.end<<"  "<<X.weight;
	return out;
}
enum VisitFlag{ UNVISITED,VISITED}; //用以标识图中结点是否访问过
enum EdgeType{ DIRECTED,UNDIRECTED}; //用以标识是否为有向图 
template<class T>
class Graph{                   //图类型 
protected:
	int vertexNum;
	int edgeNum; //图的边数目
	VisitFlag*marks; //标记某顶点是否被访问过
	EdgeType edgeType; 
public:
	static T MAX_VALUE;
	Graph(int vertexNum,EdgeType edgeType=DIRECTED){  //构造函数 
	    this->vertexNum=vertexNum;    //初始化图的顶点个数 
		this->edgeNum=0;           //初始化边的个数 
		this->marks=new VisitFlag[vertexNum];  //申请数组，Mark为数组指针 
		this->edgeType=edgeType;       //设置图是否为有向图 
		for(int i=0;i<vertexNum;i++){ //标志位初始化为未被访问过 
			marks[i]=UNVISITED; 
		} 
	} 
	~Graph(){                        //析构函数 
		delete[]marks;              //释放Mark数组 
	}
	virtual Edge<T> FirstEdge(int oneVertex)=0;
	virtual Edge<T> NextEdge(Edge<T> oneEdge)=0;
	int VertexCount() {return vertexNum;}  //返回图的顶点个数
	int EdgeCount() {return edgeNum;}      //返回图的边数 
	bool IsEdge(Edge<T> oneEdge){          //判断oneEdge是否为有效的边 
		return (oneEdge!=Edge<T>::Empty());
	} 
	int StartVertex(Edge<T> oneEdge){        //返回边oneEdge的始边 
		return oneEdge.start;
	} 
	int EndVertex(Edge<T> oneEdge){
		return oneEdge.end;
	} 
	T Weight(Edge<T> oneEdge){                  //返回oneEdge的终点 
 	    return oneEdge.weight; 
	} 
	virtual void SetEdge(int start,int end,T weight)=0;
	virtual void DeleteEdge(int start,int end)=0;
	typedef void(*VisitFunction)(Graph<T>&,int); 
	void DFS(int v,VisitFunction visit);  	 //从一个顶点v开始进行深度优先搜索 （递归） 
	void DFSTraverse(VisitFunction visit);   //对整个图进行深度优先搜索 （运用递归函数）    
	
	void DFSNoReverse(VisitFunction visit);// 深度优先搜索   (非递归)  
	
	void BFS(int v,VisitFunction visit);  //从一个顶点v开始的广度优先搜索算法 
	void BFSTraverse(VisitFunction visit); //图的广度优先搜索算法 
	
	void Dijkstra(int s,LinkList< Edge<T> >& dij);  //迪杰斯特拉算法 
	
	void Floyd(ArrayList< ArrayList<T> >&distance,ArrayList< ArrayList<int> >&path); //弗洛伊德算法 
};
template<class T>
T Graph<T>::MAX_VALUE = 100000;
template<class T>
class AdjGraph : public Graph<T>
{
private:
	T** matrix;
	int vertexNum;
public:
	AdjGraph(int vertexNum,EdgeType edgeType=DIRECTED):Graph<T>::Graph(vertexNum,edgeType)
	{
		this->vertexNum=vertexNum;
		this->matrix=(T**)new T * [vertexNum];
		for(int i=0;i<vertexNum;i++)
			matrix[i]=new T[vertexNum];
		for(int i=0;i<vertexNum;i++)
			for(int j=0;j<vertexNum;j++)
				matrix[i][j]=0;
	}
	~AdjGraph(){
		for(int i=0;i<this->vertexNum;i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	Edge<T> FirstEdge(int oneVertex){
		for(int i=0;i<this->vertexNum;i++)
			if(matrix[oneVertex][i]!=0)
			return Edge<T>(oneVertex,i,matrix[oneVertex][i]);
		    return Edge<T>::Empty();
	}
	Edge<T> NextEdge(Edge<T> oneEdge){
		for(int i=oneEdge.end+1;i<this->vertexNum;i++)
			if(matrix[oneEdge.start][i]!=0)
			return Edge<T>(oneEdge.start,i,matrix[oneEdge.start][i]);
		    return Edge<T>::Empty();
	}
	void SetEdge(int start,int end,T weight)
	{
		assert(start >= 0 && start < vertexNum);
		assert(end >= 0 && end < vertexNum);
		if(matrix[start][end]==0)
			this->edgeNum++;
		matrix[start][end]=weight;
		if(this->edgeType==UNDIRECTED)
			matrix[end][start]=weight;
		}
		void DeleteEdge(int start,int end)
		{
			assert(start >= 0 && start < vertexNum);
			assert(end >= 0 && end < vertexNum);
			if(matrix[start][end]!=0)
				this->edgeNum--;
			matrix[start][end]=0;
			if(this->edgeType==UNDIRECTED)
				matrix[end][start]=0;
		}
};
template<class T>
void Graph<T>::DFS(int v,VisitFunction visit){                              //从顶点v开始进行深度优先搜索 （递归）    
	visit(*this,v);       //访问该顶点 
	marks[v]=VISITED;     //标记该顶点已访问 
	for(Edge<T> e=FirstEdge(v); IsEdge(e);e=NextEdge(e)){
		if(marks[e.end]==UNVISITED)    //访问v邻接到的未被访问过的顶点，并递归地进行深度优先搜索 
		DFS(e.end,visit);
	}	
}
template<class T>
void Graph<T>::DFSTraverse(VisitFunction visit){
	for(int i=0;i<vertexNum;i++)
	marks[i]=UNVISITED;
	for(int i=0;i<vertexNum;i++)
	{
		if(marks[i]==UNVISITED)
		DFS(i,visit);
	}
}
template<class T>
void Graph<T>::DFSNoReverse(VisitFunction visit){
	stack<int> s1;
	for(int i=0;i<vertexNum;i++)
		marks[i]=UNVISITED;
	for(int i=0;i<vertexNum;i++)
	{
		if(marks[i]==UNVISITED)
		{
			s1.push(i);
			while(!s1.empty())
			{
				int v;
				v=s1.top();
				s1.pop();
				if(marks[v]==UNVISITED)
				visit(*this,v);
				marks[v]=VISITED;
				for(Edge<T>e=FirstEdge(v);IsEdge(e);e=NextEdge(e))
				{
					if(marks[e.end]==UNVISITED)
					s1.push(e.end);
				}
			}
		}
	}
}
template <class T>
void Graph<T>::BFS(int v,VisitFunction visit){       //从一个顶点v开始的广度优先搜索算法 
    queue<int> q1;
	q1.push(v);
	while(!q1.empty())
	{
		int u;
		u=q1.front();
		q1.pop();
		if(marks[u]==UNVISITED)
		    visit(*this,u);
		marks[u]=VISITED;
		for(Edge<T> e=FirstEdge(u); IsEdge(e); e=NextEdge(e)){
			if(marks[e.end] == UNVISITED)
			    q1.push(e.end);
		}
	 } 
}
template <class T>
void Graph<T>::BFSTraverse(VisitFunction visit){  //图的广度优先搜索算法 
	for(int v=0; v<vertexNum ;v++)
		marks[v]=UNVISITED;
	for(int v=0; v<vertexNum ;v++)  //检查图中是否有未访问的顶点，如果有则从该顶点开始广度优先搜索
	    if(marks[v]==UNVISITED) BFS(v,visit);
}
template <class T>
void Graph<T>::Floyd(ArrayList<ArrayList<T> >&distance,ArrayList<ArrayList<int> >&path){ //弗洛伊德算法 
	for(int i=0;i<vertexNum;i++){
		for(int j=0;j<vertexNum;j++){
			distance[i][j]=(i==j)?0:MAX_VALUE;
			path[i][j]=i;
		}
		for(Edge<T> e=FirstEdge(i);IsEdge(e);e=NextEdge(e))
		    distance[i][e.end]=e.weight;
	}
	for(int v=0;v<vertexNum;v++)
	    for(int i=0;i<vertexNum;i++) 
	        for(int j=0;j<vertexNum;j++) 
	            if(distance[i][j]>distance[i][v]+distance[v][j]){
	            	distance[i][j] = distance[i][v]+distance[v][j];
	            	path[i][j]=path[v][j];
				}
		cout<<"distance:"<<endl;
		for(int i=0;i<vertexNum;i++){
			for(int j=0;j<vertexNum;j++){
				cout<<left<<setw(6)<<distance[i][j]<<"  ";
			}
			cout<<endl;
		}
		cout<<"path:"<<endl;
		for(int i=0;i<vertexNum;i++){
			for(int j=0;j<vertexNum;j++){
				cout<<left<<setw(6)<<path[i][j]<<"  ";
			}
			cout<<endl;
		}
}
template<class T>
void Graph<T>::Dijkstra(int s, LinkList<Edge<T> >& dij){   //迪杰斯特拉算法 
	ArrayList<T> distances (vertexNum);
	ArrayList<int> path (vertexNum);
	for(int i=0;i< vertexNum; i++){
		marks[i]= UNVISITED;
		distances[i] = MAX_VALUE;
		path[i]= s;
	}
	distances[s]=0;
	for(int j=0;j<vertexNum; j++){
		T minDistance = MAX_VALUE;
		int minVertex= -1;
		for(int i=0;i< vertexNum;i++)
			if(marks[i] == UNVISITED && minDistance > distances[i]){
				minDistance = distances[i];
				minVertex=i;
			}
		if(minVertex>=0){
			dij.insertTail(Edge<T>(path[minVertex], minVertex, minDistance));
			marks[minVertex] = VISITED;
			for (Edge<T> e = FirstEdge (minVertex); IsEdge(e);e = NextEdge(e))
				if(marks[e.end]== UNVISITED &&distances[e.end] > (distances[minVertex] + e.weight)){
				distances[e.end] = distances[minVertex] + e.weight;
				path[e.end] = minVertex;
			}
		}
	}
			dij.print();
}
template<class T>
void visit(Graph<T>&a, int i)
{
	cout<<i<<"  ";
}
int main()
{                                                                    //              8   5
	AdjGraph<int> graph(6);                                                 //   (4)--(0)-(1)  
	graph.SetEdge(0,1,5);                                                   //50 | \32 9\ |10
	graph.SetEdge(0,4,8);                                                   // (5)-(3)--(2)
	graph.SetEdge(0,2,9);                                                      //12   11
	graph.SetEdge(1,2,10);
	graph.SetEdge(2,3,11);
	graph.SetEdge(3,5,12);
	graph.SetEdge(4,3,32);
	graph.SetEdge(4,5,50);
	cout<<"DFSNoReverse:";
	graph.DFSNoReverse(visit);        //深度非递归 
	cout<<endl;
	cout<<"DFSTraverse:";
	graph.DFSTraverse(visit);         //深度递归 
	cout<<endl;
	cout<<"BFS:";
	graph.BFSTraverse(visit);  //广度 
	cout<<endl;
	cout<<"Floyd:"<<endl;
	ArrayList<ArrayList<int> > distance;
	ArrayList<ArrayList<int> > path;
	graph.Floyd(distance,path);   //弗洛伊德算法
	cout<<endl;
	cout<<"Dijkstra:";      //迪杰斯特拉算法 
	LinkList<Edge<int> > dij;
	graph.Dijkstra(0,dij);
	cout<<endl;
	return 0;
}
 

