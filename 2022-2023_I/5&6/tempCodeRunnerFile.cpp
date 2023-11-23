template<class T>
void siftdown(T data[],int i,int n){
	int l=2*n+1,r=2*i+2,min=i;
	if(l<n&&data[min]<data[l])
	    min=l;
	if(r<n&&data[min]<data[r])
	    min=r;
	if(min!=i){
		T t=data[min];
		data[min]=data[i];
		data[i]=t;
		siftdown(data,min,n);
	}
} 
template<class T>
void buildheap(T data[],int n){
	int p=n/2-1;
	for(int i=p;i>=0;i--){
		siftdown(data,i,n);
	}
}              //最大堆 
template<class T>
void heapsort(T data[],int n){
	buildheap(data,n);int m=0;
	for(int i=n-1;i>0;i--){
		T t=data[0];
		data[0]=data[i];
		data[i]=t;
		siftdown(data,0,i);
	}
	cout<<"第"<<++m<<"趟排序之后："; 
	print(data,n);
}