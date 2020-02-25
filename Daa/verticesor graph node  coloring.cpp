#include <iostream>

using namespace std;

#define V 50
/* cancolor  function to check if the current color assignment 
is safe for vertex v i.e. checks whether the edge exists or not 
(i.e, input[v][i]==1). If exist then checks whether the color to  
be filled in the new vertex(c is sent in the parameter) is already 
used by its adjacent vertices(i-->adj vertices) or not (i.e, color[i]==c) */


bool cancolor(bool input[V][V], int v, int c, int color[V])
{
    for (int i = 0; i < V; i++)
    {
        if(input[v][i] == 1&& (c == color[i])) // checking edge exits or not and if exists  color to be assigned to adjacent  vertex is used or not 
            return false;
               
    }
    return true; 
}


bool colorg(bool input[V][V], int m, int v, int color[V])
{  /* If all vertices are assigned a color then 
       return true */
    if (v == V)
        return true;
        ///* Consider this vertex v and try different colors */

    for (int i = 1; i <= m; i++) {  
     /* Check if assignment of color i to v is fine*/
        if (cancolor(input, v, i, color))
        {   /* recur to assign colors to rest of the vertices */
            color[v] = i;
            if (colorg(input, m, v+1, color))
                return true;
                
                /* If assigning color i doesn't lead to a solution 
               then remove it */
            color[v] = 0;
        }
    }
     /* If no color can be assigned to this vertex then return false */
    return false;
}

// printing colors
void printcolours(int color[V])
{
    for (int i = 0; i < V; i++)
        cout <<"node"<< i<<"="<<color[i] << endl;
}


int main()
{    cout<<" program for node coloring "<<endl;

  
                        
    bool input[V][V];
	cout<<"enter  matrice as input  "<< endl;
	int i,j;
	      for(i=0;i<V;i++) 
		    for(j=0;j<V;j++)
			{
				cin>>input[i][j];
						 }             
                        
    int m = 10; // Number of colors
    int color[V];
  //  memset(color, 0, sizeof color);
  cout<<"color asigned to the nodes are  "<<endl;
  
    bool flag = colorg(input, m, 0, color);
    if (flag)
        printcolours(color);
    else 
        cout << "Solution doesn't exist.";
    return 0;
}
