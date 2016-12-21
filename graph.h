/*
 * graph.h
 *
 *  Created on: Oct 29, 2016
 *      Author:  Yifan_Tian ID 78921267.  Xufeng_Bao, ID 18446359
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
using namespace std;


class Vertex;

class Edge
{
public:
    Edge(Vertex *org, Vertex *dest, float dist)
    {
        origin = org;
        destination = dest;
        distance = dist;
    }

    Vertex* getOrigin() {return origin;}
    Vertex* getDestination() {return destination;}
    float getDistance() {return distance;}
private:
    Vertex* origin;
    Vertex* destination;
    float distance;
};


class Vertex
{
public:
	Vertex(int id)
    {
		nameid = id;
    key = 100000.0;
    parent = this;
    heaplocation = 0;
    }

    void addEdge(Vertex *v, float dist)
    {
        Edge newEdge(this, v, dist);
        edges.push_back(newEdge);
    }

    void printEdges()
    {
        cout << nameid << ":" << endl;
        for (int i = 0; i < edges.size(); i++)
        {
        	Edge e = edges[i];
        	cout << e.getDestination()->getName() << " - " << e.getDistance() << endl;
        }
        cout << endl;
    }

    int getName() {return nameid;}
    vector<Edge> getEdges() {return edges;}

    float getkey() {return key;}
    Vertex* getParent() {return parent;}

    void key_update(float val){ key = val;}
    void parent_update(Vertex* newp){ parent = newp; }
    void printname() {cout<<"vetname: "<<nameid<<endl;}
    void heapupdate(int hl) {heaplocation = hl; }

    int heapl() {return heaplocation; }

private:
    int nameid;
    float key;
    Vertex* parent;			//decide the mst
    int heaplocation;
    vector<Edge> edges;
};


class Graph
{
public:
    Graph(int num)
	{
    	vnum = num;
    	for(int i = 0;i<num;i++){
    		Vertex newv = Vertex(i);
    		vertices.push_back(newv);
    	}
    	for(int i = 0;i<num;i++){
    	    pvertices.push_back(&vertices[i]);
    	   }

	}

    void insert(Vertex v)
    {
        vertices.push_back(v);
    }

    void printGraph()
    {
        for (int i = 0; i < vertices.size(); i++){
            vertices[i].printEdges(); }
    }

    void printvname(){
    	cout<<"printvname0"<<endl;
        for (int i = 0; i < vertices.size(); i++) {
        	cout<<"i2: "<<i<<endl;
        	pvertices[i]->printname();
        }
        cout<<"printvname1"<<endl;
    }

    vector<Vertex*> get_vertices(){
    	return pvertices;
    }
    Vertex* get_Vertex(int i){
    	return pvertices[i];
    }
    int vertex_num(){
    	return vertices.size();
    }
    int size(){
    	return vnum;
    }

private:
    int vnum;
    vector<Vertex> vertices;
    vector<Vertex*> pvertices;
};


#endif /* GRAPH_H_ */
