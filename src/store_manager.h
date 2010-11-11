/**
 * @file store_manager.h 
 * 
 * @brief StoreManager class is responsible for containing the store
 *	  customer, inventory, and transaction objects. The 
 *	  StoreManager also processes the transactions.
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date November 9, 2010
 */ 
//--------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows adding a Customer object.
 *	- Allows adding an Inventory object.
 * 	- Allows adding a Transaction object.
 *	- Allows processing the Transactions.  
 * 
 * Assumptions:
 * 	- 
 *
 */
//--------------------------------------------------------------------

#ifndef STORE_MANAGER_H
#define STORE_MANAGER_H

#include "customer.h"
#include "item.h"
#include "transaction.h"


/**
 * @class StoreManager
 */
class StoreManager {

/**
 * @public
 */
public:
	//-------------------------------------------------------------------
	/**
 	 *
 	 */
	StoreManager ();

	
	//-------------------------------------------------------------------
	/**
 	 *
 	 */
	~StoreManager ();


/**
 * @private:
 */

};
#endif /* STORE_MANGER_H */

