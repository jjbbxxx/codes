#include<bits/stdc++.h>
using namespace std;     
short int IsTrue[128];      
bool getTrue[128][7];        
int loc;                     
bool state[27];      
int mi(int n){
    int k=1;
    for(int i=0;i<n;i++){
        k*=2;
    }
    return k;
}
void set_getTrue(){
    for(int i=0;i<128;i++){
        for(int j=0;j<7;j++){
            getTrue[i][j]=0;
        }
    }
}
template<class T>
class Stack{
private:
    int top;
    int maxnum;
    T* st;
public:
    Stack(){
        maxnum=20;
        top=-1;
        st=new T[20];
    }
    ~Stack(){
        delete[] st;
    }
    void clean(){
        top=-1;
    }
    bool push(T n){
        top++;
        this->st[top]=n;
    }
    T get_top(){
        int k=st[top];
        top--;
        return k;
    }
    T read_top(){
        return st[this->top];
    }
    bool IsEmpty(){
        if(this->top==-1) return true;
        return false;
    }
    bool IsFull(){
        if(top+1==maxnum) return true;
        return false;
    }
};
class Calculator{
private:
    char InfixExp[50];
    char PostfixExp[50];
public:
    Calculator(char * exp);
    void getinf(); 
void ans(int nn);
    void getpost();
    void trans();
};
void Calculator::getinf(){
    cout<<InfixExp<<endl;
}
void Calculator::getpost(){
    cout<<PostfixExp<<endl;
}
Calculator::Calculator(char * exp){
    strcpy(this->InfixExp,exp);
    for(int i=0;i<50;i++){
        PostfixExp[i]='\0';
    }
}
void Calculator::trans(){
    Stack<char> save;
    int i=0,j=0;
    while(this->InfixExp[i]!='\0'){
        if(this->InfixExp[i]>=80&&this->InfixExp[i]<=90){
            while(this->InfixExp[i]>=80&&this->InfixExp[i]<=90){
                PostfixExp[j]=this->InfixExp[i];
                j++;
    i++;
            }
        }
        else{
            if(this->InfixExp[i]=='('||this->InfixExp[i]==')'){
                if(this->InfixExp[i]=='(') {
                    save.push(this->InfixExp[i]);
                }
                else if(this->InfixExp[i]==')'){
                    if(save.IsEmpty()){
                        cout<<"ERROR!"<<endl;
                        exit(0);
                    }
                    while(!save.IsEmpty()&&save.read_top()!='('){
                        PostfixExp[j++]=save.get_top();
                    }
                    if(save.read_top()=='(') save.get_top();
                }
            }else{
                if(save.IsEmpty()){
                    save.push(this->InfixExp[i]);
                }else{
                    if(this->InfixExp[i]=='!'){
                        char temp=save.read_top();
                        while(temp=='!'&&temp!='('&&!save.IsEmpty()){
                            PostfixExp[j++]=save.get_top();
                            temp=save.read_top();
                        }
                        save.push(this->InfixExp[i]);
                    }else
                    if(this->InfixExp[i]=='*'){
                        char temp=save.read_top();
                        while(temp!='+'&&temp!='('&&!save.IsEmpty()){
                            PostfixExp[j++]=save.get_top();
                            temp=save.read_top();
                        }
                        save.push(this->InfixExp[i]);
                    }else
                    if(this->InfixExp[i]=='+'){
                        char temp=save.read_top();
                        while((temp=='*'||temp=='!')&&!save.IsEmpty()){
                            PostfixExp[j]=save.get_top();
                            j++;
                            temp=save.read_top();
                        }
                        save.push(this->InfixExp[i]);
                    }else
                    if(this->InfixExp[i]=='@'){
                        char temp=save.read_top();
                        while((temp=='*'||temp=='!'||temp=='+')&&!save.IsEmpty()){
                            PostfixExp[j++]=save.get_top();
                            temp=save.read_top();
                        }
                        save.push(this->InfixExp[i]);
                    }else
                    if(this->InfixExp[i]=='$'){
                        char temp=save.read_top();
                        while((temp=='*'||temp=='!'||temp=='+'||temp=='@')&&!save.IsEmpty()){
                            PostfixExp[j++]=save.get_top();
                            temp=save.read_top();
                        }
                        save.push(this->InfixExp[i]);
                    }
                }
            }
            i++;
        }
    }
    while(!save.IsEmpty()){
        PostfixExp[j++]=save.get_top();
    }
    PostfixExp[j]='\0';
} 
void Calculator::ans(int nn){
    Stack<int> save_num;
    int i=0,j=0,n1=0,n2=0;
    for(i=0;i<nn;i++){
        cout<<' '<<getTrue[loc][i]<<' ';
    }
    i=0;
    while (this->PostfixExp[i]!='\0'){
        if(this->PostfixExp[i]>=80&&this->PostfixExp[i]<=90){
            int temp=0;
            temp=getTrue[loc][this->PostfixExp[i]-80];
            i++;
            save_num.push(temp);
        }else if(this->PostfixExp[i]=='!'){
            n1=save_num.get_top();
            n1=1-n1;
            save_num.push(n1);
            i++;
        }
        else if(this->PostfixExp[i]=='+'||this->PostfixExp[i]=='*'
                ||this->PostfixExp[i]=='@'||this->PostfixExp[i]=='$'){
            n2=save_num.get_top();
            n1=save_num.get_top();
            switch(this->PostfixExp[i]){
            case('+'):
                n1+=n2;
                save_num.push(n1);
                break;
            case('*'):
                n1*=n2;
                save_num.push(n1);
                break;
            case('@'):
                if(n1>0&&n2==0) n1=0;
                    else n1=1;
                save_num.push(n1);
                break;
            case('$'):
                if((n1+n2>0)&&(n1*n2==0)) n1=0;
                else n1=1;
                save_num.push(n1);
                break;
            }
            i++;
        }else{
            i++;
        }
    }
    if(save_num.read_top()>0) IsTrue[loc]=1;
     else IsTrue[loc]=0;
    cout<<"  "<<save_num.get_top()<<endl;
}
void printxiqu(int num,int m){
    int i,j;
    int temp=m;
    cout<<"主析取范式: ";
    for(;temp>0&&!IsTrue[temp];temp--)
    m=temp;
    for(i=0;i<m-1;i++){
        if(IsTrue[i]==1){
            cout<<'(';
            for(j=0;j<num-1;j++){
                if(getTrue[i][j]==0) cout<<"┐";
                cout<<(char)(j+80);
                cout<<"∧ ";
            }
            if(getTrue[i][num-1]==0) cout<<"┐";
                cout<<(char)(j+80);
            cout<<')';
            cout<<"∨ ";
        }
    }
    i=m-1;
    if(IsTrue[i]==1){
            cout<<'(';
            for(j=0;j<num-1;j++){
                if(getTrue[i][j]==0) cout<<"┐";
                cout<<(char)(j+80);
                cout<<"∧ ";
            }
            if(getTrue[i][num-1]==0) cout<<"┐";
                cout<<(char)(j+80);
            cout<<')';
    }
    cout<<endl;
}
    
