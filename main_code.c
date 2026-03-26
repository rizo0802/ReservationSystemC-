#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TotalnumberofSeats = 7;

const int MaxnumberofPassengers = 7;

class BasePassenger {

public:
    virtual ~BasePassenger() {}
    virtual int getId() const = 0;
    virtual string getName() const = 0;
    virtual double getMoney() const = 0;
    virtual bool isSeated() const = 0;
    virtual void setSeated(bool user_input_seated) = 0;
    virtual void setMoney(double user_input_money) = 0;
};

class Passenger : public BasePassenger {

protected:

    int age;

    double weight;

private:

    int id;

    string name;

    double money;

    bool seated;


public:

    Passenger() : id(0), age(0), weight(0), money(0), seated(false) {}


    Passenger(int user_input_id, const string &user_input_name, int user_input_age, double user_input_weight,
              double user_input_money)
            : id(user_input_id), name(user_input_name), age(user_input_age), weight(user_input_weight),
              money(user_input_money), seated(false) {}




    void setMoney(double user_input_money) override {

        this->money = user_input_money;

    }

    int getId() const override{

        return id;

    }

    string getName() const override{

        return name;

    }


    double getMoney() const override{

        return money;

    }

    bool isSeated() const override{

        return seated;

    }

    void setSeated(bool user_input_seated) override{

        this->seated = user_input_seated;

    }
};


class Seat {

private:

    int SeatsNumber;

    bool CheckIfSeatIsBusiness;

    double BusinessSeatPrice;

public:

    Seat() : SeatsNumber(0), CheckIfSeatIsBusiness(false), BusinessSeatPrice(0), Passenger(nullptr) {}


    Seat(int user_input_number, bool user_input_CheckIfSeatIsBusiness, double user_input_price)
            : SeatsNumber(user_input_number), CheckIfSeatIsBusiness(user_input_CheckIfSeatIsBusiness), BusinessSeatPrice(user_input_price), Passenger(nullptr) {}



    int getNumber() const {

        return SeatsNumber;

    }
    bool getCheckIfSeatIsBusiness() const {

        return CheckIfSeatIsBusiness;

    }
    double getPrice() const {

        return BusinessSeatPrice;

    }

    BasePassenger* getPassenger() const {

        return Passenger;

    }

    void setPassenger(BasePassenger* user_input_Passenger) {

        this->Passenger = user_input_Passenger;

        if (user_input_Passenger) {

            user_input_Passenger->setSeated(true);

        }

    }

    BasePassenger* Passenger;

};

class Airplane {

private:

    Seat seats[TotalnumberofSeats];

public:

    Airplane(int NumberOfBusinessSeats, int NumberOfEconomySeats, double BusinessSeatPrice, double EconomyPrice) {

        for (int i = 0; i < NumberOfBusinessSeats; ++i) {

            seats[i] = Seat(i + 1, true, BusinessSeatPrice);

        }

        for (int i = 0; i < NumberOfEconomySeats; ++i) {

            seats[NumberOfBusinessSeats + i] = Seat(NumberOfBusinessSeats + i + 1, false, EconomyPrice);

        }

    }

    bool bookSeat(Passenger& user_input_Passenger, int user_input_seatNumber) {

        for (int i = 0; i < TotalnumberofSeats; ++i) {

            if (seats[i].getNumber() == user_input_seatNumber) {

                cout << "Seat " << user_input_seatNumber << " costs " << seats[i].getPrice() << "\n";

                if (seats[i].getPassenger() == nullptr) {

                    if (user_input_Passenger.getMoney() >= seats[i].getPrice()) {

                        seats[i].setPassenger(&user_input_Passenger);

                        user_input_Passenger.setMoney(user_input_Passenger.getMoney() - seats[i].getPrice());

                        return true;

                    } else {

                        cout << "Passenger " << user_input_Passenger.getName() << " does not have enough money for seat " << user_input_seatNumber << ".\n";

                    }

                } else {

                    cout << "Seat " << user_input_seatNumber << " is already booked.\n";

                }

                return false;

            }

        }

        cout << "Seat " << user_input_seatNumber << " does not exist. Available seats are:\n";

        for (int i = 0; i < TotalnumberofSeats; ++i) {

            if (seats[i].getPassenger() == nullptr) {

                cout << "Seat " << seats[i].getNumber() << " - Price: " << seats[i].getPrice() << "\n";

            }

        }

        return false;

    }

