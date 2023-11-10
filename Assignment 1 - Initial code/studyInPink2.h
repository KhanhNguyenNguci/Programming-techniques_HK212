/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

//ho tro ham notebook2
int Dem(int n) {
    if (n == 0) return 1;
    int dem = 0;
    while (n > 0) {
        dem++;
        n /= 10;
    }
    return dem;
}
//ho tro ham notebook3
bool KT_SNT(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int SNT_fisrt(int n) {
    int i = 1;
    while (true) {
        if (KT_SNT(n + i) == true) return n + i;
        i++;
    }
}
long long Fibonacci(int n)
{
    long long Fibo[1000];
    Fibo[0] = 1;
    Fibo[1] = 1;

    for (int i = 2; i < 1000; i++)
    {
        Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
    }
    return Fibo[n];
}
bool check_Fib(long long n)
{
    for (int i = 0; Fibonacci(i) <= n; i++)
    {
        if (Fibonacci(i) == n)
        {
            return true;
        }
    }
    return false;
}
long long Fib_count(long long n) {
    while (true) {
        if (check_Fib(n) == false) {
            n++;
        }
        else
        {
            return n;
        }
    }
}
//ho tro ham generateListPasswords
string g(string p1, string p2) {
    string s = "";
    int T1 = 0, T2 = 0;
    int Temp = 0;
    for (int i = 0; i < 10; i++) {
        T1 = p1[i] - '0';
        T2 = p2[i] - '0';
        Temp = (T1 + T2 + Temp);
        if (Temp > 9) {
            Temp %= 10;
            s += to_string(Temp);
            Temp = 1;
        }
        else {
            s += to_string(Temp);
            Temp = 0;
        }
    }
    return s;
}
//ho tro ham chaseTaxi
// check toa do
int CheckID(string s, int& indexBg, int Len) {
    int n = 0;
    string ID = "";
    while (indexBg < Len) {
        if (s[indexBg] >= '0' && s[indexBg] <= '9') {
            ID += s[indexBg];
            if (s[indexBg + 1] >= '0' && s[indexBg + 1] <= '9') {
                ID += s[indexBg + 1];
                indexBg += 2;;
                break;
            }
            indexBg++;
            break;
        }
        indexBg++;
    }
    n = atoi(ID.c_str());
    return n;
}
//=======================================
string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream FileName(ntb1);
    string s = {};
    getline(FileName, s, '/');
    getline(FileName, s, '/');
    getline(FileName, s);
    for (int i = 0; i < 3; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return "0000000000";
        }
    }
    int n1 = atoi(s.c_str());
    if (n1 > 0 && n1 < 1000) {
        int arr[1000] = {};
        for (int i = 0; i < n1; i++) {
            FileName >> arr[i];
        }
        int count;
        string Temp = "";
        for (int i = 0; i <= 9; i++) {
            count = 0;
            for (int j = 0; j < n1; j++) {
                if (arr[j] == i) count++;
            }
            count = count % 10;
            Temp += to_string(count);
        }
        return Temp;
    }
    else return "0000000000";
    FileName.close();
}

string notebook2(string ntb2) {
    // Complete this function to gain point
    ifstream FileName(ntb2);
    string s = "";
    getline(FileName, s);
    for (int i = 0; i < 5; i++) {
        if (s[i] < '0' && s[i] > '9') {
            return "1111111111";
        }
    }
    int n2 = atoi(s.c_str());
    if (n2 >= 5 && n2 <= 100) {
        int cntP = 0;
        for (int i = 0; i < n2; i++) {
            getline(FileName, s);
            int temp1 = -1;
            int temp2 = -1;
            temp1 = s.find("pink");
            temp2 = s.find("Pink");
            while (temp2 != string::npos) {
                temp2 = s.find("Pink", temp2 + 1);
                cntP++;
            }
            while (temp1 != string::npos) {
                temp1 = s.find("pink", temp1 + 1);
                cntP++;
            }
        }
        int dem = Dem(cntP);
        if (dem < 5) {
            cntP = cntP * cntP;
        }
        dem = Dem(cntP);
        string Temp = to_string(cntP);
        while (dem < 10) {
            Temp += "9";
            dem++;
        }
        return Temp;
    }
    else return "1111111111";
    FileName.close();
}

