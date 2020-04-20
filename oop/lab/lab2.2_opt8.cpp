#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class Figures {
    public:
        virtual void square() {
        };
        virtual void perimeter() {
        };
};

class Rectangles: public Figures {
    public:
        float x, y;
        float getSquare() {
            return x * y;
        };
        float getPerimeter() {
            return 2 * (x + y);
        };
        Rectangles(float width, float height) {
            x = width;
            y = height;
        };
};

class Circle: public Figures {
    public:
        float r;
        float getSquare() {
            return M_PI * r * r;
        }
        float getPerimeter() {
            return 2 * M_PI * r;
        };
        Circle(float radius) {
            r = radius;
        };
};

int main() {
    float x, y;
    float r;

    cout << "Enter the length of the rectangle: ";
    cin >> x;

    cout << "Enter the width of the rectangle: ";
    cin >> y;

    Rectangles recObj(x,y);

    cout << "Rectangle Square = " << recObj.getSquare() << "\n";
    cout << "Rectangle Perimeter = " << recObj.getPerimeter() << "\n";

    cout << "\nEnter the circle radius: ";
    cin >> r;

    Circle circleObj(r);

    cout << "Circle Square = " << circleObj.getSquare() << "\n";
    cout << "Circle Perimeter = " << circleObj.getPerimeter() << "\n";

    return 0;
}
