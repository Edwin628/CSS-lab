/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */




/* 
 *   lsbZero - set 0 to the least significant bit of x 
 *   Example: lsbZero(0x87654321) = 0x87654320
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 1
 */

int lsbZero(int x) {
	//因为左移时低位会补0，所以左移右移后能保证最低位一定为0
	x=x>>1;
	x=x<<1;
  return x;
}

int byteNot(int x, int n) {
	x=x^(1<<n);
  return x;
}
/* 
 * byteNot - bit-inversion to byte n from word x  
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByteNot(0x12345678,1) = 0x1234A978
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
/*
int byteNot(int x, int n) {
	//通过1的异或可以保证0变为1和1变为0
	int m;
	n=n<<3;
	m=0xff<<n;
	x=x^m;
  return x;
}
*/
int byteXor(int x, int y, int n) {
	n=n<<3;
	x=(x>>n)&0xff;
	y=(y>>n)&0xff;
	
  return !(!(x^y));
}

/* 
 *   byteXor - compare the nth byte of x and y, if it is same, return 0, if not, return 1

 *   example: byteXor(0x12345678, 0x87654321, 1) = 1

 *			  byteXor(0x12345678, 0x87344321, 2) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2 
 */

/*
int byteXor(int x, int y, int n) {
	//首先取到比较位置，然后通过两者的异或来实现比较，两个!实现将结果限制在
	//0与1之间
	int m;
	int val;
	n=n<<3;
	m=0xff<<n;
	y=y&m;
	x=x&m; 
	y=y>>n;
	x=x>>n;
	val=!(!(x^y)); 
  return val;
}
*/
int logicalAnd(int x, int y) {
  return !(!x)&!(!y);
}
/* 
 *   logicalAnd - x && y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
/*
int logicalAnd(int x, int y) {
	//判断x与y是否有一个为0即可，通过!将其转化
	int m=!(!x)&!(!y);
  return m;
}
*/
/* 
 *   logicalOr - x || y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalOr(int x, int y) {
	//比较x与y各个位之间的或，如果结果不为0
	//则说明其中必定有非零数
	int val=!(!(x|y));
	//int val=!(!x)|!(!y);
  return val;
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
/*
int rotateLeft(int x, int n) {
	int temp=~0;
	int nneg=~n+1;
	int xhigh = x>>(32+nneg);
	//temp=~temp;//this is crucial
	temp = temp<<n;
	xhigh = xhigh&(~temp);
	//x = x&temp;
	x = x<<n;
	x = x|xhigh;
  return x;
}
*/
int rotateLeft(int x, int n) {
	//通过mlow取待转移的高位地址，存至mhigh中
	//然后将其通过移位至低位，再与原来的数转移后合并即可。
	int m=0;
	int mlow,nneg,mhigh;
	m=~m;
	mlow=~(m<<n);
	nneg=~n+1;
	mhigh=mlow<<(32+nneg);
	mhigh=mhigh&x;
	mhigh=mhigh>>(32+nneg);
	mhigh=mhigh&mlow;
	x=x<<n;
	x=x|mhigh;
  return x;
}
/*
int parityCheck(int x) {
	int temp=x>>16;
	x=temp^x;
	temp=x>>8;
	x=temp^x;
	temp=x>>4;
	x=temp^x;
	temp=x>>2;
	x=temp^x;
	temp=x>>1;
	x=temp^x;
	x=x&1;
  return x;
}
/*
 * parityCheck - returns 1 if x contains an odd number of 1's
 *   Examples: parityCheck(5) = 0, parityCheck(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */

int parityCheck(int x) {
	//将高位与低位反复比较，即可达到两个1就消为0的效果
	int m=x;
	m=m>>16;
	m=m^x;
	x=m;
	m=m>>8;
	m=m^x;
	x=m;
	m=m>>4;
	m=m^x;
	x=m;
	m=m>>2;
	m=m^x;
	x=m;
	m=m>>1;
	m=m^x;
	m=m&1;	//can I use this way?
  return m;
}


int mul2OK(int x) {
	//int temp=~0;
	int xs,x2s;
	//temp=~(temp<<1);
	xs=(x>>31)&1;
	x2s=(x>>30)&1;
  return 1^(xs^x2s); //we cant use !,and ~ worked incorrectly too
}
/*
 * mul2OK - Determine if can compute 2*x without overflow
 *   Examples: mul2OK(0x30000000) = 1
 *             mul2OK(0x40000000) = 0
 *         
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2
 */
