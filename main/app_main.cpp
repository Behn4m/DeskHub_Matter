#include <nvs_flash.h>
#include "MatterInterface.h"
#include "BaseProcess.h"
#include "DerivedProcess.h"

DoneMatter::BaseInterfaceHandler bIh;
DoneMatter::DeivedInterfaceHandler DerivedbIh1;
DoneMatter::DeivedInterfaceHandler DerivedbIh2;

QueueHandle_t MainBufQueue;
SemaphoreHandle_t MainSemaphore = NULL;
void MatterAttributeUpdateCBMain(callback_type_t type, 
                uint16_t endpoint_id, uint32_t cluster_id,
                uint32_t attribute_id, esp_matter_attr_val_t *val, 
                void *priv_data);
MatterInterfaceHandler_t MatterInterfaceHandler;

extern "C" void app_main()
{    
    nvs_flash_init();

    // MatterInterfaceHandler.SharedBufQueue = &MainBufQueue;
    // MatterInterfaceHandler.SharedSemaphore = &MainSemaphore;
    // MatterInterfaceHandler.MatterAttributeUpdateCB = MatterAttributeUpdateCBMain;
    // Matter_TaskInit(&MatterInterfaceHandler);        

    DoneMatter::DerivedProcess dProcess1;
    dProcess1.TaskInit(
        &DerivedbIh1,
        "2ndProcess",
        2500,
        (void*) "2ndProcess",
        5,
        NULL,
        1000);//ms          

    DoneMatter::DerivedProcess dProcess2;
    dProcess2.TaskInit(
        &DerivedbIh2,
        "3ndProcess",
        2500,
        (void*) "3ndProcess",
        1,
        NULL,
        1000);//ms          

    vTaskDelay(5000/portTICK_PERIOD_MS);
    unsigned int numberOfTasks = uxTaskGetNumberOfTasks();
    printf("Number of tasks: %u\n", numberOfTasks);
    printf("CONFIG_FREERTOS_HZ =%d\n",CONFIG_FREERTOS_HZ);
}

void MatterAttributeUpdateCBMain(
                callback_type_t type, 
                uint16_t endpoint_id, uint32_t cluster_id,
                uint32_t attribute_id, esp_matter_attr_val_t *val, 
                void *priv_data)
{
    printf("callback_type_t: %u\n", type);
    printf("endpoint_id: %u\n", endpoint_id);
    printf("cluster_id: %lu\n", cluster_id);
    printf("attribute_id: %lu\n", attribute_id);
    printf("val: %p\n", val);
    printf("priv_data: %p\n", priv_data);
}