#include "Point.h"
#include<math.h>

Point::Point(double x, double y, double z){
    _x=x; _y=y; _z=z;
}
double Point::getX()const{
    return _x;
}
double Point::getY()const{
    return _y;
}
double Point::getZ()const{
    return _z;
}
void Point::negate(){
    _x*=-1; _y*=-1; _z*=-1;
}
double Point::norm()const{
    return sqrt(_x*_x + _y*_y + _z*_z);
}
std::ostream& operator<<(std::ostream& os, const Point& p){
    return os<<"("<<p.getX()<<","<<p.getY()<<","<<p.getZ()<<")";
}
Point operator+(const Point& p1, const Point& p2){
    return Point(p1.getX()+p2.getX(),p1.getY()+p2.getY(),p1.getZ()+p2.getZ());
}