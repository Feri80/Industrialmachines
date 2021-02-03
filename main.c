#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define maxn 100

int sz=0;

struct machine
{
    int code;
    int repaircode;
    int repairperiod;
    char repairtype;
    char repairdescription[maxn];
};

void add_machine()
{
    struct machine new_machine;
    int x;
    do
    {
        printf("Please Enter Your Machine Code : \n1)Taraash\n2)Ferez\n3)Sang\n4)Drill\n5)Safhe Taraash\n6)Joosh\n7)Press\n8)Boresh\n9)Navard\n");
        scanf("%d",&x);
    }while(x>9 || x<1);
    new_machine.code=x;
    char tmp[1];
    gets(tmp);
    printf("Please Enter Your Machine Repair Description : \n");
    gets(new_machine.repairdescription);
    do
    {
        printf("Please Enter Your Machine Repair Code (1-4) : ");
        scanf("%d",&x);
    }while(x>4 || x<1);
    new_machine.repaircode=new_machine.code*10+x;
    do
    {
        printf("Please Enter Your Machine Repair Period (1-6) : ");
        scanf("%d",&x);
    }while(x>6 || x<1);
    new_machine.repairperiod=x;
    char c;
    do
    {
        printf("Please Enter Your Machine Repair Type (M/E/I)/(m/e/i) : ");
        scanf(" %c",&c);
        c=toupper(c);
    }while(c!='M' && c!='E' && c!='I');
    new_machine.repairtype=c;
    for(int i=0;i<maxn-strlen(new_machine.repairdescription);i++)
    {
        strcat(new_machine.repairdescription," ");
    }
    if(sz==0)
    {
        FILE *fo=fopen("machines.dat","w");
        fprintf(fo,"*\n");
        fprintf(fo,"%d\n",new_machine.code);
        fprintf(fo,"%d\n",new_machine.repaircode);
        fprintf(fo,"%d\n",new_machine.repairperiod);
        fprintf(fo,"%c\n",new_machine.repairtype);
        fprintf(fo,"%s\n",new_machine.repairdescription);
        fclose(fo);
    }
    else
    {
        FILE *fo=fopen("machines.dat","a");
        fprintf(fo,"*\n");
        fprintf(fo,"%d\n",new_machine.code);
        fprintf(fo,"%d\n",new_machine.repaircode);
        fprintf(fo,"%d\n",new_machine.repairperiod);
        fprintf(fo,"%c\n",new_machine.repairtype);
        fprintf(fo,"%s\n",new_machine.repairdescription);
        fclose(fo);
    }
    sz++;
    printf("Added Successfully \n");
}

int find_machine(int code)
{
    FILE *fin=fopen("machines.dat","r");
    if(fin==NULL)
    {
        printf("Can't Find Files \n");
        return -1;
    }
    int t;
    char c;
    int x;
    char b[maxn];
    char tmp[maxn];
    for(int i=0;i<sz;i++)
    {
        fscanf(fin,"%c",&c);
        fscanf(fin,"%d",&t);
        fscanf(fin,"%d",&x);
        fscanf(fin,"%d",&t);
        fscanf(fin," %c",&c);
        fgets(tmp,maxn,fin);
        fgets(b,maxn,fin);
        if(x==code)
        {
            fclose(fin);
            return i;
        }
    }
    fclose(fin);
    return -1;
}

