#include "MemberList.h"

#include <iostream>
#include <algorithm>

using namespace std;

void MemberList::addMember(const string& firstName,
	const string& lastName)
{
	if (memberList->empty())
	{
		Member newMember(firstName, lastName);
		newMember.setID(MEMBER_ID);
		memberList->insert(newMember);
	}
	else
	{
		Member newMember(firstName, lastName);
		newMember.setID(getLastID() + 1);
		memberList->insert(newMember);
	}
	
}

void MemberList::addMember(const std::string& firstName,
	const std::string& lastName, int points)
{
	if (memberList->empty())
	{
		Member newMember(firstName, lastName);
		newMember.addPoints(points);
		newMember.setID(MEMBER_ID);
		memberList->insert(newMember);
	}
	else
	{
		Member newMember(firstName, lastName);
		newMember.addPoints(points);
		newMember.setID(getLastID() + 1);
		memberList->insert(newMember);
	}
}

int MemberList::getLastID() const
{
	return memberList->rbegin()->getID();
}

int MemberList::getPoints(int memberID) const
{
	auto itr = find_if(memberList->begin(), memberList->end(),
		[memberID](const Member& element) 
		{ return element.getID() == memberID; });

	return itr->getPoints();
}

void MemberList::printMember(int memberID, 
	const string& lastName) const
{	
	auto itr = find_if(memberList->begin(), memberList->end(),
		[memberID, &lastName](const Member& memberInList) {
			return (memberID == memberInList.getID()) &&
				(lastName == memberInList.getLastName()); });

	itr->printMember();
	cout << "\tMembership # " << memberID << "\n";
}

void MemberList::clearList()
{
	memberList->clear();
}

MemberList::~MemberList()
{
	delete memberList;
	memberList = nullptr;
}