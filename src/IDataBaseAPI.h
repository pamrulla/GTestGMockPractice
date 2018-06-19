/*
 * IDataBaseAPI.h
 *
 *  Created on: Jun 19, 2018
 *      Author: Patan Amrulla Khan
 */

#ifndef IDATABASEAPI_H_
#define IDATABASEAPI_H_

#include <iostream>

using namespace std;

struct Data
{
	int age;
};

class IDataBaseAPI
{
public:
	IDataBaseAPI(){};
	virtual ~IDataBaseAPI(){};
	virtual bool ConnectToDB(string username, string password) {return true;}
	virtual void IsUserMale(bool *obj) { *obj = false; }
	virtual void GetAge(int& age) { age = 0; }
	virtual bool GetCompetetionScores(float *scores) { return false; }
	virtual void UpdateHashCode(int code) {}
	virtual void UpdateNewData(Data *d) {}
};


#endif /* IDATABASEAPI_H_ */
