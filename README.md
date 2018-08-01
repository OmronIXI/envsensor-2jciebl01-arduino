
# envsensor-2jciebl01-arduino
OMRON製環境センサ(2JCIE-BL01)のデータをArduino(ESPr® Developer 32)で受信するスケッチです。  
2JCIE-BL01を使用したシステムを構築する際の参考資料(サンプルプログラム)としてお使いください。

## [1] サンプルプログラム概要
環境センサは計測した値をBLEで周辺に発信しています。  
サンプルプログラムでは環境センサが発信した計測データを受信し、接続しているPCにシリアル通信で各種センサ値を送信するものです。

![全体図](/img/general_view.png)

## [2]使用Hardware
### 2jciebl-01とは
OMRONが発売した環境情報(温度 ・ 湿度 ・ 照度（明るさ） ・ 気圧 ・ 音 ・ UV)を計測するワンパッケージの小型複合センサーです。  
計測したデータをBLE経由で他の機器に送信することができます。  
製品の詳細は以下のサイトを確認ください。  
https://www.omron.co.jp/ecb/product-info/sensor/iot-sensor/environmental-sensor

コネクションによりデータ取得も可能ですが、本サンプルはADV（アドバタイズモード）で受信できる情報を取得します。
送信している値の詳細は以下のサイトを確認ください。  
https://omronmicrodevices.github.io/products/2jcie-bl01/communication_if_manual.html  
3.5. (E) Sensor ADV 2 (ADV_IND)


### ESPr® Developer 32とは
無線通信モジュール（Wi-Fi + Bluetooth）とESP-WROOM-32を搭載したArduino互換開発ボードです。  
詳細は以下のサイトを確認ください。  
https://www.switch-science.com/catalog/3210/

## [3]セットアップ
(1) 以下のサイトを参照し、環境センサの設定を設定をBroadcasterに変更してください。  
https://qiita.com/komde/items/7209b36159da69ae79d2

(2) 以下のサイトを参照し、Arduino IDEの設定を行ってください。  
https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/windows.md

(3) 本リポジトリをダウンロードして、マイコンボードに書き込みを行ってください。

(4) シリアルモニタ(ツール→シリアルモニタ)を開き、通信速度を115200bpsに変更してください。

(5) シリアルモニタに環境センサの計測値が表示されます。

![通信時](/img/serial_monitor.png)
