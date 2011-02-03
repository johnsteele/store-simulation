/**
 * @file dvd.cpp 
 * 
 * @brief This class represents a Dvd. A Dvd is a derived type of
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
 * 	- Allows clients to create a new instance of a Dvd by calling
 *	  getNewInstance. 
 *	- Allows clients to compare Dvd's for equality.
 *	- Allows clients to compare Dvd's for less than value.
 *	- Allows clients to print the Dvd.
 *	- Allows clients to clone a Dvd.
 * 
 * Assumptions:
 * 	- All derived types of Dvd implement getNewInstance, and 
 *	  within the method return a pointer to a dynamically 
 *	  allocated object of that derived type. 
 *	- The file stream passed to createNewInstance is open and 
 *	  contains correct format according to Lab 4 specifications. 
 */
//-------------------------------------------------------------------- 

#include "dvd.h"

//---------------------Default Constructor----------------------------
/**
 * @brief Creates a Dvd object with default values.	 	
 *
 * Preconditions: None.
 *	
 * Postconditions: This Dvd was instantiated with default values.  
 */
Dvd::Dvd () : Item () {} 


//---------------------Constructor------------------------------------
/**
 * @brief Creates a Dvd object with the scpecified values. 
 *
 * Preconditions: None.
 *
 * Postconditions: This Dvd was instantiated with the specified 
 *		   values. 
 *
 * @param type  The type of Dvd
 * @param name  The name of the Dvd.	
 * @param title The title of the Dvd.
 * @param year  The year of the Dvd.
 * @param count The occurence count of this Dvd.
 */
Dvd::Dvd (char type, string name, string title, int year, int count) 
		: Item (type, name, title, year, count) {}



//---------------------Destructor-------------------------------------
/**
 * @brief Deletes all dynamically allocated memory.
 *	
 * Preconditions: None.	
 *
 * Postconditions: All resources have been released. 
 */
Dvd::~Dvd () {}


//---------------------print------------------------------------------
/** 
 * @brief Prints the data members of this Item to the output stream.
 * 
 * Preconditions: my_name and my_title have a terminating character 
 *		  at the end of their strings.
 *
 * Postconditions: my_type, my_count, my_name, my_title, and my_year 
 *		   have been printed to the output stream.
 * 
 * @param output The output stream. 
 */
void Dvd::print (ostream &output) const
{
	output << "Dvd : ";
	Item::print (output);	
}


//---------------------getNewInstance---------------------------------
/**
 * @brief Returns a pointer to a new instance of a Dvd object. The 
 *	  data of the object will be set using the provided file
 *	  stream.
 *
 * Preconditions: The file stream is open and correctly formatted 
 *		  according to Lab 4 specifications.
 *
 * Postconditions: A pointer to a new Dvd obect is returned. The data
 *		   of the object is set using the provided file
 *		   stream.
 *
 * @param input The input stream to extract from.
 * @return Returns a pointer to a new Dvd object.
 */
Dvd * Dvd::getNewInstance (ifstream &input) const
{
	
	char type, test;
	int year, count;
	string title, name;	

	input >> type;  
	input.ignore (); input.ignore ();
	
	// See if there's a quantity.
	test = input.peek ();	
	if (isdigit (test)) {
		input >> count; input.ignore ();
		input.ignore ();	
	} 
	else { count = 0; }	
	
	getline (input, name,  ',');
	input.ignore ();
	getline (input, title, ','); 
	input >> year; 
	input.ignore (INT_MAX, '\n'); 
	return new Dvd (type, name, title, year, count); 
}


//---------------------clone------------------------------------------
/**
 * @brief Clones this Dvd.
 * 
 * Preconditions: None.
 * 
 * Postconditions: A pointer to the clone is returned.
 * 
 * @return The pointer to the cloned object.
 */
Dvd * Dvd::clone () const
{
	return new Dvd (getType(), getName(), getTitle(), 
				getYear(), getCount());
}


//---------------------operator<-------------------------------------
/**
 * @brief Compares this Dvd with the_other for less than value. 
 *	  Comparisons are first made with the title, then the year,
 *	  and finally the director.
 *
 * Preconditions: The data members of the Item base class have been
 *		  initialized, and accessor methods are available
 *		  from the base class to the members needed for
 *		  comparisons.
 *
 * Prostconditions: Returns true if this Dvd is less the_other.
 *	 
 * @param the_other The other Dvd to compare with this Dvd. 
 * @return Returns true if this Dvd is less than the_other, false
 *	   otherwise. 
 */
bool Dvd::operator< (const Object &the_other) const
{
	try {
		const Dvd &d = dynamic_cast<const Dvd &> (the_other);

		if ((getTitle() < d.getTitle()) &&
		    (getYear()  < d.getYear())  &&
		    (getName()  < d.getName())) {
			return true;	
		}  

	} catch (exception &e) {
		cout << "Dvd ";
		cout << "Exception: " << e.what() << endl;
	}
	return false;
}


//---------------------operator==-------------------------------------
/**
 * @brief Compares this Dvd with the_other Dvd. 
 *
 * Preconditions: The data members of the Item base class have been
 *		  initialized.
 *
 * Postconditions: Returns true if this Dvd is equal to the_other.
 *
 * @param the_other The other Dvd to compare with this Dvd.
 * @return Returns true if the_other is equal to this Dvd, false
 *	   otherwise.
 */
bool Dvd::operator== (const Object &the_other) const
{
	try {
		const Dvd &d = dynamic_cast<const Dvd &> (the_other);

		if ((getTitle() == d.getTitle()) &&
		    (getYear()  == d.getYear())  &&
		    (getName()  == d.getName())) {
			return true;	
		}  

	} catch (exception &e) {
		cout << "Exception: " << e.what() << endl;
	}
	return false;
}

