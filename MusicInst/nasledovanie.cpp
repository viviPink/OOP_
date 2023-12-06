//Pinchukova Gera

#include <iostream>
#include <string>
using namespace std;

// базовый класс 
//определены основные свойства инструмента, такие как 
//стоимость ремонта, материал изготовления, 
//страна производства и название инструмента.
class MusicalInstrument {
protected:
    double settingsCost;  // стоимость ремонта инструмента
    string Material;      // материал из которого сделан инструмент
    string CountryMade;   // страна в которой изобретен инструмент
    string InstrumentName; // название инструмента

public:
    // конструктор для базового класса
    MusicalInstrument() : settingsCost(0.0) {}
    virtual ~MusicalInstrument() {}

    // абстрактный метод
    virtual void ElementPlay() = 0;

    // ввод стоимости ремонта
    void setSettingCost(const double cost) { settingsCost = cost; }
    // вывод стоимости ремонта
    double getSettingCost() const { return settingsCost; }

    // ввод страны производства
    void setMadeIn(const string Country) { CountryMade = Country; }
    // вывод страны производства
    string getMadeIn() const { return CountryMade; }

    // ввод материала инструмента
    void setMaterial(const string material) { Material = material; }
    // вывод материала производства
    string getMaterial() const { return Material; }

    // ввод названия инструмента
    void setInstrumentName(const string name) { InstrumentName = name; }
    // вывод названия инструмента
    string getInstrumentName() const { return InstrumentName; }

    // вывод информации о инструменте (название, материал, производство, стоимость ремонта)
    virtual void showInfo() {
        cout << "Instrument Name: " << InstrumentName << endl;
        cout << "Material: " << Material << endl;
        cout << "Made in: " << CountryMade << endl;
        cout << "Settings Cost: " << settingsCost << endl;
    }
};

// производный класс Струнные инструменты
class StringsInst : public MusicalInstrument {
protected:
    int numberOfStrings; //количество струн
//внутренний класс содержит уникальные свойства для струнных 
//инструментов,техника игры и материал струн
    class UniqueStringsInfo {
    private:
        int playingTechnique;  //техника игры
        string stringMaterial; //материал струн
    public:
         
       //внутренний класс содержит уникальные свойства для струнных 
       //инструментов,техника игры и материал струн
        UniqueStringsInfo() : playingTechnique(0), stringMaterial("") {}


        void setPlayingTechnique(const int technique) { playingTechnique = technique; }
        int getPlayingTechnique() const { return playingTechnique; }

        void setStringMaterial(const string material) { stringMaterial = material; }
        string getStringMaterial() const { return stringMaterial; }
       
       // определены методы для ввода и вывода значений уникальных свойств струнных инструментов
        void showInfo() {
            cout << "Playing Technique: " << playingTechnique << endl;
            cout << "String Material: " << stringMaterial << endl;
        }
    };

    UniqueStringsInfo uniqueInfo;

public:
    StringsInst() : numberOfStrings(0) {}

    void setNumberOfStrings(const int num) { numberOfStrings = num; }
    int getNumberOfStrings() const { return numberOfStrings; }

    void ElementPlay() override {
        cout << "Playing " << InstrumentName << " with " << numberOfStrings << " strings." << endl;
    }

    void setPlayingTechnique(const int technique) { uniqueInfo.setPlayingTechnique(technique); }
    int getPlayingTechnique() const { return uniqueInfo.getPlayingTechnique(); }

    void setStringMaterial(const string material) { uniqueInfo.setStringMaterial(material); }
    string getStringMaterial() const { return uniqueInfo.getStringMaterial(); }

    void showInfo() override {
        cout << "String Instrument Type: " << InstrumentName << endl;
        cout << "Number of Strings: " << numberOfStrings << endl;
        uniqueInfo.showInfo();
        MusicalInstrument::showInfo();
    }
};

class KeyboardsInst : public MusicalInstrument {
protected:
    string instrumentType;
    int numberOfKeys;


    class UniqueKeyboardInfo {
    private:
        bool hasPedal;
    public:
         //определен метод для ввода и вывода значения наличия педали.
        UniqueKeyboardInfo() : hasPedal(false) {}

        void setHasPedal(const bool pedal) { hasPedal = pedal; }
        bool getHasPedal() const { return hasPedal; }

        void showInfo() {
            cout << "Has Pedal: " << (hasPedal ? "yes" : "no")
        }
    }
//создаются объекты классов 
//устанавливаются их свойства и вызываются методы для 
//воспроизведения и вывода информации об инструментах.

int main() {
// Creating an instance of the String Instrument class
StringsInst violin;
violin.setInstrumentName("Violin");
violin.setMaterial("Wood");
violin.setMadeIn("Italy");
violin.setSettingCost(100.0);
violin.setNumberOfStrings(4);
violin.setPlayingTechnique(1);
violin.setStringMaterial("Steel");

// Creating an instance of the Keyboard Instrument class
KeyboardsInst piano;
piano.setInstrumentName("Piano");
piano.setMaterial("Wood and Metal");
piano.setMadeIn("Germany");
piano.setSettingCost(1000.0);
piano.setNumberOfKeys(88);
piano.setHasPedal(true);

// Performing the actions
violin.ElementPlay();
cout << endl;
piano.ElementPlay();
cout << endl;

// Showing the information of both instruments
violin.showInfo();
cout << endl;
piano.showInfo();

}





