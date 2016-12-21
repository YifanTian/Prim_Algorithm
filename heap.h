/*
 * heap.h
 *
 *  Created on: Oct 30, 2016
 *      Author:  Yifan_Tian ID 78921267.  Xufeng_Bao, ID 18446359
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

class heap
{
public:
	heap(vector<Vertex*> l1){
		list = l1;
	};

	void Build_min_heap();
	void min_heapify(int i);
	Vertex* heap_maximum();
	Vertex* heap_min();
	Vertex* heap_extract_min();
	void swap(int child,int parent);
	int Left(int parent);
	int Right(int parent);
	int Parent(int child);
	void print_heap();
	int print_effective_heap();
	int find_position(Vertex* v);
	bool vertex_exist(Vertex* v);
	void heap_decrease_key(int i,float key);
	void print_by_name();
	Vertex* node(int location);

	Vertex* remove();
	int getSize();
private:
	vector<Vertex*> list;
};

int heap::getSize() {
	return list.size();
}

Vertex* heap::node(int location) {
	return list[location];
}

void heap:: swap(int child,int parent){
	Vertex* temp = list[child];
	list[child] = list[parent];
	list[parent] = temp;
	list[child]->heapupdate(child);
	list[parent]->heapupdate(parent);
}

int heap::Parent(int child) {
  if (child % 2 == 0)
	return (child/2)-1;
  else
	return child/2;
}

int heap::Left(int parent) {
	return 2*parent+1;
}

int heap::Right(int parent) {
	return 2*parent+2;
}

bool heap::vertex_exist(Vertex* node){
	if (std::find(list.begin(), list.end(), node) != list.end())
		return 1;
	else{
		return 0;
	}
}

int heap::find_position(Vertex* node){
	int location = -1;
	for(int i = 0; i < list.size(); i++){
		if (list[i] == node){
			return i;
		}
	}
	return location;
}

void heap::print_heap(){
	int len = getSize();
	for(int i = 0; i<len;i++){
		cout<<list[i]->getName()<<" "<<list[i]->getkey()<<endl;
	}
}

void heap::print_by_name() {
	int len = getSize();
	for(int i = 0; i<len;i++) {
		cout<<list[i]->getName()<<" "<<list[i]->heapl()<<endl;
	}
}

int heap::print_effective_heap(){
	int len = getSize();
	float maxf = list[len-1]->getkey();
	int stat = 0;
	for(int i = 0; i<len;i++){
		if (list[i]->getkey() < maxf){
			stat += 1;
		}
	}
	return stat;
}


void heap::min_heapify(int i){
 int l = Left(i);
 int r = Right(i);
 int smallest;
 if (l<list.size() && list[l]->getkey() <list[i]->getkey()){
	 smallest = l;
 }
 else {smallest = i;
 }
if (r < list.size() && list[r]->getkey()<list[smallest]->getkey()){
	smallest = r;
	}
 if (smallest != i){
	 swap(i,smallest);
	 min_heapify(smallest);
 }
}

void heap::heap_decrease_key(int i,float key){
	if(key > list[i]->getkey()){
		cout<<"new key is larger than current key"<<endl;
	}
	list[i]->key_update(key);
	while(i>0 && list[Parent(i)]->getkey() > list[i]->getkey()){
		swap(i,Parent(i));
		i = Parent(i);
	}
}


void heap::Build_min_heap(){
	int l = list.size();
	for(int i = 0; i<l; i++){
		list[i]->heapupdate(i);
	}
	for(int i = l/2;i>=0;i--){
		min_heapify(i);
	}
}

Vertex* heap::heap_min(){
	return list[0];
}


Vertex* heap::heap_extract_min(){
if (list.size()<1){
	cout<<"error message"<<endl;
}

Vertex* min = list[0];
list[0] = list[list.size()-1];
for(int i = 0; i< list.size()-1; i++){
	list[i]->heapupdate(i);
}
list.pop_back();
min_heapify(0);
return min;
}



#endif /* HEAP_H_ */