/*
int mul2OK(int x) {
	//m为x*2的结果，溢出的条件是m与x的符号位不同
	int m; 
	m= x<<1;
	m=m>>31;
	x=x>>31;
  return 0x1^(0x1&(m^x));
}

*/
int mult3div2(int x) {
	int m=x+(x<<1);//dont forget the column
	m=m+(!(!(m>>31)));
	m=m>>1;
  return m;
}
/*
 * mult3div2 - multiplies by 3/2 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/2),
 *   including overflow behavior.
 *   Examples: mult3div2(11) = 16
 *             mult3div2(-9) = -13
 *             mult3div2(1073741824) = -536870912(overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
/*
int mult3div2(int x) {
	//因为向零取整，根据m的符号位来进行加一操作
	int m;
	m=(x<<1)+x;
	m=m+!(!(m>>31));
	m=m>>1;
  return m;
}
*/
int subOK(int x, int y) {
	int m=~y+1;
	int ms=((~y)>>31)&1;//use ~y to replace m crucial
	int xs=(x>>31)&1;
	int sums;
	m=x+m;
	sums=(m>>31)&1;
  return !(!(ms^xs)&(sums^ms));
}

/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
/*
	int m,yneg,dec;	
	yneg=~y+1;
	m=x+yneg;
	x=!(!(x>>31));
	y=!(!(y>>31));
	m=!(!(m>>31));
	dec=!(!(x^y) & ((x^m)|(y^m))); 
*/
/*
int subOK(int x, int y) {
	//x与y符号位不同并且x与（x-y）符号位不同时则溢出
	int m,dec,yneg;	
	yneg=~y+1;
	m=x+yneg;
	x=!(!(x>>31));
	y=!(!(y>>31));
	m=!(!(m>>31));
	dec=(x^y) & (x^m); //This one work incorrectly in 64bit Linux

  return !dec;
}
*/
int absVal(int x) {
	//int s=!(!(x>>31));
	int s=x>>31;	
	x=(x&(~s))+((~x+1)&s); //column is crucial
  return x;
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
/*
int absVal(int x) {
	//通过截取最高位来判断正负的操作
	int m=x>>31;
	int xabs = ((~m)&x)+(m&(~x+1));//pay attention to the brackets
  return xabs;  //test this one in 32 bit machine
}

*/
unsigned float_abs(unsigned uf) {
	unsigned abv=uf&0x7fffffff;
	if(abv>(0x7f800000)) return uf;
	else return abv;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
/*
unsigned float_abs(unsigned uf) {
	//最高位为符号位全部置零，超出范围则返回原值
	unsigned m=~(1<<31);
	m=m&uf;
	if(m>0x7f800000) return uf;
	else
  return m;
}
*/
int float_f2i(unsigned uf) {
	unsigned s = uf>>31;
	//must use int not unsigned, because there is comapre 
	int jiema = ((uf&(0x7f800000))>>23)-127;
	int weima = (uf&(0x007fffff))+(0x00800000);
	if(jiema<0) return 0;
	if (jiema>31) return 0x80000000;//we should consider the range of int
	//30and31 both pass, standard is 31
	if(s==0){
		if(jiema<=23)
		return weima>>(23-jiema);
		else return weima<<(jiema-23);	
	}
	else{
		if(jiema<=23)
		return (~(weima>>(23-jiema))+1);
		else return (~(weima<<(jiema-23))+1);	
	}
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
/*
int float_f2i(unsigned uf) {
	//当阶码超出范围或者小于127则直接判定返回值
	//然后因为表示时已经默认为右移了23位，所以通过比较150来
	//判断真正的位置。
	unsigned sf=(0x80000000&uf)>>31;
	unsigned e=(uf&0x7f800000)>>23;
	unsigned f=(uf&0x007fffff);
	int m;
	f=f^0x00800000;
	if(e<127)return 0;
	else if(e>158)return 0x80000000;
	else if(e>150){
		if(sf){
			m=~(f<<(e-150))+1;
		}
		else m=f<<(e-150);
	}
	else if(e<=150){
		if(sf){
			m=~(f>>(150-e))+1;
		}
		else m=f>>(150-e);
	}

  return m;
}
*/
