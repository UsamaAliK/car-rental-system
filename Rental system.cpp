#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <unistd.h>

using namespace std;

class Car {
private:
    string cname;
    string model;
    string company;
    string color;
    bool available;
    double rent;





public:
     Car() : available(true), rent(0.0) {}

    // Getter and Setter  methods
    string getCname() const { return cname; }
    void setCname(const string& name) { cname = name; }

    string getModel() const { return model; }
    void setModel(const string& model_) { model = model_; }

    string getCompany() const { return company; }
    void setCompany(const string& company_) { company = company_; }

    string getColor() const { return color; }
    void setColor(const string& color_) { color = color_; }

    bool isAvailable() const { return available; }
    void setAvailable(bool available_) { available = available_; }

    double getRent() const { return rent; }
    void setRent(double rent_) { rent = rent_; }
};



class admin : public Car{
public:


    void addcar() {
        Car car;
        string temp;
        cout << "Enter the car name: ";
        getline(cin, temp);
        car.setCname(temp);
        cout << "Enter the car model: ";
        getline(cin, temp);
        car.setModel(temp);
        cout << "Enter the car company: ";
        getline(cin, temp);
        car.setCompany(temp);
        cout << "Enter the car color: ";
        getline(cin, temp);
        car.setColor(temp);
        cout << "Enter the car rent per day: ";
        double rent;
        cin >> rent;
        car.setRent(rent);
        cin.ignore();

        ofstream cars("carrz.txt", ios::app);
        cars << car.getCname() << "\t " << car.getModel() << "\t " << car.getCompany() << "\t " << car.getColor() << "\t " << car.isAvailable() << "\t " << car.getRent() << endl;
        cars.close();

        cout << "Car added successfully!" << endl;
    }

