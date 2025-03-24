#include <iostream>
#include <string>

using namespace std;

const int MAX_DONATIONS = 100; // Maximum number of donations
const int MAX_REQUESTS = 100;   // Maximum number of requests

struct Donation {
    string name;
    string contact;
    string type;
    bool confirmed;
};

struct Request {
    string name;
    string contact;
    string needFor;
    string reason;
    bool confirmed;
};

Donation donations[MAX_DONATIONS];
Request requests[MAX_REQUESTS];
int donationCount = 0;
int requestCount = 0;
string history[MAX_DONATIONS]; // Assuming history can hold the same number of donations
int historyCount = 0;

void clearScreen() {
    // For Windows
    system("CLS");
}

void becomeDonor() {
    if (donationCount < MAX_DONATIONS) {
        Donation newDonation;
        
        cout << "================================================" << endl;
        cout <<"|Please input the following information below: |" << endl;
        cout << "================================================" << endl;
        cout << "Enter your name: ";
        cin >> newDonation.name;
        cout << "Enter your contact number: ";
        cin >> newDonation.contact;

        // Define donation types
        string donationTypes[] = {
            "Blood",
            "Medicines",
            "Food and Water",
            "Clothes",
            "First Aid Supplies",
            "Flashlights, Batteries, Power Banks"
        };

        // Display donation types
        cout << endl;
        cout << "==========================" << endl;
        cout << "|Select type of donation:|" << endl;
        cout << "==========================" << endl;
        
        for (int i = 0; i < 6; i++) {
            cout << i + 1 << ". " << donationTypes[i] << endl;
        }

        // Get user input for donation type
        int choice;
        cout << "Enter the number corresponding to your choice: ";
        cin >> choice;

        // Validate choice and assign type
        if (choice >= 1 && choice <= 6) {
            newDonation.type = donationTypes[choice - 1]; // Store the selected type
        } else {
            cout << "Invalid choice. Donation type set to 'Unknown'." << endl;
            newDonation.type = "Unknown"; // Default value for invalid input
        }
		cout << endl;
		cout << "==========================================" << endl;
        cout << "|Confirm donation (1 for Yes, 0 for No): |" << endl;
        cout << "==========================================" << endl;
        cin >> newDonation.confirmed;

        if (newDonation.confirmed) {
            donations[donationCount++] = newDonation; // Store in array and increment count
            cout << "Donation confirmed!" << endl;
        }
    } else {
        cout << "Donation limit reached!" << endl;
    }
}


void applyForAid() {
    if (requestCount < MAX_REQUESTS) {
        Request newRequest;
        cout << "================================================" << endl;
        cout <<"|Please input the following information below: |" << endl;
        cout << "=================================================" << endl;
        cout << "Enter your name: ";
        cin >> newRequest.name;
        cout << "Enter your contact number: ";
        cin >> newRequest.contact;

        // Define disaster aid types
        string disasterAidTypes[] = {
            "Food and water",
            "Clothes",
            "Medicines",
            "First Aid Kit",
            "Flashlights, Batteries, Powerbank",
            "Blood"
        };

        // Display disaster aid types
        cout << endl;
        cout << "======================================" << endl;
        cout << "|Select type of disaster aid needed: |" << endl;
         cout << "=====================================" << endl;
        for (int i = 0; i < 6; i++) {
            cout << i + 1 << ". " << disasterAidTypes[i] << endl;
        }

        // Get user input for disaster aid type
        int choice;
        cout << "Enter the number corresponding to your choice: ";
        cin >> choice;

        // Validate choice and assign needFor
        if (choice >= 1 && choice <= 6) {
            newRequest.needFor = disasterAidTypes[choice - 1]; // Store the selected type
        } else {
            cout << "Invalid choice. Aid type set to 'Unknown'." << endl;
            newRequest.needFor = "Unknown"; // Default value for invalid input
        }

        // Define reasons for aid
        string reasons[] = {
            "Flooding",
            "Tsunami",
            "Storm surge",
            "Earthquake",
            "Landslide",
            "Volcanic Eruptions",
            "Terrorist attack"
        };

        // Display reasons for aid
        cout << endl;
        cout << "======================================" << endl;
        cout << "|Select the reason for your request: | " << endl;
        cout << "======================================" << endl;
        for (int i = 0; i < 7; i++) {
            cout << i + 1 << ". " << reasons[i] << endl;
        }

        // Get user input for reason
        cout << "Enter the number corresponding to your reason: ";
        cin >> choice;

        // Validate choice and assign reason
        if (choice >= 1 && choice <= 7) {
            newRequest.reason = reasons[choice - 1]; // Store the selected reason
        } else {
            cout << "Invalid choice. Reason set to 'Unknown'." << endl;
            newRequest.reason = "Unknown"; // Default value for invalid input
        }
		cout << endl;
        cout << "Confirm request (1 for Yes, 0 for No): ";
        cin >> newRequest.confirmed;

        if (newRequest.confirmed) {
            requests[requestCount++] = newRequest; // Store in array and increment count
            cout << "Request for aid confirmed!" << endl;
        }
    } else {
        cout << "Request limit reached!" << endl;
    }
}

