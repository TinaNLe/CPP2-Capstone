#include "Reservations.h" 

#include <iostream>
#include <iomanip>

using namespace std;

int Reservations::addReservation(int memberID, 
	const std::string& hikeName)
{
	if (first == nullptr)
	{
		first = new Node(memberID, hikeName, nullptr, nullptr);
		first->setReservationNo(RESERVATION_NUMBER);
		last = first;
	}
	else
	{
		last->setNext(new Node(memberID, hikeName, last, nullptr));
		last = last->getNext();
		last->setReservationNo(last->getPrev()->getReservation() + 1);
	}

	++count;
	return last->getReservation();
}

void Reservations::cancelReservation(int reservation)
{
	if (count == 1)
	{
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else
	{
		Node* nodeToDelete = findReservation(reservation);

		if (first == nodeToDelete)
		{
			first = first->getNext();
			first->setPrev(nullptr);
		}
		else if (last == nodeToDelete)
		{
			last = last->getPrev();
			last->setNext(nullptr);
		}
		else
		{
			nodeToDelete->getNext()->setPrev(nodeToDelete->getPrev());
			nodeToDelete->getPrev()->setNext(nodeToDelete->getNext());
		}
		delete nodeToDelete;
		nodeToDelete = nullptr;
		--count;
	}
}

void Reservations::printReservation(int reservation, 
	const HikeList& hikeList, const MemberList& memberList) const
{
	Node* reservationNode = findReservation(reservation); 

	hikeList.printByHikeName(reservationNode->getHikeName()); 

	int memberID = reservationNode->getMemberID(); 
	int points = memberList.getPoints(memberID);

	if (points != 0)
	{
		double price = hikeList.getPrice(reservationNode->getHikeName());
		double discount = price - (points / 100);
		cout << "\n\tDiscounted price using points: $" << discount;
		cout << "\n";
	}
}

void Reservations::clearList()
{
	Node* current = first; 
	
	while (current != nullptr) // maybe for loop?
	{
		first = first->getNext();
		delete current; 
		current = first;
	}

	last = nullptr;
	count = 0;
}

Reservations::~Reservations()
{
	clearList(); 
}

Node* Reservations::findReservation(int reservation) const
{
	Node* current = first;

	while (current->getReservation() != reservation)
	{
		current = current->getNext();
	}

	return current;
}

