import tkinter as tk
from tkinter import ttk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import serial
import threading
import time


######################## 장치관리자, stm32 cube ide에서 확인하고 변경하기 ######################
PORT = "COM5"
baud_rate = 115200
##############################################################################################

# UART 연결
s = serial.Serial(PORT, baud_rate)

# 바이트 문자열에서 정수를 추출하는 함수
def parse_byte_string(byte_str):
    num_str = byte_str.strip().decode('utf-8')
    num = int(num_str)
    return num

# Tkinter 설정
root = tk.Tk()
root.title("실시간 ADC 값")

# Matplotlib 그래프 생성
fig, axs = plt.subplots(1, 2, figsize=(10, 5))  # 1x2 배열의 그래프
ax1, ax2 = axs
ax1.set_title("Value")
ax1.set_xlabel("Time")
ax1.set_ylabel("Value")
ax1.set_ylim(0, 4095)

ax2.set_title("Volt")
ax2.set_xlabel("Time")
ax2.set_ylabel("Volt")
ax2.set_ylim(0, 3.3)

# Matplotlib 그래프를 Tkinter에 연결
canvas = FigureCanvasTkAgg(fig, master=root)
canvas.get_tk_widget().pack()

# 데이터 저장
x_data = []
y1_data = []
y2_data = []

start_time = time.time()  # 프로그램 시작 시간

# 그래프 업데이트 함수
def update_graph():
    current_time = time.time() - start_time
    ax1.clear()
    ax1.set_title("Value")
    ax1.set_xlabel("Time")
    ax1.set_ylabel("Value")
    ax1.set_ylim(0, 4095)
    ax1.set_xlim(current_time - 5, current_time)

    ax2.clear()
    ax2.set_title("Volt")
    ax2.set_xlabel("Time")
    ax2.set_ylabel("Volt")
    ax2.set_ylim(0, 3.3)
    ax2.set_xlim(current_time - 5, current_time)

    ax1.plot(x_data, y1_data, 'r-', linewidth=2)
    ax2.plot(x_data, y2_data, 'b-', linewidth=2)

    canvas.draw()  # 그래프 그리기

# 별도의 스레드로 데이터 수신
def read_uart_data():
    while True:
        data = parse_byte_string(s.readline())
        current_time = time.time() - start_time
        volt = data * 3.3 / 4095

        x_data.append(current_time)
        y1_data.append(data)
        y2_data.append(volt)

        # Tkinter 이벤트 루프에서 그래프 업데이트 요청
        root.after_idle(update_graph)

        time.sleep(0.1)  # 데이터 수신 간격

# 데이터 수신 스레드 시작
uart_thread = threading.Thread(target=read_uart_data)
uart_thread.daemon = True  # 프로그램 종료 시 스레드 종료
uart_thread.start()

# Tkinter 메인 루프 실행
root.mainloop()
