#include <stdio.h>
#include <string.h>
#include "BaseProcess.h"
#include <esp_log.h>
#include <esp_system.h>

namespace DoneMatter {

BaseProcess::MainTaskPtr BaseProcess::MainTask = NULL;
uint32_t BaseProcess::taskDelayMs = 0;
BaseInterfaceHandler *BaseProcess::InterfaceHandler = NULL;   

bool BaseProcess::TaskInit(  
    BaseInterfaceHandler *BIHandler,                             
    const char * const pcName,
    uint16_t usStackDepth,
    void *pvParameters,
    UBaseType_t uxPriority,
    TaskHandle_t *pxCreatedTask,
    uint32_t taskDelay_Ms)
{
    char buff[50];    
    memset(buff, 0x0, sizeof(buff));
    sprintf(buff,"%s_Task",pcName);    

    InterfaceHandler = BIHandler;
    taskDelayMs = taskDelay_Ms;

    if(checkEssencialParam())
    {        
        xTaskCreate(MainTask, buff, usStackDepth, pvParameters, uxPriority, pxCreatedTask);
        ESP_LOGI(buff, "%s app initiated successfully", buff);
    }
    else
    {
        ESP_LOGE(buff, "%sIntefaceHandler is is missing some pointers, can not run the app", buff);
        return false;
    }
    return true;    
}
}

