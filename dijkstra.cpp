#include<iostream>
#include<time.h>
using namespace std;
#define V 10

int minDistance(int dist[], bool sptSet[],int nv) 
{ 
    
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < nv; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
}

void dijk(int beg,int nv,int adjmat[V][V],char vert[V])
{
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	int dist[V];    
	bool sptSet[V]; 
	for (int i = 0; i < nv; i++) 
	    dist[i] = INT_MAX, sptSet[i] = false; 
	   
	dist[beg] = 0; 
	   
	for (int count = 0; count < nv-1; count++) 
	   {  
	    int u = minDistance(dist, sptSet,nv); 
		sptSet[u] = true; 
	   
	    for (int v = 0; v < nv; v++) 
	   		if (!sptSet[v] && adjmat[u][v] && dist[u] != INT_MAX && dist[u]+adjmat[u][v] < dist[v]) 
	           	dist[v] = dist[u] + adjmat[u][v]; 
	    } 
	cout<<"\nDistance from Source: "; 
	for (int i = 0; i < nv; i++) 
	    cout<<"\n"<<vert[beg]<<"--->"<<vert[i]<<" = "<<dist[i];
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout<<"time taken when source was: "<<vert[beg]<<" = "<<cpu_time_used;
} 
int main()
{
	
	int nv,ne,adjmat[V][V],weight;
	char v1,v2;
	int vnum1,vnum2;
	int vertnum[V];
	char vert[V];
	cout<<"\n enter no of vertices: ";
	cin>>nv;
	int flag=0;int vert1,vert2;
	cout<<"\nenter vertices: ";
	for(int i=0;i<nv;i++)
	{
		cin>>vert[i];
		vertnum[i]=i;				
	}
	for(int i=0;i<nv;i++)
		for(int j=0;j<nv;j++)
			adjmat[i][j]=0;
	cout<<"\nHow many edges?: ";
	cin>>ne;
	cout<<"\nenter edges:";
	for(int i=0;i<ne;i++)
	{
		cout<<"for edge "<<i+1<<". Enter vertices and the edge weight: \n";
		cout<<"v1:";
		cin>>v1;
		for(int k=0;k<nv;k++)
		{
			if(vert[k]==v1)
			{
				vnum1=k;
			}
		}
		cout<<"\nv2: ";
		cin>>v2;
		for(int k=0;k<nv;k++)
		{
			if(vert[k]==v2)
			{
				vnum2=k;
			}
		}
		cout<<"weight: ";
		cin>>weight;
		adjmat[vnum1][vnum2]=weight;
		adjmat[vnum2][vnum1]=weight;
	}

	cout<<"\nADJENCY MATRIX:\n[";
	for(int i=0;i<nv;i++)
		{
			cout<<"[";
			for(int j=0;j<nv;j++)
				cout<<adjmat[i][j]<<",";
			cout<<"]\n";
		}

	cout<<"]\n";
	cout<<"\nTaking "<<vert[0]<<" as source:\n";
	dijk(0,nv,adjmat,vert); 
	cout<<"\nEnter where to start:";
	int beg;
	char begin;
	cin>>begin;
	for(int k=0;k<nv;k++)
			{
				if(vert[k]==begin)
				{
					beg=k;
				}
			}
	dijk(beg,nv,adjmat,vert); 
	return 0;

}