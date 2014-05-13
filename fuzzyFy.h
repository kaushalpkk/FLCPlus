// ---------------------------------------------------------------------------------------------
/*  function:    getDegreeOfMem
    input:        crisp value (float), respective target trapezoid(structure pointer)
    output:        firestrength (float, trapezoid)
    functioning:calculates the degree of membership of a crisp value in a target trapezoid    */
fireStrength getDegreeOfMem(float inp, const struct myTrapezoid *mFunc) {
    //input value
    fireStrength degOfMem;
    degOfMem.fuzzMem = *mFunc;

    //rising edge
    if ((inp > mFunc->low) && (inp < mFunc->midLower))
        degOfMem.firePower = (inp - mFunc->low)/((mFunc->midLower) - (mFunc->low));
    //top of trapezoid
    else if ((inp >= mFunc->midLower) && (inp <= mFunc->midHigher))
        degOfMem.firePower = 1.0;
    //falling edge
    else if ((inp > mFunc->midHigher) && (inp < mFunc->high))
        degOfMem.firePower = (((mFunc->high) - inp)/((mFunc->high) - (mFunc->midHigher)));
    //no degree of membership
    else
        degOfMem.firePower = 0;
//    printf("inp: %.2f, DOM: %.2f\r\n",inp, degOfMem.firePower);
    return degOfMem;
}

// ---------------------------------------------------------------------------------------------
/*    function:    getMin
    input:        2 float values
    output:        float
    functioning:returns lowest of the input values    */
float getMin(float a, float b) {
    if (a < b)
        return a;
    else
        return b;
}

/*    function:    getMin
    input:        3 float values
    output:        float
    functioning:returns lowest of the input values    */
float getMin(float a, float b, float c) {
    if ((a < b)&&(a < c))
        return a;
    if ((b < a)&&(b < c))
        return b;
    else
        return c;
}

float getMax(float a, float b) {
    if (a > b)
        return a;
    else
        return b;
}

float getMax(float a, float b, float c) {
    if ((a > b) && (a > c))
        return a;
    else if ((b > a) && (b > c))
        return b;
    else
        return c;
}
