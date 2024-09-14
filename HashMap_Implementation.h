#include <string>
using namespace std;
template <typename V>
class MapNode{
public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key,V value){
    this->key=key;
    this->value=value;
    next=nullptr;
    }

    ~MapNode(){
    delete next;
    }
};

template <typename V>
class ourMap{
    MapNode<V>** bucket;
    int count;
    int numBucket;
public:
    ourMap(){
    count=0;
    numBucket=5;
    bucket=new MapNode<V>*[numBucket];
    for(int i=0;i<numBucket;i++){
        bucket[i]=nullptr;
    }
    }
    ~ourMap(){
    for(int i=0;i<numBucket;i++){
        delete bucket[i];
    }
    delete [] bucket;
    }
private:
    int getBucketIndex(string key){
        int hashCode=0;
        int coefficientNumber=1;
        for(int i=key.length()-1;i>=0;i--){
            hashCode+=key[i]*coefficientNumber;
            hashCode%=numBucket;
            coefficientNumber*=37;
            coefficientNumber%=numBucket;
        }
        return hashCode%numBucket;
    }
public:
    double getLoadFactor(){
        return (1.0*count)/numBucket;
    }
    int size(){
        return count;
    }
    void rehash(){
    MapNode<V>** temp=bucket;
    bucket=new MapNode<V>*[2*numBucket];
    int oldNumBucket=numBucket;
    numBucket*=2;
    count=0;// When we will use insert function,if by then we would have not converted count to 0 then it would have meant count will double in value;
    for(int i=0;i<numBucket;i++){
        bucket[i]=nullptr;
    }
    for(int i=0;i<oldNumBucket;i++){
        MapNode<V>* head=temp[i];
        while(head!=nullptr){
            string key=head->key;
            V value=head->value;
            insert(key,value);//count gets updated by itself inside the insert function so in this function we do not have to write any code to update count;
            head=head->next;
        }
    }
    for(int i=0;i<oldNumBucket;i++){
        MapNode<V>* head=temp[i];
        delete head;
    }
    delete [] temp;
    }
    V getValue(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<V>* head=bucket[bucketIndex];
        while(head!=nullptr){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }
    void insert(string key, V value){
     int bucketIndex=getBucketIndex(key);
     MapNode<V>* head=bucket[bucketIndex];
     while(head!=nullptr){
        if(head->key==key){
            head->value=value;
            return;
        }
        head=head->next;
     }
     head=bucket[bucketIndex];
     MapNode<V>* curr=new MapNode<V>(key,value);
     curr->next=head;
     bucket[bucketIndex]=curr;
     count++;
     double loadFactor=(1.0*count)/numBucket;
     if(loadFactor>0.7){
        rehash();
     }
    }

    V remove(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<V>* head=bucket[bucketIndex];
        MapNode<V>* prev=nullptr;
        while(head!=nullptr){
            if(head->key==key){
                if(prev==nullptr){
                    bucket[bucketIndex]=head->next;
                }else{
                    prev->next=head->next;
                }
                V item=head->value;
                head->next=nullptr;
                delete head;
                count--;
                return item;
            }
            prev=head;
            head=head->next;
        }
        return 0;

    }


};
