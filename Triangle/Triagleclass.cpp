//Пинчукова Гера ИВТ-22
#include "Triagleclass.h"
#include <cmath>
#include <string>
#include <iostream>
#include <cassert>
#include<fstream>
#include<typeinfo>
using namespace std;

//x1 y1 -координаты точки X
//x2 y2 -координаты точки Y
//x3 y3 -координаты точки Z
//a,b,c-стороны
/// Конструктор
 Triangle::Triangle()
 {
		x1=y1=x2=y2=x3=y3=0.0;//задаем начальные значения координат
	}

   Triangle::Triangle(double x_1,double y_1,double x_2,double y_2,double x_3,double y_3) {
    setX1(x_1);
    setY1(y_1);
    setX2(x_2);
    setY3(y_2);
    setX3(x_3);
    setY3(y_3);
    }
    //Функции ввода координат вершин треугольника
    //для X(x1;y1); Y(x2,y2); Z(x3,y3)

	 void Triangle::setX1(double x_1) {
        x1=x_1;
    }
    void  Triangle::setY1(double y_1) {
       y1=y_1;
    }
    void  Triangle::setX2(double x_2) {
        x2=x_2;
    }
    void  Triangle::setY2(double y_2) {
        y2=y_2;
    }
    void  Triangle::setX3(double x_3) {
        x3=x_3;
    }
    void  Triangle::setY3(double y_3) {
         y3=y_3;
    }


    //Функции вывода координат вершин треугольника
    //для X(x1;y1); Y(x2,y2); Z(x3,y3)
    double Triangle::getX1() const {
        return x1;
    }
     double Triangle::getY1() const {
        return y1;
    }
     double Triangle::getX2() const {
        return x2;
    }
     double Triangle::getY2() const{
        return y2;
    }
     double Triangle::getX3() const{
       return x3;
    }
     double Triangle::getY3() const{
       return y3;
    }

    ///функция для поиска сторон треугольника по координатам для 1 стороны
   // double  Triangle::calculateSide( double x1, double y1,double x2, double y2 ) const{  ////////////////////new
   //      return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
   //  }



    ///функция для поиска сторон треугольника по координатам
    //A
     double  Triangle::calculateSideA() const{
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }                                                  
    //B      
 double  Triangle::calculateSideB() const{
        return sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    }  
    //C
     double  Triangle::calculateSideC() const{
        return sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    }  

  
//поиск радиуса вписсанной окружности
   double Triangle::radius_inscribed_circle() const{
    double s=this->calculateArea();
    double p=this->calculatePerimeter();
    return s/p;
   }

//поиск углов треугольника
//угол А
   double Triangle::CornerTrA() const{
a =this-> calculateSideA();
b =this-> calculateSideB();
c =this-> calculateSideC();
  return cos(b*b + c*c - (a*a)/(2*b*c));
   }
//угол В   
   double Triangle::CornerTrB() const{
a =this-> calculateSideA();
b =this-> calculateSideB();
c =this-> calculateSideC();
  return cos(c*c + a*a - (b*b)/(2*a*c));
   }
//угол С   
double Triangle::CornerTrC() const{
a =this-> calculateSideA();
b =this-> calculateSideB();
c =this-> calculateSideC();
  return cos(a*a + b*b - (c*c)/(2*b*a));
   }

//поиск радиуса описанной окружности
double Triangle::radius_circumscribed_circle() const{
a =this-> calculateSideA();
b =this-> calculateSideB();
c =this-> calculateSideC();
double s=this->calculateArea();
 return (a*b*c)/(4*s);


  }


 //double  Triangle::calculateSide = [](double x1, double y1, double x2, double y2) {
       // return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
   // };


    /// функция для поиска периметра треугольника по координатам
     double  Triangle::calculatePerimeter() const{
        double a,b,c;
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
        return a + b + c;
    }

    ///функция для поиска площади треугольника по координатам
    //по формуле с использованием полупериметра (semiPerimeter)
     double  Triangle::calculateArea() const {
        double a,b,c;
         a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
         b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
         c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
        double semiPerimeter = (a + b + c) / 2;  
        return sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
    }

    ///функция поиска вида треугольника
    typeof Triangle::type Triangle::getTriangleType()const {
    double a, b, c;
    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

    if (a == b && b == c) {
        return TriangleT::Equilateral;
    }
    else if (a == b || b == c || c == a) {
        return TriangleT::Isosceles;
    }
    else if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2) || pow(c, 2) + pow(a, 2) == pow(b, 2)) {
        return TriangleT::Rectangular;
    }
    else  
        return TriangleT::noExist;
    
}
   

std::string Triangle::to_stringAll() const { //вывод полученных результатов в строку
    std::string s;
  switch (type) {
        case TriangleT::Equilateral:  
            s = "Equilateral";
            break;
        case TriangleT::Isosceles:
            s = "Isosceles";
            break;
        case TriangleT::Rectangular:
            s = "Rectangular";
            break;
        case TriangleT::noExist:
            s = "noExist";
            break;
        default:
            s = "Unknown";
            break;
    }
            return "Triangle with vertices:\n"
               "X(" + std::to_string(x1) + ";" + std::to_string(y1) + ")\n"
               "Y(" + std::to_string(x2) + ";" + std::to_string(y2) + ")\n"
               "Z(" + std::to_string(x3) + ";" + std::to_string(y3) + ")\n"
               "Type: " + s+ "\n"
               "Perimeter: " + std::to_string(calculatePerimeter()) + "\n"
               "Area: " + std::to_string(calculateArea()) + "\n"
               "the radius of the circumscribed circle  "+std::to_string(radius_circumscribed_circle())+"\n"
               "the radius of the  circle  "+std::to_string(radius_inscribed_circle())+"\n"
               "Corner A  "+ std::to_string(CornerTrA())+"\n"
               "Corner B  "+ std::to_string(CornerTrB())+"\n"
               "Corner C  "+ std::to_string(CornerTrC())+"\n"
               ;
    }



