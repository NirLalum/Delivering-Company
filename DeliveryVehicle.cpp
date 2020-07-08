#include "DeliveryVehicle.H"
#include <cstddef>
#include <cstring>
#include <exception>
#include <iostream>
using namespace std;


//* function name: RouteToPackage
//* Description: This function calculates the length of the road to a package
//* Parameters: current position - the location of a vehicle/parcel (depends which func calls)
//*				ParcelDest - the location of a parcel
//* return value: the length of the road
int DeliveryVehicle::RouteToPackage(int currentPosition, int ParcelDest) {
	int RoadLength = 0;
	while (currentPosition != ParcelDest) {
		RoadLength++;
		currentPosition++;
		if (currentPosition == 10) currentPosition = 0;
	}
	return RoadLength;
}

//* function name: CreateNewCopy
//* Description: This function copies an ID
//* Parameters: src - pointer to the string we want to copy
//* return value: a poiter to the copied string
char* DeliveryVehicle::createNewCopy(const char* src) {
	char* dst;
	if (src == NULL) return NULL;
	dst = new char[strlen(src) + 1];
	strcpy(dst, src);
	return dst;
}

//* constructor name: DeliveryVehicle
//* Description: the constructor of DeliveryVehicle
//* Parameters: ID - a pointer to a vehicle ID
//*				quality - the quality of a vehicle
//*             currentLocation - the location of the vehicle
//* return value: None
DeliveryVehicle::DeliveryVehicle(const char* ID, Quality quality) : ID_(createNewCopy(ID)), quality_(quality), currentLocation_(0) {
	int i = 0;
	for (i = 0; i < MAX_PARCELS; i++) {
		ParcelList_[i] = NULL;
	}
}

//* function name: getID
//* Description: This function returns the ID of a vehicle
//* Parameters: the vehicle instance
//* return value: a poiter to ID of a vehicle
const char* DeliveryVehicle::getID() const {
	return ID_;
}

//* function name: getQuality
//* Description: This function returns the quality of a vehicle
//* Parameters: the vehicle instance
//* return value: the quality of a vehicle
Quality DeliveryVehicle::getQuality() const {
	return quality_;
}


//* function name: getCurrentLocation
//* Description: This function returns the current location of a vehicle
//* Parameters: the vehicle instance
//* return value: the current location of a vehicle
int DeliveryVehicle::getCurrentLocation() const {
	return currentLocation_;
}

//* function name: addParcel
//* Description: This function adds a parcel to a vehicle
//* Parameters: the vehicle instance
//*				parcel - a pointer to the parcel we want to add
//* return value: true if added false if not
bool DeliveryVehicle::addParcel(Parcel* parcel) {
	if (parcel == NULL) return false;
	int i = 0;
	for (i = 0; i < MAX_PARCELS; i++) { 
		if (ParcelList_[i] == NULL) {
			ParcelList_[i] = parcel;
			return true;
		}
		if (parcel == ParcelList_[i]) {
			return false; // in case the same parcel is allready in
		}
	}
	return false;  // there is not enough space in the vehicle
}

//* function name: performDeliveryDay
//* Description: this function makes a day of delivery by the given rules
//* Parameters: the vehicle instance
//*				number of Deliveries - a pointer to a counter of the deliveries
//* return value: the revenue of the day
int DeliveryVehicle::performDeliveryDay(int* numberOfDeliveries) {
	if (ParcelList_[0] == NULL) {
		cout << "No parcels to deliver for vehicle " << ID_ << endl;
		return 0;
	}
	cout << "Starting deliveries for vehicle " << ID_ << endl;
	int TotFuelConsumption = 0; // the max fuel consumption is 12
	*numberOfDeliveries = 0;
	int i = 0;
	for (i = 0; i < MAX_PARCELS; i++) {
		if (ParcelList_[i] == NULL) break; // in case the there is no Parcel in the cell
		int ParcelDest = ParcelList_[i]->getDest();
		int RoadLength = RouteToPackage(currentLocation_, ParcelDest); // get how mush fuel was used 
		if ((RoadLength + TotFuelConsumption) > 12) break; // in case all fuel was used
		cout << "Delivering parcel " << ParcelList_[i]->getID() << " to position " << ParcelList_[i]->getDest() << endl;
		(*numberOfDeliveries)++;
		TotFuelConsumption += RoadLength;
		currentLocation_ = ParcelDest; // updating the location of the vehicle
		cout << "Fuel consumed: " << RoadLength << " Revenue is: " << PARCEL_PRICE << endl;
		delete ParcelList_[i];
		ParcelList_[i] = NULL;
		RoadLength = 0;
	}
	// arrange the Parcel list so that the first cells will be fille with parcels
	for (i = 0; ((i < (*numberOfDeliveries)) && ((*numberOfDeliveries) != 5)) ; i++) {
		if ((i + *numberOfDeliveries) == MAX_PARCELS || ParcelList_[i + *numberOfDeliveries] == NULL) break;
		ParcelList_[i] = ParcelList_[i + *numberOfDeliveries];
		ParcelList_[i + *numberOfDeliveries] = NULL;
	}
	cout << "Total travel distance is " << TotFuelConsumption << endl;
	int revenue = *numberOfDeliveries * PARCEL_PRICE - TotFuelConsumption - quality_;
	cout << "Total revenue is " << revenue << endl;
	return revenue;
}

//* function name: getType
//* Description: this function return the type of a vehicle (1 for regular 2 for fast 3 for pro)
//* Parameters: the vehicle instance
//* return value: 1 or 2 or 3
int DeliveryVehicle::getType() {
	return 1;
}

// destructor of DeliveryVehicle
DeliveryVehicle::~DeliveryVehicle() { 
	int i = 0;
	delete[] ID_; 
	for (i = 0; i < MAX_PARCELS; i++) {
		if (ParcelList_[i] == NULL) break;
		delete ParcelList_[i];
	}
}