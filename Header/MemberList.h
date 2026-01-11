#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Member.h"

#include <set>

const int MEMBER_ID = 111;

class MemberList
{
public:
    MemberList() : memberList(new std::set<Member>) {}
    MemberList(const MemberList& otherMemberList);

    MemberList& operator=(const MemberList& otherMemberList);

    void addMember(const std::string& firstName,
        const std::string& lastName);
    void addMember(const std::string& firstName,
        const std::string& lastName, int points);

    int getLastID() const;
    int getPoints(int memberID) const;

    void printMember(int memberID,
        const std::string& lastName) const;

    void clearList();
    ~MemberList();

private:
    std::set<Member>* memberList;
};

#endif MEMBERLIST_H