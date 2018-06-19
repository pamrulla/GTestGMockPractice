/*
 * ClassUnderTest.cpp
 *
 *  Created on: Jun 19, 2018
 *      Author: Patan Amrulla Khan
 */

#include "ClassUnderTest.h"

ClassUnderTest::ClassUnderTest(IDataBaseAPI* _db): db(_db) {
	// TODO Auto-generated constructor stub

}

ClassUnderTest::~ClassUnderTest() {
	// TODO Auto-generated destructor stub
}

bool ClassUnderTest::InitDB(string userName, string password) {
	if(db->ConnectToDB(userName, password))
	{
		return true;
	}
	else
	{
		return false;
	}
}

char ClassUnderTest::UpdateGender()
{
	bool isMale;
	char gender;

	db->IsUserMale(&isMale);

	if(isMale)
		gender = 'M';
	else
		gender = 'F';

	return gender;
}

bool ClassUnderTest::IsTeenage() {
	int age;
	db->GetAge(age);
	if(age < 20 && age > 12)
		return true;
	else
		return false;
}

float ClassUnderTest::GetAverageScore(int maxSize) {
	float scores[maxSize] = {0};
	if(db->GetCompetetionScores(scores))
	{
		float sum = 0;
		for(int i = 0; i < maxSize; i++)
		{
			sum += scores[i];
		}
		return sum / maxSize;
	}
	else
	{
		return 0.0;
	}
}

void ClassUnderTest::CreatyDefaultData()
{
	Data d{-1};
	db->UpdateNewData(&d);
}
