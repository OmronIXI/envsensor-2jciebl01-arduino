/*
   2JCIE-BL01スキャン処理サンプルプログラム
   参考 : http://blog.livedoor.jp/sce_info3-craft/archives/9717154.html
   
*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

int scanTime = 1; //スキャン実行間隔(秒数)
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {

    double convertToDouble(const String s) {
      // 引数をDouble型にキャスト
      
      return atof(String(strtol(s.c_str(), 0, 16)).c_str()) ;
    }
  
    void onResult(BLEAdvertisedDevice advertisedDevice) {

      // 受信データを取得
      String hexString = (String) BLEUtils::buildHexData(nullptr, (uint8_t*)advertisedDevice.getManufacturerData().data(),
      advertisedDevice.getManufacturerData().length());

      // 受信データの会社コードがオムロンだった場合
      if (hexString.substring(0, 4).equals("d502")) {

        // シリアル接続で計測データを送信
        Serial.printf("temperature: %s \n", String(convertToDouble((hexString.substring(8, 10) + hexString.substring(6, 8))) / 100).c_str());
        Serial.printf("relativeHumidity: %s \n", String(convertToDouble((hexString.substring(12, 14) + hexString.substring(10, 12))) / 100).c_str());
        Serial.printf("ambientLight: %s \n", String(convertToDouble((hexString.substring(16, 18) + hexString.substring(14, 16)))).c_str());
        Serial.printf("uvIndex: %s \n", String(convertToDouble((hexString.substring(20, 22) + hexString.substring(18, 20))) / 100).c_str());
        Serial.printf("pressure: %s \n", String(convertToDouble((hexString.substring(24, 26) + hexString.substring(22, 24))) / 100).c_str());
        Serial.printf("soundNoise: %s \n", String(convertToDouble((hexString.substring(28, 30) + hexString.substring(26, 28))) / 100).c_str());
        Serial.printf("discomfortIndex: %s \n", String(convertToDouble((hexString.substring(32, 34) + hexString.substring(30, 32))) / 100).c_str());
        Serial.printf("heatStroke: %s \n", String(convertToDouble((hexString.substring(36, 38) + hexString.substring(34, 36))) / 100).c_str());
        Serial.printf("rfu: %s \n", String(convertToDouble((hexString.substring(40, 42) + hexString.substring(38, 40))) / 100).c_str());
        Serial.printf("batteryVoltage: %s \n", String(convertToDouble((hexString.substring(44, 46) + hexString.substring(42, 44)))).c_str());        
        Serial.printf("\n");
        
      }
    }
};

void setup() {
  Serial.begin(115200);
  Serial.println("Scanning...");

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan(); //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
  
}

void loop() {
  BLEScanResults foundDevices = pBLEScan->start(scanTime);
}
