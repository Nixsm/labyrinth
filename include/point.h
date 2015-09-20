#ifndef POINT_H
#define POINT_H

template<typename T> class Point {
public:
    Point() { }
    Point(const T& x, const T& y)
        :_x(x), _y(y)
    {
        
    }

    T getX() const;
    T getY() const;

    void setX(const T& x);
    void setY(const T& y);

    bool operator==(const Point<T>& other);
private:
    T _x;
    T _y;
};

#endif//POINT_H
