/*
 * BitMath.h
 *
 * Created: 3/18/2023 8:55:32 PM
 *  Author: user
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(Reg,BitNo) (Reg |= (1<<BitNo))
#define ClearBit(Reg,BitNo) (Reg &=~ (1<<BitNo))
#define ToggleBit(Reg,BitNo) (Reg ^= (1<<BitNo))
#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)
//#define GetBit(Reg,BitNo) ((Reg & (1<<BitNo))>>BitNo)

#endif /* BITMATH_H_ */