string notebook3(string ntb3) {
    // Complete this function to gain point
    ifstream FileName(ntb3);
    int arr[10][10];
    char c;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            FileName >> arr[i][j];
            arr[i][j] = abs(arr[i][j]);
            FileName >> c;
        }
        FileName >> arr[i][9];
        arr[i][9] = abs(arr[i][9]);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            //B1:
            if (i < j) {
                if (KT_SNT(arr[i][j]) == false) {
                    arr[i][j] = SNT_fisrt(arr[i][j]);
                }
            }
            //B2:
            if (i > j) {
                arr[i][j] = Fib_count(arr[i][j]);
            }
        }
    }
    //B3:
    for (int i = 0; i < 10; i++) {
        for (int j = 7; j < 9; j++) {
            for (int k = j + 1; k < 10; k++) {
                if (arr[i][j] > arr[i][k]) swap(arr[i][j], arr[i][k]);
            }
        }
    }
    //Find Max of row
    string s = "";
    int Max = 0;
    int index_Max;
    for (int i = 0; i < 10; i++) {
        Max = arr[i][0];
        index_Max = 0;
        for (int j = 0; j < 10; j++) {
            if (Max <= arr[i][j]) {
                Max = arr[i][j];
                index_Max = j;
            }
        }
        s = s + to_string(index_Max);
    }
    return s;
    return "0000000000";
    FileName.close();
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    string s = "";
    s += (pwd1 + ";");//1
    s += (pwd2 + ";");//2
    s += (pwd3 + ";");//3
    s += (g(pwd1, pwd2) + ";"); //4
    s += (g(pwd1, pwd3) + ";"); //5
    s += (g(pwd2, pwd3) + ";"); //6
    s += (g(g(pwd1, pwd2), pwd3) + ";"); //7
    s += (g(pwd1, g(pwd2, pwd3)) + ";"); //8
    s += g(g(pwd1, pwd2), g(pwd1, pwd3)); //9
    return s;
    return "0000000000";
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string& outTimes,
    string& outCatchUps
) {
    // Complete this function to gain point
    //1.
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            arr[i][j] = -9;
        }
    }
    //Tim n Points
    int LenOfPoints = points.length();
    int indexOfPoints = 0;
    //=====
    int xP[100] = {};
    int yP[100] = {};
    int idx = 0;
    xP[idx] = CheckID(points, indexOfPoints, LenOfPoints);
    yP[idx] = CheckID(points, indexOfPoints, LenOfPoints);
    idx++;
    // n-1 poits 
    while (points[indexOfPoints] != '\0') {
        if (points[indexOfPoints] >= '0' && points[indexOfPoints] <= '9') {
            //cap nhat x2,y2
            xP[idx] = CheckID(points, indexOfPoints, LenOfPoints);
            yP[idx] = CheckID(points, indexOfPoints, LenOfPoints);
            idx++;
        }
        indexOfPoints++;
    }
    //point
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    int d = 0;
    int Times[100] = {};
    x1 = x2;
    y1 = y2;
    // point dau tien
    x2 = xP[0];
    y2 = yP[0];
    // 
    d = abs(x1 - x2) + abs(y1 - y2);
    Times[0] = 14 * d;
    for (int i = 1; i < idx; i++) {
        x1 = x2;
        y1 = y2;
        x2 = xP[i];
        y2 = yP[i];
        d = abs(x1 - x2) + abs(y1 - y2);
        Times[i] = Times[i - 1] + 14 * d;
    }

    //2.
    /////
    int LenOfMoves = moves.length();
    int index_xOfTaxi = 0, index_yOfTaxi = 0;
    int T = 9;
    bool Id_ed = false;
    int memOfIdx = 0;
    //ban dau o vi tro (0,0)
    arr[0][0] = 0;
    for (int i = 0; i < LenOfMoves; i++) {
        //Kiem tra bien ban do
        switch (moves[i])
        {
        case 'U':
        {
            if (index_xOfTaxi != 0) {
                T += 9;
                arr[index_xOfTaxi - 1][index_yOfTaxi] += T;
                index_xOfTaxi--;
            }
            break;
        }
        case 'D':
        {
            if (index_xOfTaxi != 99) {
                T += 9;
                arr[index_xOfTaxi + 1][index_yOfTaxi] += T;
                index_xOfTaxi++;
            }
            break;
        }
        case 'L':
        {
            if (index_yOfTaxi != 0) {
                T += 9;
                arr[index_xOfTaxi][index_yOfTaxi - 1] += T;
                index_yOfTaxi--;
            }
            break;
        }
        case 'R':
        {
            if (index_yOfTaxi != 99) {
                T += 9;
                arr[index_xOfTaxi][index_yOfTaxi + 1] += T;
                index_yOfTaxi++;
            }
            break;
        }

        }
    }
    //Tim diem dau tien bat kip Taxi
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                if (xP[i] == j && yP[i] == k && Id_ed == false && Times[i] <= arr[j][k]) {
                    Id_ed = true;
                    memOfIdx = i;
                    break;
                }
            }
            if (Id_ed == true) break;
        }
        if (Id_ed == true) break;
    }
    if (Id_ed == false) {
        for (int i = 0; i < idx; i++) {
            outTimes += to_string(Times[i]);
            outCatchUps += "N";
            if (i != idx - 1) {
                outTimes += ";";
                outCatchUps += ";";
            }
        }
    }
    else {
        for (int i = 0; i < idx; i++) {
            if (i <= memOfIdx) {
                if (i != memOfIdx) {
                    outTimes += to_string(Times[i]);
                    outCatchUps += "N";
                }
                else {
                    outTimes += to_string(Times[i]);
                    outCatchUps += "Y";
                }
            }
            else {
                outTimes += "-";
                outCatchUps += "-";
            }
            if (i != idx - 1) {
                outTimes += ";";
                outCatchUps += ";";
            }
        }
    }
    return Id_ed;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    ifstream FileName(tag);
    string sE = "", sA = "";
    string pwdL = "";
    int n3 = 0;
    getline(FileName, sE, ' ');
    getline(FileName, sE);
    getline(FileName, sA, ':');
    FileName >> n3;
    pwdL += sE + ";";
    for (int i = 0; i < n3; i++) {
        pwdL += message;
    }
    return pwdL;
    return "";
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