void edit_machine()
{
    printf("Please Enter Your Machine Repair Code : ");
    int x;
    scanf("%d",&x);
    int id=find_machine(x);
    if(id==-1)
    {
        printf("Can't Find This Machine \n");
        return;
    }
    struct machine info;
    FILE *fin=fopen("machines.dat","r");
    int t;
    char c;
    char b[maxn];
    char tmp[maxn];
    for(int i=0;i<sz;i++)
    {
        if(i==id)
        {
            fscanf(fin,"%c",&c);
            fscanf(fin,"%d",&t);
            info.code=t;
            fscanf(fin,"%d",&t);
            info.repaircode=t;
            fscanf(fin,"%d",&t);
            info.repairperiod=t;
            fscanf(fin," %c",&c);
            info.repairtype=c;
            fgets(tmp,maxn,fin);
            fgets(b,maxn,fin);
            strcpy(info.repairdescription,b);
        }
        else
        {
            fscanf(fin,"%c",&c);
            fscanf(fin,"%d",&t);
            fscanf(fin,"%d",&t);
            fscanf(fin,"%d",&t);
            fscanf(fin," %c",&c);
            fgets(tmp,maxn,fin);
            fgets(b,maxn,fin);
        }
    }
    fclose(fin);
    do
    {
        printf("Which Information You Want To Change : \n1)Code\n2)Repair Code\n3)Repair Period\n4)Repair Type\n5)Repair Description\n");
        scanf("%d",&x);
    }while(x>5 || x<1);
    int y;
    if(x==1)
    {
        do
        {
            printf("Please Enter Your Machine Code : \n1)Taraash\n2)Ferez\n3)Sang\n4)Drill\n5)Safhe Taraash\n6)Joosh\n7)Press\n8)Boresh\n9)Navard\n");
            scanf("%d",&y);
        }while(y>9 || y<1);
        info.code=y;
        int z=info.repaircode%10;
        info.repaircode=y*10;
        info.repaircode+=z;
    }
    else if(x==2)
    {
        do
        {
            printf("Please Enter Your Machine Repair Code (1-4) : ");
            scanf("%d",&y);
        }while(y>4 || y<1);
        info.repaircode=info.code*10+y;
    }
    else if(x==3)
    {
        do
        {
            printf("Please Enter Your Machine Repair Period (1-6) : ");
            scanf("%d",&y);
        }while(y>6 || y<1);
        info.repairperiod=y;
    }
    else if(x==4)
    {
        do
        {
            printf("Please Enter Your Machine Repair Type (M/E/I)/(m/e/i) : ");
            scanf(" %c",&c);
            c=toupper(c);
        }while(c!='M' && c!='E' && c!='I');
        info.repairtype=c;
    }
    else if(x==5)
    {
        char tmp[1];
        gets(tmp);
        printf("Please Enter Your Machine Repair Description : \n");
        gets(info.repairdescription);
    }
    else
    {
        return;
    }
    FILE *fedit=fopen("machines.dat","r");
    long int p;
    for(int i=0;i<sz;i++)
    {
        if(i==id)
        {
            p=ftell(fedit);
            fscanf(fedit,"%c",&c);
            fscanf(fedit,"%d",&t);
            fscanf(fedit,"%d",&t);
            fscanf(fedit,"%d",&t);
            fscanf(fedit," %c",&c);
            fgets(tmp,maxn,fin);
            fgets(b,maxn,fin);
        }
        else
        {
            fscanf(fedit,"%c",&c);
            fscanf(fedit,"%d",&t);
            fscanf(fedit,"%d",&t);
            fscanf(fedit,"%d",&t);
            fscanf(fedit," %c",&c);
            fgets(tmp,maxn,fin);
            fgets(b,maxn,fin);
        }
    }
    fclose(fedit);
    fedit=fopen("machines.dat","r+");
    fseek(fedit,p,SEEK_SET);
    fprintf(fedit,"*\n");
    fprintf(fedit,"%d\n",info.code);
    fprintf(fedit,"%d\n",info.repaircode);
    fprintf(fedit,"%d\n",info.repairperiod);
    fprintf(fedit,"%c\n",info.repairtype);
    for(int i=0;i<maxn-strlen(info.repairdescription);i++)
    {
       strcat(info.repairdescription," ");
    }
    fputs(info.repairdescription,fedit);
    fclose(fedit);
    printf("Edited Successfully \n");
}

void delete_machine()
{
    printf("Please Enter Your Machine Repair Code : ");
    int x;
    scanf("%d",&x);
    int id=find_machine(x);
    if(id==-1)
    {
        printf("Can't Find This Machine \n");
        return;
    }
    struct machine machines[sz-1];
    FILE *fin=fopen("machines.dat","r");
    int t;
    char c;
    char b[maxn];
    char tmp[maxn];
    int j=0;
    for(int i=0;i<sz;i++)
    {
        if(i!=id)
        {
            fscanf(fin,"%c",&c);
            fscanf(fin,"%d",&t);
            machines[j].code=t;
            fscanf(fin,"%d",&t);
            machines[j].repaircode=t;
            fscanf(fin,"%d",&t);
            machines[j].repairperiod=t;
            fscanf(fin," %c",&c);
            machines[j].repairtype=c;
            fgets(tmp,maxn,fin);
            fgets(b,maxn,fin);
            strcpy(machines[j].repairdescription,b);
            j++;
        }
        else
        {
            fscanf(fin,"%c",&c);
            fscanf(fin,"%d",&t);
            fscanf(fin,"%d",&t);
            fscanf(fin,"%d",&t);
            fscanf(fin," %c",&c);
            fgets(tmp,maxn,fin);
            fgets(b,maxn,fin);
        }
    }
    fclose(fin);
    sz--;
    FILE *fo=fopen("machines.dat","w");
    for(int i=0;i<sz;i++)
    {
        fprintf(fo,"*\n");
        fprintf(fo,"%d\n",machines[i].code);
        fprintf(fo,"%d\n",machines[i].repaircode);
        fprintf(fo,"%d\n",machines[i].repairperiod);
        fprintf(fo,"%c\n",machines[i].repairtype);
        fprintf(fo,"%s",machines[i].repairdescription);
    }
    fclose(fo);
    printf("Deleted Successfully \n");
}

