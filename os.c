#include<stdio.h>

/*
p - process
at - arrival time
bt - burst time
wt - waiting time 
tat- turnaround time 
rnt - remaining time  
pp - priority
*/

int n,quantum;
struct process_times{
    int pid,p,af,a,fb,b,comp,tat;
};


void sort(struct process_times temp[],int n)
{  
	int i=0,j=0,temp1=0;
	for (i = 0; i < n; ++i) 
    {
        for (j = i + 1; j < n; ++j)
        {
            if (temp[i].af>temp[j].af) 
            {
            	temp1 =  temp[i].comp;
                temp[i].comp = temp[j].comp;
                temp[j].comp = temp1;
                temp1 =  temp[i].a;
                temp[i].a = temp[j].a;
                temp[j].a = temp1;
                temp1 =  temp[i].af;
                temp[i].af = temp[j].af;
                temp[j].af = temp1;
                temp1 =  temp[i].p;
                temp[i].p = temp[j].p;
                temp[j].p = temp1;
                temp1 =  temp[i].pid;
                temp[i].pid = temp[j].pid;
                temp[j].pid = temp1; 
                temp1 =  temp[i].b;
                temp[i].b = temp[j].b;
                temp[j].b = temp1; 
                temp1 =  temp[i].fb;
                temp[i].fb = temp[j].fb;
                temp[j].fb = temp1;
    	    }
			else if(temp[i].af==temp[j].af)
			{
              	if(temp[i].p<temp[j].p)
				{
                temp1 =  temp[i].comp;
                temp[i].comp = temp[j].comp;
                temp[j].comp = temp1;
                temp1 =  temp[i].a;
                temp[i].a = temp[j].a;
                temp[j].a = temp1;
                temp1 =  temp[i].p;
                temp[i].p = temp[j].p;
                temp[j].p = temp1;
                temp1 =  temp[i].af;
                temp[i].af = temp[j].af;
                temp[j].af = temp1;
                temp1 =  temp[i].pid;
                temp[i].pid = temp[j].pid;
                temp[j].pid = temp1; 
                temp1 =  temp[i].b;
                temp[i].b = temp[j].b;
                temp[j].b = temp1; 
                temp1 =  temp[i].fb;
                temp[i].fb = temp[j].fb;
                temp[j].fb = temp1;	
				}
			}
        }
	}
}


void sortid(struct process_times temp[],int n)
{
	int i=0,j=0,temp1=0;
	for (i = 0; i < n; ++i) 
    {
        for (j = i + 1; j < n; ++j)
        {
            if (temp[i].pid>temp[j].pid) 
            {
              temp1 =  temp[i].comp;
                temp[i].comp = temp[j].comp;
                temp[j].comp = temp1;
                temp1 =  temp[i].a;
                temp[i].a = temp[j].a;
                temp[j].a = temp1;
                temp1 =  temp[i].af;
                temp[i].af = temp[j].af;
                temp[j].af = temp1;
                temp1 =  temp[i].p;
                temp[i].p = temp[j].p;
                temp[j].p = temp1;
                temp1 =  temp[i].pid;
                temp[i].pid = temp[j].pid;
                temp[j].pid = temp1; 
                temp1 =  temp[i].b;
                temp[i].b = temp[j].b;
                temp[j].b = temp1; 
                temp1 =  temp[i].fb;
                temp[i].fb = temp[j].fb;
                temp[j].fb = temp1;	
            }
		}
    }
 
}

void display_answer(struct process_times temp[],int n,int time){

	printf("\n\n\t Final Solution :- \n");
	float avtat=0,avwt=0;
	printf(" PROCESS ID \t| TurnAroundTime \t| Waiting Time  \n");
	for(int i=0;i<n;i++)
	{	
		temp[i].tat = temp[i].comp-temp[i].a;
		int x = temp[i].comp-(temp[i].a+temp[i].b);
		printf(" P[%d] \t\t| %d \t\t\t| %d \n",temp[i].pid,temp[i].tat,x);
		avtat+=temp[i].tat;	
		avwt+=x;
	}
	printf("%d %d",temp[n-1].a,time);
	float cpu_util = ((float)temp[n-1].a/(float)time) * 100;
	printf("\n\n Average TurnAround Time =  %.2f",avtat/=(n));
	printf("\n Average Waiting Time =  %.2f",avwt/=(n));
	printf("\n CPU_UTIL = %0.2f percent \n",cpu_util);
}


