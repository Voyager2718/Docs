using UnityEngine;
using System.Collections;

public class HealthScript : MonoBehaviour
{
    public int hp = 5;

    public bool isEnemy = true;

    void OnTriggerEnter2D(Collider2D collider)
    {
        BulletScript bullet = collider.gameObject.GetComponent<BulletScript>();

        if (bullet != null && bullet.isEnemyShot != isEnemy)
        {
            hp -= bullet.damage;
            Destroy(bullet.gameObject);
            if (hp <= 0)
                Destroy(gameObject);
        }
    }
}
