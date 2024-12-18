#include <iostream>
#include <string>
using namespace std;

double getServicePrice(string serviceType) {
    if (serviceType == "Economy") {
        return 1000.0;
    } else if (serviceType == "Standard") {
        return 2000.0;
    } else if (serviceType == "VIP") {
        return 3000.0;
    } else {
        return 0.0;
    }
}

string selectService() {
    int serviceChoice;
    cout << "\n\tPLEASE SELECT YOUR SERVICE TYPE (enter number)\n";
    cout << "\t1. Economy\n";
    cout << "\t2. Standard\n";
    cout << "\t3. VIP\n";
    cout << "\t0. CANCEL RESERVATION\n\n";
    cout << "\tEnter your choice: ";
    cin >> serviceChoice;

    switch (serviceChoice) {
        case 1: return "Economy";
        case 2: return "Standard";
        case 3: return "VIP";
        case 0:
            cout << "\n\tCANCELLING RESERVATION...\n";
            exit(0);
        default:
            cout << "\n\tInvalid input. Please select a valid service type.\n";
            return selectService();
    }
}

double getPrice(string origin, string destination) {
    if (origin == "KARACHI") {
        if (destination == "ISLAMABAD") 
        return 6000.0;
        if (destination == "LAHORE") 
        return 45000.0;
        if (destination == "RAWALPINDI") 
        return 6500.0;
        if (destination == "SWABI") 
        return 8000.0;

    } else if (origin == "ISLAMABAD") {

        if (destination == "KARACHI") 
            return 4500.0;
        if (destination == "LAHORE") 
            return 3000.0;
        if (destination == "RAWALPINDI")
            return 800.0;
        if (destination == "SWABI") 
            return 1000.0;

    } else if (origin == "LAHORE") {

        if (destination == "KARACHI") 
            return 4000.0;
        if (destination == "ISLAMABAD")
             return 3500.0;
        if (destination == "RAWALPINDI")
             return 3000.0;
        if (destination == "SWABI") 
            return 3000.0;

    } else if (origin == "RAWALPINDI") {
        if (destination == "KARACHI") 
            return 1800.0;
        if (destination == "ISLAMABAD") 
            return 800.0;
        if (destination == "LAHORE") 
            return 1000.0;
        if (destination == "SWABI") 
            return 1200.0;
    } else if (origin == "SWABI") {
        if (destination == "KARACHI") 
            return 1900.0;
        if (destination == "ISLAMABAD") 
            return 1000.0;
        if (destination == "LAHORE") 
            return 1200.0;
        if (destination == "RAWALPINDI") 
            return 1200.0;
    }
    return 0.0;
}

string selectdept() {
    int orgn;
    cout << "\n\tSELECT DEPATRURE POINT (enter number)\n";
    cout<<"\n";
    cout << "\t1. KARACHI\n";
    cout << "\t2. ISLAMABAD\n";
    cout << "\t3. LAHORE\n";
    cout << "\t4. RAWALPINDI\n";
    cout << "\t5. SWABI\n";
    cout << "\t0. CANCEL RESERVATION\n\n";
    cout << "\tEnter your choice: ";
    cin >> orgn;
    switch (orgn) {
        case 1: return "KARACHI";
        case 2: return "ISLAMABAD";
        case 3: return "LAHORE";
        case 4: return "RAWALPINDI";
        case 5: return "SWABI";
        case 0:
            cout << "\n\tCANCELLING RESERVATION...\n";
            exit(0);
        default:
            cout << "\n\tInvalid input. Try again.\n";
            return selectdept();
    }
}

string selectDestination() {
    int dest;
    cout << "\n\tPLEASE SELECT YOUR JOURNEY'S DESTINATION (enter number)\n";
    cout << "\t1. KARACHI\n";
    cout << "\t2. ISLAMABAD\n";
    cout << "\t3. LAHORE\n";
    cout << "\t4. RAWALPINDI\n";
    cout << "\t5. SWABI\n";
    cout << "\t0. CANCEL RESERVATION\n\n";
    cout << "\tEnter your choice: ";
    cin >> dest;
    switch (dest) {
        case 1: return "KARACHI";
        case 2: return "ISLAMABAD";
        case 3: return "LAHORE";
        case 4: return "RAWALPINDI";
        case 5: return "SWABI";
        case 0:
            cout << "\n\tCANCELLING RESERVATION...\n";
            exit(0);
        default:
            cout << "\n\tInvalid input. Try again.\n";
            return selectDestination();
    }
}

