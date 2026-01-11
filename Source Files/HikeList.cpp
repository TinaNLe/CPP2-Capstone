#include "HikeList.h"

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void HikeList::addHike(const Hike& hike, double price)
{
	hikeList.insert({hike, price});
}

void HikeList::addHike(const string& location, const string& hikeName,
	int duration, char difficulty, const double& price)
{
	hikeList.insert({Hike(location, hikeName, duration, difficulty),
		price});
}

double HikeList::getPrice(const string& hikeName) const
{
	auto targetItr = find_if(hikeList.begin(), hikeList.end(),
		[&hikeName](pair<Hike, double> aPair)
		{ return (aPair.first.getHikeName() == hikeName); });

	return targetItr->second;
}

void HikeList::printAllLocations() const
{
	auto pairItr = hikeList.begin();
	auto endItr = hikeList.end();

	while (pairItr != endItr)
	{
		cout << "\t" << pairItr->first.getLocation() << "\n";
		pairItr = hikeList.upper_bound(pairItr->first);
	}
}

void HikeList::printByLocation(const string& location) const
{
	auto targetHikeItr = find_if(hikeList.begin(), hikeList.end(),
		[&location](pair<Hike, double> aPair)
		{ return (aPair.first.getLocation() == location); });

	auto endItr = hikeList.end();

	while (targetHikeItr != endItr)
	{
		cout << targetHikeItr->first
			<< "\n\t  Price (per person): $ "
			<< fixed << setprecision(2)
			<< targetHikeItr->second << "\n\n";

		++targetHikeItr;

		targetHikeItr = find_if(targetHikeItr, hikeList.end(),
			[&location](pair<Hike, double> aPair)
			{ return (aPair.first.getLocation() == location); });
	}
}

void HikeList::printByDuration() const
{
	multimap<int, string> tempMultiMap;
	int hikeListSize = static_cast<int>(hikeList.size());
	string comma = ", ";

	for (auto aHike : hikeList)
	{
		tempMultiMap.insert({ aHike.first.getDuration(),
			aHike.first.getHikeName() + comma +
			aHike.first.getLocation() });
	}

	for (auto aPair : tempMultiMap)
	{
		cout << "\t(" << aPair.first << ") "
			<< aPair.second << "\n";
	}
}

void HikeList::printByDuration(int days) const
{
	multimap<int, string> tempMultiMap;
	int hikeListSize = static_cast<int>(hikeList.size());

	for (auto aPair : hikeList)
	{
		Hike aHike = aPair.first;
		int duration = aHike.getDuration();
		if (duration == days)
		{
			cout << aHike << "\n\n";
		}
	}
}

void HikeList::printByDifficulty(char difficulty) const
{
	for (auto aPair : hikeList)
	{
		Hike aHike = aPair.first;
		char aDifficulty = aHike.getDifficulty();
		if (aDifficulty == difficulty)
		{
			cout << "\t(" << aDifficulty << ") "
				<< aHike.getHikeName() << ", "
				<< aHike.getLocation() << "\n";
		}
	}
}

void HikeList::printByPrice() const
{
	multimap<double, pair<string, string>> tempMultiMap;
	int hikeListSize = static_cast<int>(hikeList.size());

	for (auto aHike : hikeList)
	{
		double price = aHike.second;
		string location = aHike.first.getLocation();
		string hikeName = aHike.first.getHikeName();
		tempMultiMap.emplace(price,
			pair<string, string>(location, hikeName)); 
	}

	for (auto aPair : tempMultiMap)
	{
		cout << "\t$ " << setw(7)
			<< fixed << setprecision(2)
			<< aPair.first << " - "
			<< aPair.second.first << " ("
			<< aPair.second.second << ")\n";
	}
}

void HikeList::printByHikeName(const string& hikeName) const
{
	auto targetItr = find_if(hikeList.begin(), hikeList.end(),
		[&hikeName](pair<Hike, double> aPair)
		{ return (aPair.first.getHikeName() == hikeName); });

	cout << targetItr->first
		<< fixed << setprecision(2)
		<< "\n\t  $" << targetItr->second << "\n";
}

void HikeList::clearList()
{
	hikeList.clear();
}