#include<iostream>
#include<queue>
using namespace std;
/*Capital  1 2 2 3
 Profit   2 4 6 8
 c=1 and k=2
 find maximum profit with minimum capital available.

 Minimize capital and maximize profit

 MinHeap for Capital:   cap 1 , K1: 1 profit 2. total cap =3, rem 1
                        cap 3 , K2: pop capital until top < cap and return max 
                        of popped element.



 step1:  loop K times
 step2:  find capital <= ic and with max profit. 
 step3 :  pop capital from heap.
 step4 :  add capital.cap to Ic
 step5 :  repeat step 2. 
*/
struct capital{
    int cap;
    int index;
     capital(int cap, int index): cap(cap), index(index){}
};
struct compmin{
bool operator()(const capital& left, const capital& right){
        return left.cap > right.cap;
    }
};
struct compmax{
bool operator()(const capital& left, const capital& right){
        return left.cap < right.cap;
    }
};
priority_queue<capital,vector<capital>, compmin> minheap;

void insert(vector<int> capitals)
{
    int sz =  capitals.size();
    for(int i =0; i< sz; i++)
    {
      minheap.push({capitals[i], i});  
    }
}

int MaximumCapital(int c, int k, vector<int> capitals, vector<int> profits)
{
    int totalcapital =  c;
     insert(capitals);

    for (int i =0; i < k; i++)
    {
        capital c = minheap.top();
        capital max = c;
        vector<capital> list;
        //finding the max profit capital

        while(c.cap <= totalcapital && !minheap.empty()){
         minheap.pop();
         list.push_back(c);
         if( profits[c.index] >= profits[max.index])
            max =c; 
         c =   minheap.top(); 
        } 

        //remove the max capitalfrom the heap and insert the rest of the element back
        for( capital x :  list){
              if( x.cap == max.cap)
                continue;
             minheap.push(x);
        }
        totalcapital+=  profits[max.index];
    }
    return totalcapital;
}
int main(){
    vector<int> captial = {1, 3, 4, 5, 6};
    vector<int> profit = {1, 2, 3, 4, 5};
    int ic =  1;
    int chance  = 2;
    int max = MaximumCapital(2,3, captial,profit);
    cout<< "Max Capital:" << max << endl;

}