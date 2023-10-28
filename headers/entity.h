#pragma once
#include <string>


class User
{
    protected:
        std::string user_login;
        std::string user_password;
        std::string last_name;
        std::string first_name;
        unsigned int date_of_birth;

    public:
        //Constructors
        User();
        User(std::string, std::string, std::string, std::string, unsigned int);

        // Setters
        void setUserLogin(std::string);
        void setUserPassword(std::string);
        void setLastName(std::string);
        void setFirstName(std::string);
        void setDateOfBirth(unsigned int);

        // Getters
        std::string getUserLogin() const;
        std::string getUserPassword() const;
        std::string getLastName() const;
        std::string getFirstName() const;
        unsigned int getDateOfBirth() const;
};

class Room
{
    friend class Modify_Room_Availability;
    private:
        unsigned int room_number;
        short room_floor_number;
        bool room_available;
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
        // Room room;

    public:
        // Constructors
        Patient();
        Patient(std::string, std::string, std::string, std::string, unsigned int, bool, std::string);

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
        Staff(std::string, std::string, std::string, std::string, unsigned int, unsigned int, short, std::string, unsigned int);

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