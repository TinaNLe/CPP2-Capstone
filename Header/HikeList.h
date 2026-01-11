#ifndef HIKELIST_H
#define HIKELIST_H

#include "Hike.h"

#include <string>
#include <map>

class HikeList
{
public:
	void addHike(const Hike& hike, double price);
	void addHike(const std::string& location,
		const std::string& hikeName, int duration,
		char difficulty, const double& price);

	double getPrice(const std::string& hikeName) const;

	void printAllLocations() const;
	void printByLocation(const std::string& location) const;
	void printByDuration() const;
	void printByDuration(int days) const;
	void printByDifficulty(char difficulty) const;
	void printByPrice() const;
	void printByHikeName(const std::string& hikeName) const;

	void clearList();

private:
	std::multimap<Hike, double> hikeList;
};

#endif HIKELIST_H