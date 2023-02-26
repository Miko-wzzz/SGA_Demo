#ifndef __OCD_PS2_H_
#define __OCD_PS2_H_

#include "drv_hal_conf.h"

#define DI  Drv_GPIO_Read(&_tPS2->tGPIO[0])     //DI����

#define DO_H Drv_GPIO_Set(&_tPS2->tGPIO[1])     //����λ��
#define DO_L Drv_GPIO_Reset(&_tPS2->tGPIO[1])   //����λ��

#define CS_H Drv_GPIO_Set(&_tPS2->tGPIO[2])     //CS����
#define CS_L Drv_GPIO_Reset(&_tPS2->tGPIO[2])   //CS����

#define CLK_H Drv_GPIO_Set(&_tPS2->tGPIO[3])    //ʱ������
#define CLK_L Drv_GPIO_Reset(&_tPS2->tGPIO[3])  //ʱ������

/* ������Ӧ */
#define PSB_SELECT      1
#define PSB_L3          2
#define PSB_R3          3
#define PSB_START       4
#define PSB_PAD_UP      5
#define PSB_PAD_RIGHT   6
#define PSB_PAD_DOWN    7
#define PSB_PAD_LEFT    8
#define PSB_L2          9
#define PSB_R2          10
#define PSB_L1          11
#define PSB_R1          12
/* ��ɫ�ֱ� */
#define PSB_GREEN       13
#define PSB_RED         14
#define PSB_BLUE        15
#define PSB_PINK        16
/* ͼ�ηֱ� */
#define PSB_TRIANGLE    13
#define PSB_CIRCLE      14
#define PSB_CROSS       15
#define PSB_SQUARE      16


/* ҡ�˴洢λ�� */
#define PSS_RX 5                //��ҡ��X������
#define PSS_RY 6                //��ҡ��Y������
#define PSS_LX 7                //��ҡ��X������
#define PSS_LY 8                //��ҡ��Y������

#define DELAY_TIME  Drv_Delay_Us(5); 

typedef struct 
{
    tagGPIO_T tGPIO[4];     //����[0]DI/DAT [1]DO/CMD [2]CS [3]CLK˳��
}tagPS2_T;

uint16_t Handkey;	// ����ֵ��ȡ����ʱ�洢��
uint8_t Comd[2]={0x01,0x42};	//��ʼ�����������
uint8_t PS2Data[9]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; //���ݴ洢����
                    /*PS2Data[0]    �� 
                      PS2Data[1]    0x73 ���ģʽ 0x41 ���ģʽ
                      PS2Data[2]    0x5A ��������Ԥ��
                      PS2Data[3]    ��8λ����״̬ 0����
                      PS2Data[4]    ��8λ����״̬ 0����
                      PS2Data[5]    PSS_RX
                      PS2Data[6]    PSS_RY
                      PS2Data[7]    PSS_LX
                      PS2Data[8]    PSS_LY
                    */
uint16_t MASK[]={
    PSB_SELECT,
    PSB_L3,
    PSB_R3 ,
    PSB_START,
    PSB_PAD_UP,
    PSB_PAD_RIGHT,
    PSB_PAD_DOWN,
    PSB_PAD_LEFT,
    PSB_L2,
    PSB_R2,
    PSB_L1,
    PSB_R1 ,
    PSB_GREEN,
    PSB_RED,
    PSB_BLUE,
    PSB_PINK
};

void OCD_PS2_Init(tagPS2_T *_tPS2);
uint8_t OCD_PS2_RedLight(tagPS2_T *_tPS2);
uint8_t OCD_PS2_AnologData(uint8_t button);
void OCD_PS2_ReadData(tagPS2_T *_tPS2);
uint8_t OCD_PS2_DataKey(tagPS2_T *_tPS2);

#endif
