/*
 * @file rock.h 
 * 
 * @brief This class represents a Rock cd. It is a derived type of
 * 	  CD. 
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
 * 	- Allows clients to get a pointer to a new instance of a 
 *	  Rock CD by calling getNewInstance.
 *	- Allows clients to compare Rock CD's for equality.
 *	- Allows clients to compare Rock CD's for less than value.
 *	- Allows clients to print the Rock CD. 
 *
 * Assumptions:
 * 	- The file stream is open and correctly formatted according to
 *	  Lab 4 specifications. 
 */
//--------------------------------------------------------------------

#ifndef ROCK_H
#define ROCK_H

#include "cd.h"

/**
 * @class Rock
 */
class Rock: public CD {

/**
 * @public
 */
public:

	//---------------------Default Constructor--------------------
	/**
	 * @brief Create a Rock object with default values. 
	 *
	 * Preconditions: None.
	 *	
 	 * Postconditions: This Rock CD was instantiated with 
	 *		   default values. 
	 */
	Rock ();


	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a Rock object with the specified 
	 *	  values.
	 *
	 * Preconditions: None.
	 * 
 	 * Postconditions: The CD super class constructor was called
 	 *		   with the specified values.
	 *
	 * @param type  The type of CD.
	 * @param name  The name of the Rock CD.
	 * @param title The title of the Rock CD. 
	 * @param year  The year of the Rock CD.
	 */
	Rock (char type, string name, string title, int year);


	//---------------------Destructor-----------------------------
	/**
	 * @brief Deletes dynamically allocated memory.
	 *
	 * Preconditions: None.
	 *	
 	 * Postconditions: All resources have been released. 
	 */
	virtual ~Rock ();

		
	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new Rock object. 
	 *	  The objects' data will be set using the provided
 	 *	  file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *	 	  formatted according to Lab 4 specs.
	 *	
	 * Postconditions: A new Rock object was created using
	 *		   the provided file stream, and a pointer
	 *		   to it is returned. 
	 *
	 * @param input The input stream to extract from.
	 * @return Returns a pointer to a new instance of a Rock.
	 */
	virtual Rock * getNewInstance (ifstream &input) const;


	//---------------------operator<------------------------------
	/**
	 * @brief Compares this Rock CD with the_other for less 
	 *	  than value. Comparisons are first made by the
	 *	  artist name, then by year, then by CD title.
	 *
	 * Preconditions: The data members of the base class have 
	 *		  been initialized, and accessor methods are 	
 	 *		  available from the base class to the members 
	 *		  needed for comparisons.
 	 *
	 * Prostconditions: Returns true if this Rock CD is less
	 *		    than the_other.
	 *	 
 	 * @param the_other The other Rock CD to compare with. 
	 * @return Returns true if this Rock CD is less than 
	 *	   the_other, false otherwise. 
 	 */
	virtual bool operator< (const Item &the_other) const; 


	//---------------------operator==-----------------------------
	/**
	 * @brief Compares this Rock CD with the_other Rock CD. 
	 *
	 * Preconditions: The data members of the base class have
 	 *		  been initialized, and accessor methods are
	 *		  available from the base class to the members
	 *		  needed for comparisons.
	 *
	 * Postconditions: Returns true if this Rock CD is equal
	 *		   to the_other.  
	 *
	 * @param the_other The other Rock CD to compare with this 
	 *		    Rock CD.
	 * @return Returns true if the_other is equal to this, false
	 *		   otherwise.
 	 */
	virtual bool operator== (const Item &the_other) const; 

	
	//---------------------print----------------------------------
	/** 
	 * @brief Prints the data members of this Rock CD in the
 	 * 	  output stream.
	 * 
	 * Preconditions: The data members of the base class have
	 *		  been initialized.
	 *
	 * Postconditions: This Rock CD was printed in the output
	 *	           stream. 
 	 */
	virtual void print () const; 

};
#endif /* ROCK_H */

