#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "1.h"

using namespace std;

void Simulation(int studNum, int* date);
int Purchase(Student& s, int g);
void RefreshData(int studNum, Student* s, int date, int* goods);

int main(){
    srand((unsigned)time(NULL));
    //≥ı ºªØ ˝æ›
    int date[1096]={0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0,0,0,11,11,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,7,7,7,7,7,0,0,0,0,0,0,0,0,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0,12,12,12,12,13,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,7,7,7,7,7,0,0,0,0,0,0,0,12,12,12,12,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0,12,12,12,12,13,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,7,7,7,7,7,0,0,0,0,0,0,0,0,12,12,12,12,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,11,11,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,7,7,7,7,7,0,0,0,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0,12,12,12,12,13,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,7,7,7,7,7,0,0,0,0,0,0,0,0,0,12,12,12,12,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0};
    Simulation(10000,date);
}

void Simulation(int studNum, int* date){
    Student* s = new Student[studNum]; //¥¥Ω®∂‘œÛ
    string filename = "/Users/kingcos/Desktop/Data.txt";
    ofstream saveInfo(filename);
    int goods[50]={0}; //…Ã∆∑π∫¬Ú ˝¡ø
    //≥ı ºªØ
    for(int i=0;i<studNum;i++){
        s[i].setPersonality(rand()%5);
        s[i].setWealth(rand()%4);
        s[i].setGender(rand()%3);
        s[i].Match();
    }
    for(int i=0;i<1096;i++){
        //√øÃÏ÷ÿ÷√…Ã∆∑π∫¬Ú ˝¡ø
        for(int j=0;j<50;j++){
            goods[j] = 0;
        }
        RefreshData(studNum,s,date[i],goods);
        
        for(int j=0;j<50;j++){
            if(i == 0 && j == 0){
                saveInfo << goods[j] <<"," ;
                saveInfo.close();
            }
            else{
                saveInfo.open(filename,ios::app);
                saveInfo << goods[j] <<"," ;
                saveInfo.close();
            }
        }
        saveInfo.open(filename,ios::app);
        saveInfo << endl;
        saveInfo.close();
    }
}

// π∫¬Ú…Ã∆∑∫Ø ˝
int Purchase(Student& s, int g){
    if(rand()/double(RAND_MAX) <= s.getProb(g) * (s.getWealth()+1.0)/2){
        if(rand()/double(RAND_MAX) <= 0.8){
            return 1;
        }
        else{
            return 2;
        }
    }
    else return 0;
}

