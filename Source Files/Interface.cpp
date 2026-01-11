#include "Interface.h"
#include <string>

using namespace std;

void displayMenu()
{
	string ast = string(51, '*');
	string blank = string(16, ' ');

	// Display the header
	cout << ast << "\n"
		<< blank << "HIKING IN THE US\n"
		<< ast << "\n\n";

	cout << "\t1. Browse by location\n"
		<< "\t2. Browse by duration\n"
		<< "\t3. Browse by difficulty\n"
		<< "\t4. Browse by price\n"
		<< "\t5. Make a reservation\n"
		<< "\t6. View reservation\n"
		<< "\t7. Cancel reservation\n"
		<< "\t8. Exit\n";
}

void processReservation(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations)
{
	cout << "\nPlease make a selection: ";
	int userSelection = 0;
	cin >> userSelection;

	while (userSelection != 8)
	{
		if (userSelection == 1)
		{
			chooseByLocation(hikeList,
				memberList, reservations);
		}
		else if (userSelection == 2)
		{
			chooseByDuration(hikeList,
				memberList, reservations);
		}
		else if (userSelection == 3)
		{
			chooseByDifficulty(hikeList,
				memberList, reservations);
		}
		else if (userSelection == 4)
		{
			chooseByPrice(hikeList,
				memberList, reservations);
		}
		else if (userSelection == 5)
		{
			makeReservation(hikeList,
				memberList, reservations);
		}
		else if (userSelection == 6)
		{
			viewReservation(hikeList,
				memberList, reservations);
		}
		else if (userSelection == 7)
		{
			cancelReservation(hikeList,
				memberList, reservations);
		}

		system("Pause");
		cout << "\n";
		displayMenu();

		cout << "\nPlease make a selection: ";
		cin >> userSelection;
	}
	cout << "\nThank you for visiting!\n\n";
	system("Pause");
}

void chooseByLocation(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations)
{
	cout << "\n";
	hikeList.printAllLocations();

	cout << "\nChoose a location: ";
	string location;
	cin >> location;
	cout << "\n";
	hikeList.printByLocation(location);

	askToReserve(hikeList, memberList, reservations);
}

void chooseByDuration(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations)
{
	cout << "\n\t(days)\n";
	hikeList.printByDuration();

	cout << "\nHow many days are you considering? ";
	int duration = 0;
	cin >> duration;
	cout << "\n";
	hikeList.printByDuration(duration);

	askToReserve(hikeList, memberList, reservations);
}

void chooseByDifficulty(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations)
{
	cout << "\nChoose difficulty level: \n";
	cout << "\n\te. easy\n\tm. moderate\n\ts. strenuous\n\n";
	cout << "Your choice: ";
	char difficulty = 'e';
	cin >> difficulty;

	cout << "\n\t(difficulty level)\n";
	hikeList.printByDifficulty(difficulty);

	cout << "\n";
	askToReserve(hikeList, memberList, reservations);
}

void chooseByPrice(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations)
{
	cout << "\n";
	hikeList.printByPrice();
	cout << "\n";
	askToReserve(hikeList, memberList, reservations);
}


int askIfMember(MemberList& memberList)
{
	cout << "\nAre you a member? (y/n) ";
	char ifMemberInput = '\0';
	cin >> ifMemberInput;

	if (ifMemberInput == 'y')
	{
		cout << "\nWhat is your member ID number? ";
		int memberIDInput = 0;
		cin >> memberIDInput;
		cout << "\nWhat is your last name? ";
		string lastNameInput;
		cin >> lastNameInput;

		cout << "\n";
		memberList.printMember(memberIDInput, lastNameInput);

		return memberIDInput;
	}
	else
	{
		return addNewMember(memberList);
	}
}

int addNewMember(MemberList& memberList)
{
	// Prompt a user to input one's
	// first name and last name.
	cout << "\n\tLet's add you to the member list!";
	cout << "\n\t\tWhat is your first name? ";
	string firstNameInput;
	cin >> firstNameInput;
	cout << "\t\tWhat is your last name? ";
	string lastNameInput;
	cin >> lastNameInput;

	// Add to the member list.
	memberList.addMember(firstNameInput, lastNameInput);
	int memberID = memberList.getLastID();

	// Display the member ID.
	cout << "\n\tWelcome to the club!";
	cout << "\n\t\tYour member ID number is: " << memberID
		<< "\n";

	// Return the member ID.
	return memberID;
}

void makeReservation(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations)
{
	int memberID = askIfMember(memberList);

	cout << "\nWhich hike would you like to reserve (hike name)? ";
	string hikeNameInput;
	cin >> hikeNameInput;
	cout << "\n";
	hikeList.printByHikeName(hikeNameInput);

	int points = memberList.getPoints(memberID);
	if (points != 0)
	{
		cout << "\n\tDiscounted price using points: $"
			<< hikeList.getPrice(hikeNameInput) -
			(points / 100.0);
		cout << "\n";
	}

	int reservationNo =
		reservations.addReservation(memberID, hikeNameInput);
	cout << "\n\tBefore proceeding, please make a "
		<< "note of your reservation number."
		<< "\n\t  Reservation #: " << reservationNo;
	cout << "\n\n( *** Will continue to "
		<< "scheduling and payment. *** )\n\n";
}

void viewReservation(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations)
{
	cout << "\nEnter reservation #: ";
	int reservationNo = 0;
	cin >> reservationNo;
	cout << "\n";

	reservations.printReservation(reservationNo,
		hikeList, memberList);
	cout << "\n";
}

void cancelReservation(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations)
{
	cout << "\nEnter reservation #: ";
	int reservationNo = 0;
	cin >> reservationNo;
	cout << "\n";

	reservations.printReservation(reservationNo,
		hikeList, memberList);

	cout << "\nAre you sure you want to "
		<< "cancel this reservation? (y/n) ";
	char cancelConfirmation = '\0';
	cin >> cancelConfirmation;

	if (cancelConfirmation == 'y')
	{
		reservations.cancelReservation(reservationNo);

		cout << "\nReservation #" << reservationNo
			<< " has been canceled.\n";
	}
	cout << "\n";
}

void askToReserve(const HikeList& hikeList,
	MemberList& memberList, Reservations& reservations)
{
	cout << "Would you like to make a reservation? (y/n) ";
	char reserveConfirmation = '\0';
	cin >> reserveConfirmation;

	if (reserveConfirmation == 'y')
	{
		makeReservation(hikeList, memberList, reservations);
	}
	else
	{
		cout << "\n";
	}
}
