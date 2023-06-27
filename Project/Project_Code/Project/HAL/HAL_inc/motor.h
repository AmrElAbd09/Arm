#ifndef MOTOR_H_
#define MOTOR_H_

#include "Dio.h"
#include "Port.h"
#include "Dio_Cfg.h"


#define Motor_ChannelType Dio_ChannelType

/* Motor API status. */
typedef enum {
    MOTOR_OK = 0, MOTOR_NOT_OK = 1
}en_MOTOR_Status_t;

en_MOTOR_Status_t MOTOR_Init(void);
en_MOTOR_Status_t MOTOR_Forward(void);
en_MOTOR_Status_t MOTOR_Backward(void);
en_MOTOR_Status_t MOTOR_RotateRight(void);
en_MOTOR_Status_t MOTOR_RotateLeft(void);
en_MOTOR_Status_t MOTOR_Stop(void);

#endif /* MOTOR_H_ */
