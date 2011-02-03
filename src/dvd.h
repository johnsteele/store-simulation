/*
 * @file dvd.h 
 * 
 * @brief This class represents a DVD. A DVD is a derived type of
 *	  of Item.  
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date November 11, 2010
 */ 
//--------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows clients to create a new instance of a DVD by calling
 *	  getNewInstance. 
 *	- Allows clients to compare DVD's for equality.
 *	- Allows clients to compare DVD's for less than value.
 *	- Allows clients to print the DVD.
 * 
 * Assumptions:
 * 	- All derived types of DVD implement getNewInstance, and 
 *	  within the method return a pointer to a dynamically 
 *	  allocated object of that derived type. 
 *	- The file stream passed to createNewInstance is open and 
 *	  contains correct format according to Lab 4 specifications. 
 */
//-------------------------------------------------------------------- 
#ifndef DVD_H
#define DVD_H

#include "item.h"

/**
 * @class DVD
 */
class DVD: public Item {

/**
 * @public 
 */
public:

	//---------------------Default Constructor--------------------
	/**
	 * @brief Creates a DVD object with default values.	 	
	 *
	 * Preconditions: None.
	 *	
	 * Postconditions: This DVD was instantiated with default 	
 	 *		   values.  
 	 */
	DVD ();


	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a DVD object with the scpecified values. 
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This DVD was instantiated with the 
	 *		   specified values. 
	 *
	 * @param type  The type of DVD
	 * @param name  The name of the DVD.	
 	 * @param title The title of the DVD.
	 * @param year  The year of the DVD.
	 */
	DVD (char type, string name, string title, int year);

	
	//---------------------Destructor-----------------------------
	/**
	 * @brief Deletes all dynamically allocated memory.
	 *	
 	 * Preconditions: None.	
 	 *
	 * Postconditions: All resources have been released. 
	 */
	virtual ~DVD ();
	

	//---------------------getNewInstance-------------------------
	/**
	 * @brief Returns a pointer to a new instance of a DVD object.
	 *	  The data of the object will be set using the 
	 *	  provided file stream.
	 *
	 * Preconditions: The file stream is open and correctly
 	 *		  formatted according to Lab 4 specifications.
	 *
	 * Postconditions: A pointer to a new DVD obect is returned.
	 *		   The data of the object is set using the
 	 *		   provided file stream.
	 *
	 * @param input The input stream to extract from.
	 * @return Returns a pointer to a new DVD object.
	 */
	virtual DVD * getNewInstance (ifstream &input) const; 


	//---------------------operator<------------------------------
	/**
	 * @brief Compares this DVD with the_other for less than 
	 *	  value. Comparisons are first made with the title, 
	 *	  then the year, and finally the director.
	 *
	 * Preconditions: The data members of the Item base class have 
	 *		  been initialized, and accessor methods are 	
	 *		  available from the base class to the members
	 *		  needed for comparisons.
 	 *
	 * Prostconditions: Returns true if this DVD is less
	 *		    the_other.
	 *	 
 	 * @param the_other The other DVD to compare with this DVD. 
	 * @return Returns true if this DVD is less than the_other, 
	 *	   false otherwise. 
 	 */
	virtual bool operator< (const Object &the_other) const; 


	//---------------------operator==-----------------------------
	/**
	 * @brief Compares this DVD with the_other DVD. 
	 *
	 * Preconditions: The data members of the Item base class have
 	 *		  been initialized.
	 *
	 * Postconditions: Returns true if this DVD is equal to 
	 *		   the_other.
	 *
	 * @param the_other The other DVD to compare with this DVD.
	 * @return Returns true if the_other is equal to this DVD, 
	 *	   false otherwise.
 	 */
	virtual bool operator== (const Object &the_other) const; 
};
#endif /* DVD_H */

