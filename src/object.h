/**
 * @file object.h 
 * 
 * @brief  A class to represent a Object. Object class is a simple 
 *	   interface that allows other classes to share the same
 *	   type.  
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
 * 	- Allows creating a Object using a specified file.   
 *	- Allows clients to compare Objects for equality.
 * 	- Allows clients to compare Objects for less than value.
 *	- Allows clients to display an Object using <<. 
 * Assumptions:
 * 	- All derived classes of Item implement getNewInstance, and 
 *	  within the method return a dynamically allocated object of
 *	  the derived type. 
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.
 */

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <fstream>
/** 
 * @namespace std
 */
using namespace std;


/**
 * @class Object
 */
class Object {

	//---------------------operator<<-----------------------------
	/**
	 * @brief Overloaded output operator.
	 * 
	 * Preconditions: The object is not NULL.
	 * 
	 * Postconditions: The data members of Object have been sent 
 	 *		   to the output stream.
	 * 
	 * @param output The output stream.
	 * @param item The Object to output.
	 * @return The output stream.
	 */
	friend ostream& operator<< (ostream &output, 
					const Object &object);

public:

	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a default Object. 
	 * 
 	 * Preconditions: None.	
	 *
 	 * Postconditions: this Object was instantiated.  
	 */
	Object ();


	//---------------------Destructor-----------------------------
	/**
	 * @brief Releases all resources obtained by this object. 
	 * 
 	 * Preconditions: None.	
	 *
 	 * Postconditions: All dynamic memory has been released. 
	 */
	virtual ~Object ();

	
	//---------------------getNewInstance-------------------------
	/**
	 * @brief Retuns a pointer to a new instance of the derived
 	 *	  Object. The data of the new object will be set
  	 *	  using the provided file stream.
	 *	
 	 * Preconditions: The file stream is open and correctly 
	 *		  formatted according to Lab 4 specs.  	
	 *
	 * Postconditions: A new object of the derived type was 
	 *		   created using the provided file to set 
	 *		   its data. A pointer to the object was then
	 *		   returned.
	 *
	 * @param input The input stream to extract from.
	 * @return A pointer to a  new instance of the derived
	 *	   Object.
	 */
	virtual Object * getNewInstance (ifstream &input) const = 0; 


	//---------------------print----------------------------------
	/** 
	 * @brief Prints the data members of this Item to the output
	 *	  stream.
	 * 
	 * Preconditions: my_name and my_title have a terminating 
	 *		  character at the end of their strings.
	 *
	 * Postconditions: my_type, my_count, my_name, my_title, 
	 *		   and my_year have been printed to the 
	 *		   output stream.
 	 */
	virtual void print () const = 0; 


	//---------------------operator<------------------------------
	/**
	 * @brief Compares this Object with the_other for less than 
	 *	  value.
	 *
	 * Preconditions: The data members of this Object have been 
	 *	  	  initialized.
 	 *
	 * Prostconditions: Returned true if this Object was less than
	 *		    the_other.
	 *	 
 	 * @param the_other The other Object to compare with this 
 	 *	            Object. 
	 * @return True if this Object is less than the_other, 
	 *	   false otherwise. 
 	 */
	virtual bool operator< (const Object &the_other) const = 0;


	//---------------------operator==-----------------------------
	/**
	 * @brief Compares this Object with the_other Object. 
	 *
	 * Preconditions: The data members of this Object have been 
	 *		  initialized.
	 *
	 * Postconditions: Returned true if this Object was equal to 
	 *		   the_other.
	 *
	 * @param the_other The other Object to compare with this
	 *		    Object.
	 * @return True if the_other is equal to this Object, 
	 *	   false otherwise.
 	 */
	virtual bool operator== (const Object &the_other) const = 0; 
}; 
#endif /* _OBJECT_H_ */

