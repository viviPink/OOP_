
#ifndef NASLEDMODUL_H
#define NASLEDMODUL_H

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
    MusicalInstrument();
    virtual ~MusicalInstrument();

    virtual void ElementPlay() = 0;
    // стоимость ремонта инструмента
    void setSettingCost(const double &cost);
    double getSettingCost() const;
    // материал из которого сделан инструмент
    void setMadeIn(const string &Country);
    string getMadeIn() const;
    // страна в которой изобретен инструмент
    void setMaterial(const string &material);
    string getMaterial() const;
    // название инструмента
    void setInstrumentName(const string &name);
    string getInstrumentName() const;
    // виртуальная функция
    // вывод информации о инструменте
    // (название, материал, производство, стоимость ремонта)
    virtual void showInfo();
};

// производный класс Струнные инструменты
class StringsInst {

protected:
    int numberOfStrings;

      class UniqueStringsInfo {
private:
   
    int playingTechnique;
    string stringMaterial;

public:
    // Конструкторы и деструктор
    StringsInst();
    StringsInst(const string &name, const string &mat, const string &made, const double cost, const int strings, const int technique, const string &strMat);
    ~StringsInst();

    // Сеттеры и геттеры
    void setNumberOfStrings(const int strings);
    void setPlayingTechnique(const int technique);
    void setStringMaterial(const string &strMat);


    int getNumberOfStrings() const;
    int getPlayingTechnique() const;
    string getStringMaterial() const;

};

class KeyboardsInst {
private:
    int numberOfKeys;
    bool hasPedal;

public:
    // Конструкторы и деструктор
    KeyboardsInst();
    KeyboardsInst(const string &name, const string &mat, const string &made, const double cost, const int keys, const bool pedal);
    ~KeyboardsInst();

    // Сеттеры и геттеры
    void setNumberOfKeys(const int keys);
    void setHasPedal(const bool pedal);

    int getNumberOfKeys() const;
    bool getHasPedal() const;
};

#endif