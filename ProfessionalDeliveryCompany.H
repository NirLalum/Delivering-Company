#ifndef PROFESSIONALDELIVERYCOMPANY_H_
#define PROFESSIONALDELIVERYCOMPANY_H_

#include "DeliveryVehicle.H"
#include "DeliveryCompany.H"

class ProfessionalDeliveryCompany : public DeliveryCompany{
public:
	
	//* constructor name: ProfessionalDeliveryCompanyDeliveryCompany
	//* Description: the constructor of ProfessionalDeliveryCompanyDeliveryCompany
	//* Parameters: money - the initial funds of the company
	//*				round_robin_num_ - a control parameter for round robin
	//*             sumDeliveries - total number of deliveries for company
	//* return value: None
	ProfessionalDeliveryCompany(int money);
	
	// default constructor with funs_=100
	ProfessionalDeliveryCompany();
	
	//Destructor of ProfessionalDeliveryCompany
	~ProfessionalDeliveryCompany();
	
	//* function name: addVehicle
	//* Description: This function adds a new vehicle to a company
	//* Parameters: the company instance
	//*				vehicle - the vehicle that need to be added
	//* return value: true if added and false if not
	bool addVehicle(DeliveryVehicle* vehicle);
	
};

#endif /* PROFESSIONALDELIVERYCOMPANY_H_ */
