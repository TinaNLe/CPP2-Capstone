#include "Member.h"
#include "MemberList.h"
#include "Reservations.h"

#include <set>

using namespace std;

MemberList::MemberList(const MemberList& otherMemberList)
{
	memberList = new set<Member>(*otherMemberList.memberList);
}

MemberList& MemberList::operator=(const MemberList& otherMemberList)
{
	if (&otherMemberList == this)
	{
		cerr << "Attempted assignment to itself." << endl;
	}
	else
	{
		*memberList = set<Member>(*otherMemberList.memberList);
	}
	return *this;
}

Reservations::Reservations(const Reservations& otherReservations)
{
	first = nullptr;
	last = nullptr;
	count = 0;

	if (otherReservations.count != 0)
	{
		first = new Node();
		last = new Node();
		Node* current = otherReservations.first;

		while (current != nullptr)
		{
			addReservation(current->getMemberID(),
				current->getHikeName());
			current = current->getNext();
		}
	}
}

Reservations& Reservations::operator=(
	const Reservations& otherReservations)
{
	if (&otherReservations == this)
	{
		cerr << "Attempted assignment to itself." << endl;
	}
	else
	{
		int otherCount = otherReservations.count;

		if (otherCount == 0)
		{
			clearList();
		}
		else if (count == 0)
		{
			copyCallingObjIsEmpty(otherReservations);
		}
		else if (count == otherCount)
		{
			copyObjectsSameLength(otherReservations);
		}
		else if (count > otherCount)
		{
			copyCallingObjLonger(otherReservations);
		}
		else if (count < otherCount)
		{
			copyCallingObjShorter(otherReservations);
		}
	}
	return *this;
}

void Reservations::copyCallingObjIsEmpty(
	const Reservations& otherReservations)
{
	Node* current = otherReservations.first;
	while (current != nullptr)
	{
		addReservation(current->getMemberID(), current->getHikeName());
		current = current->getNext();
	}
	count = otherReservations.count;
}

void Reservations::copyObjectsSameLength(
	const Reservations& otherReservations)
{
	Node* current = otherReservations.first;
	Node* thisCurrent = first;

	while (current != nullptr)
	{
		thisCurrent->setReservationNo(current->getReservation());
		thisCurrent->setMemberID(current->getMemberID());
		thisCurrent->setHikeName(current->getHikeName());
		current = current->getNext();
		thisCurrent = thisCurrent->getNext();
	}
}

void Reservations::copyCallingObjLonger(
	const Reservations& otherReservations)
{
	Node* current = otherReservations.first;
	Node* thisCurrent = first;

	while (current != nullptr)
	{
		thisCurrent->setReservationNo(current->getReservation());
		thisCurrent->setMemberID(current->getMemberID());
		thisCurrent->setHikeName(current->getHikeName());
		current = current->getNext();
		thisCurrent = thisCurrent->getNext();
	}

	last = thisCurrent->getPrev();
	last->setNext(nullptr);

	Node* temp = thisCurrent;

	while (thisCurrent != nullptr)
	{
		delete temp;
		thisCurrent = thisCurrent->getNext();
		temp = thisCurrent;
	}
	temp = nullptr;
	count = otherReservations.count;
}

void Reservations::copyCallingObjShorter(
	const Reservations& otherReservations)
{
	Node* current = otherReservations.first;
	Node* thisCurrent = first;

	while (thisCurrent != nullptr)
	{
		thisCurrent->setReservationNo(current->getReservation());
		thisCurrent->setMemberID(current->getMemberID());
		thisCurrent->setHikeName(current->getHikeName());
		current = current->getNext();
		thisCurrent = thisCurrent->getNext();
	}

	while (current != nullptr)
	{
		addReservation(current->getMemberID(), current->getHikeName());
		current = current->getNext();
	}

	count = otherReservations.count;
}