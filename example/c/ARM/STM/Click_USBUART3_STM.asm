_systemInit:
;Click_USBUART3_STM.c,34 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_USBUART3_STM.c,36 :: 		mikrobus_uartInit( _MIKROBUS1, &_USBUART3_UART_CFG[0] );
MOVW	R0, #lo_addr(__USBUART3_UART_CFG+0)
MOVT	R0, #hi_addr(__USBUART3_UART_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_uartInit+0
;Click_USBUART3_STM.c,37 :: 		mikrobus_logInit( _MIKROBUS1, 9600 );
MOVW	R1, #9600
MOVS	R0, #0
BL	_mikrobus_logInit+0
;Click_USBUART3_STM.c,38 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_USBUART3_STM.c,39 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_USBUART3_STM.c,41 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_USBUART3_STM.c,43 :: 		usbuart3_uartDriverInit( (T_USBUART3_P)&_MIKROBUS1_GPIO, (T_USBUART3_P)&_MIKROBUS1_UART );
MOVW	R1, #lo_addr(__MIKROBUS1_UART+0)
MOVT	R1, #hi_addr(__MIKROBUS1_UART+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_usbuart3_uartDriverInit+0
;Click_USBUART3_STM.c,44 :: 		mikrobus_logWrite( "Initialized", _LOG_LINE );
MOVW	R0, #lo_addr(?lstr1_Click_USBUART3_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_USBUART3_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_USBUART3_STM.c,45 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_applicationInit2:
SUBS	R7, R7, #1
BNE	L_applicationInit2
NOP
NOP
NOP
;Click_USBUART3_STM.c,46 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_USBUART3_STM.c,48 :: 		void applicationTask()
SUB	SP, SP, #8
STR	LR, [SP, #0]
;Click_USBUART3_STM.c,55 :: 		rdyFlag = usbuart3_byteReady();
BL	_usbuart3_byteReady+0
;Click_USBUART3_STM.c,57 :: 		if (1 == rdyFlag)
CMP	R0, #1
IT	NE
BNE	L_applicationTask4
;Click_USBUART3_STM.c,59 :: 		tmp = usbuart3_readByte();
BL	_usbuart3_readByte+0
STRB	R0, [SP, #4]
;Click_USBUART3_STM.c,60 :: 		mikrobus_logWrite( &tmp, _LOG_BYTE );
ADD	R0, SP, #4
MOVS	R1, #0
BL	_mikrobus_logWrite+0
;Click_USBUART3_STM.c,61 :: 		}
L_applicationTask4:
;Click_USBUART3_STM.c,65 :: 		for (tmp = 0; tmp < 9; tmp++)
MOVS	R0, #0
STRB	R0, [SP, #4]
L_applicationTask5:
LDRB	R0, [SP, #4]
CMP	R0, #9
IT	CS
BCS	L_applicationTask6
;Click_USBUART3_STM.c,67 :: 		usbuart3_writeByte( MESSAGE_DATA[tmp] );
LDRB	R1, [SP, #4]
MOVW	R0, #lo_addr(_MESSAGE_DATA+0)
MOVT	R0, #hi_addr(_MESSAGE_DATA+0)
ADDS	R0, R0, R1
LDRB	R0, [R0, #0]
BL	_usbuart3_writeByte+0
;Click_USBUART3_STM.c,68 :: 		mikrobus_logWrite( "MESSAGE SENT", _LOG_LINE );
MOVW	R0, #lo_addr(?lstr2_Click_USBUART3_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_USBUART3_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_USBUART3_STM.c,65 :: 		for (tmp = 0; tmp < 9; tmp++)
LDRB	R0, [SP, #4]
ADDS	R0, R0, #1
STRB	R0, [SP, #4]
;Click_USBUART3_STM.c,69 :: 		}
IT	AL
BAL	L_applicationTask5
L_applicationTask6:
;Click_USBUART3_STM.c,70 :: 		Delay_ms(2000);
MOVW	R7, #13823
MOVT	R7, #366
NOP
NOP
L_applicationTask8:
SUBS	R7, R7, #1
BNE	L_applicationTask8
NOP
NOP
NOP
;Click_USBUART3_STM.c,72 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #8
BX	LR
; end of _applicationTask
_main:
;Click_USBUART3_STM.c,74 :: 		void main()
;Click_USBUART3_STM.c,76 :: 		systemInit();
BL	_systemInit+0
;Click_USBUART3_STM.c,77 :: 		applicationInit();
BL	_applicationInit+0
;Click_USBUART3_STM.c,79 :: 		while (1)
L_main10:
;Click_USBUART3_STM.c,81 :: 		applicationTask();
BL	_applicationTask+0
;Click_USBUART3_STM.c,82 :: 		}
IT	AL
BAL	L_main10
;Click_USBUART3_STM.c,83 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
