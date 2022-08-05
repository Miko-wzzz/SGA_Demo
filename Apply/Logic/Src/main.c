#include "main.h"
#include "drv_hal_conf.h"	/* �����ض��� */ 


#ifdef RTT_ENABLE
#include <rtthread.h>		/* RTOS�����޸���rtconfig.h��*/
#else
#include "task_sysinit.h"
#include "task_userinit.h"
#include "task_userdebug.h"
#endif

int main()
{
#ifdef	RTT_ENABLE
	rt_kprintf("RTT ����\r\n");
#else
	Task_Sys_Init();		/* ϵͳ��ʼ�������� */
	Task_UserInit();		/* �û������ʼ�� */
	
	Task_UserDebug();		/* �û��߼�ִ�� */
#endif
}
