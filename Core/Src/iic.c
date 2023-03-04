///*********************************************************************************************************************
// * COPYRIGHT NOTICE
// * Copyright (c) 2018,��ɿƼ�
// * All rights reserved.
// * ��������QQȺ��179029047
// *
// * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
// * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
// *
// * @file       		ģ��IIC
// * @company	   		�ɶ���ɿƼ����޹�˾
// * @author     		��ɿƼ�(QQ3184284598)
// * @version    		�鿴common.h��VERSION�궨��
// * @Software 		IAR 7.8 or MDK 5.24a
// * @Target core		LPC54606J512BD100
// * @Taobao   		https://seekfree.taobao.com/
// * @date       		2018-05-24
// * @note		
//					���߶��壺
//					------------------------------------ 
//						SCL                 �鿴SEEKFREE_IIC�ļ��ڵ�SEEKFREE_SCL�궨��
//						SDA                 �鿴SEEKFREE_IIC�ļ��ڵ�SEEKFREE_SDA�궨��
//					------------------------------------ 
// ********************************************************************************************************************/


//#include "main.h"
//#include "iic.h"
//#include "stm32f1xx_hal.h"


//#define SDA   			ICM20602_SDA_GPIO_Port->IDR & ICM20602_SDA_Pin
//#define SDA0()          HAL_GPIO_WritePin (ICM20602_SDA_GPIO_Port,ICM20602_SDA_Pin,(GPIO_PinState)0)		//IO������͵�ƽ
//#define SDA1()          HAL_GPIO_WritePin (ICM20602_SDA_GPIO_Port,ICM20602_SDA_Pin,(GPIO_PinState)1)		//IO������ߵ�ƽ  
//#define SCL0()          HAL_GPIO_WritePin (ICM20602_SCL_GPIO_Port,ICM20602_SCL_Pin,(GPIO_PinState)0)		//IO������͵�ƽ
//#define SCL1()          HAL_GPIO_WritePin (ICM20602_SCL_GPIO_Port,ICM20602_SCL_Pin,(GPIO_PinState)1)		//IO������ߵ�ƽ
//#define DIR_OUT()		;//����Ҫ
//#define DIR_IN()		;//����Ҫ

////�ڲ����ݶ���
//uint8_t IIC_ad_main; //�����ӵ�ַ	    
//uint8_t IIC_ad_sub;  //�����ӵ�ַ	   
//uint8_t *IIC_buf;    //����|�������ݻ�����	    
//uint8_t IIC_num;     //����|�������ݸ���	     

//#define ack 1      //��Ӧ��
//#define no_ack 0   //��Ӧ��	 



////-------------------------------------------------------------------------------------------------------------------
////  @brief      ģ��IIC��ʱ
////  @return     void						
////  @since      v1.0
////  Sample usage:				���IICͨѶʧ�ܿ��Գ�������j��ֵ
////-------------------------------------------------------------------------------------------------------------------
//void simiic_delay(void)
//{
//	
//    uint16_t j=30;   //ʹ��С�������ͷʱ������ʱ��Ҫ����Ϊ500����
//	while(j--);
//}


////�ڲ�ʹ�ã��û��������
//void simiic_start(void)
//{
//	SDA1();
//	SCL1();
//	simiic_delay();
//	SDA0();
//	simiic_delay();
//	SCL0();
//}

////�ڲ�ʹ�ã��û��������
//void simiic_stop(void)
//{
//	SDA0();
//	SCL0();
//	simiic_delay();
//	SCL1();
//	simiic_delay();
//	SDA1();
//	simiic_delay();
//}

////��Ӧ��(����ack:SDA=0��no_ack:SDA=0)
////�ڲ�ʹ�ã��û��������
//void simiic_sendack(unsigned char ack_dat)
//{
//    SCL0();
//	simiic_delay();
//	if(ack_dat) SDA0();
//    else    	SDA1();

//    SCL1();
//    simiic_delay();
//    SCL0();
//    simiic_delay();
//}


//static int sccb_waitack(void)
//{
//    SCL0();
//	DIR_IN();
//	simiic_delay();
//	
//	SCL1();
//    simiic_delay();
//	
//    if(SDA)           //Ӧ��Ϊ�ߵ�ƽ���쳣��ͨ��ʧ��
//    {
//        DIR_OUT();
//        SCL0();
//        return 0;
//    }
//    DIR_OUT();
//    SCL0();
//	simiic_delay();
//    return 1;
//}

