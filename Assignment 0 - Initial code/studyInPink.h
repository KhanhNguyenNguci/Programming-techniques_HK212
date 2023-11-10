/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void ThietLap_HP(int& HP) {
	if (HP > 999) HP = 999;
	if (HP < 0) HP = 0;
}
//EXP
void ThietLap_EXP(int& EXP) {
	if (EXP > 900) EXP = 900;
	if (EXP < 0) EXP = 0;
}
//M
void ThietLap_M(int& M) {
	if (M > 2000) M = 2000;
	if (M < 0) M = 0;
}
//Tap hop con duong 3
void SCP_Chan(int P3[]) {
	int index = 0;
	for (int i = 1;; i++) {
		if (i % 2 == 0) {
			P3[index] = i * i;
			index++;
			if (index == 20) return;
		}
	}
}

int firstMeet(int& EXP1, int& EXP2, const int& E1) {
	//Complete this function to gain point on task 1
	if (E1 >= 0 && E1 <= 999) {
		ThietLap_EXP(EXP1);
		ThietLap_EXP(EXP2);
		//Truong hop 1
		if (E1 >= 0 && E1 <= 399) {
			//EXP1
			//Afghanistan
			if (E1 % 2 != 0) {
				//Tinh va thiet lap EXP1
				EXP1 = ceil(EXP1 + E1 / 10.);
			}
			//Irag
			else {
				EXP1 = ceil(EXP1 - E1 / 5.);
			}
			ThietLap_EXP(EXP1);

			//EXP2
			if (E1 >= 0 && E1 <= 49) {
				EXP2 = EXP2 + 25;
			}
			else if (E1 >= 50 && E1 <= 99) {
				EXP2 = EXP2 + 50;
			}
			else if (E1 >= 100 && E1 <= 149) {
				EXP2 = EXP2 + 85;
			}
			else if (E1 >= 150 && E1 <= 199) {
				EXP2 = EXP2 + 75;
			}
			else if (E1 >= 200 && E1 <= 249) {
				EXP2 = EXP2 + 110;
			}
			else if (E1 >= 250 && E1 <= 299) {
				EXP2 = EXP2 + 135;
			}
			else {
				EXP2 = EXP2 + 160;
			}
			ThietLap_EXP(EXP2);
			return EXP1 + EXP2;
		}
		//Truong hop 2
		else if (E1 >= 400 && E1 <= 999) {
			//EXP1
			EXP1 = ceil(EXP1 - 0.1 * E1);
			ThietLap_EXP(EXP1);
			//EXP2
			if (E1 >= 400 && E1 <= 499) {
				EXP2 = ceil(EXP2 + (E1 / 7. + 9));
			}
			if (E1 >= 500 && E1 <= 599) {
				EXP2 = ceil(EXP2 + (E1 / 9. + 11));
			}
			if (E1 >= 600 && E1 <= 699) {
				EXP2 = ceil(EXP2 + (E1 / 5. + 6));
			}
			//Thiet lap chung 3 thong tin tren
			ThietLap_EXP(EXP2);
			////////////
			if (E1 >= 700 && E1 <= 799) {
				//thong tin 1
				EXP2 = ceil(EXP2 + (E1 / 7. + 9.));
				ThietLap_EXP(EXP2);
				//thong tin 2
				if (EXP2 > 200) {
					EXP2 = ceil(EXP2 + (E1 / 9. + 11.));
					ThietLap_EXP(EXP2);
				}
			}
			if (E1 >= 800 && E1 <= 999) {
				//Thong tin 1, 2
				EXP2 = ceil(EXP2 + (E1 / 7. + 9.) + (E1 / 9. + 11.));
				ThietLap_EXP(EXP2);
				//thong tin 3
				if (EXP2 > 600) {
					EXP2 = ceil(EXP2 + (E1 / 5. + 6.));
					ThietLap_EXP(EXP2);
					EXP2 = ceil(1.15 * EXP2);
					ThietLap_EXP(EXP2);
				}
			}
			return EXP1 + EXP2;
		}
	}
	return -999;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2) {
	//Complete this function to gain point on task 2
	if (E2 >= 0 && E2 <= 999) {
		// Thiet lap
		ThietLap_EXP(EXP1);
		ThietLap_EXP(EXP2);
		ThietLap_HP(HP2);
		ThietLap_M(M2);
		//Giai doan 1
		if (E2 >= 0 && E2 <= 299) {
			//chiec nhan
			EXP1 = ceil(EXP1 + ((E2 / 9.) + 10) / 3.); //xem lai//
			EXP2 = ceil(EXP2 + ((E2 / 9.) + 10));
		}
		else if (E2 >= 300 && E2 <= 499) {
			//chiec nhan
			EXP1 = ceil(EXP1 + ((E2 / 9.) + 10) / 3.);
			ThietLap_EXP(EXP1);
			EXP2 = ceil(EXP2 + ((E2 / 9.) + 10));
			ThietLap_EXP(EXP2);
			//ao khoac
			EXP1 = ceil(EXP1 + (0.35 * E2) / 3.);
			EXP2 = ceil(EXP2 + 0.35 * E2);
		}
		else if (E2 >= 500 && E2 <= 999) {
			//chiec nhan va ao khoac
			EXP1 = ceil(EXP1 + ((E2 / 9.) + 10) / 3.);
			ThietLap_EXP(EXP1);
			EXP2 = ceil(EXP2 + ((E2 / 9.) + 10));
			ThietLap_EXP(EXP2);
			//ao khoac
			EXP1 = ceil(EXP1 + (0.35 * E2) / 3.);
			ThietLap_EXP(EXP1);
			EXP2 = ceil(EXP2 + 0.35 * E2);
			ThietLap_EXP(EXP2);
			//hanh li
			float d = 0.17 * (((E2 / 9.) + 10) + 0.35 * E2);
			EXP1 = ceil(EXP1 + d / 3.); //khong dao 2 len truoc 1 => tranh thay doi exp2
			EXP2 = ceil(EXP2 + d);
		}
		ThietLap_EXP(EXP1);
		ThietLap_EXP(EXP2);
		// Giai doan 2
		// HP2 bi hao hut khi di chuyen 1 doan E2^3
		HP2 = ceil(HP2 - (pow(E2, 3)) / 8388608.);
		ThietLap_HP(HP2);
		// M2 la so tien nhan truoc cua Watson
		if (E2 % 2 == 0) {
			M2 = ceil(M2 + (pow(E2, 2)) / 50.);
			ThietLap_M(M2);
		}
		return EXP2 + HP2 + M2 + EXP1;
	}
	return -999;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3) {
	//Complete this function to gain point on task 3
	if (E3 >= 0 && E3 <= 999) {
		ThietLap_EXP(EXP1);
		ThietLap_HP(HP1);
		ThietLap_M(M1);
		bool PhatHien = false;
		//vi tri (thu k) o moi con duong, bat dau tu k = 1
		int k = 1;
		//CON DUONG 1: chuoi 9 so nguyen le dau
		int P1[9] = { 1,3,5,7,9,11,13,15,17 };
		//Bien doi con duong 1
		for (int i = 0; i < 9; i++) {
			P1[i] = (P1[i] + E3) % 26 + 65;
			// i+1=k la vi tri tim ra
			if (P1[i] == 80) {
				HP1 = HP1 - P1[i] * k * 2;
				ThietLap_HP(HP1);
				EXP1 = EXP1 + ((1000 - P1[i] * k) % 101);
				ThietLap_EXP(EXP1);
				M1 = ceil(M1 - (k * E3) / 9.);
				ThietLap_M(M1);
				PhatHien = true;
				break;
			}
			// Con duong 1 khong tim ra hanh li
			if (k == 9 && P1[i] != 80) {
				M1 = ceil(M1 - (pow(9, 2) * E3 / 9.));
				ThietLap_M(M1);
				break;
			}
			k++;
		}
		/*==========================================*/
		// CON DUONG 2: chuoi 7 so nguyen to dau 
		// reset lai vi tri
		k = 1;
		int P2[7] = { 2,3,5,7,11,13,17 };
		int s = 0, m = 0;
		//Bien doi con duong 2
		for (int i = 0; i < 7; i++) {
			P2[i] = (P2[i] + E3) % 26;
		}
		for (int i = 0; i < 7; i++) {
			s += P2[i];
		}
		m = ceil(s / 7.);
		for (int i = 0; i < 7; i++) {
			P2[i] = (P2[i] + s + m) % 26 + 65;
			// i+1=k la vi tri tim ra
			if (P2[i] == 80) {
				HP1 = HP1 - P2[i] * k * 2;
				ThietLap_HP(HP1);
				EXP1 = EXP1 + (1000 - P2[i] * k) % 101;
				ThietLap_EXP(EXP1);
				M1 = ceil(M1 - (k * E3) / 9.);
				ThietLap_M(M1);
				PhatHien = true;
				break;
			}
			// Con duong 2 khong tim ra hanh li
			if (k == 7 && P2[i] != 80) {
				M1 = ceil(M1 - pow(7, 2) * E3 / 9.);
				ThietLap_M(M1);
				break;
			}
			k++;
		}
		/*==========================================*/
		// CON DUONG 3: chuoi 20 int dau thoa dk so chinh phuong chan
		//reset k
		k = 1;
		//Temp luu tron len
		int temp = 0;
		int P3[20] = {};
		int Max = 0;
		SCP_Chan(P3);
		for (int i = 0; i < 20; i++) {
			P3[i] = (P3[i] + E3 * E3) % 113;
		}
		Max = P3[0];
		for (int i = 0; i < 20; i++) {
			if (Max < P3[i]) Max = P3[i];
		}
		for (int i = 19; i >= 0; i--) {
			temp = ceil((P3[i] + E3) * 1. / Max);
			P3[i] = (temp) % 26 + 65;
			if (P3[i] == 80) {
				HP1 = HP1 - P3[i] * k * 3;
				ThietLap_HP(HP1);
				EXP1 = EXP1 + ((3500 - P3[i] * k) % 300);
				ThietLap_EXP(EXP1);
				M1 = ceil(M1 - (k * E3) / 9.);
				ThietLap_M(M1);
				PhatHien = true;
				break;
			}
			// Con duong 3 khong tim ra hanh li
			if (k == 20 && P3[i] != 80) {
				M1 = ceil(M1 - pow(20, 2) * E3 / 9.);
				ThietLap_M(M1);
				break;
			}
			k++;
		}
		/*==========================================*/
		// CON DUONG 4: 
		//reset k
		k = 1;
		int P4[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int Min = 0, Min_idx = 1;
		int Dtemp = 0;
		int MinTemp = 0;
		Dtemp = ceil(E3 / 29.);
		for (int i = 0; i < 12; i++) {
			P4[i] = (P4[i] + pow(Dtemp, 3));
			P4[i] = P4[i] % 9;
		}
		Min = P4[0];
		for (int i = 0; i < 12; i++) {
			if (Min > P4[i]) {
				Min = P4[i];
				Min_idx = i + 1;
			}
		}
		MinTemp = ceil(Min * 1. / Min_idx);
		for (int i = 11; i >= 0; i--) {
			P4[i] = ((P4[i] + E3) * (MinTemp)) % 26 + 65;
			if (P4[i] == 80) {
				HP1 = HP1 - P4[i] * k * 4;
				ThietLap_HP(HP1);
				EXP1 = EXP1 + (4500 - P4[i] * k) % 400;
				ThietLap_EXP(EXP1);
				M1 = ceil(M1 - k * E3 / 9.);
				ThietLap_M(M1);
				PhatHien = true;
				break;
			}
			// Con duong 4 khong tim ra hanh li
			if (k == 12 && P4[i] != 80) {
				M1 = ceil(M1 - pow(12, 2) * E3 / 9.);
				ThietLap_M(M1);
				break;
			}
			k++;
		}
		if (PhatHien == false) {
			HP1 = HP1 - (59 * E3) % 900;
			ThietLap_HP(HP1);
			EXP1 = EXP1 - (79 * E3) % 300;
			ThietLap_EXP(EXP1);
			return -1;
		}
		return HP1 + EXP1 + M1;
	}
	return -999;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
