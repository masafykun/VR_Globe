﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Lkusuri : MonoBehaviour {

	GameObject Yubi;
	public SerialRead script;

	void start(){
		Yubi = GameObject.Find ("Serial");
		script = Yubi.GetComponent<SerialRead> ();
	}

	public void Arduino_Send(byte n){    //Arduino側にbyte値を送信
		byte[] byte1 = new byte[1];
		byte1 [0] = n; 
		script.Port1.Write (byte1, 0, 1);
		Debug.Log (n);
	} 


	void OnCollisionEnter(Collision collision){
		Arduino_Send(129);
	}

	void OnCollisionExit(Collision collision){
		Arduino_Send (29);
	}
}
