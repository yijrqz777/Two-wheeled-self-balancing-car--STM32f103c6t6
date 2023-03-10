/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "icm_iic.h"
#include "icm.h"
#include "stdio.h"
#include "iic.h"
#include "oled.h"
#include "encoder.h"
#include "pid.h"
#include "moto.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
uint8_t xx=0;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */


//#ifdef __GNUC__
//#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
//#else
//#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
//#endif 
//PUTCHAR_PROTOTYPE
//{
//HAL_UART_Transmit(&huart1 , (uint8_t *)&ch, 1, 0xFFFF);
//return ch;
//}

int fputc(int ch, FILE *f)
{
HAL_UART_Transmit(&huart1 , (uint8_t *)&ch, 1, 0xFFFF);
return ch;
}

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
//????PB??????,AFIO????????

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
	PID_init();
	icm20602_init_simspi();
	gyroOffset_init();
		OLED_Init();
	OLED_Clear();
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
	__HAL_TIM_CLEAR_IT(&htim2,TIM_CHANNEL_3);
//	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,0);	
//	
//	
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
	__HAL_TIM_CLEAR_IT(&htim2,TIM_CHANNEL_4);
//	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,1000);	
	HAL_TIM_Base_Start(&htim2);
	
	
	/* USER CODE BEGIN 2 */
  HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
//	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_1|TIM_CHANNEL_2);
//	HAL_TIM_Base_Start_IT(&htim1);
//	HAL_TIM_Base_Start_IT(&htim2);
	
	
//	HAL_TIM_Base_Start(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		encoder();
		uint32_t enc1=0;
		
		enc1 = (uint32_t)(__HAL_TIM_GET_COUNTER(&htim1));//??????????????
		
				uint32_t enc2=0;
//		
		enc2 = (uint32_t)(__HAL_TIM_GET_COUNTER(&htim3));//??????????????
//		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,0);
//		HAL_Delay(10);
//		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,1);
//		HAL_Delay(10);               // Device header
		printf("%d,%d,3\n",enc1,enc2);
//		printf("%d,%f,%f,%f,%d,%f\n",enc1,pid[1].fOutput,pid[2].fOutput,pid[3].fOutput,icm_gyro_y,eulerAngle.pitch);
//		xx=1;
//		if(eulerAngle.pitch>10 | eulerAngle.pitch<-10)
//		{
//			xx=0;
//			moto_contorl(0,0);
//		}
		
//		OLED_ShowString(1,1,(unsigned char *)"YJRQZ",16);
//		
//		OLED_Refresh_Gram();

//		OLED_ShowChinese(32,0,2,16);  //??
//		OLED_ShowChinese(48,0,3,16);	//??
//		OLED_ShowChar(62,0,':',16,1);	//?? 
//		OLED_ShowChar(74,0,'Q',16,1); //Q
//		OLED_ShowChinese(86,0,0,16);	//??
//		OLED_ShowChinese(102,0,1,16);	//??
//		OLED_ShowString(45,40,(unsigned char *)"2022.6.1",16); //2022.6.1

//		OLED_Refresh_Gram();
		
//		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,1);
		
//		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,0);
//		printf("%d,%d,%d,%d,%d,%d\r\n",icm_acc_x,icm_acc_y,icm_acc_z,icm_gyro_x,icm_gyro_y,icm_gyro_z);
//		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
//		HAL_Delay(500);
//		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
//		HAL_Delay(500);
//		printf("1111");
//		printf("%.2f,%.2f,%.2f\n",eulerAngle.pitch,eulerAngle.roll,eulerAngle.yaw);
		//HAL_Delay(5);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
