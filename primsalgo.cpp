#include<iostream>
#include<conio.h>
#include"linkedtemp.cpp"
using namespace std;

class Prims
{
	public:
		int nV; //no. of vertices	
		bool* visited; //visited array for vertices;
		SLlist* graph;
		SLlist tree;
		int totalcost;
		int ce;
		
		void inputdata()
		{
			cout<<"Enter the number of vertices : ";
			cin>>nV;
			graph = new SLlist[nV];
			visited = new bool[nV];
			int ans;
			
			//initialising visited array as false
			for(int i=0; i<nV; i++)
			{
				visited[i]=false;
			}
			
			//formation of graph
			cout<<"\nEnter edges and their cost"<<endl;
			cout<<"Enter '1' if connected and '0' if not."<<endl;
			for(int i=0; i<nV; i++)
			{
				for(int j=0; j<nV; j++)
				{
					if(i<j)
					{
						cout<<"\nVertex "<<i<<" connected to  "<<j<<" : ";
						cin>>ans;
						if(ans==1)
						{
							cout<<"Enter the cost of edge : ";
							cin>>ce;
							graph[i].insertatend(j,ce);
							graph[j].insertatend(i,ce);
							
						}
							
					}
				}
				cout<<endl<<endl;
			}
			cout<<"\nGraph formed as follows"<<endl;
			for(int i=0; i<nV; i++)
			{
				cout<<i<<" =  ";
				graph[i].displaygraph();
				cout<<endl;
			}
		}
		
		//MST Prims
		void primsalgo()
		{
			totalcost=0;
			int min, counter=1;
			int index,ver;
			tree.insert(0);
			visited[0]=true;
			
			while(counter<nV)
			{
				min=9999;
				node* treetemp=new node();
				treetemp=tree.head;
				while(treetemp!=NULL)
				{
					node* temp=new node();
					temp=graph[treetemp->info].head;
					while(temp!=NULL)
					{
						if(temp->cost < min)
						{
							min=temp->cost;
							index=treetemp->info;
							ver=temp->info;
							temp=temp->next;	
						}	
						else
							temp=temp->next;
					}
					treetemp=treetemp->next;	
				}
				if(visited[ver]==true)
				{
					if(graph[index].head->info==ver)
						graph[index].deletionatbeg();
					else
						graph[index].deleteat(ver);
				}
				else
				{
					visited[ver]=true;
					tree.insert(ver);
					counter++;
					totalcost+=min;
					cout<<"\nInserted edge in tree with cost : "<<index<<"---"<<ver<<" "<<min;
					
					if(graph[index].head->info==ver)
						graph[index].deletionatbeg();
					else
						graph[index].deleteat(ver);
				}
			}
			
			cout<<"\nTotal cost in the created MST : "<<totalcost;
			cout<<"\nFormed MST tree"<<endl;
			tree.display();
		}

};
int main()
{
	Prims p;
	p.inputdata();
	p.primsalgo();
}
