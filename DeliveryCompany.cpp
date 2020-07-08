#include "DeliveryCompany.H"
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

//* constructor name: DeliveryCompany
//* Description: the constructor of DeliveryCompany
//* Parameters: money - the initial funds of the company
//*				round_robin_num_ - a control parameter for round robin
//*             sumDeliveries - total number of deliveries for company
//* return value: None
DeliveryCompany::DeliveryCompany(int money) : funds_(money), round_robin_num_(-1), sumDeliveries_(0) {};

// default constructor with funs_=100
DeliveryCompany::DeliveryCompany() : funds_(100), round_robin_num_(-1), sumDeliveries_(0){};

//* function name: addVehicle
//* Description: This function adds a new vehicle to a company
//* Parameters: the company instance
//*				vehicle - the vehicle that need to be added
//* return value: true if added and false if not
bool DeliveryCompany::addVehicle(DeliveryVehicle* vehicle) {
	int i;
	for (i = 0; (unsigned)i < vehicles.size(); i++) {
		if (!strcmp(vehicle->getID(), vehicles[i]->getID())) {
			cout << "Can't add vehicle, it already exists" << endl;
			delete vehicle;
			return false;
		}
	}
	vehicles.push_back(vehicle);
	return true;
}

//* function name: receiveParcel
//* Description: This function puts a parcel in a vehicle
//* Parameters: the company instance
//*				parcel - the parcel that need to be added
//* return value: true if added and false if not
bool DeliveryCompany::receiveParcel(Parcel* parcel) {
	int i, v_size = vehicles.size();
	if (round_robin_num_ == -1) round_robin_num_ = (v_size - 1); //for first time use only
	for (i = 0; i < v_size; i++) {
		if (vehicles[round_robin_num_]->addParcel(parcel)) {
			round_robin_num_--;
			return true;
		}
		round_robin_num_--;
		if (round_robin_num_ == -1) round_robin_num_ = (v_size - 1);
	}
	delete parcel;
	return false;
}

//* function name: performDeliveryDay
//* Description: This function performs a day of delivery for a company
//* Parameters: the company instance
//* return value: true if a delivery day was succefull
bool DeliveryCompany::performDeliveryDay() {
	
	if (!vehicles.size()) return false;
	int i;
	int dayProfit = 0;
	int numberOfDeliveries = 0;
	int totalNumberOfDeliveries = 0;
	int* numberOfDeliveries_ptr = &numberOfDeliveries;
	cout << "Starting days deliveries:" << endl;

	for (i = 0; (unsigned)i < vehicles.size(); i++) {
		dayProfit += vehicles[(vehicles.size() -1 - i)]->performDeliveryDay(numberOfDeliveries_ptr);
		totalNumberOfDeliveries += numberOfDeliveries;
		numberOfDeliveries = 0;
	}
	cout << "Total revenue for company is " << dayProfit << endl;
	sumDeliveries_ += totalNumberOfDeliveries;
	funds_ += dayProfit;
	return true;
}

//* function name: displayFunds
//* Description: This function this function displays the funds of a company
//* Parameters: the company instance
//* return value: none
void DeliveryCompany::displayFunds() {
	cout << "Company balance is now " << funds_ << endl;
}

//* function name: displayNumberOfDeliveries
//* Description: This function displays the number of deliveries of a company
//* Parameters: the company instance
//* return value: none
void DeliveryCompany::displayNumberOfDeliveries() {
	cout << "Till now company has delivered " << sumDeliveries_ << " parcels" << endl;
}

// destructor of a company
DeliveryCompany::~DeliveryCompany() {
	int i = 0;
	for (i = 0; (unsigned)i < vehicles.size(); i++) {
		delete vehicles[i];
	}
}