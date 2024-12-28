import pandas as pd
import joblib
from sklearn.preprocessing import StandardScaler

model_filename = 'emg_model.pkl'
model = joblib.load(model_filename)

def load_new_data(file_path):
    data = pd.read_csv(file_path)
    return data

def preprocess_data(df):
    df = df.dropna()  
    features = df[['Timestamp', 'EMG Value', 'massage_speed']]
    scaler = StandardScaler()
    features_scaled = scaler.fit_transform(features)
    
    return features_scaled

def predict_relaxation(model, features):
    predictions = model.predict(features)
    return predictions

def main(file_path):
    new_data = load_new_data(file_path)
    preprocessed_data = preprocess_data(new_data)
    predictions = predict_relaxation(model, preprocessed_data)
    relaxed = predictions.mean() > 0.5 
    result = "Relaxed" if relaxed else "Not Relaxed"
    print(f"The massage effect is: {result}")

if __name__ == "__main__":
    file_path = 'emg_data_test.csv'
    main(file_path)
