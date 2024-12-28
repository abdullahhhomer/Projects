import tkinter as tk
from tkinter import ttk
import serial
import joblib
import numpy as np
from sklearn.preprocessing import StandardScaler
import time
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from threading import Thread

SERIAL_PORT = 'COM8'  
BAUD_RATE = 115200
DURATION = 30 
MODEL_PATH = 'emg_model.pkl'  

model = joblib.load(MODEL_PATH)
scaler = StandardScaler()

class MassageTherapyApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Massage Therapy EMG Analysis")

        self.port_label = ttk.Label(root, text="COM Port:")
        self.port_label.grid(row=0, column=0, padx=5, pady=5)
        
        self.port_entry = ttk.Entry(root)
        self.port_entry.grid(row=0, column=1, padx=5, pady=5)
        
        self.start_button = ttk.Button(root, text="Start", command=self.start_analysis)
        self.start_button.grid(row=1, column=0, columnspan=2, padx=5, pady=5)

        self.figure, self.ax = plt.subplots()
        self.canvas = FigureCanvasTkAgg(self.figure, master=root)
        self.canvas.get_tk_widget().grid(row=2, column=0, columnspan=2, padx=5, pady=5)

        self.result_label = ttk.Label(root, text="")
        self.result_label.grid(row=4, column=0, columnspan=2, padx=5, pady=5)
        
        self.timer_label = ttk.Label(root, text=f"Time remaining: {DURATION} s")
        self.timer_label.grid(row=3, column=0, columnspan=2, padx=5, pady=5)

        self.emg_values = []
        self.timestamps = []
        self.collecting_data = False

    def start_analysis(self):
        self.serial_port = self.port_entry.get()
        self.emg_values.clear()
        self.timestamps.clear()
        self.collecting_data = True

        self.update_timer(DURATION)
        self.data_thread = Thread(target=self.collect_emg_data, args=(DURATION,))
        self.data_thread.start()
        self.update_plot()

    def update_timer(self, remaining):
        self.timer_label.config(text=f"Time remaining: {remaining} s")
        if remaining > 0:
            self.root.after(1000, self.update_timer, remaining - 1)

    def update_plot(self):
        if self.collecting_data:
            self.ax.clear()
            self.ax.plot(self.timestamps, self.emg_values)
            self.ax.set_title("EMG Data")
            self.ax.set_xlabel("Time (s)")
            self.ax.set_ylabel("EMG Value")
            self.canvas.draw()
            self.root.after(100, self.update_plot)

    def collect_emg_data(self, duration):
        ser = serial.Serial(self.serial_port, BAUD_RATE, timeout=1)
        print(f"Connected to {self.serial_port} at {BAUD_RATE} baud")

        start_time = time.time()
        while (time.time() - start_time) < duration:
            if ser.in_waiting > 0:
                try:
                    line = ser.readline().decode('utf-8').strip()
                    emg_value = int(line)
                    self.emg_values.append(emg_value)
                    self.timestamps.append(time.time() - start_time)
                    print(f"EMG Value: {emg_value}")
                except ValueError:
                    pass
        ser.close()
        self.collecting_data = False
        
        features = np.column_stack((self.timestamps, self.emg_values, [1.0]*len(self.emg_values)))
        preprocessed_data = self.preprocess_data(features)
        result, mean_prediction = self.predict_relaxation(model, preprocessed_data)
        
        self.result_label.config(text=f"The massage effect is: {result} (Mean Prediction: {mean_prediction:.2f})")

    def preprocess_data(self, features):
        features_scaled = scaler.fit_transform(features)
        return features_scaled

    def predict_relaxation(self, model, features):
        predictions = model.predict(features)
        mean_prediction = predictions.mean()
        print("Predictions mean: ", mean_prediction)
        relaxed = mean_prediction > 1.2  # Adjust threshold based on your model's output and classes
        return ("Relaxed" if relaxed else "Not Relaxed"), mean_prediction

if __name__ == "__main__":
    root = tk.Tk()
    app = MassageTherapyApp(root)
    root.mainloop()
