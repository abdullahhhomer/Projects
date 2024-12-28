import serial
import joblib
import numpy as np
from sklearn.preprocessing import StandardScaler
import time

SERIAL_PORT = 'COM8'  
BAUD_RATE = 115200
DURATION = 30 
MODEL_PATH = 'emg_model.pkl'  

model = joblib.load(MODEL_PATH)

scaler = StandardScaler()

def collect_emg_data(duration):
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    print(f"Connected to {SERIAL_PORT} at {BAUD_RATE} baud")

    emg_values = []
    timestamps = []
    massage_speed = 1.0  
    massage_duration = 30  

    start_time = time.time()
    while (time.time() - start_time) < duration:
        if ser.in_waiting > 0:
            try:
                line = ser.readline().decode('utf-8').strip()
                emg_value = int(line)
                emg_values.append(emg_value)
                timestamps.append(time.time() - start_time)
                print(f"EMG Value: {emg_value}")
            except ValueError:
                pass
    ser.close()
    features = np.column_stack((timestamps, emg_values, [massage_speed]*len(emg_values)))
    
    return features

def preprocess_data(features):
    features_scaled = scaler.fit_transform(features)
    return features_scaled

def predict_relaxation(model, features):
    predictions = model.predict(features)
    print("Predictions mean: ", predictions.mean())
    relaxed = predictions.mean() > 1.2  # Adjust threshold based on your model's output and classes
    return "Relaxed" if relaxed else "Not Relaxed"

def main():
    print("Starting data collection...")
    features = collect_emg_data(DURATION)
    
    print("Preprocessing data...")
    preprocessed_data = preprocess_data(features)
    
    print("Predicting relaxation level...")
    result = predict_relaxation(model, preprocessed_data)
    
    print(f"The massage effect is: {result}")

if __name__ == "__main__":
    main()
