#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
#include "adc.h"
#include "oled.h"
#include "usart2.h"
#include "8266wifi.h"

int main(void)
{

    
    HAL_Init();                                             /* 初始化HAL库 */
    sys_stm32_clock_init(RCC_PLL_MUL9);                     /* 设置时钟, 72Mhz */
    delay_init(72);                                         /* 延时初始化 */
    usart_init(115200);                                     /* 初始化串口 */
    led_init();                                             /* 初始化LED */
	// OLED_Init();
    usart2_init(115200);

    if(esp8266_Init(mode_1_TCP_Client,wifi_mode_Station)==esp8266_OK)
    {
        printf("\r\nesp8266 模式 %d 初始化完成!\r\n",mode_1_TCP_Client);
    }
    else
    {
        printf("\r\nesp8266初始化失败\r\n");
        while(1)
        {
            LED0_TOGGLE();
            delay_ms(200);
        }
    }
    

    char rx_data[128];
    uint8_t ID=0;
    while (1)
    {
        if(esp8266wifi_rx_sta&0X8000)//esp收到的信息通过串口一打印
        {
            printf("\nGot Date!\n");
            ID = esp8266_receive_data(rx_data,esp8266wifi_rx_buf);
            if(ID)
            {                
                printf("ID :%d,收到的信息: %s\n",ID,rx_data);
            }
            else
            {
                printf("收到的信息: %s\n",rx_data);
            }
            esp8266wifi_rx_sta=0;
        }
        if(g_usart_rx_sta&0X8000)   //串口一收到的信息发送到esp  
        {           
            while ((USART_UX->SR & 0X40) == 0);     /* 等待上一个字符发送完成 */
            esp8266_send_data((char *)g_usart_rx_buf,ID);
            // printf("%s\n",g_usart_rx_buf);
            g_usart_rx_sta = 0;
        }
        

        LED0_TOGGLE();
        delay_ms(500);
    }
}
