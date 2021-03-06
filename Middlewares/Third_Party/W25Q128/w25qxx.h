#ifndef __W25QXX_H
#define __W25QXX_H			    

#include "stm32f4xx_hal.h"
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

//W25Xϵ��/Qϵ��оƬ�б�	   
#define W25Q80 	0XEF13 	
#define W25Q16 	0XEF14
#define W25Q32 	0XEF15
#define W25Q64 	0XEF16
#define W25Q128	0XEF17 

extern SPI_HandleTypeDef hspi2;

#define W25Q_SPI hspi2
#define	W25QXX_CS(SET)   		HAL_GPIO_WritePin(SPI_CS_GPIO_Port, SPI_CS_Pin, (GPIO_PinState)(SET))  		 //W25QXX��Ƭѡ�ź�

////////////////////////////////////////////////////////////////////////////////// 
//ָ���
#define W25X_WriteEnable		0x06 
#define W25X_WriteDisable		0x04 
#define W25X_ReadStatusReg	0x05 
#define W25X_WriteStatusReg	0x01 
#define W25X_ReadData			  0x03 
#define W25X_FastReadData		0x0B 
#define W25X_FastReadDual		0x3B 
#define W25X_PageProgram		0x02 
#define W25X_BlockErase			0xD8 
#define W25X_SectorErase		0x20 
#define W25X_ChipErase			0xC7 
#define W25X_PowerDown			0xB9 
#define W25X_ReleasePowerDown	0xAB 
#define W25X_DeviceID					0xAB 
#define W25X_ManufactDeviceID	0x90 
#define W25X_JedecDeviceID		0x9F 

void W25QXX_Init(void);
u16  W25QXX_ReadID(void);  	    		//��ȡFLASH ID
u8	 W25QXX_ReadSR(void);        		//��ȡ״̬�Ĵ��� 
void W25QXX_Write_SR(u8 sr);  			//д״̬�Ĵ���
void W25QXX_Write_Enable(void);  		//дʹ�� 
void W25QXX_Write_Disable(void);		//д����
void W25QXX_Write_NoCheck(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite);
void W25QXX_Read(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead);   //��ȡflash
void W25QXX_Write(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite);//д��flash
void W25QXX_Erase_Chip(void);    	  														//��Ƭ����
void W25QXX_Erase_Sector(u32 Dst_Addr);													//��������
void W25QXX_Wait_Busy(void);           													//�ȴ�����
void W25QXX_PowerDown(void);        														//�������ģʽ
void W25QXX_WAKEUP(void);																				//����
#endif
















