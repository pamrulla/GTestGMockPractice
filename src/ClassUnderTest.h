/*
 * ClassUnderTest.h
 *
 *  Created on: Jun 19, 2018
 *      Author: Patan Amrulla Khan
 */

#ifndef CLASSUNDERTEST_H_
#define CLASSUNDERTEST_H_

#include "IDataBaseAPI.h"

class ClassUnderTest {
private:
	IDataBaseAPI* db;

public:
	ClassUnderTest(IDataBaseAPI* _db);
	virtual ~ClassUnderTest();

	bool InitDB(string userName, string password);

	char UpdateGender();

	bool IsTeenage();

	float GetAverageScore(int maxSize);

	void UpdateHashCode()
	{
		//Some method to calculate hash code
		int code = 12345;
		db->UpdateHashCode(code);
	}

	void CreatyDefaultData();
};

#endif /* CLASSUNDERTEST_H_ */
