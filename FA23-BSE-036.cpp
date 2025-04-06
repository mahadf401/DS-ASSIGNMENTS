#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Patient structure
struct Patient {
    string name;
    string condition;
    int priority;
    int arrival;

    Patient(string n, string c, int p, int a) {
        name = n;
        condition = c;
        priority = p;
        arrival = a;
    }
};

// Custom comparator for priority queue
struct Compare {
    bool operator()(Patient const& a, Patient const& b) {
        if (a.priority == b.priority)
            return a.arrival > b.arrival;
        return a.priority > b.priority;
    }
};

// Function to display emergency conditions
void showConditions() {
    cout << "\nSelect Emergency Condition:\n";
    cout << "1. Heart Attack\n";
    cout << "2. Stroke\n";
    cout << "3. Broken Leg\n";
    cout << "4. Severe Burn\n";
    cout << "5. Fractured Arm\n";
    cout << "6. Fever\n";
    cout << "7. Food Poisoning\n";
    cout << "8. Migraine\n";
    cout << "9. Mild Cold\n";
    cout << "10. Small Cut\n";
}

// Function to get condition and priority
void getCondition(int choice, string &condition, int &priority) {
    switch (choice) {
        case 1: condition = "Heart Attack"; priority = 1; break;
        case 2: condition = "Stroke"; priority = 1; break;
        case 3: condition = "Broken Leg"; priority = 2; break;
        case 4: condition = "Severe Burn"; priority = 2; break;
        case 5: condition = "Fractured Arm"; priority = 2; break;
        case 6: condition = "Fever"; priority = 3; break;
        case 7: condition = "Food Poisoning"; priority = 3; break;
        case 8: condition = "Migraine"; priority = 3; break;
        case 9: condition = "Mild Cold"; priority = 4; break;
        case 10: condition = "Small Cut"; priority = 4; break;
        default: condition = "Unknown"; priority = 5;
    }
}

int main() {
    priority_queue<Patient, vector<Patient>, Compare> pq;
    int arrival = 0;
    int choice;

    while (true) {
        cout << "\n1. Add Patient\n2. Show Treatment Order\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, condition;
            int condChoice, priority;
            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, name);
            showConditions();
            cout << "Enter condition number: ";
            cin >> condChoice;
            getCondition(condChoice, condition, priority);
            pq.push(Patient(name, condition, priority, ++arrival));
            cout << "Patient added!\n";
        }
        else if (choice == 2) {
            if (pq.empty()) {
                cout << "No patients in queue.\n";
            } else {
                cout << "\n--- Treatment Order ---\n";
                int count = 1;
                priority_queue<Patient, vector<Patient>, Compare> temp = pq;
                while (!temp.empty()) {
                    Patient p = temp.top(); temp.pop();
                    cout << count++ << ". " << p.name << " - " << p.condition
                         << " (Priority " << p.priority << ")\n";
                }
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
