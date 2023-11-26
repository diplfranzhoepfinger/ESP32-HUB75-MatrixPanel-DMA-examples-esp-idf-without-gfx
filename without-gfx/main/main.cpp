#include "ESP32-HUB75-MatrixPanel-I2S-DMA.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


MatrixPanel_I2S_DMA *dma_display = nullptr;

extern "C" void app_main() {
  HUB75_I2S_CFG mxconfig(/* width = */ 64, /* height = */ 32, /* chain = */ 1);

  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin();
  dma_display->setBrightness8(80);
  dma_display->clearScreen();


  vTaskDelay(1000 / portTICK_PERIOD_MS);
  dma_display->fillRect(20, 20, 30, 25, dma_display->color444(0, 15, 0));
}
