#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Cargo.h"
 using namespace std;

namespace sdds
{
	// the function to set the Cargo class's data members
	void Cargo::initialize(const char* desc, double weight) {
		// setting data for description
		if (strlen(desc) <= MAX_DESC) {
			setDesc(desc);
		} else {
			setDesc("\0");
		}
		// setting data for weight
		if (weight >= MIN_WEIGHT && weight <= MAX_WEIGHT) {
			setWeight(weight);
		}
		else {
			setWeight(MIN_WEIGHT);
		}
	}
	// Returns the description of the cargo
	const char* Cargo::getDesc() const {
		return m_description;
	}
	// Returns the weight of the cargo
	double Cargo::getWeight() const {
		return m_weight;
	}
	// Sets the description of the cargo by copying data to m_description
	void Cargo::setDesc(const char* desc) {
		strcpy(m_description, desc);
	}
	// Sets the weight of the cargo
	void Cargo::setWeight(double weight) {
		m_weight = weight;
	}
	// Helper function for loading new cargo data
	void Cargo::load(const Cargo& nCargo) {
		//copies cargo from new cargo to this cargo
		strcpy(m_description, nCargo.m_description);
		m_weight = nCargo.m_weight;
	}
}