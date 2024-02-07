# Msolve.hpp
This is a header file for command line calculator
## ex1.cpp
operation can be solve Addition(+), Subtraction(-), Multiplication(astric symbol), Division(/), Modulus(%), Power of(^).
allowed string: NUM, '(', ')', '+', '-', '/', '%', '^',and astric symbol
format for use Msolve() function:
### format1:
    cout << Msolve("-1-2-3+4+3+5-08+78+54") << "\n";
### format2:
    int x0 = 78;
    cout << Msolve("-1-2-3+4+3+5-08+" + to_string(x0) + "+54") << "\n";
### format3:
    string x1 = to_string(x0);
    cout << Msolve("-1-2-3+4+3+5-08+" + x1 + "+54") << "\n";
### format4:
    cout << Msolve("(ab2+ d_ytc-r+2.0)", 1, 2, 3) << '\n';
    //ab2=1, d_ytc=2,r=3;
    cout<<Msolve("2*(x^5) - 3*(x^4) + 7*(x^3) + 4*(x^2) - 6*(x*y) + 5*(y^3) - 8*(y^2) + 9*y - 12",2,-3);
    //x=2,y=-3;
this format is my choice, use it.

## How to compile
open Msolve_3 folder and you can see two file one is Msolve.hpp (is a header file) and a ex1.cpp(main), And in ex1.cpp includes "Msolve.hpp".
to compile this program youneed to type:
    
    g++ -std=c++17 ex1.cpp -o abc
and run abc.exe in cmd, Only type

    abc
and press enter.

# In V3 extra options are added:
## you can use in build functions also like
            #include <iostream>
            #include <iomanip>
            #include "Msolve3.hpp"
            int main()
            {
    
                std::cout << std::fixed << std::setprecision(10);
                std::cout << Msolve("(x+w+(w+(x-w+(x*fmin(x,w)))))",1,9) << '\n';

            }
            /*
            Trigonometric Functions:
            fsin(x): Sine of x.
            fcos(x): Cosine of x.
            ftan(x): Tangent of x.
            fasin(x): Arcsine of x.
            facos(x): Arccosine of x.
            fatan(x): Arctangent of x.

            Hyperbolic Functions:
            fsinh(x): Hyperbolic sine of x.
            fcosh(x): Hyperbolic cosine of x.
            ftanh(x): Hyperbolic tangent of x.
            fasinh(x): Inverse hyperbolic sine of x.
            facosh(x): Inverse hyperbolic cosine of x.
            fatanh(x): Inverse hyperbolic tangent of x.

            Exponential and Logarithmic Functions:
            fexp(x): Exponential function e^x.
            flog(x): Natural logarithm of x.
            flog10(x): Base-10 logarithm of x.
            flog2(x): Base-2 logarithm of x.
            fexp2(x): 2 raised to the power x.

            fsqrt(x): Square root of x.
            fcbrt(x): Cube root of x.

            Rounding and Remainder Functions:
            fceil(x): Round up to the nearest integer.
            floor(x): Round down to the nearest integer.
            fround(x): Round to the nearest integer.
            ftrunc(x): Truncate towards zero.

            fabs(x): Absolute value of x.
            fabs(x): Same as fabs(x).
            */

            
