#ifndef STRING_H
#define STRING_H


#include <cctype>
#include <cstring>
#include <iostream>

#include "Szerializal.h"

/**
A String oszt�ly.
A 'pData'-ban vannak a karakterek (a lez�r� null�val egy�tt), 'len' a hossza.
A hosszba nem sz�m�t bele a lez�r� nulla.
 */
class String : public Szerializal
{
private:
    char* pData;        ///< pointer az adatra
    size_t len;         ///< hossz lez�r� nulla n�lk�l

public:

    /// Sztring hossz�t adja vissza.
    /// @return sztring t�nyleges hossza (lez�r� nulla n�lk�l).
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pointer a t�rolt, vagy azzal azonos tartalm� null�val lez�rt sztring-re.
    const char* c_str() const { return pData == nullptr ? "" : pData; }


    /// Parameter nelkuli konstruktor:
    String() 
        : pData(nullptr)
        , len(0)
    {}

    ///Egyparameteres konstruktor, egyben konverzios konstruktor
    ///Egyetlen karakterbol csinal String-et
    String(char c)
        : pData(new char[2])
        , len(1)
    {
        pData[0] = c;
        pData[1] = '\0';
    }

    /// Egyparam�teres konstruktor
    /// C-sztringbol csinal String-et
    String(char const* str)
        : pData(new char[strlen(str) + 1])
        , len(strlen(str))
    {
        strcpy(pData, str);
    }


    //RULE OF THREE

    ///Masolo konstruktor
    String(String const& rhs)
        : pData(nullptr)
    {
        *this = rhs;
    }

    ///Ertekado operator
    String const& operator=(String const& rhs) {
        if (this == &rhs)
            return rhs;

        delete[] pData;
        len = rhs.len;
        pData = new char[len + 1];
        strcpy(pData, rhs.pData);
        return *this;
    }

    ///Destruktor
    ~String() {
        delete[] pData;
    }

    //RULE OF THREE

    ///+ operator: String-hez String-et ad
    String operator+(String const& rhs) const {
        String res;
        res.len = size() + rhs.size();
        res.pData = new char[res.size() + 1];
        strcpy(res.pData, pData);
        strcat(res.pData, rhs.pData);
        return res;
    }


    ///+ operator: Stringhez jobbrol ad hozza karaktert
    String operator+(char rhs_c) const { return *this + String(rhs_c); }

    ///== operator
    bool operator==(String const& rhs) {
        return (strcmp(pData, rhs.pData) == 0);
    }


    bool contains (const String keresendo){
        
    }


    void kiir(std::ostream& os) const {
        os.write(pData, len);
        os << '\t';
    }

    void beolvas(std::istream& is) {
        *this = "";
        char c;
        is >> c;
        while (c != '\t')
        {
            *this = *this + c;
            is >> c;
        }

    }
        

}; 


#endif