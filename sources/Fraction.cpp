#include "Fraction.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel{

Fraction floatToFraction(const float &num)
{
    int denominator = 1, count = 0;
    while ((num * denominator != floor(num * denominator)) && count < 3)
    {
        denominator = denominator * 10;
        count++;
    }
    Fraction res(static_cast<int>(num * denominator), denominator);
    res.SimplfyFraction();
    return res;
}

// Constructors
Fraction::Fraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("Denominator cannot be 0");
    }
    if(numerator == 0){
        this->nume = 0;
        this->deno = 1;
        return;
    }
    int gcd = GetGcd(numerator, denominator);
    this->nume = numerator / gcd;
    this->deno = denominator / gcd;
    
}

Fraction::Fraction(float numerator)
{
    Fraction floatFrac = floatToFraction(numerator);
    nume = floatFrac.nume;
    deno = floatFrac.deno;
}

Fraction::Fraction() : nume(1), deno(1) {}

// Functions

int Fraction::GetGcd(int num1, int num2) const
{
    num1 = abs(num1);
    num2 = abs(num2);
    int gcd = 1;
    for (int i = 1; i <= num1 && i <= num2; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

int Fraction::GetLcm(int num1, int num2, int calculatedGcd = 0) const
{
    if (!calculatedGcd)
    {
        return (num1 * num2) / GetGcd(num1, num2);
    }
    return (num1 * num2) / calculatedGcd;
}

void Fraction::SimplfyFraction()
{
    int gcd = GetGcd(nume, deno);
    nume = nume / gcd;
    deno = deno / gcd;
}

int Fraction::getNumerator() const
{
    return nume;
}

void Fraction::setNumerator(int numerator)
{
    nume = numerator;
}

int Fraction::getDenominator() const
{
    return deno;
}

void Fraction::setDenominator(int denominator)
{
    deno = denominator;
}

// Math Operators
Fraction Fraction::operator=(const Fraction &other)
{
    nume = other.nume;
    deno = other.deno;
    this->SimplfyFraction();
    return *this;
}

Fraction Fraction::operator+(const Fraction &other) const
{
    int new_deno = GetLcm(other.deno, this->deno);
    int new_nume = this->nume * (new_deno / this->deno) + other.nume * (new_deno / other.deno);
    Fraction new_frac(new_nume, new_deno);
    new_frac.SimplfyFraction();
    return new_frac;
}

Fraction operator+(const float &num, const Fraction &frac)
{
    Fraction floatFrac = floatToFraction(num);
    return frac + floatFrac;
}

Fraction operator+(const Fraction &frac, const float &num)
{
    Fraction floatFrac = floatToFraction(num);
    return frac + floatFrac;
}

Fraction Fraction::operator-(const Fraction &other) const
{
    int new_deno = GetLcm(other.deno, this->deno);
    int new_nume = this->nume * (new_deno / this->deno) - other.nume * (new_deno / other.deno);
    Fraction new_frac(new_nume, new_deno);
    new_frac.SimplfyFraction();
    return new_frac;
}

Fraction operator-(const float &num, const Fraction &frac)
{
    Fraction floatFrac = floatToFraction(num);
    return floatFrac - frac;
}

Fraction operator-(const Fraction &frac, const float &num)
{
    Fraction floatFrac = floatToFraction(num);
    return frac - floatFrac;
}

Fraction Fraction::operator*(const Fraction &other) const
{
    int new_nume = this->nume * other.nume;
    int new_deno = this->deno * other.deno;
    Fraction new_frac(new_nume, new_deno);
    new_frac.SimplfyFraction();
    return new_frac;
}

Fraction operator*(const float &num, const Fraction &frac)
{
    Fraction floatFrac = floatToFraction(num);
    return frac * floatFrac;
}

Fraction operator*(const Fraction &frac, const float &num)
{
    Fraction floatFrac = floatToFraction(num);
    return frac * floatFrac;
}

Fraction Fraction::operator/(const Fraction &other) const
{
    if(other.nume == 0){
        throw runtime_error("Cannot divide by 0");
    }
    int new_nume = this->nume * other.deno;
    int new_deno = this->deno * other.nume;
    Fraction new_frac(new_nume, new_deno);
    new_frac.SimplfyFraction();
    return new_frac;
}

Fraction operator/(const float &num, const Fraction &frac)
{
    Fraction floatFrac = floatToFraction(num);
    return floatFrac / frac;
}

Fraction operator/(const Fraction &frac, const float &num)
{
    Fraction floatFrac = floatToFraction(num);
    return frac / floatFrac;
}

// Boolean Operators

bool Fraction::operator==(const Fraction &other) const
{
    float this_frac = (float)this->nume / (float)this->deno;
    this_frac = roundf(this_frac * 1000) / 1000;
    float other_frac = (float)other.nume / (float)other.deno;
    other_frac = roundf(other_frac * 1000) / 1000;

    return this_frac == other_frac;
}

bool operator==(const float &num, const Fraction &frac){
    if(frac.getNumerator() == 0 && num == 0){
        return true;
    }
    Fraction floatFrac = floatToFraction(num);
    return floatFrac == frac;
}

bool operator==(const Fraction &frac, const float &num){
    if(frac.getNumerator() == 0 && num == 0){
        return true;
    }
    Fraction floatFrac = floatToFraction(num);
    return floatFrac == frac;
}

bool Fraction::operator>(const Fraction &other) const
{
    float this_frac = (float)this->nume / (float)this->deno;
    float other_frac = (float)other.nume / (float)other.deno;
    return this_frac > other_frac;
}

bool operator>(const float &num, const Fraction &frac){
    Fraction floatFrac = floatToFraction(num);
    return floatFrac > frac;
}

bool operator>(const Fraction &frac, const float &num){
    Fraction floatFrac = floatToFraction(num);
    return frac > floatFrac;
}

bool Fraction::operator<(const Fraction &other) const
{
    float this_frac = (float)this->nume / (float)this->deno;
    float other_frac = (float)other.nume / (float)other.deno;
    return this_frac < other_frac;
}

bool operator<(const float &num, const Fraction &frac){
    Fraction floatFrac = floatToFraction(num);
    return floatFrac < frac;
}

bool operator<(const Fraction &frac, const float &num){
    Fraction floatFrac = floatToFraction(num);
    return frac < floatFrac;
}

bool Fraction::operator>=(const Fraction &other) const
{
    float this_frac = (float)this->nume / (float)this->deno;
    float other_frac = (float)other.nume / (float)other.deno;
    return this_frac >= other_frac;
}

bool operator>=(const float &num, const Fraction &frac){
    Fraction floatFrac = floatToFraction(num);
    return floatFrac >= frac;
}

bool operator>=(const Fraction &frac, const float &num){
    Fraction floatFrac = floatToFraction(num);
    return frac >= floatFrac;
}

bool Fraction::operator<=(const Fraction &other) const
{
    float this_frac = (float)this->nume / (float)this->deno;
    float other_frac = (float)other.nume / (float)other.deno;
    return this_frac <= other_frac;
}

bool operator<=(const float &num, const Fraction &frac){
    Fraction floatFrac = floatToFraction(num);
    return floatFrac <= frac;
}

bool operator<=(const Fraction &frac, const float &num){
    Fraction floatFrac = floatToFraction(num);
    return frac <= floatFrac;
}

Fraction Fraction::operator++(int increment_flag){
    Fraction old_frac(this->nume, this->deno);
    this->nume += this->deno;
    return old_frac;
}

Fraction Fraction::operator--(int decrement_flag){
    Fraction old_frac(this->nume, this->deno);
    this->nume-= this->deno;
    return old_frac;
}

Fraction& Fraction::operator++(){
    this->nume += this->deno;
    return *this;
}

Fraction& Fraction::operator--(){
    this->nume-= this->deno;
    return *this;
}

// Stream Operators

ostream& operator<<(ostream& ost, const Fraction& frac){
    if (frac.deno < 0 && frac.nume > 0){
        ost << frac.getNumerator()*-1 << "/" << abs(frac.getDenominator());
        return ost;
    }
    if (frac.deno < 0 && frac.nume < 0){
        ost << abs(frac.getNumerator()) << "/" << abs(frac.getDenominator());
        return ost;
    }
    ost << frac.getNumerator() << "/" << frac.getDenominator();
    return ost;
}

istream& operator>>(istream& ist, Fraction& frac){
    int nume = 0, deno = 0;
    ist >> nume >> deno;
    if (deno == 0){
        throw runtime_error("Denominator cannot be zero or empty");
    }
    frac.setNumerator(nume);
    frac.setDenominator(deno);
    return ist;
}
};