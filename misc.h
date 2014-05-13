/*
name:                   misc.h
date:                   4-june-2011
header description:     small and insignificant sub routines to interface quadrature encoder
compiler-library:       the mbed library
compatability:          n/a
hardware dependency:    n/a

indentation:            <nmbed default indentation - 4 spaces>
resources:              C reference manual*/

//gets a bit position by shifting 1
#define _BV(x) (1 << x)

// sbi sets a particular bit and cbi clears the bit (target byte-word, bit position)
#define sbi(y,x); y|=_BV(x)
#define cbi(y,x); y&=~_BV(x)

//  function:   saveState
//  input:      input byte
//  output:     target byte
//  functioning: save the byte reducing memory size
char saveState(char nowS){
    return nowS;
}

//  function:   getBit
//  input:      bit position of target byte, target byte
//  output:     char output 
//  functioning:returns the bit 
char getBit(char bitP, char targB) {
    targB = targB & _BV(bitP);
    if (targB == 0)
        return 0;
    else
        return 1;
}   
