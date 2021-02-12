using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class kasokudo : MonoBehaviour {

	public SerialRead script;
	public string message="まんじ";
	public GameObject L_kubi,R_kubi;
	public GameObject CUBE;
	public Text text_R;
	public Text text_L;

	void Update () {
		if (script.Port1.IsOpen) {
			message = script.Port1.ReadLine ();
			//Debug.Log ("Port1Say:" + message);
			CUBEDATA (message);
		}
	}

	void CUBEDATA(string message){
		string[] angles = message.Split (',');
		if (int.Parse(angles [0]) == 1) {
			text_R.text = "x:" + angles [1] + "\n" + "y:" + angles [2] + "\n" + "z:" + angles [3] + "\n"; 
			Vector3 angle = new Vector3 (float.Parse (angles [1]), float.Parse (angles [3]), float.Parse (angles [2]));
			R_kubi.transform.rotation = Quaternion.Euler (angle);
		} else if (int.Parse(angles [0]) == 2) {
			text_L.text = "x:" + angles [1] + "\n" + "y:" + angles [2] + "\n" + "z:" + angles [3] + "\n"; 
			Vector3 angle = new Vector3 (float.Parse (angles [1]), float.Parse (angles [3])-90, float.Parse (angles [2]));
			L_kubi.transform.rotation = Quaternion.Euler (angle);
		}
	}
}
