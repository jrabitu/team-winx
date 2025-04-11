#include <iostream> 
#include <cmath> 
#include <string> 
#include <cstring> 
using namespace std; 
const float PI = 3.14159; 
//эхийн эх класс
class Shape { 
protected: 
char *name;
static int count;
public: 
Shape(const char *n); 
char *getName(); 
virtual void setName(const char *n); 
virtual ~Shape(); 
    static int getCount();
    static void setCount(int c);
}; 
int Shape::count = 0;
Shape::Shape(const char *n) {
this->name = new char[strlen(n)+1];  
strcpy(name, n); 
count++;
} 
Shape::~Shape(){ 
delete[] this->name;  
cout << "Shape destructor" << endl; 
}
char *Shape:: getName() { return this->name; } 
void Shape::setName(const char *n) {  
if (n == nullptr) { 
cout << "Error: Null name provided." << endl; 
return; 
} 
delete[] this->name;
this->name = new char[strlen(n)+1];  
strcpy(this->name, n);  
} 
int Shape::getCount() {
    return count;
}
 
void Shape::setCount(int c) {
    count = c;
}
//abstract 2d класс 
class TwoDShape : public Shape { 
protected: 
float size; // tal, radius zeregt zoriulsan eronhii huwisagch 
public: 
TwoDShape(const char *n, float s); 
virtual float getArea()=0; 
virtual float getPerimeter()=0; 
virtual void printCoordinate()=0; 
virtual ~TwoDShape(); 
}; 
TwoDShape::TwoDShape(const char *n, float s) : Shape(n) {size = s;} 
TwoDShape::~TwoDShape() { cout << "TwoDShape destructor" << endl; } 
// КВАДРАТ 
class Square : public TwoDShape { 
private: 
float zuunDeedX, zuunDeedY; 
public: 
Square(const char *n, float x, float y, float urt); 
float getArea() override; 
float getPerimeter() override; 
void printCoordinate() override; 
~Square(); 
}; 
Square::Square(const char *n, float x, float y, float urt) : TwoDShape(n, 
urt) { 
zuunDeedX = x; 
zuunDeedY = y; 
} 
float Square::getArea() { return size * size; } 
float Square::getPerimeter() { return 4 * size; } 
void Square::printCoordinate() { 
cout << "Zuun deed: (" << zuunDeedX << ", " << zuunDeedY << ")" << 
endl; 
cout << "Baruun deed: (" << zuunDeedX + size << ", " << zuunDeedY << 
")" << endl; 
cout << "Baruun dood: (" << zuunDeedX + size << ", " << zuunDeedY – 
size << ")" << endl; 
cout << "Zuun dood: (" << zuunDeedX << ", " << zuunDeedY - size << 
")" << endl;} 
Square::~Square() { 
cout << "Square destructor" << endl;} 
// ТОЙРОГ 
class Circle : public TwoDShape { 
private: 
float tuvX, tuvY; 
public: 
Circle(const char *n, float x, float y, float r); 
float getArea() override; 
float getPerimeter() override; 
void printCoordinate() override; 
~Circle(); 
}; 
Circle::Circle(const char *n, float x, float y, float r): TwoDShape(n, r) 
{ 
tuvX = x; 
tuvY = y; 
} 
float Circle::getArea() { 
return PI * size * size; 
} 
float Circle::getPerimeter() { 
return 2 * PI * size; 
} 
void Circle::printCoordinate() { 
cout << "Tuv: (" << tuvX << ", " << tuvY << ")" << endl; 
cout << "Radius: " << size << endl; 
} 
Circle::~Circle() { 
cout << "Circle destructor" << endl; 
} 
// ЗӨВ ГУРВАЛЖИН 
class Triangle : public TwoDShape { 
private: 
float deedOroiX, deedOroiY; 
public: 
Triangle(const char *n, float x, float y, float urt); 
float getArea() override; 
float getPerimeter() override; 
void printCoordinate() override; 
~Triangle(); 
}; 
Triangle::Triangle(const char *n, float x, float y, float urt) : 
TwoDShape(n, urt) { 
deedOroiX = x; 
deedOroiY = y; 
} 
float Triangle::getArea() { 
return (sqrt(3) / 4) * size * size; 
} 
float Triangle::getPerimeter() { 
return 3 * size; 
} 
void Triangle::printCoordinate() { 
float ondor = (size * sqrt(3)) / 2; 
cout << "Deed oroi: (" << deedOroiX << ", " << deedOroiY << ")" << 
endl; 
cout << "Baruun dood: (" << deedOroiX + size / 2 << ", " << deedOroiY - ondor << ")" << endl; 
cout << "Zuun dood: (" << deedOroiX - size / 2 << ", " << deedOroiY – 
ondor << ")" << endl; 
} 
Triangle::~Triangle() { 
cout << "Triangle destructor" << endl; 
} 
int main() { 
int n; 
cout << "heden durs uusgeh we?"<<endl; 
cin >>n; 
TwoDShape **shapes=new TwoDShape*[n]; 
for(int i=0; i<n; i++){ 
int turul; 
char name[100]; 
float size, x, y; 
cout << "\n[Durs " << i + 1 << "]" << endl; 
cout<<"Dursiin turliig songono uu: (1: kvadrat, 2: toirog, 3: 
gurvaljin)"<<endl; 
cin >>turul; 
cout<<"Dursiin ner: "<<endl; 
cin >> name; 
cout<<"Dursiin hemjee: (taliin urt, radius)"<<endl; 
cin >> size; 
cout<<"Dursiin coordinate iig oruulna uu: (x, y)"<<endl; 
cin >> x >> y; 
switch (turul){ 
case 1: 
shapes[i]=new Square(name, x, y, size); 
break; 
case 2: 
shapes[i]=new Circle(name, x, y, size); 
break; 
case 3: 
shapes[i]=new Triangle(name, x, y, size); 
break; 
default: 
                cout<< "aldaa garlaa! zuw turul oruulna uu.\n"; 
                i--; 
                break; 
        } 
    } 
                 
    for (int i=0; i<n; i++){ 
        for( int j=0; j<n-1; j++){ 
            if(shapes[j]->getArea() > shapes[j+1]->getArea()){ 
                TwoDShape *temp = shapes[j]; 
                shapes[j] = shapes[j+1]; 
                shapes[j+1] = temp; 
            } 
        } 
    } 
 
    //hewleh 
    cout << "\n=========================\n" << endl; 
    for(int i=0; i<n; i++){ 
        cout << "Dursiin ner: " << shapes[i]->getName() << endl; 
        cout << "Talbai: " << shapes[i]->getArea() << endl; 
        cout << "Perimeter: " << shapes[i]->getPerimeter() << endl; 
        shapes[i]->printCoordinate(); 
        cout << "\n=========================\n" << endl; 
    } 
 
    //sanah oig chuluuluh 
    for(int i=0; i<n; i++){ 
        delete shapes[i]; 
    } 
 
    delete[] shapes; 
    cout<<"code ajillaj duuslaa"<<endl; 
 
    return 0; 
} 