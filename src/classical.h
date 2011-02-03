/*
 * @file classical.h 
 * 
 * @brief This class represents a Classical. It is a derived type of
 *	  CD.
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
 *	  Classical by calling getNewInstance.
 *	- Allows clients to compare Classical objects for equality.
 *	- Allows clients to compare Classical objects for less than 
	  value.
 *	- Allows clients to print the Classical.
 * 
 * Assumptions:
 * 	- The file stream is open and correctly formatted according
 *	  to Lab 4 specifications. 
 */
//--------------------------------------------------------------------

#ifndef CLASSICAL_H
#define CLASSICAL_H

#include "cd.h"

/**
 * @class Classical
 */
class Classical: public CD {

/**
 * @public
 */
public:

	//---------------------Default Constructor--------------------
	/**
	 * @brief Create a Classical object with default values. 
	 *
	 * Preconditions: None.
	 *	
 	 * Postconditions: This Classical was instantiated with 
	 *		   default values. 
	 */
	Classical ();


	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a Classical object with the specified 
	 *	  values.
	 *
	 * Preconditions: None.
	 * 
 	 * Postconditions: The CD super class constructor was called
 	 *		   with the specified values, and the 
	 *		   composer of this Classical was set. 
	 *
	 * @param type  The type of CD.
	 * @param name  The name of the Classical.
	 * @param title The title of the Classical. 
	 * @param year  The year of the Classical.
	 * @param composer The composer of the Classical. 
	 */
	Classical (char type, string name, 
			string title, int year, string composer);		


	//---------------------Destructor-----------------------------
	/**
	 * @brief Deletes dynamically allocated memory.
	 *
	 * Preconditions: None.
	 *	
 	 * Postconditions: my_composer was deleted and set to NULL.
	 */
	virtual ~Classical ();

		
	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new Classical object CD. 
	 *	  The objects' data will be set using the provided
 	 *	  file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *	 	  formatted according to Lab 4 specs.
	 *	
	 * Postconditions: A new Classical object was created using
	 *		   the provided file stream, and a pointer
	 *		   to it is returned. 
	 *
	 * @param input The input stream to extract from.
	 * @return Returns a pointer to a new instance of a Classical.
	 */
	virtual Classical * getNewInstance (ifstream &input) const;


	//---------------------operator<------------------------------
	/**
	 * @brief Compares this Classical CD with the_other for less 
	 *	  than value. Comparisons are firt made with the 
	 *	  composer, then by artist name, then by year, then by
	 *	  title.
	 *
	 * Preconditions: The data members of the base class have 
	 *		  been initialized, and accessor methods are 	
 	 *		  available from the base class to the members 
	 *		  needed for comparisons.
 	 *
	 * Prostconditions: Returns true if this Classical CD is less
	 *		    than the_other.
	 *	 
 	 * @param the_other The other Classical CD to compare with. 
	 * @return Returns true if this Classical CD is less than 
	 *	   the_other, false otherwise. 
 	 */
	virtual bool operator< (const Object &the_other) const; 


	//---------------------operator==-----------------------------
	/**
	 * @brief Compares this Classical CD with the_other Classical
	 *	  CD. 
	 *
	 * Preconditions: The data members of the base class have
 	 *		  been initialized, and accessor methods are
	 *		  available from the base class to the members
	 *		  needed for comparisons.
	 *
	 * Postconditions: Returns true if this Classical CD is equal
	 *		   to the_other.  
	 *
	 * @param the_other The other Classical CD to compare with 
	 *		    this Classical CD.
	 * @return Returns true if the_other is equal to this, false
	 *		   otherwise.
 	 */
	virtual bool operator== (const Object &the_other) const; 

	
	//---------------------print----------------------------------
	/** 
	 * @brief Prints the data members of this Classical CD in the
 	 * 	  output stream.
	 * 
	 * Preconditions: The data members of the base class have
	 *		  been initialized.
	 *
	 * Postconditions: This Classical CD was printed in the output
	 *	           stream. 
 	 */
	virtual void print () const; 

	
/**
 * @private
 */
private:
	string my_composer;
};
#endif /* CLASSICAL_H */
 
