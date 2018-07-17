//#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

#include<stddef.h> //consists wchar_t size_t ptrdiff_t
#include<uchar.h> // consists cha16_t char32_t
#include<stdint.h> // consists integer types with specifiedbit width
#include<float.h>

int main(){
    printf("\n");

    printf("INT_MAX from limits : %d\n",INT_MAX);
    printf("CHAR_MAX from limits : %d\n",CHAR_MAX);
    printf("UINT_MAX from limits : %d\n",UINT_MAX);

    printf("INT_MIN from limits : %d\n",INT_MIN);
    printf("CHAR_MIN from limits : %d\n\n",CHAR_MIN);

    _Bool isTrue = true;//stored in terms of 1 or 0 for true and false respectively
    printf("\nType of _Bool from stdbool : %d\n",isTrue);
    bool isFalse = false;
    printf("Or just bool : %d\n",isFalse);

    int a ;
    short b ;
    long c;
    long long d;
    signed char e;

    unsigned int f;
    unsigned short g;
    unsigned long h;
    unsigned long long i;
    unsigned char j;

    printf("\nsize of int : %d\nsize of short : %d\n",sizeof(int),sizeof(short));
    printf("size of long : %d\nsize of long long : %d\n",sizeof(long),sizeof(long long));
    printf("size of signed char : %d\n\nsize of unsigned int : %d\n",sizeof(signed char),sizeof(unsigned int));
    printf("size of unsigned short : %d\nsize of unsigned long : %d\n",sizeof(unsigned short), sizeof(unsigned long));
    printf("size of unsigned long long : %d\nsize of unsigned char : %d",sizeof(unsigned long long),sizeof(unsigned char));

    printf("\n\nsize of wchar_t from stddef : %d\n",sizeof(wchar_t));
    printf("size of size_t from stddef : %d\n",sizeof(size_t));
    printf("size of ptrdiff_t from stddef : %d\n",sizeof(ptrdiff_t));

    printf("\nsize of char16_t from uchar : %d\n",sizeof(char16_t));
    printf("size of char32_t from uchar : %d\n",sizeof(char32_t));
    printf("size of wchar_t from stddef : %d\n",sizeof(wchar_t));

    printf("size of int8_t from stdint : %d\n",sizeof(int8_t));
    printf("INT8_MAX from stdint : %d\n",INT8_MAX);
    printf("size of int16_t from stdint : %d\n",sizeof(int16_t));
    printf("INT16_MAX from stdint : %d\n", INT16_MAX);
    printf("size of int32_t from stdint :%d\n",sizeof(int32_t));
    printf("INT32_MAX from stdint : %d\n",INT32_MAX);
    printf("size of int64_t from stdint : %d\n",sizeof(int64_t));
    printf("INT64MAX from stdint : %lld\n",INT64_MAX);

    printf("size of uint8_t from stdint : %d\n",sizeof(uint8_t));
    printf("size of uint16_t from stdint : %d\n",sizeof(uint16_t));
    printf("size of uint32_t from stdint :%d\n",sizeof(uint32_t));
    printf("size of uint64_t from stdint : %d\n",sizeof(uint64_t));
    printf("\n\nDecimal of A : %d\n",'A');
    printf("decimal of A += 2 : %d",'A'+2);
    printf("\nfloat -- single precision\ndouble -- double precision\nlong -- extended precision\n");
    printf("\n");
    printf("\\x61 : \x61\n");
    printf("\nFLT_MIN, FLT_MAX and FLT_DIG from float.h : \n%E\n%E\n%d\n",FLT_MIN,FLT_MAX,FLT_DIG);
    printf("\nDBL_MIN, DBL_MAX, DBL_DIG from float : \n%E\n%E\n%d\n",DBL_MIN,DBL_MAX,DBL_DIG);
    printf("\nLDBL_MIN, LDBL_MAX, LDBL_DIG from float : \n%LE\n%LE\n%d\n",LDBL_MIN,LDBL_MAX,LDBL_DIG);
    return 0;
}
