#include "Member.h"
#include "MemberList.h"
#include "Hike.h"
#include "HikeList.h"
#include "Reservations.h"
#include "HikeReader.h"
#include "MemberReader.h"
#include "ReservationReader.h"
#include "Interface.h"

#include <iostream>

using namespace std;

int main()
{
	MemberList theMemberList;
	getMemberData(theMemberList);
	HikeList theHikeList;
	getHikeData(theHikeList);
	Reservations theReservations;
	getReservationData(theReservations);
	displayMenu();
	processReservation(theHikeList, theMemberList,theReservations);
	return 0;
}