void main_sol(struct process_times temp[],int n){
    	int slot = 0,time = 0,cur = 0,nw[10];
	for(int i=0;i<n;i++)
	{
		nw[i] += temp[i].b ;
		if((nw[i] < temp[i+1].a)){
			slot = slot+1;
		}
		if(temp[i].b%quantum==0)
			slot = slot+temp[i].b/quantum;
		else
			slot = slot+(temp[i].b/quantum)+1;
		printf("%d\n",slot);
	}
	
	for(int i=0;i<slot;i++)
	{
		int k = 0;
		int flag =0;
		int ft=time;
		if(temp[cur].af<=time){
			if(temp[cur].fb<=quantum)
			{
				time=time+temp[cur].fb;
				temp[cur].af=temp[cur].af+temp[cur].fb;
				k = temp[cur].fb - quantum;
				temp[cur].fb=0;
				temp[cur].p=-100;
				temp[cur].af=100000;
				temp[cur].comp=time;
			}
			else
			{
				temp[cur].fb=temp[cur].fb-quantum;
				time+=quantum;
				temp[cur].af=temp[cur].af+quantum;
			}
				printf("Process P[%d]Executed From %d to %d\n",temp[cur].pid,ft,time);
		}
		else{
			flag = 1;
		k  = temp[cur].a - ft;
		time+=k;
			printf("Process P_IDLE Executed From %d to %d\n",ft,time);
			
		}
		if(flag==0){
		//	printf(" P[%d] \t\t| %d \t\t| %d \t\t| %d \t\t %d\n",pid[cur],a[i],b[i],p[i],comp[i]);
		sort(temp,n);
		
	//	printf(" P[%d] \t\t| %d \t\t| %d \t\t| %d \t\t %d\n",pid[cur],a[i],b[i],p[i],comp[i]);
	
	    printf("\n\n");
		cur=0;
		for(int j=1;j<n;j++)
			if(temp[j].p>temp[cur].p&&temp[j].af<=time)
					cur = j;
		
	
	}
    }
	sortid(temp,n);
	display_answer(temp,n,time);
}

void display_question(struct process_times temp[],int n){
    	printf("\n\n\t\tQuestion :- \n\n");
	printf(" PROCESS ID \t| ARRIVAL TIME \t| BURST TIME \t| PRIORITY \n");
	for(int i=0;i<n;i++)
	{
		printf(" P[%d] \t\t| %d \t\t| %d \t\t| %d \t\t %d\n",temp[i].pid,temp[i].a,temp[i].b,temp[i].p,temp[i].comp);
	}
	printf("\n\n");
    main_sol(temp,n);
}


void insert(){ 
    printf("Prioirty Based Round Robin Scheduling\n\n");
	printf("Enter Time Quantum :- ");
	scanf("%d",&quantum);
	printf("Enter Number of Process:- ");
	scanf("%d",&n);
    struct process_times temp[n];
	for(int i=0;i<n;i++){
		printf("\nEnter Arrval Time of Process %d :- ",i+1);
		temp[i].pid = i+1;
		scanf("%d",&temp[i].a);
		temp[i].af=temp[i].a;
		printf("Enter Burst Time Of Process %d :- ",i+1);
		scanf("%d",&temp[i].b);
		temp[i].fb = temp[i].b;
		printf("Enter Priority Of Process %d :- ",i+1);
		scanf("%d",&temp[i].p);	
		temp[i].comp = 0;
		temp[i].tat = 0;
	}
	sort(temp,n);
   display_question(temp,n);
}




int main(){
    insert();
    return 0;
}