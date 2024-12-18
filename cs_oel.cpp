#include <iostream>
#include <string>
using namespace std;

double getServicePrice(string serviceType) {
	
	//distinguishes price for each service type
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
    
    //Promts user to select Service type
    cout << "\n\tPLEASE SELECT YOUR SERVICE TYPE (enter number)\n";
    cout << "\t1. Economy\n";
    cout << "\t2. Standard\n";
    cout << "\t3. VIP\n";
    cout << "\t0. CANCEL RESERVATION\n\n";
    cout << "\tEnter your choice: ";
    cin >> serviceChoice;

    switch (serviceChoice) {
    	
    	//returns string value to srvice variables
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
	
		//returns price based on departure and destination
		
    if (origin == "KARACHI") {
        if (destination == "ISLAMABAD") return 2500.0;
        if (destination == "LAHORE") return 2200.0;
        if (destination == "TAXILA") return 1800.0;
        if (destination == "JHELUM") return 1900.0;
    } else if (origin == "ISLAMABAD") {
        if (destination == "KARACHI") return 2500.0;
        if (destination == "LAHORE") return 2000.0;
        if (destination == "TAXILA") return 800.0;
        if (destination == "JHELUM") return 1000.0;
    } else if (origin == "LAHORE") {
        if (destination == "KARACHI") return 2200.0;
        if (destination == "ISLAMABAD") return 2000.0;
        if (destination == "TAXILA") return 1000.0;
        if (destination == "JHELUM") return 1200.0;
    } else if (origin == "TAXILA") {
        if (destination == "KARACHI") return 1800.0;
        if (destination == "ISLAMABAD") return 800.0;
        if (destination == "LAHORE") return 1000.0;
        if (destination == "JHELUM") return 1200.0;
    } else if (origin == "SWABI") {
        if (destination == "KARACHI") return 1900.0;
        if (destination == "ISLAMABAD") return 1000.0;
        if (destination == "LAHORE") return 1200.0;
        if (destination == "TAXILA") return 1200.0;
    }
    return 0.0;
}

string selectOrigin() {
    int orgn;
    
    
    // SHOWS DEPARTURE POINTS
    cout << "\n\tPLEASE SELECT YOUR JOURNEY'S ORIGIN (enter number)\n";
    cout << "\t1. KARACHI\n";
    cout << "\t2. ISLAMABAD\n";
    cout << "\t3. LAHORE\n";
    cout << "\t4. TAXILA\n";
    cout << "\t5. SWABI\n";
    cout << "\t0. CANCEL RESERVATION\n\n";
    cout << "\tEnter your choice: ";
    cin >> orgn;
    switch (orgn) {
    	
    	// RETURNS STRING VALUE BASED ON USER SELECTION
        case 1: return "KARACHI";
        case 2: return "ISLAMABAD";
        case 3: return "LAHORE";
        case 4: return "TAXILA";
        case 5: return "SWABI";
        case 0:
            cout << "\n\tCANCELLING RESERVATION...\n";
            exit(0);
        default:
            cout << "\n\tInvalid input. Try again.\n";
            return selectOrigin();
    }
}

string selectDestination() {
    int dest;
    
    // SHOWS AVAILABLE DESTINATIONS POINTS
    cout << "\n\tPLEASE SELECT YOUR JOURNEY'S DESTINATION (enter number)\n";
    cout << "\t1. KARACHI\n";
    cout << "\t2. ISLAMABAD\n";
    cout << "\t3. LAHORE\n";
    cout << "\t4. TAXILA\n";
    cout << "\t5. JHELUM\n";
    cout << "\t0. CANCEL RESERVATION\n\n";
    cout << "\tEnter your choice: ";
    cin >> dest;
    switch (dest) {
    	
    	// RETURNS DESTINATION TO STRING "DESTINATION"
        case 1: return "KARACHI";
        case 2: return "ISLAMABAD";
        case 3: return "LAHORE";
        case 4: return "TAXILA";
        case 5: return "JHELUM";
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
    
    // ASKS USER TO SELECT JOURNEY TIME 
    cout << "\n\tAVAILABLE TIMES FOR YOUR JOURNEY (enter number)\n";
    cout << "\t1. 09:00 AM\n";
    cout << "\t2. 12:00 PM\n";
    cout << "\t3. 03:00 PM\n";
    cout << "\t4. 06:00 PM\n";
    cout << "\t0. CANCEL RESERVATION\n\n";
    cout << "\tEnter your choice: ";
    cin >> timeChoice;

    switch (timeChoice) {
    	
    	//RETURNS JOURNEY TIME 
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



int generateTicketNumber(int &ticketCounter) {
	
	//increments tickets number
    return ticketCounter++;
}

//prints final ticket slip by using necessary arguments
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
    int jrny_typ;
    static int ticketCounter = 10001;
    double totalBill = 0.0;
    int totalTickets = 0;

    char continueBooking = 'y';                                 
    while (continueBooking == 'y' || continueBooking == 'Y') {
    	
    	// MENUE SCREEN
        cout << "\n\tWELCOME TO THE BUS RESERVATION SYSTEM!\n\n";
        cout << "\tPLEASE SELECT JOURNEY TYPE (enter number)\n";
        cout << "\t1. ROUND TRIP\n";
        cout << "\t2. ONE-WAY\n";
        cout << "\t0. EXIT\n\n";
        cout << "\tEnter your choice: ";
        cin >> jrny_typ;

        if (jrny_typ == 0) {
            break;
        }
			
			// EACH VARIABLE CALLS RESPECTIVE FUNCTIONS
        string origin = selectOrigin();
        string destination = selectDestination();
        string serviceType = selectService();
        string time = selectTime();

		// CALCULATES FINAL PRICE BASED ON SELECTED DESTINATION AND SERVICE 
        double price = getPrice(origin, destination) + getServicePrice(serviceType);
        double finalPrice = price;
		
        int ticketNumber = generateTicketNumber(ticketCounter);
        
        // PRINTS FINAL TICKET PRICE AND DESTINATIONV AND TIME
        printTicket(origin, destination, serviceType, finalPrice, time, ticketNumber);

        totalBill += finalPrice;
        totalTickets++;
		
		// ASKS USER WHETHER TO BOOK AGAIN OR NOT
        cout << "\n\tDo you want to book another ticket? (y/n): ";
        cin >> continueBooking;
    }

    cout << "\n\t--------------------------------------------\n";
    cout << "\tTotal Tickets Booked: " << totalTickets << endl;
    cout << "\tTotal Bill: Rs. " << totalBill << endl;
    cout << "\t--------------------------------------------\n";

    return 0;
}
