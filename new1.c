#include<stdio.h>
int quantum,n,p[10],a[10],af[10],j,pid[10],b[10],time=0,cur=0,slot=0,comp[10],tat[10],wt[10],fb[10];
void sort()
{
	int i=0,j=0,temp=0;
	for (i = 0; i < n; ++i) 
    {
        for (j = i + 1; j < n; ++j)
        {
            if (af[i]>af[j]) 
            {
            	temp =  comp[i];
                comp[i] = comp[j];
                comp[j] = temp;
                temp =  a[i];
                a[i] = a[j];
                a[j] = temp;
                temp =  af[i];
                af[i] = af[j];
                af[j] = temp;
                temp =  p[i];
                p[i] = p[j];
                p[j] = temp;
                temp =  pid[i];
                pid[i] = pid[j];
                pid[j] = temp; 
                temp =  b[i];
                b[i] = b[j];
                b[j] = temp; 
                temp =  fb[i];
                fb[i] = fb[j];
                fb[j] = temp;
    	    }
			else if(af[i]==af[j])
			{
              	if(p[i]<p[j])
				{
            	   	temp =  comp[i];
            	    comp[i] = comp[j];
            	    comp[j] = temp;
                	temp =  a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    temp =  p[i];
                    p[i] = p[j];
                    p[j] = temp;
                    temp =  af[i];
                    af[i] = af[j];
                    af[j] = temp;
                    temp =  pid[i];
                    pid[i] = pid[j];
                    pid[j] = temp; 
                    temp =  b[i];
                    b[i] = b[j];
                    b[j] = temp;
					temp =  fb[i];
                    fb[i] = fb[j];
                    fb[j] = temp;	
				}
			}
        }
	}
}

void sortid()
{
	int i=0,j=0,temp=0;
	for (i = 0; i < n; ++i) 
    {
        for (j = i + 1; j < n; ++j)
        {
            if (pid[i]>pid[j]) 
            {
              	temp =  comp[i];
                comp[i] = comp[j];
                comp[j] = temp;
                temp =  a[i];
                a[i] = a[j];
                a[j] = temp;
                temp =  af[i];
                af[i] = af[j];
                af[j] = temp;
                temp =  p[i];
                p[i] = p[j];
                p[j] = temp;
                temp =  pid[i];
                pid[i] = pid[j];
                pid[j] = temp; 
                temp =  b[i];
                b[i] = b[j];
                b[j] = temp; 
                temp =  fb[i];
                fb[i] = fb[j];
                fb[j] = temp;
            }
		}
    }
 
}


void display_answer(){

	printf("\n\n\t Final Solution :- \n");
	float avtat=0,avwt=0;
	printf(" PROCESS ID \t| TurnAroundTime \t| Waiting Time  \n");
	for(int i=0;i<n;i++)
	{	
		tat[i] = comp[i]-a[i];
		int x = comp[i]-(a[i]+b[i]);
		printf(" P[%d] \t\t| %d \t\t\t| %d \n",pid[i],tat[i],x);
		avtat+=tat[i];	
		avwt+=x;
	}
	float cpu_util = ((float)a[n-1]/(float)time) * 100;
	printf("\n\n Average TurnAround Time =  %.2f",avtat/=(n));
	printf("\n Average Waiting Time =  %.2f",avwt/=(n));
	printf("\n CPU_UTIL = %0.2f percent",cpu_util);

}

void main_sol(){
	
	for(int i=0;i<n;i++)
	{
	
		if((a[i]+b[i] < a[i+1])&&(pid[i] < n)){
			slot = slot+1;
		}
		if(b[i]%quantum==0)
			slot = slot+b[i]/quantum;
		else
			slot = slot+(b[i]/quantum)+1;
		printf("%d",slot);
		
	}
	for(int i=0;i<slot ;i++)
	{
		int k = 0;
		int flag =0;
		int ft=time;
		if(af[cur]<=time){
			if(fb[cur]<=quantum)
			{
				time=time+fb[cur];
				af[cur]=af[cur]+fb[cur];
				k = fb[cur] - quantum;
				fb[cur]=0;
				p[cur]=-100;
				af[cur]=100000;
				comp[cur]=time;
			}
			else
			{
				fb[cur]=fb[cur]-quantum;
				time+=quantum;
				af[cur]=af[cur]+quantum;
			}
				printf("Process P[%d]Executed From %d to %d\n",pid[cur],ft,time);
		}
		else{
			flag = 1;
		k  = a[cur] - ft;
		time+=k;
			printf("Process P_IDLE Executed From %d to %d\n",ft,time);
			
		}
		if(flag==0){
		//	printf(" P[%d] \t\t| %d \t\t| %d \t\t| %d \t\t %d\n",pid[cur],a[i],b[i],p[i],comp[i]);
		sort(a,p,pid,af,b,fb,n,comp);
		
	//	printf(" P[%d] \t\t| %d \t\t| %d \t\t| %d \t\t %d\n",pid[cur],a[i],b[i],p[i],comp[i]);
	
	printf("\n\n");
		cur=0;
		for(int j=1;j<n;j++)
			if(p[j]>p[cur]&&af[j]<=time)
					cur = j;
		
	
	}
	}
	sortid(a,p,pid,af,b,fb,n,comp);
	display_answer();
}

void display_question(){

	printf("\n\n\t\tQuestion :- \n\n");
	printf(" PROCESS ID \t| ARRIVAL TIME \t| BURST TIME \t| PRIORITY \n");
	for(int i=0;i<n;i++)
	{
		printf(" P[%d] \t\t| %d \t\t| %d \t\t| %d \t\t %d\n",pid[i],a[i],b[i],p[i],comp[i]);
	}
	printf("\n\n");
	main_sol();
} 


void insert(){
	
	printf("Prioirty Based Round Robin Scheduling\n\n");
	printf("Enter Time Quantum :- ");
	scanf("%d",&quantum);
	printf("Enter Number of Process:- ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("\nEnter Arrval Time of Process %d :- ",i+1);
		pid[i] = i+1;
		scanf("%d",&a[i]);
		af[i]=a[i];
		printf("Enter Burst Time Of Process %d :- ",i+1);
		scanf("%d",&b[i]);
		fb[i] = b[i];
		printf("Enter Priority Of Process %d :- ",i+1);
		scanf("%d",&p[i]);	
	}
	sort(a,p,pid,af,b,fb,n,comp);
	display_question();
}

int main()
{
	insert();
return 0;
}
	
