#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include<unistd.h>

using namespace std;

class Car {
public:
    string cname;
    string model;
    string company;
    string color;
    bool available;
    double rent;

    Car() {
        available = true;
        rent = 0.0;
    }
};

class admin {
public:
    void addcar() {
        Car car;
        cout << "Enter the car name: ";
        getline(cin, car.cname);
        cout << "Enter the car model: ";
        getline(cin, car.model);
        cout << "Enter the car company: ";
        getline(cin, car.company);
        cout << "Enter the car color: ";
        getline(cin, car.color);
        cout << "Enter the car rent per day: ";
        cin >> car.rent;
        cin.ignore();

        ofstream cars("carrz.txt", ios::app);
        cars << car.cname << "\t " << car.model << "\t " << car.company << "\t " << car.color << "\t " << car.available << "\t " << car.rent << endl;
        cars.close();

        cout << "Car added successfully!" << endl;
    }

    void searchcar() {
        string searchCriteria;
        cout << "Enter the car name to search: ";
        getline(cin, searchCriteria);
        cout<<"---------------\n";
        cout<<"AVAILABLE CARS WITH THIS NAME: \n";

        ifstream cars("carrz.txt");
        bool found = false;
        string line;

        while (getline(cars, line)) {
            stringstream SC(line);
            Car car;

            SC >> car.cname >> car.model >> car.company >> car.color >> car.available >> car.rent;

            if (searchCriteria == car.cname) {
                cout << "Name: " << car.cname << endl;
                cout << "Model: " << car.model << endl;
                cout << "Company: " << car.company << endl;
                cout << "Color: " << car.color << endl;
                cout << "Availability: " << (car.available ? "Available" : "Not Available") << endl;
                cout << "Rent: $" << fixed << setprecision(2) << car.rent << " per day" << endl;
                cout<<"------------------------------------\n";

                found = true;
                
            }
        }

        cars.close();

        if (!found) {
            cout << "No car found with the given name." << endl;
        }
    }

    void searchcaar() {
        int searchOption;
        string searchCriteria;

        cout << "Search car by: " << endl;
        cout << "1. Color" << endl;
        cout << "2. Model" << endl;
        cout << "3. Company" << endl;
        cout << "Enter your choice: ";
        cin >> searchOption;
        cin.ignore();
        system("clear");

        cout << "Enter the search criteria: ";
        getline(cin, searchCriteria);
        cout<<"-------------------\n";
        cout<<"AVAILABLE CARS WITH PROVIDED CRITERIA: \n";

        ifstream cars("carrz.txt");
        bool found = false;
        string line;

        while (getline(cars, line)) {
            stringstream SC(line);
            Car car;

            SC >> car.cname >> car.model >> car.company >> car.color >> car.available >> car.rent;

            switch (searchOption) {
                case 1:
                    if (searchCriteria == car.color) {
                        cout << "Name: " << car.cname << endl;
                        cout << "Model: " << car.model << endl;
                        cout << "Company: " << car.company << endl;
                        cout << "Color: " << car.color << endl;
                        cout << "Availability: " << (car.available ? "Available" : "Not Available") << endl;
                        cout << "Rent: $" << fixed << setprecision(2) << car.rent << " per day" << endl;
                        cout<<"----------------------------------\n";
                        found = true;

                    }
                    break;
                case 2:
                    if (searchCriteria == car.model) {
                        cout << "Name: " << car.cname << endl;
                        cout << "Model: " << car.model << endl;
                        cout << "Company: " << car.company << endl;
                        cout << "Color: " << car.color << endl;
                        cout << "Availability: " << (car.available ? "Available" : "Not Available") << endl;
                        cout << "Rent: $" << fixed << setprecision(2) << car.rent << " per day" << endl;
                        cout<<"---------------------------------\n";
                        found = true;
                    }
                    break;
                case 3:
                    if (searchCriteria == car.company) {
                        cout << "Name: " << car.cname << endl;
                        cout << "Model: " << car.model << endl;
                        cout << "Company: " << car.company << endl;
                        cout << "Color: " << car.color << endl;
                        cout << "Availability: " << (car.available ? "Available" : "Not Available") << endl;
                        cout << "Rent: $" << fixed << setprecision(2) << car.rent << " per day" << endl;
                        cout<<"----------------------------------\n";
                        found = true;
                    }
                    break;
                default:
                    cout << "Invalid search option." << endl;
                    break;
            }
        }

        cars.close();

        if (!found) {
            cout << "No car found with the given criteria." << endl;
        }
    }

