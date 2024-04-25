# STM32_Firmware_mini_project_bundle
STM32와 Renesas의 Eval Board로 Firmware를 개발한 미니 프로젝트입니다.


## Require
<h4> 사용한 개발 보드: Nucleo-F103RB, ST사 제작</h4>

![뉴클레오](https://github.com/woodong11/STM32_Firmware_mini_project_bundle/assets/91379630/f4d60532-a8df-4046-8c66-b8abfcd6ec66)
<br><br>
MCU 이름 : STM32F103RB <br>
MCU 정보 : ARM Cortex-M3 계열, 72MHz <br>
- RAM size : 20KB SRAM <br>
- Flash size : 128KB flash memory <br>

<h4> 사용한 개발 보드: FPB-RA6E1, 르네사스 제작 </h4>
<img src = "https://github.com/woodong11/Firmware_mini_project_bundle/assets/91379630/c710287a-0540-4d94-97de-a81dbb3e7d19" width="30%" height="30%"><br><br>

MCU 이름 :  R7FA6E10F2CFP <br>
MCU 정보 : ARM Cortex - M33 계열, 200MHz <br>
- RAM size : 256KB SRAM <br>
- Flash size : 1MB flash memory <br>


## Nucleo_LED_and_Swtich
Bread Board에 버튼 2개와 LED3개를 연결하고, <br>
버튼1 누르면 LED1 → LED2 → LED3 → LED1 → … <br>
버튼2 누르면 LED3 → LED2 → LED1 → LED3 → … <br>
로 동작하는 예제입니다. <br>

[![Video Label](http://img.youtube.com/vi/s4oU_HAVQSQ/0.jpg)](https://youtu.be/s4oU_HAVQSQ)

<h4> Pinout MAP </h4>
PC5, PC6, PC8을 LED1, LED2, LED3로 설정 <br>
PA11, PA12를  BTN1, BTN2로 설정하고 GPIO설정에서 pull up으로 설정 <br>

<img src = "https://github.com/woodong11/STM32_Firmware_mini_project_bundle/assets/91379630/56a93127-0cfa-45d7-ac4f-e33100363b4b" width="40%" height="40%"><br><br>

<h4> how to run </h4>
main.c 대신 해당 코드를 복붙하고 디버그 실행 <br><br>

## Nucleo_UART_LED_Blink
Bread Board 에 LED 3개를 연결하고, PC에서 입력한 숫자만큼 LED1, LED2, LED3를 깜빡이는 예제입니다. <br>
ex) 숫자 4를 입력하면 LED 전체가 4번 깜빡임  <br>
![도전4](https://github.com/woodong11/STM32_Firmware_mini_project_bundle/assets/91379630/edf70900-bc06-46ee-adb2-724687c86a70)
<br><br>

[![Video Label](http://img.youtube.com/vi/KpeYn1smhSw/0.jpg)](https://youtu.be/KpeYn1smhSw) <br>


<h4> Pinout MAP </h4>
PC5, PC6, PC8을 LED1, LED2, LED3로 설정 <br>

<img src = "https://github.com/woodong11/STM32_Firmware_mini_project_bundle/assets/91379630/acfb6497-d710-44de-8821-9b4ea6e50b40" width="40%" height="40%"><br><br>

<h4> how to run </h4>
main.c 대신 해당 코드를 복붙하고 디버그 실행 <br><br>

## Nucleo_LED_Interrupt.c
LED와 Switch를 이용해 인터럽트를 제작해보는 예제입니다. <br>
1. 버튼1 누르면, LED1 무한 blink
2. 버튼2 누르면, LED2 무한 blink
코드를 수정하여 우선순위 변경 가능 <br>
<img src = "https://github.com/woodong11/Firmware_mini_project_bundle/assets/91379630/b176af64-aac3-404a-a18f-e23e21baeae1" width="40%" height="40%"><br><br>



<h4> how to run </h4>
main.c 대신 해당 코드를 복붙하고 디버그 실행 <br><br>

## Necleo_LED_timmer_interrupt.c

LED 3개를 Timer 설정과 UART를 이용해 PC에 출력하는 예제입니다. <br>
1. LED1 : 0.5s 에 한번 blink
2. LED2 : 0.3s 에 한번 blink
3. LED3 : 0.7s 에 한번 blink
<br>
<img src = "https://github.com/woodong11/Firmware_mini_project_bundle/assets/91379630/db09854a-97ec-480b-80fc-e17360f2a8be" width="40%" height="40%"><br><br>

<h4> Pinout MAP </h4>
PC6, PC8, PA11: LED1, LED2, LED3 <br>
PC9, PA12: BTN1, BTN2 <br>
clock configuration: Prescaler를 8000-1, Counter Period를 10-1로 설정 <br>
<img src = "https://github.com/woodong11/Firmware_mini_project_bundle/assets/91379630/c83b7568-a35b-4f8a-9da8-9cf893197f37" width="40%" height="40%"><br><br>



<h4> how to run </h4>
main.c 대신 해당 코드를 복붙하고 디버그 실행 <br><br>

## Nucleo_ADC_visualization
뉴클레오 보드에서 ADC가변저항을 조절해, UART로 PC에 데이터를 보내 ADC Value 와 Volt 그래프를 시각화하는 예제입니다. <br>
<img src = "https://github.com/woodong11/Firmware_mini_project_bundle/assets/91379630/5cf647e2-8413-4430-8898-532b73f314df" width="40%" height="40%"><br><br>
<img src = "https://github.com/woodong11/Firmware_mini_project_bundle/assets/91379630/4c1c20e5-ea00-4539-9147-0abd805614ef" width="40%" height="40%"><br><br>



<h4> how to run </h4>
main.c 대신 해당 c 코드를 복붙하고 디버그 실행 <br><br>
PC에서 python adc_visual.py 로 실행 <br>

## Renesas_LED_Interrupt

Switch 2개와 LED 4개를 사용하고, 인터럽트와 재귀호출을 사용해 xxxx 부터 oooo 까지 모든 조합을 LED로 보여주는 예제입니다. <br>

1. 0.3초에 한번씩 LED 4개로 표현합니다. <br>
모든 조합을 보여주었다면, 아무것도 하지 않고 버튼 눌리기를 대기합니다. <br> <br>
2. Switch 1 : Play를 처음부터 다시 시작합니다. <br>
3. Switch 2 : 즉시 일시정지를 한다. 한번 더 누르면 재개합니다. <br>


<h4> Pinout MAP </h4>
P409, P302: usr_SW1, usr_SW2(IRQ6, IRQ5) <br>
p113, p303, p105, p107: usr_LED1, usr_LED2, usr_LED3, usr_LED4 <br>


![image](https://github.com/woodong11/Firmware_mini_project_bundle/assets/91379630/1669b6b5-14c7-432e-b90e-e6f6355a6e7d)



<h4> how to run </h4>
hal_entry.c 대신 해당 코드를 복붙하고 디버그 실행 <br><br>

<h4> troubleshooting </h4>

  1. 기본 설정으로 스위치가 동작하지 않을 때, 보드에서 직접 풀업 회로를 구성하고 irq setting의 Triger에 Falling으로 체크해 해결할 수   있습니다. + 인터럽트 우선순위는 IRQ마다 다르게 해야 합니다. <br>

2. 임베디드 MCU에선 flag같은 전역변수를 사용할 때 꼭 volatile로 선언해주어야 합니다. <br>
volatile로 선언하게 되면 해당 변수를 읽고 쓸 때 무조건 특정 메모리를 사용하게 됩니다. <br>
ex) 선언하지 않았을 때: 컴파일러가 코드를 최적화하여, cpu가 해당 변수를 자주 쓰는 변수로 인식해 캐쉬에 저장하게 되면, <br>
inturrupt가 동작해 어떤 함수에서 flag를 바꾸는 작업을 할때 cpu는 캐쉬에서만 읽게 되어 내가 원하는 동작을 하지 않을 수 있습니다.

3. 버튼을 눌렀을때 잘 동작하지 않을 시, bounce로 발생하는 채터링 현상 때문일 수 있습니다. <br>
SW적으로 해결할려면, 처음 신호와 약 100ms 이후의 신호의 종류가 같을때 High 또는 Low로 판별하는 코드를 추가할 수 있습니다. 

4. IRQ를 같은 종류로만 사용해야 합니다. <br>
ex) IRQ1_DS와 IRQ2는 동시 사용 불가








