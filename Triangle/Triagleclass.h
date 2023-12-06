//Пинчукова Гера ИВТ-22
#ifndef CLASS_TRIAGLE_H
#define CLASS_TRIAGLE_H

#include <string>
using namespace std;


//x1 y1 -координаты точки X
//x2 y2 -координаты точки Y
//x3 y3 -координаты точки Z
//a,b,c-стороны треугольника

class Triangle {
private:
    double x1, y1; // Координаты первой точки
    double x2, y2; // Координаты второй точки
    double x3, y3; // Координаты третьей точки

public:
	enum TriangleT {Equilateral, Isosceles, Rectangular, noExist};
	//Равносторонний, Равнобедренный, Прямоугольный, Несуществующий
	TriangleT type; 

	Triangle();
	Triangle(double x_1,double y_1,double x_2,double y_2,double x_3,double y_3);
//ввод значений точек
	void setX1(double x_1); 
	void setY1(double y_1); 
	void setX2(double x_2); 
	void setY2(double y_2); 
	void setX3 (double x_3);
	void setY3(double y_3); 
//получение значений точек
	double getX1() const; 
	double getY1() const; 
	double getX2() const; 
	double getY2() const; 
	double getX3() const;
    double getY3() const; 
//поиск сторон треугольника
    //A
	double calculateSideA()const;
	//B
	double calculateSideB()const; 
    //C
	double calculateSideC()const; 
 
//поиск периметра треугольника               
	double calculatePerimeter() const; 
//поиск площади треугольника          
	double calculateArea() const;
//вид треугольника                 
	typeof type getTriangleType()const;
//вывод данных в строку         
	string to_stringAll() const ;  
//загрузка данных в бинарный файл
	void savePoint(Triangle& PointF, const std::string& filename);
//загрузка данных из бинарного файла
	void loadFromF(Triangle& PointF, const std::string& filename); 
//функция для поиска сторон треугольника по координатам для 1 стороны
	double calculateSide( double x1, double y1,double x2, double y2 ) const;   
//поиск радиуса вписсанной окружности
   double Triangle::radius_inscribed_circle() const;
//поиск углов треугольника
   //угол А
   double Triangle::CornerTrA() const;
   //угол В   
   double Triangle::CornerTrB() const;
   //угол С   
double Triangle::CornerTrC() const;
//поиск радиуса описанной окружности
double Triangle::radius_circumscribed_circle() const;          
};


void TestAss1();                                  //проверка вычислений 
void TestAss2();
void TestAss3();
#endif

//методы сторон углов
