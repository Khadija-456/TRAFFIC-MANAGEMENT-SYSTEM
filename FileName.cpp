#include <iostream>
#include <string>

using namespace std;

// Here we are defining a structure for vehicle record
struct VehicleRecord
{
    string registrationNumber;
    string ownerName;
    string vehicleType;
    string city;
    bool enteringCity;
};

// Here we are defining a structure for challan record
struct ChallanRecord
{
    string vehicleRegistrationNumber;
    string violationDetails;
    string violationType;
    double amount;
};

const int MAX_VEHICLES = 100;
const int MAX_CHALLANS = 100;

void recordVehicle(VehicleRecord vehicleRecords[], int& vehicleCount)
{
    VehicleRecord newVehicle;

    cout << "Enter registration number: ";
    cin >> newVehicle.registrationNumber;
    cout << "Enter owner's name: ";
    cin >> newVehicle.ownerName;
    cout << "Enter type of vehicle: ";
    cin >> newVehicle.vehicleType;
    cout << "Enter city (Rawalpindi, Islamabad): ";
    cin >> newVehicle.city;
    cout << "Is the vehicle entering the city? (1 for yes, 0 for no): ";
    cin >> newVehicle.enteringCity;
    vehicleRecords[vehicleCount++] = newVehicle;
    cout << "Vehicle recorded successfully!" << endl;
}

void recordChallan(ChallanRecord challanRecords[], int& challanCount)
{
    ChallanRecord newChallan;
    cout << "Enter vehicle registration number: ";
    cin >> newChallan.vehicleRegistrationNumber;
    cout << "Enter violation type (red, yellow, green): ";
    cin >> newChallan.violationType;

    if (newChallan.violationType == "red") {
        newChallan.amount = 5000;
        newChallan.violationDetails = "Traffic light violation (Red signal)";
    }
    else if (newChallan.violationType == "yellow") {
        newChallan.amount = 3000;
        newChallan.violationDetails = "Traffic light violation (Yellow signal)";
    }
    else {
        newChallan.amount = 0;
        newChallan.violationDetails = "Traffic light violation (Green signal)";
    }

    challanRecords[challanCount++] = newChallan;

    cout << "Challan recorded successfully!" << endl;

    // Printing challan
    cout << "_____________________________________" << endl;
    cout << "             Challan Form            " << endl;
    cout << "_____________________________________" << endl;
    cout << " Vehicle Registration Number: " << newChallan.vehicleRegistrationNumber << endl;
    cout << " Violation Details: " << newChallan.violationDetails << endl;
    cout << " Challan Amount: $" << newChallan.amount << endl;
    cout << "_____________________________________" << endl;
}

void searchVehicle(const VehicleRecord vehicleRecords[], int vehicleCount, const ChallanRecord challanRecords[], int challanCount, const string& regNumber)
{
    bool vehicleFound = false;
    for (int i = 0; i < vehicleCount; i++) {
        if (vehicleRecords[i].registrationNumber == regNumber) {
            vehicleFound = true;
            cout << "_____________________________________" << endl;
            cout << "          Vehicle Information        " << endl;
            cout << "_____________________________________" << endl;
            cout << "Owner's name: " << vehicleRecords[i].ownerName << endl;
            cout << "Vehicle type: " << vehicleRecords[i].vehicleType << endl;
            cout << "City: " << vehicleRecords[i].city << endl;
            cout << "Direction of travel: " << (vehicleRecords[i].enteringCity ? "Entering" : "Leaving") << endl;
            cout << "_____________________________________" << endl;

            bool challanFound = false;
            cout << "Challan records for this vehicle:" << endl;
            for (int j = 0; j < challanCount; j++) {
                if (challanRecords[j].vehicleRegistrationNumber == regNumber) {
                    challanFound = true;
                    cout << " Violation Details: " << challanRecords[j].violationDetails << endl;
                    cout << " Challan Amount: $" << challanRecords[j].amount << endl;
                }
            }
            if (!challanFound) {
                cout << " No challan records found for this vehicle." << endl;
            }
            cout << "_____________________________________" << endl;
            return;
        }
    }
    if (!vehicleFound) {
        cout << "Vehicle not found!" << endl;
    }
}

void manageBooths(const VehicleRecord vehicleRecords[], int vehicleCount) {
    int choice;

    cout << "Choose the traffic control booth:" << endl;
    cout << "1. Rawalpindi" << endl;
    cout << "2. Islamabad" << endl;
    cout << "Enter your choice (1-2): ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Traffic Control Booth: Rawalpindi" << endl;
        break;
    case 2:
        cout << "Traffic Control Booth: Islamabad" << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        return;
    }

    int enteringCount = 0;
    int leavingCount = 0;

    for (int i = 0; i < vehicleCount; ++i) {
        if (choice == 1 && vehicleRecords[i].city == "Rawalpindi") {
            if (vehicleRecords[i].enteringCity) {
                enteringCount++;
            }
            else {
                leavingCount++;
            }
        }
        else if (choice == 2 && vehicleRecords[i].city == "Islamabad") {
            if (vehicleRecords[i].enteringCity) {
                enteringCount++;
            }
            else {
                leavingCount++;
            }
        }
    }

    cout << "Number of vehicles entering the city: " << enteringCount << endl;
    cout << "Number of vehicles leaving the city: " << leavingCount << endl;
}

void displayHelp()
{
    cout << "Help options..." << endl;
    cout << "Edhi Ambulance Helpline: 115" << endl;
    cout << "Chhipa Ambulance Helpline: 1020" << endl;
    cout << "Police Helpline: 15" << endl;
}

int main()
{
    VehicleRecord vehicleRecords[MAX_VEHICLES];
    ChallanRecord challanRecords[MAX_CHALLANS];
    int vehicleCount = 0;
    int challanCount = 0;
    int choice;

    do {
        cout << "____________________________________" << endl;
        cout << "*    Traffic Management System     *" << endl;
        cout << "____________________________________" << endl;
        cout << "  1. Record of Vehicles             " << endl;
        cout << "  2. Record of Challan              " << endl;
        cout << "  3. Search the Record of Vehicles  " << endl;
        cout << "  4. Traffic Control Booths         " << endl;
        cout << "  5. Help !                         " << endl;
        cout << "____________________________________" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            recordVehicle(vehicleRecords, vehicleCount);
            break;

        case 2:
            recordChallan(challanRecords, challanCount);
            break;

        case 3: {
            string regNumber;
            cout << "Enter registration number to search: ";
            cin >> regNumber;
            searchVehicle(vehicleRecords, vehicleCount, challanRecords, challanCount, regNumber);
            break;
        }

        case 4:
            manageBooths(vehicleRecords, vehicleCount);
            break;

        case 5:
            displayHelp();
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}


