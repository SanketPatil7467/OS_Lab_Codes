#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pid;
    int bt;
    int at;
    int rt; //remaining time
    int ft;
    int tat; 
    int wt; 
    
} Process;

void sort(int n, Process p[n])
{
    int i, j;
    Process temp;
    
    for(i=0; i<n-1; i++)
        for(j=0; j<(n-1-i); j++)
            if((p[j].at > p[j + 1].at) || ((p[j].at == p[j+1].at) && (p[j].bt > p[j+1].bt)))
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            } 
}

int countIteration(int n, Process p[n],int tq)
{
    int i, j=0, total = 0;
    for(i=0; i<n; i++)
    {
        if(p[i].bt % tq != 0)
            j = j + (p[i].bt / tq) +1;
        else
            j = j + (p[i].bt/tq);
    }
    // 2+3+4 = 9 -->    j = 5  correct
    // 1+2+3 = 6 -->    j = 3  incorrect
    // (1)2+2+3 = 7 --> j = 4  correct 
    
    return j;
}

void print_chart(int n, Process p[n])
{
    int i, j;
    printf("\n\t+");
    for(i=0; i<n; i++)
    {   for(j=1; j<=p[i].bt; j++)
            printf("---");
        printf("+");    
    }
    printf("\n\t|");
    for(i=0; i<n; i++)
    {
        printf(" P%d",p[i].pid);
        for(j=1; j<p[i].bt; j++)
            printf("   ");
        printf("|");
    }
    printf("\n\t+");    
    for(i=0; i<n; i++)
    {   for(j=1; j<=p[i].bt; j++)
            printf("---");
        printf("+");    
    }
    
    int check = 0;
    printf("\n\t%d",p[0].at);
    if(p[0].at > 9)
        check = 1;
    for(i=0; i<n; i++)
    {   for(j=1; j<=p[i].bt; j++)
            if(check == 1)
            {
                printf("  ");
                check = 0;
            }
            else
                printf("   ");
        printf("%d",p[i].ft);
        if(p[i].ft > 9)
            check = 1;
    }

}

int execute(int n, Process p[n], int o, Process exec[o], int t, int tq)
{
    int i, j;
    j = 0;
    for(i=0; i<o; i++)
    {
        if(i==0)
            t = p[i].at;
        if(p[j].rt > 0)
        {
            exec[i] = p[j];
            if(p[j].rt < tq)
            {
                t = t +p[j].rt;
                exec[i].bt = p[j].rt;
                p[j].rt = 0; 
                p[j].ft = t;
            }
            else
            {
                t = t +tq;
                p[j].rt = p[j].rt - tq;
                if(p[j].rt == 0)
                    p[j].ft = t;
                exec[i].bt = tq;
            }
            exec[i].ft = t;
            exec[i].rt = p[j].rt;
        }
        else    
            i--;
        j++;
        if(j == n)
            j = 0;
    }

    return t;
}

void print_table(int n,Process p[n])
{
    int i, avgw = 0, avgt = 0;
    printf("\n\n\tpid\tAt\tBt\tFt\tTAt\tWt\n");
    for(i=0;i<n;i++)
    {
        p[i].tat = p[i].ft - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avgw = avgw + p[i].wt;
        avgt = avgt + p[i].tat;
        if(p[i].pid != -1)
            printf("\n\t%d\t%d\t%d\t%d\t %d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ft,p[i].tat,p[i].wt);
    }
    avgw = (avgw/n);
    avgt = (avgt/n);
    printf("\n\n\tAverage waiting time: %d units\n\tAverage turn-around time: %d units",avgw,avgt);
}

void main()
{
    int n, i, j, t, tq;
    printf("\n\t\t\t\tRound Robin\n\n\t Enter the total number of processes: "); scanf("%d",&n);
    Process p[n];

    printf("\n\t Enter the time quantum: ");
    scanf("%d",&tq);

    printf("\n\t Enter the following data for each process: ");
    for(i=0; i<n; i++)
    {
        printf("\n\t Process %d:\n\tArrival time: ",i+1);
        scanf("%d",&p[i].at);
        printf("\tBurst time: ");
        scanf("%d",&p[i].bt);
        p[i].rt = p[i].bt;
        p[i].pid = i+1;
    }
    sort(n,p); //sorted on arrival and if same then burst time
    
    int u = countIteration(n,p,tq);
    //printf("\n Divides into %d iterations.",o);
    Process exec[u];

    t = execute(n,p,u,exec,t,tq);
    print_table(n,p);
    printf("\n\n\t Gnatt chart\n");
    print_chart(u,exec);
    //printf("\n t: %d\n",t);

    int upbt = 4,  lowbt = 1, rand_at, rand_bt;
    
    int s = t + 2;
    int m;
    printf("\n\n\n\t\t\tRandom CPU Burst\n\n\t Enter the total number of processes: "); scanf("%d",&m);
    Process q[m];
    for(i=0; i<m; i++)
    {
        rand_at = s;
        s++;                
        rand_bt = (rand() % (upbt - lowbt + 1)) + lowbt;
        q[i].at = rand_at; 
        q[i].bt = rand_bt;
        q[i].rt = q[i].bt;
        q[i].pid = i+1;
    }

    sort(m,q); //sorted on arrival and if same then burst time
   
    int v = countIteration(m,q,tq);
    //printf("\n Divides into %d iterations.",v);
    Process exek[v];

    t = execute(m,q,v,exek,t,tq);
    print_table(m,q);
    printf("\n\n\t Gnatt chart\n");
    print_chart(v,exek);
    
    printf("\n\n\n\t Combined Gnatt chart\n");
    print_chart(u,exec);
    printf("\n\n\t\t--IO of 2 units--\n");
    print_chart(v,exek);
}