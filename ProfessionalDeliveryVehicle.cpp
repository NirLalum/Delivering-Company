#include "ProfessionalDeliveryVehicle.H"
#include <cstddef>
#include <cstring>
#include <exception>
#include <iostream>
using namespace std;

//* constructor name: ProfessionalDeliveryVehicle
//* Description: the constructor of ProfessionalDeliveryVehicle
//* Parameters: ID - a pointer to a vehicle ID
//*				quality - the quality of a vehicle
//*             currentLocation - the location of the vehicle
//* return value: None
ProfessionalDeliveryVehicle::ProfessionalDeliveryVehicle(const char* ID, Quality quality) : DeliveryVehicle(ID, quality) {}

//* function name: getType
//* Description: this function return the type of a vehicle (1 for regular 2 for fast 3 for pro)
//* Parameters: the vehicle instance
//* return value: 1 or 2 or 3
int ProfessionalDeliveryVehicle::getType() {
	return 3;
}

//* function name: addParcel
//* Description: This function adds a parcel to a vehicle
//* Parameters: the vehicle instance
//*				parcel - a pointer to the parcel we want to add
//* return value: true if added false if not
bool ProfessionalDeliveryVehicle::addParcel(Parcel* parcel) {
	if (parcel == NULL) return false;
	int i = 0;
	int RoadLength = 0;
	if (ParcelList_[0] == NULL) { // in case there are no parcels in the vehicle
		RoadLength = RouteToPackage(currentLocation_, parcel->getDest());
		if (RoadLength <= 4) {
			return DeliveryVehicle::addParcel(parcel);
		}
	}
	for (i = 1; i < MAX_PARCELS; i++) {
		if (ParcelList_[i] == NULL && RoadLength == 0) {
			RoadLength = RouteToPackage(ParcelList_[i - 1]->getDest(), parcel->getDest());
			if (RoadLength <= 4) {
				return DeliveryVehicle::addParcel(parcel);
			}
		}
	}
	return false;
}

//* function name: performDeliveryDay
//* Description: this function makes a day of delivery by the given rules and prints statistics
//* Parameters: the vehicle instance
//*				numberofDeliveries - a pointer to a counter of the deliveries
//* return value: the revenue of the day
int ProfessionalDeliveryVehicle::performDeliveryDay(int* numberOfDeliveries) {
	if (ParcelList_[0] == NULL) {
		cout << "No parcels to deliver for vehicle " << ID_ << endl;
		cout << "Revenue per distance: no distance" << endl;
		cout << "Revenue per parcel: no parcels" << endl;
		return 0;
	}
	int i = 0;
	int RoadLength = 0;
	int TotRoadLength = RouteToPackage(currentLocation_, ParcelList_[i]->getDest());
	for (i = 1; i < MAX_PARCELS; i++) {
		if (ParcelList_[i] == NULL) break;
		RoadLength = RouteToPackage(currentLocation_, ParcelList_[i]->getDest());
		if (RoadLength + TotRoadLength > 12) break;
		TotRoadLength += RoadLength;
		RoadLength = 0;
	}
	int revenue = DeliveryVehicle::performDeliveryDay(numberOfDeliveries);
	if(TotRoadLength) cout << "Revenue per distance: " << (revenue / TotRoadLength) << endl;
	else cout << "Revenue per distance: no distance" << endl;
	cout << "Revenue per parcel: " << (revenue / *numberOfDeliveries) << endl;
	return revenue;
}

// Destructor of ProfessionalDeliveryVehicle
ProfessionalDeliveryVehicle::~ProfessionalDeliveryVehicle(){}