//проверка треугольника(прямоугольного)
    void TestAss1(){
        // Triangle TestTriagle;
        {
          Triangle TestTriagle(2,3,2,7,5,3);
          // TestTriagle.setX1(2);
          // TestTriagle.setY1(3);
          // TestTriagle.setX2(2);
          // TestTriagle.setY2(7);
          // TestTriagle.setX3(5);
          // TestTriagle.setY3(3);
          cout<<"X:"<<endl;
      cout<<TestTriagle.getX1() <<endl;
      cout<<TestTriagle.getY1()<<endl;
        cout<<"Y:"<<endl;
      cout<<TestTriagle.getX2()<<endl;
      cout<<TestTriagle.getY2() <<endl;
        cout<<"Z:"<<endl;
      cout<<TestTriagle.getX3()<<endl;
      cout<<TestTriagle.getY3() <<endl;


         double Test= TestTriagle.calculateArea();//проверка площади
            assert(Test-6<= 0.1);

        double  Test2=TestTriagle.calculatePerimeter();//проверка периметра
        assert(12.0-Test2 <0.01);

        assert(TestTriagle.getTriangleType()==2);  //проверка вида треугольника(прямоугольного)
        }
    }

//проверка  треугольника(равнобедренного)
        void TestAss2(){
        Triangle TestTriagle;
        {
            //Triangle(2,3,2,7,5,3);
          TestTriagle.setX1(-3);
          TestTriagle.setY1(0);
          TestTriagle.setX2(3);
          TestTriagle.setY2(0);
          TestTriagle.setX3(0);
          TestTriagle.setY3(5);
          cout<<"X:"<<endl;
      cout<<TestTriagle.getX1() <<endl;
      cout<<TestTriagle.getY1() <<endl;
        cout<<"Y:"<<endl;
      cout<<TestTriagle.getX2() <<endl;
      cout<<TestTriagle.getY2() <<endl;
        cout<<"Z:"<<endl;
      cout<<TestTriagle.getX3() <<endl;
      cout<<TestTriagle.getY3() <<endl;
         double Test= TestTriagle.calculateArea();//проверка площади
            //assert(Test==15);

        double  Test2=TestTriagle.calculatePerimeter();//проверка периметра
        assert(12.0-Test2 <0.01);

        assert(TestTriagle.getTriangleType()==1);  //проверка вида треугольника(равнобедренного)
        }
    }

//проверка треугольника(равностороннего)
        void TestAss3(){
        Triangle TestTriagle;
        {
          TestTriagle.setX1(0);
          TestTriagle.setY1(0);
          TestTriagle.setX2(2);
          TestTriagle.setY2(3.464);
          TestTriagle.setX3(4);
          TestTriagle.setY3(0);
          cout<<"X:"<<endl;
      cout<<TestTriagle.getX1() <<endl;
      cout<<TestTriagle.getY1() <<endl;
        cout<<"Y:"<<endl;
      cout<<TestTriagle.getX2() <<endl;
      cout<<TestTriagle.getY2() <<endl;
        cout<<"Z:"<<endl;
      cout<<TestTriagle.getX3() <<endl;
      cout<<TestTriagle.getY3() <<endl;


         double Test= TestTriagle.calculateArea();//проверка площади
            assert(Test-6.928<0.1);

        double  Test2=TestTriagle.calculatePerimeter();//проверка периметра
        assert(12.0-Test2 <0.001);

        }
    }

//загрузка данных в бинарный файл
void Triangle::savePoint(const std::string& filename)
{
  std::ofstream file(filename, std::ios::binary);
  if (file.is_open())
  {
    double temp;
    // file.write(reinterpret_cast< char*>(&temp), sizeof(temp));-преобразет их значения (дабл) в указатель на char и используя функцию write для записи в файл.

    temp = this->getX1();
    file.write(reinterpret_cast< char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 
    temp = this->getY1();
    file.write(reinterpret_cast< char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 

    temp = this->getX2();
    file.write(reinterpret_cast< char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 
    temp = this->getY2();
    file.write(reinterpret_cast< char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 


    temp = this->getX3();
    file.write(reinterpret_cast< char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 
    temp = this->getY3();
    file.write(reinterpret_cast< char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 
    file.close();
  }
  else {
        throw std::runtime_error("File_is_not_found_");
  }
}

///загрузка данных из бинарного файла


void Triangle::loadFromF(Triangle& PointF, const std::string& filename)
{
  std::ifstream file(filename, std::ios::binary);
  if (file.is_open()) {

      double temp;
    // file.write(reinterpret_cast< char*>(&temp), sizeof(temp));-преобразет их значения (дабл) в указатель на char и используя функцию write для записи в файл.
  file.read(reinterpret_cast<char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 
  PointF.setX1(temp);
  file.read(reinterpret_cast<char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 
  PointF.setY1(temp);

 file.read(reinterpret_cast<char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 
  PointF.setX2(temp);
  file.read(reinterpret_cast<char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 
  PointF.setY2(temp);

   file.read(reinterpret_cast<char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 
  PointF.setX3(temp);
  file.read(reinterpret_cast<char*>(&temp), sizeof(temp));// (sieof) размер temp в байтах 
  PointF.setY3(temp);  
  }

   else {
       throw std::runtime_error("File_is_not_found_");
  }
}

 
