#ifndef BAG_H
#define BAG_H

#include <iostream>

using namespace std;

class Bag
{
	friend ostream &operator <<(ostream &os,const Bag &obj);
	friend Bag operator+(const Bag &obj, int i);
    friend Bag operator+(const Bag &bag1, const Bag &bag2);
    
public:
	Bag(int capacity=100) : bag(new int[capacity]), capacity(capacity), size(0) {}
	Bag(const Bag &other);
	~Bag() {delete [] bag;}
	Bag & operator =(const Bag &rhs);
	Bag &operator +=(int val);
	Bag &operator +=(const Bag &bag);
	int getSize() const {return size;}
	bool isEmpty();
    bool contains(int val) const;
    int find(int val) const;
    void clear();
    
private:
	void checkCapacity();
	int *bag;
	int capacity;
	int size;
};

#endif
