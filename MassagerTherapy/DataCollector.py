import serial
import time
import csv
import matplotlib.pyplot as plt
from datetime import datetime

data_type=["before_massage","after_massage","during_massage"]

SERIAL_PORT = 'COM8'  
BAUD_RATE = 115200
DURATION = 30  

def generate_filename():
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    return f"emg_data_{timestamp}.csv"

def collect_data(filename):
    data_type_input = input("Enter the data type (before_massage, after_massage, during_massage): ")
    if data_type_input not in data_type:
        print("Invalid data type. Please enter 'before_massage', 'after_massage', or 'during_massage'.")
        return
    massage_speed = float(input("Enter the massage speed: "))
    massage_duration = float(input("Enter the massage duration: "))
    relaxment_level = float(input("Enter the relaxment level(0-5): "))
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    print(f"Connected to {SERIAL_PORT} at {BAUD_RATE} baud")

    timestamps = []
    emg_values = []

    filename=f"{data_type_input}/{filename}"

    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['Timestamp', 'EMG Value' , 'massage_speed', 'massage_duration', 'relaxment_level'])

        start_time = time.time()
        while (time.time() - start_time) < DURATION:
            if ser.in_waiting > 0:
                try:
                    line = ser.readline().decode('utf-8').strip()
                    emg_value = int(line)  
                    timestamp = time.time() - start_time
                    writer.writerow([timestamp, emg_value, massage_speed, massage_duration, relaxment_level])
                    timestamps.append(timestamp)
                    emg_values.append(emg_value)
                    print(f"{timestamp:.2f}, {emg_value}")
                except ValueError:
                    pass

    # Close the serial port
    ser.close()
    print(f"Data collection complete. Data saved to {filename}")

    return timestamps, emg_values

def plot_data(timestamps, emg_values):
    plt.figure(figsize=(10, 5))
    plt.plot(timestamps, emg_values, label='EMG Value')
    plt.xlabel('Time (seconds)')
    plt.ylabel('EMG Value')
    plt.title('EMG Data Over Time')
    plt.legend()
    plt.grid(True)
    plt.show()

def main():
    filename = generate_filename()
    timestamps, emg_values = collect_data(filename)
    plot_data(timestamps, emg_values)

if __name__ == '__main__':
    main()
