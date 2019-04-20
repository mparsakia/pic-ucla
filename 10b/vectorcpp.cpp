#include<iostream>
#include<list>
#include<iterator>
using namespace std;
class myiterator;
class myvector{
public:
    myvector(){
        size=0;
        capacity=3;
        addr=new int[capacity];
    }
    void push_back(int k){
        if (size==capacity){
            capacity=capacity*2;
            int* t=new int[capacity];
            for (int i=0;i<size;i++){
                t[i]=addr[i];
            }
            delete[] addr;
            addr=t;
        }
        addr[size]=k;
        size++;
    }
    int& at(int i){
        return addr[i];
    }
    int& operator[](int i){
        return addr[i];
    }
    myiterator begin();
    myiterator end();
private:
    int* addr;
    int size;
    int capacity;
};
class myiterator:public iterator<input_iterator_tag, int>{
public:
    myiterator(){
        addr=NULL;
        pos=0;
    }
    myiterator(int *addr,int pos):addr(addr),pos(pos){
    }
    bool operator!=(myiterator rhs){
        if ((addr==rhs.addr)&&(pos==rhs.pos)){
            return false;
        }
        else{
            return true;
        }
    }
    myiterator operator++(int){//post-increment
        myiterator tmp=*this;
        pos++;
        return tmp;
    }
    myiterator& operator++(){//pre-increment
        pos++;
        return *this;
    }
    int& operator*(){
        return *(addr+pos);
    }
private:
    int* addr;
    int pos;
};
myiterator myvector::begin(){
    return myiterator(addr, 0);
}
myiterator myvector::end()
{
    return myiterator(addr, size);
};
int main(){
    myvector a;
    for (int i=0;i<10;i++) a.push_back(i);
    //for (int i=0;i<10;i++) cout<<a.at(i)<<endl;
    //for (int i=0;i<10;i++) cout<<a[i]<<endl;
    for (int i=0;i<10;i++) {
        a[i]=10-i;
        //cout<<a[i]<<endl;
    }
//    for (myiterator p=a.begin();p!=a.end();p++){
//        *p=10-*p;
//        cout<<*p<<endl;
//    }
    list<int> b(a.begin(),a.end());
    for (list<int>::iterator p=b.begin();p!=b.end();p++){
        cout<<*p<<endl;
    }
    return 0;
}

