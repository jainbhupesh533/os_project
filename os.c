#include<stdio.h>
#include"queue.c"

/*
p - process
at - arrival time
bt - burst time
wt - waiting time 
tat- turnaround time 
rnt - remaining time  
pp - priority
*/


struct process_times{
    int p,at,bt,wt,tat,pp,rnt;
};

void sortstruc(struct process_times b[],int pro){
struct process_times temp;
for(int i = 0;i<pro;i++){
    for(int j=i+1;j<pro;j++)
    {
        if(b[i].at > b[j].at)
        {
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    }
}
return ;
}

void gant_chart(struct process_times a[],int pro,int ts){
    int remain = 0,time = 0,i,;
    int r_p[pro];
    remain = pro;
    sortstruc(a,pro);
    printf("Gant Chart\n: ");
    int cpu_time = a[0].at;
    if(cpu_time != 0){
        time += cpu_time;
        printf("0-> [P_IDLE]  <-%d",time);
        insert(a[0].p);
    }else{
        insert(a[0].p)
    }
    for(i = 0;remain!=0;){
        if((a[i].at<=ts && a[i].at>0) && a[i].p == intArray[i])
        {
            
        }
    }
    

}

void display(struct process_times a[],int pro){
    sortstruc(a,pro);
printf("\nProcess\tPriority\tArrival_Time\tBurst_time\n");
    for(int i=0;i<pro;i++)
       {
              printf("P%d\t\t%d\t\t%d\t\t%d\t\t\n",a[i].p+1,a[i].at,a[i].bt,a[i].pp);
       }
}

int main(){
    int pro,time,ts;
    printf("\t\t\tPriotity based round robin algorithm\n");
    printf("Enter the no of process: ");
    scanf("%d",&pro);
    struct process_times a[pro];
    printf("Enter the time quantutm: ");
    scanf("%d",&ts);
    for(int i=0;i<pro;i++)
       {
              printf("Enter priority, arrival time and Burst time for Process P%d : ",i+1);
              scanf("%d%d%d",&a[i].pp,&a[i].at,&a[i].bt);
              a[i].p = i;
              a[i].rnt = a[i].bt;
       }
    main_sol(a,pro,ts);
    return 0;
}