class Student{
private:
    int personality; // 0 sports; 1 travel; 2 lazy; 3 learning
    int wealth; // 0 wealthy; 1 medium; 2 poor
    int gender; // 0 male; 1 female
    double purchaseProb[50];// ‘§…Ëπ∫¬Ú∏≈¬  0.01
public:
    Student(){
        for(int i=0;i<50;i++){
            purchaseProb[i] = 0.01;
        }
    }
    
    void setPersonality(int a){ personality = a;}
    void setWealth(int a){ wealth = a;}
    void setGender(int a){ gender = a;}
    void setProb(int i,double p){ purchaseProb[i] = p;}
    int getPersonality() const{ return personality;}
    int getWealth() const{ return wealth;}
    int getGender() const{ return gender;}
    double getProb(int i) const{ return purchaseProb[i];}
    void Match();
};

void Student::Match(){
    switch (getPersonality())
    {
        case 0://sports
            setProb(5,0.05);
            setProb(6,0.05);
            setProb(7,0.05);
            setProb(8,0.05);
            setProb(9,0.05);
            setProb(10,0.05);
            setProb(11,0.05);
            setProb(12,0.05);
            break;
        case 1://travel
            setProb(13,0.05);
            setProb(14,0.05);
            setProb(15,0.05);
            setProb(16,0.05);
            setProb(17,0.05);
            setProb(18,0.05);
            setProb(19,0.05);
            setProb(28,0.05);
            setProb(29,0.05);
            setProb(30,0.05);
            setProb(31,0.05);
            setProb(32,0.05);
            setProb(35,0.05);
            setProb(36,0.05);
            setProb(37,0.05);
            setProb(38,0.05);
            setProb(39,0.05);
            setProb(40,0.05);
            setProb(41,0.05);
            break;
        case 2://lazy
            setProb(0,0.05);
            setProb(1,0.05);
            setProb(2,0.05);
            setProb(3,0.05);
            setProb(4,0.05);
            setProb(5,0.05);
            setProb(20,0.05);
            setProb(21,0.05);
            setProb(22,0.05);
            setProb(23,0.05);
            setProb(24,0.05);
            setProb(35,0.05);
            setProb(36,0.05);
            setProb(37,0.05);
            setProb(38,0.05);
            setProb(39,0.05);
            setProb(40,0.05);
            setProb(41,0.05);
            setProb(42,0.05);
            setProb(43,0.05);
            setProb(44,0.05);
            break;
        case 3://learning
            setProb(33,0.05);
            setProb(34,0.05);
            setProb(45,0.05);
            setProb(46,0.05);
            setProb(47,0.05);
            setProb(48,0.05);
            setProb(49,0.05);
            break;
    }
    if(getGender()){
        //female
        setProb(13,0.05);
        setProb(14,0.05);
        setProb(15,0.05);
        setProb(16,0.05);
        setProb(17,0.05);
        setProb(18,0.05);
        setProb(19,0.05);
        setProb(20,0.05);
        setProb(21,0.05);
        setProb(24,0.05);
        setProb(35,0.05);
        setProb(36,0.05);
        setProb(44,0.05);
    }
    else{
        //male
        setProb(0,0.05);
        setProb(1,0.05);
        setProb(2,0.05);
        setProb(3,0.05);
        setProb(8,0.05);
        setProb(9,0.05);
        setProb(40,0.05);
        setProb(41,0.05);
    }
}
