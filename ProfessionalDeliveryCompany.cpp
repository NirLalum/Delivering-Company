#include "ProfessionalDeliveryCompany.H"
#include "DeliveryCompany.H"
#include <vector>
#include <iostream>

//* constructor name: ProfessionalDeliveryCompanyDeliveryCompany
//* Description: the constructor of ProfessionalDeliveryCompanyDeliveryCompany
//* Parameters: money - the initial funds of the company
//*				round_robin_num_ - a control parameter for round robin
//*             sumDeliveries - total number of deliveries for company
//* return value: None
ProfessionalDeliveryCompany::ProfessionalDeliveryCompany(int money) : DeliveryCompany(money) {};

// default constructor with funs_=100
ProfessionalDeliveryCompany::ProfessionalDeliveryCompany() : DeliveryCompany() {};

//* function name: addVehicle
//* Description: This function adds a new vehicle to a company
//* Parameters: the company instance
//*				vehicle - the vehicle that need to be added
//* return value: true if added and false if not
bool ProfessionalDeliveryCompany::addVehicle(DeliveryVehicle* vehicle) {
	if (vehicle->getType() == 3) {
		return DeliveryCompany::addVehicle(vehicle);
	}
	delete vehicle;
	return false;
}

//Destructor of ProfessionalDeliveryCompany
ProfessionalDeliveryCompany::~ProfessionalDeliveryCompany() {};