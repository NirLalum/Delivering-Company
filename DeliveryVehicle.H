#ifndef DELIVERYVEHICLE_H_
#define DELIVERYVEHICLE_H_

#include "Parcel.H"

#define MAX_PARCELS 5
#define PARCEL_PRICE 4
typedef enum quality{good = 3, ok = 4, bad = 5} Quality;

class DeliveryVehicle {
public:
	//* constructor name: DeliveryVehicle
	//* Description: the constructor of DeliveryVehicle
	//* Parameters: ID - a pointer to a vehicle ID
	//*				quality - the quality of a vehicle
	//*             currentLocation - the location of the vehicle
	//* return value: None
	DeliveryVehicle(const char* ID, Quality quality);
	
	// destructor of DeliveryVehicle
	virtual ~DeliveryVehicle();
	
	//* function name: getID
	//* Description: This function returns the ID of a vehicle
	//* Parameters: the vehicle instance
	//* return value: a poiter to ID of a vehicle
	const char* getID() const;
	
	//* function name: getQuality
	//* Description: This function returns the quality of a vehicle
	//* Parameters: the vehicle instance
	//* return value: the quality of a vehicle
	Quality getQuality() const;
	
	//* function name: getCurrentLocation
	//* Description: This function returns the current location of a vehicle
	//* Parameters: the vehicle instance
	//* return value: the current location of a vehicle
	int getCurrentLocation() const;
	
	//* function name: addParcel
	//* Description: This function adds a parcel to a vehicle
	//* Parameters: the vehicle instance
	//*				parcel - a pointer to the parcel we want to add
	//* return value: true if added false if not
	virtual bool addParcel(Parcel* parcel);
	
	//* function name: getType
	//* Description: this function return the type of a vehicle (1 for regular 2 for fast 3 for pro)
	//* Parameters: the vehicle instance
	//* return value: 1 or 2 or 3
	virtual int getType();

	//* function name: RouteToPackage
	//* Description: This function calculates the length of the road to a package
	//* Parameters: current position - the location of a vehicle/parcel (depends which func calls)
	//*				ParcelDest - the location of a parcel
	//* return value: the length of the road
	static int RouteToPackage(int currentPosition, int ParcelDest);


	//* function name: performDeliveryDay
	//* Description: this function makes a day of delivery by the given rules
	//* Parameters: the vehicle instance
	//*				number of Deliveries - a pointer to a counter of the deliveries
	//* return value: the revenue of the day
	virtual int performDeliveryDay(int* numberOfDeliveries);
	
	//* function name: CreateNewCopy
	//* Description: This function copies an ID
	//* Parameters: src - pointer to the string we want to copy
	//* return value: a poiter to the copied string
	static char* createNewCopy(const char* src);
protected:
	const char* ID_;
	Quality quality_;
	Parcel* ParcelList_[MAX_PARCELS];
	int currentLocation_;
};

#endif /* DELIVERYVEHICLE_H_ */
