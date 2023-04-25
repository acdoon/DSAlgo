#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Interval
{
    int start;
    int end;
};

struct compmax
{
    bool operator()(const Interval& left, const Interval& right){
        return left.start < right.start;
    }
};
struct compmin{
bool operator()(const Interval& left, const Interval& right){
        return left.start > right.start;
    }
};


void printheap(priority_queue<Interval,vector<Interval>, compmax>& heap )
{
    while(!heap.empty())
    {
        Interval val =  heap.top();
        heap.pop();
        cout<< "[" << val.start << "," << val.end << "]" << " ";
    }
    cout<<endl;
}


vector<int>  findrightInterval(vector<Interval>&  listInterval ){
    priority_queue<Interval,vector<Interval>, compmax>  maxstartheap;
    priority_queue<Interval,vector<Interval>, compmin>  maxendheap;
    vector<int> retval(listInterval.size());
    for(int i =0; i < listInterval.size(); i++ ){
        
        Interval val = { listInterval[i].start, i};
        Interval val2 = {listInterval[i].end, i};
        maxstartheap.push(val);
        maxendheap.push(val2);
    }

   while( !maxendheap.empty())
   {
        Interval end = maxendheap.top();

        // pick top of maxstart heap
        // compare start with end
        //if start < end then at array[ put ret[end.end] = -1]
        //if start > end then pop start until start.start > end.start
        Interval start =  maxstartheap.top();
        if(start.start < end.start){
             retval[end.end] = -1;
        }
        else if( start.start > end.start)
        {
            vector<Interval> temp;
            while(start.start > end.start){
                temp.push_back(start);
                start =  maxstartheap.top();
                maxstartheap.pop();
            }
            int sz =  temp.size();
            retval[end.end] = temp[sz -1].end;
            for(Interval interval: temp){
                maxstartheap.push(interval);
            }
        }
        maxendheap.pop();
   }
    
    return retval;

}



int main()
{
  vector<Interval> ilist = {{ 2, 3 } , {1, 4 }, {5, 6} };
   vector<int> ret = findrightInterval(ilist);
   cout<< " Right Interval: " << endl;
   for( int x : ret)
   {
     cout<< x << " ,"  ;
   }
   cout<< endl;
   return 0;
}
