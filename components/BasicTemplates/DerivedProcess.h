#ifndef DERIVED_PROCESS_H
#define DERIVED_PROCESS_H

#include "BaseProcess.h"

namespace DoneMatter {

    class DeivedInterfaceHandler: public BaseInterfaceHandler
    {    
        public:
            DeivedInterfaceHandler(){};
            ~DeivedInterfaceHandler(){};
            QueueHandle_t localBufQueue;
            SemaphoreHandle_t localSemaphore;          
    };    

    class DerivedProcess : public BaseProcess
    {
        private:
            static void Derived_MainTask(void *pvParameters);    

        public:
            DerivedProcess(uint32_t td) {MainTask = Derived_MainTask;};
            ~DerivedProcess(){};
        
    };           
}
#endif //DERIVED_PROCESS_H