    void display() {
        ifstream cars("carrz.txt");
        string line;
         cout<<"***ALL CARS****"<<endl;
        while (getline(cars, line)) {
            stringstream SC(line);
            Car car;

            SC >> car.cname >> car.model >> car.company >> car.color >> car.available >> car.rent;

            cout << "Name: " << car.cname << endl;
            cout << "Model: " << car.model << endl;
            cout << "Company: " << car.company << endl;
            cout << "Color: " << car.color << endl;
            cout << "Availability: " << (car.available ? "Available" : "Not Available") << endl;
            cout << "Rent: $" << fixed << setprecision(2) << car.rent << " per day" << endl;
            cout << endl;
        }

        cars.close();
    }
};

class customer  {
public:
int  days;
    void rentcar() {
        string carName;
        cout << "Enter the name of the car you want to rent: ";
        getline(cin, carName);
        cout<<"For how many days you want the car: ";
        cin>>days;

        ifstream cars("carrz.txt");
        ofstream temp("temp.txt");
        bool found = false;
        string line;

        while (getline(cars, line)) {
            stringstream SC(line);
            Car car;

            SC >> car.cname >> car.model >> car.company >> car.color >> car.available >> car.rent;

            if (carName == car.cname && car.available) {
                car.available = false;
                temp << car.cname << " " << car.model << " " << car.company << " " << car.color << " " << car.available << " " << car.rent << endl;
                cout << "You have rented the car " << carName << "." << endl;
                found = true;
            } else {
                temp << line << endl;
            }
        }

        if (!found) {
            cout << "The car " << carName << " is not available for rent." << endl;
        }

        cars.close();
        temp.close();

        remove("carrz.txt");
        rename("temp.txt", "carrz.txt");
    }

    void returncar() {
        double totalrent;
        string carName;
        cout << "Enter the name of the car you want to return: ";
        getline(cin, carName);

        ifstream cars("carrz.txt");
        ofstream temp("temp.txt");
        bool found = false;
        string line;

        while (getline(cars, line)) {
            stringstream SC(line);
            Car car;

            SC >> car.cname >> car.model >> car.company >> car.color >> car.available >> car.rent;

            if (carName == car.cname && !car.available) {
                car.available = true;
                temp << car.cname << " " << car.model << " " << car.company << " " << car.color << " " << car.available << " " << car.rent << endl;
                cout << "You have returned the car " << carName << "." << endl;
                cout<<"Your total bill is: ";
                totalrent=days*car.rent;
                cout<<totalrent<<"$";
                
                
                found = true;
            } else {
                temp << line << endl;
            }
        }

        if (!found) {
            cout << "You have not rented the car " << carName << "." << endl;
        }

        cars.close();
        temp.close();

        remove("carrz.txt");
        rename("temp.txt", "carrz.txt");
    }

    void display() {
        ifstream cars("carrz.txt");
        string line;

        while (getline(cars, line)) {
            stringstream SC(line);
            Car car;

            SC >> car.cname >> car.model >> car.company >> car.color >> car.available >> car.rent;

            cout << "Name: " << car.cname << endl;
            cout << "Model: " << car.model << endl;
            cout << "Company: " << car.company << endl;
            cout << "Color: " << car.color << endl;
            cout << "Availability: " << (car.available ? "Available" : "Not Available") << endl;
            cout << "Rent: $" << fixed << setprecision(2) << car.rent << " per day" << endl;
            cout << endl;
        }

        cars.close();
    }
};

