#ifndef PROFESSIONALDELIVERYVEHICLE_H_
#define PROFESSIONALDELIVERYVEHICLE_H_

#include "DeliveryVehicle.H"

class ProfessionalDeliveryVehicle : public DeliveryVehicle{
public:
	
	//* constructor name: ProfessionalDeliveryVehicle
	//* Description: the constructor of ProfessionalDeliveryVehicle
	//* Parameters: ID - a pointer to a vehicle ID
	//*				quality - the quality of a vehicle
	//*             currentLocation - the location of the vehicle
	//* return value: None
	ProfessionalDeliveryVehicle(const char* ID, Quality quality);
	
	// Destructor of ProfessionalDeliveryVehicle
	~ProfessionalDeliveryVehicle();
	
	//* function name: addParcel
	//* Description: This function adds a parcel to a vehicle
	//* Parameters: the vehicle instance
	//*				parcel - a pointer to the parcel we want to add
	//* return value: true if added false if not
	bool addParcel(Parcel* parcel);
	
	//* function name: performDeliveryDay
	//* Description: this function makes a day of delivery by the given rules and prints statistics
	//* Parameters: the vehicle instance
	//*				numberofDeliveries - a pointer to a counter of the deliveries
	//* return value: the revenue of the day
	int performDeliveryDay(int* numberOfDeliveries);

	//* function name: getType
	//* Description: this function return the type of a vehicle (1 for regular 2 for fast 3 for pro)
	//* Parameters: the vehicle instance
	//* return value: 1 or 2 or 3
	int getType();
};

#endif /* PROFFESSIONALDELIVERYVEHICLE_H_ */
