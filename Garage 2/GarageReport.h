#ifndef GARAGEREPORT_H_INCLUDED
#define GARAGEREPORT_H_INCLUDED

using namespace std;

class GarageReport
{
    private:
        int totalVehicles;
        int totalIncome;

    public:
        GarageReport(int vehicles = 0, int income = 0)
        {totalVehicles = vehicles; totalIncome = income;}

        void printReport()
        {
            cout << "\n\nGarage Report: ";
            cout << "\nTotal vehicles: " << totalVehicles;
            cout << "\nTotal income: " << totalIncome << endl;
        }
};

#endif // GARAGEREPORT_H_INCLUDED
