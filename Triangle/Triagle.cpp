//Пинчукова Гера ИВТ-22
#include "Triagleclass.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cassert> 
#include <vector>
using namespace std;

int main(){
     	//
	Triangle NewTriagle;
	//проверка данных
	TestAss1();
    TestAss2();
    TestAss3();

char check;
//загрузка данных из бинарного файла
cout<<"Load points? y/n"<<endl;
cin>>check;
if ((check=='y')or (check=='Y'))
{ 
	string fileName;
	cout<<"The name of file";
	cin>>fileName;
	NewTriagle.loadFromF(NewTriagle,fileName);//загрузка вайла
	cout<<"coordinates:"<<" "<<NewTriagle.getX1()<<" "<<NewTriagle.getY1()<<endl<<
	NewTriagle.getX2()<<" "<<NewTriagle.getY2()<<endl<<NewTriagle.getX3()<<" "<<NewTriagle.getY3()<<endl;

}
else

    //переменные для ввода координат

	for (unsigned i=0; i<3;i++){
		double step1,step2;
		cout<<"write the coordimates(x,y):";
		cin>>step1>> step2;
		switch(i){
			//ввод координат
		case 0: NewTriagle.setX1(step1);
			    NewTriagle.setY1(step2); break;
		case 1: NewTriagle.setX2(step1);
			    NewTriagle.setY2(step2); break;
		case 2: NewTriagle.setX3(step1);
			    NewTriagle.setY3(step2); break;	    	    
		}
	}	//переменные для поиска сторон треугольника
double a,b,c;
string s;
char answ;  
char answ2;

//изменение координат 
cout << "new coordinates? y/n: ";
	cin >> answ;
	//пока не будет n будет ввод новых координат
	while (answ == 'y'){ 
		//указать какую координату изменить
	cout << "name of new coordinates: ";
	char answ2;
	cin >> answ2;
		switch (answ2) {
			double step1,step2;
			//изменение x
		case 'x': {cout << "New x1 y1 "; 
			    cin >> step1>> step2; 
			   NewTriagle.setX1(step1);
			   NewTriagle.setY1(step2); break;}
            //изменение y
		case 'y': {cout << "New x2 y2 "; 
			    cin >> step1>> step2; 
			    NewTriagle.setX2(step1);
			   NewTriagle.setY2(step2); break;}
			 //изменение z
		case 'z':{cout << "New x3 y3 "; 
			    cin >> step1>> step2; 
			   NewTriagle.setX3(step1);
			   NewTriagle.setY3(step2); break;}
		}

cout << "change coordinates? y/n: ";//изменение координат
	cin >> answ;
	}
	//вывод результатов 
	 	s=NewTriagle.to_stringAll();
        cout<<s; 
//сохранение координат в бинарный файл
cout<<"Do u want to save coordinates? y/n";
cin>>check;

if ((check=='y')or (check=='Y'))
{ string fileName;
	cin>>fileName;

	NewTriagle.savePoint(NewTriagle,fileName);
}
char answ3;
cout<<"Do u want to get 1 side?"<<endl;
cin>>answ3;
if ((check=='y')or (check=='Y')){
int d;
	cout<<"1 (x-y) 2(y-z) 3(z-y)"<<endl;
	cin>>d;
    switch (d){
    case '1':{cout<<NewTriagle.calculateSide(NewTriagle.getX1(),NewTriagle.getY1(),NewTriagle.setX2(),NewTriagle.setY2())<<endl;}
    case '2':{cout<<NewTriagle.calculateSide(NewTriagle.getX2(),NewTriagle.getY2(),NewTriagle.setX3(),NewTriagle.setY3())<<endl;}
    case '3':{cout<<NewTriagle.calculateSide(NewTriagle.getX1(),NewTriagle.getY1(),NewTriagle.setX3(),NewTriagle.setY3())<<endl;}	
    }
}



const int size = 2;

    // Динамический объект 
	Triangle * 	dinTrian = new Triangle();
	(*dinTrian).setX1(3); 
	dinTrian->setY1(4); 	
	//работа с дин объектами
	cout << "Dinamic X (x,y) = " << dinTrian->getX1() << " "<< dinTrian->getY1() << endl;

	delete dinTrian; 		//удаление динамического объекта

    // Создание cтатического массива объектов
    Triangle triangles[size];
    triangles[0].setX1(2);
    triangles[1].setY1(1);
    cout<<"Statistic: (x,y) "<<triangles[0].getX1()<<" "<<triangles[1].getY1()<<endl;

    // Создание массива указателей на объекты
    Triangle* trianglePointers[size];
    trianglePointers[0] = new Triangle();
    trianglePointers[1]= new Triangle();
    trianglePointers[0]->setX1(3);
    trianglePointers[1]->setY1(5);
    //работа с массивом указателей на объекты
    cout<<"Pointers Mas"<<trianglePointers[0]->getX1()<<" "<<trianglePointers[1]->getY1()<<endl;

    // Вызов метода для одного элемента из массива указателей
   cout<<trianglePointers[0]->to_stringAll()<<endl;;
    // Освобождение памяти
    for (int i = 0; i <size; i++) {
        delete trianglePointers[i];
    }

//  дин массив из указателей на объекты
 	Triangle * * TriangleDU= new Triangle* [2];
 	for (int i = 0; i < 2; i++) TriangleDU[i] = new Triangle(); //создание и выделение памяти
 	
 	TriangleDU[0]->setX1(8);
    TriangleDU[1]->setY1(18);




cout<<"DU :"<<TriangleDU[0]->getX1()<<" "<<TriangleDU[1]->getY1()<<endl;
 	//пример использов
 		//удаление каждого
 delete TriangleDU[0];
 delete TriangleDU[1];
	delete[] TriangleDU; 		   

// Массив с помощью векторов
 	vector<Triangle*> TriangleDU_Vect(2);

 	TriangleDU_Vect[0]->setX1(4);
 	TriangleDU_Vect[1]->setY1(9);
 	cout<<"Vector"<<TriangleDU_Vect[0]->getX1()<<TriangleDU_Vect[1]->getY1()<<endl;

 	
 	// Массив с помощью векторов из указателей
 	vector<Triangle*> TriangleVect(2);
 	for (int i = 0; i < TriangleVect.size(); i++)
 	TriangleVect[i] = new Triangle(); //создание и выделение памяти
   TriangleVect[0]->setX1(11);
   TriangleVect[1]->setY1(11);

   cout<<"Vect:"<<TriangleVect[0]->getX1()<<TriangleVect[1]->getY1()<<endl;
}

