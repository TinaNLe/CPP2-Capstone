#include "MemberList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string MEMBERS_FILE = "members_database.txt";

void createMemberList(ifstream& infile, MemberList& memberList)
{
	string firstName, lastName;
	int points = 0;

	while (!infile.eof())
	{
		infile >> firstName >> lastName >> points;
		memberList.addMember(firstName, lastName, points);
	}
}

void getMemberData(MemberList& memberList)
{
	ifstream infile;

	infile.open(MEMBERS_FILE);

	if (!infile)
	{
		cerr << MEMBERS_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createMemberList(infile, memberList);

	infile.close();
}


