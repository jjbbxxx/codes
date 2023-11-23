#include<iostream>
using namespace std;
class maxHeap{
	private:
		int* arrHeap;
		int size; 
		int maxSize;
	public:
		maxHeap(int max);
		~maxHeap();
		void Clear();
		void BuildHeap();
		void swap(int x,int y);
		bool isEmpty();
		bool isleaf(int x);
		int leftchild(int x);
		int rightchild(int x);
		int parent(int x);
		bool Remove(int x, int &data);
		void Siftdown(int x);
		void Siftup(int x);
		bool Insert(int x);
		int RemoveMax();
		int getCurrSize(){return size;}
		void print();
};
	maxHeap::maxHeap(int max)
	{
		maxSize = max;
		arrHeap = new int [maxSize + 1];
		size = 0;	
	}
	maxHeap::~maxHeap()
	{
		if(arrHeap != NULL)
		{
			delete []arrHeap;
			size = 0;
		}
	}
	void maxHeap::swap(int x,int y)
	{
		int temp = arrHeap[x];
		arrHeap[x] = arrHeap[y];
		arrHeap[y] = temp;
	}
	void maxHeap::BuildHeap()
	{
		for(int i = size/2 - 1;i >= 0;i--)
		{
			Siftdown(i);
		}
	}
	bool maxHeap::isEmpty()
    {
        if(size == 0)
        {
            return true;
        }
        else
        return false;
    }
	bool maxHeap::isleaf(int x)
	{
		if(leftchild(x) == 0 && rightchild(x) == 0)
		return true;
		else 
		return false;
	}
	int maxHeap::leftchild(int x)
	{
		return x * 2 + 1;
	}
	int maxHeap::rightchild(int x)
	{
		return x * 2 + 2;
	}
	int maxHeap::parent(int x)
	{
		return (x-1) / 2;
	}
	bool maxHeap::Insert(int x)
	{
		if(size < maxSize)
		{
			arrHeap[size] = x;
			Siftup(size);
			size++; 
			return true;
		}
		else
		return false;
	 } 
	 int maxHeap::RemoveMax()
	 {
	 	if(!isEmpty())
	 	{
	 		int temp = arrHeap[0];
	 		swap(0,size - 1);
	 		size--;
	 		Siftdown(0);
	 		return temp;
		 }
		 else
		 cout<<"empty!"<<endl;
		 return 0; 
	  } 
	  bool maxHeap::Remove(int x,int &data)
	  {
	  	if(x >= 0 && x <= size)
	  	{
	  		data = arrHeap[x];
	  		swap(x,size - 1);
	  		size--;
	  		Siftup(x);
	  		Siftdown(x);
	  		return true;
		  }
		  else
		  return false;
	  }
	  void maxHeap::Siftup(int x)
	  {
	  		while(x && arrHeap[x] >= arrHeap[this->parent(x)])
	  		{
	  			this->swap(x,this->parent(x));
	  			x = this->parent(x);
			  }
	  }
void maxHeap::Siftdown(int x)
{
	int i = x;
	int j = 2 * i + 1;
	int temp = arrHeap[i];
	while (j < size){
		if((j <size - 1) && (arrHeap[j] < arrHeap[j+1]))j++;
		if(temp < arrHeap[j]){
			arrHeap[i] = arrHeap[j];
				i = j;
				j = 2 * j + 1; 
		} 
		else break;
	} 
	 arrHeap[i] = temp;
}

void maxHeap::print()
{
	for(int i = 0;i < size;i++)
    {
        cout<<arrHeap[i]<<" ";
    }
    cout<<endl;
}
int main()
{
	maxHeap h(15);
    h.Insert(3);
    h.Insert(5);
    h.Insert(8);
    h.Insert(2);
    h.Insert(4);
    h.Insert(9);
    h.Insert(6);
    h.Insert(10);
    h.Insert(1);
    h.Insert(7);
    h.print();
    h.Insert(8);
    h.print();
    h.RemoveMax();
    h.print();
    int temp;
    h.Remove(3,temp);
    cout<<temp<<endl;
    h.print();
    return 0;
}
