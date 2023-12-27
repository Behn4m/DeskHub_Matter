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
    
    typedef void (*MainTaskPtr)(void *pvParameter);

    class BaseProcess
    {            
        public:                        
            BaseProcess(uint32_t taskDelay_){taskDelay = taskDelay_;};
            ~BaseProcess(){};            
            bool TaskInit(  BaseInterfaceHandler *BIHandler,                             
                            const char * const pcName,
                            uint16_t usStackDepth,
                            void *pvParameters,
                            UBaseType_t uxPriority,
                            TaskHandle_t *pxCreatedTask);
        
            static MainTaskPtr MainTask;
        private:                  
            static uint32_t taskDelay;
            static BaseInterfaceHandler *InterfaceHandler;   

            virtual bool checkEssencialParam();   
            //virtual void JustRunOneTime();
            //virtual void Run4Ever();
            //static void MainTask(void *pvParameter);
    };                
}

#endif //BASE_PROCESS_H
