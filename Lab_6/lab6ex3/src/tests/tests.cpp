// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../lab6ex3/Record.h"
#include "../lab6ex3/StringList.h"

struct RecordFixture
{
	CRecord record;

	RecordFixture()
		:record("string")
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Record, RecordFixture)

BOOST_AUTO_TEST_CASE(CanGetValue)
{
	BOOST_CHECK_EQUAL(record.GetValue(), "string");
}

BOOST_AUTO_TEST_CASE(CanGetPointerToNextPrevElement)
{
	BOOST_CHECK_EQUAL(record.GetNext(), shared_ptr<CRecord>());
	BOOST_CHECK_EQUAL(record.GetPrev(), shared_ptr<CRecord>());
}

BOOST_AUTO_TEST_CASE(CanSetPointerToNextPrevElement)
{
	auto it = make_shared<CRecord>("record");
	record.SetNext(it);
	record.SetPrev(it);
	BOOST_CHECK_EQUAL(record.GetNext(), it);
	BOOST_CHECK_EQUAL(record.GetPrev(), it);
}

BOOST_AUTO_TEST_SUITE_END()


struct StringListFixture
{
	CStringList list;
};

BOOST_FIXTURE_TEST_SUITE(StringList, StringListFixture)


BOOST_AUTO_TEST_CASE(CanGetLinkToFirstAndLast)
{
	list.Insert("string");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "string");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "string");	
	list.Insert("2", list.GetLast());
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "2");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "string");
}

BOOST_AUTO_TEST_CASE(CanInsertToBeginByDefault)
{
	list.Insert("string");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "string");
}

BOOST_AUTO_TEST_CASE(CanInsertAfterGivenArg)
{
	list.Insert("1");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "1");
	list.Insert("2", list.GetLast());
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "2");
	list.Insert("4", list.GetLast());
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "4");
	auto it = list.GetLast()->GetPrev();
	list.Insert("3", it);
	BOOST_CHECK_EQUAL(list.GetLast()->GetPrev()->GetValue(), "3");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "4");
}

BOOST_AUTO_TEST_CASE(CanDeleteElem)
{
	{
		list.Insert("1");
		list.Insert("2", list.GetLast());
		list.Insert("4", list.GetLast());
		auto it = list.GetLast()->GetPrev();
		list.Insert("3", it);
		list.Delete(list.GetLast());
		BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "3");
		BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "1");
		list.Delete(list.GetFirst());
		BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "3");
		BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "2");
		list.Delete(list.GetLast());
		BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "2");
		BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "2");
		list.Delete(list.GetLast());
		BOOST_CHECK_EQUAL(list.GetLast(), shared_ptr<CRecord>());
		BOOST_CHECK_EQUAL(list.GetFirst(), shared_ptr<CRecord>());
	}
	{
		list.Insert("1");
		list.Insert("2", list.GetLast());
		list.Insert("3", list.GetLast());
		list.Delete(list.GetLast()->GetPrev());
		BOOST_CHECK_EQUAL(list.GetNext(list.GetFirst())->GetValue(), "3");
	}
}

BOOST_AUTO_TEST_SUITE_END()