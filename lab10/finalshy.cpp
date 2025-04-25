#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

const float PI = 3.14159;

// ---------------------- Shape болон дүрсүүд ----------------------

class Shape {
protected:
    char *name;
public:
    Shape(const char *n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    virtual ~Shape() {
        delete[] name;
        cout << "Shape destructor" << endl;
    }
    virtual void setName(const char *n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    char *getName() { return name; }
};

class TwoDShape : public Shape {
protected:
    float size; // талын урт, радиус гэх мэт
public:
    TwoDShape(const char *n, float s) : Shape(n), size(s) {}
    virtual float getArea() = 0;
    virtual float getPerimeter() = 0;
    virtual void printCoordinate() = 0;
    virtual ~TwoDShape() { cout << "TwoDShape destructor" << endl; }
};

// КВАДРАТ
class Square : public TwoDShape {
    float x, y;
public:
    Square(const char *n, float x, float y, float urt) : TwoDShape(n, urt), x(x), y(y) {}
    float getArea() override { return size * size; }
    float getPerimeter() override { return 4 * size; }
    void printCoordinate() override {
        cout << "Zuun deed: (" << x << ", " << y << ")" << endl;
        cout << "Baruun deed: (" << x + size << ", " << y << ")" << endl;
        cout << "Baruun dood: (" << x + size << ", " << y - size << ")" << endl;
        cout << "Zuun dood: (" << x << ", " << y - size << ")" << endl;
    }
    ~Square() { cout << "Square destructor" << endl; }
};

// ТОЙРОГ
class Circle : public TwoDShape {
    float x, y;
public:
    Circle(const char *n, float x, float y, float r) : TwoDShape(n, r), x(x), y(y) {}
    float getArea() override { return PI * size * size; }
    float getPerimeter() override { return 2 * PI * size; }
    void printCoordinate() override {
        cout << "Tuv: (" << x << ", " << y << "), Radius: " << size << endl;
    }
    ~Circle() { cout << "Circle destructor" << endl; }
};

// ГУРВАЛЖИН
class Triangle : public TwoDShape {
    float x, y;
public:
    Triangle(const char *n, float x, float y, float urt) : TwoDShape(n, urt), x(x), y(y) {}
    float getArea() override { return (sqrt(3) / 4) * size * size; }
    float getPerimeter() override { return 3 * size; }
    void printCoordinate() override {
        float ondor = (size * sqrt(3)) / 2;
        cout << "Deed oroi: (" << x << ", " << y << ")" << endl;
        cout << "Baruun dood: (" << x + size / 2 << ", " << y - ondor << ")" << endl;
        cout << "Zuun dood: (" << x - size / 2 << ", " << y - ondor << ")" << endl;
    }
    ~Triangle() { cout << "Triangle destructor" << endl; }
};

// ---------------------- Template List<T> ----------------------

/*
  Загвар класс ашиглан дурын төрлийн жагсаалт үүсгэнэ.
  List<T> нь:
    - add(T)
    - insert(T, index)
    - get(index)
    - remove(index)
    - length()
    - sortByArea() функцтэй
*/

template <typename T>
class List {
private:
    T* data;
    int count;
    int capacity;

public:
    List() {
        capacity = 100;
        data = new T[capacity];
        count = 0;
    }

    void add(T t) {
        if (count < capacity)
            data[count++] = t;
        else
            cout << "Jagsaalt duursen!" << endl;
    }

    void insert(T t, int index) {
        if (index < 0 || index > count || count >= capacity) return;
        for (int i = count; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = t;
        count++;
    }

    T get(int index) {
        if (index < 0 || index >= count) return nullptr;
        return data[index];
    }

    void remove(int index) {
        if (index < 0 || index >= count) return;
        delete data[index]; // динамик санах ойг чөлөөлнө
        for (int i = index; i < count - 1; i++) {
            data[i] = data[i + 1];
        }
        count--;
    }

    int length() { return count; }

    void sortByArea() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (data[j]->getArea() > data[j + 1]->getArea()) {
                    T temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    ~List() {
        for (int i = 0; i < count; i++) {
            delete data[i];
        }
        delete[] data;
    }
};

// ---------------------- MAIN ----------------------
int main() {
    srand(time(0)); // санамсаргүй үр үүсгэнэ
    List<TwoDShape*> shapes;

    int n = 20 + rand() % 11; // 20-30 тооны дүрс

    for (int i = 0; i < n; i++) {
        int turul = 1 + rand() % 3; // 1=square, 2=circle, 3=triangle
        float size = 1 + rand() % 10;
        float x = rand() % 100;
        float y = rand() % 100;

        string ner = (turul == 1 ? "Square" : (turul == 2 ? "Circle" : "Triangle")) + to_string(i + 1);

        switch (turul) {
            case 1:
                shapes.add(new Square(ner.c_str(), x, y, size));
                break;
            case 2:
                shapes.add(new Circle(ner.c_str(), x, y, size));
                break;
            case 3:
                shapes.add(new Triangle(ner.c_str(), x, y, size));
                break;
        }
    }

    shapes.sortByArea(); // Талбайгаар эрэмбэлнэ

    cout << "\n=========== ЭРЭМБЭЛСЭН ДҮРСҮҮД ===========\n" << endl;
    for (int i = 0; i < shapes.length(); i++) {
        cout << "Ner: " << shapes.get(i)->getName() << endl;
        cout << "Talbai: " << shapes.get(i)->getArea() << endl;
        cout << "Perimeter: " << shapes.get(i)->getPerimeter() << endl;
        shapes.get(i)->printCoordinate();
        cout << "-----------------------------\n";
    }

    cout << "code ajillaj duuslaa." << endl;
    return 0;
}