void RefreshData(int studNum, Student* s, int date, int* goods){
    
    //for students
    switch (date)
    {
        case 0:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(pr <= 0.01) s[i].setProb(j,0.01);
                    else s[i].setProb(j,pr * 0.5);
                }
            }
            break;
        case 1:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(j == 0 && j == 1 && j == 2 && j == 3 && j == 6  && j == 7 && j == 8 && j == 9
                       && j == 10 && j == 11 && j == 12
                       && j == 13 && j == 14 && j == 15 && j == 16  && j == 17 && j == 18 && j == 19
                       && j == 25 && j == 26 && j == 27 && j == 28 && j == 29 && j == 30 && j == 31 && j == 32){
                        if(pr >= 1) s[i].setProb(j,1.0);
                        else s[i].setProb(j,pr * 4);
                    }
                    else{
                        if(pr <= 0.01) s[i].setProb(j,0.01);
                        else s[i].setProb(j,pr * 0.5);
                    }
                }
            }
            break;
        case 2:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(j == 0 && j == 1 && j == 2 && j == 3 && j == 4 && j == 5 && j == 6 && j == 7 && j == 8 && j == 9
                       && j == 31 && j == 32
                       && j == 35 && j == 36 && j == 37 && j == 38 && j == 39 && j == 40 && j == 41 && j == 42 && j == 43 && j == 44){
                        if(pr >= 1) s[i].setProb(j,1.0);
                        else s[i].setProb(j,pr * 4);
                    }
                    else{
                        if(pr <= 0.01) s[i].setProb(j,0.01);
                        else s[i].setProb(j,pr * 0.5);
                    }
                }
            }
            break;
        case 3:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(j == 0 && j == 1 && j == 2 && j == 3 && j == 4 && j == 5 && j == 6 && j == 7
                       && j == 10 && j == 11 && j == 12
                       && j == 35 && j == 36 && j == 37 && j == 38 && j == 39 && j == 40 && j == 41 && j == 42 && j == 43 && j == 44){
                        if(pr >= 1) s[i].setProb(j,1.0);
                        else s[i].setProb(j,pr * 4);
                    }
                    else{
                        if(pr <= 0.01) s[i].setProb(j,0.01);
                        else s[i].setProb(j,pr * 0.5);
                    }
                }
            }
            break;
        case 4:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(pr <= 0.005) s[i].setProb(j,0.005);
                    else s[i].setProb(j,pr * 0.15);
                }
            }
            break;
        case 5:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(pr <= 0.005) s[i].setProb(j,0.005);
                    else s[i].setProb(j,pr * 0.15);
                }
            }
            break;
        case 6:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(j == 0 && j == 1 && j == 2 && j == 3 && j == 6 && j == 7 && j == 8 && j == 9
                       && j == 35 && j == 36 && j == 37 && j == 38 && j == 39 && j == 42 && j == 43 && j == 44){
                        if(pr >= 1) s[i].setProb(j,1.0);
                        else s[i].setProb(j,pr * 4);
                    }
                    else{
                        if(pr <= 0.01) s[i].setProb(j,0.01);
                        else s[i].setProb(j,pr * 0.5);
                    }
                }
            }
            break;
        case 7:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(j == 0 && j == 1 && j == 2 && j == 3 && j == 6 && j == 7 && j == 8 && j == 9
                       && j == 13 && j == 14
                       && j == 35 && j == 36 && j == 37 && j == 38 && j == 39 && j == 40 && j == 41 && j == 42 && j == 43 && j == 44){
                        if(pr >= 1) s[i].setProb(j,1.0);
                        else s[i].setProb(j,pr * 4);
                    }
                    else{
                        if(pr <= 0.01) s[i].setProb(j,0.01);
                        else s[i].setProb(j,pr * 0.5);
                    }
                }
            }
            break;
        case 8:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(j == 0 && j == 1 && j == 2 && j == 3 && j == 4 && j == 5 && j == 6 && j == 7 && j == 8 && j == 9
                       && j == 13 && j == 14
                       && j == 20 && j == 21){
                        if(pr >= 1) s[i].setProb(j,1.0);
                        else s[i].setProb(j,pr * 4);
                    }
                    else{
                        if(pr <= 0.01) s[i].setProb(j,0.01);
                        else s[i].setProb(j,pr * 0.5);
                    }
                }
            }
            break;
        case 9:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(j == 24
                       && j == 35 && j == 36 && j == 37 && j == 38 && j == 39 && j == 40 && j == 41 && j == 42 && j == 43 && j == 44){
                        if(pr >= 1) s[i].setProb(j,1.0);
                        else s[i].setProb(j,pr * 4);
                    }
                    else{
                        if(pr <= 0.01) s[i].setProb(j,0.01);
                        else s[i].setProb(j,pr * 0.5);
                    }
                }
            }
            break;
        case 10:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(j == 13 && j == 14 && j == 15 && j == 16  && j == 17 && j == 18 && j == 19
                       && j == 22 && j == 23 && j == 24
                       && j == 25 && j == 26 && j == 27 && j == 28 && j == 29 && j == 30 && j == 31 && j == 32
                       && j == 33 && j == 34
                       && j == 45 && j == 46 && j == 47 && j == 48 && j == 49){
                        if(pr >= 1) s[i].setProb(j,1.0);
                        else s[i].setProb(j,pr * 4);
                    }
                    else{
                        if(pr <= 0.01) s[i].setProb(j,0.01);
                        else s[i].setProb(j,pr * 0.5);
                    }
                }
            }
            break;
        case 11:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(j == 13 && j == 14 && j == 15 && j == 16  && j == 17 && j == 18 && j == 19
                       && j == 25 && j == 26 && j == 27 && j == 28 && j == 29 && j == 30 && j == 31 && j == 32
                       && j == 33 && j == 34
                       && j == 45 && j == 46 && j == 47 && j == 48 && j == 49){
                        if(pr >= 1) s[i].setProb(j,1.0);
                        else s[i].setProb(j,pr * 4);
                    }
                    else{
                        if(pr <= 0.01) s[i].setProb(j,0.01);
                        else s[i].setProb(j,pr * 0.5);
                    }
                }
            }
            break;
        case 12:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    if(pr <= 0.002) s[i].setProb(j,0.002);
                    else s[i].setProb(j,pr * 0.1);
                }
            }
            break;
        case 13:
            for(int i=0;i<studNum;i++){
                for(int j=0;j<50;j++){
                    double pr = s[i].getProb(j);
                    s[i].setProb(j,pr * 100);
                }
            }
            break;
    }
    
    //for goods
    for(int i=0;i<50;i++){
        for(int j=0;j<studNum;j++){
            goods[i] += Purchase(s[j],i); //Ω´√ø∏ˆ—ß…˙µƒπ∫¬Ú¡øœ‡º”
        }
    }
}