void show_machine()
{
    printf("Please Enter Your Machine Repair Code : ");
    int x;
    scanf("%d",&x);
    int id=find_machine(x);
    if(id==-1)
    {
        printf("Can't Find This Machine \n");
        return;
    }
    FILE *fin=fopen("machines.dat","r");
    if(fin==NULL)
    {
        printf("Can't Find Files \n");
        return;
    }
    int t;
    char c;
    char b[maxn];
    char tmp[maxn];
    for(int i=0;i<sz;i++)
    {
        if(i==id)
        {
            printf("Your Machine Info : \n");
            printf("\t------------------------------------------\n");
            fscanf(fin,"%c",&c);
            fscanf(fin,"%d",&t);
            printf("\tMachine Code : %d ",t);
            if(t==1)
            {
                printf("Taraash\n");
            }
            else if(t==2)
            {
                printf("Ferez\n");
            }
            else if(t==3)
            {
                printf("Sang\n");
            }
            else if(t==4)
            {
                printf("Drill\n");
            }
            else if(t==5)
            {
                printf("Safhe Taraash\n");
            }
            else if(t==6)
            {
                printf("Joosh\n");
            }
            else if(t==7)
            {
                printf("Press\n");
            }
            else if(t==8)
            {
                printf("Boresh\n");
            }
            else if(t==9)
            {
                printf("Navard\n");
            }
            fscanf(fin,"%d",&x);
            printf("\tMachine Repair Code : %d \n",x);
            fscanf(fin,"%d",&t);
            printf("\tMachine Repair Period : %d \n",t);
            fscanf(fin," %c",&c);
            printf("\tMachine Repair Type : %c \n",c);
            fgets(tmp,maxn,fin);
            fgets(b,maxn,fin);
            printf("\tMachine Repair Description : \n\t%s",b);
            printf("\t------------------------------------------\n");
        }
        else
        {
            fscanf(fin,"%c",&c);
            fscanf(fin,"%d",&t);
            fscanf(fin,"%d",&x);
            fscanf(fin,"%d",&t);
            fscanf(fin," %c",&c);
            fgets(tmp,maxn,fin);
            fgets(b,maxn,fin);
        }
        
    }
    fclose(fin);
}

void show_plan()
{
    int m;
    printf("Please Enter Period In Month : ");
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        FILE *fin=fopen("machines.dat","r");
        printf("Month Number %d :\n\n",i);
        for(int j=0;j<sz;j++)
        {
            struct machine cur;
            int t;
            char c;
            char b[maxn];
            char tmp[maxn];
            int flag=0;
            fscanf(fin,"%c",&c);
            fscanf(fin,"%d",&t);
            cur.code=t;
            fscanf(fin,"%d",&t);
            cur.repaircode=t;
            fscanf(fin,"%d",&t);
            cur.repairperiod=t;
            if(i%cur.repairperiod==0)
            {
                flag=1;
            }
            fscanf(fin," %c",&c);
            cur.repairtype=c;
            fgets(tmp,maxn,fin);
            fgets(b,maxn,fin);
            strcpy(cur.repairdescription,b);
            if(flag)
            {
                printf("\t------------------------------------------\n");
                printf("\tMachine Code : %d ",cur.code);
                if(cur.code==1)
                {
                    printf("Taraash\n");
                }
                else if(cur.code==2)
                {
                    printf("Ferez\n");
                }
                else if(cur.code==3)
                {
                    printf("Sang\n");
                }
                else if(cur.code==4)
                {
                    printf("Drill\n");
                }
                else if(cur.code==5)
                {
                    printf("Safhe Taraash\n");
                }
                else if(cur.code==6)
                {
                    printf("Joosh\n");
                }
                else if(cur.code==7)
                {
                    printf("Press\n");
                }
                else if(cur.code==8)
                {
                    printf("Boresh\n");
                }
                else if(cur.code==9)
                {
                    printf("Navard\n");
                }
                printf("\tMachine Repair Code : %d \n",cur.repaircode);
                printf("\tMachine Repair Period : %d \n",cur.repairperiod);
                printf("\tMachine Repair Type : %c \n",cur.repairtype);
                printf("\tMachine Repair Description : \n\t%s",cur.repairdescription);
                printf("\t------------------------------------------\n\n");
            }
        }
        fclose(fin);
    }
    
}

int main()
{
    sz=5;
    show_machine();
}