int main() {
    cout<<"*****     WELCOME TO CAR  RENTAL SYSTEM    ******"<<endl;   
    sleep(2);
    int option;
    admin adminObj;
    customer customerObj;
    string userType;

    cout << "Are you a seller or a buyer? Enter 'seller' or 'buyer': ";
    getline(cin, userType);

    if (userType == "seller") {
        string email, password;

        cout << "Are you a registered seller? Enter 'yes' or 'no': ";
        string registered;
        getline(cin, registered);

        if (registered == "no") {
            cout << "Registration Form" << endl;
            cout << "Enter your email address: ";
            getline(cin, email);
            cout << "Enter your password: ";
            getline(cin, password);

            // Save the registration details in a file or database
            ofstream sellerFile("sellers.txt", ios::app);
            sellerFile << email << "," << password << endl;
            sellerFile.close();

            cout << "Registration successful! You can now log in as a seller." << endl;
        } else if (registered == "yes") {
            cout << "Enter your email address: ";
            getline(cin, email);
            cout << "Enter your password: ";
            getline(cin, password);

            // Check if the email and password match any registered seller
            ifstream sellerFile("sellers.txt");
            string line;
            bool found = false;

            while (getline(sellerFile, line)) {
                stringstream SS(line);
                string savedEmail, savedPassword;
                getline(SS, savedEmail, ',');
                getline(SS, savedPassword);

                if (email == savedEmail && password == savedPassword) {
                    found = true;
                    break;
                }
            }

            sellerFile.close();

            if (found) {
                do {
                    // Seller menu options
                    cout << "----- Seller Menu -----" << endl;
                    cout << "Select an option:" << endl;
                    cout << "1. Add a car" << endl;
                    cout << "2. Search a car by name" << endl;
                    cout << "3. Search cars by color, model, or company" << endl;
                    cout << "4. Display all cars" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> option;
                    cin.ignore();

                    switch (option) {
                        case 1:
                        system("clear");
                            adminObj.addcar();
                            break;
                        case 2:
                        system("clear");
                            adminObj.searchcar();
                            break;
                        case 3:
                        system("clear");
                            adminObj.searchcaar();
                            break;
                        case 4:
                        system("clear");
                            adminObj.display();
                            break;
                        case 0:
                            cout << "Exiting the program. Goodbye!" << endl;
                            break;
                        default:
                            cout << "Invalid option. Please try again." << endl;
                            break;
                    }

                    cout << endl;
                } while (option != 0);
            } else {
                cout << "Invalid email or password. Access denied." << endl;
            }
        } else {
            cout << "Invalid response. Please try again." << endl;
        }
    } else if (userType == "buyer") {
        string email, password;

        cout << "Are you a registered buyer? Enter 'yes' or 'no': ";
        string registered;
        getline(cin, registered);

        if (registered == "no") {
            cout << "Registration Form" << endl;
            cout << "Enter your email address: ";
            getline(cin, email);
            cout << "Enter your password: ";
            getline(cin, password);

            // Save the registration details in a file or database
            ofstream buyerFile("buyers.txt", ios::app);
            buyerFile << email << "," << password << endl;
            buyerFile.close();

            cout << "Registration successful! You can now log in as a buyer." << endl;
        } 
        else if (registered == "yes") {
            cout << "Enter your email address: ";
            getline(cin, email);
            cout << "Enter your password: ";
            getline(cin, password);

            // Check if the email and password match any registered buyer
            ifstream buyerFile("buyers.txt");
            string line;
            bool found = false;

            while (getline(buyerFile, line)) {
                stringstream SS(line);
                string savedEmail, savedPassword;
                getline(SS, savedEmail, ',');
                getline(SS, savedPassword);

                if (email == savedEmail && password == savedPassword) {
                    found = true;
                    break;
                }
            }

            buyerFile.close();
            system("clear");
        

            if (found) {
                do {
                    // Buyer menu options
                    cout << "----- Buyer Menu -----" << endl;
                    cout << "Select an option:" << endl;
                    cout << "1. Display cars" << endl;
                    cout << "2. Rent a car" << endl;
                    cout << "3. Return a car" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> option;
                    cin.ignore();

                    switch (option) {
                        case 1:
                        system("clear");
                            customerObj.display();
                            break;
                        case 2:
                        system("clear");
                            customerObj.rentcar();
                            break;
                        case 3:
                        system("clear");
                            customerObj.returncar();
                            break;
                        case 0:
                            cout << "Exiting the program. Goodbye!" << endl;
                            break;
                        default:
                            cout << "Invalid option. Please try again." << endl;
                            break;
                    }

                    cout << endl;
                } while (option != 0);
            } else {
                cout << "Invalid email or password. Access denied." << endl;
            }
        } else {
            cout << "Invalid response. Please try again." << endl;
        }
    } else {
        cout << "Invalid user type. Please try again." << endl;
    }

    return 0;
}
