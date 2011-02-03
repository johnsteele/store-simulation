
#include <iostream>
using namespace std;

#include "object.h"
#include "customer.h" // verified.
#include "item.h"
#include "cd.h"
#include "dvd.h"
#include "classical.h"
#include "rock.h"
#include "transaction.h"
#include "history_transaction.h"
#include "all_history_transaction.h"
#include "inventory_transaction.h"
#include "purchase_transaction.h"
#include "trade_transaction.h"
#include <queue>
#include <string>
#include <fstream>
#include "bstree.h"
#include <vector>
int main (void) 
{
	vector<Transaction *> *t = new vector<Transaction *>();
	Item *item  = new Rock('R', "Metallica", "Masters of Puppets", 1983, 2);
	Item *item1 = new Classical ('C', "Boring", "Stuff", 1983, 5, "Composer Jack");
	Item *tem   = new DVD();
	Transaction *t1 = new InventoryTransaction ('I');
	Transaction *t2 = new HistoryTransaction(45, 'H');
	Transaction *t3 = new AllHistoryTransaction('A');
	Transaction *t4 = new PurchaseTransaction(321, item, 'P');
	Transaction *t5 = new TradeTransaction(222, item, 'T');
	Transaction *t7 = new PurchaseTransaction(777, tem, 'P'); 
	Transaction *t6 = new PurchaseTransaction(777, item1, 'P');
	t->push_back(t1);
	t->push_back(t2);
	t->push_back(t3);
	t->push_back(t4);
	t->push_back(t5);

	for (int i = 0; i < (long) t->size(); i++)
		cout << "T" << i << ") " << *t->at(i) << endl;

	
	BSTree *c = new BSTree();
	Customer *c1 = new Customer(123, "John");
	c1->addTransaction(t1);
	c->insert(c1);
	c1 = new Customer (321, "Bones");
	c1->addTransaction(t2);
	c1->addTransaction(t4);
	c1->addTransaction(t6);
	c->insert(c1);
	c1 = new Customer (999, "Clinton");
	c1->addTransaction(t3);
	c1->addTransaction(t7);
	c->insert(c1);
	cout << *c;
	/*Customer *dummy = new Customer ();
	Customer *cust = dummy->clone();
	cout << *cust;
	
	Object *t1 = new PurchaseTransaction();
	cust->addTransaction(t1);
	
	cout << *cust; */
/*
	Object *r_dummy = new Rock();
	Object *c_dummy = new Classical();
	Object *d_dummy = new DVD();	

	BSTree *r_tree = new BSTree();	
	BSTree *c_tree = new BSTree();
	BSTree *d_tree = new BSTree();

	ifstream infile ("hw4inventory.txt");

	Object *item;
 
	item = r_dummy->getNewInstance(infile);
	r_tree->insert(item);	
	item = r_dummy->getNewInstance(infile);
	r_tree->insert(item);
	
	item = c_dummy->getNewInstance(infile); 
	c_tree->insert(item);
	item = c_dummy->getNewInstance(infile);
	c_tree->insert(item);
	
	// Bad one.
	item = r_dummy->getNewInstance(infile);
	delete item;

	item = d_dummy->getNewInstance(infile);
	d_tree->insert(item);
 	item = d_dummy->getNewInstance(infile);
	d_tree->insert(item);
*/
	
	
/*	while (infile.peek() != EOF) {
		item = dummy->getNewInstance (infile);
		tree->insert (item);	
	}
*/
/*	cout << *r_tree << endl;
	cout << "-----------------" << endl;
	cout << *c_tree << endl;
	cout << "-----------------" << endl;
	cout << *d_tree << endl;
	cout << "-----------------" << endl;
*/
/*	Object *cust1 = new Customer (1, "apple");
	Object *cust2 = new Customer (0, "ample");
	Object *cust4 = new Customer (9, "beet");
	Object *cust3 = new Customer (5, "bait");


	tree->insert (cust1);
	tree->insert (cust2);
	tree->insert (cust3);
	tree->insert (cust4);
*/
//	cout << *tree << endl;	
/*	Object *obj = new Customer (12, "pimp");
	q.push(cust);
	q.push(obj);
	cout << *q.front() << endl;
	q.pop();
	cout << *q.front() << endl;
	//cout << *cust << endl; */
	return 0;
}

