#ifndef BASE_PROCESS_H
#define BASE_PROCESS_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

namespace DoneMatter {
                
    class BaseInterfaceHandler
    {    
        public:
            BaseInterfaceHandler(){};
            ~BaseInterfaceHandler(){};

            QueueHandle_t SharedBufQueue;
            SemaphoreHandle_t SharedSemaphore;            
        private:        
    };    

    class BaseProcess
    {            
        public:                        
            BaseProcess(){};
            ~BaseProcess(){};            
            bool TaskInit(  BaseInterfaceHandler *BIHandler,                             
                            const char * const pcName,
                            uint16_t usStackDepth,
                            void *pvParameters,
                            UBaseType_t uxPriority,
                            TaskHandle_t *pxCreatedTask,
                            uint32_t taskDelay_Ms);

            static uint32_t taskDelayMs;
            typedef void (*MainTaskPtr)(void *pvParameter);              
            static MainTaskPtr MainTask;
            virtual bool checkEssencialParam()=0;               
            static BaseInterfaceHandler *InterfaceHandler;   
    };                
}

#endif //BASE_PROCESS_H
