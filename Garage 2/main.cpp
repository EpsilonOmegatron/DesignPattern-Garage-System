#include <iostream>
#include "ParkingGarage.h"
using namespace std;

//Adham Hazem Fahmy Shafhei - S1 - 20206011

int main()
{
    //Administrator
    cout << "Enter the number of spots in garage: ";
    int garageSize;
    bool slotChoice;
    cin >> garageSize;
    ParkingGarage testGarage(garageSize);
    cout << "Do you want to manually set dimensions or use default values (500 x 200 cm, 10$ payrate)?" << endl << "0 if default, 1 if custom: ";
    cin >> slotChoice;
    if(slotChoice == 1)
    {testGarage.setSlotDimensions();}

    //Driver
    string model;
    int id , year, algoChoice;
    float length, width;
    while(testGarage.isFree())
    {
        cout << "Enter the vehicle Model, ID, Year, Length and Width: ";
        cin >> model >> id >> year >> length >> width;
        Vehicle testVehicle(model, id, year, length, width);
        cout << "Select slot algorithm (0 for first fit, 1 for best fit): ";
        cin >> slotChoice;
        if(!testGarage.addVehicle(testVehicle, slotChoice))
            cout << "No slot fits.";
    }

    cout << "\nThe garage is full.";
    testGarage.removeVehicle(0);
    testGarage.generateGarageReport();

    return 0;
}
