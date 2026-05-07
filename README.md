# VR_Globe

> 研究会制作：VR 仮想ハンド × Arduino シリアル通信セット

## 概要

研究会で制作した Unity + Arduino 連携プロジェクトです。
Unity 上に表示された仮想の手（VR ハンド）と Arduino をシリアル通信でリンクさせることができます。

- Unity 側で仮想ハンドを表示・制御
- Arduino スクリプト（`VR_Globe_arduino`）も同梱
- キーボード入力（N / M キー）で Arduino に byte データを送信し、LED などのデバイスを制御

## 使用技術

- Unity（C#）
- Arduino（シリアル通信）
- SerialPort（UnityEngine）

## 動作環境 / 注意事項

- Windows 環境推奨（SerialPort の COM ポート設定が必要）
- Arduino IDE で Arduino スクリプトを書き込んだうえで Unity を実行してください
- COM ポート番号はスクリプト内で手動設定が必要です（デフォルト：COM7）

## ライセンス

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=flat-square)](https://opensource.org/licenses/MIT)

このプロジェクトは **MIT ライセンス** のもとで公開しています。  
使用・参考にした際はできる限り作者へのクレジット表記をお願いします。

© 2025 masafykun (https://github.com/masafykun)
