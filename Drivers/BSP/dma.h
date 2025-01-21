#ifndef __DMA_H
#define	__DMA_H

#include "sys.h"


extern DMA_HandleTypeDef  g_dma_handle;     /* DMA句柄 */
void dma_init(DMA_Channel_TypeDef* DMAx_CHx);

#endif