    void suggestLowerPricedSeats(Passenger& user_input_Passenger) {

        cout << "Suggested lower-priced seats for " << user_input_Passenger.getName() << ":\n";

        for (int i = 0; i < TotalnumberofSeats; ++i) {

            if (seats[i].getPassenger() == nullptr && user_input_Passenger.getMoney() >= seats[i].getPrice()) {

                cout << "Seat " << seats[i].getNumber() << " - Price: " << seats[i].getPrice() << "\n";

            }

        }

    }

    bool swapSeats(int user_input_seatNumber1, int user_input_seatNumber2) {

        Seat* seat1 = nullptr;

        Seat* seat2 = nullptr;

        for (int i = 0; i < TotalnumberofSeats; ++i) {

            if (seats[i].getNumber() == user_input_seatNumber1) {
                seat1 = &seats[i];}

            if (seats[i].getNumber() == user_input_seatNumber2) {
                seat2 = &seats[i];}

        }

        if (seat1 && seat2 && seat1->getPassenger() && seat2->getPassenger()) {

            swap(seat1->Passenger, seat2->Passenger);

            return true;

        }

        return false;

    }

    bool CancelBooking(int user_input_seatNumber) {

        for (int i = 0; i < TotalnumberofSeats; ++i) {

            if (seats[i].getNumber() == user_input_seatNumber && seats[i].getPassenger() != nullptr) {

                seats[i].getPassenger()->setSeated(false);

                seats[i].setPassenger(nullptr);

                return true;

            }

        }

        return false;

    }

    void searchPassengerById(int user_input_id, Passenger Passengers[], int user_input_PassengerCount) {

        for (int i = 0; i < user_input_PassengerCount; ++i) {

            if (Passengers[i].getId() == user_input_id) {

                cout << "Passenger found: " << Passengers[i].getName();

                if (Passengers[i].isSeated()) {

                    for (int j = 0; j < TotalnumberofSeats; ++j) {

                        if (seats[j].getPassenger() && seats[j].getPassenger()->getId() == user_input_id) {

                            cout << " in seat " << seats[j].getNumber() << "\n";

                            return;

                        }

                    }

                } else {

                    cout << " is not seated.\n";

                }

                return;

            }

        }

        cout << "Passenger not found\n";

    }

    void searchPassengerByName(const string& user_input_name, Passenger Passengers[], int user_input_PassengerCount) {

        for (int i = 0; i < user_input_PassengerCount; ++i) {

            if (Passengers[i].getName() == user_input_name) {

                cout << "Passenger found: " << Passengers[i].getName();

                if (Passengers[i].isSeated()) {

                    for (int j = 0; j < TotalnumberofSeats; ++j) {

                        if (seats[j].getPassenger() && seats[j].getPassenger()->getName() == user_input_name) {

                            cout << " in seat " << seats[j].getNumber() << "\n";

                            return;

                        }
                    }
                } else {

                    cout << " is not seated.\n";

                }

                return;

            }

        }

        cout << "Passenger not found\n";

    }

    double getMaxSeatPrice() const {

        double maxPrice = 0;

        for (int i = 0; i < TotalnumberofSeats; ++i) {

            if (seats[i].getPrice() > maxPrice) {

                maxPrice = seats[i].getPrice();

            }

        }

        return maxPrice;

    }

};

