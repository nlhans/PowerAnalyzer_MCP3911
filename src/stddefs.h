#ifndef STDDEFS_H
#define STDDEFS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

#include <stdio.h>
#include <string.h>

#define strConcat(a,b) a##b

typedef unsigned char UI08_t;
typedef unsigned int UI16_t;
typedef unsigned long UI32_t;

typedef char SI08_t;
typedef int SI16_t;
typedef long SI32_t;

typedef unsigned char bool_t;

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef NULL
#define NULL 0
#endif

#ifdef	__cplusplus
}
#endif

#endif