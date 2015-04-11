#include <iostream>

#include "bag.h"
#include "bag_exception.h"

using namespace std;

#define DEBUG true

ostream &operator <<(ostream &os,const Bag &obj)
{	
	os << "{";
	for (int i = 0; i < obj.size; i++)
		os << obj.bag[i] << (i < obj.size-1 ? ", " : "");
	os << "}";
	return os;
}

Bag &Bag::operator+=(const Bag &obj){
	int j = size;
	size += obj.size;
	checkCapacity();
	for (int i=0; i < obj.size; i++)
    bag[j+i] = obj.bag[i];
	return *this;
}


Bag operator+(const Bag &obj, int i){
	Bag result;
	result.size = obj.size;
	result.checkCapacity();
	for (int x = 0; x < result.size; x++) 
		result.bag[x] = obj.bag[x];
	result.bag[result.size] = i;
	result.size++;
	return result;
}

Bag operator+(const Bag &bag1, const Bag &bag2){
	Bag result = bag1;
	return result += bag2;
}


Bag::Bag(const Bag &other) : bag(new int[other.capacity]), capacity(other.capacity), size(other.size) {
	for (int i = 0; i < size; i++) 
		bag[i] = other.bag[i];
}

Bag &Bag::operator =(const Bag &rhs) {
	if (this == &rhs) return *this;
	delete [] bag;
	size = rhs.size;
	capacity = rhs.capacity;
	bag = new int[capacity];  
	for (int i = 0; i < size; i++) 
		bag[i] = rhs.bag[i];
	return *this;
}


Bag &Bag::operator +=(int val) {
	checkCapacity();
	bag[size] = val;
	size++;
	return *this;
}


bool Bag::isEmpty(){
	if (size == 0)
	return true;
	else
	return false;
}

bool Bag::contains(int val) const
{
	for (int i=0; i < this->size; i++){
		if(this->bag[i] == val)
			return true;}
	return false;
}

int Bag::find(int val) const{
	int occurrence=0;
	for(int i=0; i < this->size; i++){
	if(this->bag[i] == val) 
	occurrence++;}
	if(occurrence > 0)
	return occurrence;
	else
	return -1;
}


void Bag::checkCapacity(){
	if (size < capacity) return;
	
	capacity *= 2;
	int *newBag = new int [capacity];
	for (int i=0;i < size; i++)
		newBag[i] = bag[i];
	delete [] bag;
	bag = newBag; 
	if (DEBUG) cerr << "Increased array capacity to " << capacity << endl;
}

void Bag::clear(){ 
	delete [] bag;
	bag = 0;
	size = 0;
	}
