/*
 * MockIDataBaseAPI.h
 *
 *  Created on: Jun 19, 2018
 *      Author: Patan Amrulla Khan
 */

#ifndef MOCKIDATABASEAPI_H_
#define MOCKIDATABASEAPI_H_

#include "IDataBaseAPI.h"
#include "gmock/gmock.h"

class MockIDataBaseAPI : public IDataBaseAPI
{
public:
	MOCK_METHOD2(ConnectToDB, bool(string username, string password));
	MOCK_METHOD1(IsUserMale, void(bool *obj));
	MOCK_METHOD1(GetAge, void(int& age));
	MOCK_METHOD1(GetCompetetionScores, bool(float *scores));
	MOCK_METHOD1(UpdateHashCode, void(int code));
	MOCK_METHOD1(UpdateNewData, void(Data *d));
};


#endif /* MOCKIDATABASEAPI_H_ */
