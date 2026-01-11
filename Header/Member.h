#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
public:
    Member(const std::string& aFirstName,
        const std::string& aLastName) : id(0),
        firstName(aFirstName), lastName(aLastName), points(0) {} 

    void addPoints(int morePoints);
    void setID(int newID);

    int getID() const;
    std::string getLastName() const;
    int getPoints() const;

    void printMember() const;

    bool operator<(const Member& otherMember) const;

private:
    int id;
    std::string firstName;
    std::string lastName;
    int points;
};

#endif MEMBER_H