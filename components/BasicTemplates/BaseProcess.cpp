#include <stdio.h>
#include <string.h>
#include "BaseProcess.h"
#include <esp_log.h>
#include <esp_system.h>

namespace DoneMatter {
    
bool BaseProcess::TaskInit(  
    BaseInterfaceHandler *BIHandler,                             
    const char * const pcName,
    uint16_t usStackDepth,
    void *pvParameters,
    UBaseType_t uxPriority,
    TaskHandle_t *pxCreatedTask)
{
    char buff[50];    
    memset(buff, 0x0, sizeof(buff));
    sprintf(buff,"%s_Task",pcName);    

    InterfaceHandler = BIHandler;

    if(checkEssencialParam())
    {        
        xTaskCreate(MainTask, buff, usStackDepth, pvParameters, uxPriority, pxCreatedTask);
        ESP_LOGI(pcName, "%s app initiated successfully", pcName);
    }
    else
    {
        ESP_LOGE(pcName, "%sIntefaceHandler is is missing some pointers, can not run the app", pcName);
        return false;
    }
    return true;    
}

// void BaseProcess::MainTask(void *pvParameter)
// {
//     //JustRunOneTime();

//     while (1)
//     {
//         //Run4Ever();

//         vTaskDelay(pdMS_TO_TICKS(taskDelay));
//     }
// }
}

