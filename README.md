# STM32_Firmware_mini_project_bundle
STM32와 Renesas의 Eval Board로 Firmware를 개발한 미니 프로젝트입니다.


## Require
<h4> 사용한 stm보드 </h4>

![뉴클레오](https://github.com/woodong11/STM32_Firmware_mini_project_bundle/assets/91379630/f4d60532-a8df-4046-8c66-b8abfcd6ec66)
<br><br>
보드 이름 : Nucleo <br>
보드 모델명 : Nucleo-F103RB <br>
ST사의 CPU 칩셋 이름 : STM32F103RB <br>
CPU 설계 : ARM Cortex-M3 <br>



## LED_and_Swtich
Bread Board에 버튼 2개와 LED3개를 연결하고, <br>
버튼1 누르면 LED1 → LED2 → LED3 → LED1 → … <br>
버튼2 누르면 LED3 → LED2 → LED1 → LED3 → … <br>
로 동작합니다. <br>

[![Video Label](http://img.youtube.com/vi/s4oU_HAVQSQ/0.jpg)](https://youtu.be/s4oU_HAVQSQ)

<h4> Pinout MAP </h4>
PC5, PC6, PC8을 LED1, LED2, LED3로 설정 <br>
PA11, PA12를  BTN1, BTN2로 설정하고 GPIO설정에서 pull up으로 설정 <br>

<img src = "https://github.com/woodong11/STM32_Firmware_mini_project_bundle/assets/91379630/56a93127-0cfa-45d7-ac4f-e33100363b4b" width="60%" height="60%"><br><br>


## UART_LED_Blink
![도전4](https://github.com/woodong11/STM32_Firmware_mini_project_bundle/assets/91379630/edf70900-bc06-46ee-adb2-724687c86a70)
<br><br>

[![Video Label](http://img.youtube.com/vi/KpeYn1smhSw/0.jpg)](https://youtu.be/KpeYn1smhSw) <br>
Bread Board 에 LED 3개를 연결하고, PC에서 입력한 숫자만큼 LED1, LED2, LED3를 깜빡입니다. <br>
ex) 숫자 4를 입력하면 LED 전체가 4번 깜빡임 

<h4> Pinout MAP </h4>
PC5, PC6, PC8을 LED1, LED2, LED3로 설정 <br>

<img src = "https://github.com/woodong11/STM32_Firmware_mini_project_bundle/assets/91379630/acfb6497-d710-44de-8821-9b4ea6e50b40" width="60%" height="60%"><br><br>











