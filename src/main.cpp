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

int main (void) 
{
	StoreInitializer store_init;
	store_init.run();	
	return 0;
}

