#include <iostream>
using namespace std;
void findAvgWaitingTime(int proc[],int n,int bt[],int wt[],int quantum){
    int rt_bt[n],t=0;
    for(int i=0;i<n;i++){
        rt_bt[i]=bt[i];
    }
    while(1){
        bool done =true;

        for(int i=0;i<n;i++){
            if(rt_bt[i]>0){
                done=false;
                if(rt_bt[i]>quantum){
                    rt_bt[i]=rt_bt[i]-quantum;
                    t+=quantum;
                }else{
                    t+=rt_bt[i];
                    wt[i]=t-bt[i];
                    rt_bt[i]=0;

                }
            }
        }
        if(done==true){
            break;
        }

    }
}
void findTurnAroundTime(int proc[],int n,int burstTime[],int wt[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i]=burstTime[i]+wt[i];
    }
}
void findavgTime(int proc[],int burstTime[],int n,int quantum){
    int wt[n],tat[n];
    int total_wt=0,total_tat=0;

    findAvgWaitingTime(proc,n,burstTime,wt,quantum);

    findTurnAroundTime(proc,n,burstTime,wt,tat);

    cout<<"PN"<<"\tBT\t"<<"WT\t"<<"TAT"<<endl;

    for(int i=0;i<n;i++){
        total_tat+=tat[i];
        total_wt+=wt[i];
        cout<<proc[i]<<"\t"<<burstTime[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }
    cout<<"Average Waiting Time: "<<(float)total_wt/(float)n<<endl;
    cout<<"Average TurnAround Time: "<<(float)total_tat/(float)n<<endl;
}
int main(){
    int proc[]={1,2,3};
    int n=sizeof(proc)/sizeof(proc[0]);
    int burstTime[]={10,5,8};
    int quantum=2;
    findavgTime(proc,burstTime,n,quantum);
}
