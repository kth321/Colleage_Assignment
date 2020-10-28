#include "ArrayList.h"

//make list empty
void ArrayList::MakeEmpty()
{
	Length = 0;
}

//return the number of lists
int ArrayList::GetLength()
{
	return Length;
}

//check capacity
bool ArrayList::IsFull()
{
	if (Length > MAX_LENGTH - 1)
		return true;
	return false;
}

//add new item
int ArrayList::Add(ItemType data)
{
	if (!IsFull())
	{
		Array[Length] = data;
		Length++;
		return 1;
	}
	return 0;
}

//reset list, initialized current point to -1
void ArrayList::ResetList()
{
	Currentpointer = -1;
}

//get next item
int ArrayList::GetNextItem(ItemType& data)
{
	Currentpointer++;
	if (Currentpointer == MAX_LENGTH)
		return -1;
	data = Array[Currentpointer];

	return Currentpointer;
}

//replace the item
int ArrayList::Replace(ItemType data)
{
	for (Currentpointer = 0; Currentpointer < Length; ++Currentpointer)
	{
		if (data == Array[Currentpointer])
		{
			Array[Currentpointer] = data;
			return 1;
		}
	}
	return -1;
}

//delete the item
int ArrayList::Delete(ItemType data)
{
	bool isFind = false;
	for (Currentpointer = 0; Currentpointer < Length; Currentpointer++)
	{
		if (!isFind)
		{
			if (data == Array[Currentpointer])
				isFind = true;
		}
		else
			Array[Currentpointer - 1] = Array[Currentpointer];
	}
	Length--;

	if (isFind)
		return 1;
	else
		return 0;
}

//get the item
int ArrayList::Get(ItemType& data)
{
	for (Currentpointer = 0; Currentpointer < Length; Currentpointer++)
	{
		if (data == Array[Currentpointer])
		{
			data = Array[Currentpointer];
			return 1;
		}
	}
	return -1;
}