string selectTime() {
    int timeChoice;
    cout << "\n\tAVAILABLE TIMES FOR YOUR JOURNEY (enter number)\n";
    cout << "\t1. 09:00 AM\n";
    cout << "\t2. 12:00 PM\n";
    cout << "\t3. 03:00 PM\n";
    cout << "\t4. 06:00 PM\n";
    cout << "\t0. CANCEL RESERVATION\n\n";
    cout << "\tEnter your choice: ";
    cin >> timeChoice;

    switch (timeChoice) {
        case 1: return "09:00 AM";
        case 2: return "12:00 PM";
        case 3: return "03:00 PM";
        case 4: return "06:00 PM";
        case 0:
            cout << "\n\tCANCELLING RESERVATION...\n";
            exit(0);
        default:
            cout << "\n\tInvalid input. Please select a valid time.\n";
            return selectTime();
    }
}

double applyDiscount(double totalPrice) {
    string promoCode;
    double discount = 0.0;
    cout << "\n\tEnter Promo Code (or press 0 to skip): ";
    cin.ignore();
    cin >> promoCode;

    if (promoCode == "DISCOUNT10") {
        discount = 0.10;
        cout << "\n\tPromo code applied: 10% discount\n";
    } else if (promoCode == "DISCOUNT20") {
        discount = 0.20;
        cout << "\n\tPromo code applied: 20% discount\n";
    } else if (promoCode != "") {
        cout << "\n\tInvalid promo code. No discount applied.\n";
    } 

        return totalPrice * (1 - discount);


}

int generateTicketNumber(int &ticketCounter) {
    return ticketCounter++;
}

void printTicket(string origin, string destination, string serviceType, double totalPrice, string time, int ticketNumber) {
    cout << "\n\t--------------------------------------------\n";
    cout << "\t          ** BUS TICKET **\n";
    cout << "\t--------------------------------------------\n";
    cout << "\tTicket No:    " << ticketNumber << endl;
    cout << "\tTime:         " << time << endl;
    cout << "\tOrigin:       " << origin << endl;
    cout << "\tDestination:  " << destination << endl;
    cout << "\tService:      " << serviceType << endl;
    cout << "\tPrice:        Rs. " << totalPrice << endl;
    cout << "\t--------------------------------------------\n";
    cout << "\t         Have a Safe Journey! \n";
    cout << "\t--------------------------------------------\n";
}

int main() {
    int jrny_typ,c1;
    static int ticketCounter = 10001;
    double totalBill = 0.0;
    int totalTickets = 0;

    
        cout << "\n\tWELCOME TO THE BUS RESERVATION SYSTEM!\n\n";
        cout << "\tPLEASE SELECT JOURNEY TYPE (enter number)\n";
        cout << "\t1. ROUND TRIP\n";
        cout << "\t2. ONE-WAY\n";
        cout << "\t0. EXIT\n\n";
        cout << "\tEnter your choice: ";
        cin >> jrny_typ;

        if (jrny_typ == 0) {
            return 0;
        }

        string origin = selectdept();
        string destination = selectDestination();
        string serviceType = selectService();
        string time = selectTime();

        double price = getPrice(origin, destination) + getServicePrice(serviceType);
        double finalPrice = applyDiscount(price);

        int ticketNumber = generateTicketNumber(ticketCounter);
        printTicket(origin, destination, serviceType, finalPrice, time, ticketNumber);

        totalBill += finalPrice;
        totalTickets++;

    cout << "\n\t--------------------------------------------\n";
    cout << "\tTotal Tickets Booked: " << totalTickets << endl;
    cout << "\tTotal Bill: Rs. " << totalBill << endl;
    cout << "\t--------------------------------------------\n";


    cout << "\n\tDo you want to book another ticket ? \n ";
    cout << "Press 1 to book another Ticket \n ";
    cout << "Press 2 to Exit : ";
    cin>>c1;

    if(c1 == 1){
        main();
    }


    return 0;
}
