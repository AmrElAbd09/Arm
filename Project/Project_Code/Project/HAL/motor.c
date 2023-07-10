#include "motor.h"

/*********************************func_implementation********************************************************/

/**DESCRIPTION:-
  this function initializes the Motor pins
  **/
en_MOTOR_Status_t MOTOR_Init(void) {
    Port_Init(&Port_ConfigType);
    
    return MOTOR_OK;
}

/**************************************************************************************************************/
/**DESCRIPTION:-
    this function is used to drive the motor to move in the +VE direction which will lead the car to move FWD
**/
en_MOTOR_Status_t MOTOR_Forward(void) {
    /* this is used to provide the ground to the +ve pin of */
    Dio_WriteChannel(DIO_CONFIG_MOTOR1_D1A_CHANNEL_ID, DIO_LEVEL_LOW);
    Dio_WriteChannel(DIO_CONFIG_MOTOR1_D1B_CHANNEL_ID, DIO_LEVEL_HIGH);
    
    /* this is used to provide voltage to the -ve pin of the motor */
    Dio_WriteChannel(DIO_CONFIG_MOTOR2_D2A_CHANNEL_ID, DIO_LEVEL_LOW);
    Dio_WriteChannel(DIO_CONFIG_MOTOR2_D2B_CHANNEL_ID, DIO_LEVEL_HIGH);
    
    return MOTOR_OK;
}

/**************************************************************************************************************/
/**DESCRIPTION:-
this function is used to drive the motor to move in the -VE direction which will lead the car to move BWD
**/
en_MOTOR_Status_t MOTOR_Backward(void) {
    
    /* this is used to provide voltage to the -ve pin of the motor */
    Dio_WriteChannel(DIO_CONFIG_MOTOR1_D1A_CHANNEL_ID, DIO_LEVEL_HIGH);
    Dio_WriteChannel(DIO_CONFIG_MOTOR1_D1B_CHANNEL_ID, DIO_LEVEL_LOW);
    
    /* this is used to provide the ground to the +ve pin of */
    Dio_WriteChannel(DIO_CONFIG_MOTOR2_D2A_CHANNEL_ID, DIO_LEVEL_HIGH);
    Dio_WriteChannel(DIO_CONFIG_MOTOR2_D2B_CHANNEL_ID, DIO_LEVEL_LOW);
    
    return MOTOR_OK;
}

/***********************************************************************************************************************/
/**DESCRIPTION:-
this function is used to stop the 4 wheels by stopping the 4 motors*/
en_MOTOR_Status_t MOTOR_RotateRight(void) {
    
    /* this is used to provide voltage to the -ve pin of the motor */
    Dio_WriteChannel(DIO_CONFIG_MOTOR1_D1A_CHANNEL_ID, DIO_LEVEL_HIGH);
    Dio_WriteChannel(DIO_CONFIG_MOTOR1_D1B_CHANNEL_ID, DIO_LEVEL_LOW);
    
    /* this is used to provide the ground to the +ve pin of */
    Dio_WriteChannel(DIO_CONFIG_MOTOR2_D2A_CHANNEL_ID, DIO_LEVEL_LOW);
    Dio_WriteChannel(DIO_CONFIG_MOTOR2_D2B_CHANNEL_ID, DIO_LEVEL_HIGH);
    
    return MOTOR_OK;
}

/***********************************************************************************************************************/
/**DESCRIPTION:-
this function is used to drive the right wheels to move BWD, and the left wheels to move FWD,
which will lead to rotation of the car */
en_MOTOR_Status_t MOTOR_RotateLeft(void) {
    
    /* this is used to provide the ground to the +ve pin of */
    Dio_WriteChannel(DIO_CONFIG_MOTOR1_D1A_CHANNEL_ID, DIO_LEVEL_LOW);
    Dio_WriteChannel(DIO_CONFIG_MOTOR1_D1B_CHANNEL_ID, DIO_LEVEL_HIGH);
    
    /* this is used to provide voltage to the -ve pin of the motor */
    Dio_WriteChannel(DIO_CONFIG_MOTOR2_D2A_CHANNEL_ID, DIO_LEVEL_HIGH);
    Dio_WriteChannel(DIO_CONFIG_MOTOR2_D2B_CHANNEL_ID, DIO_LEVEL_LOW);
    
    return MOTOR_OK;
}

/***********************************************************************************************************************/
/**DESCRIPTION:-
this function is used to drive the right wheels to move FWD, and the left wheels to move BWD,
which will lead to rotation of the car */
en_MOTOR_Status_t MOTOR_Stop(void) {
    
    Dio_WriteChannel(DIO_CONFIG_MOTOR1_D1A_CHANNEL_ID, DIO_LEVEL_LOW);
    Dio_WriteChannel(DIO_CONFIG_MOTOR1_D1B_CHANNEL_ID, DIO_LEVEL_LOW);
    
    Dio_WriteChannel(DIO_CONFIG_MOTOR2_D2A_CHANNEL_ID, DIO_LEVEL_LOW);
    Dio_WriteChannel(DIO_CONFIG_MOTOR2_D2B_CHANNEL_ID, DIO_LEVEL_LOW);  
    
    return MOTOR_OK;
}
