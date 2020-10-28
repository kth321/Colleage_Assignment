#ifndef _ITEMTYPE_H_
#define _ITEMTYPE_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
	class for ItemType
*/
class ItemType
{
private:
	string music_name;
	string composer;
	string singer;
	int genre;
	int num;
public:
	/*
		default constructor
	*/
	ItemType()
	{
		music_name = "is real";
		composer = "";
		singer = "";
		genre = 0;
		num = 0;
	}

	/*
		destructor
	*/
	~ItemType() { }

	/*
		@brief	get music name
		@pre	music name is set
		@post	none
		@return name
	*/
	string GetMusicName()	const;

	/*
		@brief	get composer 
		@pre	composer is set
		@post	none
		@return	composer
	*/
	string GetComposer() const;

	/*
		@brief	get singer 
		@pre	singer is set
		@post	none
		@return singer
	*/
	string GetSinger() const;

	/*
		@brief	get genre
		@pre	genre is set
		@post	none
		@return	genre
	*/
	int GetGenre() const;

	/*
		@brief	get num
		@pre	num is set
		@post	none
		@return num
	*/
	int GetNum() const;

	/*
		@brief	display music name
		@pre	none
		@post	music name is on screen
	*/
	void DisplayMusicName() const;

	/*
		@brief	display composer
		@pre	none
		@post	composer is on screen
	*/
	void DisplayComposer() const;

	/*
		@brief	display singer
		@pre	none
		@post	singer is on screen
	*/
	void DisplaySinger() const;

	/*
		@brief	display genre
		@pre	none
		@post	genre is on screen
	*/
	void DisplayGenre() const;

	/*
		@brief	display num
		@pre	none
		@post	num is on screen
	*/
	void DisplayNum() const;

	/*
		@brief	display record
		@pre	none
		@post	record is on screen
	*/
	void DisplayRecord() const;

	/*
		@brief	set music name
		@pre	no spacing
		@post	music name is set
	*/
	void SetMusicName();

	/*
		@brief	set composer
		@pre	no spacing
		@post	composer is set
	*/
	void SetComposer();

	/*
		@brief	set singer
		@pre	no spacing
		@post	singeris set
	*/
	void SetSinger();

	/*
		@brief	set genre
		@pre	none
		@post	genre is set
	*/
	void SetGenre();

	/*
		@brief	set num
		@pre	none
		@post	num is set
	*/
	void SetNum();

	/*
		@brief	set record
		@pre	none
		@post	record is set
	*/
	void SetRecord();

	/*
		@brief	Read a record from file
		@pre	target file is opened
		@post	music record is set
		@param fin		file descriptor
		@return	return 1 if function works well, otherwise return 0
	*/
	int ReadDataFromFile(ifstream& fin);

	/*
		@brief	Write a record to file
		@pre	target file is opened, list is initialized
		@post	music record is stored in file
		@param fout		file descriptor
		@return	return 1 if function works well, otherwise return 0
	*/
	int WriteDataToFile(ofstream& fout);

	bool operator==(const ItemType& _item) {
		if (num == _item.GetNum())
			return true;
		return false;
	}
	void operator=(const ItemType& _item) {
		num = _item.GetNum();
		music_name = _item.GetMusicName();
		composer = _item.GetComposer();
		singer = _item.GetSinger();
		genre = _item.GetGenre();
		num = _item.GetNum();
	}
};

#endif