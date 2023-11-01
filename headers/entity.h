#pragma once
#include <string>
#include <ctime>
#include <chrono>
#include <vector>


class User
{
    protected:
        std::string user_login;
        std::string user_password;
        std::string last_name;
        std::string first_name;
        unsigned int date_of_birth;
        unsigned char gender;

    public:
        //Constructors
        User();
        //login, password, last name, first name, dob, gender
        User(const std::string& login, std::string, std::string, std::string, unsigned int, unsigned char);

        // Setters
        void setUserLogin(std::string);
        void setUserPassword(std::string);
        void setLastName(std::string);
        void setFirstName(std::string);
        void setDateOfBirth(unsigned int);
        void setGender(unsigned char);

        // Getters
        std::string getUserLogin() const;
        std::string getUserPassword() const;
        std::string getLastName() const;
        std::string getFirstName() const;
        unsigned int getDateOfBirth() const;
        unsigned char getGender() const;
};

class Room
{
    //friend class Modify_Room_Availability;
    private:
        unsigned int room_number; // Room number
        short room_floor_number;  // Floor Number
        bool room_available;      // Room Availability
    public:
        //Constructors
        Room();
        Room(unsigned int, short, bool);

        // Setters
        void setRoomNumber(unsigned int);
        void setRoomFloorNumber(short);
        void setRoomAvailability(bool);

        // Getters
        unsigned int getRoomNumber() const;
        short getRoomFloor() const;
        bool getRoomAvailability() const;
};

class Patient : virtual public User
{
    private:
        bool has_insurance;
        std::string insurance_provider;
        Room room;

    public:
        // Constructors
        Patient();
        Patient(std::string, std::string, std::string, std::string, unsigned int, unsigned char, bool, std::string);

        // Setters
        void setHasInsurance(bool);
        void setInsuranceProvider(std::string);

        // Getters
        bool getHasInsurance() const;
        std::string getInsuranceProvider() const;
};

class Staff : virtual User
{
    public:
        enum Clearance { entry, janitorial, nursing, medical, admin };
    private:
        unsigned int id_number;
        short clearance_level;
        std::string job_title;
        unsigned int date_of_hire;
    public:
        //Constructors
        Staff();
        Staff(std::string, std::string, std::string, std::string, unsigned int, unsigned char, unsigned int, short, std::string, unsigned int);

        // Setters
        void setIdNumber(unsigned int);
        void setClearanceLevel(short);
        void setJobTitle(std::string);
        void setDateOfHire(unsigned int);

        // Getters
        unsigned int getIdNumber() const;
        unsigned int getDateOfHire() const;
        short getClearanceLevel() const;
        std::string getJobTitle() const;
};

class Inventory
{
    private:
        std::string item_name;
        unsigned int item_count;
        unsigned int item_threshold;
    public:
        // Constructors
        Inventory();
        Inventory(std::string, unsigned int, unsigned int);
        
        // Setters
        void setItemName(std::string);
        void setItemCount(unsigned int);
        void setItemThreshold(unsigned int);
        
        // Getters
        std::string getItemName() const;
        unsigned int getItemCount() const;
        unsigned int getItemThreshold() const;
};

class Procedure
{
    private:
        std::string procedure_name;
        float cost;
        std::vector<Inventory> items_used;
    public:
        Procedure();
        Procedure(std::string, float, std::vector<Inventory>&);
        void setProcedureName(std::string);
        void setCost(float);
        void setItemsUsed(std::vector<Inventory>&);
        // void addItemUsed(Inventory&);        // these operations will be
        // void removeItemUsed(Inventory&);     // done by the control class
        std::string getProcedureName() const;
        float getCost() const;
        const std::vector<Inventory>& getItemsUsed() const;
};

class Schedule
{
    public:
        using TimePoint = std::chrono::system_clock::time_point;

    private:
        TimePoint time;
        Staff staffer;
        Patient patient;
        Room room;
        Procedure procedure;
    public:
        // Constructors
        Schedule();
        Schedule(const TimePoint&, const Staff&, const Patient&, const Room&, const Procedure&);

        // Setters
        void setTime(TimePoint&);
        void setStaffer(Staff&);
        void setPatient(Patient&);
        void setRoom(Room&);
        // No need to set the procedure here, because it's instantiated from a seperate class.
        // There will also be implementation of control classes to modify these members.

        // Getters
        const TimePoint getTime() const;
        const Staff getStaffer() const;
        const Patient getPatient() const;
        const Room getRoom() const;
        const Procedure getProcedure() const;
};