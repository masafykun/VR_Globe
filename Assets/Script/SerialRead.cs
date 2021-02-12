using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class SerialRead : MonoBehaviour {

	public SerialPort Port1 = new SerialPort("COM7",9600);
	//public SerialPort Port2 = new SerialPort("COM5", 9600);

	void Start () {

		if (Port1.IsOpen) {
			Port1.Close ();
			Debug.Log ("Port1_Close\n");
		} else {
			Port1.Open ();
			Port1.ReadTimeout = 1000;
			Debug.Log ("Port1_Open\n");
		}
	}

	public void Arduino_Send(byte n){    //Arduino側にbyte値を送信
		byte[] byte1 = new byte[1];
		byte1 [0] = n; 
		Port1.Write (byte1, 0, 1);
		Debug.Log (n);
	}

}
