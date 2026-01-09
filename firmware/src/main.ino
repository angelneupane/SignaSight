#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define BUTTON_PIN 27
#define VIB_PIN 23        // Vibration motor
#define SPEAKER_PIN 33    // Speaker
#define TRIG 5
#define ECHO 18

Adafruit_MPU6050 mpu;
int flexPins[5] = {25, 26, 34, 35, 32}; // Flex sensors

bool signMode = false;
bool lastButton = HIGH;

// Measure distance using ultrasonic sensor
long getDistance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    long d = pulseIn(ECHO, HIGH, 25000);
    if(d == 0) return -1;
    return d * 0.034 / 2; // distance in cm
}

// Model:
void processSignMode(int flex[5], float ax, float ay, float az) {
    Serial.println("Processing data for Edge Impulse model...");

    // TODO: Convert flex+IMU to model input
    // Example: float modelInput[8] = {flex[0], flex[1], flex[2], flex[3], flex[4], ax, ay, az};

    // TODO: Run Edge Impulse inference
    // Output: .mp3 or audio buffer

    Serial.println("Model returned .mp3 output. Playing through speaker...");
    
    // Temporary demo: play a short tone on speaker using LEDC
    ledcWriteTone(1, 1000);
    delay(200);
    ledcWriteTone(1, 0);
}

void setup() {
    // Pins
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(VIB_PIN, OUTPUT);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(SPEAKER_PIN, OUTPUT);

    Serial.begin(115200);
    Wire.begin(21, 22);  // ESP pins for MPU6050
    Wire.setClock(400000);

    // Setup PWM channels for ESP32 (vibration + speaker)
    ledcSetup(0, 5000, 8);        
    ledcAttachPin(VIB_PIN, 0);
    ledcSetup(1, 2000, 8);        
    ledcAttachPin(SPEAKER_PIN, 1);

    if (!mpu.begin()) {
        Serial.println("Failed to find MPU6050 chip");
        while (1) { delay(10); }
    }
    Serial.println("Found MPU6050");

    Serial.println("BOOT OK");
    Serial.println("SYSTEM READY");
}

void loop() {
    // Button to toggle mode
    bool btn = digitalRead(BUTTON_PIN);
    if(btn == LOW && lastButton == HIGH) {
        signMode = !signMode;
        Serial.println(signMode ? "MODE: SIGN" : "MODE: OBSTACLE");
        delay(200); 
    }
    lastButton = btn;

    if(signMode) {
        // SIGN MODE
        int flex[5];
        for(int i = 0; i < 5; i++){
            flex[i] = analogRead(flexPins[i]);
            Serial.print("F"); Serial.print(i+1); Serial.print(": "); Serial.println(flex[i]);
        }

        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
        float ax = a.acceleration.x;
        float ay = a.acceleration.y;
        float az = a.acceleration.z;
        Serial.print("AX: "); Serial.println(ax);
        Serial.print("AY: "); Serial.println(ay);
        Serial.print("AZ: "); Serial.println(az);

        // Send sensor data to Edge Impulse model and play audio
        processSignMode(flex, ax, ay, az);

    } else {
        // OBSTACLE MODE
        long dist = getDistance();
        if(dist < 0 || dist > 150) {
            Serial.println("No Obstacle");
            analogWrite(VIB_PIN, 0);
        } else {
            Serial.print("Obstacle: "); Serial.print(dist); Serial.println(" cm");
            int intensity = map(dist, 150, 5, 20, 255);
            intensity = constrain(intensity, 0, 255);
            analogWrite(VIB_PIN, intensity);
        }
    }

    delay(200);
}