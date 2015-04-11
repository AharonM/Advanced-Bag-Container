#include<iostream>

#include "bag.h"


int main()
{
	Bag bag(10);
	int n;

	for (int i = 0; i < 7; i++)
		bag += i;

	cout << "bag:\n" << bag << endl;
	
	Bag bagI = bag;
	cout << "bagI:\n" << bagI << endl;
	
	bag += 9;
	cout << "bagI:\n" << bagI << endl;
	
	bagI += 2;
	cout << "bag:\n" << bag << endl;
	
	Bag bagG(10);
	for (int i = 0; i < 6; i++)
		bagG += i;
	cout << "bagG:\n" << bagG << endl;
		
	bagI = bagG;
	cout << "bagI:\n" << bagI << endl;
	bagG += 14;
	cout << "bagI:\n" << bagI << endl;	
	
	Bag bagK(10);	
	for (int i = 19; i < 25; i++)
		bagK += i;
	
	cout << "bagG:\n" << bagG << endl;
	cout << "bagK:\n" << bagK << endl;
	bag = bagK + bagG;
	bag += 3;
	bag += 19;
	cout << "bag:\n" << bag << endl;

	cout << "bagI + 7 :\n" << bagI+7 << endl;

	cout << "bagI + bagG:\n" << bagI + bagG << endl;

	if(bag.isEmpty())
	cout << "Bag is empty\n";
	else
	cout << "Bag is Not empty\n";
	
	cout << "Enter an int to look up in the bag: ";
	cin >> n;
	if(bag.contains(n)==true)
	cout << "Bag contains " << n << endl;
	else
	cout << "Bag does not contain " << n << endl; 
	

	cout << "Enter an int to look up it's occurrence in the Bag: ";
	cin >> n;
	if(bag.find(n) > 0)
	cout << "The int "<< n <<" occurrs: " << bag.find(n)  << " times in the bag" << endl;
	else
	cout << "Bag does not contain " << n << endl; 
	
	bag.clear();
	cout << "bag:\n" << bag << endl;
	
	bag = bagI;
	cout << "bag:\n" << bag << endl;
	return 0;
}
