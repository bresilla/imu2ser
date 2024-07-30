#include <Arduino.h>
#include <Arduino_BMI270_BMM150.h>


//Establishment of variables for axis
//Acceleration Axis
float Ax, Ay, Az;
//Gyroscope Axis
float Gx, Gy, Gz;
//Magnetometer Axis
float Mx, My, Mz;
//Quaternion derived Orientation Variables
float roll, pitch, heading;



void setup() {
    Serial.begin(115200);
    while (!Serial);
    Serial.println("Started");

    if (!IMU.begin()) {
        Serial.println("Failed to initialize IMU!");
        while (1);
    }
    IMU.setContinuousMode();

    Serial.print("Accelerometer sample rate = " + String(IMU.accelerationSampleRate()) + " Hz");
    Serial.print(" Gyroscope sample rate = " + String(IMU.gyroscopeSampleRate()) + " Hz");
    Serial.println(" Magnetometer sample rate = " + String(IMU.magneticFieldSampleRate()) + " Hz");
}

void loop() {

    if (IMU.accelerationAvailable()){
        IMU.readAcceleration(Ax, Ay, Az);
        Serial.print("Acceleration: ");
        Serial.print(Ax);
        Serial.print(" ");
        Serial.print(Ay);
        Serial.print(" ");
        Serial.println(Az);
    }
    if (IMU.gyroscopeAvailable()){
        IMU.readGyroscope(Gx, Gy, Gz);
        Serial.print("Gyroscope: ");
        Serial.print(Gx);
        Serial.print(" ");
        Serial.print(Gy);
        Serial.print(" ");
        Serial.println(Gz);
    }
    if (IMU.magneticFieldAvailable()){
        IMU.readMagneticField(Mx, My, Mz);
        Serial.print("Magnetometer: ");
        Serial.print(Mx);
        Serial.print(" ");
        Serial.print(My);
        Serial.print(" ");
        Serial.println(Mz);
    }
}