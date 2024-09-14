#include <vector>
class PriorityQueue{
vector<int> pq;
public:
    PriorityQueue(){

    }
    bool isEmpty(){
    return pq.size()==0;
    }
    int getSize(){
    return pq.size();
    }
    int getMin(){
    if(isEmpty()){
        return -1;
    }
    return pq[0];
    }
    void insertpq(int element){
    pq.push_back(element);
    int childIndex=pq.size()-1;
    while(childIndex>0){
        int parentIndex=(childIndex-1)/2;
        if(pq[childIndex]<pq[parentIndex]){
            swap(pq[childIndex],pq[parentIndex]);
        }else{
        break;
        }
        childIndex=parentIndex;
    }
    }
    int removeMin(){
    if(isEmpty()){
        return -1;
    }
    int ans=pq[0];
    pq[0]=pq[pq.size()-1];
    pq.pop_back();

    int parentIndex=0;
    int leftIndex=2*parentIndex+1;
    int rightIndex=2*parentIndex+2;

    while(leftIndex<pq.size()){
        int minIndex=parentIndex;
        if(pq[leftIndex]<pq[minIndex]){
            minIndex=leftIndex;
        }
        if(rightIndex<pq.size() && pq[rightIndex]<pq[minIndex]){
            minIndex=rightIndex;
        }
        if(minIndex==parentIndex){
            break;
        }
        swap(pq[parentIndex],pq[minIndex]);
        parentIndex=minIndex;
        leftIndex=2*parentIndex+1;
        rightIndex=2*parentIndex+2;

    }
    return ans;
    }
};
