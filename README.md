
# envsensor-2jciebl01-arduino
Omron製環境センサ(2jciebl01)のデータをArduinoで受信するスケッチプログラムです。  
2jciebl01を使用したシステムを構築する際のサンプルプログラムとしてお使いください。

## 動作確認環境
本プログラムの動作確認を行った環境を記します。
###  HardWare
* 環境センサ : 2jcie-bl01  
https://www.omron.co.jp/ecb/product-info/sensor/iot-sensor/environmental-sensor

* Arduino : ESPr® Developer 32  
https://www.switch-science.com/catalog/3210/

### Software
* IDE : Arduino IDE 1.8.5

## Setup
(1) 以下のサイトを参照し、環境センサの設定を設定をBroadcasterに変更してください。
https://qiita.com/komde/items/7209b36159da69ae79d2

(2) 以下のサイトを参照し、Arduino IDEの設定を行ってください。  
https://github.com/espressif/arduino-esp32/blob/master/docs/arduino-ide/windows.md

(3) 本リポジトリをダウンロードして、マイコンボードに書き込みを行ってください。

(4) シリアルモニタ(ツール→シリアルモニタ)を開き、通信速度を115200bpsに変更してください。

(5) シリアルモニタに環境センサの計測値が表示されたら、確認完了です。  

![通信時](/img/serial_monitor.png)
