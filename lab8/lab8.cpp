#include <iostream> 
#include <cmath> 
#include <string> 
#include <cstring> 
using namespace std;

const float PI = 3.14159; 

//ЭХ КЛАСС: SHAPE CLASS
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
//ФУНКЦИЙН ТОДОРХОЙЛОЛТ
int Shape::count = 0;

Shape::Shape(const char *n) {
  this->name = new char[strlen(n)+1];  
  strcpy(this->name, n); 
  count++;
} 

Shape::~Shape(){ 
  delete[] this->name;  
  cout << "Shape destructor" << endl; 
}

char *Shape:: getName() { return this->name; } 
void Shape::setName(const char *n) {  
  if (n == nullptr) { 
    cout << "name null bna" << endl; 
    return; 
  } 
  delete[] this->name;
  this->name = new char[strlen(n)+1];  
  strcpy(this->name, n);  
}

int Shape::getCount() {return count;}
void Shape::setCount(int c) {count = c;}


//abstract 2dshape класс 
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

//ФУНКЦИЙН ТОДОРХОЙЛОЛТ
TwoDShape::TwoDShape(const char *n, float s) : Shape(n) {this->size = s;} 
TwoDShape::~TwoDShape() { cout << "TwoDShape destructor" << endl; } 

// КВАДРАТ КЛАСС 
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
//ФУНКЦИЙН ТОДОРХОЙЛОЛТ
Square::Square(const char *n, float x, float y, float urt) : TwoDShape(n, urt) { 
  zuunDeedX = x; 
  zuunDeedY = y; 
}

float Square::getArea() { return this->size * this->size; } 
float Square::getPerimeter() { return 4 * this->size; } 

void Square::printCoordinate() {
  cout << "Zuun deed: (" << zuunDeedX << ", " << zuunDeedY << ")" << endl;
  cout << "Baruun deed: (" << zuunDeedX + size << ", " << zuunDeedY << ")" << endl;
  cout << "Baruun dood: (" << zuunDeedX + size << ", " << zuunDeedY - size << ")" << endl;
  cout << "Zuun dood: (" << zuunDeedX << ", " << zuunDeedY - size << ")" << endl;}

Square::~Square() {cout << "Square destructor" << endl;} 

// ТОЙРОГ КЛАСС
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

//ФУНКЦИЙН ТОДОРХОЙЛОЛТ
Circle::Circle(const char *n, float x, float y, float r): TwoDShape(n, r){ 
  tuvX = x; 
  tuvY = y; 
} 
float Circle::getArea() {return PI * size * size;} 
float Circle::getPerimeter() {return 2 * PI * size;}

void Circle::printCoordinate() {
  cout << "Tuv: (" << tuvX << ", " << tuvY << ")" << endl; 
  cout << "Radius: " << size << endl; 
}

Circle::~Circle() {cout << "Circle destructor" << endl;}


// ЗӨВ ГУРВАЛЖИН КЛАСС
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

//ФУНКЦИЙН ТОДОРХОЙЛОЛТ
Triangle::Triangle(const char *n, float x, float y, float urt):TwoDShape(n, urt) { 
  deedOroiX = x; 
  deedOroiY = y; 
} 
float Triangle::getArea() {return (sqrt(3) / 4) * size * size;} 
float Triangle::getPerimeter() {return 3 * size;}

void Triangle::printCoordinate() { 
  float ondor = (size * sqrt(3)) / 2; 
  cout << "Deed oroi: (" << deedOroiX << ", " << deedOroiY << ")" << endl; 
  cout << "Baruun dood: (" << deedOroiX + size / 2 << ", " << deedOroiY - ondor << ")" << endl; 
  cout << "Zuun dood: (" << deedOroiX - size / 2 << ", " << deedOroiY - ondor << ")" << endl; 
}

Triangle::~Triangle() {cout << "Triangle destructor" << endl;}


//MAIN ФУНКЦ
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
    cout << "Dursiin turliig songono uu: (1: kvadrat, 2: toirog, 3: gurvaljin)" << endl;
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
  
  //ТАЛБАЙ БОЛОН ПЕРИМЕТРЭЭР АНГИЛАХ
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      float area1 = shapes[j]->getArea();
      float area2 = shapes[j + 1]->getArea();

      float perim1 = shapes[j]->getPerimeter();
      float perim2 = shapes[j + 1]->getPerimeter();

      if (area1 > area2 || (area1 == area2 && perim1 > perim2)) {
          TwoDShape *temp = shapes[j];
          shapes[j] = shapes[j + 1];
          shapes[j + 1] = temp;
      }
    }
  }
 
  //ХЭВЛЭХ 
  cout << "\n================Dursiin medeeelel================\n" << endl; 
  for(int i=0; i<n; i++){ 
      cout << "\nDursiin ner: " << shapes[i]->getName() << endl; 
      cout << "Talbai: " << shapes[i]->getArea() << endl; 
      cout << "Perimeter: " << shapes[i]->getPerimeter() << endl; 
      shapes[i]->printCoordinate(); 
      cout << "\n=========================\n" << endl; 
  } 

  //COUNTER-Г ХАРУУЛАХ
  cout<< "\nNiit uussen dursiin too: "<<Shape::getCount()<<endl;

  //САНАХ ОЙ ЧӨЛӨӨЛӨХ
  for(int i=0; i<n; i++){ 
    delete shapes[i]; 
  } 

  delete[] shapes; 
  cout<<"code ajillaj duuslaa"<<endl; 

  return 0; 
} 