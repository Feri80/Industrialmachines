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
        printf("Please Enter Your Machine Code : \n1)Taraash\n2)Ferez\n3)Sang\n4)Drill\n5)Safhe Taraash\n6)Joosh\n7)Press\n8)Boresh\n9)Navar\n");
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
}

int main()
{
    
}