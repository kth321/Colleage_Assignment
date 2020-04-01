#include "Application.h"

//Program driver
void Application::Run()
{
	while (1)
	{
		Command = GetCommand();

		switch (Command)
		{
		case 1:
			AddMusic();
			break;
		case 2:
			DeleteMusic();
			break;
		case 3:
			ReplaceMusic();
			break;
		case 4:
			RetrieveMusic();
			break;
		case 5:
			DisplayAllMusic();
			break;
		case 6:
			MakeEmpty();
			break;
		case 7:
			ReadDataFromFile();
			break;
		case 8:
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add music" << endl;
	cout << "\t   2 : Delete music" << endl;
	cout << "\t   3 : Replace music" << endl;
	cout << "\t   4 : Retrieve music" << endl;
	cout << "\t   5 : Print all on screen " << endl;
	cout << "\t   6 : Make empty " << endl;
	cout << "\t   7 : Get from file" << endl;
	cout << "\t   8 : Put to file" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

int Application::AddMusic()
{
	if (List.IsFull())
		// if list is full, return 0
	{
		cout << "List is full, can't add music" << endl;
		return 0;
	}

	ItemType item;		//new item

	item.SetRecord();	//get new item's info
	List.Add(item);		//add new item to ArrayList

	DisplayAllMusic();	//show the result

	return 1;
}

int Application::DeleteMusic()
{
	ItemType item;
	item.SetNum();		//find the target item to delete by num

	if (List.Delete(item))
	{
		cout << "\n\tSuccessfully Delete" << endl;
		DisplayAllMusic();
		
		return 1;
	}
	else
	{
		cout << "\n\tdoesn't exist";
		return 0;
	}
}

int Application::ReplaceMusic() 
{
	ItemType item;
	item.SetNum();		//find the target item by num
	item.SetRecord();	//set new info for item

	if (List.Replace(item)) 
	{
		cout << "\n\tSuccessfully Replaced";
		return 1;
	}
	else 
	{
		cout << "\n\tThe music doesn't exist";
		return 0;
	}
}

int Application::RetrieveMusic() 
{
	ItemType item;		
	item.SetNum();				//find the target item by num

	if (List.Get(item))	
	{
		item.DisplayRecord();	//item initialized with the target item
		return 1;
	}
	else
	{
		cout << "\n\tThe music doesn't exist";
		return 0;
	}
}

void Application::DisplayAllMusic()
{
	ItemType data;

	cout << "\n\tCurrent list\n" << endl;

	List.ResetList();
	int length = List.GetLength();
	int curIndex = List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecord();
		curIndex = List.GetNextItem(data);
	}
}

void Application::MakeEmpty()
{
	List.MakeEmpty();
}

int Application::OpenInFile(char* fileName)
{
	InFile.open(fileName);	

	if (!InFile)
		return 0;
	else	
		return 1;
}

int Application::OpenOutFile(char* fileName)
{
	OutFile.open(fileName);	

	if (!OutFile)	
		return 0;
	else	
		return 1;
}

int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	if (!OpenInFile(filename))
		return 0;

	while (!InFile.eof()) {
		data.ReadDataFromFile(InFile);
		if (InFile.eof())
			break;
		List.Add(data);
	}

	InFile.close();	

	DisplayAllMusic();

	return 1;
}

int Application::WriteDataToFile()
{
	ItemType data;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;

	List.ResetList();

	int length = List.GetLength();
	int curIndex = List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(OutFile);
		curIndex = List.GetNextItem(data);
	}

	OutFile.close();

	return 1;
}