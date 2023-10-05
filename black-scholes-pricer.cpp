#define _USE_MATH_DEFINES
 
#include <cmath>
#include <iostream>
#include<string>
using namespace std;

double askUser (string phrase){
    double userInput;
    cout << phrase;
    cin >> userInput;
    return userInput;
}

double normalRepartition(double x){
    return (1.0 + erf(x / sqrt(2.0))) / 2.0;
}

int main (int argc, char** argv){

    double price;
    double S;
    double K;
    double r;
    double t;
    double sigma;
    double d1;
    double d2;
    int callOrPut;

    S = askUser("Prix spot sous-jacent : ");
    K = askUser("Prix exercice de l'action : ");
    r = askUser("taux sans risque en % : ");
    t = askUser("Temps jusqu'a la fin de l'option en année : ");
    sigma = askUser("Volatilité du sous-jacent : ");

    r = r/100;
    sigma = sigma/100;
    
    d1 = (1/(sigma/t))*(log(S/K)+(r+(pow(sigma,2)/2))*t);
    d2 = d1 - sigma*sqrt(t);
    
    price = S*normalRepartition(d1)-K*exp(-r*t)*normalRepartition(d2);
    cout << "Prix de l'option : " << price ;

    price = -S*normalRepartition(-d1)+K*exp(-r*t)*normalRepartition(-d2);
    cout << "Prix de l'option : " << price ;
    return 1;
}