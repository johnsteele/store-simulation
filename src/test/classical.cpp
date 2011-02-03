/*
 * @file classical.cpp
 * 
 * @brief This class represents a Classical. It is a derived type of
 *	  Item.
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
 *      - Allos clients to clone Classical.
 * Assumptions:
 * 	- The file stream is open and correctly formatted according
 *	  to Lab 4 specifications. 
 */
//--------------------------------------------------------------------

#include "classical.h"

//---------------------Default Constructor----------------------------
/**
 * @brief Create a Classical object with default values. 
 *
 * Preconditions: None.
 *	
 * Postconditions: This Classical was instantiated with default
 *		   values. 
 */
Classical::Classical () : Item () 
{
	my_composer = ""; 
}


//---------------------Constructor------------------------------------
/**
 * @brief Creates a Classical object with the specified values.
 *
 * Preconditions: None.
 * 
 * Postconditions: The Item super class constructor was called with
 *		   the specified values, and the composer of this
 *		   Classical was set. 
 *
 * @param type  The type of Classical.
 * @param name  The name of the Classical.
 * @param title The title of the Classical. 
 * @param year  The year of the Classical.
 * @param count The occurence count of the Classical. 
 * @param composer The composer of the Classical. 
 */
Classical::Classical (char type, string name, 
		string title, int year, int count, string composer) 
		: Item (type, name, title, year, count) 
{ 
	my_composer = composer;
}


//---------------------Destructor-------------------------------------
/**
 * @brief Deletes dynamically allocated memory.
 *
 * Preconditions: None.
 *	
 * Postconditions: my_composer was deleted and set to NULL.
 */
Classical::~Classical () {}

	
//---------------------getNewInstance---------------------------------
/**
 * @brief Retuns a pointer to a new Classical object. The objects' 
 *	  data will be set using the provided file stream.
 *	
 * Preconditions: The file stream is open and correctly formatted
 *		  according to Lab 4 specs.
 *	
 * Postconditions: A new Classical object was created using the 
 *	 	   provided file stream, and a pointer to it is
 *		   returned. 
 *
 * @param input The input stream to extract from.
 * @return Returns a pointer to a new instance of a Classical.
 */
Classical * Classical::getNewInstance (ifstream &input) const
{
	char type, test;
	int count, year;
	string name, title, composer;

	input >> type;     
	input.ignore (); input.ignore ();

	// See if there's a quantity.
	test = input.peek ();	
	if (isdigit (test)) {
		input >> count; input.ignore ();
		input.ignore ();
	} else { count = 0; } 
	
	getline (input, name,  ','); 
	input.ignore ();
	getline (input, title, ',');
	input >> year;     input.ignore ();
	getline (input, composer); 
	return new Classical (type,name,title,year,count,composer);
}


//---------------------clone------------------------------------------
/**
 * @brief Clones this Classical.
 * 
 * Preconditions: None.
 * 
 * Postconditions: A pointer to a Classical is returned.
 * 
 * @return The pointer to the cloned object.
 */
Classical * Classical::clone () const
{
	return new Classical (getType(), getName(), 		
				getTitle(), getYear(), getCount(),
					my_composer);
}


//---------------------operator<--------------------------------------
/**
 * @brief Compares this Classical with the_other for less than value.
 *	  Comparisons are firt made with the composer, then by artist 
 *	  name, then by year, then by title.
 *
 * Preconditions: The data members of the base class have been
 *		  initialized, and accessor methods are available from
 *		  the base class to the members needed for 
 *		  comparisons.
 *
 * Prostconditions: Returns true if this Classical is less than 
 *		    the_other.
 *	 
 * @param the_other The other Classical to compare with. 
 * @return Returns true if this Classical is less than the_other,
 *	   false otherwise. 
 */
bool Classical::operator< (const Object &the_other) const
{ 
	try {	
		const Classical &c =
			 dynamic_cast<const Classical &> (the_other);
		
		if ((my_composer < c.my_composer) && 
		    (getName()   < c.getName())   &&
		    (getYear()   < c.getYear())   && 
		    (getTitle()  < c.getTitle())) {
			return true;
		}		

	} catch (exception &e) {
		cout << "Exception: " << e.what () << endl;
	}
 	return false;
}


//---------------------operator==-------------------------------------
/**
 * @brief Compares this Classical with the_other Classical. 
 *
 * Preconditions: The data members of the base class have been 
 *		  initialized, and accessor methods are available from
 *		  the base class to the members needed for comparisons.
 *
 * Postconditions: Returns true if this Classical is equal to 
 *		   the_other.  
 *
 * @param the_other The other Classical to compare with this
 *	            Classical. 
 * @return Returns true if the_other is equal to this, false
 *		   otherwise.
 */
bool Classical::operator== (const Object &the_other) const
{
	try {	
		const Classical &c =
			 dynamic_cast<const Classical &> (the_other);
		
		if ((my_composer == c.my_composer) && 
		    (getName()   == c.getName())   && 
		    (getYear()   == c.getYear())   && 
		    (getTitle()  == c.getTitle())) {
 		    return true;	
		} 

	} catch (exception &e) {
		cout << "Exception: " << e.what () << endl;
	}
	return false; 
}


//---------------------print------------------------------------------
/** 
 * @brief Prints the data members of this Classical in the output 
 *	  stream.
 * 
 * Preconditions: The data members of the base class have been
 *		  initialized.
 *
 * Postconditions: This Classical was printed in the output stream. 
 * 
 * @param output The output stream. 
 */
void Classical::print (ostream &output) const
{
	output << "Classical CD: ";
	Item::print (output);
	output << ", " << my_composer;
}

