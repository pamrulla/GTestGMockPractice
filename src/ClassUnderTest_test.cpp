/*
 * ClassUnderTest_test.cpp
 *
 *  Created on: Jun 19, 2018
 *      Author: Patan Amrulla Khan
 */

#include "ClassUnderTest.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockIDataBaseAPI.h"

using ::testing::_;
using ::testing::Return;
using ::testing::NotNull;
using ::testing::SetArgPointee;
using ::testing::SetArgReferee;
using ::testing::SetArrayArgument;
using ::testing::DoAll;

class DataBaseAPITestFixture : public ::testing::Test
{
public:
	MockIDataBaseAPI mockDb;
	ClassUnderTest* obj = nullptr;
	void SetUp()
	{
		obj = new ClassUnderTest(&mockDb);
	}

	void TearDown()
	{
		delete obj;
	}
};

TEST_F(DataBaseAPITestFixture, ConnectionToDBSuccess) {
		EXPECT_CALL(mockDb, ConnectToDB(_, _))
	.Times(1)
	.WillOnce(Return(true));

	bool retVal = obj->InitDB("testUser", "testpassword");

	ASSERT_EQ(retVal, true);
}

TEST_F(DataBaseAPITestFixture, ConnectionToDBFailure) {
	bool ExpectedValue = true;

	EXPECT_CALL(mockDb, ConnectToDB(_, _))
	.Times(1)
	.WillOnce(Return(ExpectedValue));

	bool retVal = obj->InitDB("testUser", "testpassword");

	ASSERT_EQ(retVal, ExpectedValue);
}

TEST_F(DataBaseAPITestFixture, UpdateMaleUserGender)
{
	EXPECT_CALL(mockDb, IsUserMale(NotNull()))
	.Times(1)
	.WillOnce(SetArgPointee<0>(true));

	char retVal = obj->UpdateGender();

	EXPECT_EQ(retVal, 'M');

}

TEST_F(DataBaseAPITestFixture, UpdateFemaleUserGender)
{
	EXPECT_CALL(mockDb, IsUserMale(NotNull()))
	.Times(1)
	.WillOnce(SetArgPointee<0>(false));

	char retVal = obj->UpdateGender();

	EXPECT_EQ(retVal, 'F');

}

TEST_F(DataBaseAPITestFixture, CheckingTeenageForAge8)
{
	EXPECT_CALL(mockDb, GetAge(_))
	.Times(1)
	.WillOnce(SetArgReferee<0>(8));

	bool retVal = obj->IsTeenage();

	EXPECT_EQ(retVal, false);

}

TEST_F(DataBaseAPITestFixture, CheckingTeenageForAge18)
{
	EXPECT_CALL(mockDb, GetAge(_))
	.Times(1)
	.WillOnce(SetArgReferee<0>(18));

	bool retVal = obj->IsTeenage();

	EXPECT_EQ(retVal, true);

}

TEST_F(DataBaseAPITestFixture, CheckingTeenageForAge28)
{
	EXPECT_CALL(mockDb, GetAge(_))
	.Times(1)
	.WillOnce(SetArgReferee<0>(28));

	bool retVal = obj->IsTeenage();

	EXPECT_EQ(retVal, false);

}

TEST_F(DataBaseAPITestFixture, CalculatingAverageScoresSuccess)
{
	int maxSize = 5;
	float scores[] = { 50.0f, 20.0f, 60.0f, 80.0f, 100.0f};
	EXPECT_CALL(mockDb, GetCompetetionScores(NotNull()))
	.Times(1)
	.WillOnce(DoAll(SetArrayArgument<0>(scores, scores+maxSize), Return(true)));

	float retVal = obj->GetAverageScore(maxSize);

	EXPECT_FLOAT_EQ(retVal, 62.0f);

}

TEST_F(DataBaseAPITestFixture, CalculatingAverageScoresFailure)
{
	int maxSize = 5;
	float scores[] = { 50.0f, 20.0f, 60.0f, 80.0f, 100.0f};
	EXPECT_CALL(mockDb, GetCompetetionScores(NotNull()))
	.Times(1)
	.WillOnce(DoAll(SetArrayArgument<0>(scores, scores+maxSize), Return(false)));

	float retVal = obj->GetAverageScore(maxSize);

	EXPECT_FLOAT_EQ(retVal, 0.0f);

}

TEST_F(DataBaseAPITestFixture, NewHashCodeTest)
{
	int code = 12345;
	int actualCode;

	EXPECT_CALL(mockDb, UpdateHashCode(_))
	.Times(1)
	.WillOnce(::testing::SaveArg<0>(&actualCode));

	obj->UpdateHashCode();

	EXPECT_FLOAT_EQ(actualCode, code);

}

TEST_F(DataBaseAPITestFixture, DefaultDataTest)
{
	Data actualCode{};

	EXPECT_CALL(mockDb, UpdateNewData(_))
	.Times(1)
	.WillOnce(::testing::SaveArgPointee<0>(&actualCode));

	obj->CreatyDefaultData();

	EXPECT_FLOAT_EQ(actualCode.age, -1);

}
