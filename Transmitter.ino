#include <Wire.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <MPU6050.h>

RF24 radio(8, 9);
MPU6050 mpu;

const uint64_t pipeOut = 0xF9E8F0F0E1LL;

struct PacketData {
  byte xAxisValue;
  byte yAxisValue;
};

PacketData packet;

int16_t baseAx, baseAy, baseAz;
int16_t ax, ay, az, gx, gy, gz;

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(pipeOut);
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }
  calibrateMPU();
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  int mappedX = map(ax - baseAx, -17000, 17000, 0, 254);
  int mappedY = map(ay - baseAy, -17000, 17000, 0, 254);
  packet.xAxisValue = constrain(mappedX, 0, 254);
  packet.yAxisValue = constrain(mappedY, 0, 254);
  radio.write(&packet, sizeof(PacketData));
  Serial.print("X: ");
  Serial.print(packet.xAxisValue);
  Serial.print("\tY: ");
  Serial.println(packet.yAxisValue);
  delay(10);
}

void calibrateMPU() {
  int numSamples = 100;
  long sumAx = 0, sumAy = 0, sumAz = 0;

  for (int i = 0; i < numSamples; i++) {
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    sumAx += ax;
    sumAy += ay; 
    sumAz += az;
    delay(10);
  }

  baseAx = sumAx / numSamples;
  baseAy = sumAy / numSamples;
  baseAz = sumAz / numSamples;

  Serial.println("Calibration complete.");
}
