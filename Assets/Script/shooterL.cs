using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class shooterL : MonoBehaviour {

	public GameObject target;
	int count=0;

	void Update(){
		//スペースを押したら
		//if (Input.GetKeyDown (KeyCode.A)) {
		if(count/100==0)
			Instantiate (target, this.transform.position , Quaternion.identity);
		count++;

	}
}