/*  -----------------------------------------------------------------------------
    MIT License

    Copyright (c) 2021 Elcereza

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
    -----------------------------------------------------------------------------
*/

#include "Arduino.h"
#include "Elcereza_pH014.h"

pH014::pH014(int _pin, int _rADC = 1024, int _average = 100){
    pinMode(_pin, 0);
    pin = _pin;
    average = _average;
    
    if(_rADC < 25)
        rADC = pow(2, _rADC);
    else
        rADC = _rADC;

    c = rADC / 1024;
}

double pH014::getpH(){
    double ph = pow(analogRead(pin), -1) / (0.000264542 / c);
    if(ph >= 14)
        return 14;
    else if(ph <= 0)
        return 0;
    else 
        return ph;
}
