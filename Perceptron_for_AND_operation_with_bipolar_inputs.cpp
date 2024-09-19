
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Perceptron{
public:
    vector<double> weights{0.0,0.0};
    double bias=0.0;
    double learning_rate=1;
    int epochs=100;
    Perceptron(vector<double> weights,double bias,double learning_rate,int epochs):weights(weights),bias(bias),learning_rate(learning_rate),epochs(epochs){}
    int activation(double x){
        return x>0?1:-1;
    }
    
    void train(vector<vector<double>>& X,vector<double>y){
        for(int j=0;j<epochs;j++){
            int n=X.size();
            for(int i=0;i<n;i++){
                double sum=bias;
                for(int k=0;k<weights.size();k++){
                    sum+=weights[k]*X[i][k];
                }
                
                int predict=activation(sum);
                
                int error=y[i]-predict;
                
                for(int k=0;k<weights.size();k++){
                    weights[k]+=learning_rate*error*X[i][k];
                }
                bias+=learning_rate*error;
            }
        }
    }
    
    int prediction(vector<double>& X){
        double sum=bias;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i]*X[i];
        }
        return activation(sum);
    }
    
    void printWeights(){
        cout<<"Weights ";
        for(double w: weights){
            cout<< w <<" ";
        }
        cout<<"\nBias "<<bias<<endl;
    }
};
int main(){
    vector<vector<double>> train={
        {-1,-1},
        {-1,1},
        {1,-1},
        {1,1}};
    vector<double> y={-1,-1,-1,1};
    Perceptron p({0,0},0,1,200);
    p.train(train,y);
    p.printWeights();
    vector<vector<double>> tests={
        {-1,-1},
        {-1,1},
        {1,-1},
        {1,1}};
        y={-1,-1,-1,1};
        int i=0;
    for(vector<double> test:tests){
       cout<<test[0]<<" "<<test[1]<<" ";
       cout<<p.prediction(test)<<" ";
       cout<<y[i]<<"\n";
       i++;
    }
}