void viewPendingDonations() {
    clearScreen();
    if (donationCount == 0) {
        cout << "No pending donations." << endl;
    } else {
        for (int i = 0; i < donationCount; i++) {
            cout << "Name: "  << donations[i].name << endl << "Contact: "<< donations[i].contact 
                 << endl << "Type: " << donations[i].type << endl;
                 cout << endl;
        }
    }
}

void viewPendingRequests() {
    clearScreen();
    if (requestCount == 0) {
        cout << "No pending requests." << endl;
    } else {
        for (int i = 0; i < requestCount; i++) {
            cout << "Name: "<< requests[i].name << endl << "Contact: " << requests[i].contact 
                 << endl <<"Need For: "  << requests[i].needFor << endl << "Reason: " << requests[i].reason << endl;
                 cout << endl;
        }
    }
}

void manageDonationsAndRequests() {
    clearScreen();
    string donorName, requestName;
    
    cout << "Enter the name of the donor: ";
    cin >> donorName;
    
    bool donorFound = false;
    for (int i = 0; i < donationCount; i++) {
        if (donations[i].name == donorName) {
            cout << "Donor found: " << donations[i].name << ", Contact: " << donations[i].contact 
                 << ", Type: " << donations[i].type << endl;
            donorFound = true;
            break;
        }
    }
    
    if (!donorFound) {
        cout << "No donor found." << endl;
        return;
    }

    cout << "Enter the name of the request: ";
    cin >> requestName;

    bool requestFound = false;
    for (int i = 0; i < requestCount; i++) {
        if (requests[i].name == requestName) {
            cout << "Request found: " << requests[i].name << ", Contact: " << requests[i].contact 
                 << ", Need For: " << requests[i].needFor << ", Reason: " << requests[i].reason << endl;
            requestFound = true;
            break;
        }
    }

    if (!requestFound) {
        cout << "No request found." << endl;
        return;
    }

    cout << "Would you like to edit the information? (1 for Yes, 0 for No): ";
    bool edit;
    cin >> edit;

    if (edit) {
        // Edit donor information
        for (int i = 0; i < donationCount; i++) {
            if (donations[i].name == donorName) {
                cout << "Enter new donor name (leave empty to keep current): ";
                string newName;
                cin >> newName;
                if (!newName.empty()) {
                    donations[i].name = newName;
                }

                cout << "Enter new donor contact (leave empty to keep current): ";
                string newContact;
                cin >> newContact;
                if (!newContact.empty()) {
                    donations[i].contact = newContact;
                }
            }
        }

        // Edit recipient information
        for (int i = 0; i < requestCount; i++) {
            if (requests[i].name == requestName) {
                cout << "Enter new recipient name (leave empty to keep current): ";
                string newName;
                cin >> newName;
                if (!newName.empty()) {
                    requests[i].name = newName;
                }

                cout << "Enter new recipient contact (leave empty to keep current): ";
                string newContact;
                cin >> newContact;
                if (!newContact.empty()) {
                    requests[i].contact = newContact;
                }
            }
        }

        cout << "Information updated successfully!" << endl;
    }

    cout << "Confirm donor and recipient (1 for Yes, 0 for No): ";
    bool confirm;
    cin >> confirm;

    if (confirm) {
        history[historyCount++] = "Donor: " + donorName + " has donated to " + requestName;
        cout << "Donation confirmed and recorded in history." << endl;
    }
}