    void searchcar() {
        string searchCriteria;
        cout << "Enter the car name to search: ";
        getline(cin, searchCriteria);
        cout << "---------------\n";
        cout << "AVAILABLE CARS WITH THIS NAME: \n";

        ifstream cars("carrz.txt");
        bool found = false;
        string line;

        while (getline(cars, line)) {
            stringstream SC(line);
            Car car;

            string cname, model, company, color;
            bool available;
            double rent;

            SC >> cname >> model >> company >> color >> available >> rent;

            car.setCname(cname);
            car.setModel(model);
            car.setCompany(company);
            car.setColor(color);
            car.setAvailable(available);
            car.setRent(rent);

            if (searchCriteria == car.getCname()) {
                cout << "Name: " << car.getCname() << endl;
                cout << "Model: " << car.getModel() << endl;
                cout << "Company: " << car.getCompany() << endl;
                cout << "Color: " << car.getColor() << endl;
                cout << "Availability: " << (car.isAvailable() ? "Available" : "Not Available") << endl;
                cout << "Rent: $" << fixed << setprecision(2) << car.getRent() << " per day" << endl;
                cout << "------------------------------------\n";

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
        cout << "-------------------\n";
        cout << "AVAILABLE CARS WITH PROVIDED CRITERIA: \n";

        ifstream cars("carrz.txt");
        bool found = false;
        string line;





        while (getline(cars, line)) {
            stringstream SC(line);
            Car car;

            string cname, model, company, color;
            bool available;
            double rent;

            SC >> cname >> model >> company >> color >> available >> rent;

            car.setCname(cname);
            car.setModel(model);
            car.setCompany(company);
            car.setColor(color);
            car.setAvailable(available);
            car.setRent(rent);

            switch (searchOption) {
                case 1:
                    if (searchCriteria == car.getColor()) {
                        cout << "Name: " << car.getCname() << endl;
                        cout << "Model: " << car.getModel() << endl;
                        cout << "Company: " << car.getCompany() << endl;
                        cout << "Color: " << car.getColor() << endl;
                        cout << "Availability: " << (car.isAvailable() ? "Available" : "Not Available") << endl;
                        cout << "Rent: $" << fixed << setprecision(2) << car.getRent() << " per day" << endl;
                        cout << "----------------------------------\n";
                        found = true;
                    }
                    break;



                case 2:
                    if (searchCriteria == car.getModel()) {
                        cout << "Name: " << car.getCname() << endl;
                        cout << "Model: " << car.getModel() << endl;
                        cout << "Company: " << car.getCompany() << endl;
                        cout << "Color: " << car.getColor() << endl;
                        cout << "Availability: " << (car.isAvailable() ? "Available" : "Not Available") << endl;
                        cout << "Rent: $" << fixed << setprecision(2) << car.getRent() << " per day" << endl;
                        cout << "---------------------------------\n";
                        found = true;
                    }
                    break;





                case 3:
                    if (searchCriteria == car.getCompany()) {
                        cout << "Name: " << car.getCname() << endl;
                        cout << "Model: " << car.getModel() << endl;
                        cout << "Company: " << car.getCompany() << endl;
                        cout << "Color: " << car.getColor() << endl;
                        cout << "Availability: " << (car.isAvailable() ? "Available" : "Not Available") << endl;
                        cout << "Rent: $" << fixed << setprecision(2) << car.getRent() << " per day" << endl;
                        cout << "------------------------------------\n";
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
        cout << "***ALL CARS****" << endl;
        while (getline(cars, line)) {
            stringstream SC(line);
            Car car;

            string cname, model, company, color;
            bool available;
            double rent;

            SC >> cname >> model >> company >> color >> available >> rent;

            car.setCname(cname);
            car.setModel(model);
            car.setCompany(company);
            car.setColor(color);
            car.setAvailable(available);
            car.setRent(rent);

            cout << "Name: " << car.getCname() << endl;
            cout << "Model: " << car.getModel() << endl;
            cout << "Company: " << car.getCompany() << endl;
            cout << "Color: " << car.getColor() << endl;
            cout << "Availability: " << (car.isAvailable() ? "Available" : "Not Available") << endl;
            cout << "Rent: $" << fixed << setprecision(2) << car.getRent() << " per day" << endl;
            cout << endl;
        }

        cars.close();
    }
};

class customer : public admin{
public:
    int days;

    void rentcar() {
        string carName;
        cout << "Enter the name of the car you want to rent: ";
        getline(cin, carName);
        cout << "For how many days you want the car: ";
        cin >> days;

        ifstream cars("carrz.txt");
        ofstream temp("temp.txt");
        bool found = false;
        string line;

        while (getline(cars, line)) {
            stringstream SC(line);
            Car car;

            string cname, model, company, color;
            bool available;
            double rent;

            SC >> cname >> model >> company >> color >> available >> rent;

            car.setCname(cname);
            car.setModel(model);
            car.setCompany(company);
            car.setColor(color);
            car.setAvailable(available);
            car.setRent(rent);

            if (carName == car.getCname() && car.isAvailable()) {
                cout << "Car is available." << endl;
                cout << "You have rented " << car.getCname() << " for " << days << " days." << endl;
                cout << "Total rent is: $" << fixed << setprecision(2) << car.getRent() * days << endl;
                car.setAvailable(false);
                found = true;
            }

            temp << car.getCname() << "\t " << car.getModel() << "\t " << car.getCompany() << "\t " << car.getColor() << "\t " << car.isAvailable() << "\t " << car.getRent() << endl;
        }

        cars.close();
        temp.close();

        if (!found) {
            cout << "Car not available." << endl;
        }

        remove("carrz.txt");
        rename("temp.txt", "carrz.txt");
    }
};

int main() {
    admin adm;
    customer cust;

    int choice;
    while (true) {
        cout << "***** CAR RENTAL SYSTEM *****" << endl;
        cout << "1. Add Car" << endl;
        cout << "2. Search Car by Name" << endl;
        cout << "3. Search Car by Other Criteria" << endl;
        cout << "4. Display All Cars" << endl;
        cout << "5. Rent a Car" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                adm.addcar();
                break;
            case 2:
                adm.searchcar();
                break;
            case 3:
                adm.searchcaar();
                break;
            case 4:
                adm.display();
                break;
            case 5:
                cust.rentcar();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice.  Please try again." << endl;
        }
    }
}
