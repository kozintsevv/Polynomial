#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
    vector<double> coeffs1 = { 4,5,-1,7,0,3};
    vector<double> coeffs2 = { 4,0,-1,3, };
    double oneNumber = 15;


    //1. vytvoreni polynomu z pole.
    cout << "1. vytvoreni polynomu z pole." << endl;
    Polynomial poly1(coeffs1);
    poly1.Print();
    cout << endl;

    //2. vytvoreni z jednoho cisla
    cout << "2. vytvoreni z jednoho cisla" << endl;
    Polynomial polyy(oneNumber);
    polyy.Print();
    cout << endl;

    //4. stupen
    cout << "4. stupen" << endl;
    cout << poly1.Degree() << endl;
    cout << polyy.Degree() << endl;
    cout << endl;

    //5. hodnota v bode
    cout << "5. hodnota v bode" << endl;
    cout << poly1.Substitution(5) << endl;
    cout << polyy.Substitution(2)<<endl;
    cout << endl;

    //6. soucet dvou
    cout << "6. soucet dvou" << endl;
    Polynomial polyS(coeffs2);
    polyS.Print();
    poly1.Print();
    Polynomial polyyS = poly1 + polyS;
    polyyS.Print();
    cout << endl;

    //7. rozdil
    cout << "7. rozdil" << endl;
    polyS.Print();
    poly1.Print();
    Polynomial polySubstr = polyS - poly1;
    polySubstr.Print();
    cout << endl;

    //8. nasobeni
    cout << "8. nasobeni" << endl;
    polyS.Print();
    poly1.Print();
    Polynomial polyM = polyS * poly1;
    polyM.Print();
    cout << endl;

    //9. derivace
    cout << "8. derivate" << endl;
    poly1.Print();
    Polynomial poly2 = poly1.Derivative();
    poly2.Print();
    Polynomial poly3 = poly2.Derivative();
    poly3.Derivative();
    poly3.Print();
    Polynomial poly4 = poly3.Derivative();
    poly4.Print();
    Polynomial poly5 = poly4.Derivative();
    poly5.Print();
    Polynomial poly6 = poly5.Derivative();
    poly6.Print();
    Polynomial poly7 = poly6.Derivative();
    poly7.Print();
    cout << endl;

    //10. primitivni funkci
    cout << "10. primitivni funkci" << endl;
    poly1.Print();
    Polynomial polyPrim = poly1.Primitive();
    polyPrim.Print();
    
}