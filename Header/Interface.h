#ifndef INTERFACE_H
#define INTERFACE_H

#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"

#include <string>

void displayMenu();

void processReservation(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations);

void chooseByLocation(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations);

void chooseByDuration(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations);

void chooseByDifficulty(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations);

void chooseByPrice(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations);

int askIfMember(MemberList& memberList);

int addNewMember(MemberList& memberList);

void makeReservation(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations);

void viewReservation(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations);

void cancelReservation(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations);

void askToReserve(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations);

#endif INTERFACE_H