int main() {

    cout << "Welcome to the Private Airplane Booking System Station! Choose one of the following options\n";

    Airplane airplane(2, 5, 500, 200);

    Passenger Passengers[MaxnumberofPassengers];

    int PassengerCount = 0;

    srand(time(0));

    while (true) {

        cout << "1. Register\n";
        cout << "2. Generate a passenger\n";
        cout << "3. Search a passenger by their given ID\n";
        cout << "4. Search passenger by their name\n";
        cout << "5. Book a seat\n";
        cout << "6. Cancel booking\n";
        cout << "7. Swap seats between passengers\n";
        cout << "8. Exit application\n";

        int UsersChoice;

        cin >> UsersChoice;

        if (UsersChoice == 1) {

            if (PassengerCount >= MaxnumberofPassengers) {

                cout << "Maximum number of passengers reached. Cannot register more passengers.\n";

                continue;

            }

            int user_input_id = PassengerCount + 1;

            string user_input_name;

            int user_input_age;

            double user_input_weight, user_input_money;

            cout << "Name: ";

            cin >> user_input_name;

            cout << "Age: ";

            cin >> user_input_age;

            cout << "Weight: ";

            cin >> user_input_weight;

            cout << "Money: ";

            cin >> user_input_money;

            Passengers[PassengerCount++] = Passenger(user_input_id, user_input_name, user_input_age, user_input_weight, user_input_money);

            cout << "Your ID is: " << user_input_id << "\n";

        }
        else
            if (UsersChoice == 2) {

                if (PassengerCount >= MaxnumberofPassengers) {

                    cout << "Maximum number of passengers reached. Cannot generate more passengers.\n";

                    continue;

                }

            int user_input_id = PassengerCount + 1;

            string names[] = {"Yuji", "Gojo", "Sukuna", "Jiyan"};

            string user_input_name = names[rand() % 4];

            int user_input_age = rand() % 50 + 18;

            double user_input_weight = rand() % 50 + 50;

            double maxSeatPrice = airplane.getMaxSeatPrice();

            double user_input_money = maxSeatPrice + (rand() % 1000);

            Passengers[PassengerCount++] = Passenger(user_input_id, user_input_name, user_input_age, user_input_weight, user_input_money);

            cout << "Generated passenger with ID: " << user_input_id << " Name: " << user_input_name << "\n";

        }
            else
            if (UsersChoice == 3) {

                int user_input_id;

                cout << "Type passenger ID: ";

                cin >> user_input_id;

                airplane.searchPassengerById(user_input_id, Passengers, PassengerCount);

            }
            else
            if (UsersChoice == 4) {

                string user_input_name;

                cout << "Type passenger name: ";

                cin >> user_input_name;

                airplane.searchPassengerByName(user_input_name, Passengers, PassengerCount);

            }
             else
            if (UsersChoice == 5) {

            int user_input_PassengerId, user_input_seatNumber;{

            cout << "Passenger ID: ";}

            cin >> user_input_PassengerId;

            cout << "What is the seat number ?: ";

            cin >> user_input_seatNumber;

            if (user_input_PassengerId > 0 && user_input_PassengerId <= PassengerCount) {

                if (!airplane.bookSeat(Passengers[user_input_PassengerId - 1], user_input_seatNumber)) {

                    if (user_input_seatNumber <= 0 || user_input_seatNumber > TotalnumberofSeats) {

                        cout << "This is all we have :C\n";

                    }
                    else {

                        cout << "The booking didn't go through because your budget isn't enough or the seat is already booked\n";

                        cout << "Here are some seats still available that may fit your budget!\n";

                        airplane.suggestLowerPricedSeats(Passengers[user_input_PassengerId - 1]);

                    }

                }
                else {

                    cout << "Seat " << user_input_seatNumber << " successfully booked by " << Passengers[user_input_PassengerId - 1].getName() << "\n";

                }

            }
            else {

                cout << "There's no passenger with that ID\n";

            }

        }
            else
            if (UsersChoice == 6) {

                int user_input_seatNumber;

                cout << "Type seat number: ";

                cin >> user_input_seatNumber;

                if (!airplane.CancelBooking(user_input_seatNumber)) {

                    cout << "Cancel booking failed. Try again\n";

                } else {

                    cout << "You canceled the booking of seat " << user_input_seatNumber << "\n";

                }
            }
            else
            if (UsersChoice == 7) {

            int user_input_seat1, user_input_seat2;

            cout << "Type first seat number: ";

            cin >> user_input_seat1;

            cout << "Type second seat number: ";

            cin >> user_input_seat2;

            if (!airplane.swapSeats(user_input_seat1, user_input_seat2)) {

                cout << "Swapping failed due to technical reasons. Try again\n";

            } else {

                cout << "You have successfully swapped seats " << user_input_seat1 << " and " << user_input_seat2 << "\n";

            }

        }

            else

                if (UsersChoice == 8) {

            cout << "Thank you for using our Booking System Station! Next stop, Shibuya!\n";

            break;

        } else {

            cout << "Invalid selection, please try again.\n";

        }

    }

    return 0;

}
