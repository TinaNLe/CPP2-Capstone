#include "Member.h"

#include <iostream>

using namespace std;

void Member::addPoints(int morePoints)
{
    points += morePoints;
}

void Member::setID(int newID)
{
    id = newID;
}

int Member::getID() const
{
    return id;
}

string Member::getLastName() const
{
    return lastName;
}

int Member::getPoints() const
{
    return points;
}

void Member::printMember() const
{
    cout << "\t" << lastName << ", " << firstName << "\n\t"
        "Points available: " << points << "\n";
}

bool Member::operator<(const Member& otherMember) const
{
    return id < otherMember.id;
}

