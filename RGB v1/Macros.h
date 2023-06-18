
#ifndef Macros_H_
#define Macros_H_

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Check if a certain bit in any register is set or cleared */
#define GET_BIT(REG,BIT) (( REG & (1<<BIT))>>BIT)

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))


#endif  /* Macros_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Macros.h
 *********************************************************************************************************************/
