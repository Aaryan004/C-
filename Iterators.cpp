#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    unordered_map<string,int> ourMap;
    ourMap["a1"]=1;
    ourMap["a2"]=2;
    ourMap["a3"]=3;
    ourMap["a4"]=4;
    ourMap["a5"]=5;
    unordered_map<string,int>::iterator it=ourMap.begin();
    while(it!=ourMap.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    //find
    unordered_map<string, int>:: iterator it2=ourMap.find("a4");
    cout<<it2->first<<" "<<it2->second<<endl;
    //erase in hashmaps
    ourMap.erase(it2);
    it=ourMap.begin();
    while(it!=ourMap.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    vector<int>::iterator it1=a.begin();

    while(it1!=a.end()){
        cout<<*it1<<endl;
        it1++;
    }

    vector<int>::iterator it3=a.begin()+1;
    a.erase(it3,it3+2);

    it1=a.begin();
    while(it1!=a.end()){
        cout<<*it1<<endl;
        it1++;
    }
}

