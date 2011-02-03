/*
 * @file item.cpp 
 * 
 * @brief An Item is an abstract base class that can be inherited to
 *	  share a common interface type and allow poloymorphic
 *	  behavior of the different Item types. 
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
 * 	- Allows clients to create a new instance of a derived type 
 *	  by calling getNewInstance. 
 *	- Allows client to << a Item.
 * 	- Allows clients to compare Items for equality.
 * 	- Allows clients to compare Items for less than value.
 *	- Allows clients to print the Item.
 *	- Allows cloning an Item.
 * 	- Allows getting the occurence count of an Item.
 * Assumptions:
 * 	- All derived classes of Item implement getNewInstance, and 
 *	  within the method return a dynamically allocated object of
 *	  the derived type. 
 *	- The file stream passed to createNewInstance is open and 
 *	  constains correct format according to Lab 4 specifications.
 */
//--------------------------------------------------------------------

#include "item.h"

//---------------------Default Constructor----------------------------
/**
 * @brief Creates an Item object with default values.
 *
 * Preconditions: None.
 *
 * Postconditions: The data members of this Item have been
 *		   initialized with default values.
 */
Item::Item () : Object ()
{
	my_type  = 0;
	my_name  = "";
	my_title = "";
	my_year  = 0;
	my_count = 0;
}


//---------------------Constructor------------------------------------
/**
 * @brief Creates an Item object with the specified values.
 *
 * Preconditions: None.
 *
 * Postconditions: The data members of this Item have been set to the  
 * 		   specified values.
 *
 * @param type  The type of Item.
 * @param name  The name of this Item.
 * @param title The title of this Item.
 * @param year  The year of this Item.
 * @param count The occurence count of Item.
 */
Item::Item (char type, string name, string title, int year, int count)
	: Object ()
{
	my_type  = type;
	my_name  = name;
	my_title = title;
	my_year  = year;
	my_count = count;
}


//---------------------Destructor-------------------------------------
/**
 * @brief Deletes all dynamically allocated memory. 
 *
 * Preconditions: None. 
 *
 * Postconditions: Resources have been released.
 */
Item::~Item () {}


//---------------------print------------------------------------------
/** 
 * @brief Prints the data members of this Item to the output stream.
 * 
 * Preconditions: my_name and my_title have a terminating character at
 *		  the end of their strings.
 *
 * Postconditions: my_count, my_name, my_title, and my_year have been
 *		   printed to the output stream.
 * 
 * @param output The output stream. 
 */
void Item::print (ostream &output) const
{
	output << my_name  << ", ";
	output << my_title << ", ";
	output << my_year; 
}



//---------------------getName----------------------------------------
/**
 * @brief An accessor method for derived classes to use for 
 *	  comparisons.
 *
 * Preconditions: my_name is initialized.
 *
 * Postconditions: my_name was returned.
 *
 * @return The name of this Item.	
 */
const string Item::getName () const
{
	return my_name;
}


//---------------------getTitle---------------------------------------
/**
 * @brief An accessor method for derived classe to use for 
 *	  comparisons.
 *
 * Preconditions: my_title is initialized.
 *
 * Postconditions: my_title was returned.
 * 
 * @return The title of this Item.
 */	
const string Item::getTitle () const
{
	return my_title;
}


//---------------------getYear----------------------------------------
/**
 * @brief An accessor method for derived classe to use for 
 *	  comparisons.
 *
 * Preconditions: my_year is initialized.
 *
 * Postconditions: my_year was returned.
 * 
 * @return The year of this Item.
 */	
int Item::getYear () const
{	
	return my_year;
}


//---------------------getCount---------------------------------------
/**
 * @brief Returns the number of occurences of this Item.
 * 
 * Preconditions: None. 
 * 
 * Postconditions: Occurence count was returned. 
 * 
 * @return Occurence count of this Item.
 */
int Item::getCount () const
{
	return my_count;
}


//---------------------getType----------------------------------------
/**
 * @brief An accessor method for derived classe to use for cloning.
 *
 * Preconditions: my_type is initialized.
 *
 * Postconditions: my_typ was returned.
 * 
 * @return The year of this Item.
 */	
char Item::getType () const
{
	return my_type;
}

