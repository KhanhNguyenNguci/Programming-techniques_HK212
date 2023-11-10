/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
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

class Point {
private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    };
    string toString() const {
        string s = "";
        s += "<Point[";
        s += to_string(this->x);
        s += ",";
        s += to_string(this->y);
        s += "]>";
        return s;
    }

    int distanceTo(const Point& otherPoint) const {
        int d = 0;
        int x1 = this->x, y1 = this->y; //point hien tai
        int x2 = otherPoint.x, y2 = otherPoint.y;
        d = ceil(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
        return d;
    }
};
class Node {
private:
    Point point;
    Node* next;

    friend class Path;

public:
    Node(const Point& point = Point(), Node* next = NULL) {
        this->point = point;
        this->next = next;
    }
    string toString() const {
        string s = "";
        s += "<Node[";
        s += this->point.toString();
        s += "]>";
        return s;
    }
};

class Path {
private:
    Node* head;
    Node* tail;
    int count;
    int length;

public:
    Path() {
        this->head = NULL;
        this->tail = NULL;
        this->count = 0;
        this->length = -1;
    }
    ~Path() {
        while (true) {
            if (this->head == NULL) break;
            if (this->head == this->tail && this->head != NULL) {
                delete this->head;
                this->head = this->tail = NULL;
                break;
            }
            if (this->head != this->tail) {
                Node* k = this->head->next;
                delete this->head;
                this->head = k;
            }
        }
    }

    void addPoint(int x, int y) {
        Point p(x, y);
        Node* pNode = new Node(p, NULL);
        if (this->head == NULL) {
            this->head = this->tail = pNode;
        }
        else {
            this->tail->next = pNode;
            this->tail = pNode;

        }
        this->count++;
        //neu tai su dung length thi lam lai sau
        if (this->head == this->tail && this->head != NULL) {
            this->length = 0;
        }
        if (this->head != this->tail) {
            this->length = 0;
            Node* h = NULL;
            Point p1;
            Point p2;
            for (Node* k = this->head; k != NULL; k = k->next) {
                //todo
                if (h != NULL) {
                    p1 = h->point;
                    p2 = k->point;
                    int d = p1.distanceTo(p2);
                    this->length = this->length + d;
                }
                h = k;
            }
        }
    }
    
    string toString() const {
        string s = "";
        s += "<Path[count:";
        s += to_string(this->count);
        s += ",length:";
        s += to_string(this->length);
        s += ",[";
        for (Node* k = this->head; k != NULL; k = k->next) {
            s += k->toString();
            if (k != this->tail) s += ",";
        }
        s += "]]>";
        return s;
    }
    Point getLastPoint() const {
        return this->tail->point;
    }
    //them phuong thuc
    //tinh length
    int LengthPath() {
        if (this->head == this->tail && this->head != NULL) {
            this->length = 0;
        }
        if (this->head != this->tail) {
            this->length = 0;
            Node* h = NULL;
            Point p1;
            Point p2;
            for (Node* k = this->head; k != NULL; k = k->next) {
                //todo
                if (h != NULL) {
                    p1 = h->point;
                    p2 = k->point;
                    int d = p1.distanceTo(p2);
                    this->length = this->length + d;
                }
                h = k;
            }
        }
        return this->length;
    }
};

class Character {
private:
    string name;
    Path* path;

public:
    Character(const string& name = "") {
        this->name = name;
        this->path = new Path;
    }
    ~Character() {
        //todo
        this->path->~Path();
    }

    string getName() const {
        return this->name;
    }
    void setName(const string& name) {
        this->name = name;
    }

    void moveToPoint(int x, int y) {
        this->path->addPoint(x, y);
    }
    string toString() const {
        string s = "";
        s += "<Character[name:";
        s += this->name;
        s += ",path:";
        s += this->path->toString();
        s += "]>";
        return s;
    }
    ///
    //tu them phuong thuc 
    Path* getter_path() const {
        return this->path;
    }
};

bool rescueSherlock(
    const Character& chMurderer,
    const Character& chWatson,
    int maxLength,
    int maxDistance,
    int& outDistance
) {
    //todo
    int l1 = chWatson.getter_path()->LengthPath();
    int l2 = chMurderer.getter_path()->LengthPath();
    if ((l1 - l2) <= maxLength) {
        const Point p1 = chWatson.getter_path()->getLastPoint();
        const Point p2 = chMurderer.getter_path()->getLastPoint();
        int d = 0;
        d = p1.distanceTo(p2);
        outDistance = d;
        if (d <= maxDistance) return true;
        else return false;
    }
    else {
        outDistance = -1;
        return false;
    }
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */