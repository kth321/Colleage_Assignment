#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "ItemType.h"
#include "ArrayList.h"

#define FILENAMESIZE 1024

class Application
{
private:
	ifstream InFile;
	ofstream OutFile;
	ArrayList List;
	int Command;
public:
	/*
		default constructor
	*/
	Application()
	{
		Command = 0;
	}

	/*
		destructor
	*/
	~Application() { }

	/*
		@brief	program driver
		@pre	program is started
		@post	program is finished
	*/
	void Run();

	/*
		@brief	get command from keyboard
		@pre	none
		@post	none
		@return	command number
	*/
	int GetCommand();

	/*
		@brief	add new music to the list
		@pre	list is initialized
		@post	new music is added to the list
		@return	return 1 if function works well, otherwise return 0
	*/
	int AddMusic();

	/*
		@brief	delete a music
		@pre	list is initialized
		@post	selected music is deleted
		@return	return 1 if function works well, otherwise return 0
	*/
	int DeleteMusic();

	/*
		@brief	replace the music
		@pre	selected music must exist
		@post	music replaced to the selected one
		@return	return 1 if function works well, otherwise return 0
	*/
	int ReplaceMusic();

	/*
		@brief	find the music
		@pre	selected music must exist
		@post	none
		@return	return 1 if function works well, otherwise return 0
	*/
	int RetrieveMusic();

	/*
		@brief	display all musics in the list on screen
		@pre	none
		@post	none
	*/
	void DisplayAllMusic();


	void MakeEmpty();

	/*
		@brief	open a file by file descriptor as an input file
		@pre	file is exist
		@post	open the file
		@param fileName		filename to open the file
		@return	return 1 if function works well, otherwise return 0
	*/
	int OpenInFile(char* fileName);

	/*
		@brief	open a file by file descriptor as an output file
		@pre	file is exist
		@post	open the file
		@param fileName		filename to open the file
		@return	return 1 if function works well, otherwise return 0
	*/
	int OpenOutFile(char* fileName);

	/*
		@brief	open a file as read mode. read all data on the file, and set list by the data
		@pre	file is not opened
		@post	list holds all data from the file
		@return	return 1 if function works well, otherwise return 0
	*/
	int ReadDataFromFile();

	/*
		@brief	open a file as write mode. write all lists into the file
		@pre	file is not opened
		@post	file restored lists
		@return	return 1 if function works well, otherwise return 0

	*/
	int WriteDataToFile();

};

#endif