import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report
import os
import glob

def load_data(data_directory):
    all_files = glob.glob(os.path.join(data_directory, "*.csv"))
    df_list = []

    for file in all_files:
        df = pd.read_csv(file)
        df_list.append(df)

    combined_df = pd.concat(df_list, axis=0, ignore_index=True)
    return combined_df

def preprocess_data(df):
    df = df.dropna()
    return df

data_directory = 'during_massage' 
data = load_data(data_directory)
data = preprocess_data(data)

X = data[['Timestamp', 'EMG Value', 'massage_speed']]
y = data['relaxment_level']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

model = RandomForestClassifier(n_estimators=100, random_state=42)

model.fit(X_train, y_train)

y_pred = model.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)
print(f'Accuracy: {accuracy * 100:.2f}%')
print(classification_report(y_test, y_pred))

import matplotlib.pyplot as plt
import seaborn as sns

feature_importances = pd.Series(model.feature_importances_, index=X.columns)
sns.barplot(x=feature_importances, y=feature_importances.index)
plt.title('Feature Importance')
plt.show()

import joblib
joblib.dump(model, 'emg_model.pkl')

