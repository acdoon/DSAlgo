#include<iostream>
#include <queue>
#include<vector>
using namespace std;

//  [4 , 6 ,8 ,9, 10, 12, 11];
// insert in max heap  when size of max and min is 0
// if x is > maxheap.top then insert in min heap
// check if  maxheap size  - min heap size > 1
//  if maxheapsize > minheap size
//    remove maxheap top and insert it in min heap
// else if minheap size > maxheapsize+1
// remove minheap top and insert it in maxheap
//  if minheap and maxheap size is equel then:
    //  return minheap + maxheap top  /2 
// else return minheap top element
// 4    
priority_queue<int,vector<int>,greater<int>> minheap;
priority_queue<int> maxheap;

void insert( int x) {
    if(minheap.size() == maxheap.size() && minheap.size() == 0)
    {
           maxheap.push(x);
            return;
    }

    if(x > maxheap.top())
    {
        minheap.push(x);
    }
    else{
        maxheap.push(x);
    }

     if(minheap.size() > maxheap.size()+1)
     {
        int y =  minheap.top();
        minheap.pop();
        maxheap.push(y);
     }
     else if( maxheap.size() > minheap.size())
     {
        int y =  maxheap.top();
        maxheap.pop();
        minheap.push(y);
     }
    
}

void printminheap()
{
    cout<< "MinHeap:" << "[ ";
    while( ! minheap.empty()){
        cout<< minheap.top() << ","; 
        minheap.pop();
    }
    cout<< "]" <<endl;
}
void printmaxheap()
{
    cout<< "Maxheap:" << "[ ";
    while( ! maxheap.empty()){
        cout<< maxheap.top() << ","; 
        maxheap.pop();
    }
    cout<< "]" <<endl;
}
float findmedian(vector<int>& arr)
{
    int sz =  arr.size();
    for(int i=0; i< sz; i++)
    {
       insert(arr[i]); 
    }

    if( maxheap.size() == minheap.size())
    {
         return  (minheap.top() + maxheap.top())/2;
    }
    else
    {
        return minheap.top();
    }

}
int main()
{
  vector<int>  list = { 12, 14, 36, 54};
  int median  =  findmedian(list); 
  cout<< "Median: " <<median <<endl;

  printminheap();
  printmaxheap();

}







    