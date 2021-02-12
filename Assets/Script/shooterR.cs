using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class shooterR : MonoBehaviour {

	public GameObject target;

	void Update(){
		//スペースを押したら
		if (Input.GetKeyDown (KeyCode.S)) {
			
			Instantiate (target, this.transform.position , Quaternion.identity);

		}
	}
}
