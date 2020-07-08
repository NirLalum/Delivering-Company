####################################################################
# Makefile for building the delivery application
#

#
# Definitions
#
CCC = g++ 
CXXFLAGS = -Wall -g -std=c++11
CXXLINK = $(CCC)
LIBS = 
OBJS = DeliveryVehicle.o FastDeliveryVehicle.o ProfessionalDeliveryVehicle.o \
DeliveryVehicleList.o DeliveryCompany.o FastDeliveryCompany.o ProfessionalDeliveryCompany.o Parcel.o
RM = rm -f
TARGET = all

# Targets
$(TARGET): test1 test2 test3

test1: $(OBJS) main1.o
	$(CXXLINK) -o test1 $(OBJS) main1.o

test2: $(OBJS) main2.o
	$(CXXLINK) -o test2 $(OBJS) main2.o

test3: $(OBJS) main3.o
	$(CXXLINK) -o test3 $(OBJS) main3.o

main1.o: main1.C FastDeliveryCompany.H DeliveryCompany.H DeliveryVehicle.H Parcel.H DeliveryVehicleList.H \
ProfessionalDeliveryCompany.H FastDeliveryVehicle.H ProfessionalDeliveryVehicle.H

main2.o: main2.C FastDeliveryCompany.H DeliveryCompany.H DeliveryVehicle.H Parcel.H DeliveryVehicleList.H \
ProfessionalDeliveryCompany.H FastDeliveryVehicle.H ProfessionalDeliveryVehicle.H

main3.o: main3.C FastDeliveryCompany.H DeliveryCompany.H DeliveryVehicle.H Parcel.H DeliveryVehicleList.H \
ProfessionalDeliveryCompany.H FastDeliveryVehicle.H   ProfessionalDeliveryVehicle.H

DeliveryCompany.o: DeliveryCompany.C DeliveryCompany.H DeliveryVehicle.H Parcel.H DeliveryVehicleList.H 

DeliveryVehicle.o: DeliveryVehicle.C DeliveryVehicle.H Parcel.H 

DeliveryVehicleList.o: DeliveryVehicleList.C DeliveryVehicleList.H DeliveryVehicle.H Parcel.H

FastDeliveryCompany.o: FastDeliveryCompany.C FastDeliveryCompany.H DeliveryCompany.H DeliveryVehicle.H \
Parcel.H DeliveryVehicleList.H

FastDeliveryVehicle.o: FastDeliveryVehicle.C FastDeliveryVehicle.H DeliveryVehicle.H Parcel.H
Parcel.o: Parcel.C Parcel.H

ProfessionalDeliveryCompany.o: ProfessionalDeliveryCompany.C ProfessionalDeliveryCompany.H DeliveryCompany.H \
DeliveryVehicle.H Parcel.H DeliveryVehicleList.H

ProfessionalDeliveryVehicle.o: ProfessionalDeliveryVehicle.C ProfessionalDeliveryVehicle.H DeliveryVehicle.H \
Parcel.H

#
# Cleaninng
#
clean:
	$(RM) $(TARGET) *.o *.bak *~"#"* core test1 test2 test3