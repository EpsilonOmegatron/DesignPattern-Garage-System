#ifndef PARKINGGARAGE_H_INCLUDED
#define PARKINGGARAGE_H_INCLUDED
#include "ParkingSlot.h"
#include "Vehicle.h"
#include "GarageReport.h"
#include "SlotSelection.h"

using namespace std;

class ParkingGarage
{
    private:
        ParkingSlot *parkingSlots;
        Vehicle *parkedVehicle;
        int carCounter = 0, income = 0, gSize;

    public:
        ParkingGarage(int main_gSize = 1)
        {
            gSize = main_gSize;
            parkingSlots = new ParkingSlot[gSize];
            parkedVehicle = new Vehicle[gSize];
        }

        bool addVehicle(Vehicle main_Vehicle, int slotAlgo)
        {
            if(slotAlgo == 0)
            {
                FirstFit algo;
                if(algo.selectSlot(parkingSlots, parkedVehicle, gSize, main_Vehicle))
                {carCounter++; return 1;}
                else return 0;
            }
            else if(slotAlgo == 1)
            {
                BestFit algo;
                if(algo.selectSlot(parkingSlots, parkedVehicle, gSize, main_Vehicle))
                {carCounter++; return 1;}
                else return 0;
            }
        }

        void removeVehicle(int main_slot)
        {
            int slotIncome = parkedVehicle[main_slot].getTime() * parkingSlots[main_slot].getPayrate();
            income += slotIncome;
            Vehicle reset;
            parkedVehicle[main_slot] = reset;
            parkingSlots[main_slot].setOccupied(0);
        }

        void setSlotDimensions()
        {
            for(int i = 0; i < gSize; i++)
            {
                cout << "\nSet slot " << i + 1 << "'s dimensions" << endl;
                parkingSlots[i].setSlot();
            }
        }

        bool isFree()
        {
            for(int i = 0; i < gSize; i++)
            {
                if(parkingSlots[i].getOccupied() == 0)
                {return 1;}
            }
            return 0;
        }

        void generateGarageReport()
        {
            GarageReport report(carCounter, income);
            report.printReport();
        }
};

#endif // PARKINGGARAGE_H_INCLUDED
