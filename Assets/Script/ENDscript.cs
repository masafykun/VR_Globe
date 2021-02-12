using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ENDscript : MonoBehaviour {

	public SerialRead script;

	void OnDestroy(){
		script.Arduino_Send (222);
		script.Port1.Close ();
		//script.Port2.Close ();
		Debug.Log("ALL_PIN&PORT_CLOSE\n");
	}
}
