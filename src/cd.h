/*
 * @file cd.h 
 * 
 * @brief This clas represents a CD. It is a derived type of Item, 
 *	  and it is also an abstract class. It serves as a common 
 *	  interface for all CD types. 
 *
 * @brief CSS 343 - Lab 4
 *
 * @author John Steele  \<steelejr@u.washington.edu\> 
 *  
 * @version 1.0.0
 * @date November 12, 2010
 */ 
//--------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows clients to get a pointer to a new instance of a 
 *	  derived type of CD by calling getNewInstance.
 *	- Allows clients to compare CD's for equality.
 *	- Allows clients to compare CD's for less than value.
 *	- Allows clients to print the CD.
 * 
 * Assumptions:
 * 	- All derived types of CD implement getNewInstance, and 
 *	  within the method return a pointer to a dynamically 
 *	  allocated object of that derived type. 
 *	- The file stream passed to createNewInstance is open and
 *	  contains correct format according to Lab 4 spcifications.
 */
//--------------------------------------------------------------------
 
#ifndef CD_H
#define CD_H

#include "item.h"

/**
 * @class CD
 */
class CD: public Item {

/**
 * @public
 */
public: 
	
	//---------------------Default Constructor--------------------
	/**
	 * @brief Create a CD with default values. 
	 *
	 * Preconditions: None.
	 *	
 	 * Postconditions: This CD was instantiated with default 
	 *	   	   values. 
	 */
	CD ();


	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a CD object with the specified values.
	 *
	 * Preconditions: None.
	 * 
 	 * Postconditions: The Item super class constructor was called
 	 *		   with the specified values.
	 *
	 * @param type  The type of CD.
	 * @param name  The name of the CD.
	 * @param title The title of the CD. 
	 * @param year  The year of the CD. 
	 */
	CD (char type, string name, string title, int year);		


	//---------------------Destructor-----------------------------
	/**
	 * @brief Deletes dynamically allocated memory.
	 *
	 * Preconditions: None.
	 *	
 	 * Postconditions: All resources have been released. 
	 */
	virtual ~CD ();

		
	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new instance of the derived 
 	 *	  CD. The new objects' data will be set using the
 	 *	  provided file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *	 	  formatted according to Lab 4 specs.
	 *	
	 * Postconditions: A new object of the derived type is created
 	 *		   using the provided file stream, and a 
	 *		   pointer to it is returned. 
	 *
	 * @param input The input stream to extract from.
	 * @return Returns a pointer to a new instance of the derived
	 *	   CD.
	 */
	virtual CD * getNewInstance (ifstream &input) const = 0;


	//---------------------operator<------------------------------
	/**
	 * @brief Compares this CD with the_other for less than 
	 *	  value. 
	 *
	 * Preconditions: The data members of the Item base class have 
	 *		  been initialized, and accessor methods are 	
 	 *		  available from the base class to the members 
	 *		  needed for comparisons.
 	 *
	 * Prostconditions: Returns true if this CD is less than
	 *		    the_other.
	 *	 
 	 * @param the_other The other CD to compare with this CD. 
	 * @return Returns true if this CD is less than the_other, 
	 *	   false otherwise. 
 	 */
	virtual bool operator< (const Item &the_other) const = 0; 


	//---------------------operator==-----------------------------
	/**
	 * @brief Compares this CD with the_other CD. 
	 *
	 * Preconditions: The data members of the Item base class have
 	 *		  been initialized, and accessor methods are
	 *		  available from the base class to the members
	 *		  needed for comparisons.
	 *
	 * Postconditions: Returns true if this CD is equal to 
	 *		   the_other.  
	 *
	 * @param the_other The other CD to compare with this CD.
	 * @return Returns true if the_other is equal to this CD, 
	 *	   false otherwise.
 	 */
	virtual bool operator== (const Item &the_other) const = 0; 

	
	//---------------------print----------------------------------
	/** 
	 * @brief Prints the data members of this CD in the output	
 	 *	  stream.
	 * 
	 * Preconditions: The data members of the base class have
	 *		  been initialized.
	 *
	 * Postconditions: This CD was printed in the output stream. 
 	 */
	virtual void print () const; 
};
#endif /* CD_H */