void viewHistoryAndReports() {
    clearScreen();
    if (historyCount == 0) {
        cout << "No history available." << endl;
        return;
    } 

    // Display history with current names
    for (int i = 0; i < historyCount; i++) {
        // Extract donor and recipient names from history string
        string donorName, recipientName;
        size_t donorPos = history[i].find("Donor: ") + 6;
        size_t recipientPos = history[i].find(" has donated to ") + 16;
        
        if (donorPos != string::npos && recipientPos != string::npos) {
            // Extract names
            donorName = history[i].substr(donorPos, recipientPos - donorPos - 1);
            recipientName = history[i].substr(recipientPos);
            
            // Find current donor name
            string currentDonorName = donorName;
            for (int j = 0; j < donationCount; j++) {
                if (donations[j].name == currentDonorName) {
                    currentDonorName = donations[j].name;
                    break;
                }
            }
            
            // Find current recipient name
            string currentRecipientName = recipientName;
            for (int k = 0; k < requestCount; k++) {
                if (requests[k].name == currentRecipientName) {
                    currentRecipientName = requests[k].name;
                    break;
                }
            }
            
            // Display with current names
            cout << "Donor: " << currentDonorName << " has donated to " << currentRecipientName;
            cout << " (Original: " << donorName << " -> " << recipientName << ")" << endl;
        } else {
            cout << history[i] << endl;
        }
    }
}
void adminDashboard() {
    int choice;
    do {
        clearScreen();
        cout << "=============================" << endl;
        cout << "|WELCOME TO ADMIN DASHBOARD!|" << endl;
        cout << "=============================" << endl;
        cout << "1. View Pending Donations" << endl;
        cout << "2. View Pending Requests" << endl;
        cout << "3. Manage Donations and Requests" << endl;
        cout << "4. View History and Reports" << endl;
        cout << "5. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewPendingDonations();
                break;
            case 2:
                viewPendingRequests();
                break;
            case 3:
                manageDonationsAndRequests();
                break;
            case 4:
                viewHistoryAndReports();
                break;
            case 5:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    } while (choice != 5);
}

void adminLogin() {
    string username, password;
    cout << endl;
    
    cout << "=======================" << endl;
    cout << "|Enter admin username:|" << endl;
    cout << "=======================" << endl;
	cin >> username;
	
	cout << "=======================" << endl;
    cout << "|Enter admin password:|" << endl;
    cout << "=======================" << endl;
    cin >> password;

    if (username == "ria" && password == "admin123") {
        cout << "Login successful!" << endl;
        adminDashboard(); // Directly go to the admin dashboard
    } else {
        cout << "Username or password is incorrect, please try again." << endl;
    }
}

int main() {
    int choice;
    do {
        clearScreen();
        cout << "|=====================================|" << endl;
        cout << "|WELCOME TO DISASTER MANAGEMENT SYSTEM|" << endl;
        cout << "|=====================================|" << endl;;
        cout << endl;
        cout << "DISPLAY MENU MENU" << endl;
        cout << "1. Become a donor" << endl;
        cout << "2. Apply for aid" << endl;
        cout << "3. Admin Login" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice:" << endl;
        
        
        cin >> choice;

        switch (choice) {
            case 1:
                becomeDonor();
                break;
            case 2:
                applyForAid();
                break;
            case 3:
                adminLogin();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}