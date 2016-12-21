//============================================================================
// Name        : Prim.cpp
// Author      : Yifan_Tian ID 78921267.  Xufeng_Bao, ID 18446359
// Version     :
// Copyright   : Your copyright notice
// Description : Prim algorithm in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <math.h>
#include <vector>
#include "graph.h"
#include "heap.h"
#include <cstdlib>
#include <sstream>

using namespace std;


int main (int argc, char* argv[]) {

	if (argc != 2) {
    cout<<"incorrect command, should use ./Prim 'input file' "<<endl;
		return 0;
	}

  cout<<"Input graph file: "<<argv[1]<<endl;

  string line;
	ostringstream os;
  double w,total_weight;
  int v1,v2;
  ifstream myfile (argv[1]);

  if (myfile.is_open())
  {
	  getline (myfile,line);
	  char buffer[256];
	  strcpy(buffer, line.c_str());
	  int vnum = atoi (buffer);
	  Graph g(vnum);
    while (getline (myfile,line))
    {
    	if (line.length()>0){
    		std::size_t pos1 = line.find(" ");
    		strcpy(buffer, line.substr(0,pos1).c_str());
    		v1 = atoi(buffer);
    		string line2 = line.substr(pos1+1);
    		std::size_t pos2 = line2.find(" ");
    		strcpy(buffer, line2.substr(0,pos2).c_str());
    		v2 = atoi(buffer);
    		string line3 = line2.substr(pos2+1);
    		std::size_t pos3 = line3.find(" ");
    		strcpy(buffer, line3.substr(0,pos3).c_str());
    		w = atof(buffer);
    		Vertex *vleft = g.get_Vertex(v1);
    		vleft->addEdge(g.get_Vertex(v2),w);
    		Vertex *vright = g.get_Vertex(v2);
    		vright->addEdge(g.get_Vertex(v1),w);
    	}
    }
    myfile.close();
    heap hh(g.get_vertices());
    Vertex *root = g.get_Vertex(0);
    root->key_update(0);
    hh.Build_min_heap();

    ofstream myfile1 ("prim_output.txt");
    //myfile1<<vnum<<endl;
    //myfile1<<endl;
    cout<<endl;
    cout<<"Start Prim:"<<endl;
		cout<<"Total num of vertices in original graph: "<<endl;
    cout<<vnum<<endl;
    cout<<endl;
    int pathn = 0,mstn = 0;
    while(hh.getSize()!=0){
    	Vertex *u =  hh.heap_extract_min();
      if (u->getkey() == 100000){
    		u->key_update(0.0);
    	}
			else if (pathn > 0) {
				cout<<u->getName()<<" "<<u->getParent()->getName()<<" "<<u->getkey()<<endl;
				cout<<endl;
				total_weight += u->getkey();
				os<<u->getName()<<" "<<u->getParent()->getName()<<" "<<u->getkey()<<endl;
				os<<endl;
	      //myfile1<<u->getName()<<" "<<u->getParent()->getName()<<" "<<u->getkey()<<endl;
	    	//myfile1<<endl;
				mstn += 1;
			}
    	vector<Edge> elist = u->getEdges();
    	for(int e = 0; e < elist.size(); e++){
    			if (hh.vertex_exist(elist[e].getDestination()) && elist[e].getDistance() < elist[e].getDestination()->getkey())
    			{
    				int location = hh.find_position(elist[e].getDestination());
    				elist[e].getDestination()->parent_update(u);
    				hh.heap_decrease_key(location,elist[e].getDistance());
    			}
    	    }
					pathn+=1;
    }
		cout<<"Total num of edges in MST: "<<endl;
		cout<<mstn<<endl;
    cout<<"Prim ends."<<endl;
		cout<<"total_weight: "<<total_weight<<endl;
		myfile1<<mstn<<endl;
		myfile1<<endl;
		os<<"total_weight: "<<endl;
		os<<total_weight;
		string s = os.str();
    myfile1<<s;
    myfile1.close();
  }
  else cout << "Unable to open file";

  return 0;
}
