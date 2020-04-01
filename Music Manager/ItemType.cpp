#include "ItemType.h"

//return music name
string ItemType::GetMusicName() const
{
	return music_name;
}

//return composer
string ItemType::GetComposer() const
{
	return composer;
}

//return singer
string ItemType::GetSinger() const
{
	return singer;
}

//return genre
int ItemType::GetGenre() const
{
	return genre;
}

//return num
int ItemType::GetNum() const
{
	return num;
}

//display music name
void ItemType::DisplayMusicName() const
{
	cout << "\tMusic : " << music_name << endl;
}

//display composer
void ItemType::DisplayComposer() const
{
	cout << "\tComposer : " << composer << endl;
}

//display singer
void ItemType::DisplaySinger() const
{
	cout << "\tSinger : " << singer << endl;
}

//display genre
void ItemType::DisplayGenre() const
{
	cout << "\tGenre : ";
	if (genre == 0)
		cout << "가요" << endl;
	else
		cout << "연주" << endl;
}

//display num
void ItemType::DisplayNum() const
{
	cout << "\tNum : " << num << endl;
}

//display record
void ItemType::DisplayRecord() const
{
	DisplayMusicName();
	DisplayComposer();
	DisplaySinger();
	DisplayGenre();
	DisplayNum();
	cout << endl;
}

//set music name
void ItemType::SetMusicName()
{
	cout << "\tMusic : ";
	cin >> music_name;
}

//set composer
void ItemType::SetComposer()
{
	cout << "\tComposer : ";
	cin >> composer;
}

//set singer
void ItemType::SetSinger()
{
	cout << "\tSinger : ";
	cin >> singer;
}

//set genre
void ItemType::SetGenre()
{
	string tmp;
	while (1)
	{
		cout << "\tGenre(가요, 연주) : ";
		cin >> tmp;
		if (tmp == "가요")
		{
			genre = 0;
			break;
		}
		else if (tmp == "연주")
		{
			genre = 1;
			break;
		}
		else
		{
			cout << "\n\t가요 또는 연주를 입력해주세요\n" << endl;
			continue;
		}
	}
}

//set num
void ItemType::SetNum()
{
	cout << "\tNum : ";
	cin >> num;
}

//set record
void ItemType::SetRecord()
{
	SetMusicName();
	SetComposer();
	SetSinger();
	SetGenre();
	SetNum();
}

//read data from file
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> music_name;
	fin >> composer;
	fin >> singer;
	fin >> genre;
	fin >> num;

	return 1;
};

//write data to file
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << music_name << " ";
	fout << composer << " ";
	fout << singer << " ";
	fout << genre << " ";
	fout << num;
	fout << endl;

	return 1;
}
