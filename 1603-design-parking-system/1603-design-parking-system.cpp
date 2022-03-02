class ParkingSystem {
public:
    int b,m,s;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int c) {
        if(c==1)
        {
            if(b>0)
                b--;
            else return false;
        }
        if(c==2)
        {
            if(m>0)
                m--;
            else return false;
        }
        if(c==3)
        {
            if(s>0)
                s--;
            else return false;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */