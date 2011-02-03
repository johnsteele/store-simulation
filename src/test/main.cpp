/**
 * @file main.cpp 
 * 
 * @brief This is the main driver for Lab 4. It creates a
 *	  StoreInitializer the passes control over to it.
 *	  When the StoreInitializer is finished initializing the
 *	  store it then passes control over to its StoreManager
 * 	  to process the transactions. 
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date November 11, 2010
 */ 
//--------------------------------------------------------------------

#include "store_initializer.h"

/**
 * @brief Starts the store initialization process.
 * 
 * @return Zero for success. 
 */
int main (void) 
{
	// StoreInitializer store_init;
	// store_init.run();	
/*	ifstream input;
	input.open ("hw4commands.txt");
	Object *dummy = new HistoryTransaction ();
	cout << *dummy->getNewInstance (input) << endl;
*/

	for (i = 0; i < count; i++) {
		/* code */		
		cout << "This is a test " << endl;
	}
/*	HashTable *t = new HashTable ();

	t->add ('P', new PurchaseTransaction (123, NULL, 'P'));
	t->add ('T', new TradeTransaction (123, NULL, 'T'));
	t->add ('H', new HistoryTransaction (124, 'H'));
	t->add ('A', new AllHistoryTransaction ('A')); 

	Object *p = t->get ('P');
	Object *tp = t->get ('T');
	Object *h = t->get ('H');
	Object *a = t->get ('A');  

	cout << *p << endl;
	cout << *tp << endl;
	cout << *h << endl;
	cout << *a << endl;  */
	return 0;
}

