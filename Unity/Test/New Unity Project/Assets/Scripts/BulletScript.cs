﻿using UnityEngine;
using System.Collections;

public class BulletScript : MonoBehaviour
{

    public int damage = 1;

    public bool isEnemyShot = false;

    // Use this for initialization
    void Start()
    {
        Destroy(gameObject, 20);
    }

    // Update is called once per frame
    void Update()
    {

    }
}
