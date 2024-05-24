import tkinter as tk
from tkinter import messagebox
import random
def fetch_weather_data(city_name):
    temperatures = [random.randint(15, 30) for _ in range(5)]
    dates = ["2024-03-20", "2024-03-21", "2024-03-22", "2024-03-23", "2024-03-24"]
    return {
        "温度": temperatures,
        "日期": dates
    }
def draw_chart(canvas, data):
    canvas.delete("all")
    temperatures = data["温度"]
    dates = data["日期"]
    max_temp = max(temperatures)
    min_temp = min(temperatures)
    temp_range = max_temp - min_temp if max_temp != min_temp else 1  # 防止除以零
    canvas_height = 300
    canvas_width = 400
    for i in range(len(temperatures)):
        x = i * (canvas_width / (len(temperatures) - 1))
        y = canvas_height - ((temperatures[i] - min_temp) / temp_range) * canvas_height
        if i < len(temperatures) - 1:
            next_x = (i + 1) * (canvas_width / (len(temperatures) - 1))
            next_y = canvas_height - ((temperatures[i + 1] - min_temp) / temp_range) * canvas_height
            canvas.create_line(x, y, next_x, next_y, fill="blue", width=2)
        canvas.create_text(x, y - 10, text=f"{temperatures[i]}°C", fill="black")
        canvas.create_text(x, canvas_height - 10, text=dates[i], fill="black", anchor="s")
def show_weather():
    city_name = city_entry.get()  # 获取文本框内容
    if not city_name:
        messagebox.showinfo("提示", "请输入城市名")
        return
    weather_data = fetch_weather_data(city_name)
    draw_chart(canvas, weather_data)
root = tk.Tk()
root.title("天气数据可视化")
city_entry = tk.Entry(root)  # 输入框
city_entry.pack()
show_button = tk.Button(root, text="显示天气", command=show_weather)  # 按钮
show_button.pack()
canvas = tk.Canvas(root, width=400, height=300)  # 画布
canvas.pack()
root.mainloop()

