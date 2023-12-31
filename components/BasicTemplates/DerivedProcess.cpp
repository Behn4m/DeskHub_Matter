#include <stdio.h>
#include <string.h>
#include <esp_log.h>
#include <esp_system.h>

#include "DerivedProcess.h"

namespace DoneMatter {

bool DerivedProcess::checkEssencialParam()
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

    char buff[50];    
    memset(buff, 0x0, sizeof(buff));
    sprintf(buff,(char*) pvParameters);    

    ESP_LOGI(buff,"%s1Time", buff);

    while (true)
    {
        vTaskDelay(pdMS_TO_TICKS(taskDelayMs));
        ESP_LOGI(buff,"%s4ever", buff);
    }    
}
}
