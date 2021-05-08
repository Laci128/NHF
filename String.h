#define _CRT_SECURE_NO_WARNINGS
#ifndef STRING_H
#define STRING_H


#include <cctype>
#include <cstring>
#include <iostream>

#include "Szerializal.h"



///A String osztaly.
///A 'pData'-ban vannak a karakterek (a lezaro nullaval egyutt), 'len' a hossza.
///A hosszba nem szamit bele a lezaro nulla.
class String : public Szerializal
{
private:
    char* pData;        ///< pointer az adatra
    size_t len;         ///< hossz lezaro nulla nelkul

public:

    /// Sztring hosszat adja vissza.
    /// @return sztring tenyleges hossza (lezaro nulla nelkul).
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pointer a tarolt, vagy azzal azonos tartalma nullaval lezart sztring-re.
    const char* c_str() const { return pData == nullptr ? "" : pData; }


    /// Parameter nelkuli konstruktor
    /// 
    String() 
        : pData(nullptr)
        , len(0)
    {}

    /// Egyparameteres konstruktor, egyben konverzios konstruktor
    /// Egyetlen karakterbol csinal String-et
    String(char c)
        : pData(new char[2])
        , len(1)
    {
        pData[0] = c;
        pData[1] = '\0';
    }

    /// Egyparameteres konstruktor
    /// C-sztringbol csinal String-et
    String(char const* str)
        : pData(new char[strlen(str) + 1])
        , len(strlen(str))
    {
        strcpy(pData, str);
    }


    //RULE OF THREE

    /// Masolo konstruktor
    /// 
    String(String const& rhs)
        : pData(nullptr)
    {
        *this = rhs;
    }

    /// = operator:
    /// Ertekado operator
    String& operator=(String const& rhs) {
        if (this == &rhs)
            return *this;

        delete[] pData;
        len = rhs.len;
        pData = new char[len + 1];
        strcpy(pData, rhs.pData);
        return *this;
    }

    /// Destruktor
    /// 
    ~String() {
        delete[] pData;
    }

    //RULE OF THREE



    /// + operator:
    /// Stringhez Stringet ad
    /// @return atmeneti String, amiben az osszeadott Stringek vegeredmenye van
    String operator+(String const& rhs) const {
        String res;
        res.len = size() + rhs.size();
        res.pData = new char[res.size() + 1];
        strcpy(res.pData, pData);
        strcat(res.pData, rhs.pData);
        return res;
    }


    /// + operator:
    /// Stringhez jobbrol ad hozza karaktert
    String operator+(char rhs_c) const { return *this + String(rhs_c); }

    /// == operator:
    /// Ket Stringet hasonlit ossze
    bool operator==(String const& rhs) {
        return (strcmp(pData, rhs.pData) == 0);
    }

    /// A String streamre kiiro fuggvenye
    /// 
    void kiir(std::ostream& os) const {
        os.write(pData, len);
        os << ' ';
    }

    /// A String streamrol beolvaso fuggvenye
    /// 
    void beolvas(std::istream& is) {
        /**this = "";
        char c;
        is >> c;
        while (c != '\t')
        {
            *this = *this + c;
            is >> c;
        }*/
        *this = "";
        char c;
        is >> std::skipws >> c;
        *this = *this + c;
        while (true) {
            c = is.peek();
            if (c == EOF) {
                is >> c;
                break;
            }
            if (isspace(c))
                break;
            is >> std::noskipws >> c;
            *this = *this + c;
        }

    }
        

}; 


#endif