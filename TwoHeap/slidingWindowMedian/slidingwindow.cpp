#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
Sliding Window Median
Given an integer array, nums, and an integer,
 k, there is a sliding window of size k, 
which is moving from the very left to the very right of the array.
We can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Given this scenario, return the median of the each window. 


k = size of sliding window

*/
priority_queue<int,vector<int>,greater<int>> minheap;
priority_queue<int> maxheap;


void insert(int x)
{
    if(minheap.size() == maxheap.size() && minheap.size()==0)
    {     
        maxheap.push(x);
        return ;
    }

    if( x < maxheap.top())
    {
        maxheap.push(x);
    }
    else
    {
        minheap.push(x);
    }

    //rebalancing
    if(maxheap.size() >  minheap.size())
    {
        int x =  maxheap.top();
        maxheap.pop();
        minheap.push(x);
    }
    else if( minheap.size() > maxheap.size()+1)
    {
        int x = minheap.top();
        minheap.pop();
        maxheap.push(x);
    }
}


void remove(int x){
    if( maxheap.size() == minheap.size() && minheap.size() ==0)
       return;

    if( x <= maxheap.top())
    {
        priority_queue<int> temp;
        while( !maxheap.empty())
        {
             if( x != maxheap.top()){
                 temp.push(maxheap.top());
             }
           maxheap.pop();  
        }
        maxheap = temp;
    }
    else
    {
        priority_queue<int, vector<int>,greater<int>> temp;
        while( !minheap.empty())
        {
             if( x != minheap.top()){
                 temp.push(minheap.top());
             }
           minheap.pop();  
        }
        minheap = temp;
    }

}

double  median(int winsz)
{
    if(winsz == 1)
    {
        return maxheap.top();
    }

    if(maxheap.size() == minheap.size() && minheap.size() !=0)
    {
        return (maxheap.top() + minheap.top())/ 2;
    }
    else if( maxheap.size() < minheap.size())
            return minheap.top();

   return 0.0;
}

vector<double> MedianSlidingWindow(vector<int> nums, int k)
{
    // your code will replace this placeholder return statement
    vector<double> retval;
    int sz =  nums.size();
    
    for(int i=0; i < k; i++){
        insert( nums[i]);
    }
   
    
    int window = sz -k ;
    retval.push_back(median(k));
    for(int i=0 ;i<window; i++)
    {
        remove(nums[i]);
        insert(nums[k+i]);
        retval.push_back(median(k));
    }
    return retval;

}

int main()
{
    vector<int> arr = {1, 2};
    vector<double> ret;
    ret = MedianSlidingWindow(arr ,1);
    cout<<"[ ";
    for(auto x:  ret){
        cout<< x << ",";
    }
    cout<<" ]"<<endl;
    return 0;
}