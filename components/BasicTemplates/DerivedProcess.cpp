#include <stdio.h>
#include <string.h>
#include "BaseProcess.h"
#include <esp_log.h>
#include <esp_system.h>

namespace DoneMatter {

void DerivedProcess::checkEssencialParam()
{
    // if (InterfaceHandler.SharedBufQueue != NULL &&
    //     InterfaceHandler.SharedSemaphore != NULL &&
    //     InterfaceHandler.localBufQueue != NULL &&
    //     InterfaceHandler.localSemaphore != NULL)        
    // {
    //     return true
    // }
    // else
    //     return false;
    return true;
}

void DerivedProcess::Derived_MainTask(void *pvParameters)
{
    ESP_LOGI("MainTask","Derived_MainTask1Time");

    while (true)
    {
        vTaskDelay(pdMS_TO_TICKS(taskDelay));
        ESP_LOGI("MainTask","Derived_MainTask4ever");
    }    
}
}
