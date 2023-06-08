#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;
int main() {
    float val1;
    float val2;
    cout << "Enter a float value: ";
    cin >> val1;
    Fraction frac1(val1);
    cout << "Enter a float value: ";
    cin >> val2;
    Fraction frac2(val2);
    cout << "Fraction 1: " << frac1 << endl;
    cout << "Fraction 2: " << frac2 << endl;

    // Correct answers:
    float correctSum = val1 + val2;
    float correctDifference = val1 - val2;
    float correctProduct = val1 * val2;
    float correctQuotient = val1 / val2;
    bool correctIsEqual = val1 == val2;
    bool correctIsGreater = val1 > val2;
    bool correctIsLess = val1 < val2;
    bool correctIsGreaterOrEqual = val1 >= val2;
    bool correctIsLessOrEqual = val1 <= val2;

    
    // Perform arithmetic operations
    Fraction sum = frac1 + frac2;
    Fraction difference = frac1 - frac2;
    Fraction product = frac1 * frac2;
    Fraction quotient = frac1 / frac2;
    
    // Display the results
    cout << "Correct Sum: " << correctSum << endl;
    cout << "Sum: " << sum << endl;
    cout << "Correct Difference: " << correctDifference << endl;
    cout << "Difference: " << difference << endl;
    cout << "Correct Product: " << correctProduct << endl;
    cout << "Product: " << product << endl;
    cout << "Correct Quotient: " << correctQuotient << endl;
    cout << "Quotient: " << quotient << endl;
    
    // Compare fractions
    bool isEqual = frac1 == frac2;
    bool isGreater = frac1 > frac2;
    bool isLess = frac1 < frac2;
    bool isGreaterOrEqual = frac1 >= frac2;
    bool isLessOrEqual = frac1 <= frac2;
    
    // Display the comparison results
    puts("");
    cout << "Correct Fraction 1 == Fraction 2: " << correctIsEqual << endl;
    cout << "Fraction 1 == Fraction 2: " << isEqual << endl;
    cout << "Correct Fraction 1 > Fraction 2: " << correctIsGreater << endl;
    cout << "Fraction 1 > Fraction 2: " << isGreater << endl;
    cout << "Correct Fraction 1 < Fraction 2: " << correctIsLess << endl;
    cout << "Fraction 1 < Fraction 2: " << isLess << endl;
    cout << "Correct Fraction 1 >= Fraction 2: " << correctIsGreaterOrEqual << endl;
    cout << "Fraction 1 >= Fraction 2: " << isGreaterOrEqual << endl;
    cout << "Correct Fraction 1 <= Fraction 2: " << correctIsLessOrEqual << endl;
    cout << "Fraction 1 <= Fraction 2: " << isLessOrEqual << endl;
    
    // Increment and decrement fractions
    frac1++;  // Post-increment
    ++frac2;  // Pre-increment
    frac1--;  // Post-decrement
    --frac2;  // Pre-decrement
    
    // Display the updated fractions
    puts("");
    cout << "Fraction 1 and 2 should stay: " << val1 << " and " << val2 << endl;
    cout << "Updated Fraction 1: " << frac1 << endl;
    cout << "Updated Fraction 2: " << frac2 << endl;

    // Perform arithmetic operations with fractions and floats
    cout << "\nFraction objects with float values:" << endl;
    
    // Correct answers:
    float correctSum1 = val1 + 1.25;
    float correctSum2 = 2.5 + val2;
    float correctDifference1 = 1.5 - val1;
    float correctDifference2 = val2 - 0.25;
    float correctProduct1 = val1 * 1.5;
    float correctProduct2 = 2.5 * val2;
    float correctQuotient1 = 1.5 / val1;
    float correctQuotient2 = val2 / 0.5;

    // Perform arithmetic operations
    Fraction sum2 = 1.25 + frac1;
    Fraction sum3 = frac2 + 2.5;
    
    Fraction difference2 = 1.5 - frac1;
    Fraction difference3 = frac2 - 0.25;
    
    Fraction product2 = 1.5 * frac1;
    Fraction product3 = frac2 * 2.5;
    
    Fraction quotient2 = 1.5 / frac1;
    Fraction quotient3 = frac2 / 0.5;
    
    // Display the results

    cout << "Correct 1.25 + Fraction 1: " << correctSum1 << endl;
    cout << "1.25 + Fraction 1: " << sum2 << endl;
    cout << "Correct Fraction 2 + 2.5: " << correctSum2 << endl;
    cout << "Fraction 2 + 2.5: " << sum3 << endl;
    puts("");

    cout << "Correct 1.5 - Fraction 1: " << correctDifference1 << endl;
    cout << "1.5 - Fraction 1: " << difference2 << endl;
    cout << "Correct Fraction 2 - 0.25: " << correctDifference2 << endl;
    cout << "Fraction 2 - 0.25: " << difference3 << endl;
    puts("");
    
    cout << "Correct 1.5 * Fraction 1: " << correctProduct1 << endl;
    cout << "1.5 * Fraction 1: " << product2 << endl;
    cout << "Correct Fraction 2 * 2.5: " << correctProduct2 << endl;
    cout << "Fraction * 2.5: " << product3 << endl;
    puts("");

    cout << "Correct 1.5 / Fraction 1: " << correctQuotient1 << endl;
    cout << "1.5 / Fraction 1: " << quotient2 << endl;
    cout << "Correct Fraction 2 / 0.5: " << correctQuotient2 << endl;
    cout << "Fraction 2 / 0.5: " << quotient3 << endl;
    
    return 0;
}