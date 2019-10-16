#include<iostream>
class Point{
    private:
        double _x,_y,_z;
    public:
        Point(double x=0, double y=0, double z=0);
        double getX()const;
        double getY()const;
        double getZ()const;
        void negate();
        double norm()const; 
};
std::ostream& operator<<(std::ostream&, const Point&);
Point operator+(const Point&, const Point&); //Lo metto fuori dalla classe per mantenere la proprietà commutativa