////�ֽڷ��ͳ���
////����c(����������Ҳ���ǵ�ַ)���������մ�Ӧ��
////�����Ǵ�Ӧ��λ
////�ڲ�ʹ�ã��û��������
//void send_ch(uint8_t c)
//{
//	uint8_t i = 8;
//    while(i--)
//    {
//        if(c & 0x80)	SDA1();//SDA �������
//        else			SDA0();
//        c <<= 1;
//        simiic_delay();
//        SCL1();                //SCL ���ߣ��ɼ��ź�
//        simiic_delay();
//        SCL0();                //SCL ʱ��������
//    }
//	sccb_waitack();
//}

////�ֽڽ��ճ���
////�����������������ݣ��˳���Ӧ���|��Ӧ����|ʹ��
////�ڲ�ʹ�ã��û��������
//uint8_t read_ch(uint8_t ack_x)
//{
//    uint8_t i;
//    uint8_t c;
//    c=0;
//    SCL0();
//    simiic_delay();
//    SDA1();             
//    DIR_IN();           //��������Ϊ���뷽ʽ
//    for(i=0;i<8;i++)
//    {
//        simiic_delay();
//        SCL0();         //��ʱ����Ϊ�ͣ�׼����������λ
//        simiic_delay();
//        SCL1();         //��ʱ����Ϊ�ߣ�ʹ��������������Ч
//        simiic_delay();
//        c<<=1;
//        if(SDA) 
//        {
//            c+=1;   //������λ�������յ����ݴ�c
//        }
//    }
//    DIR_OUT();
//	SCL0();
//	simiic_delay();
//	simiic_sendack(ack_x);
//	
//    return c;
//}

////-------------------------------------------------------------------------------------------------------------------
////  @brief      ģ��IICд���ݵ��豸�Ĵ�������
////  @param      dev_add			�豸��ַ(����λ��ַ)
////  @param      reg				�Ĵ�����ַ
////  @param      dat				д�������
////  @return     void						
////  @since      v1.0
////  Sample usage:				
////-------------------------------------------------------------------------------------------------------------------
//void simiic_write_reg(uint8_t dev_add, uint8_t reg, uint8_t dat)
//{
//	simiic_start();
//    send_ch( (dev_add<<1) | 0x00);   //����������ַ��дλ
//	send_ch( reg );   				 //���ʹӻ��Ĵ�����ַ
//	send_ch( dat );   				 //������Ҫд�������
//	simiic_stop();
//}


////-------------------------------------------------------------------------------------------------------------------
////  @brief      ģ��IIC���豸�Ĵ�����ȡ����
////  @param      dev_add			�豸��ַ(����λ��ַ)
////  @param      reg				�Ĵ�����ַ
////  @param      type			ѡ��ͨ�ŷ�ʽ��IIC  ���� SCCB
////  @return     uint8_t			���ؼĴ���������			
////  @since      v1.0
////  Sample usage:				
////-------------------------------------------------------------------------------------------------------------------
//uint8_t simiic_read_reg(uint8_t dev_add, uint8_t reg, IIC_type type)
//{
//	uint8_t dat;
//	simiic_start();
//    send_ch( (dev_add<<1) | 0x00);  //����������ַ��дλ
//	send_ch( reg );   				//���ʹӻ��Ĵ�����ַ
//	if(type == SCCB)simiic_stop();
//	
//	simiic_start();
//	send_ch( (dev_add<<1) | 0x01);  //����������ַ�Ӷ�λ
//	dat = read_ch(no_ack);   				//��ȡ����
//	simiic_stop();
//	
//	return dat;
//}

////-------------------------------------------------------------------------------------------------------------------
////  @brief      ģ��IIC��ȡ���ֽ�����
////  @param      dev_add			�豸��ַ(����λ��ַ)
////  @param      reg				�Ĵ�����ַ
////  @param      dat_add			���ݱ���ĵ�ַָ��
////  @param      num				��ȡ�ֽ�����
////  @param      type			ѡ��ͨ�ŷ�ʽ��IIC  ���� SCCB
////  @return     uint8_t			���ؼĴ���������			
////  @since      v1.0
////  Sample usage:				
////-------------------------------------------------------------------------------------------------------------------
//void simiic_read_regs(uint8_t dev_add, uint8_t reg, uint8_t *dat_add, uint8_t num, IIC_type type)
//{
//	simiic_start();
//    send_ch( (dev_add<<1) | 0x00);  //����������ַ��дλ
//	send_ch( reg );   				//���ʹӻ��Ĵ�����ַ
//	if(type == SCCB)simiic_stop();
//	
//	simiic_start();
//	send_ch( (dev_add<<1) | 0x01);  //����������ַ�Ӷ�λ
//    while(--num)
//    {
//        *dat_add = read_ch(ack); //��ȡ����
//        dat_add++;
//    }
//    *dat_add = read_ch(no_ack); //��ȡ����
//	simiic_stop();
//}



