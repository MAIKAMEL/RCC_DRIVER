#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(ADDR,BIT_NUM)		(ADDR) |= (1<<(BIT_NUM))
#define CLR_BIT(ADDR,BIT_NUM)		(ADDR) &=(~(1<<BIT_NUM))
#define TOGGEL_BIT (ADDR,BIT_NUM)	(ADDR)^=((1<<BIT_NUM))
#define GET_BIT(ADDR,BIT_NUM)		((ADDR>>BIT_NUM)&1)
#endif
