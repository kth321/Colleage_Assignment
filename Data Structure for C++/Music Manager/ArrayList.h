#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include "ItemType.h"

#include <iostream>
#include <string>

#define MAX_LENGTH 10

/*
	List for managing ItemType
*/
class ArrayList
{
private:
	ItemType Array[MAX_LENGTH];
	int Length;
	int Currentpointer;
public:
	/*
		default constructor
	*/
	ArrayList()
	{
		Length = 0;
		ResetList();
	}

	/*
		destructor
	*/
	~ArrayList() {}

	/*
		@brief	make list empty
		@pre	list is initialized
		@post	list is cleared
	*/
	void MakeEmpty();

	/*
		@brief	get a number of list of list
		@pre	none
		@post	none
		@return	return length(number of records)
	*/
	int GetLength();

	/*
		@brief	check if the list is full
		@pre	none
		@post	none
		@return	return true if list is full, otherwise return false
	*/
	bool IsFull();

	/*
		@brief	add new record to the list
		@pre	list is initialized
		@post	new record is added to the list
		@return	return 1 if function works well, otherwise return 0
	*/
	int Add(ItemType data);

	/*
		@brief	initialize list iterator
		@pre	list is initialized
		@post	iterator is reset
	*/
	void ResetList();

	/*
		@brief	move iterator to the next record and get the item
		@pre	list and iterator is not initialized
		@post	iterator moves to the next item
		@param data		get current item
		@return	index of moved iterator's item, otherwise return -1
	*/
	int GetNextItem(ItemType& data);

	/*
		@brief	delete current item
		@pre	list and iterator is not initialized
		@post	delete item and reduce length
		@param data		deleting item
		@return	return 1 if function works well, otherwise return 0
	*/
	int Delete(ItemType data);

	/*
		@brief	replace item
		@pre	list exist and is not been initialized
		@post	replace the item
		@param data		replacement
		@return	return 1 if function works well, otherwise return 0
	*/
	int Replace(ItemType data);

	/*
		@brief	get currentpointer
		@pre	list is initialized
		@post	put current pointer's data to param data
		@param data		temporary val to get item
		@return	return 1, otherwise return -1
	*/
	int Get(ItemType& data);
};

#endif