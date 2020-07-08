#include <cstring>
#include "Parcel.H"

//* constructor name: Parcel
//* Description: the constructor of Parcel
//* Parameters: ID - a pointer to the name of the parcel
//*				dest - the destination of the parcel
//*             sumDeliveries - total number of deliveries for company
//* return value: None
Parcel::Parcel(const char* ID, int dest) : dest_(dest) {
	int len = strlen(ID);
	ID_ = new char[len + 1];
	strcpy(ID_, ID);
};

//* function name: getID
//* Description: This function returns the ID of the parcel
//* Parameters: the parcel instance
//* return value: the ID of the Parcel
char* Parcel::getID() const {
	return ID_;
}

//* function name: getDest
//* Description: This function returns the destination of the parcel
//* Parameters: the parcel instance
//* return value: the destination of the Parcel
int Parcel::getDest() const{
	return dest_;
}

//Destructor of Parcel
Parcel::~Parcel() {
	delete[] ID_;
};