int main(){
    cout<<"! * + @ $ 分别代表否定、合取、析取、单条件、双条件"<<endl;;
    for(int i=0;i<27;i++){
    state[i]=0;
}
    for(int i=0;i<128;i++){
    IsTrue[i]=-1;
}
    set_getTrue();
    int i,j,k,m=1;
    int num;//变元种数 
    cout<<"输入析取范式中所含变元的种数：";
    cin>>num;
    for(i=0;i<num;i++) m=m*2;
    char exp[50];
    cout<<"请输入析取范式，且变元从P开始:";
    cin>>exp; //命题公式
    Calculator cal(exp);
    cal.trans();
    for(i=0;i<m;i++){
        int temp=i,tt=0;
        for(j=0;j<num-1;j++){ 
            tt=mi(num-1-j); 
            state[j]=temp/tt;
            temp=temp%tt;
        }
        state[num-1]=temp;
        for(int k=0;k<num;k++){
            getTrue[i][k]=state[k];
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<num;j++){
            state[j]=getTrue[i][j];
        }
    }
    for(i=0;i<num;i++){
        cout<<' '<<(char)(i+80)<<' ';
    }
    cout<<' '<<exp;
    cout<<endl;
    for(i=0;i<m;i++){
        loc=i;
        cal.ans(num);
    }
    printxiqu(num,m);
    return 0;
}
