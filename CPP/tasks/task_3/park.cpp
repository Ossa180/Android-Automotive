/*
# Design Parking System

Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.

*/

class ParkingSystem {
public:
    int big;
    int medium;
    int small;
    static int c_big;
    static int c_medium;
    static int c_small;

    ParkingSystem(int big, int medium, int small) : big(big), medium(medium), small(small) {
    }
    
    bool addCar(int carType) {
        switch (carType) {
            case 1:
                if (c_big < big) {
                    c_big++;
                    return true;
                } else {
                    return false;
                }
            case 2:
                if (c_medium < medium) {
                    c_medium++;
                    return true;
                } else {
                    return false;
                }
            case 3:
                if (c_small < small) {
                    c_small++;
                    return true;
                } else {
                    return false;
                }
        }
        return false;
    }
};

// Definition of static members
int ParkingSystem::c_big = 0;
int ParkingSystem::c_medium = 0;
int ParkingSystem::c_small = 0;

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
