#ifndef PARCEL_H_
#define PARCEL_H_

class Parcel {
public:
	
	//* constructor name: Parcel
	//* Description: the constructor of Parcel
	//* Parameters: ID - a pointer to the name of the parcel
	//*				dest - the destination of the parcel
	//*             sumDeliveries - total number of deliveries for company
	//* return value: None
	Parcel(const char* ID, int dest);

	const int getParcelRate() {
		return rate_;
	}

	//* function name: getDest
	//* Description: This function returns the destination of the parcel
	//* Parameters: the parcel instance
	//* return value: the destination of the Parcel
	int getDest() const;
	
	//* function name: getID
	//* Description: This function returns the ID of the parcel
	//* Parameters: the parcel instance
	//* return value: the ID of the Parcel
	char* getID() const;
	
	//Destructor of Parcel
	~Parcel();

protected:
	char* ID_;
	int dest_;
	const int rate_ = 4;

};

#endif /* PARCEL_H_ */
