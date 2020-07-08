#ifndef DELIVERYCOMPANY_H_
#define DELIVERYCOMPANY_H_
#include "DeliveryVehicle.H"
#include <vector>

using namespace std;

class DeliveryCompany{
public:
	
	//* constructor name: DeliveryCompany
	//* Description: the constructor of DeliveryCompany
	//* Parameters: money - the initial funds of the company
	//*				round_robin_num_ - a control parameter for round robin
	//*             sumDeliveries - total number of deliveries for company
	//* return value: None
	DeliveryCompany(int money);
	// default constructor with funs_=100
	DeliveryCompany();
	
	// destructor of a company
	~DeliveryCompany();
	
	//* function name: addVehicle
	//* Description: This function adds a new vehicle to a company
	//* Parameters: the company instance
	//*				vehicle - the vehicle that need to be added
	//* return value: true if added and false if not
	bool addVehicle(DeliveryVehicle* vehicle);
	
	//* function name: receiveParcel
	//* Description: This function puts a parcel in a vehicle
	//* Parameters: the company instance
	//*				parcel - the parcel that need to be added
	//* return value: true if added and false if not
	bool receiveParcel(Parcel* parcel);
	
	//* function name: performDeliveryDay
	//* Description: This function performs a day of delivery for a company
	//* Parameters: the company instance
	//* return value: true if a delivery day was succefull
	bool performDeliveryDay();
	
	//* function name: displayFunds
//* Description: This function this function displays the funds of a company
//* Parameters: the company instance
//* return value: none
	void displayFunds();
	
	//displays number of deliveries company has done so far
	//output example:
	//Till now company has delivered 3 parcels
	void displayNumberOfDeliveries();

private:
	int funds_;
	vector<DeliveryVehicle*> vehicles; //vehicles vector
	int round_robin_num_;
	int sumDeliveries_;
};

#endif /* DELIVERYCOMPANY_H_ */
