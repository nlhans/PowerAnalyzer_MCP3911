#ifndef TRITON_STDDEFS_H
#define TRITON_STDDEFS_H

#include <stdio.h>
#define CLOCK_CPU 40000000
#define CLOCK_PERIPHERAL CLOCK_CPU/2

#define GPIO_Write_PA LATA
#define GPIO_Write_PB LATB
#define GPIO_Read_PA PORTA
#define GPIO_Read_PB PORTB
#define GPIO_Tris_PA TRISA
#define GPIO_Tris_PB TRISB
#define GPIO_Direction_Input 1
#define GPIO_Direction_Output 0
#define GPIO_Direction_INPUT 1
#define GPIO_Direction_OUTPUT 0
#define GPIO_Direction_IN 1
#define GPIO_Direction_OUT 0
#define INPUT 1
#define OUTPUT 0

/**** DATA TYPES ****/
// temporarely
#define UI32_t volatile unsigned long
#define UI16_t volatile unsigned int
#define UI08_t volatile unsigned char

#define SI32_t volatile  long
#define SI16_t volatile signed int
#define SI08_t volatile signed char
#define PTR16(addr) ((UI16_t*)addr)
#ifndef NULL
    #define NULL 0
#endif
#ifndef null
    #define null 0
#endif

typedef void *          Pointer_t;
typedef char *          String_t;
typedef void            (*HandlerPtr_t) (void);
typedef void            (*HandlerPtr_argb_t) (UI08_t arg);
typedef void            (*HandlerPtr_ptr_t) (UI08_t* arg);
typedef void            (*HandlerPtr_argb_ptr_t) (UI08_t arg1, UI08_t* arg2);
typedef void            (*HandlerPtr_argb_argb_t) (UI08_t arg1, UI08_t arg2);
typedef void            (*CaptureHandlerPtr_t) (UI08_t id, UI32_t elTime);

/**** General definition of IO pin reference */
typedef struct IOPin_s
{
    unsigned port:3;         // A to D
    unsigned pin:6;          // Pin 0 to 15
    unsigned invert:1;       // 1 invert
} IOPin_t;

typedef struct IOPort_s
{
	UI16_t* TRIS;
	UI16_t* PORT;
	UI16_t* LAT;
	UI16_t* ODC;
} IOPort_t;

/***** General purpose Fast-GPIO writes (not flexible)*****/
//TODO: add set/clr function
#ifdef GPIO_SetClr
	// This microcontroller uses set/clr registers
	#define FGPIO_Write(port, pin, value) if(value) { \
		GPIO_Write1_##port |=  (1U << pin); \
	} else { \
		GPIO_Write0_##port }=  (1U << pin); \
	}
	#define FGPIO_Write1(port, pin) GPIO_Write1_##port |=  (1U << pin)
	#define FGPIO_Write0(port, pin) GPIO_Write0_##port |=  (1U << pin)
#else
	#define FGPIO_Write(port, pin, value) if(value) { \
		GPIO_Write_##port |=  (1U << pin); \
	} else { \
		GPIO_Write_##port &=  ~(1U << pin); \
	}
	#define FGPIO_Write1(port, pin) GPIO_Write_##port |=  (1U << pin)
	#define FGPIO_Write0(port, pin) GPIO_Write_##port &= ~(1U << pin)
#endif

#define FGPIO_Read(port, pin) ((GPIO_Write_##port>>pin) & 0x1)
#define FGPIO_Direction(port, pin, dir) if(GPIO_Direction_##dir) \
{ \
    GPIO_Tris_##port  |= 1<<pin; \
}else{ \
    GPIO_Tris_##port &= ~(1<<pin); \
}

/**** Look-up general purpose writes ****/
#define PIN(port, pin, invert) {IO_##port, pin, invert}

// For use with structs (i.e. stored port number in memory)
#define SGPIO_Direction(port, pin, dir) \
    if(dir) {   \
        *(IOPorts[port].TRIS) |= 1<<pin;    \
    } else {    \
        *(IOPorts[port].TRIS) &= ~(1<<pin); \
    }
#define SGPIO_Write(port, pin, value) \
    if(value) {\
    SGPIO_Write1(port, pin);\
    }else{\
    SGPIO_Write0(port,pin));\
    }
#define SGPIO_Read(port, pin) ((*(IOPorts[port].PORT)>>pin)&0x1)
#define SGPIO_Write1(port, pin) *(IOPorts[port].LAT) |=  (1U << pin);
#define SGPIO_Write0(port, pin) *(IOPorts[port].LAT)  &= ~(1U << pin);


// For normal code (usage of macros)
#define GPIO_Direction(port, pin, dir) \
    if(dir) {   \
        *(IOPorts[IO_##port].TRIS) |= 1<<pin;    \
    } else {    \
        *(IOPorts[IO_##port].TRIS) &= ~(1<<pin); \
    }

#define GPIO_Write(port, pin, value) \
    if(value) {\
    GPIO_Write1(port, pin);\
    }else{\
    GPIO_Write0(port,pin));\
    }
#define GPIO_Read(port, pin) ((*(IOPorts[IO_##port].PORT)>>pin)&0x1)
#define GPIO_Write1(port, pin) *(IOPorts[IO_##port].LAT) |=  (1U << pin);
#define GPIO_Write0(port, pin) *(IOPorts[IO_##port].LAT)  &= ~(1U << pin);


#endif
